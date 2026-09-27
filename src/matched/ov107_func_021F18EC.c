/*
 * function: func_021F18EC
 * address:  0x021F18EC
 * packet:   pkt_ov107_021F18EC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201ED04  0x0201ED04  thumb
 */

typedef struct {
    unsigned char pad00[0x24];
    void *f24;
} Ov107Ctx;

void func_0201ED04(void *);

void func_021F18EC(Ov107Ctx *p)
{
    if (p->f24 != 0) {
        func_0201ED04(p->f24);
        p->f24 = 0;
    }
}
