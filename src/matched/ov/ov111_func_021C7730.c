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
 *   G3D_LIGHT_DeleteSlots  0x02048C4C  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[0x100];
    void *f100;
} Work;

extern void G3D_LIGHT_DeleteSlots(void *p);
extern void G3D_SYSTEM_Exit(void);

void func_021C7730(Work *p)
{
    G3D_LIGHT_DeleteSlots(p->f100);
    G3D_SYSTEM_Exit();
}
