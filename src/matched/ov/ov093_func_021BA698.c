/*
 * function: func_021BA698
 * address: 0x021BA698
 * packet: pkt_ov093_021BA698
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA710 0x021BA710 thumb ov093
 *   func_021B997C 0x021B997C thumb ov093
 */

typedef unsigned char u8;
extern u8 func_021BA710(int, int);
extern u8 func_021B997C(u8 *, int);
void func_021BA698(u8 *p, int k)
{
 int i;
 i = func_021BA710(p[0x46c], k);
 *((u8 *)(*(char **)p + i) + 0x44) = func_021B997C(p, k);
}
