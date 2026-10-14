/*
 * function: func_021F9774, func_021F979C
 * unit: yes
 * extent: empty-return follower 0x021F979C; trailing two-byte padding.
 * address: 0x021F9774
 * packet: pkt_ov186_021F9774
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 */
#include "../include/Obj05496.h"
#include "../include/Obj05497.h"
#include "../include/Obj24791.h"
#include "../include/Obj24792.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
void func_021F9774(char *p,char *q) { ((struct Obj05496 *)p)->f8=((struct Obj05497 *)q)->f4;((struct Obj05496 *)p)->f0=((struct Obj05497 *)q)->fC;((struct Obj05496 *)p)->fC=((struct Obj05497 *)q)->f8;((struct Obj05496 *)p)->f4=BR_GRAPHIC_GetActorUnit((u8 *)(((struct Obj05497 *)q)->f0));((struct Obj05496 *)p)->f10=((struct Obj05497 *)q)->f14;((struct Obj05496 *)p)->f14=((struct Obj24792 *)(*(char * *)&((struct Obj24791 *)(*(char * *)&((struct Obj05497 *)q)->f18))->fC))->f4; }
void func_021F979C(void) {}
