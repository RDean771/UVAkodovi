rijeci=["Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"]
imena=[]
N=int(input())
for i in range(0,N):
    imena.append(input())
brpon=((N//16)+1)*16
for i in range(0,brpon):
    print("{}: {}".format(imena[i%N],rijeci[i%16]))
    