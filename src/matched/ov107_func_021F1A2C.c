/*
 * function: func_021F1A2C
 * address:  0x021F1A2C
 * packet:   pkt_ov107_021F1A2C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201FEBC  0x0201FEBC  thumb
 */

typedef struct {
    unsigned char pad00[0x50];
    void *f50;
} Ov107Ctx;

int func_0201FEBC(void *);

int func_021F1A2C(Ov107Ctx *p)
{
    int r = func_0201FEBC(p->f50);
    if (r == 0) {
        p->f50 = 0;
        return 1;
    }
    if (r == -2) {
        p->f50 = 0;
        return 2;
    }
    return 0;
}
