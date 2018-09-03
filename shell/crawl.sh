#!/bin/bash


function xpath() {
  html=$1
  xpath_expr=$2
  python_cmd_import="from lxml.etree import HTML; \
                     from sys import stdin;"
  python_cmd_xpath="is=''.join(stdin.readlines()); \
                      print '\n'.join(HTML(is)).xpath('$2')"
  python -c "$python_cmd_import"\
            "$python_cmd_xpath" < "$1" | echo 

}

oxpath "index.html" "//link/@href"


url="www.baidu.com www.huya.com"
array=($url)
for each in ${array[@]}
do
  wget -t10 -header="fir"  $each -O tmp.html
  #curl
  

done


