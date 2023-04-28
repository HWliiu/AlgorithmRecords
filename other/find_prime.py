import math


def find_prime(n):
    exclude = set()  # 筛法求素数
    for i in range(2, n + 1):
        if i in exclude:
            continue
        flag = True
        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                flag = False  # 说明i是素数
        if flag:
            for k in range(i + 1, n + 1):
                if k % i == 0:  # 筛除素数i的倍数
                    exclude.add(k)
            print(i, end=" ")


if __name__ == "__main__":
    find_prime(100)
