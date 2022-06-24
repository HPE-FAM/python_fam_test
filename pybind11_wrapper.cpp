#include <pybind11/pybind11.h>
#include "test.h"

#include <fam/fam.h>
#include <fam/fam_exception.h>

using namespace std;

using namespace openfam;

namespace py = pybind11;

PYBIND11_MODULE(example, m) {




    py::class_<Test>(m, "Test")
        .def(py::init<>())
        .def("update_value", &Test::update_value)
        .def("read_value", &Test::read_value)
        .def("run_fam_add_example", &Test::run_fam_add_example)
	.def("run_fam_initialize_example", &Test::run_fam_initialize_example)
	.def("set_fam_options", &Test::set_fam_options, py::return_value_policy::move)
	.def("fam_create_region",&Test::my_create_region)
	.def("my_fam_allocate",&Test::my_fam_allocate)
	//.def("fam_destroy_region",&Test::my_destory_region)
	//.def("myfam_finalize", &Test::fam_finalize_wrapper)
	//.def("myadd",&Test::myadd)
        ;

    py::class_<fam>(m, "fam")
	.def(py::init<>())
	.def("fam_abort", &fam::fam_abort)
	.def("fam_initialize", &fam::fam_initialize)
	.def("fam_finalize",&fam::fam_finalize)


	//Gives error when called
	.def("fam_and",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_and) , "and1")
	.def("fam_and",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_and) , "and2")

	.def("fam_fetch_and",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_fetch_and) , "fand1")
	.def("fam_fetch_and",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_fetch_and) , "fand2")

	.def("fam_or",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_or) , "or1")
	.def("fam_or",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_or) , "or2")

	.def("fam_fetch_or",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_fetch_or) , "for1")
	.def("fam_fetch_or",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_fetch_or) , "for2")	

	.def("fam_xor",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_xor) , "xor1")
	.def("fam_xor",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_xor) , "xor2")

	.def("fam_fetch_xor",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_fetch_xor) , "fxor1")
	.def("fam_fetch_xor",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_fetch_xor) , "fxor2")

	.def("fam_fence", &fam::fam_fence)
	

	// works
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_add) , "add1")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_add) , "add2")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_add), "add3")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_add), "add4")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_add), "add5")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_add), "add6")

	.def("fam_fetch_add",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_fetch_add) , "fadd1")
	.def("fam_fetch_add",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_fetch_add) , "fadd2")
	.def("fam_fetch_add",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_fetch_add), "fadd3")
	.def("fam_fetch_add",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_fetch_add), "fadd4")
	.def("fam_fetch_add",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_fetch_add), "fadd5")
	.def("fam_fetch_add",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_fetch_add), "fadd6")

	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_max) , "max1")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_max) , "max2")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_max) , "max3")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_max) , "max4")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_max) , "max5")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_max) , "max6")

	.def("fam_fetch_max",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_fetch_max) , "fmax1")
	.def("fam_fetch_max",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_fetch_max) , "fmax2")
	.def("fam_fetch_max",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_fetch_max) , "fmax3")
	.def("fam_fetch_max",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_fetch_max) , "fmax4")
	.def("fam_fetch_max",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_fetch_max) , "fmax5")
	.def("fam_fetch_max",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_fetch_max) , "fmax6")

	.def("fam_min",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_min) , "min1")
	.def("fam_min",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_min) , "min2")
	.def("fam_min",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_min) , "min3")
	.def("fam_min",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_min) , "min4")
	.def("fam_min",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_min) , "min5")
	.def("fam_min",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_min) , "min6")

	.def("fam_fetch_min",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_fetch_min) , "fmin1")
	.def("fam_fetch_min",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_fetch_min) , "fmin2")
	.def("fam_fetch_min",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_fetch_min) , "fmin3")
	.def("fam_fetch_min",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_fetch_min) , "fmin4")
	.def("fam_fetch_min",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_fetch_min) , "fmin5")
	.def("fam_fetch_min",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_fetch_min) , "fmin6")

	.def("fam_subtract",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t >(&fam::fam_subtract) , "sub1")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_subtract) , "sub2")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_subtract),"sub3")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_subtract) , "sub4")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_subtract) , "sub5")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_subtract) , "sub6")

	.def("fam_fetch_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_fetch_subtract) , "fsub1")
	.def("fam_fetch_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_fetch_subtract) , "fsub2")
	.def("fam_fetch_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_fetch_subtract), "fsub3")
	.def("fam_fetch_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_fetch_subtract), "fsub4")
	.def("fam_fetch_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_fetch_subtract), "fsub5")
	.def("fam_fetfam_fetch_subtractch_add",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_fetch_subtract), "fsub6")

	.def("fam_swap",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t >(&fam::fam_swap) , "swap1")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_swap) , "swap2")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_swap),"swap3")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_swap) , "swap4")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_swap) , "swap5")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_swap) , "swap6")

	.def("fam_compare_swap",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t, int32_t >(&fam::fam_compare_swap) , "cswap1")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t, int64_t >(&fam::fam_compare_swap) , "cswap2")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t, uint32_t >(&fam::fam_compare_swap),"cswap3")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t, uint64_t >(&fam::fam_compare_swap) , "cswap4")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , int128_t, int128_t >(&fam::fam_compare_swap) , "cswap5")

	.def("fam_set",py::overload_cast<Fam_Descriptor * , uint64_t , int32_t >(&fam::fam_set) , "set1")
	.def("fam_set",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_set) , "set2")
	.def("fam_set",py::overload_cast<Fam_Descriptor * , uint64_t , int128_t >(&fam::fam_set) , "set3")
	.def("fam_set",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_set) , "set4")
	.def("fam_set",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_set) , "set5")
	.def("fam_set",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_set) , "set6")
	.def("fam_set",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_set) , "set7")

	.def("fam_fetch_int32", &fam::fam_fetch_int32)
	.def("fam_fetch_int64", &fam::fam_fetch_int64)
	.def("fam_fetch_int128", &fam::fam_fetch_int128)
	.def("fam_fetch_uint32", &fam::fam_fetch_uint32)
	.def("fam_fetch_uint64", &fam::fam_fetch_uint64)
	.def("fam_fetch_float", &fam::fam_fetch_float)
	.def("fam_fetch_double", &fam::fam_fetch_double)

	//.def("fam_list_options", &fam::fam_list_options)

	.def("fam_lookup_region", &fam::fam_lookup_region)

	.def("fam_destroy_region", &fam::fam_destroy_region)
	.def("fam_deallocate", &fam::fam_deallocate)

	.def("fam_quiet", &fam::fam_quiet)

	.def("fam_copy", &fam::fam_copy)

	.def("fam_stat",py::overload_cast<Fam_Descriptor * , Fam_Stat * >(&fam::fam_stat) , "stat1")
	.def("fam_stat",py::overload_cast<Fam_Region_Descriptor * , Fam_Stat * >(&fam::fam_stat) , "stat2")

	.def("fam_lookup", &fam::fam_lookup)

	.def("fam_barrier_all", &fam::fam_barrier_all)




	//.def("fam_create_region", &fam::fam_create_region)
	//.def("fam_add", &fam::fam_add<Fam_Descriptor*, uint64_t , int32_t>())
	//.def("fam_create_region", &fam::fam_create_region)
	//.def("fam_allocate", &fam::fam_allocate)
	;






	py::class_<Fam_Descriptor>(m,"Fam_Descriptor")
	.def(py::init<>());

	py::class_<Fam_Region_Descriptor>(m,"Fam_Region_Descriptor")
	.def(py::init<>());


	py::class_<Fam_Options>(m,"Fam_Options")
	.def(py::init<>());


	py::class_<Fam_Stat>(m,"Fam_Stat")
	.def(py::init<>())
	.def_readwrite("name", &Fam_Stat::name)
	.def_readwrite("size", &Fam_Stat::size)
	.def_readwrite("perm", &Fam_Stat::perm)
	.def_readwrite("key", &Fam_Stat::key)
	;

	py::enum_<Fam_Redundancy_Level>(m, "Kind")
    	.value("NONE", Fam_Redundancy_Level::NONE)
    	.value("RAID1", Fam_Redundancy_Level::RAID1)
	.value("RAID5", Fam_Redundancy_Level::RAID5)
    	.export_values();
	
	py::enum_<Fam_Error>(m, "Kindly")
	.value("FAM_NO_ERROR", Fam_Error::FAM_NO_ERROR)
	.value("FAM_ERR_UNKNOWN", Fam_Error::FAM_ERR_UNKNOWN)
	.value("FAM_ERR_NOPERM", Fam_Error::FAM_ERR_NOPERM)
	.value("FAM_ERR_TIMEOUT", Fam_Error::FAM_ERR_TIMEOUT)
	.value("FAM_ERR_INVALID", Fam_Error::FAM_ERR_INVALID)
	.value("FAM_ERR_LIBFABRIC", Fam_Error::FAM_ERR_LIBFABRIC)
	.value("FAM_ERR_SHM", Fam_Error::FAM_ERR_SHM)
	.value("FAM_ERR_NOT_CREATED", Fam_Error::FAM_ERR_NOT_CREATED)
	.value("FAM_ERR_NOTFOUND", Fam_Error::FAM_ERR_NOTFOUND)
	.value("FAM_ERR_ALREADYEXIST", Fam_Error::FAM_ERR_ALREADYEXIST)
	.value("FAM_ERR_ALLOCATOR", Fam_Error::FAM_ERR_ALLOCATOR)
	.value("FAM_ERR_RPC", Fam_Error::FAM_ERR_RPC)
	.value("FAM_ERR_PMI", Fam_Error::FAM_ERR_PMI)
	.value("FAM_ERR_OUTOFRANGE", Fam_Error::FAM_ERR_OUTOFRANGE)
	.value("FAM_ERR_NULLPTR", Fam_Error::FAM_ERR_NULLPTR)
	.value("FAM_ERR_UNIMPL", Fam_Error::FAM_ERR_UNIMPL)
	.value("FAM_ERR_RESOURCE", Fam_Error::FAM_ERR_RESOURCE)
	.value("FAM_ERR_INVALIDOP", Fam_Error::FAM_ERR_INVALIDOP)
	.value("FAM_ERR_RPC_CLIENT_NOTFOUND", Fam_Error::FAM_ERR_RPC_CLIENT_NOTFOUND)
	.value("FAM_ERR_MEMSERV_LIST_EMPTY", Fam_Error::FAM_ERR_MEMSERV_LIST_EMPTY)
	.value("FAM_ERR_METADATA", Fam_Error::FAM_ERR_METADATA)
	.value("FAM_ERR_MEMORY", Fam_Error::FAM_ERR_MEMORY)
	.value("FAM_ERR_NAME_TOO_LONG", Fam_Error::FAM_ERR_NAME_TOO_LONG)
	.value("FAM_ERR_ATL_QUEUE_FULL", Fam_Error::FAM_ERR_ATL_QUEUE_FULL)
	.value("FAM_ERR_ATL_QUEUE_INSERT", Fam_Error::FAM_ERR_ATL_QUEUE_INSERT)
	.value("FAM_ERR_ATL_NOT_ENABLED", Fam_Error::FAM_ERR_ATL_NOT_ENABLED)
	.value("FAM_ERR_ATL", Fam_Error::FAM_ERR_ATL)
	.export_values();
	//py::class_<Fam_Exception>(m, "Fam_Exception")
	
	//.def(py::init<>())
	//.def(py::init<const std::string &,Fam_Error >())
	//.def(py::init<const char*>())
	//.def("fam_error",&Fam_Exception::fam_error,"FUnction errors")
	//.def(py::init<Fam_Error  , const char *>())
	//.def(py::init<const Fam_Exception *>())
	//.def("fam_error_msg",&Fam_Exception::fam_error_msg,"Function  Description")
	//.def("what",&Fam_Exception::what,"Function  Description");
	


 
//static py::exception<Fam_Exception> ex(m, "Fam_Exception");
    //py::register_exception_translator([](std::exception_ptr p) {
        //try {
            //if (p) {
             //   std::rethrow_exception(p);
            //}
        //} catch (const Fam_Exception &e) {
            // Set MyException as the active python error
		
          //  ex(e.what());
     //   }
   // });



	//py::register_exception<>(m, "PyExp");
	    

	   






}