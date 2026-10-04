/*
 * function: func_021D5E48
 * address: 0x021D5E48
 * packet: pkt_ov115_021D5E48
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   func_02027974 0x02027974 thumb
 *   func_0201FEBC 0x0201FEBC thumb
 */
#include "../include/Obj08044.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void func_02027974(struct Obj *);
extern u32 func_0201FEBC(u8 *);
void func_021D5E48(u8 *p) { switch(((struct Obj08044 *)p)->f0) { case 0: func_02027974(*(struct Obj * *)&((struct Obj08044 *)p)->f20); break; case 1: ((struct Obj08044 *)p)->f28=func_0201FEBC(*(u8 * *)&((struct Obj08044 *)p)->f24); break; } }
