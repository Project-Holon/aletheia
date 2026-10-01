/*
 * function: func_021BF080
 * address: 0x021BF080
 * packet: pkt_ov210_021BF080
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021BF0DA..021BF0DC is zero alignment padding.
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned char u8;
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
void func_021BF080(u8 *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x10c);
        if (v != -1) func_0204A8D4(v);
    }
    for (i = 0; i < 6; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x124);
        if (v != -1) func_0204ADA4(v);
    }
    for (i = 0; i < 4; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x13c);
        if (v != -1) func_0204AFD8(v);
    }
}
