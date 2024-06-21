#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 25 19:59:00 2023

@author: aaronpang
"""


    
def cal(n):
    n=n*7
    if n<=9 :return n
    else : return plus(n)
    
def plus(n):
    m=0
    while n>0 :
        m+=n%10
        n//=10
    if m<=9 : return m
    else : return plus(m)
n=int(input())
for i in range(n):
    m=int(input())
    f=0
    while (m>0):
        f+=cal(m%10)
        f+=(m//10)%10
        m//=100
    if(f%8==0):print('T')
    else : print('F')
            