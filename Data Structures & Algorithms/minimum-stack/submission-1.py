class MinStack:
    
    def __init__(self):
        self._min_stack = []
        self._min_elements = []

    def push(self, val: int) -> None:
        self._min_stack.append(val)
        if self._min_elements:
            if val <= self._min_elements[-1]:
                self._min_elements.append(val)
        else:
            self._min_elements.append(val)

    def pop(self) -> None:
        l = self._min_elements[-1]
        r = self._min_stack.pop()
        if l == r:
            self._min_elements.pop()

    def top(self) -> int:
        return self._min_stack[-1]

    def getMin(self) -> int:
        return self._min_elements[-1]
        
