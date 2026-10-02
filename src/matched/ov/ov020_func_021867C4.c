/*
 * function: func_021867C4
 * address:  0x021867C4
 * packet:   pkt_ov020_021867C4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204932C  0x0204932C  arm
 *   d_02187EB4     0x02187EB4  data  ov020  a4
 */

extern int *func_02030734(int, int, int, void *, int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204932C(void *, int, int *);
extern int d_02187EB4;

int *func_021867C4(int a, int id)
{
    int *p = func_02030734(id, 0x38, 1, &d_02187EB4, 0x448);

    p[0] = (int)func_020490F4(0x9a, id);
    func_0204932C((void *)p[0], a, p + 2);
    p[1] = a;
    return p;
}
