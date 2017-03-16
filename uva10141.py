import sys
import pdb
k=0
#pdb.set_trace()
for line in sys.stdin:
    k=k+1
    line=line.replace('\n',"")
    if line=="0 0":
        break
    else:
#       if k!=1:
#           print()
       L=line.split(" ")
       (stvari,ponude)=(int(L[0]),int(L[1]))
       listastvari=[]
       for i in range (0,stvari):
           listastvari.append(input())
       maxartikli=0
       bestcijena=0
       bestponudac=""
       for i in range (0,ponude):
           ponudac=input()
           podaci=input()
           podaci=podaci.split(" ")
           (cijena,artikli)=(float(podaci[0]),int(podaci[1]))
           if i==0:
               bestcijena=cijena
           listaartikala=[]
           for j in range(0,artikli):
               listaartikala.append(input())
           poklapanja=0
           for j in range(0,len(listaartikala)):
               if listaartikala[j] in listastvari:
                   poklapanja+=1
           if poklapanja >= maxartikli:
               if poklapanja==maxartikli:
                   if cijena<bestcijena:
                       bestcijena=cijena
                       maxartikli=poklapanja
                       bestponudac=ponudac
               else:
                   bestcijena=cijena
                   maxartikli=poklapanja
                   bestponudac=ponudac
       print("RFP #{}".format(k))
       print(bestponudac)
       print()
                   
            
           
               
           