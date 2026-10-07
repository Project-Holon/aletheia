/*
 * file:     trial_house_p12.c
 * unit:     yes
 * function: func_021CFCF4, func_021CFD08, func_021CFD88, func_021CFDBC, func_021CFEA0, func_021CFEF0, func_021CFF28, func_021CFF78
 * address:  0x021CFCF4
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02009634  0x02009634  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02025B64  0x02025B64  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0201F048  0x0201F048  thumb
 *   func_02008570  0x02008570  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02009628  0x02009628  thumb
 *   func_0201F198  0x0201F198  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02009590  0x02009590  thumb
 *   sub_020095C8  0x020095C8  thumb
 *   func_02009698  0x02009698  thumb
 */
struct Big;
struct Ctx;
struct Sub0200852CObj;
struct Sub02009470Ent;
struct Sub02009470Obj;
struct WordSet;
struct Tbl021CFCF4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Tbl021CFCF4 {
    u8 f0;
    u8 n;
    u8 pad2[6];
    u8 v[5];
} Tbl021CFCF4;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_02012F38(int base);
extern u8 func_02025B64(u32 v);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern void func_0201F198(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u8 func_02009590(void *a, u32 b, u32 c);
extern u8 sub_020095C8(const struct Sub02009470Obj *obj);
extern void func_02009698(struct Sub02009470Obj *obj, int i, u32 field, u32 value);
u8 func_021CFCF4(Tbl021CFCF4 *p, u32 i);
int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e);
int func_021CFD88(int a, u32 b, u32 c, int d, int e);
void func_021CFDBC(void *ws, u32 h, u32 x);
int func_021CFEA0(u32 a, u32 b);
int func_021CFEF0(u32 a, u32 b);
int func_021CFF28(u32 a, u32 b);
int func_021CFF78(u32 a, u32 b);


u8 func_021CFCF4(Tbl021CFCF4 *p, u32 i)
{
    u8 r = 0xff;

    if (i < 5 && i < p->n) {
        r = p->v[i];
    }
    return r;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e)
{
    u32 v, t, w, s, x, g, h;
    u32 flag;

    flag = 0;
    h = (u32)func_020120F4((const struct Ctx *)b);
    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    if (d >= 5) {
        return 4;
    }
    x = ((u8 *)(c + d))[8];
    func_021CFDBC((void *)a, h, x);
    v = (u32)func_0200973C((struct Sub02009470Obj *)g, x);
    s = func_02008550((const struct Sub0200852CObj *)v);
    w = func_02009634((const struct Sub02009470Obj *)g, x, 4);
    t = func_02008530((const struct Sub0200852CObj *)v);
    if (func_02025B64(*((u8 *)func_02012F38(h)))) {
        flag = 1;
    }
    return func_021CFD88(s, t, w, e, flag);
}


int func_021CFD88(int a, u32 b, u32 c, int d, int e)
{
    int off;

    if (e != 0) {
        off = 4;
    } else {
        off = 0x44;
    }
    if (c < 5) {
        off += c * 0xc;
    }
    if (a != 0) {
        off += 6;
    }
    if (d == 0) {
        off++; off += b % 5;
    }
    return off;
}


void func_021CFDBC(void *ws, u32 h, u32 x)
{
    u32 g, e, v;
    u8 k;

    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    k = *((u8 *)func_02012F38(h));
    e = (u32)func_0200973C((struct Sub02009470Obj *)g, x);
    func_0201F048(ws, 0, k);
    if (func_02025B64(k)) {
        func_0201F094(ws, 1, k, func_02008570((const struct Sub0200852CObj *)e));
    }
    func_0201F02C(ws, 3, func_02012944((void *)h));
    func_0201EE60(ws, 5, func_02009634((const struct Sub02009470Obj *)g, x, 0));
    func_0201F198(ws, 6, func_02009628((const struct Sub02009470Obj *)g));
    func_0201F02C(ws, 7, (void *)e);
    v = func_02009634((const struct Sub02009470Obj *)g, x, 3);
    if (v == 0) {
        v = 1;
    }
    func_0201EFA4(ws, 8, v, 3, 0, 1);
    func_0201EE60(ws, 9, func_02009634((const struct Sub02009470Obj *)g, x, 1));
    k = func_02009634((const struct Sub02009470Obj *)g, x, 2);
    func_0201F198(ws, 10, k);
}


int func_021CFEA0(u32 a, u32 b)
{
    u32 k, h, g;
    void *x;
    u16 *out;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    h = (u32)func_020120F4(x);
    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    *out = func_02009590((void *)g, (u32)func_02012944((void *)h), k);
    return 0;
}


int func_021CFEF0(u32 a, u32 b)
{
    void *x;
    u16 *q;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    q = func_02159AE8((void *)a, (void *)b);
    *q = sub_020095C8(func_02009470(func_02012EBC(func_020120F4((void *)x))));
    return 0;
}


int func_021CFF28(u32 a, u32 b)
{
    u32 h, p, r;
    u8 k;

    func_0215A5F4((void *)b);
    h = (u32)func_020120F4(func_0215A5DC((void *)b));
    p = func_02012F38(h);
    k = func_02159B10((void *)a, (void *)b);
    r = func_021CFCF4((struct Tbl021CFCF4 *)p, k);
    if (r != 0xff) {
        func_02009698(func_02009470(func_02012EBC((struct Big *)h)), r, 5, 1);
    }
    return 0;
}


int func_021CFF78(u32 a, u32 b)
{
    u32 h, p, k, r;
    u16 *out;

    func_0215A5F4((void *)b);
    h = (u32)func_020120F4(func_0215A5DC((void *)b));
    p = func_02012F38(h);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    *out = 0;
    r = func_021CFCF4((struct Tbl021CFCF4 *)p, k);
    if (r != 0xff) {
        if ((u8)func_02009634(func_02009470(func_02012EBC((struct Big *)h)), r, 5)) {
            *out = 1;
        }
    }
    return 0;
}
