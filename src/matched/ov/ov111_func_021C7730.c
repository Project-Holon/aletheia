/*
 * function: func_021C7730
 * address:  0x021C7730
 * packet:   pkt_ov111_021C7730
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02048C4C  0x02048C4C  arm
 *   func_02046788  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[0x100];
    void *f100;
} Work;

extern void func_02048C4C(void *p);
extern void func_02046788(void);

void func_021C7730(Work *p)
{
    func_02048C4C(p->f100);
    func_02046788();
}
