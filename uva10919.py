import sys,pdb
for unos in sys.stdin:
    unos=unos.replace("\n","")
    if unos=="0":
        break
    else:
        unos=unos.split(" ")
        for i in range(0,len(unos)):
            unos[i]=int(unos[i])
        courses=input()
        courses=courses.split(" ")
        stanje=[]
        for i in range(0,unos[1]):
            predmeti=input()
            predmeti=predmeti.split(" ")
            zadodati=[]
            for j in range(2,len(predmeti)):
                zadodati.append(predmeti[j])
            zadodati.append(int(predmeti[1]))
            stanje.append(zadodati)
            
        for i in range(0,len(courses)):
            for j in range(0,len(stanje)):
                if courses[i] in stanje[j]:
                    stanje[j][-1]-=1
        flag=1
        #pdb.set_trace()
        for i in range(0,len(stanje)):
            if stanje[i][-1]>0:
                flag=0
                break
        if flag==0:
            print("no")
        else:
            print("yes")
                    
            
        