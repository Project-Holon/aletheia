/*
 * function: func_021BD8F4
 * address: 0x021BD8F4
 * packet: pkt_ov209_021BD8F4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj; extern u32 func_0204B3F4(struct Obj *);
u32 func_021BD8F4(char *p,u32 idx) {return func_0204B3F4(*(struct Obj **)(p+idx*4+0xa74));}
