#!/usr/bin/env python
# -*- coding:utf-8 -*-

f1 = open('seq1.txt', 'w')

for i in range(10000):
    num = i/10.0
    f1.write(str(num) + "\n")

f1.close()    



f2 = open('seq2.txt', 'w')

for i in range(10000):
    num = 0.2*(500 - (i%500))
    f2.write(str(num) + "\n")

f2.close()    



f3 = open('seq3.txt', 'w')

for i in range(10000):
    num = 0.19*(500 - (i%500))
    f3.write(str(num) + "\n")

f3.close()    
    
