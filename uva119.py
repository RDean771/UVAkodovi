import sys
for unos in sys.stdin:
    unos=unos.replace("\n","")
    if unos!="":
        print()
        unos=int(unos)
        rj=[]
        for i in range(0,unos+1):
            if i==0:
                imena=input()
                listaimena=imena.split(" ")
                for ime in listaimena:
                    rj.append([ime,0])
            else:
   
                poklon=input()
                listapoklon=poklon.split(" ")
                if listapoklon[1]=='0' or listapoklon[2]=='0':
                    continue
                else:
                    for j in range(0,len(rj)):
                        if rj[j][0]==listapoklon[0]:
                            rj[j][1]=rj[j][1]-int(listapoklon[1])+(int(listapoklon[1])%int(listapoklon[2]))
                            break
                    for j in range(3,len(listapoklon)):
                        for k in range(0,len(rj)):
                            if rj[k][0]==listapoklon[j]:
                                rj[k][1]=rj[k][1]+(int(listapoklon[1])//int(listapoklon[2]))
                                break
        for i in range(0,len(rj)):
           print("{} {}".format(rj[i][0],rj[i][1]))
    else:
        break
        
        
    