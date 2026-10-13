/*
 * function: IRC_COMPATIBLE_StepRunnerIsBusy
 * address:  0x021B6BFC
 * packet:   pkt_ov101_021B6BFC
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_Main  0x02031330  arm  arm9
 */
#include "../include/Obj22113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern unsigned int PROCSYS_Main(void *);
unsigned int IRC_COMPATIBLE_StepRunnerIsBusy(u8 *p) { return PROCSYS_Main((void *)((struct Obj22113 *)p)->f0); }
