/*
 * function: func_0216202C
 * address: 0x0216202C
 * packet: pkt_ov010_0216202C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021622D8 0x021622D8 thumb ov010
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021622D8(char *, void *);
int func_0216202C(char *p, void *out, u8 *index)
{
    *index = *(u16 *)(p + 4);
    return func_021622D8(p, out);
}
