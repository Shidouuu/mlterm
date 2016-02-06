#!/bin/sh

if [ $# != 1 ]; then
	echo "Usage: rename.sh [installed prefix]"
	exit
fi

if [ ! -d $HOME/mlterm.app ]; then
	echo "Copy top_srcdir/cocoa/mlterm.app to $HOME/"
	exit
fi

cd $HOME/mlterm.app/Contents/MacOS

prefix="${1}"
libs="lib/libkik.[0-9]*.dylib lib/libmkf.[0-9]*.dylib lib/libmlterm_core.dylib lib/mlterm/libctl_bidi.so lib/mlterm/libctl_iscii.so lib/mlterm/libind_bengali.so lib/mlterm/libind_hindi.so lib/mlterm/libotl.so"

mkdir -p lib/mkf
mkdir -p lib/mlterm
for file in $libs lib/mkf/lib*.so ; do
	cp -f $prefix/$file `dirname $file`/
done

for file in bin/mlterm libexec/mlterm/mlconfig ; do
	cp -f $prefix/$file .
done

for file in $libs mlterm mlconfig ; do
	if [ -f $file ]; then
		echo "Update $file"
		for lib in $libs ; do
			install_name_tool -change $prefix/$lib @executable_path/$lib $file
		done
	fi
done

if [ -f lib/mlterm/libotl.so ]; then
	libhb=`otool -L lib/mlterm/libotl.so |sed -n 's/[^/]*\(.*harfbuzz.*dylib\).*/\1/p'`
	if [ "$libhb" != "" ]; then
		install_name_tool -change $libhb \
			@executable_path/lib/gtk/libharfbuzz.0.dylib lib/mlterm/libotl.so
	fi

	libotf=`otool -L lib/mlterm/libotl.so |sed -n 's/[^/]*\(.*otf.*dylib\).*/\1/p'`
	if [ "$libotf" != "" ]; then
		install_name_tool -change $libotf \
			@executable_path/lib/gtk/libotf.0.dylib lib/mlterm/libotl.so
	fi
fi