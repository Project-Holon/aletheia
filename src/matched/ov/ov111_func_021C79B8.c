/*
 * function: func_021C79B8
 * address:  0x021C79B8
 * packet:   pkt_ov111_021C79B8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[0x10C];
    int state;
} Work;

typedef unsigned int   u32;
extern u32 func_020221A4(void);

int func_021C79B8(Work *p)
{
    if (func_020221A4()) {
        p->state = 1;
    }
    return 1;
}
