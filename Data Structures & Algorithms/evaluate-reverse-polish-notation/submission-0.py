class Solution:

  def evalRPN(self, tokens: list[str]) -> int:
    stack = []
    ops = {"+", "-", "*", "/"}

    for token in tokens:
      if token in ops:
        b = stack.pop()  # Second operand
        a = stack.pop()  # First operand

        if token == "+":
          stack.append(a + b)
        elif token == "-":
          stack.append(a - b)
        elif token == "*":
          stack.append(a * b)
        elif token == "/":
          # int(a / b) truncates toward zero for both positive and negative values
          stack.append(int(a / b))
      else:
        stack.append(int(token))

    return stack[0]


