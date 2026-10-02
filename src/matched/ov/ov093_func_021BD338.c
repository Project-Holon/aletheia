/*
 * function: func_021BD338
 * address: 0x021BD338
 * packet: pkt_ov093_021BD338
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8588 0x021B8588 thumb ov093
 */
typedef unsigned char u8;
extern unsigned int func_021B8588(void *);
void func_021BD338(u8 *p, u8 *q)
{
    if (func_021B8588(*(void **)(q + 4)) == 3) p[3] = 1;
}
