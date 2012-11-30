#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys
import time


class Dtw:

    def __init__(self):
        pass

    
    def calcDistance(self):
        self.mat_d = []
        for i in range(len(self.seq_1)):
            self.mat_d.append([])
            for j in range(len(self.seq_2)):
                self.mat_d[i].append(abs(self.seq_1[i] - self.seq_2[j]))


    def calcGamma(self):

        self.mat_g = []
        for i in range(len(self.seq_1)):
            self.mat_g.append([])
            for j in range(len(self.seq_2)):
                self.mat_g[i].append(0.0)
            
        self.mat_g[0][0] = self.mat_d[0][0]
            
        for i in range(1, len(self.mat_d)):
            self.mat_g[i][0] = self.mat_d[i][0] + self.mat_g[i-1][0]

        for i in range(1, len(self.mat_d[0])):
            self.mat_g[0][i] = self.mat_d[0][i] + self.mat_g[0][i-1]
        
        for i in range(1, len(self.seq_1)):
            for j in range(1, len(self.seq_2)):
                self.mat_g[i][j] = self.mat_d[i][j] + min(self.mat_g[i-1][j], self.mat_g[i][j-1], self.mat_g[i-1][j-1])

                
    def calcSum(self):

        sum = 0.0
        i = len(self.seq_1)-1
        j = len(self.seq_2)-1
            
        while (i != 0) or (j != 0):
            sum += self.mat_g[i][j]
    
            if i == 0:
                j -= 1
    
            elif j == 0:
                i -= 1
    
            else:
                m = min(self.mat_g[i-1][j], self.mat_g[i][j-1], self.mat_g[i-1][j-1])
    
                if m == self.mat_g[i-1][j]:
                    i -= 1
                
                elif m == self.mat_g[i][j-1]:
                    j -= 1
                
                else:
                    i -= 1
                    j -= 1
    
        return sum


    
    def calc(self):
        
        self.calcDistance()
        print("calcDistance completed")
        
        self.calcGamma()
        print("calcGamma completed")
        
        return self.calcSum()


    
    def openFiles(self, argv):

        if len(argv) < 2:
            sys.exit("Usage: # ./dtw.py file1 file2")

        self.seq_1 = []
        self.seq_2 = []
        
        for line in open(argv[0], 'r'):
            self.seq_1.append(float(line))

        for line in open(argv[1], 'r'):
            self.seq_2.append(float(line))

    
    

if __name__=='__main__':

    dtw = Dtw()

    dtw.openFiles(sys.argv[1:])
    print("file read end")

    time_start = time.time()

    result = dtw.calc()
    print("DTW : " + str(result))
    print("time: " + str(time.time() - time_start))
    print("")
