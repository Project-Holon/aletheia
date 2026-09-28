/*
 * function: func_021C636C
 * address:  0x021C636C
 * packet:   pkt_ov111_021C636C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6874  0x021C6874  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;

typedef struct {
    u8 pad0[0x32E2];
    s16 scroll;
} Work;

extern void func_021C6874(Work *p, int scroll, int flush, int idx);

void func_021C636C(Work *p, void *bg, void *info)
{
    func_021C6874(p, p->scroll, 0, 0);
}
