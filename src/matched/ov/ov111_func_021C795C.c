/*
 * function: func_021C795C
 * address:  0x021C795C
 * packet:   pkt_ov111_021C795C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4C0  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[4];
    void *f4;
    unsigned char pad8[0xC];
    void *f14;
} Work;

struct PrintSys;
extern void func_0201C4C0(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);

void func_021C795C(Work *p)
{
    func_0201C4C0(p->f14);
    GF_FONT_Delete(p->f4);
}
