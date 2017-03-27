import sys

for unos in sys.stdin:
    unos=unos.replace("\n","")
    if unos=="0 0":
        break
    else:
        unos=unos.split(" ")
        L=[]
        for i in range(0,int(unos[0])):
            L.append(i+1)
        for i in range(0,int(unos[1])):
            ubijeni=input()
            ubijeni=ubijeni.split(" ")
            lijevi=0
            desni=0
            for j in range(0,len(L)):
                if L[j]==int(ubijeni[0]):
                    lijevi=j
                    manji=j-1
                if L[j]==int(ubijeni[1]):
                    desni=j
                    veci=j+1
            if manji < 0:
                if  veci> len(L)-1:
                    print("* *")
                else:
                    print("* {}".format(L[veci]))
            elif veci > len(L)-1:
                print("{} *".format(L[manji]))
            else:
                print("{} {}".format(L[manji],L[veci]))
            
            del(L[lijevi:desni+1])
                    
                
        print("-")