/**
 * @file touch.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#if LV_USE_LOG

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lvgl_log_init(void)
{
	lv_log_register_print_cb(print_cb);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void print_cb(const char *buf)
{
    PRINTF("\r%s\n", buf);
}

#else

void lvgl_log_init(void)
{

}
#endif
