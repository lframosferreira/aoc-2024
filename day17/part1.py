rega = int(input().split(":")[1])
regb = int(input().split(":")[1])
regc = int(input().split(":")[1])
_ = input()
prog = list(map(lambda x: int(x), input().split(":")[1].split(",")))

ans = ""

iptr = 0
opptr = 1


def combo_operand(x):
    match x:
        case 0 | 1 | 2 | 3:
            return x
        case 4:
            return rega
        case 5:
            return regb
        case 6:
            return regc
    return -1


while iptr < len(prog):
    inst = prog[iptr]
    op = prog[opptr]
    match inst:
        case 0:
            rega = rega // (2 ** combo_operand(op))
        case 1:
            regb = regb ^ op
        case 2:
            regb = combo_operand(op) % 8
        case 3:
            if rega == 0:
                iptr += 2
                opptr += 2
                continue
            iptr = op
            opptr = iptr + 1
            continue
        case 4:
            regb = regc ^ regb
        case 5:
            ans += str(combo_operand(op) % 8) + ","
        case 6:
            regb = rega // (2 ** combo_operand(op))
        case 7:
            regc = rega // (2 ** combo_operand(op))

    iptr += 2
    opptr += 2

ans = ans[:-1]
print(ans)
