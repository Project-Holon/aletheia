/*
 * function: func_021C81F8
 * address:  0x021C81F8
 * packet:   pkt_ov021_021C81F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   d_021DAAE0     0x021DAAE0  data  a2
 *   d_021DAAE2     0x021DAAE2  data  a2
 */

extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02189A00(unsigned char *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0215A5F4(void *p);
extern int func_021C1CB0(int a, char *b, int c);
extern void func_0215897C(void *vm, void *task);
extern unsigned short d_021DAAE0[];
extern unsigned short d_021DAAE2[];

int func_021C81F8(int a, int b)
{
    void *sp4;
    void *sp0;
    int v, found, i;
    void *r5;
    unsigned short r4;

    sp4 = func_0215A5DC((void *)b);
    sp0 = func_02189A00(func_0201210C(sp4));
    v = (int)func_02159B10((void *)a, (void *)b);
    found = 0;
    for (i = 0; i < 17; i++) {
        if (v == d_021DAAE0[i * 2]) {
            found = 1;
            r4 = d_021DAAE2[i * 2];
            break;
        }
    }
    if (found) {
        r5 = func_0215A5F4((void *)b);
        v = func_021C1CB0((int)sp4, sp0, (unsigned char)r4);
        if (v) {
            func_0215897C(r5, (void *)v);
        }
    }
    return 1;
}
