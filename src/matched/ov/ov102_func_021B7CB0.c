/*
 * function: IRC_COMPATIBLE_MENU_UpdateTextQueue
 * address:  0x021B7CB0
 * packet:   pkt_ov102_021B7CB0
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 */
#include "../include/Obj22143.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
void IRC_COMPATIBLE_MENU_UpdateTextQueue(u8 *p) { PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj22143 *)p)->f8)); }
