/*
 * function: func_021DBBC4
 * address: 0x021DBBC4
 * packet: pkt_ov183_021DBBC4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x021DBC66
 * symbols:
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_MainProfileScreen 0x021FD6B0 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 */
#include "../include/Obj02892.h"
#include "../include/Obj24542.h"
#include "../include/Obj24543.h"
#include "../include/Obj24544.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern int BR_NET_HandleNetError(char *p);
extern void BR_PROC_SYS_FlushWindows(void *);
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *p);
extern void BR_UTIL_RunHandles(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int BR_UTIL_FlushText(u8 *p);
extern int BR_UTIL_MainProfileScreen(u8 *p);
extern void BR_UTIL_FlushWindow(void *);
int func_021DBBC4(int a,int b,int c,char *p)
{
    int i;
    if(GAME_DATA_IsSaving(((struct Obj24542 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f28)==0 && BR_NET_HandleNetError(((struct Obj24543 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f24)==2) {
        BR_PROC_SYS_FlushWindows(((struct Obj24544 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f14);
        return 1;
    }
    BR_UTIL_RunTask(((struct Obj02892 *)p)->f8);
    if(BR_UTIL_IsTaskIdle(((struct Obj02892 *)p)->f8)) return 1;
    for(i=0;i<2;i++) BR_UTIL_RunHandles(*(void **)(p+i*4+0xc));
    PRINTSYS_QUE_Main(((struct Obj02892 *)p)->f4);
    for(i=0;i<2;i++) if(*(void **)(p+i*4+0x28)) BR_UTIL_FlushText(*(void **)(p+i*4+0x28));
    for(i=0;i<5;i++) if(*(void **)(p+i*4+0x30)) BR_UTIL_FlushText(*(void **)(p+i*4+0x30));
    if(((struct Obj02892 *)p)->f44) BR_UTIL_MainProfileScreen(((struct Obj02892 *)p)->f44);
    if(((struct Obj02892 *)p)->f18) BR_UTIL_FlushWindow(((struct Obj02892 *)p)->f18);
    return 0;
}
