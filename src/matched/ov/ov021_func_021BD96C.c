/*
 * function: func_021BD96C
 * address:  0x021BD96C
 * packet:   pkt_ov021_021BD96C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[4];
    void *f4;
    char pad2[0x44];
    int f4C;
} Inner;

typedef struct {
    char pad[8];
    Inner *f8;
} Obj;

extern int func_0202952C(void *a, int b);
extern void func_02012374(void *a, int b);

void func_021BD96C(Obj *p, void *b)
{
    Inner *q = p->f8;

    func_02012374(b, func_0202952C(q->f4, 0x1E));
    q->f4C = 1;
}
