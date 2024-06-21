#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 20 21:42:55 2023

@author: aaronpang
"""
def su(n):
    for i in range(2,n-1):
        if (n%i==0):return False
    return True
    
def hui(n):
    num=n
    if (len(num)==0 or len(num)==1) :return True
    elif (num[0]!=num[-1]):return False #python 中字符串[-1]表示最后一个字符
    else : return hui((num[1:-1])) # python 中所有遵循左闭右开
    
n=int(input())
count=0
for i in range(11,n+1):
    if(su(i) and hui(str(i))): 
        count+=1
print(count)

