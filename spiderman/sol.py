N = int(input())

for _ in range(N):
    M = int(input())

    dists = [int(x) for x in input().split()]

    curr_stage = [(0,0)]
    for dist in dists:
        new_stage = []
        for state in curr_stage:
            currheight = state[0]
            maxheight = state[1]
            prospectiveheightup = currheight + dist
            prospectiveheightdown = currheight - dist
            decision = None
            if prospectiveheightdown >= 0:
                decision = prospectiveheightdown
            else:
                decision = prospectiveheightup
                maxheight = max(maxheight, prospectiveheightup)
            new_stage.append((decision,maxheight))
        curr_stage = new_stage
    memo = dict() # find lowest height building at each step, don't explore if it's suboptimal




