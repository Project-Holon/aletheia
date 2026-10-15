/*
 * function: BR_BTN_UpdatePrint
 * address: 0x021F9FE8
 * packet: pkt_ov186_021F9FE8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 */
#include "../include/Obj08326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void BR_UTIL_RunTask(u8 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void BR_UTIL_FlushWindow(void *p);
void BR_BTN_UpdatePrint(char *p) { BR_UTIL_RunTask((u8 *)(((struct Obj08326 *)p)->fC));PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08326 *)p)->f4C);if(*(char * *)&((struct Obj08326 *)p)->f50)BR_UTIL_FlushWindow(*(char * *)&((struct Obj08326 *)p)->f50); }
