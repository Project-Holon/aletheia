/*
 * function: func_021BA7F8
 * address: 0x021BA7F8
 * packet: pkt_ov093_021BA7F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021CD9B0 0x021CD9B0 thumb ov093
 */

typedef unsigned char u8;
extern int func_021B8B9C(void *, u8);
extern void func_021CD9B0(u8 *p);
void func_021BA7F8(char *p)
{
 unsigned int i;
 for (i = 0; i < 4; i++) {
  if (func_021B8B9C(p, i)) func_021CD9B0(*(void **)(p + i * 4 + 0x10));
 }
}
