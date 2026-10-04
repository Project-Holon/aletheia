/*
 * function: func_021B574C
 * address:  0x021B574C
 * packet:   pkt_ov021_021B574C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0201A354 is filed as src/matched/arm9/func_0201A354.c (witness).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0201A354  0x0201A354  thumb
 *   func_021B58B0  0x021B58B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0215A5CC();
extern void *func_0201A354(int a, int b);
extern void *func_021B58B0(void *sys, int flag, void *rules, u16 *out, int k);
extern void func_020307B0(void *p);
extern void func_0215897C(void *vm, void *task);

int func_021B574C(int a0, int a1)
{
    void *s8 = func_0215A5F4((void *)a1);
    void *s4 = func_0215A5DC((void *)a1);
    int r4 = func_02159B10((void *)a0, (void *)a1);
    u16 *r7 = func_02159AE8((void *)a0, (void *)a1);
    int r6 = func_0215A5CC(a1);
    void *r5 = func_0201A354(r4, r6);
    int r1 = 1;
    u16 d = r4 + 0xffec;
    void *res;

    if (d > 2) {
        r1 = 0;
    }
    res = func_021B58B0((void *)s4, r1, r5, r7, r6);
    func_020307B0(r5);
    if (res == 0) {
        return 0;
    }
    func_0215897C(s8, res);
    return 1;
}
