import sys,pdb
k=0
for unos in sys.stdin:
    k=k+1
    pdb.set_trace()
    unos=unos.replace("\n","")
    if unos=="":
        break
    else:
        print("Case {}:".format(k))
        N=int(input())
        for i in range(0,N):
            indeksi=input()
            indeksi=indeksi.split(" ")
            indeksi.sort()
            (indeks1,indeks2)=(int(indeksi[0]),int(indeksi[1]))
            indeks1=min(indeks1,indeks2)
            indeks2=max(indeks1,indeks2)
            dio=unos[indeks1:indeks2+1]
            rj1=""
            rj2=""
            for i in range(0,len(dio)):
                rj1+="0"
                rj2+="1"
            if dio==rj1 or dio==rj2:
                print("Yes")
            else:
                print("No")