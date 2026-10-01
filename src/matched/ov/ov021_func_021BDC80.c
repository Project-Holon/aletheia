/*
 * function: func_021BDC80
 * address:  0x021BDC80
 * packet:   pkt_ov021_021BDC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 */

typedef short s16;

typedef struct {
    char pad[0xC];
    void *fC;
    char pad2[0x10];
    s16 s20;
} Inner;

typedef struct {
    Inner *f0;
} Obj;

extern int func_02188D20(void *a);
extern void func_021BC550(int a, int b);

void func_021BDC80(Obj *p)
{
    Inner *q = p->f0;

    func_021BC550(func_02188D20(q->fC), q->s20);
}
