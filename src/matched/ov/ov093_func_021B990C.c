/*
 * function: func_021B990C
 * address: 0x021B990C
 * packet: pkt_ov093_021B990C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 */
typedef unsigned int   u32;
struct S2;
extern u32 func_021B9BF0(struct S2 *p, u32 i);
void *func_021B990C(char *p, unsigned int i, unsigned int j)
{
    return (void *)func_021B9BF0((void *)((unsigned int)p + 4 + i * 28), j);
}
