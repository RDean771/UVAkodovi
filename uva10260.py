import sys
d={1: ['B','F','P','V'], 2: ['C','G','J','K','Q','S','X','Z'], 3:['D','T'], 4:['L'], 5:['M','N'], 6:['R']} 
for rijec in sys.stdin:
    rijec=rijec.replace("\n","")
    if rijec=="":
        break
    else:
        rj=""
        for i in range(0,len(rijec)):
            if i==0:
                flag=0
                for j in range(1,7):
                    if rijec[i] in d[j]:
                        flag=1
                        rj+=str(j)
                        break
                if flag==0:
                    rj+='0'
            else:
                flag=0
                for j in range(1,7):
                    if rijec[i] in d[j] and rijec[i-1] not in d[j]:
                        flag=1
                        rj+=str(j)
                        break
                if flag==0:
                    rj+='0'
        sol=""
        for slovo in rj:
            if slovo!='0':
                sol+=slovo
        print(sol)
                            
                        
                
            
            