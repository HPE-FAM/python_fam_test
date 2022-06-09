#include <iostream>
#include "test.h"

#include <string.h>

#include <fam/fam.h>
#include <fam/fam_exception.h>

using namespace std;

using namespace openfam;

Test::Test() {
    cout << "Setting default value..." << endl;
    value_ = 100;

}


// Testing functions___________________________________________________________________
void Test::update_value(int val) {
    value_ = val;
    cout << "Value updated" << endl;
}

int Test::read_value() {
    return value_;
}
//_____________________________________________________________________________________

Fam_Options fam_opts;
Fam_Options* Test::set_fam_options(){

	memset((void*)&fam_opts, 0, sizeof(Fam_Options));
	return &fam_opts;
}

// ________________________________________________________________________________________________________________

Fam_Region_Descriptor * Test::my_create_region(fam * myFam)
{
	Fam_Region_Descriptor * region =NULL;
		try {
				region = myFam->fam_create_region("my_Region100", (uint64_t)10000000, 0777 , RAID5);
			} 
		catch (Fam_Exception &e) 
			{
				printf("Create region/Allocate Data item failed: %d: %s\n",e.fam_error(), e.fam_error_msg());
			}
		return region ; 
}

Fam_Descriptor *  Test::my_fam_allocate(fam * myFam,Fam_Region_Descriptor * region)
{
	Fam_Descriptor * descriptor=NULL ;
		try 
		{
			descriptor = myFam->fam_allocate("my_item100", (uint64_t)(1 * sizeof(int)),0600, region);
		}
		catch (Fam_Exception &e) 
		{
			printf("Create region/Allocate Data item failed: %d: %s\n",e.fam_error(), e.fam_error_msg());
		}
		return descriptor; 
}

int Test::myadd(fam * myFam,Fam_Descriptor * d ,int x ,int y)
{
	myFam->fam_add(d, 0, x);
	myFam->fam_add(d, 0, y);
	int value = myFam->fam_fetch_int32(d, 0);
	printf("result %d",value);
	return value ;
}

void Test::my_destory_region(fam * myFam , Fam_Region_Descriptor * region)
{
 try {

        myFam->fam_destroy_region(region);
    } catch (Fam_Exception &e) {
        printf("Destroy region failed: %d: %s\n", e.fam_error(),
               e.fam_error_msg());
    }
}


void Test::fam_finalize_wrapper(fam *f, const char* groupName){
	try {
        f->fam_finalize("myApplication");
        printf("FAM finalized\n");
	} catch (Fam_Exception &e) {
	printf("FAM Finalization failed: %s\n", e.fam_error_msg());
	f->fam_abort(-1); 
	}
}


// ________________________________________________________________________________________________________________


// Not relevant --- runs only the example api
//___________________________________________________________________

int Test::run_fam_initialize_example(){
    int ret = 0;
    fam *myFam = new fam();
    Fam_Options *fm = (Fam_Options *)malloc(sizeof(Fam_Options));
    memset((void *)fm, 0, sizeof(Fam_Options));
    // assume that no specific options are needed by the implementation
    fm->runtime = strdup("NONE");
    try {
        myFam->fam_initialize("myApplication", fm);
        printf("FAM initialized\n");
    } catch (Fam_Exception &e) {
        printf("FAM Initialization failed: %s\n", e.fam_error_msg());
        myFam->fam_abort(-1); // abort the program
        // note that fam_abort currently returns after signaling
        // so we must terminate with the same value
        return -1;
    }

    // ... Finalization code follows
    try {
        myFam->fam_finalize("myApplication");
        printf("FAM finalized\n");
    } catch (Fam_Exception &e) {
        printf("FAM Finalization failed: %s\n", e.fam_error_msg());
        myFam->fam_abort(-1); // abort the program
        // note that fam_abort currently returns after signaling
        // so we must terminate with the same value
        return -1;
    }
    return (ret);
}

int Test::run_fam_add_example(){
    int ret = 0;
    fam *myFam = new fam();
    Fam_Region_Descriptor *region = NULL;
    Fam_Descriptor *descriptor = NULL;
    Fam_Options *fm = (Fam_Options *)malloc(sizeof(Fam_Options));
    memset((void *)fm, 0, sizeof(Fam_Options));
    // assume that no specific options are needed by the implementation
    fm->runtime = strdup("NONE");
    try {
	myFam->fam_initialize("myApplication", fm);
	printf("FAM initialized\n");
    } catch (Fam_Exception &e) {
	printf("FAM Initialization failed: %s\n", e.fam_error_msg());
	myFam->fam_abort(-1); // abort the program
	// note that fam_abort currently returns after signaling
	// so we must terminate with the same value
	return -1;
    }

    // ... Initialization code here

    try {
	// create a 100 MB region with 0777 permissions and RAID5 redundancy
	region = myFam->fam_create_region("myRegion", (uint64_t)10000000, 0777,
	                                  RAID5);
	// create 50 element unnamed integer array in FAM with 0600
	// (read/write by owner) permissions in myRegion
	descriptor = myFam->fam_allocate("myItem", (uint64_t)(50 * sizeof(int)),
	                                 0600, region);
	// use the created region and data item...
	// ... continuation code here
	//
    } catch (Fam_Exception &e) {
	printf("Create region/Allocate Data item failed: %d: %s\n",
	       e.fam_error(), e.fam_error_msg());
	return -1;
    }

    try {
	// look up the descriptor to a previously allocated data item
	// (an integer array with at least 10 elements)
	// Fam_Descriptor *descriptor = myFam->fam_lookup("myItem", "myRegion");

	// Atomically add a value of 100 to first interger element in the array
	myFam->fam_add(descriptor, 0, 100);

	// ensure that the add operation is complete
	myFam->fam_quiet();
	// The first integer in FAM is now added a value of 100

	printf("fam_add successful!!\n");
	// ... subsequent code here
    } catch (Fam_Exception &e) {
	printf("fam API failed: %d: %s\n", e.fam_error(), e.fam_error_msg());
	ret = -1;
    }

    try {
	// we are finished. Destroy the region and everything in it
	myFam->fam_destroy_region(region);
	// printf("fam_destroy_region successfull\n");
    } catch (Fam_Exception &e) {
	printf("Destroy region failed: %d: %s\n", e.fam_error(),
	       e.fam_error_msg());
	ret = -1;
    }

    // ... Finalization code follows
    try {
	myFam->fam_finalize("myApplication");
	printf("FAM finalized\n");
    } catch (Fam_Exception &e) {
	printf("FAM Finalization failed: %s\n", e.fam_error_msg());
	myFam->fam_abort(-1); // abort the program
	// note that fam_abort currently returns after signaling
	// so we must terminate with the same value
	return -1;
    }
    return (ret);
}

//___________________________________________________________________

