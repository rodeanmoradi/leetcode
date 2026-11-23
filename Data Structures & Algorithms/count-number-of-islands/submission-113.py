class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        q = deque()
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    q.append((i, j))
                    grid[i][j] = "0"
                    while len(q) > 0:
                        x, y = q.popleft()
                        n = []
                        if x - 1 >= 0:
                            n.append((x - 1, y))
                        if x + 1 < len(grid):
                            n.append((x + 1, y))
                        if y - 1 >= 0:
                            n.append((x, y - 1))
                        if y + 1 < len(grid[0]):
                            n.append((x, y + 1))
                        for n_i in n:
                            if grid[n_i[0]][n_i[1]] == "1":
                                q.append((n_i[0], n_i[1]))
                                grid[n_i[0]][n_i[1]] = "0"
                    count += 1
        
        return count
