/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite
 * address: 0x021B9184
 * packet: pkt_ov103_021B9184
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
#include "../include/Obj13740.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void MI_CpuFill8(void *,int,int);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite(u8 *p, struct Obj *q, int v, u8 w) { MI_CpuFill8(p,0,0x2c); *(struct Obj * *)&((struct Obj13740 *)p)->f0=q; ((struct Obj13740 *)p)->f4=w; CLACT_SetActorPaletteOffset(q,(u8)v,1); }
