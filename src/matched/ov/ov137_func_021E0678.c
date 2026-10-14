/*
 * function: GURU2_MAIN_RemoveBackgroundUnit
 * address: 0x021E0678
 * packet: pkt_ov137_021E0678
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: original narrows the second call argument with lsls/lsrs #16 at 021E0682/021E0686, so this caller's extern uses u16.
 * symbols:
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 */
#include "../include/Obj14234.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
void GURU2_MAIN_RemoveBackgroundUnit(char *p) { G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj14234 *)p)->fAF4,(u16)(((struct Obj14234 *)p)->fDA4)); }
