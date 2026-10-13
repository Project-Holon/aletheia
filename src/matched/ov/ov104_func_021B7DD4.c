/*
 * function: IRC_RHYTHM_RunPrintQueue
 * address:  0x021B7DD4
 * packet:   pkt_ov104_021B7DD4
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 */
#include "../include/Obj22219.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int IRC_RHYTHM_RunPrintQueue(u8 *p) { return PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj22219 *)p)->f8)); }
