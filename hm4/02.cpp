def condition(k, n):
	return k * (k + 1) * (k + 5) // 6 - 1 <= n

N = int(input())
L, R = 0, N
while (L < R):
	mid = (L + R + 1) // 2
	if condition(mid, N):
		L = mid
	else:
		R = mid - 1
print(L)