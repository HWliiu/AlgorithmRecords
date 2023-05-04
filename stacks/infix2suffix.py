"""
将中缀表达式转换为后缀表达式
"""
# 支持的运算符
operator = "+-*/"
# 出栈优先级
prior = {"*": 2, "/": 2, "+": 1, "-": 1, "(": 0}


def main():
    infix_exp = "a+b-a*((c+d)/e-f)+g"
    # TODO: 检查表达式括号匹配的正确性
    suffix_exp = ""
    stack = []
    for c in infix_exp:
        if c in operator:
            # 若为除括号外的其他运算符，当其优先级高于除'('外的栈顶运算符时，直接入栈。
            # 否则从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符，
            # 直到一个比它优先级低的或遇到了一个左括号为止
            while len(stack) and prior[stack[-1]] >= prior[c]:
                # '('的优先级最低，不会在这里出栈，所以'('不出现在后缀表达式
                suffix_exp += stack.pop()
            stack.append(c)
        elif c == "(":
            # 遇到'('直接入栈
            stack.append(c)
        elif c == ")":
            # 若为')'，则依次把栈中的运算符加入后缀表达式，直到出现 '('，并从栈中删除'('
            while stack[-1] != "(":
                suffix_exp += stack.pop()
            stack.pop()
        else:
            # 遇到数字时，直接加入后缀表达式
            suffix_exp += c
    # 当扫描的中缀表达式结束时，栈中的所有运算符依次出栈加入后缀表达式
    while len(stack):
        suffix_exp += stack.pop()

    print(f'"{infix_exp}"==>"{suffix_exp}"')
    # "a+b-a*((c+d)/e-f)+g"==>"ab+acd+e/f-*-g+"


if __name__ == "__main__":
    main()
