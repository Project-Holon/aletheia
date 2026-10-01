/*
 * function: func_021CCFC0
 * address:  0x021CCFC0
 * packet:   pkt_ov021_021CCFC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the +0xB0 handle of the work block from its +0xA4 object and +0xA8 entry.
 *
 * symbols:
 *   func_02190F64  0x02190F64  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0xa4];
    void *fA4;
    void *fA8;
    u8 padAC[4];
    void *fB0;
    void *fB4;
} Work;

extern void *func_02190F64(void *a, void *b);

void func_021CCFC0(Work *w)
{
    w->fB0 = func_02190F64(w->fA4, w->fA8);
}
