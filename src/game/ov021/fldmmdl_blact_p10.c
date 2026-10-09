/*
 * file:     fldmmdl_blact_p10.c
 * unit:     yes
 * function: func_0219E784, func_0219E828, func_0219E834, func_0219E844, func_0219E854, func_0219E938, func_0219E940, func_0219E968, func_0219E9A8, func_0219E9F8
 * address:  0x0219E784
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
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_021B80D8  0x021B80D8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_0207B51C  0x0207B51C  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_021D84D4     0x021D84D4  data  ov021  a1
 *   d_021D841C     0x021D841C  data  ov021  a2
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219EA78  0x0219EA78  thumb  ov021
 *   func_0219EA94  0x0219EA94  thumb  ov021
 *   func_0219EAB8  0x0219EAB8  thumb  ov021
 *   func_0219EB18  0x0219EB18  thumb  ov021
 *   func_0219EB4C  0x0219EB4C  thumb  ov021
 *   func_0219EB90  0x0219EB90  thumb  ov021
 *   func_0219EBA0  0x0219EBA0  thumb  ov021
 *   func_0219EBF4  0x0219EBF4  thumb  ov021
 *   func_0219ED7C  0x0219ED7C  thumb  ov021
 *   func_0219ED8C  0x0219ED8C  thumb  ov021
 *   func_0219EDC4  0x0219EDC4  thumb  ov021
 *   func_0219EF04  0x0219EF04  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_02164380  0x02164380  thumb  ov010
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219EA5C  0x0219EA5C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 */
struct Sub;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef signed long long s64;

typedef struct { s32 x, y, z; } V;

typedef signed char    s8;

typedef struct {
    u32 pad0;
    s16 lx;
    u16 ly;
} L;

extern void *func_0219E348(void *a);
extern void func_021B8050(struct Sub *o, s16 *out);
extern u32 func_021B80D8(u8 *p);
extern void func_0207AF1C();
extern void func_0207B51C();
extern void func_0207CCA4();
extern void *func_0216D69C(void *p);
extern u32 func_0219EA78(u32, u32);
extern u32 func_0219EA94(u32 a, u32 *b);
extern int func_0219EAB8(u32 a, u32 b);
extern int func_0219EB18();
extern int func_0219EB4C(u32 o);
extern int func_0219EB90(u32 *a);
extern void func_0219EBA0(u32 o, u32 k);
extern int func_0219EBF4(u32 o);
extern int func_0219ED7C(u32 *a);
extern int func_0219ED8C();
extern int func_0219EDC4(u32 o);
extern int func_0219EF04(u32 *a);
extern u8 func_0201441C(int i);
extern int func_02164380(void *a, u16 *b);
extern void *func_0216D684(u32, u32);
extern int func_0219EA5C(void *a, u32 b);
extern void func_02082BCC(void *, int, int);
extern void func_0219E2C0(void *a, void *r);
extern int func_0216D660(void *p);
extern int func_0216D66C(void *p);
void func_0219E784(u32 o, u32 idx, s16 *v);
void *func_0219E828(u32 a);
int func_0219E834(u32 a, u32 b, u32 c, u32 d);
int func_0219E844(u32 *a, u32 b, u32 c, u32 d);
int func_0219E854(u32 o);
int func_0219E864(u32 o);
int func_0219E870(u32 o);
int func_0219E87C(u32 o);
int func_0219E888(u32 o);
int func_0219E894(u32 o);
int func_0219E8A0(u32 o);
int func_0219E8AC(u32 o);
int func_0219E8B8(u32 o);
int func_0219E8C4(u32 o);
int func_0219E8D0(u32 o);
int func_0219E8DC(u32 o);
int func_0219E8E8(u32 o);
int func_0219E8F0(u32 *o);
void func_0219E8F8(u32 o);
void func_0219E904(u32 o);
int func_0219E910(u32 o);
int func_0219E918(u32 *o);
int func_0219E920(u32 o);
int func_0219E928(u32 o);
int func_0219E930(u32 *o);
u32 func_0219E938(int a0);
u32 func_0219E940(int x);
void *func_0219E968(u32 a, u32 size);
int func_0219E9A8(u32 o, int a, int b, L *l);
int func_0219E9F8(u32 *arr, u32 v);
extern u8  d_021D84D4[][4];
extern u16 d_021D841C[];
extern s16 d_020A1B38[];


static inline void setv(V *p, s32 x, s32 y, s32 z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}


static inline void setw(s16 *p, s32 x, s32 y, s32 z)
{
    p[0] = x;
    p[1] = y;
    p[2] = z;
}


void func_0219E784(u32 o, u32 idx, s16 *v)
{
    u32 t;
    u32 n;
    s32 k;
    s32 c;
    s32 m[9];
    V vec;

    t = (u32)func_0219E348((void *)o);
    func_021B8050((struct Sub *)t, v);
    n = func_021B80D8((u8 *)t);
    k = (d_021D841C[d_021D84D4[n][idx]] >> 4) * 2;
    c = d_020A1B38[k + 1];
    v[1] = (s16)(((s64)c * v[1] + 0x800) >> 12);
    setv(&vec, v[0], v[1], v[2]);
    func_0207AF1C(m, d_020A1B38[k], c);
    func_0207B51C(&vec, m, &vec);
    func_0207CCA4(&vec, &vec);
    setw(v, vec.x, vec.y, vec.z);
}


void *func_0219E828(u32 a)
{
    return func_0219E968(a, 0xc);
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E834(u32 a, u32 b, u32 c, u32 d)
{
return func_0219EA78((u32)func_0216D69C((void *)a), a);
}




int func_0219E844(u32 *a, u32 b, u32 c, u32 d)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}




/*
 * Addresses are Black-image addresses.
 * func_0219E854 is followed by twenty unlabelled tail-call thunks (pool
 * word plus `bx r3`), eleven of them passing a state index 0..10 to
 * func_0219EB18; the unit covers the whole 228-byte run.
 */
int func_0219E854(u32 o)
{
    return func_0219EAB8((u32)func_0216D69C((void *)o), o);
}




int func_0219E864(u32 o) { return func_0219EB18(o, 0); }



int func_0219E870(u32 o) { return func_0219EB18(o, 1); }



int func_0219E87C(u32 o) { return func_0219EB18(o, 2); }



int func_0219E888(u32 o) { return func_0219EB18(o, 3); }



int func_0219E894(u32 o) { return func_0219EB18(o, 4); }



int func_0219E8A0(u32 o) { return func_0219EB18(o, 5); }



int func_0219E8AC(u32 o) { return func_0219EB18(o, 6); }



int func_0219E8B8(u32 o) { return func_0219EB18(o, 7); }



int func_0219E8C4(u32 o) { return func_0219EB18(o, 8); }



int func_0219E8D0(u32 o) { return func_0219EB18(o, 9); }



int func_0219E8DC(u32 o) { return func_0219EB18(o, 10); }



int func_0219E8E8(u32 o) { return func_0219EB4C(o); }



int func_0219E8F0(u32 *o) { return func_0219EB90(o); }



void func_0219E8F8(u32 o) { func_0219EBA0(o, 0); }



void func_0219E904(u32 o) { func_0219EBA0(o, 9); }



int func_0219E910(u32 o) { return func_0219EBF4(o); }



int func_0219E918(u32 *o) { return func_0219ED7C(o); }



int func_0219E920(u32 o) { return func_0219ED8C(o); }



int func_0219E928(u32 o) { return func_0219EDC4(o); }



int func_0219E930(u32 *o) { return func_0219EF04(o); }




/*
 * Tail-call thunk: forwards to func_0201441C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219E938(int a0)
{
    return func_0201441C(a0);
}




/*
 * Addresses are Black-image addresses.
 */
u32 func_0219E940(int x)
{
    u32 r = 1;
    switch (x) {
    case 16: r = 0; break;
    case 4: r = 2; break;
    case 2: r = 3; break;
    case 8: break;
    }
    return r;
}




void *func_0219E968(u32 a, u32 size)
{
    u8 buf[8];
    int ok = func_02164380((void *)a, (u16 *)buf);
    void *q = func_0216D684(a, size);
    func_0219EA5C(q, a);
    if (ok) {
        func_0219E2C0((void *)a, buf);
    } else {
        func_02082BCC(buf, 0, 8);
        func_0219E2C0((void *)a, buf);
    }
    return q;
}




int func_0219E9A8(u32 o, int a, int b, L *l)
{
    int x;
    int y;
    int lo;
    int hi;

    x = func_0216D660((void *)o);
    y = func_0216D66C((void *)o);
    if (x != -1) {
        lo = b - x;
        hi = b + x;
        if (lo > l->lx || hi < l->lx) {
            return 1;
        }
    }
    if (y != -1) {
        hi = a + y;
        lo = a - y;
        if (lo > l->ly || hi < l->ly) {
            return 1;
        }
    }
    return 0;
}




int func_0219E9F8(u32 *arr, u32 v)
{
    int i;
    for (i = 0; arr[i] != v; i++) {
    }
    return i;
}
