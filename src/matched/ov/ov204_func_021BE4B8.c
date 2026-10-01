/*
 * function: func_021BE4B8
 * address: 0x021BE4B8
 * packet: pkt_ov204_021BE4B8
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF624 0x021BF624 thumb ov204
 *   func_021BF67C 0x021BF67C thumb ov204
 *   func_021BF7CC 0x021BF7CC thumb ov204
 *   d_021BFFE4 0x021BFFE4 data a1
 */
extern void func_021BF624(void *, int, int, int, const void *, unsigned char);
extern void func_021BF67C(void *, int, int, int, unsigned, unsigned char);
extern void func_021BF7CC(void *, unsigned char, int);
extern const char d_021BFFE4[];
int func_021BE4B8(char *p, int unused, unsigned *q)
{
    if (q[1] == 0) {
        func_021BF624(*(void **)(p + 8), q[2], q[3], 0, d_021BFFE4, q[0]);
        func_021BF7CC(*(void **)(p + 8), q[0], 1);
    } else {
        func_021BF67C(*(void **)(p + 8), q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}
