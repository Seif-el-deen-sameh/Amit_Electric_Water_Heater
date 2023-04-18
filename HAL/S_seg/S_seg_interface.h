/*
 * S_seg_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_S_SEG_S_SEG_INTERFACE_H_
#define HAL_S_SEG_S_SEG_INTERFACE_H_
#include "S_seg_private.h"

void S_seg_Initialize(S_seg_mode mode);
void S_seg_clear(S_seg_mode mode);
void S_seg_print_two_segments(u8 num);



#endif /* HAL_S_SEG_S_SEG_INTERFACE_H_ */
