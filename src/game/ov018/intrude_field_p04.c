/*
 * file:     intrude_field_p04.c
 * unit:     yes
 * function: func_0217B600, func_0217B810, func_0217B82C, func_0217B930, func_0217B94C, func_0217B968, func_0217BA48, func_0217BA54, func_0217BAB4, func_0217BBCC, func_0217BBD8, func_0217BC94, func_0217BCDC, func_0217BDE0, func_0217BEA8, func_0217BED4, func_0217BF1C, func_0217BF28, func_0217BF2C, func_0217BF84, func_0217BFD8, func_0217C070, func_0217C094, func_0217C0A8, func_0217C11C, func_0217C14C, func_0217C194, func_0217C1D0, func_0217C274, func_0217C294
 * address:  0x0217B600
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012798  0x02012798  thumb
 *   func_02012A90  0x02012A90  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217C658  0x0217C658  thumb
 *   func_0217C688  0x0217C688  thumb
 *   func_02185214  0x02185214  thumb
 *   func_02188BE8  0x02188BE8  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_021909BC  0x021909BC  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_02190E40  0x02190E40  thumb
 *   func_02190E74  0x02190E74  thumb
 *   func_02190EF0  0x02190EF0  thumb
 *   func_02190F64  0x02190F64  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021A3238  0x021A3238  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0202648C  0x0202648C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02012204  0x02012204  thumb
 *   func_020120D8  0x020120D8  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_020392B8  0x020392B8  arm
 *   func_02026474  0x02026474  thumb
 *   func_0202640C  0x0202640C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020263D8  0x020263D8  thumb
 *   d_02183AE0     0x02183AE0  data   a1
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02175274  0x02175274  thumb  ov011
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02161FEC  0x02161FEC  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159BBC  0x02159BBC  thumb
 *   func_0218CD20  0x0218CD20  thumb  ov021
 *   func_02012114  0x02012114  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175598  0x02175598  thumb  ov011
 *   func_021A3220  0x021A3220  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021A322C  0x021A322C  thumb  ov021
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_02175BBC  0x02175BBC  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_02182124  0x02182124  thumb  ov018
 *   d_021DB810     0x021DB810  data   ov021  a2
 *   d_021DB834     0x021DB834  data   ov021  a2
 *   d_02182B9C 0x02182B9C data ov018 a4
 *   d_02182B60     0x02182B60  data   a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_02182B6C     0x02182B6C  data   a4
 *   d_02182B54 0x02182B54 data a4
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B70  0x02012B70  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02176258 0x02176258 thumb ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B80  0x02012B80  thumb
 *   func_02012950  0x02012950  thumb
 *   d_021700A4 0x021700A4 data a4
 *   d_02170128 0x02170128 data a2
 *   d_021835D4     0x021835D4  data   a4
 *   func_0202A188  0x0202A188  thumb
 *   d_0218360C     0x0218360C  data   a4
 *   d_0218362C     0x0218362C  data   a4
 *   func_0216D63C 0x0216D63C thumb ov010
 */
#include "../../matched/include/Obj09388.h"
#include "../../matched/include/Obj12483.h"
#include "../../matched/include/Obj19353.h"
#include "../../matched/include/Obj12484.h"

struct Comm;
struct Ctx;
struct Evt;
struct Obj;
struct Rec;
struct Rec44;
struct Vec12;
struct Desc;
struct Fx;
struct Obj2;
struct Obj00020;
struct SaveBlock;
struct VecFx32;
struct BigObj;
struct Sub0200852CObj;
struct Sub24;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int x, y, z;
} V12;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    u8 f10[0x18];
    u16 f28;
} Obj;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
    u8 f8[1];
} Work;

typedef struct { int x, y, z; } Vec;

typedef struct {
    int f00;
    int f04;
    int pad;
    u16 pad2;
    u8 f0e;
} Rec;

typedef struct { u16 f : 3; u16 g : 13; } Fh;

typedef struct { u8 lo : 4; u8 b4 : 1; u8 hi : 3; } Fb;

typedef short s16;

typedef struct { u32 f : 4; u32 g : 28; } Fw;

typedef struct { s16 x, y, z; } Vec3s;

typedef struct { s16 x, y, z, w; } Ent_0217B600;

typedef struct { u32 x:10; u32 rest:22; u32 y, z; } Entry;

typedef struct { u16 a, b; int c; } Sub;

typedef struct {
    u16 f00, f02;
    u16 pad04[3];
    u16 f0a;
    u16 pad0c[8];
    Sub s;
} Buf;

typedef enum { INDEX_ZERO, INDEX_ONE } Index;

typedef struct { u16 f0, f2, f4, f6, f8; } Ent_0217BED4;

typedef struct { u8 bit:1; u8 rest:7; } Bits;

typedef struct {
    u16 h0;
    u16 h2;
    int w4;
} T;

typedef struct {
    int w[7];
    T t;
} S_0217C14C;

typedef struct {
    u16 h[14];
    T t;
} S_0217C1D0;

typedef struct {
    u32 x : 11;
    u32 gap : 10;
    u32 y : 2;
    u32 z : 6;
    u32 e : 3;
} B;

typedef struct {
    u16 h0;
    u8 b2;
    u8 b3;
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
} O;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012798(u8 *p, int i);
extern void func_02012A90(struct Rec44 *p, const struct Vec12 *src);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_0200FB24(void);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern u32 func_02045C04(struct Rec *rec);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D480(char *p);
extern void func_0216D9A0(void *map);
extern u32 *func_0216D9E4(void *c);
extern void func_0217C658();
extern int func_0217C688();
extern int func_02185214();
extern int func_02188BE8();
extern void *func_02188C7C(u8 *p);
extern u32 func_02188C54(u8 *p);
extern int func_02188CB4();
extern int func_021904B0(u32 a, u32 b);
extern int func_021907A8();
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern int func_0219077C(u8 *p);
extern int func_02190728(void *a);
extern void func_021909BC();
extern int func_02190BE4();
extern int func_02190C78();
extern int func_02190E40();
extern void func_02190E74();
extern int func_02190EF0();
extern int func_02190F64();
extern int func_021A3074();
extern int func_021A3238();
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, int);
extern u32 func_0202648C(void *obj);
extern u32 func_02026460(void *obj);
extern int func_02035390(void);
extern int func_020353B0(void);
extern u32 func_02012204(const struct Ctx *p);
extern int func_020120D8(char *p);
extern void *func_020127A4(struct SaveBlock *p);
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern int func_020392B8(void);
extern u32 func_02026474(void *obj);
extern void func_0202640C(struct Comm *p, u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern u8 *func_020120F8(const struct Ctx *p);
extern unsigned int func_02012AE4(const struct Rec44 *p);
extern int func_02175E90(void *p, u8 *q);
extern void func_021A3044(u8 *p, void *v);
extern void func_02175274(u8 *, int);
extern u16 func_02039338(void);
extern void func_02175710(u8 *o, u32 v);
extern void func_02161FEC(char *p, u16 v);
extern unsigned int func_02188C98(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern u16 *func_02159B48(int a);
extern int func_02159B94(int a0, int a1, int a2, int a3);
extern void func_02159BBC(int);
extern void func_0218CD20(int, int, int);
extern u32 func_02012114(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern u16 func_02175598(u8 *o, u32 id);
extern void func_021A3220(u8 *p, u32 res);
extern void func_0216D8C0(void *, Vec *);
extern void func_021A322C(u8 *p);
extern int func_02175B8C(u8 *);
extern int func_02175BBC(u8 *);
extern u8 *func_02175B34(u8 *);
extern int func_02175CF4(char *p, u8 *q);
extern void func_0216D828(void *, Vec3s *);
extern int func_02182124(int, u8 *, u8 *);
extern void func_0216CE60(int a, int b, int c);
extern int func_02158344(int);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_02013D9C(u32 id);
extern u32 func_0202647C(void *obj);
extern int func_02176258(u8 *);
extern unsigned int func_02026478(void *obj);
extern u8 func_02012B80(const struct BigObj *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_0202A188(u8 *p, u32 a, u32 v2, u32 v3);
extern int func_0216D63C(char *, int);
int func_0217B600(int a0, int *state, Obj *o);
void *func_0217B810(void *a, u8 *pos);
int func_0217B82C(int a0, int *state, Work *w);
int func_0217B930(int *p);
int func_0217B94C(int *p);
void func_0217B968(int a0, void *a1, void *a2, void *a3);
void func_0217BA48(int a, int b);
void func_0217BA54(void *a);
void func_0217BAB4(int a0, void *a1, void *a2, u8 *p);
void func_0217BBCC(int a, int b, char *p);
void func_0217BBD8(u8 *a, int b, u8 *c);
void func_0217BC94(int a, int n);
void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag);
int func_0217BDE0(int a, u8 *b, int c);
Entry *func_0217BEA8(u32 a);
int func_0217BED4(int a, V12 *out);
void func_0217BF1C(void *p);
u8 func_0217BF28(u8 *p);
void func_0217BF2C(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g);
void func_0217BF84(int a);
int func_0217BFD8(const struct Ctx *a, int b);
int func_0217C070(u8 *p);
void func_0217C094(unsigned char *p);
u8 func_0217C0A8(void *a0);
int func_0217C11C(u32 value);
void func_0217C14C(int a0, u16 a1, u16 a2, int a3);
void func_0217C194(int p);
void func_0217C1D0(const O *o, const B *p, u16 a2, u16 a3, T x);
void func_0217C274(unsigned int *out, char *p);
int func_0217C294(char *a0);
extern const char d_02183AE0[];
extern u16 d_021DB810[];
extern Ent_0217B600 d_021DB834[];
extern Entry d_02182B9C[];
extern const V12 d_02182B60;
extern const Buf d_02182B6C;
extern const Ent_0217BED4 d_02182B54[];
extern const u32 d_021700A4;
extern const u16 d_02170128[];
extern const S_0217C14C d_021835D4;
extern const E d_0218360C[];
extern const S_0217C1D0 d_0218362C;




/*
 * Byte-correct (528 of 528 bytes).  Sole blocker: the THM_CALL at +0x13C to
 * 0x02012798, an unlabelled arm9 leaf that disasm.py prints as .word data in
 * pool_02012794 (asm/arm9/main.s), after the pop at 0x02012790 and before
 * func_020127A4; no listing labels it and this call is its only witness, so
 * every class refuses it.  Verified EXACT at 0x02012798 (arm9, thumb, 10 B):
 *
 *     u8 *func_02012798(u8 *p, int i) { return p + 4 + i * 0x44; }
 *
 * It is the Rec44 indexer that belongs beside func_02012950 in
 * src/matched/arm9/unit_02012924.c; once it is labelled or matched this file
 * should verify EXACT unchanged.  The 12-byte scratch is a cast u8 buffer
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md):
 * the stores go through r7, which a declared struct folds to sp.
 */
int func_0217B600(int a0, int *state, Obj *o)
{
    int w;
    int g;
    int h;
    int t;
    int r;
    int ctx;
    int i;
    u8 v[12];
    V12 *pv;

    w = (int)func_020124E4((struct Obj *)a0);
    g = (int)func_0201210C((const struct Ctx *)w);
    h = func_02012138((const struct Ctx *)w);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C((u8 *)g));
        t = func_02188C54((u8 *)g);
        o->f0 = func_021904B0(t, 0x2D);
        o->f8 = func_02190F64(t, o->f0);
        func_02190E74(o->f8, 0, 0, 0x54);
        *state += 1;
        break;
    case 1:
        if (func_02190EF0(o->f8) == 1) {
            o->fc = func_02190BE4(func_02188C54((u8 *)g), 0);
            *state += 1;
        }
        break;
    case 2:
        r = func_02190C78(o->fc);
        if (r != 2) {
            func_021909BC(o->fc);
            func_02190E40(o->f8);
            o->fc = 0;
            o->f8 = 0;
            if (r == 0)
                *state = 3;
            else
                *state = 11;
        }
        break;
    case 3:
        if (func_0200FB24() == 0 && func_02026454((void *)h) == 2) {
            func_02026400((struct Comm *)h);
            o->f4 = func_021907A8(func_02188C54((u8 *)g), o->f0);
            func_02190740(o->f4, 0, 0, 0x14);
        }
        *state += 1;
        break;
    case 4:
        if (o->f4 == 0 || func_0219077C((u8 *)o->f4) == 1)
            *state += 1;
        break;
    case 5:
        o->f28++;
        if (o->f4 != 0 && o->f28 <= 0x3C)
            break;
        if (func_02026454((void *)h) == 2)
            break;
        ctx = (int)func_020120F4((const struct Ctx *)w);
        pv = (V12 *)v;
        pv->x = 0;
        pv->y = 0;
        pv->z = 0;
        for (i = 0; i < 3; i++)
            func_02012A90((struct Rec44 *)func_02012798((u8 *)ctx, i), (const struct Vec12 *)pv);
        *state += 1;
        break;
    case 6:
        if (o->f4 != 0)
            func_02190728((void *)o->f4);
        func_02045C04((struct Rec *)o->f0);
        *state += 1;
        break;
    case 7:
        g = (int)func_0201210C((const struct Ctx *)w);
        if (func_02188BE8(g) != 1)
            break;
        if (func_021A3238(func_02188CB4(g)) == 0) {
            func_0217C658(o->f10, w, g, 0, 0, 0);
            *state += 1;
        } else {
            *state = 9;
        }
        break;
    case 8:
        if (func_0217C688(o->f10, 0) == 1)
            *state += 1;
        break;
    case 9:
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185214(w));
        *state += 1;
        break;
    case 10:
        *state = 14;
        break;
    case 11:
        func_02045C04((struct Rec *)o->f0);
        *state = 12;
        break;
    case 12:
        t = func_021A3074(func_02188CB4(g));
        if (func_0216D3CC(t) == 1) {
            func_0216D410((void *)t, 8);
            *state += 1;
        }
        break;
    case 13:
        if (func_0216D480((char *)func_021A3074(func_02188CB4(g))) == 1)
            *state = 14;
        break;
    case 14:
        func_0216D9E4(func_02188C7C((u8 *)g));
        return 1;
    }
    return 0;
}



void *func_0217B810(void *a, u8 *pos) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, func_0217B82C, 0x20);
    p = func_020124E8(t);
    return t;
}





int func_0217B82C(int a0, int *state, Work *w)
{
    int sys;
    void *obj;
    int hnd;

    sys = (int)func_020124E4((struct Obj *)a0);
    obj = func_0201210C((void *)sys);
    func_02012138((const struct Ctx *)sys);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(obj));
        hnd = func_02188C54(obj);
        w->f0 = func_021904B0(hnd, 0x2D);
        w->f4 = (int)(struct Obj2 *)func_02190F64((struct Fx *)hnd, w->f0);
        func_02190E74((u32 *)w->f4, 0, 0, 0x60);
        (*state)++;
        break;
    case 1:
        if (func_02190EF0((u32 *)w->f4) == 1) {
            func_02190E40(w->f4);
            func_02045C04((struct Rec *)w->f0);
            (*state)++;
        }
        break;
    case 2:
        obj = func_0201210C((void *)sys);
        if (func_02188BE8(obj) == 1) {
            if (func_021A3238((void *)func_02188CB4((void *)obj)) == 0) {
                func_0217C658(w->f8, sys, obj, 0, 0, 0);
                (*state)++;
            } else {
                *state = 4;
            }
        }
        break;
    case 3:
        if (func_0217C688(w->f8, 0) == 1)
            (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185214(sys));
        (*state)++;
        break;
    case 5:
        if (obj != 0 && func_02188BE8(obj) == 1) {
            func_0216D9E4(func_02188C7C((void *)obj));
            return 1;
        }
        break;
    }
    return 0;
}




int func_0217B930(int *p) { if (*p >= 0x348000 || *p <= 0xb8000) return 1; return 0; }




int func_0217B94C(int *p) { if (*p > 0x308000 || *p < 0xe8000) return 1; return 0; }





void func_0217B968(int a0, void *a1, void *a2, void *a3)
{
    Vec v;

    if (func_0202648C(a2) != 0)
        return;
    if (func_02026460(a2) == 1)
        return;
    if (func_0200FB24() != 0)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    if (func_02012204(a1) == 1)
        return;
    if (func_020120D8(a1) == 1)
        return;
    if (func_02013D5C(func_02012AC8((const struct Rec44 *)func_020127A4(func_020120F4(a1)))) == 0)
        return;
    func_021A3038(a3, (struct VecFx32 *)&v);
    switch (func_02026454(a2)) {
    case 0:
        if (func_0217B930((int *)(&v)) == 1)
            func_0217BA54(a1);
        break;
    case 2:
        if (func_0217B930((int *)(&v)) != 0)
            return;
        if (func_020392B8() > 1)
            return;
        if (((u8 *)func_02026474(a2))[0x8FD] == 4)
            return;
        func_02026400(a2);
        break;
    case 1:
        if (func_0217B930((int *)(&v)) == 1)
            func_0202640C(a2, (u32)func_0217BA48, (u32)a1);
        break;
    }
}





void func_0217BA48(int a, int b)
{
    if (b == 0)
        func_0217BA54((void *)a);
}





void func_0217BA54(void *a)
{
    int h;
    Rec *r;

    h = func_02012138(a);
    if (func_0200FB24() != 0)
        return;
    if (func_02012204(a) == 1)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    r = func_02030734(0x8005, 0x10, 1, d_02183AE0, 0x528);
    r->f0e = 1;
    r->f00 = (int)a;
    r->f04 = h;
    func_020263D8((struct Comm *)h, 2, (u32)r);
}





void func_0217BAB4(int a0, void *a1, void *a2, u8 *p)
{
    int x;
    int idx;
    Vec cur;
    Vec tmp;
    int flag;
    int prev;
    int limit;
    int sys;

    x = (int)func_020120F8(a1);
    sys = func_02012AC8((const struct Rec44 *)x);
    func_02012AE4((const struct Rec44 *)x);
    x = func_02012138(a1);
    flag = 0;
    func_020120F4(a1);
    if ((int)func_02026454((void *)x) != 2)
        return;
    if (p == 0)
        return;
    if (func_02013D5C(sys) == 0)
        return;
    if (p[0x902] < 2)
        return;
    if (func_02175E90(p, p + 0x1AC) == 1)
        return;
    func_021A3038(a2, (struct VecFx32 *)&cur);
    tmp = cur;
    x = cur.x;
    prev = ((Fh *)(p + 0x86))->f;
    limit = (p[0x901] + 1) << 22;
    if (x < 0) {
        tmp.x = limit + x;
        flag = 1;
    } else if (x > limit) {
        tmp.x = x - limit;
        flag = 1;
    }
    if (flag == 1) {
        x = tmp.x;
        if (func_020120D8(a1) == 1) {
            tmp = cur;
            flag = 0;
        }
    }
    idx = x / 0x400000;
    if (flag == 1) {
        func_021A3044(a2, &tmp);
        func_02175274(p, tmp.x);
    }
    idx += func_02039338();
    if (idx > p[0x901])
        idx -= p[0x901] + 1;
    if (prev == idx)
        return;
    func_02175710(p, idx);
    p[0x900] = 1;
    func_02161FEC((char *)(p + 0x35C), (u8)idx);
}




void func_0217BBCC(int a, int b, char *p)
{
    p[0x901] = 0;
}





void func_0217BBD8(u8 *a, int b, u8 *c)
{
    Vec v;
    int n;
    void *h;
    int buf;

    if (c == 0 || a == 0)
        return;
    if (func_02188C98(a) == 0)
        return;
    if (func_02013D5C(func_02188C9C((u8 *)a)) == 0)
        return;
    n = c[0x902] - 1;
    if (n <= 0)
        n = 1;
    if (((unsigned)(c[0x8f8] << 26) >> 31) == 1)
        n = 1;
    if (c[0x901] >= n)
        return;
    h = (void *)func_02188CB4((void *)a);
    if (h == 0)
        return;
    func_021A3038(h, (struct VecFx32 *)&v);
    v.x = v.x % 0x400000;
    if (func_0217B94C((int *)(&v)) == 1)
        return;
    buf = (int)func_02159B48(0x8015);
    func_02159B94(buf, 0x76, 0x76 + 0xa1, 0x8015);
    do {
        func_0218CD20((int)a, func_02188C98(a), buf);
        c[0x901]++;
    } while (c[0x901] < n);
    func_02159BBC(buf);
}





void func_0217BC94(int a, int n)
{
    int r;

    if (n >= 3)
        n = 2;
    r = (int)func_02159B48(0x15);
    func_02159B94(r, 0x76, 0x76 + 0xa1, 0x8015);
    while (n > 0) {
        func_0218CD20(a, func_02188C98((u8 *)a), r);
        n--;
    }
    func_02159BBC(r);
}





void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag)
{
    int res;
    void *obj;
    int has;
    int x;
    int y = (int)func_020120F4(a1);
    Vec v = { 0, 0, 0 };

    if (func_02012114(a1) == 0)
        return;
    x = (int)func_02012944(func_020120F4(a1));
    has = func_02008550((const struct Sub0200852CObj *)x);
    if (p != 0) {
        if (id == 0xFFFF) {
            if (((Fh *)(p + 0x86))->f == func_02012B58((const struct BigObj *)y))
                id = 0;
        }
        if (id == 0) {
            kind = has == 0 ? 3 : 4;
            flag = has;
        }
        if (((struct Obj09388 *)p)->f88 == id)
            return;
        ((struct Obj09388 *)p)->f88 = id;
        ((Fb *)(p + 0x8A))->lo = kind;
        ((Fb *)(p + 0x8A))->b4 = flag;
        p[0x900] = 1;
        res = func_02175598(p + 0x70, x);
    } else {
        id = 0;
        res = 1;
        if (has)
            res = 4;
    }
    obj = (void *)func_02188CB4(func_0201210C(a1));
    func_021A3220(obj, (u16)res);
    func_0216D8C0((void *)func_021A3074(obj), &v);
    if (id == 0)
        func_021A322C(obj);
}





int func_0217BDE0(int a, u8 *b, int c)
{
    u8 *e;
    int n;
    int idx;
    Vec3s v;

    if (func_02175B8C(b + 0x1AC) != 1)
        goto fail;
    if (func_02175BBC(b + 0x1AC) != 0)
        goto fail;
    e = func_02175B34(b + 0x1AC);
    if (e == 0)
        goto fail;
    if (((Fw *)(e + 4))->f != 4)
        goto fail;
    if (((Fh *)(b + 0x86))->f != e[0x28])
        goto fail;
    if (func_02175CF4((char *)b, b + 0x1AC) != 0)
        goto fail;
    n = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    func_0216D828((void *)func_021A3074((void *)c), &v);
    idx = ((struct Obj12483 *)e)->f14;
    if (n != d_021DB810[idx])
        goto fail;
    if (v.x != d_021DB834[idx].x)
        goto fail;
    if (v.y != d_021DB834[idx].y)
        goto fail;
    if (v.z != d_021DB834[idx].z)
        goto fail;
    return func_02182124(a, b, e);
fail:
    return 0;
}




Entry *func_0217BEA8(u32 a) { u32 i; for (i=0; i<218; i++) { if (d_02182B9C[i].x == a) return &d_02182B9C[i]; } return 0; }





int func_0217BED4(int a, V12 *out)
{
    short *p;
    int x, y, z;

    if (func_02013D5C(a) != 1) {
        p = (short *)func_0217BEA8(a);
        if (p == 0)
            return 0;
        z = p[4] << 16;
        y = p[3] << 16;
        x = p[2] << 16;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        *out = d_02182B60;
    }
    return 1;
}





void func_0217BF1C(void *p)
{
    func_02082BCC(p, 0, 0x10);
}





u8 func_0217BF28(u8 *p)
{
    return p[0xE];
}





void func_0217BF2C(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g)
{
    Buf buf;
    void *h;
    int k;
    Sub *q;

    h = func_02188C7C((void *)a);
    k = func_02188C9C((u8 *)a);
    buf = d_02182B6C;
    buf.f00 = g;
    buf.f02 = e;
    buf.f0a = f;
    q = &buf.s;
    q->a = b;
    q->b = c;
    q->c = d;
    func_0216CE60((int)h, (int)(&buf), k);
}




/*
 * lever: enum inner counter preserves the one-iteration loop; unsigned comparison;
 *   named column load fixes the Thumb add operands.
 */
void func_0217BF84(int a)
{
    Index i;
    int j;
    unsigned int column;
    j = 1;
    do {
        i = INDEX_ZERO;
        do {
            column = d_02182B54[i].f2;
            func_0217BF2C(a, column + (j << 6), d_02182B54[i].f4, 0x2001F, d_02182B54[i].f0, d_02182B54[i].f6, j + d_02182B54[i].f8 - 1);
            i++;
        } while ((unsigned int)i < 1);
        j++;
    } while (j < 3);
}





int func_0217BFD8(const struct Ctx *a, int b)
{
    int h;
    int t;
    int w;

    h = (int)func_020120F4((const struct Ctx *)a);
    t = func_02012138((const struct Ctx *)a);
    w = func_02158344(t);
    if (func_02012B70((const struct BigObj *)h) == 0)
        return 0;
    if (w != 0)
        return 0;
    if (func_02012204(a) == 1)
        return 1;
    if (func_02013D5C(b) == 1) {
        if (func_0202648C((void *)t) != 0)
            return 1;
        return 0;
    }
    if (func_02013D9C(b) == 1) {
        if (func_02026454((void *)t) == 2 || (func_02026454((void *)t) == 0 && func_0202647C((void *)t) == 2 && func_0202648C((void *)t) != 0))
            return 1;
        return 0;
    }
    return 1;
}




int func_0217C070(u8 *p)
{
    if (((Bits *)(p + 0x93f))->bit == 1 || func_02176258(p) == 1)
        return 1;
    return 0;
}




void func_0217C094(unsigned char *p)
{
    if (p != 0) {
        p[0x8F8] |= 0x20;
    }
}





u8 func_0217C0A8(void *a0)
{
    int h;
    u8 *q;
    u8 *obj;

    h = func_02026478(a0);
    if (func_02012B70((const struct BigObj *)h) == 0) {
        obj = func_02012944((void *)h);
    } else if (func_02012B80((const struct BigObj *)h) == func_02012B58((const struct BigObj *)h)) {
        obj = func_02012944((void *)h);
    } else {
        q = 0;
        if (func_02026454(a0) == 2 && func_02026474(a0) != 0)
            q = (u8 *)func_02026474(a0);
        if (q == 0) {
            obj = func_02012944((void *)h);
        } else if (func_02013D5C(((struct Obj19353 *)q)->f84) == 1) {
            obj = func_02012944((void *)h);
        } else {
            obj = (u8 *)func_02012950((struct Sub24 *)h, func_02012B80((const struct BigObj *)h));
        }
    }
    return func_02008550((const struct Sub0200852CObj *)obj);
}



/*
 * lever: index declared before count preserves r3/r4 allocation.
 */
int func_0217C11C(u32 value)
{
    u32 i;
    u32 count;
    count = d_021700A4;
    for (i = 0; i < count; ++i) {
        if (value == d_02170128[i])
            return 1;
    }
    return 0;
}




void func_0217C14C(int a0, u16 a1, u16 a2, int a3)
{
    void *v;
    int c;
    S_0217C14C s;
    T *t;

    v = func_02188C7C((void *)a0);
    c = func_02188C9C((u8 *)a0);
    s = d_021835D4;
    t = &s.t;
    t->h0 = a1;
    t->h2 = a2;
    t->w4 = a3;
    func_0216CE60((int)v, (int)(&s), c);
}



/*
 * extent: two alignment bytes at 0x0217C1CE.
 */
void func_0217C194(int p)
{
    int i;
    if (func_02013D5C(func_02188C9C((u8 *)p)) != 0) {
        for (i = 0; i < 3; ++i)
            func_0217C14C(p, (((i << 22) + 0x1f8000) >> 12) / 16, 29, 32);
    }
}




/*
 * lever: const pointer parameters, u16 argument homes and u16 c/result
 * preserve the original spill and field-load scheduling together.
 */
void func_0217C1D0(const O *o, const B *p, u16 a2, u16 a3, T x)
{
    const E *e;
    int v;
    u16 c;
    S_0217C1D0 s;
    T *t;

    e = &d_0218360C[p->e];
    v = (int)func_02188C7C((u8 *)o->f4);
    c = func_02188C9C((u8 *)o->f4);
    s = d_0218362C;
    s.h[0] = a2;
    s.h[1] = func_0202A188((u8 *)o->f0, (u16)p->x, (u16)p->y, (u16)p->z);
    s.h[2] = e->h0;
    s.h[10] = e->b2;
    s.h[11] = e->b3;
    s.h[7] = o->f8 + a2;
    s.h[8] = ((struct Obj12484 *)p)->f0;
    s.h[9] = ((struct Obj12484 *)p)->f0 >> 16;
    t = &s.t;
    t->h0 = a3;
    t->h2 = x.h0;
    t->w4 = x.w4;
    func_0216CE60(v, (int)(&s), c);
}



void func_0217C274(unsigned int *out, char *p)
{
    int lo;
    lo = func_0216D63C(p, 1);
    *out = lo | (func_0216D63C(p, 2) << 16);
}




/*
 * Recursive MATCH unblocker: callee of func_0216AC90 (ov010) +0026 and
 * func_0216ACCC (ov010) +0032. Thumb tail-call thunk to 0x0216D63C; the
 * address is coherent Thumb only in ov018 (mid-instruction in ov019/ov176,
 * ARM in ov009), so the ov018 shard makes both sites attest as `matched`.
 */
int func_0217C294(char *a0)
{
    return func_0216D63C(a0, 0);
}
