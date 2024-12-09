input: str = input()

i: int = 0
disk: list[str] = []
for c in input:
    if i % 2 == 0:
        for _ in range(int(c)):
            disk.append(str(i // 2))
    else:
        for _ in range(int(c)):
            disk.append(".")
    i += 1
i = 0
j: int = len(disk) - 1
ans: int = 0
index: int = 0
while i <= j:
    if disk[i] == ".":
        if disk[j] != ".":
            ans += int(disk[j]) * index
            index += 1
            j -= 1
            i += 1
        else:
            j -= 1
    else:
        ans += int(disk[i]) * index
        i += 1
        index += 1

print(ans)
