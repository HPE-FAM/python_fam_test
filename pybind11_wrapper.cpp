// Pybind11 wrapper for C++
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
        //.def("run_fam_add_example", &Test::run_fam_add_example)
	//.def("run_fam_initialize_example", &Test::run_fam_initialize_example)
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
	.def("fam_add",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t >(&fam::fam_add) , "add1")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_add) , "add2")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_add),"add3")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_add) , "add4")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_add) , "add5")
	.def("fam_add",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_add) , "add6")
	.def("fam_subtract",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t >(&fam::fam_subtract) , "sub1")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_subtract) , "sub2")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_subtract),"sub3")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_subtract) , "sub4")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_subtract) , "sub5")
	.def("fam_subtract",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_subtract) , "sub6")
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
	.def("fam_destroy_region", &fam::fam_destroy_region)
	.def("fam_max",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t >(&fam::fam_max) , "max1")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_max) , "max2")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_max),"max3")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_max) , "max4")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_max) , "max5")
	.def("fam_max",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_max) , "max6")
	.def("fam_and",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_and),"and1")
	.def("fam_and",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_and) , "and2")
	.def("fam_or",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_or),"or1")
	.def("fam_or",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_or) , "or2")
	.def("fam_xor",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_xor),"xor1")
	.def("fam_xor",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_xor) , "xor2")
	.def("fam_swap",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t >(&fam::fam_swap) , "swap1")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t >(&fam::fam_swap) , "swap2")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t >(&fam::fam_swap),"swap3")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t >(&fam::fam_swap) , "swap4")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , float >(&fam::fam_swap) , "swap5")
	.def("fam_swap",py::overload_cast<Fam_Descriptor * , uint64_t , double >(&fam::fam_swap) , "swap6")
	.def("fam_compare_swap",py::overload_cast< Fam_Descriptor* , uint64_t , int32_t, int32_t >(&fam::fam_compare_swap) , "cmp1")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , int64_t,int64_t >(&fam::fam_compare_swap) , "cmp2")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint32_t,uint32_t >(&fam::fam_compare_swap),"cmp3")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , uint64_t,uint64_t >(&fam::fam_compare_swap) , "cmp4")
	.def("fam_compare_swap",py::overload_cast<Fam_Descriptor * , uint64_t , int128_t , int128_t>(&fam::fam_compare_swap) , "cmp5")

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

	py::enum_<Fam_Redundancy_Level>(m, "Kind")
    	.value("NONE", Fam_Redundancy_Level::NONE)
    	.value("RAID1", Fam_Redundancy_Level::RAID1)
	.value("RAID5", Fam_Redundancy_Level::RAID5)
    	.export_values();



}
