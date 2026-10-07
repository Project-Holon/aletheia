/*
 * file:     scrcmd_c03center_p08.c
 * unit:     yes
 * function: func_021B6B6C, func_021B6BDC
 * address:  0x021B6B6C
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A6C4  0x0215A6C4  thumb  ov010
 *   func_0215A5D0  0x0215A5D0  thumb  ov010
 *   func_021B6AB0  0x021B6AB0  thumb
 *   func_021B6AA4  0x021B6AA4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A300  0x0200A300  thumb
 *   func_0200A338  0x0200A338  thumb
 *   func_021B7834  0x021B7834  thumb  ov021
 *   func_021B7864  0x021B7864  thumb  ov021
 *   func_021B785C  0x021B785C  thumb  ov021
 *   func_021B6D0C  0x021B6D0C  thumb  ov021
 *   func_021B6D30  0x021B6D30  thumb  ov021
 *   func_021B6D64  0x021B6D64  thumb  ov021
 *   func_021B6D98  0x021B6D98  thumb  ov021
 *   func_021B6DC0  0x021B6DC0  thumb  ov021
 *   func_021B6DE4  0x021B6DE4  thumb  ov021
 *   func_021B6E0C  0x021B6E0C  thumb  ov021
 *   func_021B6EB0  0x021B6EB0  thumb  ov021
 *   func_02012F08  0x02012F08  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0216BF74  0x0216BF74  thumb  ov010
 *   d_021D9970     0x021D9970  data   ov021  a4
 */
struct Ctx;
struct Big;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

typedef struct Ent {
    int id;
    u32 f4[5];
} Ent;

extern u32 func_02159B10(void *, void *);
extern u32 func_0215A6C4(void *p);
extern u16 func_0215A5D0(void *);
extern int func_021B6AB0(void *a);
extern int func_021B6AA4(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_02158F54(void *);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021854B0(void *, void *, int, Vec3 *, int);
extern void func_0215897C(void *vm, void *task);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5DC(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A300(void *a0, void *a1, void *a2);
extern void func_0200A338(void *h);
extern void *func_021B7834(void *a, int *out, void *buf);
extern u8 func_021B7864(void *a);
extern void func_021B785C(u8 *p, u32 i);
extern int func_021B6D0C(int idx, void *x, void *y, void *z);
extern int func_021B6D30(int idx, void *x, void *c);
extern int func_021B6D64(int idx, void *x, void *c);
extern int func_021B6D98(int idx, void *x, void *y, void *z);
extern int func_021B6DC0(int idx, void *x, void *y, void *z);
extern u16 func_021B6DE4(void *a, void *sv);
extern u16 func_021B6E0C(void *a);
extern int func_021B6EB0(u32 *o, int k);
extern void *func_02012F08(int *p);
extern u8 *func_02012944(void *p);
extern void func_0216BF74(void *a, int i, void *b);
u32 func_021B6B6C(void *a, void *b);
int func_021B6BDC(u32 a, u32 b);
extern Ent d_021D9970[];


u32 func_021B6B6C(void *a, void *b)
{
    u32 idx = func_02159B10(a, b);
    void *tab = (void *)func_0215A6C4(b);

    func_0215A5D0(b);
    if (idx < func_021B6AB0(tab)) {
        const u16 *e = (const u16 *)func_021B6AA4((u32)tab, idx);
        void *r5 = func_0215A5F4(b);
        void *r6 = func_02158F54(r5);
        void *cur = func_0201210C(r6);
        Vec3 v;
        u32 f3 = e[3];
        u32 f4 = e[4];
        u32 f1 = e[1];
        u32 f2 = e[2];

        v.x = f2 << 16;
        v.y = f3 << 16;
        v.z = f4 << 16;
        func_0215897C(r5, (void *)func_021854B0(r6, cur, f1, &v, 1));
    }
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B6BDC(u32 a, u32 b)
{
    int mode;
    u16 *out;
    void *sv;
    void *h;
    u32 heap;
    u8 *p;
    int k;
    u8 buf[0xcc];
    u32 x;

    mode = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    sv = func_0215A5E4((void *)b);
    heap = func_0215A5CC((void *)b);
    h = func_0200A300(func_02012EBC(sv), 0, (void *)heap);
    p = func_021B7834(h, (int *)(&x), buf);
    k = func_021B7864(h);
    if (k != d_021D9970[k].id) {
        func_0200A338(h);
        return 0;
    }
    switch (mode) {
    case 0:
        if (k != 0) {
            *out = 1;
        } else {
            *out = 0;
        }
        break;
    case 1:
        *out = func_021B6D0C(k, (void *)b, sv, p);
        break;
    case 2:
        *out = func_021B6D30(k, p, (void *)b);
        break;
    case 3:
        *out = func_021B6D64(k, p, (void *)b);
        break;
    case 4:
        if (func_021B6D98(k, (void *)b, sv, p) == 1) {
            func_021B785C(h, x);
            if (func_021B6EB0((u32 *)p, k) == 1) {
                func_0216BF74(func_02012F08(sv), 1, func_02012944(sv));
            }
        }
        *out = 0;
        break;
    case 5:
        *out = func_021B6DE4(func_0201210C(func_0215A5DC((void *)b)), sv);
        break;
    case 6:
        *out = func_021B6E0C(func_0201210C(func_0215A5DC((void *)b)));
        break;
    case 7:
        *out = func_021B6DC0(k, (void *)b, sv, p);
        break;
    }
    func_0200A338(h);
    return 0;
}
