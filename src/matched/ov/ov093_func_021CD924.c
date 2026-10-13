/*
 * function: BTL_CLIENT_ReadRecorderEntry
 * address: 0x021CD924
 * packet: pkt_ov093_021CD924
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_REC_ReadEntry 0x021EE63C thumb ov093
 */
#include "../include/Obj13352.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *BTL_REC_ReadEntry(u16 *, u32 *);
u16 *BTL_CLIENT_ReadRecorderEntry(u8 *p, u32 *out) { if (*(u16 * *)&((struct Obj13352 *)p)->f10) return BTL_REC_ReadEntry(*(u16 * *)&((struct Obj13352 *)p)->f10,out); return 0; }
