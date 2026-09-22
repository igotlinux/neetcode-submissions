class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        hashset = {
            ")":"(",
            "}":"{",
            "]":"["
        }

        for c in s:
            if c in hashset:
                if not stack or stack[-1] != hashset[c]:
                    return False
                stack.pop()

            else:
                stack.append(c)
        return len(stack) == 0
        