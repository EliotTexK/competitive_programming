n, k = map(int, input().split())
commands = input().split()
stack = [0]

i = 0
while i < len(commands):
    if commands[i] == "undo":
        undo_amount = int(commands[i+1])
        for _ in range(undo_amount):
            stack.pop()
        i += 2
    else:
        last = stack.pop()
        stack.extend( [ last, ( int(commands[i]) + last ) % n ] )
        i += 1

print(stack.pop())