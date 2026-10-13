/*
 * unit: yes
 * function: func_021D3D7C, func_021D3D84
 * address: 0x021D3D7C
 * packet: pkt_ov093_021D3D7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Claimed follower 021D3D84 is included; target byte accessor has a verified shard.
 * symbols:
 *   BTL_FIELD_GetCountdownByte 0x021EF9A8 thumb ov093
 */
#include "../include/Obj21206.h"
#include "../include/Obj21207.h"
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_021D3D7C(u8 *p) { return ((struct Obj21206 *)p)->f118; }
extern u8 BTL_FIELD_GetCountdownByte(u32 *);
u8 func_021D3D84(u8 *p) { return BTL_FIELD_GetCountdownByte(*(u32 * *)&((struct Obj21207 *)p)->f34); }
