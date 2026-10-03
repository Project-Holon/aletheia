/*
 * function: func_021BD8C4
 * address: 0x021BD8C4
 * packet: pkt_ov209_021BD8C4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor; extern u32 func_0204B98C(struct Actor *);
u32 func_021BD8C4(char *p,u32 idx) {return func_0204B98C(*(struct Actor **)(p+idx*4+0xa74));}
