/**
 * @file touch.h
 *
 */

#ifndef TICK_H
#define TICK_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/
#define LVGL_TICK_MS 1U
#define LVGL_TASK_PERIOD_TICK 5U

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lvgl_tick_init(void);

void lvgl_wait_to_call_timer_handler(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*TOUCH_H*/
