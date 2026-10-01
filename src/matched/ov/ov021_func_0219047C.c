/*
 * function: func_0219047C
 * address:  0x0219047C
 * packet:   pkt_ov021_0219047C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02194764  0x02194764  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void func_02194764(void *p);

void func_0219047C(u8 *p)
{
    void *q = *(void **)(p + 0x15C);
    if (q != 0)
        func_02194764(q);
}
