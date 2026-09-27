/*
 * function: func_021F1900
 * address:  0x021F1900
 * packet:   pkt_ov107_021F1900
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201EFA4  0x0201EFA4  thumb
 */

typedef struct {
    unsigned char pad00[0x24];
    void *f24;
} Ov107Ctx;

void func_0201EFA4(void *obj, int a, int b, int c, int d, int e);

void func_021F1900(Ov107Ctx *p, int a, int b, int c)
{
    func_0201EFA4(p->f24, a, b, c, 0, 1);
}
