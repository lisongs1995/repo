#!/bin/bash

set -x
set -o errexit
set -o pipefail
set -o nounset

function xpath() {
  
  if [ $# -ne 2 ];then
      echo "[ Usage-$0 ] : xpath html xpath_expr"
      echo "exit..."
      exit 1
  fi
  local html=$1
  local xpath_expr=$2
  local python_cmd="from lxml.etree import HTML;from sys import stdin; print '\n'.join(
                      HTML(''.join(stdin.readlines())).xpath('$xpath_expr'))" < $html
  python -c "$python_cmd" < $html
  rm -f $html
  return $?
}

function download() {

  local raw_url=$1
  local url=${url#*//} #去掉协议头，防止带来的url不标准或者死链
  if [  -z $url ];then
    echo  '$raw_url : illgeal url'
  fi
  #--no-check-certificate 防止ssl 验证
  # GNU wget 有https选项, mac没有，所以部分可以去掉
  wget -nv --no-check-certificate -T 10 -t 3 --connect-timeout=5 \
      --user-agent="Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)" \
      -O tmp.html $url

  if [ $? -eq 0 ] && [ -s tmp.html ];then
      return 0
  else
      return 1
  fi
}

function save() {
  
  row=$1
  MYSQL_BIN="mysql -uroot -p130163nihaO -Dsql -A"
  $MYSQL_BIN -e "insert into test values($row);"
  rerturn $?
}

url="www.huya.com"

download $url
#可能下载空文件,需要比对两次
if [ ! -s tmp.html ];then
  if ! download $url;then
    echo "download $url error"
  else
    rm -f tmp.html
    urls=`xpath tmp.html '//@href'`
  fi
else
  urls=`xpath tmp.html '//@href'`
fi

url_array=($urls)
for url in ${url_array[@]};
do
  echo ${url#*//}
done


