/*
 * file:     comm_player_p06.c
 * unit:     yes
 * function: func_0216959C, func_021695BC, func_02169620, func_0216968C, func_02169710, func_021697E0, func_02169800, func_02169848, func_02169880, func_0216990C, func_02169928, func_02169998, func_021699A0, func_02169A14, func_02169A68, func_02169A88, func_02169AB8
 * address:  0x0216959C
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
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_020495F4  0x020495F4  arm
 *   func_0206A9DC  0x0206A9DC  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0206AA0C  0x0206AA0C  arm
 *   func_0206A854  0x0206A854  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_02047C8C  0x02047C8C  arm
 *   d_0217216C     0x0217216C  data   ov010  a4
 *   d_02172178     0x02172178  data   ov010  a4
 *   d_02148C08     0x02148C08  data   a4
 *   d_02148BCC     0x02148BCC  data   a4
 *   d_02172160     0x02172160  data   ov010  a4
 *   d_02148B98     0x02148B98  data   a4
 *   func_02047788  0x02047788  arm
 *   func_0204755C  0x0204755C  arm
 *   VEC_Add        0x0207C9D0  arm
 *   MTX_RotY33_    0x0207AF1C  thumb
 *   tbl_020A1B38   0x020A1B38  data
 *   g_02148B98     0x02148B98  data
 *   func_0207CA00  0x0207CA00  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E954  0x0206E954  arm
 *   func_0206E964  0x0206E964  arm
 *   func_0206A2CC  0x0206A2CC  arm
 *   func_0206A4AC  0x0206A4AC  arm
 *   func_02069D14  0x02069D14  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *   func_0204932C 0x0204932C arm
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A1518  0x021A1518  thumb  ov021
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1554  0x021A1554  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A0FB4  0x021A0FB4  thumb  ov021
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02006254  0x02006254  thumb
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02169E0C  0x02169E0C  thumb  ov010
 *   func_02169E4C  0x02169E4C  thumb  ov010
 *   func_02169EA4  0x02169EA4  thumb  ov010
 *   func_02169EBC  0x02169EBC  thumb  ov010
 *   func_02169FB8  0x02169FB8  thumb  ov010
 *   func_02169FFC  0x02169FFC  thumb  ov010
 *   func_0216A07C  0x0216A07C  thumb  ov010
 *   func_0216A0BC  0x0216A0BC  thumb  ov010
 *   func_0216A148  0x0216A148  thumb  ov010
 *   func_0216A184  0x0216A184  thumb  ov010
 *   func_0216A1C0  0x0216A1C0  thumb  ov010
 *   func_0216A1F8  0x0216A1F8  thumb  ov010
 *   func_0216A21C  0x0216A21C  thumb  ov010
 *   func_0216A244  0x0216A244  thumb  ov010
 *   func_0216A264  0x0216A264  thumb  ov010
 *   func_0216A280  0x0216A280  thumb  ov010
 *   d_02172A50     0x02172A50  data
 */
#include "../../matched/include/Obj03541.h"
#include "../../matched/include/Obj19050.h"
#include "../../matched/include/Obj19051.h"
#include "../../matched/include/Obj09322.h"
#include "../../matched/include/Obj05902.h"
#include "../../matched/include/Obj19055.h"
#include "../../matched/include/Obj07317.h"
#include "../../matched/include/Obj12387.h"
#include "../../matched/include/Obj00306.h"
#include "../../matched/include/Obj12388.h"
#include "../../matched/include/Obj17746.h"
#include "../../matched/include/Obj04164.h"
#include "../../matched/include/Obj02337.h"
#include "../../matched/include/Obj00281.h"

struct ArcFile;
struct P02047C8C;
struct Tagged;
struct Ctx;
struct MsgBank;
struct Sub020071E4Ctrl;
struct Sub02008C20Obj;
struct Tcbl;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct S_021695BC {
    u16 pad0;
    u16 busy;
    u8 pad4[0x0c];
    u32 h;
    u8 pad14[0x10];
    u32 n;
    u8 pad28[0x8c];
    u32 cur;
    u32 len;
    u32 tot;
    u8 padc0[0x14];
    u32 base;
} S_021695BC;

typedef struct S_02169620 {
    u8 pad0[0x10];
    u32 h;
    u8 pad14[0x10];
    u32 n;
    u8 pad28[0x8c];
    u32 cur;
    u32 len;
    u32 tot;
    u8 padc0[0x14];
    u32 base;
} S_02169620;

typedef short s16_0216959C;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct Mtx43 {
    int m[9];
    Vec t;
} Mtx43;

typedef struct Res_0216959C {
    void *f00;
    void *f04;
} Res_0216959C;

typedef struct ResTbl {
    Res_0216959C *tbl;
    u32 count;
} ResTbl;

typedef struct Ent {
    u32 idx;        /* 0x00 */
    Vec pos;        /* 0x04 */
    u16 angle;      /* 0x10 */
    u16 pad12;
} Ent;

typedef struct Obj {
    u32 f00;
    Vec pos;        /* 0x04 */
    char pad10[0x98 - 0x10];
    ResTbl *res;    /* 0x98 */
    Ent *ents;      /* 0x9C */
    char padA0[4];
    u16 nents;      /* 0xA4 */
} Obj;

typedef void (*Cb_02169800)(void *a, u32 b, u32 *c, u32 d, u32 e);

typedef void (*Cb_02169848)(void *,u32,u32 *,u32,u32);

typedef struct E {
    int a;
    int b;
    int c;
    int d;
    u16 e;
} E;

typedef signed short s16_021699A0;

typedef signed int     s32;

typedef struct Res_02169AB8 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u8 pad20[0x44 - 0x20];
    u8 *f44;            /* 0x44 */
    u8 pad48[0x4C - 0x48];
    u32 f4C;            /* 0x4C */
} Res_02169AB8;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res_02169AB8 *f18;           /* 0x18 */
} Work;

extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *h, u32 b, u32 c, u32 d, void *e);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void func_0206A9DC(void *p);
extern void func_02082B60(void *a, void *b);
extern void func_0206AA0C(void *p);
extern void func_0206A854(void);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_02047C8C(struct P02047C8C *p);
extern int func_02047788(int *p);
extern int func_0204755C(int *p);
extern void  VEC_Add(const Vec *a, const Vec *b, Vec *dst);
extern void  MTX_RotY33_(void *m, s16_0216959C sinv, s16_0216959C cosv);
extern void func_0207CA00(u32 c, void *p, u32 *out);
extern void *func_02046F48(struct Tagged *p);
extern int func_0206E954(int p0);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_0206A2CC(void *a, void *b);
extern void func_0206A4AC(void *a, void *b);
extern void func_02069D14(void *a, void *b);
extern void func_0206DB80(void);
extern int func_0207DEA4(s32 *in);
extern void func_0204932C(struct ArcFile *,u32,void *);
extern int func_02169E0C(char *a0);
extern void func_02169E4C(int a0);
extern void func_02169EA4(Work *w, u32 n);
extern void func_02169EBC(Work *w);
extern int func_02169FB8(int a0);
extern void func_02169FFC(Work *w, u32 n);
extern int func_0216A07C(Work *w);
extern void func_0216A0BC(Work *w);
extern void func_0216A148(Work *w);
extern int func_0216A184(int a0);
extern int func_0216A1C0(int a0);
extern void func_0216A1F8(int a0);
extern int func_0216A21C(int a0);
extern int func_0216A244(void *a0);
extern int func_0216A264(int a0);
extern int func_0216A280(int a0);
extern u32 func_02188CCC(u8 *p);
extern int func_021A0F30(u32 a, u32 b);
extern int func_021A0ED4(u32 a);
extern int func_021A1518(u32 *p);
extern void func_021A1524(u32 *p);
extern int func_021A1554(u32 *p);
extern void func_021A1530(u32 *p);
extern void func_021A1548(u32 *p);
extern int func_021A153C(u32 *p);
extern void func_021A0FB4(u32 *p, u32 a);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);
extern u32 func_0201C440(void *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void func_0201F7A8(void *p, u32 kind);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern int func_02012DAC(int a0);
extern int func_02012DD0(u8 *p);
extern void func_0202F038(u8 *p);
extern void func_020061E4(u32 a);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_02006254(u32 a);
extern u32 func_020362DC(void);
void func_0216959C(u8 *p);
/* * lever: The archive length call takes the still-live member argument; the remaining two bytes are zero alignment padding. */ void func_021695BC(S_021695BC *p, int b);
int func_02169620(S_02169620 *p);
int func_0216968C(u8 *p);
/* * Draws each placed model of a list: for every 0x14-byte entry at +0x9C * (count u16 at +0xA4) whose index is valid in the resource table at +0x98, * loads the base matrix g_02148B98 (G3 cmd 0x17, MTX_LOAD_4x3), multiplies * in a Y rotation by the entry's angle translated by obj+4 plus the entry's * position (cmd 0x19, MTX_MULT_4x3), and draws it. The handed 240-byte * extent also holds an unlabelled 32-byte leaf at 0x021697E0. */ void func_02169710(Obj *obj);
/* * Unlabelled leaf (no push, so disasm.py printed it as a .word run); * called from ov021 func_0218DBD4. */ int func_021697E0(char *p);
void func_02169800(void *a, char *b, u32 c, u32 d);
/* * extent: trailing two-byte alignment padding. * output proof: func_0207CA00 stores buf[0:2] at 0207CA20/0207CA28; * callback receives that initialized three-word vector, with original arity. * address arithmetic: unsigned 32-bit index scaling and base addition * preserve the original lsls/adds wraparound without an invented index bound. */ void func_02169848(void *a,u8 *b,u32 c,u32 d);
/* * The second loop's final store goes through the +0x9C array, as the bytes show. */ void func_02169880(u8 *p);
void func_0216990C(u8 *p);
void func_02169928(void *a, void *b, void *c);
int func_02169998(int a0, int a1);
int func_021699A0(void *p);
u32 func_02169A14(u32 a);
void *func_02169A68(int a0);
void func_02169A88(u8 *p,u32 n);
int func_02169AB8(Work *w, u32 *state);
extern u8 d_0217216C[];
extern u8 d_02172178[];
extern u8 d_02148C08[];
extern struct {
    u8 pad[0x7c];
    u32 f7c;
} d_02148BCC;
extern u8 d_02172160[];
extern u8 d_02148B98[];
extern s16_0216959C tbl_020A1B38[];
extern char g_02148B98[];
extern const char d_02172A50[];





void func_0216959C(u8 *p)
{
    *(u32 *)(p + 0xB4) = 0;
    *(u32 *)(p + 0xC0) = 0;
    *(u32 *)(p + 0xC8) = 0;
    *(u32 *)(p + 0xCC) = 0;
    *(u32 *)(p + 0xD0) = 0;
}





/*
 * lever: The archive length call takes the still-live member argument; the remaining two bytes are zero alignment padding.
 */
void func_021695BC(S_021695BC *p, int b)
{
    u32 t;

    if (p->busy != 0) {
        func_02169A88((u8 *)p, b);
        return;
    }
    t = p->base + p->cur;
    p->tot = func_020493D4((struct ArcFile *)p->h, b);
    p->len = 0;
    func_0204944C((struct ArcFile *)p->h, b, 0, p->n, (void *)t);
    p->cur = p->cur + p->n;
    p->len = p->len + p->n;
}





int func_02169620(S_02169620 *p)
{
    u32 base;
    u32 cur;
    u32 len;
    u32 tot;
    u32 rem;

    base = p->base;
    cur = p->cur;
    len = p->len;
    tot = p->tot;
    if (tot <= len)
        return 0;
    rem = tot - len;
    if (rem > p->n) {
        func_020495F4((struct ArcFile *)p->h, p->n, (void *)(base + cur));
        p->cur = p->cur + p->n;
        p->len = p->len + p->n;
        return 1;
    }
    func_020495F4((struct ArcFile *)p->h, rem, (void *)(base + cur));
    p->cur = p->cur + rem;
    return 0;
}





int func_0216968C(u8 *p)
{
    int r;

    r = 0;
    if (*(u16 *)&((struct Obj03541 *)p)->f0 != 0 && ((struct Obj19050 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4 != 0) {
        func_0206A9DC(d_0217216C);
        func_02082B60(d_02172178, d_02148C08);
        d_02148BCC.f7c &= ~0xa4;
        func_0206AA0C(d_02172160);
        func_0206A854();
        func_0206DDA4(0x15, 0, 0);
        func_0206DDA4(0x17, d_02148B98, 0xc);
        func_0206DDA4(0x1c, p + 4, 3);
        if (func_021699A0(((struct Obj19051 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4) == 1) {
            func_02047C8C(((struct Obj03541 *)p)->f2C);
            r = 1;
        }
    }
    return r;
}





/*
 * Draws each placed model of a list: for every 0x14-byte entry at +0x9C
 * (count u16 at +0xA4) whose index is valid in the resource table at +0x98,
 * loads the base matrix g_02148B98 (G3 cmd 0x17, MTX_LOAD_4x3), multiplies
 * in a Y rotation by the entry's angle translated by obj+4 plus the entry's
 * position (cmd 0x19, MTX_MULT_4x3), and draws it.  The handed 240-byte
 * extent also holds an unlabelled 32-byte leaf at 0x021697E0.
 */
void func_02169710(Obj *obj)
{
    Res_0216959C *tbl = obj->res->tbl;
    u32 count = obj->res->count;
    int i;

    if (count == 0 || tbl == 0) {
        return;
    }
    for (i = 0; i < obj->nents; i++) {
        u32 idx = obj->ents[i].idx;
        void *r;
        void *mdl;
        Mtx43 m;
        s16_0216959C s;
        s16_0216959C c;
        int a;

        if (idx == (u32)-1 || idx >= count) {
            continue;
        }
        r = (void *)func_0204755C((int *)func_02047788(tbl[idx].f00));
        mdl = ((void **)r)[1];
        if (mdl == 0) {
            continue;
        }
        a = obj->ents[i].angle >> 4;
        s = tbl_020A1B38[a * 2];
        c = tbl_020A1B38[a * 2 + 1];
        func_0206DDA4(0x17, g_02148B98, 12);
        VEC_Add(&obj->pos, &obj->ents[i].pos, &m.t);
        MTX_RotY33_(&m, s, c);
        func_0206DDA4(0x19, &m, 12);
        if (func_021699A0(mdl) == 1) {
            func_02047C8C(r);
        }
    }
}





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218DBD4.
 */
int func_021697E0(char *p)
{
    if (((struct Obj09322 *)p)->fD0 == 0
        || *(int *)(*(char * *)&((struct Obj09322 *)p)->f28 + ((struct Obj09322 *)p)->f18 * 16 + 8) == 0)
        return 0;
    return 1;
}





void func_02169800(void *a, char *b, u32 c, u32 d)
{
    u32 buf[3];
    u32 e;
    Cb_02169800 cb;

    ((struct Obj19055 *)a)->f100 = 0;
    if (((struct Obj05902 *)b)->fD0 != 0) {
        e = ((struct Obj05902 *)b)->f8;
        func_0207CA00(c, b + 4, buf);
        cb = *(Cb_02169800 *)(*(char * *)&((struct Obj05902 *)b)->f28 + ((struct Obj05902 *)b)->f18 * 16 + 8);
        if (cb != 0)
            cb(a, ((struct Obj05902 *)b)->fD4, buf, d, e);
    }
}




/*
 * extent: trailing two-byte alignment padding.
 * output proof: func_0207CA00 stores buf[0:2] at 0207CA20/0207CA28;
 * callback receives that initialized three-word vector, with original arity.
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 */
void func_02169848(void *a,u8 *b,u32 c,u32 d) { u32 buf[3]; Cb_02169848 cb; func_0207CA00(c,b+4,buf); cb=*(Cb_02169848 *)(((struct Obj07317 *)b)->f28+((struct Obj07317 *)b)->f18*16u+12u); cb(a,((struct Obj07317 *)b)->fD4,buf,d,((struct Obj07317 *)b)->f8); }





/*
 * The second loop's final store goes through the +0x9C array, as the bytes show.
 */
void func_02169880(u8 *p)
{
    int i;
    E *e;

    for (i = 0; i < ((struct Obj12387 *)p)->fA4; i++) {
        (*(E **)(p + 0x9c))[i].a = -1;
        e = &(*(E **)(p + 0x9c))[i];
        e->b = 0;
        e->c = 0;
        e->d = 0;
        (*(E **)(p + 0x9c))[i].e = 0;
    }
    for (i = 0; i < ((struct Obj12387 *)p)->fA6; i++) {
        (*(E **)(p + 0xa0))[i].a = -1;
        e = &(*(E **)(p + 0xa0))[i];
        e->b = 0;
        e->c = 0;
        e->d = 0;
        (*(E **)(p + 0x9c))[i].e = 0;
    }
}




void func_0216990C(u8 *p) { ((struct Obj00306 *)p)->f0=0; ((struct Obj00306 *)p)->f4=0; ((struct Obj00306 *)p)->f8=0; ((struct Obj00306 *)p)->fC=0; ((struct Obj00306 *)p)->fB0=0; ((struct Obj00306 *)p)->f14=0; func_02169880(p); }





static inline u32 *Get(u8 *r, u32 idx)
{
    u8 *h;

    h = r + 8;
    if (h != 0 && idx < r[9])
        return (u32 *)(h + ((struct Obj12388 *)r)->fE + 4 + idx * 4);
    return 0;
}





void func_02169928(void *a, void *b, void *c)
{
    u8 *r;
    u32 *q;
    u8 *res;
    void *m;
    void *y;

    res = func_02046F48(b);
    y = func_02046F48(c);
    m = 0;
    r = (u8 *)func_0206E954((int)res);
    if (r != 0 && (q = Get(r, 0)) != 0)
        res = r + *q;
    else
        res = 0;
    if (y != 0)
        m = func_0206E964(y);
    if (m != 0) {
        func_0206A2CC(res, m);
        func_0206A4AC(res, m);
    }
    func_02069D14(a, res);
}







int func_02169998(int a0, int a1)
{

a1 = 0;
((struct Obj17746 *)a0)->f4 = a1;
    return a0;}





int func_021699A0(void *p)
{
    s16_021699A0 v[6];
    u32 w[3];
    u32 one;
    char *q;
    int r;

    r = 1;
    q = p ? (char *)p + 0x14 : 0;
    v[0] = ((struct Obj04164 *)q)->f18;
    v[1] = ((struct Obj04164 *)q)->f1A;
    v[2] = ((struct Obj04164 *)q)->f1C;
    v[3] = ((struct Obj04164 *)q)->f1E;
    v[4] = ((struct Obj04164 *)q)->f20;
    v[5] = ((struct Obj04164 *)q)->f22;
    func_0206DDA4(0x11, 0, 0);
    w[0] = ((struct Obj04164 *)q)->f24;
    w[1] = w[0];
    w[2] = w[0];
    func_0206DDA4(0x1b, w, 3);
    if (func_02169A14((u32)v) == 0)
        r = 0;
    one = 1;
    func_0206DDA4(0x12, &one, 1);
    return r;
}





u32 func_02169A14(u32 a)
{
    u32 x;
    u32 y;
    u32 z;

    x = 1;
    y = 0x30C1;
    func_0206DDA4(0x29, &y, 1);
    z = 0;
    func_0206DDA4(0x40, &z, 1);
    func_0206DDA4(0x41, 0, 0);
    func_0206DDA4(0x70, (void *)a, 3);
    func_0206DB80();
    while (func_0207DEA4((s32 *)(&x)) != 0)
        ;
    return x;
}





void *func_02169A68(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
a0 = a0 + 0x88;
a0 = *(int *)&((struct Obj02337 *)((char *)a0))->f0;
    p = func_02046F48((struct Tagged *)a0);
loc_02169A74:
    if (p != 0) goto loc_02169A82;
loc_02169A78:
a0 = t4 + 0;
a0 = a0 + 0x94;
p = ((struct Obj02337 *)((char *)a0))->f0;
    if (p != 0) goto loc_02169A86;
loc_02169A82:
t4 = t4 + 0x88;
p = ((struct Obj02337 *)((char *)t4))->f0;
loc_02169A86:
    return p;}


void func_02169A88(u8 *p,u32 n) { void *out; u32 v; out=((struct Obj00281 *)p)->fD4; v=func_020493D4(*(struct ArcFile * *)&((struct Obj00281 *)p)->f10,n); func_0204932C(*(struct ArcFile * *)&((struct Obj00281 *)p)->f10,n,out); ((struct Obj00281 *)p)->fBC=v; ((struct Obj00281 *)p)->fB4=v; ((struct Obj00281 *)p)->fB8=v; }


/*
 * The 21-state setup and teardown machine of the ov010 program. First
 * draft; the call at 0x021A153C reaches an ov021 Thumb thunk
 * (`ldr r0, [r0, #0x20]; ldr r3, =target; bx r3`), declared `thumb ov021`
 * (the ISA evidence honours the ovNNN hint since tooling_3).
 */
int func_02169AB8(Work *w, u32 *state)
{
    void *ws;
    void *str;

    switch (*state) {
    case 0:
        func_021A0F30(func_02188CCC(w->f08), 7);
        *state = 1;
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(w->f08)) == 1
            && func_021A1518((u32 *)func_02188CCC(w->f08)) == 1) {
            w->f18 = func_02030734(w->f10, 0x50, 0, d_02172A50, 0x9F);
            w->f18->f04 = func_02045B38(0, 3, 0x9E, w->f10);
            w->f18->f18 = func_020457B0(0x200, w->f10);
            w->f18->f00 = func_0203101C(w->f10, w->f10, 1, 4);
            w->f18->f1C = func_02028590(0xF, 1, 1, w->f10);
            w->f18->f14 = func_0201C440((void *)w->f10);
            w->f18->f4C = 0;
            func_02169E4C((int)w);
            func_0216A0BC(w);
            *state = 2;
        }
        break;
    case 2:
        func_02169EA4(w, 2);
        *state = 3;
        break;
    case 3:
        if (func_02169FB8((int)w) == 0) {
            func_0216A148(w);
            *state = 4;
        }
        break;
    case 4:
        switch (func_0216A184((int)w)) {
        case 0:
            if (func_020071F0(w->f00) == 1) {
                func_02169EA4(w, 8);
                *state = 0xE;
            } else {
                func_0201F7A8(w->f18->f08, 1);
                *state = 5;
            }
            break;
        case 1:
            *state = 0x11;
            break;
        }
        break;
    case 5:
        func_02008DF0(func_02012F2C(func_020120F4(w->f04)), 1);
        func_021A1524((u32 *)func_02188CCC(w->f08));
        if (func_021A1554((u32 *)func_02188CCC(w->f08)) == 1)
            func_02169FFC(w, 10);
        else
            func_02169FFC(w, 4);
        *state = 6;
        break;
    case 6:
        if (func_0216A07C(w) == 1) {
            func_0216A1C0((int)w);
            *state = 7;
        }
        break;
    case 7:
        if (func_0216A21C((int)w) == 1)
            *state = 8;
        break;
    case 8:
        if (func_0216A244(w) != 0) {
            w->f18->f44 = func_0202EE30((void *)func_020056BC(), w->f18->f08, 0xF, 0x10, w->f10);
            func_021A1530((u32 *)func_02188CCC(w->f08));
            func_0216A264((int)w);
            func_02012DAC((int)func_020120F4(w->f04));
            *state = 9;
        }
        break;
    case 9:
        switch (func_02012DD0(func_020120F4(w->f04))) {
        case 0:
        case 1:
            break;
        case 2:
            *state = 10;
            break;
        case 3:
            func_021A1548((u32 *)func_02188CCC(w->f08));
            func_0216A280((int)w);
            func_0216A1F8((int)w);
            func_02169EA4(w, 7);
            func_0202F038(w->f18->f44);
            *state = 0xD;
            break;
        }
        break;
    case 10:
        if (func_021A153C((u32 *)func_02188CCC(w->f08)) == 1) {
            func_020061E4(0x558);
            func_0216A280((int)w);
            func_0216A1F8((int)w);
            ws = func_0201EC64(w->f10);
            str = func_02045EC0(w->f18->f04, 5);
            func_0201F02C(ws, 0, func_02012944(func_020120F4(w->f04)));
            func_0201F250(ws, w->f18->f18, str);
            func_02045808(str);
            func_0201ED04(ws);
            func_02169EBC(w);
            func_0202F038(w->f18->f44);
            *state = 0xB;
        }
        break;
    case 11:
        if (func_0216A21C((int)w) == 1 && func_0216A244(w) != 0 && func_02169FB8((int)w) == 0)
            *state = 0xC;
        break;
    case 12:
        if (func_02006254(0x558) == 0)
            *state = 0x10;
        break;
    case 13:
        if (func_0216A21C((int)w) != 1 || func_0216A244(w) == 0)
            break;
        *state = 0xE;
    case 14:
        if (func_02169FB8((int)w) == 0)
            *state = 0xF;
        break;
    case 15:
        if (func_020362DC() & 3)
            *state = 0x13;
        break;
    case 16:
        if (func_020362DC() & 3)
            *state = 0x13;
        if (w->f18->f4C >= 150)
            *state = 0x13;
        else
            w->f18->f4C++;
        break;
    case 17:
        func_02169E0C((char *)w);
        func_021A0F30(func_02188CCC(w->f08), 1);
        *state = 0x12;
        break;
    case 18:
        return 1;
    case 19:
        func_02169E0C((char *)w);
        func_021A0F30(func_02188CCC(w->f08), 0);
        *state = 0x14;
        break;
    case 20:
        func_021A0FB4((u32 *)func_02188CCC(w->f08), w->f10);
        return 0;
    }
    return 2;
}
