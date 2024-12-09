input: str = input()

i: int = 0
files: list[tuple[int, int]] = []
empty: list[tuple[int, int]] = []
disk: list[str] = []
for c in input:
    if i % 2 == 0:
        files.append((len(disk), int(c)))
        for _ in range(int(c)):
            disk.append(str(i // 2))
    else:
        if c == "0":
            i += 1
            continue
        empty.append((len(disk), int(c)))
        for _ in range(int(c)):
            disk.append(".")
    i += 1


while len(empty) != 0:
    empty.sort(reverse=True)
    e = empty[-1]
    epos, esize = e
    found_file: bool = False
    for f in files[::-1]:
        fpos, fsize = f
        if fpos < epos:
            continue
        if fsize <= esize:
            found_file = True
            id = disk[fpos]
            for i in range(epos, epos + fsize):
                disk[i] = id
            for i in range(fpos, fpos + fsize):
                disk[i] = "."
            files.remove(f)
            if esize == fsize:
                empty.pop()
            else:
                empty.pop()
                empty.append((epos + fsize, esize - fsize))
            break
    if not found_file:
        empty.pop()

ans: int = 0
for index, c in enumerate(disk):
    if c == ".":
        continue
    ans += index * int(c)

print(ans)
