/*
 * function: BR_DOWNLOAD_Main
 * address: 0x021F857C
 * packet: pkt_ov184_021F857C
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   MUSICAL_SHOT_SYS_DrawScene 0x021F3C50 thumb ov112
 */
#include "../include/Obj03336.h"
#include "../include/Obj24698.h"
#include "../include/Obj24699.h"
extern int BR_NET_HandleNetError(char *);
extern void BR_PROC_SYS_FlushWindows(char *);
typedef unsigned char  u8;
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *);
extern void BR_UTIL_RunHandles(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BR_UTIL_FlushWindow(void *p);
extern void MUSICAL_SHOT_SYS_DrawScene(u8 *p);
int BR_DOWNLOAD_Main(int a,int b,int c,char *p)
{
    int i;
    if (BR_NET_HandleNetError(*(char * *)&((struct Obj24698 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f14)==2) {
        BR_PROC_SYS_FlushWindows(*(char * *)&((struct Obj24699 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f10);
        return 1;
    }
    BR_UTIL_RunTask((u8 *)(*(char * *)&((struct Obj03336 *)p)->fC));
    if (BR_UTIL_IsTaskIdle(*(int * *)&((struct Obj03336 *)p)->fC)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles(*(char **)(p+i*4+20));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj03336 *)p)->f20));
    if (*(char * *)&((struct Obj03336 *)p)->f10) BR_UTIL_FlushWindow(*(char * *)&((struct Obj03336 *)p)->f10);
    if (*(char * *)&((struct Obj03336 *)p)->f0) MUSICAL_SHOT_SYS_DrawScene((u8 *)(*(char * *)&((struct Obj03336 *)p)->f0));
    return 0;
}
