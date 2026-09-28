/*
 * function: func_021EBEE0
 * address:  0x021EBEE0
 * packet:   pkt_ov170_021EBEE0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204BA20 0x0204BA20 arm
 */

typedef struct {
    int pad0;
    int pad4;
    int a;
    int b;
    int c;
    unsigned short pad14;
    unsigned short d;
} Desc;
extern void *func_0204B294(void *a, void *b, void *c, void *d, const Desc *e, unsigned f, unsigned g);
extern void func_0204BA20(void *p, unsigned a);

void *func_021EBEE0(char *w, const Desc *s)
{
    void *r = func_0204B294(*(void **)(w + 0x9E70), *(void **)(w + s->a * 4 + 0x9FF4),
                            *(void **)(w + s->b * 4 + 0xA108), *(void **)(w + s->c * 4 + 0xA134),
                            s, s->d, 0x4C);
    func_0204BA20(r, 0);
    return r;
}
