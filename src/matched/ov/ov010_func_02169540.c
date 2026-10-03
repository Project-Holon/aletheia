/*
 * function: func_02169540
 * address:  0x02169540
 * packet:   pkt_ov010_02169540
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail call initialising the record at +0x84 in mode 1.
 *
 * symbols:
 *   sub_02046C9C  0x02046C9C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Rec;
extern void sub_02046C9C(struct Rec *rec, u32 mode, u32 value);

void func_02169540(unsigned char *a, unsigned int v)
{
    sub_02046C9C(*(void **)(a + 0x84), 1, v);
}
