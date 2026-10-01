/*
 * function: func_021BD5D4
 * address:  0x021BD5D4
 * packet:   pkt_ov021_021BD5D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _ffix          0x0209C494  arm
 *   func_021BD304  0x021BD304  thumb  ov021
 */

typedef struct {
    float f0;
    float f4;
} Q;

typedef struct {
    char pad[0xC];
    void *fC;
} Obj;

extern Q *func_021BD304(Obj *p);
extern void func_0202590C(void *a, int b, int c);

void func_021BD5D4(Obj *p)
{
    Q *q = func_021BD304(p);
    int x = (int)q->f0;
    int y = (int)q->f4;

    func_0202590C(p->fC, x, y);
}
