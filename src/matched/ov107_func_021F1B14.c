/*
 * function: func_021F1B14
 * address:  0x021F1B14
 * packet:   pkt_ov107_021F1B14
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef struct {
    unsigned char pad00[0x18];
    void *f18;
} Ov107Ctx;

int func_021F1B14(Ov107Ctx *p)
{
    if (p->f18 == 0) {
        return 1;
    }
    return 0;
}
