/*
 * function: func_021C1D7C
 * address:  0x021C1D7C
 * packet:   pkt_021C1D7C
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

void func_021C1D7C(unsigned char *p, short a)
{
    *(short *)p = a;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = 0;
    *(int *)(p + 0xc) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1b0) = 0x7db;
    p[0x1ac] = 0;
    *(short *)(p + 0x1b4) = -0xb2f;
    *(short *)(p + 0x1b6) = -0xc9;
    *(short *)(p + 0x1b8) = -0x1000;
}
