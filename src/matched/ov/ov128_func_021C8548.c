/*
 * function: func_021C8548
 * address: 0x021C8548
 * packet: pkt_ov128_021C8548
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_021C6BCC 0x021C6BCC thumb ov128
 *   func_021C867C 0x021C867C thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C87A0(s16 *);
extern void func_021C6BCC(u8 *,u8 *,int,unsigned);
extern void func_021C867C(u8 *p, u8 *a, int n, int heap);
void func_021C8548(s16 *p,u8 *q,u8 *r,u16 heap) {func_021C6BCC(r,q,*(u8 *)(q+24+func_021C87A0(p)),heap);func_021C867C((u8 *)p,r,57,heap);}
