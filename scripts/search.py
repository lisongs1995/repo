#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# for fun
# 
########################################################################
 
"""
File: search.py
Date: 2018/10/18 19:00:53
"""
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import time
import getpass
import sys
url = "http://xxxx"

def get_user_info():

    username = raw_input("username:")
    passwd = getpass.getpass()
    return username, passwd

def uuap_login():
    
    username, passwd = get_user_info()
    options = webdriver.FirefoxOptions()
    options.add_argument('-headless')

    #browser = webdriver.Firefox() 浏览器打开
    browser = webdriver.Firefox(options=options) 浏览器后台运行，不打开。

    browser.get(url)
    WebDriverWait(browser,10,0.5).until(  \
        EC.presence_of_element_located((By.ID, 'username')))  
    browser.find_element_by_id("username").send_keys(username)
    browser.find_element_by_id("password").send_keys(passwd)
    double = browser.find_element_by_id("emailLogin")
    ActionChains(browser).double_click(double).perform()
    return browser

def search_sitelink(find_url):

    browser = uuap_login()
    time.sleep(2)
    found = False
    pages = 1
    while not found and pages < 158:
        reviewed = url + "/review/sitelink/list?page=%s&pagesize=20&type=3" % (pages)
        browser.get(reviewed)
        s = browser.page_source.decode("unicode_escape").encode("utf-8")
        if s.find(find_url)>=0:
            time.sleep(2)
            browser.save_screenshot("~/1.png") #找到了浏览器截图
            print pages
            found=True
        pages +=1

    browser.close()

if __name__ == "__main__":
    #all 156 pages 
    find_url = sys.argv[1]
    search_sitelink(find_url)

