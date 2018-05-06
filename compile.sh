#! /bin/ksh

if [ $# -ne 1 ]; then
    echo compile.sh filename.cxx
    exit 1
fi

outname=eval echo $1|cut -d '.' -f 1 > /dev/null

if [ ! -f $1 ]; then
    echo File $1 not found !
    exit 1
fi

echo Compiling $1

basedirnm=`dirname $0`
gcc -o $basedirnm/$outname -std=c++11 $1
