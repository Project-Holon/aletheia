/*
 * function: func_021ED8AC
 * address:  0x021ED8AC
 * packet:   pkt_ov093_021ED8AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020311B8  0x020311B8  arm  arm9
 *   func_02031290  0x02031290  arm  arm9
 *   func_021ED8E8  0x021ED8E8  thumb  ov093
 */
typedef unsigned char u8;
struct Q { u8 *a; int b; u8 *c; };
extern void *func_020311B8(void *, void *, int, int);
extern struct Q *func_02031290(void *);
extern void func_021ED8E8(int, struct Q *);
void func_021ED8AC(u8 *p)
{
    struct Q *q;
    q = func_02031290(func_020311B8(*(void **)(p + 0x2c), (void *)func_021ED8E8, 0xc, 1));
    q->a = p;
    q->c = p + 0x40;
    q->b = 0;
    (*q->c)++;
}
