from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []

        rows, cols = len(heights), len(heights[0])
        pacific = set()
        atlantic = set()

        def dfs(r, c, visited, prev_height):
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return
            if (r, c) in visited:
                return
            if heights[r][c] < prev_height:
                return

            visited.add((r, c))
            for dr, dc in [(0,1), (0,-1), (1,0), (-1,0)]:
                dfs(r + dr, c + dc, visited, heights[r][c])

        # Pacific = top row + left col
        for c in range(cols):
            dfs(0, c, pacific, heights[0][c])
        for r in range(rows):
            dfs(r, 0, pacific, heights[r][0])

        # Atlantic = bottom row + right col
        for c in range(cols):
            dfs(rows - 1, c, atlantic, heights[rows - 1][c])
        for r in range(rows):
            dfs(r, cols - 1, atlantic, heights[r][cols - 1])

        # Cells reachable from both
        return [[r, c] for r, c in pacific.intersection(atlantic)]