/*
 * file:     comm_player_p23.c
 * unit:     yes
 * function: func_0216959C, func_021695BC, func_02169620, func_0216968C, func_02169710, func_021697E0, func_02169800, func_02169848, func_02169880, func_0216990C, func_02169928, func_02169998
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
 *   func_02169A88  0x02169A88  thumb  ov010
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_020495F4  0x020495F4  arm
 *   func_0206A9DC  0x0206A9DC  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0206AA0C  0x0206AA0C  arm
 *   func_0206A854  0x0206A854  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_021699A0  0x021699A0  thumb  ov010
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

struct ArcFile;
struct P02047C8C;
struct Tagged;
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

typedef short s16;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct Mtx43 {
    int m[9];
    Vec t;
} Mtx43;

typedef struct Res {
    void *f00;
    void *f04;
} Res;

typedef struct ResTbl {
    Res *tbl;
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

extern void func_02169A88(u8 *p, u32 n);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *h, u32 b, u32 c, u32 d, void *e);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void func_0206A9DC(void *p);
extern void func_02082B60(void *a, void *b);
extern void func_0206AA0C(void *p);
extern void func_0206A854(void);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern int func_021699A0(void *p);
extern void func_02047C8C(struct P02047C8C *p);
extern int func_02047788(int *p);
extern int func_0204755C(int *p);
extern void  VEC_Add(const Vec *a, const Vec *b, Vec *dst);
extern void  MTX_RotY33_(void *m, s16 sinv, s16 cosv);
extern void func_0207CA00(u32 c, void *p, u32 *out);
extern void *func_02046F48(struct Tagged *p);
extern int func_0206E954(int p0);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_0206A2CC(void *a, void *b);
extern void func_0206A4AC(void *a, void *b);
extern void func_02069D14(void *a, void *b);
void func_0216959C(u8 *p);
void func_021695BC(S_021695BC *p, int b);
int func_02169620(S_02169620 *p);
int func_0216968C(u8 *p);
void func_02169710(Obj *obj);
int func_021697E0(char *p);
void func_02169800(void *a, char *b, u32 c, u32 d);
void func_02169848(void *a,u8 *b,u32 c,u32 d);
void func_02169880(u8 *p);
void func_0216990C(u8 *p);
void func_02169928(void *a, void *b, void *c);
int func_02169998(int a0, int a1);
extern u8 d_0217216C[];
extern u8 d_02172178[];
extern u8 d_02148C08[];
extern struct {
    u8 pad[0x7c];
    u32 f7c;
} d_02148BCC;
extern u8 d_02172160[];
extern u8 d_02148B98[];
extern s16 tbl_020A1B38[];
extern char g_02148B98[];


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
    Res *tbl = obj->res->tbl;
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
        s16 s;
        s16 c;
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
