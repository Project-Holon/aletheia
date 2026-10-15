/*
 * function: BR_CODEIN_ButtonDestroy
 * address: 0x021DB740
 * packet: pkt_ov183_021DB740
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Explicit call arms preserve the original conditional argument branch.
 * symbols:
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_BTN_Delete 0x021F9F48 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj10727.h"
#include "../include/Obj14419.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct S020315D4;
extern void BR_RES_ApplyBgSet(int,unsigned),BR_BTN_Delete(u8 *),BR_UTIL_DeleteHandles(char *);
extern void func_020315D4(struct S020315D4 *);
int BR_CODEIN_ButtonDestroy(struct S020315D4 *task,int b,char *q,char *p) { if(((struct Obj10727 *)q)->f0<5) BR_RES_ApplyBgSet(((struct Obj10727 *)q)->f18,3); else BR_RES_ApplyBgSet(((struct Obj10727 *)q)->f18,4); BR_BTN_Delete(*(u8 * *)&((struct Obj14419 *)p)->f0); BR_UTIL_DeleteHandles(*(char * *)&((struct Obj14419 *)p)->f4); func_020315D4(task); return 1; }
