/*
 * function: func_021BA670
 * address: 0x021BA670
 * packet: pkt_ov093_021BA670
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA710 0x021BA710 thumb ov093
 */

typedef unsigned char u8;
extern u8 func_021BA710(int, int);
extern void func_02008494(void *src, void *dst);
void func_021BA670(char *p, int k, int dst)
{
 int i;
 void *q;
 i = func_021BA710(*(u8 *)(p + 0x46c), k);
 q = *(void **)(*(char **)p + i * 4 + 0x34);
 if (q != 0) func_02008494((void *)dst, q);
}
