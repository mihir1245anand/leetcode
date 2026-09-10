# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, r: Optional[TreeNode]) -> int:
        return (f:=lambda n:n and (lambda sm,k,q:(sm,k,q+(n.val==sm//k)))(
            *map(sum,zip((n.val,1,0),f(n.left),f(n.right)))) or (0,0,0))(r)[2]
        