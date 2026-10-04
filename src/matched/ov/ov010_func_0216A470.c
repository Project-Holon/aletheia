/*
 * function: func_0216A470
 * address:  0x0216A470
 * packet:   pkt_ov010_0216A470
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
 *   func_02012F50  0x02012F50  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02168BF0  0x02168BF0  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
struct Desc;
extern struct Desc *func_02168BF0(int a, int b, int c, int d, u16 *e);
extern void func_0215897C(void *a, void *b);

int func_0216A470(int a0, int a1)
{
    void *r7;
    void *l4;
    int *r6;
    int l8;
    int lc;
    u16 *l0;

    r7 = func_0215A5F4((void *)a1);
    l4 = func_0215A5DC((void *)a1);
    r6 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l4));
    l8 = func_02159B10((void *)a0, (void *)a1);
    lc = func_02159B10((void *)a0, (void *)a1);
    l0 = func_02159AE8((void *)a0, (void *)a1);
    func_0215897C(r7, func_02168BF0((int)l4, *r6, l8, lc, l0));
    return 1;
}
