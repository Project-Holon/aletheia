/*
 * function: func_021BA96C
 * address:  0x021BA96C
 * packet:   pkt_ov070_021BA96C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *   d_021BBA81     0x021BBA81  data  ov070  a1
 */

extern void func_0204B878(unsigned a, unsigned b);
extern unsigned char d_021BBA81[];

void func_021BA96C(int p, unsigned sel)
{
    unsigned i;
    for (i = 0; i < 5; i++) {
        if (i == sel) {
            func_0204B878(*(unsigned *)(p + i * 4 + 0x6AC), d_021BBA81[i * 2]);
        } else {
            func_0204B878(*(unsigned *)(p + i * 4 + 0x6AC), d_021BBA81[i * 2 + 1]);
        }
    }
}
