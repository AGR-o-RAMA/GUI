#!/bin/sh
#appname=`basename $0 | sed s,\.sh$,,`

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
./bin/agrorama

#dirname=`dirname $0`
#tmp="${dirname#?}"

#if [ "${dirname%$tmp}" != "/" ]; then
#dirname=$PWD/$dirname
#fi
#LD_LIBRARY_PATH=$dirname
#export LD_LIBRARY_PATH
#$dirname/$appname "$@"