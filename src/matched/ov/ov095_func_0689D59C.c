/*
 * function: func_0689D59C
 * address: 0x0689D59C
 * packet: pkt_ov095_0689D59C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0689D5C8 0x0689D5C8 thumb ov095
 *   func_0689D5B8 0x0689D5B8 thumb ov095
 */
typedef unsigned char u8;
extern u8 func_0689D5C8(u8 *, u8);
extern int func_0689D5B8(void *, int);
int func_0689D59C(u8 *p, void *q, u8 key)
{
    int i;
    i = func_0689D5C8(p, key);
    if (i != 6) return func_0689D5B8(q, i);
    return 0;
}
