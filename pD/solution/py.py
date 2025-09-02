import sys

sys.set_int_max_str_digits(1000000)
a, op, b, unused, c = input().split(" ")

ops = {"*": lambda x, y: x * y, "+": lambda x, y: x + y, "-": lambda x, y: x - y}
assert op in ops

a = int(a)
b = int(b)
c = int(c)

if ops[op](a, b) == c:
    print("Yes")
else:
    print("No")
