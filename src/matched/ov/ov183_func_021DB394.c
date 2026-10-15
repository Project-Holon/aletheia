/*
 * function: BR_CODEIN_SidebarMain
 * address: 0x021DB394
 * packet: pkt_ov183_021DB394
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj06595.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct PrintSys;
extern void BR_UTIL_RunTask(u8 *p);
extern void BR_UTIL_RunHandles(char *);
extern int BR_UTIL_IsTaskIdle(int *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
int BR_CODEIN_SidebarMain(int a,int b,int c,char *p) { BR_UTIL_RunTask((u8 *)(*(int *)&((struct Obj06595 *)p)->f0)); PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj06595 *)p)->fC); BR_UTIL_RunHandles(*(char * *)&((struct Obj06595 *)p)->f14); BR_UTIL_RunHandles(*(char * *)&((struct Obj06595 *)p)->f18); if(BR_UTIL_IsTaskIdle(*(int * *)&((struct Obj06595 *)p)->f0)) return 1; return 0; }
