/*
 * function: func_021F4D40
 * address: 0x021F4D40
 * packet: pkt_ov112_021F4D40
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 */
#include "../include/Obj05310.h"
#include "../include/Obj13826.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u16 low:4; u16 bit4:1; u16 rest:11; } Bits;
extern void BILLBOARD_FreeElem(void *,u32);
struct Obj0204F1A0;
extern void BILLBOARD_ReleaseImageVramIfUsed(struct Obj0204F1A0 *a0, u32 a1);
void func_021F4D40(u8 *p,u8 *e) { BILLBOARD_FreeElem(((struct Obj13826 *)p)->f4,((struct Obj05310 *)e)->f8); if (((Bits *)e)->bit4==1) BILLBOARD_ReleaseImageVramIfUsed(((struct Obj13826 *)p)->f4,((struct Obj05310 *)e)->f4); ((struct Obj05310 *)e)->f0=((struct Obj05310 *)e)->f0 & ~1; ((struct Obj05310 *)e)->f0=((struct Obj05310 *)e)->f0 & ~2; }
