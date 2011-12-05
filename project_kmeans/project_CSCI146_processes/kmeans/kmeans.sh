#!/bin/bash
#
#
g++ -c -g -I  kmeans.C >& compiler.txt
if [ $? -ne 0 ]; then
  echo "Errors compiling kmeans.C."
  exit
fi
rm compiler.txt
#
mv kmeans.o ~/libcpp/$ARCH/kmeans.o
#
echo "Library installed as ~/libcpp/$ARCH/kmeans.o"
