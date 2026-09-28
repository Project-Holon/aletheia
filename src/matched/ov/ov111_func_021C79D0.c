/*
 * function: func_021C79D0
 * address:  0x021C79D0
 * packet:   pkt_ov111_021C79D0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021C7E48  0x021C7E48  thumb
 *   func_021C8364  0x021C8364  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[0x14];
    void *f14;
} Work;

extern int func_0201C6B4(void *p);
extern void func_021C7E48(Work *p);
extern void func_021C8364(Work *p);

int func_021C79D0(Work *p)
{
    if (func_0201C6B4(p->f14) == 0) {
        return 1;
    }
    func_021C7E48(p);
    func_021C8364(p);
    return 1;
}
