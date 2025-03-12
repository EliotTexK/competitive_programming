n = int(input())

if n == 1:
    print(1)
    exit()

nums = [int(x) for x in input().split()]

i = 1
cards_left = n

while i < n:
    prev = nums[i-1]
    curr = nums[i]
    if (curr+prev)%2 == 0:
        cards_left -= 2
        i += 2
    else:
        i += 1

print(cards_left)