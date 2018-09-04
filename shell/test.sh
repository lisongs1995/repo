#!/bin/bash
# shell中是可以有递归的
# 局部变量在作用域内会覆盖全局变量
#建议函数内使用局部变量

function fib() {

  local N=$1
  if [ $N -eq 1 ];then
    echo 1
    exit 0
  else
    local res=`fib $((N-1))`
    echo `expr $res \*  $N`
  fi

}

time fib 20
# shell最多20层递归栈，多的话则容易爆栈
#2432902008176640000
#
#real	0m0.096s
#user	0m0.035s
#sys	0m0.053s
