T=int(input())
for i in range(0,T):
    N=int(input())
    if N==1:
        input()
        print("Case {}: {} {}".format(i+1,0,0))
    else:
        high=0
        low=0
        zidovi=input()
        zidovi=zidovi.split(" ")
        for j in range(0,len(zidovi)):
            zidovi[j]=int(zidovi[j])
        for j in range(1,len(zidovi)):
            if zidovi[j]>zidovi[j-1]:
                high+=1
            elif zidovi[j]==zidovi[j-1]:
                continue
            else:
                low+=1
        print("Case {}: {} {}".format(i+1,high,low))