/*
 * function: func_0217F8C0
 * address:  0x0217F8C0
 * packet:   pkt_ov019_0217F8C0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Target of src/pending/func_021881D8.c (called at +0x0C4 with the id).  The
 * only caller image-wide is inside func_021881D8's range, so the two ov019
 * callees and the ov019 data argument are carried by `sole-ref` with the
 * region hint; the allocator is an arm9 `matched` (sub_02030734).  Allocates
 * 0xf4 bytes from heap 0x8e, runs two field-init helpers, returns the block.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0217F97C  0x0217F97C  thumb  ov019
 *   func_0217FB70  0x0217FB70  thumb  ov019
 *   d_02180808     0x02180808  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0217F97C(void *p, u16 id);
extern void func_0217FB70(void *p, u16 id);
extern u32 d_02180808[];

void *func_0217F8C0(u16 id)
{
    void *p = func_02030734(id, 0xf4, 1, (const char *)d_02180808, 0x8e);
    func_0217F97C(p, id);
    func_0217FB70((char *)p + 0x20, id);
    return p;
}
