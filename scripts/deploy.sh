#!/bin/bash


pip install selenium

# 把 geckodriver所在路径放在环境变量里

dir=$PWD # geckodirver 路径 firefox 版本
echo "export PATH=$PATH:$dir" >> ~/.bash_profile

source .bash_profile

