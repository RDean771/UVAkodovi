T=int(input())
for i in range(0,T):
    N=int(input())
    instructions=[]
    rj=0
    for j in range(0,N):
        uputa=input()
        if uputa=="LEFT":
            rj-=1
            instructions.append(uputa)
        elif uputa=="RIGHT":
            rj+=1
            instructions.append(uputa)
        else:
            uputa=uputa.split(" ")
            pravauputa=instructions[int(uputa[2])-1]
            if pravauputa=="LEFT":
                rj-=1
                instructions.append(pravauputa)
            else:
                rj+=1
                instructions.append(pravauputa)
    print(rj)  
            
