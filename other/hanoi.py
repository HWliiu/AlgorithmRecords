def move(n, a, b, c):
    # 如果只剩一个塔，则直接从a移动到c
    if n == 1:
        print(f"{a}-->{c}")
        return
    # 先将上面的n-1个塔借助c从a移动到b
    move(n - 1, a, c, b)
    # 将第n个塔直接从a移动到c
    print(f"{a}-->{c}")
    # 将n-1个塔借助a从b移动到c
    move(n - 1, b, a, c)


def hanoi(n):
    # 三个塔的名字
    a, b, c = "A", "B", "C"
    # 将n个塔借助b从a移动到c
    move(n, a, b, c)


if __name__ == "__main__":
    hanoi(3)
