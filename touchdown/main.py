playnums = int(input())
plays = [int(x) for x in input().split()]
downyards=0
downs=0
totalyards=20
for p in plays:
    downs+=1
    downyards+=p
    totalyards+=p
    if downs == 4 and downyards < 10:
        if totalyards <=0:
            print("Safety")
        else: 
            print("Nothing")
        exit()
    elif downs <= 4 and totalyards <= 0:
        print("Safety")
        exit()
    elif downs <= 4 and downyards >= 10:
        downs = 0
        downyards = 0
    elif totalyards >= 100:
        print("Touchdown")
        exit()
else:
    if totalyards <= 0:
        print("Safety")
    elif totalyards < 100:
        print("Nothing")
    else:
        print("Touchdown")
