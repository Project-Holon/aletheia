/*
 * function: func_021CD204
 * address:  0x021CD204
 * packet:   pkt_ov021_021CD204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards to func_0204932C with the holder's archive, the caller's argument and the holder's +4 field.
 *
 * symbols:
 *   func_0204932C  0x0204932C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    void *arc;
    u32 f4;
} Holder;

struct ArcFile;
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);

void func_021CD204(Holder *h, u32 a)
{
    func_0204932C(h->arc, a, &h->f4);
}
