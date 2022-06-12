# test script
import example

ex = example.Test()
print("Default value: ", ex.read_value())
val = 9000
ex.update_value(val)
print("Updated value: ", ex.read_value())


famObject = example.fam()

print("\nCREATED FAM OBJECT : ", famObject)

y = ex.set_fam_options();

print("\nCREATED FAM OPTIONS OBJECT: ", y)

famObject.fam_initialize("groupname", y)

# r = ex.fam_create_region("samplename", 10000000, '0o77' , example.RAID5)  # variable parameter probls
r = ex.fam_create_region(famObject)
print("FAM CREATE REGION")
print(r)

d = ex.my_fam_allocate(famObject,r)  #wrapper used
print(d)



print('FAM ADD')
# FAM ADD DIRECT FROM FAM API _______________

famObject.fam_add(d, 0, 6.7)
famObject.fam_add(d, 0, 7.6)

res = famObject.fam_fetch_int32(d, 0)
print(res)

#_____________________________________________





print('FAM SUBTRACT')
#FAM SUBTRACT_____________________________________________

famObject.fam_subtract(d, 0, 6.8)
famObject.fam_subtract(d, 0, 9.8)

res = famObject.fam_fetch_float(d, 0)
print(res)

print('FAM MAX')


famObject.fam_max(d, 0, 6)
famObject.fam_max(d, 0, 9)

res1 = famObject.fam_fetch_int32(d, 0)
print(res1)

#______________________________________________

print('FAM AND')
#FAM AND_____________________________________________

famObject.fam_and(d, 0, 6)
famObject.fam_and(d, 0, 9)

res2 = famObject.fam_fetch_int32(d, 0)
print(res2)




print('FAM OR')
#FAM OR_____________________________________________

famObject.fam_or(d, 0, 6)
famObject.fam_or(d, 0, 4)

res3 = famObject.fam_fetch_int32(d, 0)
print(res3)



print('FAM XOR')
#FAM XOR_____________________________________________

famObject.fam_xor(d, 0, 0)
famObject.fam_xor(d, 0, 0)

res4 = famObject.fam_fetch_int32(d, 0)
print(res4)



print('FAM swap')
#FAM SWAP_____________________________________________

famObject.fam_xor(d, 0, 1)
famObject.fam_xor(d, 0, 2)

res5 = famObject.fam_fetch_int32(d, 0)
res6 = famObject.fam_fetch_int32(d, 0)
print(res6)

print('FAM cmp swap')
#FAM SWAP_____________________________________________

famObject.fam_compare_swap(d, 0, 1,2)
famObject.fam_compare_swap(d, 0, 2,3)

res7 = famObject.fam_fetch_int32(d, 0)
print(res7)









famObject.fam_destroy_region(r)
print("DESTROY REGION CALLED FROM FAM API")

#____________________________________________________________________


famObject.fam_finalize("groupname")
print("FINALIZE CALLED FROM FAM API")
famObject.fam_abort(0)
print("ABORT CALLED FROM FAM API")






