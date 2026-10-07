/*
 * file:     unit_0216B24C_p03.c
 * unit:     yes
 * function: func_0216B60C, func_0216B63C, func_0216B6DC, func_0216B720, func_0216B7B0, func_0216B7F8, func_0216B81C, func_0216B86C, func_0216B8B8, func_0216B91C
 * address:  0x0216B60C
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216BB18  0x0216BB18  thumb  ov010
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 *   func_0200C358  0x0200C358  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_0200E4F8  0x0200E4F8  thumb
 *   func_0200E4B0  0x0200E4B0  thumb
 *   d_0217219C     0x0217219C  data  ov010  a1
 *   d_021721BC     0x021721BC  data  ov010  a1
 *   func_0200E3A0  0x0200E3A0  thumb
 *   func_0200E3E8  0x0200E3E8  thumb
 *   func_02027100  0x02027100  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021670F8  0x021670F8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0216BB70  0x0216BB70  thumb  ov010
 *   func_0216BAE8  0x0216BAE8  thumb  ov010
 *   func_0216BA88  0x0216BA88  thumb  ov010
 *   func_0216B994  0x0216B994  thumb  ov010
 *   func_0216B9D8  0x0216B9D8  thumb  ov010
 *   func_0216BA08  0x0216BA08  thumb  ov010
 *   func_0216BA40  0x0216BA40  thumb  ov010
 */
struct Big;
struct Blk34;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0216BB18(void *sys);
extern void *func_0200C0F0(void *sys);
extern void *func_0200E394(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void func_0200C334(struct Blk34 *p, u8 v);
extern void func_0200C344(struct Blk34 *p, u8 i, u8 v);
extern void func_0200C358(struct Blk34 *p, u32 i, int v);
extern u64 func_0203F524();
extern void func_0200C384(struct Blk34 *p, u32 lo, u32 hi);
extern int func_0200E4F8(int a0, int a1, int a2);
extern u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);
extern void *func_0200E3A0(void *a);
extern void func_0200E3E8(u8 *bits, int id, u32 value);
extern void func_02027100(const void *src);
extern void *func_0215A5DC(void *a0);
extern void *func_021670F8(void *p);
extern int func_0215897C();
extern void *func_0200C0E8(void *sys);
extern u8 func_0200C32C(struct Blk34 *p);
extern int func_0216BB70(int index);
extern u16 func_0216BAE8(int p);
extern u16 func_0216BA88(int c);
extern int func_0216B994(int c, int vm);
extern int func_0216B9D8(int a0);
extern int func_0216BA08(void *p);
extern int func_0216BA40(int c, int vm);
int func_0216B60C(int a0, int a1);
int func_0216B63C(int a0, int a1);
int func_0216B6DC(int a0, int a1);
int func_0216B720(int c, int vm);
int func_0216B7B0(int c, int vm);
int func_0216B7F8(int a0, int a1);
int func_0216B81C(int c, int vm);
int func_0216B86C(int c, int vm);
int func_0216B8B8(int a0, u16 *a1);
int func_0216B91C(int a0, int a1, u16 *a2);
extern u8 d_0217219C[];
extern u8 d_021721BC[];


/*
 * blocked:  listing 48 compiled 46
 */
int func_0216B60C(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B618:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0216B61E:
    t6 = func_02012EBC((struct Big *)v1);
loc_0216B622:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216B62C:
    a0 = func_0216BB18(t6);
loc_0216B634:
*q = a0;
a0 = 0;
    return a0;}


int func_0216B63C(int a0, int a1)
{
    void *h;
    u16 s[3];
    int i;
    void *w;
    int k;
    int z;
    u64 t;

    func_0215A5F4((void *)a1);
    w = func_02012EBC((struct Big *)func_0215A5E4((void *)a1));
    h = func_0200C0F0(w);
    func_0200E394(w);
    k = func_02159B10((void *)a0, (void *)a1);
    s[0] = func_02159B10((void *)a0, (void *)a1);
    s[1] = func_02159B10((void *)a0, (void *)a1);
    s[2] = func_02159B10((void *)a0, (void *)a1);
    func_0200C334(h, k);
    z = 0;
    for (i = 0; i < 3; i++) {
        func_0200C344(h, i, s[i]);
        func_0200C358(h, (u8)i, z);
    }
    t = func_0203F524();
    func_0200C384(h, (u32)t, (u32)(t >> 32));
    return z;
}


int func_0216B6DC(int a0, int a1)
{
    void *w;
    void *h;
    int i;

    func_0215A5F4((void *)a1);
    w = func_02012EBC((struct Big *)func_0215A5E4((void *)a1));
    h = func_0200C0F0(w);
    func_0200E394(w);
    func_0200C334(h, 0);
    for (i = 0; i < 3; i++)
        func_0200C344(h, (u8)i, 0xFF);
    return 0;
}


int func_0216B720(int c, int vm)
{
    int i;
    int r5;
    void *r6;
    int best;
    u16 *dst;
    int out;
    int n;

    func_0215A5F4((void *)vm);
    r6 = func_0200E394(func_02012EBC((struct Big *)func_0215A5E4((void *)vm)));
    r5 = func_02159B10((void *)c, (void *)vm);
    dst = func_02159AE8((void *)c, (void *)vm);
    n = d_0217219C[r5];
    best = -1;
    for (i = 0; i < n; i++) {
        int a = func_0200E4F8((int)r6, r5, i + 1);
        int b = func_0200E4B0(r6, r5, i + 1);
        int s = a + b;
        if (best < s) {
            best = s;
            out = d_021721BC[r5 * 17 + i];
        }
    }
    *dst = out;
    return 0;
}


int func_0216B7B0(int c, int vm)
{
    void *r6;
    int a;
    int b;

    func_0215A5F4((void *)vm);
    r6 = func_0200E3A0(func_0200E394(func_02012EBC((struct Big *)func_0215A5E4((void *)vm))));
    a = func_02159B10((void *)c, (void *)vm);
    b = func_02159B10((void *)c, (void *)vm);
    func_0200E3E8(r6, (u8)a, b);
    func_02027100(r6);
    return 0;
}


/*
 * blocked:  listing 36 compiled 34
 */
int func_0216B7F8(int a0, int a1)
{    int t5;
    void *p;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B802:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216B80A:
    p = func_021670F8(v1);
loc_0216B80E:
    a0 = func_0215897C(v0, p);
loc_0216B816:
a0 = 1;
    return a0;}


int func_0216B81C(int c, int vm)
{
    void *r6;
    void *t;
    int r5;
    u16 *r4;

    r6 = func_02012EBC((struct Big *)func_0215A5E4((void *)vm));
    t = func_0200C0E8(r6);
    r5 = (u8)func_02159B10((void *)c, (void *)vm);
    r4 = func_02159AE8((void *)c, (void *)vm);
    if (r5 == func_0200C32C(t)) {
        func_0216B8B8((int)r6, r4);
    } else {
        func_0216B91C((int)r6, r5, r4);
    }
    return 0;
}


int func_0216B86C(int c, int vm)
{
    u16 *dst;
    void *r6;
    void *r7;
    int r5;
    u8 k;

    r6 = func_02012EBC((struct Big *)func_0215A5E4((void *)vm));
    r7 = func_0200C0E8(r6);
    dst = func_02159AE8((void *)c, (void *)vm);
    k = func_0216BB70(func_0200C32C(r7));
    if (k != 0) {
        if (k == 1) {
            r5 = func_0216BAE8((int)r6);
        }
    } else {
        r5 = func_0216BA88((int)r6);
    }
    *dst = r5;
    return 0;
}


int func_0216B8B8(int a0, u16 *a1)
{
    u16 *t4;
    int t5;
    void *t6;
    int t7;
    void *p;

t5 = a0 + 0;
t4 = a1 + 0;
    t6 = func_0200E394((void *)a0);
loc_0216B8C2:
a0 = t5 + 0;
    p = func_0200C0E8((void *)a0);
loc_0216B8CA:
    a0 = func_0200C32C(p);
loc_0216B8CE:
t7 = a0 + 0;
    a0 = func_0216BB70(a0);
loc_0216B8D4:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 0) goto loc_0216B8F2;
loc_0216B8DA:
    a0 = func_0216B994((int)t6, t7);
loc_0216B8E2:
    if (a0 == 0) goto loc_0216B8EC;
loc_0216B8E6:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B8EC:
a0 = 2;
*t4 = a0;
    return a0;
loc_0216B8F2:
    if (a0 != 1) goto loc_0216B91A;
loc_0216B8F6:
a0 = t5 + 0;
    a0 = func_0216B9D8(a0);
loc_0216B8FC:
    if (a0 == 0) goto loc_0216B916;
loc_0216B900:
a0 = t5 + 0;
    a0 = func_0216BA08((void *)a0);
loc_0216B906:
    if (a0 == 0) goto loc_0216B910;
loc_0216B90A:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B910:
a0 = 4;
*t4 = a0;
    return a0;
loc_0216B916:
a0 = 3;
*t4 = a0;
loc_0216B91A:
    return a0;}


int func_0216B91C(int a0, int a1, u16 *a2)
{
    u16 *t4;
    int t5;
    void *t6;
    int t7;

t7 = a0 + 0;
t5 = a1 + 0;
t4 = a2 + 0;
    t6 = func_0200E394((void *)a0);
loc_0216B928:
a0 = t7 + 0;
    func_0200C0E8((void *)a0);
loc_0216B930:
a0 = t5 + 0;
    a0 = func_0216BB70(a0);
loc_0216B936:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 0) goto loc_0216B954;
loc_0216B93C:
a1 = t5 + 0;
    a0 = func_0216B994((int)t6, a1);
loc_0216B944:
    if (a0 == 0) goto loc_0216B94E;
loc_0216B948:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B94E:
a0 = 2;
*t4 = a0;
    return a0;
loc_0216B954:
    if (a0 != 1) goto loc_0216B96E;
loc_0216B958:
a1 = t5 + 0;
    a0 = func_0216BA40((int)t6, a1);
loc_0216B960:
    if (a0 == 0) goto loc_0216B96A;
loc_0216B964:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B96A:
a0 = 3;
*t4 = a0;
loc_0216B96E:
    return a0;}
