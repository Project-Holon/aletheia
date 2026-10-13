/*
 * function: IRC_RESULT_RunPrintQueue
 * address:  0x021B7C94
 * packet:   pkt_ov105_021B7C94
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 */
#include "../include/Obj22243.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
u32 IRC_RESULT_RunPrintQueue(u8 *p) { return PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj22243 *)p)->f8)); }
