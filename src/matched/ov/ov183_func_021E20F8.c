/*
 * function: func_021E20F8
 * address: 0x021E20F8
 * packet: pkt_ov183_021E20F8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 */
#include "../include/Obj06612.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *p);
extern void BR_UTIL_RunHandles(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BR_UTIL_FlushWindow(void *p);
extern int BR_UTIL_FlushText(u8 *p);
int func_021E20F8(int a,int b,int c,char *p)
{
    int i;
    BR_UTIL_RunTask((u8 *)(((struct Obj06612 *)p)->f8));
    if (BR_UTIL_IsTaskIdle((int *)(((struct Obj06612 *)p)->f8))) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)(*(int *)(p+i*4+0x14)));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj06612 *)p)->f0));
    if (((struct Obj06612 *)p)->f4) BR_UTIL_FlushWindow((void *)(((struct Obj06612 *)p)->f4));
    for (i=0;i<2;i++) if (*(int *)(p+i*4+0xc)) BR_UTIL_FlushText((u8 *)(*(int *)(p+i*4+0xc)));
    return 0;
}
