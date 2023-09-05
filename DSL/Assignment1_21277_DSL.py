def inputData(num):

	"""This function takes input of data
	args:
	num - int number of students in the class
	return - tuple this tuple contains list of all students, list of students playing cricket, list of students playing badminton, list of students playing football"""

	#All students in the class
	data = []

	#Students playing cricket
	A = []

	#Students playing badminton
	B = []

	#Students playing football
	C = []

	#Taking input from the user
	for val in range(num):
		stud = input("Enter name of student:")
		data += [stud]
		
		a = int(input("Do you play cricket?(0/1):"))
		b = int(input("Do you play badminton?(0/1):"))
		c = int(input("Do you play football?(0/1):"))

		#Checking that student plays which sport

		if a == 1:
			A += [stud]
		
		if b == 1:
			B += [stud]
			
		if c == 1:
			C += [stud]
			
	return data, A, B, C
		
		
def intersection(a, b):
	"""This fucntion performs intersection operations on set i. e. it gives list of the elements which are common in
	both the lists i. e. sets
	args:
	a - list It is set on which you want to perform the operations
	b - list It is set on which you want to perform the operations
	return - list It is set of elements which are common in both the sets"""

	#common elements of a and b
	inter = []
	
	for val in a:
		for val2 in b:
			#Checking whether the element in list a exist in list b
			if val == val2:
				inter += [val]
	
	return inter
	
def union(a, b):

	"""This function performs the union operation on sets i. e. it gives set which contains elements of both sets in
	which no dublicate entries are present
	args:
	a - list It is set on which you want to perform the operations
	b - list It is set on which you want to perform the operations
	return - list It is set of elements which elements of both sets are present"""

    #elements of a and b
	uni = []

	#copying data from a to uni
	for val in a:
		uni += [val]

	#copying data from b to uni
	for val in b:
		flag = True
		for val2 in uni:
			#checking whether the element to be inserted in already present in the uni to avoid dublication
			if val == val2:
				flag = False
		if flag:
			uni += [val]
			
	return uni
			
def differ(a, b):

	"""This function performs the difference operation in set
	args:
	a - list It is set on which you want to perform the operations
	b - list It is set on which you want to perform the operations
	return - list It is set of elements which contains element of a which are not present in b"""

	#elements of a which are not present in b
	diff = []

	#finding common elements in a and b
	inter = intersection(a, b)

	#adding elements in uni from a which are not present in the b
	for val in a:
		flag = True
		for val2 in inter:
			#checking whether the element is present in the b or not
			if val == val2:
				flag = False
		if flag:
			diff += [val]

		
	return diff

def printData(data, A, B, C):
	print("List of the students : ", data)
	print("Students playing cricket : ", A)
	print("Students playing badminton : ", B)
	print("Students playing football : ", C)

def printA_inter_B(A, B):
	# Students who plays both cricket and badminton
	A_inter_B = intersection(A, B)
	print("Students who plays both cricket and badminton : ", A_inter_B)

def printA_uni_B_diff_A_inter_B(A, B):
	# Students who plays either cricket or badminton but not both
	A_inter_B = intersection(A, B)
	A_uni_B = union(A, B)
	A_uni_B_diff_A_inter_B = differ(A_uni_B, A_inter_B)
	print("Students who plays either cricket or badminton but not both : ", A_uni_B_diff_A_inter_B)

def printdata_diff_A_diff_B(data, A, B):
	# Students who plays neither cricket nor badminton
	data_diff_A = differ(data, A)
	data_diff_A_diff_B = differ(data_diff_A, B)
	print("Students who play neither cricket nor badminton : ", data_diff_A_diff_B)

def printA_uni_C_diff_B(A, B, C):
	# Students who plays cricket and football but not badminton
	A_uni_C = union(A, C)
	A_uni_C_diff_B = differ(A_uni_C, B)
	print("Student who plays cricket and football but not badminton : ", A_uni_C_diff_B)



#number of students in the class	
num = int(input("Enter the number of students:"))

#name of students,students playing cricket, students playing badminton, student playing football
data, A, B, C = inputData(num)

print("Press 0 for exit\nPress 1 for showing all data\nPress 2 for Students who plays both cricket and badminton\nPress 3 for #Students who plays either cricket or badminton but not both ")
print("Press 4 for Students who plays neither cricket nor badminton\nPress 5 for Students who plays cricket and football but not badminton")

ch = int(input("Enter your choice : "))

while ch != 0:

	if ch == 0:
		break

	elif ch == 1:
		printData(data, A, B, C)

	elif ch == 2:
		printA_inter_B(A, B)

	elif ch == 3:
		printA_uni_B_diff_A_inter_B(A, B)

	elif ch == 4:
		printdata_diff_A_diff_B(data, A, B)

	elif ch == 5:
		printA_uni_C_diff_B(A, B, C)

	else :
		print("Invalid choice!!!")

	ch = int(input("Enter your choice : "))











	
	
				
		
		
