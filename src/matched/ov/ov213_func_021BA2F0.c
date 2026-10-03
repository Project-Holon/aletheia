/*
 * function: func_021BA2F0
 * address: 0x021BA2F0
 * packet: pkt_ov213_021BA2F0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_021BA014 0x021BA014 thumb ov213
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045808(u32);
extern void func_021BA014(u8 *);
extern void func_020452E8(u32);
void func_021BA2F0(u8 *p) {func_02045808(*(u32 *)(p+24));func_021BA014(p+32);func_020452E8(*(u32 *)(p+28));}
