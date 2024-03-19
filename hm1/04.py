board = [[1 for _ in range(8)] for _ in range(8)]


for i in range(8):
	s = input().strip()

	for j in range(8):
		if s[j] == 'B':
			board[i][j] = 2

		if s[j] == 'R':
			board[i][j] = 3

for i in range(8):
	for j in range(8):

		if board[i][j] == 2:

			for k in range(1, 8):
				if i + k < 8 and j + k < 8 and (board[i + k][j + k] == 0 or board[i + k][j + k] == 1):
					board[i + k][j + k] = 0
				else:
					break

			for k in range(1, 8):
				if i - k >= 0 and j + k < 8 and (board[i - k][j + k] == 0 or board[i - k][j + k] == 1):
					board[i - k][j + k] = 0
				else:
					break

			for k in range(1, 8):
				if i + k < 8 and j - k >= 0 and (board[i + k][j - k] == 0 or board[i + k][j - k] == 1):
					board[i + k][j - k] = 0
				else:
					break

			for k in range(1, 8):
				if i - k >= 0 and j - k >= 0 and (board[i - k][j - k] == 0 or board[i - k][j - k] == 1):
					board[i - k][j - k] = 0
				else:
					break

		if board[i][j] == 3:
			for k in range(1, 8):
				if i + k < 8 and (board[i + k][j] == 0 or board[i + k][j] == 1):
					board[i + k][j] = 0
				else:
					break

			for k in range(1, 8):
				if j + k < 8 and (board[i][j + k] == 0 or board[i][j + k] == 1):
					board[i][j + k] = 0
				else:
					break

			for k in range(1, 8):
				if i - k >= 0 and (board[i - k][j] == 0 or board[i - k][j] == 1):
					board[i - k][j] = 0
				else:
					break

			for k in range(1, 8):
				if j - k >= 0 and (board[i][j - k] == 0 or board[i][j - k] == 1):
					board[i][j - k] = 0
				else:
					break

res = 0
for i in range(8):
	for j in range(8):
		if (board[i][j] == 1):
			res += 1

print(res)