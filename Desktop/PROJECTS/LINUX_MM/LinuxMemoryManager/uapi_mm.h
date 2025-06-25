#include <stdint.h>

//Initialization Functions
void mm_init();

//Registration Function
void mm_instantiate_new_page_family(char *struct_name,uint32_t struct_size);

#define MM_REG_STRUCT(struct_name)  \
    (mm_instantiate_new_page_family(#struct_name,sizeof(struct_name)))