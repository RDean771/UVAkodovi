L=[(0, [1 , 3]), (1 , [3 , 5]), (2 , [3 , 4]), (3 , [0 , 4]), (4 , [1 , 3]), (5 , []), (6 , [1 , 2 , 3])]
rj=[1,2,3,4,5,6]
def findelem(x):
    for i in range(0,len(L)):
        if L[i][0]==x:
            return L[i]
def src (L):
    x=L[1]
    for i in range(0,len(x)):
        if x[i] in rj:
            rj.remove(x[i])
            src(findelem(x[i]))
src(L[0])
print(rj)
