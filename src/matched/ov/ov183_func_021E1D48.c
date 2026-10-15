/*
 * function: func_021E1D48
 * address: 0x021E1D48
 * packet: pkt_ov183_021E1D48
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 */
#include "../include/Obj04579.h"
#include "../include/Obj24630.h"
#include "../include/Obj24631.h"
#include "../include/Obj24632.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern int BR_NET_HandleNetError(char *p);
extern void BR_PROC_SYS_FlushWindows(int);
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *p);
extern void BR_UTIL_RunHandles(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BR_UTIL_FlushWindow(void *p);
int func_021E1D48(int a,int b,int c,char *p)
{
    int i;
    if (!GAME_DATA_IsSaving((const u8 *)(((struct Obj24630 *)(*(char * *)&((struct Obj04579 *)p)->f18))->f14)) && BR_NET_HandleNetError((char *)(((struct Obj24631 *)(*(char * *)&((struct Obj04579 *)p)->f18))->f10))==2) {
        BR_PROC_SYS_FlushWindows(((struct Obj24632 *)(*(char * *)&((struct Obj04579 *)p)->f18))->fC);
        return 1;
    }
    BR_UTIL_RunTask((u8 *)(((struct Obj04579 *)p)->f4));
    if (BR_UTIL_IsTaskIdle((int *)(((struct Obj04579 *)p)->f4))) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)(*(int *)(p+i*4+0x10)));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj04579 *)p)->f0));
    BR_UTIL_FlushWindow((void *)(((struct Obj04579 *)p)->fC));
    return 0;
}
