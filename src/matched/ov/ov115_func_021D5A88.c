/*
 * function: func_021D5A88
 * address: 0x021D5A88
 * packet: pkt_ov115_021D5A88
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 */
#include "../include/Obj13852.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct PrintSys;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *);
void func_021D5A88(u8 *p) { func_020310C4(((struct Obj13852 *)p)->f44); func_0201C4E4(*(struct PrintSys * *)&((struct Obj13852 *)p)->f48); }
