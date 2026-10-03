/*
 * function: func_021DD6F4
 * address: 0x021DD6F4
 * packet: pkt_ov093_021DD6F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DD7B8 0x021DD7B8 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
typedef unsigned char  u8;
extern void func_021DD7B8(int a, u8 *b, int c, int *d, int e);

void func_021DD6F4(int a, void *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 4);
}
