# Bestimmung des größten gemeinsamen Teilers
def ggT(a, b):
    while(b != 0):
        r = a % b
        a = b
        b = r
    return a

# Rekursive Bestimmung des größten gemeinsamen Teilers
def ggT_rekur(a, b):
    r = a % b
    if r == 0:
        return b
    return ggT_rekur(b, r)

# Bestimmung des kleinsten gemeinsamen Vielfachen
def kgV(a, b):
    return (a*b / ggT(a, b)) 

print(ggT(54, 84))
print(kgV(54, 84))