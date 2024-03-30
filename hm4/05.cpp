def sum_diag(k):
    return (k + 1) * k // 2

N = int(input())
L, R = 0, N
while (L < R):
	mid = (L + R) // 2
	if sum_diag(mid) <= N:
		L = mid + 1
	else:
		R = mid
# print(L, sum_diag(L - 1), sum_diag(L), L - N + sum_diag(L - 1))
prev = sum_diag(L - 1)
# print(N, prev)
if L % 2 == 0:
	if N == prev:
		print(L - N + prev - 1, N - prev + 1, sep='/')
	else:
		print(L - N + prev + 1, N - prev, sep='/')
else:
	if N == prev:
		print(N - prev + 1, L - N + prev - 1, sep='/')
	else:
		print(N - prev, L - N + prev + 1, sep='/')
