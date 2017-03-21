T=int(input())
for i in range(0,T):
    N=int(input())
    pozivi=input()
    pozivi=pozivi.split(" ")
    for j in range(0,len(pozivi)):
        pozivi[j]=int(pozivi[j])
    Mile=0
    Juice=0
    for j in range(0,len(pozivi)):
        Juice=Juice+((pozivi[j]//60)+1)*15
        Mile=Mile+((pozivi[j]//30)+1)*10
    if Mile<Juice:
        print("Case {}: Mile {}".format(i+1,Mile))
    elif Mile==Juice:
        print("Case {}: Mile Juice {}".format(i+1,Mile))
    else:
        print("Case {}: Juice {}".format(i+1,Juice))