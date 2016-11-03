
# coding: utf-8

# In[54]:

import time
import random
import string

def gen():
    s=string.lowercase
    return ''.join((random.choice(s) for i in range(7)))


def find(s):
    return d[s]

def insert(s):
    d[s]=0
    
def erase(s):
    d.pop(s,None)
    
random.seed()
d = dict()

size = 3000000
testcases = 10000

test1=[]
for i in range(size):
    h=gen()
    d[h]=random.randint(0,99999)
    if i<testcases: test1.append(h)

t1=time.clock()
k=0
for i in range(testcases):
    find(test1[k])
    k=k+1
    if k==size: k=0
print(time.clock()-t1);

d.clear()
test2=[]
for i in range(size-testcases/2):
    h=gen()
    d[h]=random.randint(0,99999)
for i in range(testcases):
    h=gen()
    test2.append(h)
t2=time.clock()
for i in range(testcases):
    insert(test2[i])
print(time.clock()-t2);

t3=time.clock()
for i in range(testcases):
    erase(test2[i])
print(time.clock()-t3);

