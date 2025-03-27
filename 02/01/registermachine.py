import time


instructions = []
registers = [0, 0, 0, 0, 0, 0, 0, 0] # 8 Registers
flags = [0, 0, 0] # 3 Bit Flags


with open("instructions.asm") as file:
    for line in file:
        instructions.append(line)


n = 0
while(n < len(instructions)):

    i = instructions[n].split()
    print(i)


    if(i[0] == "MOV"):
        if(i[1][0] == "$"): # Check for constant Number
            registers[int(i[2])] = int(i[1][1:])
        else:
            registers[int(i[2])] = registers[int(i[1])]
    
    if(i[0] == "ADD"):
        if(i[1][0] == "$"): # Check for constant Number
            registers[int(i[2])] += int(i[1][1:])
        else:
            registers[int(i[1])] += registers[int(i[2])]

    if(i[0] == "SUB"):
        if(i[1][0] == "$"): # Check for constant Number
            registers[int(i[2])] -= int(i[1][1:])
        else:
            registers[int(i[1])] -= registers[int(i[2])]

    if(i[0] == "JMP"):
        n = int(i[1])-2

    if(i[0] == "JPF"): # Jump if flag0
        if(flags[0] == 1):
            n = int(i[1])-2

    if(i[0] == "CMP"): # IF 2 $62 or IF 3 4
        if(i[2][0] == "$"): # Check for constant Number
            if(registers[int(i[1])] == int(i[2][1:])):
                flags[0] = 1
            else:
                flags[0] = 0
        else:
            if(registers[int(i[1])] == registers[int(i[2])]):
                flags[0] = 1
            else:
                flags[0] = 0

    if(i[0] == "SET"):
        flags[int(i[1])] = 1 

    if(i[0] == "DEL"):
        flags[int(i[1])] = 0 

    if(i[0] == "NOP"):
        n = n # Do nothing



    print(flags)
    print(registers)

    n += 1
    time.sleep(0.05)

