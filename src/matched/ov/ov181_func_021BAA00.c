/*
 * function: func_021BAA00
 * address: 0x021BAA00
 * packet: pkt_ov181_021BAA00
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA558 0x021BA558 thumb ov181
 */
extern void func_021BA558(char *, unsigned char *);
int func_021BAA00(char *p, unsigned char *q)
{
    if (*(unsigned *)q == 0xffff) {
        *(short *)(p + 0x2da) = *(unsigned short *)(q + 4);
        *(int *)(p + 0x2ec) = 1;
        return 1;
    }
    if (*(short *)(p + 0x2da) == 0)
        *(short *)(p + 0x2da) = *(unsigned short *)(q + 4);
    func_021BA558(p, q);
    if (q[0x16] != 0 || *(unsigned short *)(q + 0x14) != 0) {
        *(int *)(p + 0x2ec) = 1;
        return 1;
    }
    return 0;
}
