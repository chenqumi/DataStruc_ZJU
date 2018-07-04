#chenqumi@20171224
#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys,os,re
import Queue

arr = Queue.Queue()

#print(arr.items)

for i in range(10):
    arr.addQ(i)
print(arr.items)

for i in range(10):
    item = arr.deQ()
    print(item)