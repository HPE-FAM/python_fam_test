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
	Fam_Region_Descriptor * region1 =NULL;
		try {
				region1 = myFam->fam_create_region("my_Region100", (uint64_t)10000000, 0777 , RAID5);
			} 
		catch (Fam_Exception &e) 
			{
				printf("Create region/Allocate Data item failed: %d: %s\n",e.fam_error(), e.fam_error_msg());
			}
		return region1 ; 
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
/*
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


*/
