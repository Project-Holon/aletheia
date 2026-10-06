/*
 * function: func_021F4650
 * address:  0x021F4650
 * packet:   pkt_ov048_021F4650
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_021F4DBC  0x021F4DBC  thumb  ov048
 *   func_0215897C  0x0215897C  thumb  ov010
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
typedef unsigned int   u32;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_020061E4(u32 a);
extern void *func_021F4DBC(int a, int b, int c);
extern void func_0215897C(void *a, void *b);

int func_021F4650(int a, int b)
{
    void *r6;
    void *r7;
    void *sp;
    int r4;

    r6 = func_0215A5F4((void *)b);
    r7 = func_0215A5DC((void *)b);
    sp = func_0201210C((void *)r7);
    r4 = (int)func_02159B10((void *)a, (void *)b);
    func_020061E4(0x547);
    func_0215897C(r6, func_021F4DBC((int)r7, (int)sp, r4));
    return 1;
}
