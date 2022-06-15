#include <fam/fam.h>
#include <fam/fam_exception.h>

using namespace openfam;

class Test {
    public:
        Test();
        void update_value(int);
        int read_value();
	int run_fam_add_example();
	int run_fam_initialize_example();
	Fam_Options* set_fam_options();
	Fam_Region_Descriptor * my_create_region(fam * myFam, const char * RNAME);
	Fam_Descriptor *  my_fam_allocate(fam * myFam,Fam_Region_Descriptor * region, const char * INAME);
	int myadd(fam * myFam,Fam_Descriptor * d ,int x ,int y);
	void my_destory_region(fam * myFam , Fam_Region_Descriptor * region);
	void fam_finalize_wrapper(fam *f, const char* groupName);
    private:
        int value_;
};
