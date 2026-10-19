/*
 * function: BTL_CLIENT_ResetActionCursor
 * address: 0x021CE2E8
 * packet: pkt_ov093_021CE2E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ACTION_SetNone 0x021D8434 thumb ov093
 */
#include "../include/Obj07769.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_ACTION_SetNone(u32 *p);
void BTL_CLIENT_ResetActionCursor(u8 *p) { *(u8 * *)&((struct Obj07769 *)p)->fC=p+0x124; BTL_ACTION_SetNone((u32 *)(p+0x124)); *(u8 * *)&((struct Obj07769 *)p)->fD8=*(u8 * *)&((struct Obj07769 *)p)->fC; ((struct Obj07769 *)p)->fDC=4; }
