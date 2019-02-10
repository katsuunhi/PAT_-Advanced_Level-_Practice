poly_1 = [float(n) for n in input().split()]
poly_2 = [float(n) for n in input().split()]



poly_1_exp = [int(n) for n in poly_1[1::2]]
poly_1_coe = poly_1[2::2]

poly_2_exp = [int(n) for n in poly_2[1::2]]
poly_2_coe = poly_2[2::2]

poly = [0]
i = j = 0
while i < len(poly_1_exp) and j < len(poly_2_exp):
	if poly_1_exp[i] > poly_2_exp[j]:
		poly.append(poly_1_exp[i])
		poly.append(poly_1_coe[i])
		i = i + 1
		continue
	if poly_1_exp[i] < poly_2_exp[j]:
		poly.append(poly_2_exp[j])
		poly.append(poly_2_coe[j])
		j = j + 1
		continue
	if poly_1_exp[i] == poly_2_exp[j]:
		if poly_1_coe[i] + poly_2_coe[j] == 0:
			i = i + 1
			j = j + 1
			continue
		poly.append(poly_1_exp[i])
		poly.append(poly_1_coe[i] + poly_2_coe[j])
		i = i + 1
		j = j + 1
while i < len(poly_1_exp):
	poly.append(poly_1_exp[i])
	poly.append(poly_1_coe[i])
	i = i + 1
while j < len(poly_2_exp):
	poly.append(poly_2_exp[j])
	poly.append(poly_2_coe[j])
	j = j + 1

poly[0] = int(len(poly)/2);
for i in poly[:-1]:
	print(i,end = ' ')
print(poly[-1],end = '')
#for i in range(length(po))