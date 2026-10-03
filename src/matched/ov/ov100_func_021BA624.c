/*
 * function: func_021BA624
 * address: 0x021BA624
 * packet: pkt_ov100_021BA624
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 */
typedef unsigned short u16;
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0201DD60(void);
void func_021BA624(unsigned a)
{
 func_0203F8F4(*(u16 *)(a+0x278));
 func_02045088(*(u16 *)(a+0x278));
 func_0201DD60();
}
