/*
 * function: func_021D7220
 * address: 0x021D7220
 * packet: pkt_ov120_021D7220
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021D71B8 0x021D71B8 thumb ov120
 */
typedef unsigned char u8;
extern void func_0204B3B4(void *);
extern void func_021D71B8(u8 *, void *, int);
void func_021D7220(u8 *p, void *q)
{
    int i;
    if (q) {
        if (*(void **)(p + 0x14c)) func_0204B3B4(*(void **)(p + 0x14c));
        for (i = 0; i < 5; i++) *(void **)(p + 0x14c + i * 4) = *(void **)(p + 0x150 + i * 4);
        *(void **)(p + 0x160) = 0;
        func_021D71B8(p, q, 5);
    }
}
