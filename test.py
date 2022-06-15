# test script
import example

ex = example.Test()

"""
print("Default value: ", ex.read_value())
val = 9000
ex.update_value(val)
print("Updated value: ", ex.read_value())
"""

famObject = example.fam()
print("\nCREATED FAM OBJECT : ", famObject)

y = ex.set_fam_options();
print("\nCREATED FAM OPTIONS OBJECT: ", y)

famObject.fam_initialize("groupname", y)

# r = ex.fam_create_region("samplename", 10000000, '0o77' , example.RAID5)  # variable parameter probls
r = ex.fam_create_region(famObject, "default name11") #Uses wrapper
print("FAM CREATE REGION")
print(r)

d = ex.my_fam_allocate(famObject,r, "default11")  #Uses wrapper
print("FAM ALLOCATE")
print(d)





print("FAM STAT OBJECT:", end = " " )
fs = example.Fam_Stat()
fs.name, fs.size, fs.key, fs.perm = "fsname", 10, 10, 0o777
print(fs)





try:

	print('FAM ADD')
	# FAM ADD_____________________________________

	famObject.fam_add(d, 0, 6.7)
	famObject.fam_add(d, 0, 7.6)

	res = famObject.fam_fetch_float(d, 0)
	print(res)

	#_____________________________________________





	print('FAM SUBTRACT')
	#FAM SUBTRACT_____________________________________________

	famObject.fam_subtract(d, 0, 6.8)
	famObject.fam_subtract(d, 0, 9.8)

	res = famObject.fam_fetch_float(d, 0)
	print(res)

	#_________________________________________________________





	print('FAM MAX')
	#FAM MAX__________________________________________________

	famObject.fam_max(d, 0, 6)
	famObject.fam_max(d, 0, 9)

	res1 = famObject.fam_fetch_int32(d, 0)
	print(res1)

	#_________________________________________________________




	print('FAM MIN')
	#FAM MIN__________________________________________________

	famObject.fam_min(d, 0, 6)
	famObject.fam_min(d, 0, 9)

	res = famObject.fam_fetch_int32(d, 0)
	print(res)

	#_________________________________________________________







	print("FAM SET")
	#FAM SET______________________________________

	famObject.fam_set(d, 0, 1)

	res = famObject.fam_fetch_int32(d, 0)

	print(res)

	#_____________________________________________

	




	print('FAM SWAP')
	#FAM SWAP_____________________________________________

	oldval = famObject.fam_swap(d, 0, 2)

	print(oldval)
	
	#_____________________________________________________





	print('FAM CMP SWAP')
	#FAM CMP SWAP_________________________________________

	oldVal = famObject.fam_compare_swap(d, 0, 2, 4)

	print(oldVal)

	#_____________________________________________________

	




	print('FAM FETCH_ADD')
	#FAM FETCH ADD_________________________________________

	res = famObject.fam_fetch_add(d, 0, 5)

	print(res)

	#_____________________________________________________


	print('FAM STAT')
	#FAM STAT_____________________________________________

	res = famObject.fam_stat(d, fs)

	print(res)

	#_____________________________________________________



	print('FAM FETCH_SUBTRACT')
	#FAM FETCH SUB_________________________________________

	res = famObject.fam_fetch_subtract(d, 0, 2)

	print(res)

	#_____________________________________________________





	print('FAM FETCH_MIN')
	#FAM FETCH MIN_________________________________________

	res = famObject.fam_fetch_min(d, 0, 9)

	print(res)

	#_____________________________________________________





	
	print('FAM FETCH_MAX')
	#FAM FETCH MAX_________________________________________

	res = famObject.fam_fetch_max(d, 0, 10)

	print(res)

	#_____________________________________________________





	print('FAM DEALLOCATE', end = " ")
	#FAM DEALLOCATE_________________________________________


	dtest = ex.my_fam_allocate(famObject,r, "toBeDeallocated")
	famObject.fam_deallocate(dtest)

	print("CALLED FROM FAM API")

	#_____________________________________________________






	#fam copy gives std::exception
	"""

	print("FAM COPY")
	#FAM COPY_________________________________________

	ds = ex.my_fam_allocate(famObject,r, "source")
	dd = ex.my_fam_allocate(famObject,r, "destination")
	res = famObject.fam_copy(ds, 0, dd, 0, 10)

	print(res)

	#_____________________________________________________
	"""




	print('FAM LOOKUP REGION')
	#FAM LOOKUP REGION_________________________________________

	r1 = famObject.fam_lookup_region("default name")

	print(r1)

	#_____________________________________________________




	print('FAM LOOKUP')
	#FAM LOOKUP_________________________________________

	d1 = famObject.fam_lookup("default", "default name")

	print(d1)

	#_____________________________________________________







	#fam list options. error because of char** not being supported...
	"""

	print('FAM LIST OPTIONS')
	#FAM LIST OPTIONS_________________________________________

	listOptions = famObject.fam_list_options()

	print(listOptions)

	#_____________________________________________________

	"""

	#FAM and, or and xor related functions give an error std::Exception
	"""

	print('FAM FETCH_AND')
	#FAM FETCH AND_________________________________________

	res = famObject.fam_fetch_and(d, 0, 2)

	print(res)

	#_____________________________________________________


	print('FAM FETCH_OR')
	#FAM FETCH OR_________________________________________

	res = famObject.fam_fetch_or(d, 0, 2)

	print(res)

	#_____________________________________________________


	print('FAM FETCH_XOR')
	#FAM FETCH XOR_________________________________________

	res = famObject.fam_fetch_xor(d, 0, 2)

	print(res)

	#_____________________________________________________
	

	print('FAM AND')
	#FAM AND______________________________________

	famObject.fam_and(d, 0, 1)
	
	res = famObject.fam_fetch_int32(d, 0)

	print(res)

	#_____________________________________________
	

	print('FAM OR')
	#FAM OR_______________________________________

	famObject.fam_or(d, 0, 6)
	famObject.fam_or(d, 0, 4)

	res3 = famObject.fam_fetch_int32(d, 0)
	print(res3)

	#_____________________________________________

	print('FAM XOR')
	#FAM XOR______________________________________

	famObject.fam_xor(d, 0, 0)
	famObject.fam_xor(d, 0, 0)

	res4 = famObject.fam_fetch_int32(d, 0)
	print(res4)

	#_____________________________________________

	"""



	#FAM FENCE gives an error std::exception
	"""

	print("FAM FENCE")
	#FAM_FENCE_____________________________________________

	famObject.fam_fence()
	print("CALLED")	

	#______________________________________________________

	"""



	# below functions work, but commented for now
	"""

	print("FAM QUIET", end = " ")
	#FAM_FENCE_____________________________________________

	famObject.fam_quiet()
	print("CALLED FROM FAM API")	

	#______________________________________________________

	"""

	"""
	print("FAM BARRIER ALL", end = " ")
	#FAM_BARRER_ALL_____________________________________________

	famObject.fam_barrier_all()
	print("CALLED FROM FAM API")	

	#______________________________________________________
	"""


	

	



except Exception as e:
	print("SOMETHING WENT WRONG:",  e)
	print()

finally:
	famObject.fam_destroy_region(r)
	print("DESTROY REGION CALLED FROM FAM API")


	famObject.fam_finalize("groupname")
	print("FINALIZE CALLED FROM FAM API")
	famObject.fam_abort(0)
	print("ABORT CALLED FROM FAM API")







