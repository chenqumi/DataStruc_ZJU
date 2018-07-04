#chenqumi@20171224
#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys,os,re

class Queue(object):
    """docstring for Queue"""
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return (self.items==[])

    def addQ(self,item):
        self.items.append(item)

    def deQ(self):
        return self.items.pop(0)
        
    def size(self):
        return len(self.items)

def main():
    pass

if __name__ == '__main__':
    main()