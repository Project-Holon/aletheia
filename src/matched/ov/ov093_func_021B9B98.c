/*
 * function: func_021B9B98
 * address: 0x021B9B98
 * packet: pkt_ov093_021B9B98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 * symbols:
 *   func_021D5B7C 0x021D5B7C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D5B7C(void *);
u8 func_021B9B98(u8 *p) {
    int i;
    u32 n;
    i = 0;
    n = 0;
    for (; i < p[24]; i++) if (func_021D5B7C(((void **)p)[i])) n++;
    return n;
}
