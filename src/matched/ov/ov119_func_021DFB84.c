/*
 * function: func_021DFB84
 * address:  0x021DFB84
 * packet:   pkt_ov119_021DFB84
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_021DFB4C  0x021DFB4C  thumb  ov119
 *   d_021E80F4     0x021E80F4  data  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *sub_02030734(u32, u32, int, const char *, u32);
extern void func_021DFB4C(void *, void *, void *);

void *func_021DFB84(void *a0, void *a1, void *a2, u32 heapId)
{
    void *r = sub_02030734(heapId, 0x38, 1, (const char *)0x021E80F4, 0xD2);

    *(void **)r = a0;
    func_021DFB4C(r, a1, a2);
    *(u32 *)((char *)r + 0xC) = 0;
    return r;
}
