/**
 * @file touch.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "tick.h"
#include "fsl_debug_console.h"

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
static volatile uint32_t s_tick        = 0U;
static volatile bool s_lvglTaskPending = false;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_tick_init(void)
{
    if (0 != SysTick_Config(SystemCoreClock / (LVGL_TICK_MS * 1000U)))
    {
        PRINTF("Tick initialization failed\r\n");
        while (1)
            ;
    }
}

void lvgl_wait_to_call_timer_handler(void)
{
    while (!s_lvglTaskPending);

    s_lvglTaskPending = false;
}

void SysTick_Handler(void)
{
    s_tick++;
    lv_tick_inc(LVGL_TICK_MS);

    if ((s_tick % LVGL_TASK_PERIOD_TICK) == 0U)
    {
        s_lvglTaskPending = true;
    }
}


/**********************
 *   STATIC FUNCTIONS
 **********************/

