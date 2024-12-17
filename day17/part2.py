# THIS CODE BELONGS TO WizzyGeek, I DIDN'T WROTE IT, I only made a few minor changes to fit my use case
# WizzyGeek's GitHub repo: https://github.com/WizzyGeek

import z3

A = int(input().split(":")[1])
B = int(input().split(":")[1])
C = int(input().split(":")[1])
_ = input()
prog = list(map(lambda x: int(x), input().split(":")[1].split(",")))

solver = z3.Solver()

A = z3.BitVec("A", 49)
b = [A, 0, 0]

registers = [0, 1, 2, 3] + b + [float("NaN"), 0]

print(registers)


def do_op(opc, op, reg):
    # print(opc, op)
    match opc:
        case 0:
            reg[4] = reg[4] >> reg[op]
        case 1:
            reg[5] = reg[5] ^ op
        case 2:
            reg[5] = reg[op] & 7
        case 3:
            # we gonna ignore this shid lol
            # if reg[4] != 0:
            reg[8] = op - 2
        case 4:
            reg[5] = reg[5] ^ reg[6]
        case 5:
            return reg[op] & 7
        case 6:
            reg[5] = reg[4] >> reg[op]
        case 7:
            reg[6] = reg[4] >> reg[op]
        case x:
            print("WTF", x)
    return None


def csat(p, reg):
    eidx = 0
    lp = len(p)
    while eidx != lp:
        x = do_op(p[reg[8]], p[reg[8] + 1], reg)
        if x != None:
            solver.add(x == p[eidx])
            eidx += 1
        reg[8] += 2

    solver.add(reg[4] == 0)


csat(prog, registers)

ans = 8888888888888888888888
while solver.check():
    ans = min(ans, solver.model()[A].as_long())
    print(ans)
