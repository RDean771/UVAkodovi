import sys
for unos in sys.stdin:
    unos=unos.replace("\n","")
    if unos=="0 0":
        break
    else:
        unos=unos.split(" ")
        (unos[0],unos[1])=(int(unos[0]),int(unos[1]))
        debentures=unos[1]
        d={}
        for i in range(0,debentures+1):
            brojevi=input()
            brojevi=brojevi.split(" ")
            for j in range(0,len(brojevi)):
                    brojevi[j]=int(brojevi[j])
            if i==0:
                for j in range(0,len(brojevi)):
                    d[j+1]=brojevi[j]
            else:
                    d[brojevi[1]]+=brojevi[2]
                    d[brojevi[0]]-=brojevi[2]
            flag=1
            for key in d:
                if d[key]<0:
                    flag=0
                    break
        if flag==1:
            print("S")
        else:
            print("N")
            
            
            