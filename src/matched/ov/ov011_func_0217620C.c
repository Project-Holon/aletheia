/*
 * function: func_0217620C
 * address: 0x0217620C
 * packet: pkt_ov011_0217620C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0217622E.
 * symbols:
 *   func_02175B14 0x02175B14 thumb ov011
 */
typedef unsigned char u8;
extern int func_02175B14(void *p);
int func_0217620C(u8 *p, int key)
{
    if (func_02175B14(p) == 0) return 0;
    if (p[0xa0] == key) return 1;
    return 0;
}
