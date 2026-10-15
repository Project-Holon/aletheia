/*
 * function: BR_CODEIN_SidebarDestroy
 * address: 0x021DB36C
 * packet: pkt_ov183_021DB36C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj08308.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct S020315D4;
extern void BR_UTIL_DeleteHandles(char *);
extern void BR_UTIL_DeleteTask(void *p);
struct PrintSys;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
int BR_CODEIN_SidebarDestroy(struct S020315D4 *task,int b,int c,char *p) { BR_UTIL_DeleteHandles(*(char * *)&((struct Obj08308 *)p)->f14); BR_UTIL_DeleteHandles(*(char * *)&((struct Obj08308 *)p)->f18); PRINTSYS_QUE_Delete(((struct Obj08308 *)p)->fC); BR_UTIL_DeleteTask((void *)(((struct Obj08308 *)p)->f0)); func_020315D4(task); return 1; }
