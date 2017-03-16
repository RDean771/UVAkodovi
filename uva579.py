import sys
import math
for line in sys.stdin:
    line=line.replace('\n',"")
    if line!="0:00":
        line=line.split(':')
        minute=float(line[1])*6
        sati=(float(line[0])%12)*30+(minute/12)
        if sati>minute:
            if(sati-minute<=180):
                print("%.3f" %(sati-minute))
            else:
                print("%.3f" %(360-sati+minute))
        else:
            if(minute-sati<=180):
                print("%.3f" %(minute-sati))
            else:
                print("%.3f" %(360-minute+sati))
    else:
        break
        