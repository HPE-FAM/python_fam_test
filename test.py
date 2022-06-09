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

print(r)

d = ex.my_fam_allocate(famObject,r)
print(d)

# print(ex.myadd(famObject,d,5,6))



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

#famObject.fam_destory_region(r)


#opts = example.Fam_Options("default", "127.0.0.1", "8787", "sockets", "FAM_THREAD_SERIALIZE", "rpc", "memory_server", "FAM_CONTEXT_DEFAULT", "1", "PMIX")

#print("CREATED FAM OPTIONS OBJ:", opts)


# Fam add and fam_initialize_example give a segmentation fault when fam_options is created using set_fam_options



famObject.fam_finalize("groupname")
print("FINALIZE CALLED FROM FAM API")
famObject.fam_abort(0)
print("ABORT CALLED FROM FAM API")






"""
print("\nRUNNING FAM INITIALIZE EXAMPLE CODE:")

_ = ex.run_fam_initialize_example()



print("\nRUNNING FAM ADD EXAMPLE CODE:")

_ = ex.run_fam_add_example()

"""





