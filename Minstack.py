class MinStack:

    def __init__(self):
        # Stack to store all values
        self.stack = []

        # Stack to store the highest consecutive minimums
        # This will get a value pushed if it's a new low or is equal
        # to the current low
        self.currMinStack = []

    def push(self, val: int) -> None:
        self.stack.append(val)

        if(bool(self.currMinStack) and val <= self.currMinStack[-1]):
            self.currMinStack.append(val)
        
        if(not bool(self.currMinStack)):
            self.currMinStack.append(val)
        

    def pop(self) -> None:
        topVal = self.stack[-1]
        self.stack.pop()

        if self.currMinStack[-1] == topVal:
            self.currMinStack.pop()

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.currMinStack[-1]
        
