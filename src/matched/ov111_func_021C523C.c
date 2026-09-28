/*
 * function: func_021C523C
 * address:  0x021C523C
 * packet:   pkt_ov111_021C523C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C59DC  0x021C59DC  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x32C7];
    u8 blink;
    u8 phase;
} Work;

extern void func_021C59DC(u32 bg, int mode);

void func_021C523C(Work *p, int flag)
{
    if (flag) {
        p->phase = 0;
        p->blink = 0;
    } else {
        p->phase = 2;
    }
    func_021C59DC(7, p->phase);
}
