/*
 * function: B_PLIST_MAIN_CheckMoveUsable
 * address: 0x02210F1C
 * packet: pkt_ov198_02210F1C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Group the unsigned address sum as base plus row, then column, then offset.
 * symbols:
 *   WAZA_TOOL_IsHmMove 0x0202F72C thumb
 */
#include "../include/Obj08364.h"
#include "../include/Obj25273.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WAZA_TOOL_IsHmMove(void *,u16,u16);
u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p) { u8 *q;unsigned long i;int row;q=*(u8 * *)&((struct Obj25273 *)p)->f0;i=q[75];if(i==4)return 0;row=(u32)p+q[32]*76;return WAZA_TOOL_IsHmMove(((struct Obj08364 *)q)->f0,*(u16 *)(row+i*8+48),((struct Obj08364 *)q)->f10); }
