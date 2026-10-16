/*
 * function: PMS_INPUT_DATA_Delete
 * address: 0x021B95F4
 * packet: pkt_ov110_021B95F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_WORD_Delete 0x020247F0 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22311.h"
extern void PMS_WORD_Delete(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PMS_INPUT_DATA_Delete(char *a) { if(a) { PMS_WORD_Delete(*(char * *)&((struct Obj22311 *)a)->f4); func_020307B0(a); } }
