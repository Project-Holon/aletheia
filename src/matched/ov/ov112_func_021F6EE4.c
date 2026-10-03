/*
 * function: func_021F6EE4
 * address: 0x021F6EE4
 * packet: pkt_ov112_021F6EE4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *);
void func_021F6EE4(void *unused,u8 *p) { func_0204B3B4(*(struct Obj **)(p+28)); *(u32 *)p=0; }
