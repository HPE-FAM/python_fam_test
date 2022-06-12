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

res = famObject.fam_fetch_float(d, 0)
print(res)

#_____________________________________________


print('FAM SUBTRACT')
#FAM SUBTRACT_____________________________________________

famObject.fam_subtract(d, 0, 6.8)
famObject.fam_subtract(d, 0, 9.8)

res = famObject.fam_fetch_float(d, 0)
print(res)

#______________________________________________


#ex.fam_destory_region(famObject, r)
#print("DESTROY REGION CALLED FROM WRAPPER")


# Doesn't work for now - incompatible function arguments (error)____

famObject.fam_destroy_region(r)
print("DESTROY REGION CALLED FROM FAM API")

#____________________________________________________________________



famObject.fam_finalize("groupname")
print("FINALIZE CALLED FROM FAM API")
famObject.fam_abort(0)
print("ABORT CALLED FROM FAM API")







