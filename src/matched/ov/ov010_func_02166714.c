/*
 * function: func_02166714
 * address: 0x02166714
 * packet: pkt_ov010_02166714
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef signed short s16;
typedef unsigned char u8;
void func_02166714(u8 *p, s16 n) {
    int q;
    *(s16 *)(p+4) = n;
    q = *(s16 *)(p+4) / 1350;
    if (*(int *)(p+8) <= q) *(int *)(p+8) = q;
}
