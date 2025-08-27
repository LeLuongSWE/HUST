n = 100000
arr = [0]*50000 + [1000]*50000
with open("testC.in", "w") as f:
    f.write(str(n) + "\n")
    f.write(" ".join(map(str, arr)) + "\n")
