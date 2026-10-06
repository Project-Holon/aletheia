/*
 * function: func_02166A00
 * address:  0x02166A00
 * packet:   pkt_ov010_02166A00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02166854  0x02166854  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

extern void *func_0215A5F4(void *b);
extern void *func_0215A5DC(void *b);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012F38(int base);
extern unsigned int func_02159B10(void *a0, void *a1);
extern unsigned short *func_02159AE8(void *a, void *b);
typedef unsigned int   u32;
extern void *func_02166854(void *a, int b, u32 c, u32 d, u32 e);
extern void func_0215897C(void *vm, void *task);

int func_02166A00(void *a, void *b)
{
    void *r6 = func_0215A5F4((void *)b);
    void *r7 = func_0215A5DC((void *)b);
    int v1;
    unsigned short *v2;
    unsigned short *v3;
    unsigned short *v4;
    int t;
    func_02012F38((int)func_020120F4((void *)r7));
    v1 = func_02159B10(a, b);
    v2 = func_02159AE8((void *)a, (void *)b);
    v3 = func_02159AE8((void *)a, (void *)b);
    v4 = func_02159AE8((void *)a, (void *)b);
    t = (int)func_02166854(r7, v1, (u32)v2, (u32)v3, (u32)v4);
    if (t == 0)
        return 1;
    func_0215897C(r6, (void *)t);
    return 1;
}
