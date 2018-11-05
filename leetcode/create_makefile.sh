#!/bin/bash
# usgae: bash leetcode/create_makefile.sh cppfile_name

set -o nounset
set -o pipefail

[ ! -f makefile ] && exit 1

target=$1

seco_row=`sed -n "2p" makefile`
name=${seco_row%:*}

sed -i "s/$name/$target/g" makefile && echo "create makefile successfully!!!"

exit $?
