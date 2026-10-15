/*
 * function: BR_POKESEARCH_Update
 * address: 0x021F8590
 * packet: pkt_ov185_021F8590
 * region: ov185
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
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_MainProfileScreen 0x021FD6B0 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   MUSICAL_SHOT_SYS_DrawScene 0x021F3C50 thumb ov112
 */
#include "../include/Obj01966.h"
#include "../include/Obj24716.h"
#include "../include/Obj24717.h"
extern int BR_NET_HandleNetError(char *);
extern void BR_PROC_SYS_FlushWindows(char *);
typedef unsigned char  u8;
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *);
extern void BR_UTIL_RunHandles(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int BR_UTIL_FlushText(u8 *p);
extern int BR_UTIL_MainProfileScreen(u8 *p);
extern void BR_UTIL_FlushWindow(void *p);
extern void MUSICAL_SHOT_SYS_DrawScene(u8 *p);
int BR_POKESEARCH_Update(int a,int b,int c,char *p)
{
    int i;
    if (BR_NET_HandleNetError(*(char * *)&((struct Obj24716 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f14)==2) {
        BR_PROC_SYS_FlushWindows(*(char * *)&((struct Obj24717 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f10);
        return 1;
    }
    BR_UTIL_RunTask((u8 *)(*(char * *)&((struct Obj01966 *)p)->f24));
    if (BR_UTIL_IsTaskIdle(*(int * *)&((struct Obj01966 *)p)->f24)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles(*(char **)(p+i*4+56));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj01966 *)p)->f2C));
    if (*(char * *)&((struct Obj01966 *)p)->f1C) BR_UTIL_FlushText((u8 *)(*(char * *)&((struct Obj01966 *)p)->f1C));
    if (*(char * *)&((struct Obj01966 *)p)->f10) BR_UTIL_MainProfileScreen((u8 *)(*(char * *)&((struct Obj01966 *)p)->f10));
    if (*(char * *)&((struct Obj01966 *)p)->f4) BR_UTIL_FlushWindow(*(char * *)&((struct Obj01966 *)p)->f4);
    if (*(char * *)&((struct Obj01966 *)p)->f14) MUSICAL_SHOT_SYS_DrawScene((u8 *)(*(char * *)&((struct Obj01966 *)p)->f14));
    return 0;
}
