/*
 * file:     event_poke_status_p24.c
 * unit:     yes
 * function: func_0215AE34, func_0215AEB8, func_0215AEE8
 * address:  0x0215AE34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159F28  0x02159F28  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_02012974  0x02012974  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013B44  0x02013B44  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159F54  0x02159F54  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 */
struct BigObj;
struct Rec44;
struct SaveBlock;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_0215A5CC(void *a0);
extern unsigned int func_02159B10(void *, void *);
extern void func_02159F28(int a, int b, int flag);
extern int func_02159B94(int a0, int a1, int a2, int a3);
extern void func_02159CC4(u32 *a, int b, int c);
extern u32 func_02012974(const struct BigObj *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013B44(u32 id);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02159F54(int a, int b);
extern void *func_0200CA1C(void *a);
extern void *func_020173F0(u32 species, u32 level, u64 id, u32 heap);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);
int func_0215AE34(int a0, int a1);
int func_0215AEB8(int a0, int a1);
int func_0215AEE8(int a0, int a1);


int func_0215AE34(int a0, int a1)
{
    void *v0 = func_0215A5DC((void *)a1);
    void *p = func_0215A5E4((void *)a1);
    int x = func_02159B10((void *)a0, (void *)a1);
    int y = func_02159B10((void *)a0, (void *)a1);
    int flag = func_02159B10((void *)a0, (void *)a1);
    int q, r, s, t;
    func_02159F28((int)p, x, y);
    if (flag != 0) {
        q = func_02012974(p);
        r = func_02012AC8(func_020127A4((struct SaveBlock *)p));
        s = func_02013B44(r);
        t = func_0215A5CC((void *)a1);
        func_02159B94(q, s, r, t);
        func_02159CC4((u32 *)q, (int)v0, t);
    }
    return 0;
}


int func_0215AEB8(int a0, int a1)
{
    int t4;
    int t5;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AEC4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215AECE:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AED8:
a1 = t7 + 0;
    a0 = func_02159F54((int)v0, a1);
loc_0215AEE2:
*q = a0;
a0 = 0;
    return a0;}


int func_0215AEE8(int a0, int a1)
{
    void *v0;
    int k;
    int m, o;
    void *n;
    v0 = func_0200CA1C((void *)func_0215A5E4((void *)a1));
    k = func_0215A5CC((void *)a1);
    m = (int)func_02159B10((void *)a0, (void *)a1);
    o = (int)func_02159B10((void *)a0, (void *)a1);
    n = func_020173F0(o, 1, 0xFFFFFFFF00000000ULL, k);
    switch (m) {
    case 0:
        func_0200CFA0(v0, n);
        break;
    case 1:
        break;
    }
    func_020307B0(n);
    return 0;
}
