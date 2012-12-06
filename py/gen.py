#!/usr/bin/env python
# -*- coding:utf-8 -*-

f1 = open('int/seq1.txt', 'w')

for i in range(10000):
    num = i
    f1.write(str(num) + "\n")

f1.close()    



f2 = open('int/seq2.txt', 'w')

for i in range(10000):
    num = 2*(500 - (i%500))
    f2.write(str(num) + "\n")

f2.close()    



f3 = open('int/seq3.txt', 'w')

for i in range(10000):
    num = 3*(500 - (i%500))
    f3.write(str(num) + "\n")

f3.close()    
    
