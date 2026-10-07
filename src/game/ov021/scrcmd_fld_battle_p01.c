/*
 * file:     scrcmd_fld_battle_p01.c
 * unit:     yes
 * function: func_021B5700, func_021B574C, func_021B57CC
 * address:  0x021B5700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201A354  0x0201A354  thumb
 *   func_021B58B0  0x021B58B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021B5824  0x021B5824  thumb  ov021
 *   func_0201EE60  0x0201EE60  thumb
 */
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5DC(void *a0);
extern void *func_0201A354(int a, int b);
extern void *func_021B58B0(void *sys, int flag, void *rules, u16 *out, int k);
extern u32 func_020307B0(void *p);
extern void func_0215897C(void *vm, void *task);
extern u16 *func_021B5824(u8 *a0, void *a1, u16 *a2, int a3);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
int func_021B5700(void *a0, void *a1);
int func_021B574C(int a0, int a1);
u16 func_021B57CC(void *a0, void *a1, u32 a2, int a3);


int func_021B5700(void *a0, void *a1)
{
    void *r6 = func_0215A5F4(a1);
    void *s = func_0215A5E4(a1);
    unsigned int r7;
    u16 *r5;

    r6 = func_02158F74(r6);
    r7 = func_02159B10(a0, a1);
    r5 = func_02159AE8(a0, a1);
    *r5 = func_021B57CC(s, r6, r7, func_0215A5CC(a1));
    return 0;
}


/*
 * func_0201A354 is filed as src/matched/arm9/func_0201A354.c (witness).
 */
int func_021B574C(int a0, int a1)
{
    void *s8 = func_0215A5F4((void *)a1);
    void *s4 = func_0215A5DC((void *)a1);
    int r4 = func_02159B10((void *)a0, (void *)a1);
    u16 *r7 = func_02159AE8((void *)a0, (void *)a1);
    int r6 = func_0215A5CC((void *)a1);
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


u16 func_021B57CC(void *a0, void *a1, u32 a2, int a3)
{
    u16 n = 0;
    u16 i = 0;
    void *t;
    u16 *v;

    t = func_0201A354(a2, a3);
    v = func_021B5824(t, a0, &n, a3);
    for (i = 0; i < n; i++) {
        func_0201EE60(a1, i, v[i]);
    }
    func_020307B0(v);
    func_020307B0(t);
    return n;
}
