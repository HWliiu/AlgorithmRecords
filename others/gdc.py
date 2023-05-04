"""
辗转相除法求最大公约数
"""


def gcd1(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def gcd2(a, b):
    if b == 0:
        return a
    return gcd2(b, a % b)


if __name__ == "__main__":
    print(gcd2(36, 81))
