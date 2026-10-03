/*
 * function: func_021C6E18
 * address: 0x021C6E18
 * packet: pkt_ov128_021C6E18
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204B92C(void *,u32);
extern void func_0204B878(void *,u16);
extern void func_0204B9A0(void *);
void func_021C6E18(u8 *p,int i,u16 a) {func_0204B92C(*(void **)((u32)p+0x15c+i*4),1);func_0204B878(*(void **)((u32)p+0x15c+i*4),a);func_0204B9A0(*(void **)((u32)p+0x15c+i*4));}
