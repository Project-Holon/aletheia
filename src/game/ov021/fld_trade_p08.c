/*
 * file:     fld_trade_p08.c
 * unit:     yes
 * function: func_021CD214, func_021CD2A4, func_021CD348, func_021CD3A4, func_021CD400, func_021CD440
 * address:  0x021CD214
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
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0204ED4C  0x0204ED4C  arm
 *   func_0204ED80  0x0204ED80  arm
 *   func_0204ED8C  0x0204ED8C  arm
 *   func_0204ED98  0x0204ED98  arm
 *   func_0204EDA4  0x0204EDA4  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012A54  0x02012A54  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0200C1F4  0x0200C1F4  thumb
 *   func_0200C20C  0x0200C20C  thumb
 *   func_02045924  0x02045924  arm
 *   d_021DB44C     0x021DB44C  data  a1
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02045808  0x02045808  arm
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov075  a4
 *   func_0200C1F8  0x0200C1F8  thumb
 *   func_02027198  0x02027198  thumb
 *   func_0200C210  0x0200C210  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_02045838  0x02045838  arm
 *   func_02165844  0x02165844  thumb  ov010
 *   d_021DB450  0x021DB450  data  ov021  a2
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */
#include "../../matched/include/Obj01220.h"
#include "../../matched/include/Obj03150.h"
#include "../../matched/include/Obj06099.h"

struct Big;
struct BigObj;
struct Blk34;
struct Ctx;
struct Desc;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct Obj;
struct Evt;
struct Obj00020;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u16 f20;
    u8 pad22[0x12];
    u32 f34;
    u8 pad38[4];
    u32 f3c;
    u8 pad40[4];
    u32 f44;
    u16 f48;
    u8 pad4a[2];
    u32 f4c;
} Obj;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 r;
} Ent;

extern void func_0207CDB8(u16 *a, u16 *b);
extern void func_0204ED4C(u8 *a0, short *a1);
extern void func_0204ED80(u8 *dst, u16 *src);
extern void func_0204ED8C(u8 *dst, u16 *src);
extern void func_0204ED98(u8 *dst, u16 *src);
extern void func_0204EDA4(u8 *dst, u16 *src);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern u8 *func_02012944(void *p);
extern u32 func_02012A54(const struct BigObj *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 *func_0200C1F4(struct Blk34 *p);
extern u16 *func_0200C20C(struct Blk34 *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_02045808(struct U16Vec *vec);
extern void func_0200C1F8(struct Blk34 *p, const u16 *src);
extern void func_02027198(void);
extern void func_0200C210(struct Blk34 *p, const u16 *src);
extern int func_020275C4(void *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02165844(void *v);
extern u16 func_02188C9C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
void func_021CD214(u8 *s, void *o);
u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d);
int func_021CD348(int a, int *st, u8 *c);
void func_021CD3A4(u8 *a, u8 *b);
u32 func_021CD400(u32 a, int b, int c);
int func_021CD440(void *a, u16 *out);
extern const u8 d_021DB44C[];
extern char d_021F5580;
extern unsigned char abs_id_C2[];
extern const Ent d_021DB450[];


void func_021CD214(u8 *s, void *o)
{
    u16 v[3];
    u16 c[4];

    v[0] = ((struct Obj01220 *)s)->f4;
    v[1] = ((struct Obj01220 *)s)->f8;
    v[2] = ((struct Obj01220 *)s)->fC;
    func_0207CDB8(v, v);
    func_0204ED4C(o, (short int *)v);
    c[3] = ((struct Obj01220 *)s)->f10 | (((struct Obj01220 *)s)->f12 << 5) | (((struct Obj01220 *)s)->f14 << 10);
    func_0204ED80(o, &c[3]);
    c[2] = ((struct Obj01220 *)s)->f16 | (((struct Obj01220 *)s)->f18 << 5) | (((struct Obj01220 *)s)->f1A << 10);
    func_0204ED8C(o, &c[2]);
    c[1] = ((struct Obj01220 *)s)->f1C | (((struct Obj01220 *)s)->f1E << 5) | (((struct Obj01220 *)s)->f20 << 10);
    func_0204ED98(o, &c[1]);
    c[0] = ((struct Obj01220 *)s)->f22 | (((struct Obj01220 *)s)->f24 << 5) | (((struct Obj01220 *)s)->f26 << 10);
    func_0204EDA4(o, &c[0]);
}


u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d)
{
    u32 h;
    Obj *o;

    h = (u32)func_020122C0((void *)a, (void *)x, func_021CD348, 0x50);
    o = func_020124E8((struct Obj *)h);
    o->f00 = a;
    o->f04 = (u32)func_020120F4((const struct Ctx *)a);
    o->f10 = b;
    o->f18 = d;
    o->f4c = c;
    o->f48 = 4;
    o->f08 = (u32)func_0200C0F0(func_02012EBC((struct Big *)o->f04));
    o->f0c = (u32)func_02012944((void *)o->f04);
    o->f14 = func_02012A54((const struct BigObj *)o->f04);
    o->f1c = c;
    o->f20 = func_02008550((const struct Sub0200852CObj *)o->f0c);
    o->f44 = o->f08;
    o->f34 = d_021DB44C[c - 5];
    o->f3c = (u32)func_020457B0(o->f34 + 1, o->f48);
    switch (c) {
    case 5:
        func_02045924((struct Strbuf *)o->f3c, func_0200C1F4((struct Blk34 *)o->f08));
        break;
    case 6:
        func_02045924((struct Strbuf *)o->f3c, func_0200C20C((struct Blk34 *)o->f08));
        break;
    case 7:
        break;
    }
    return h;
}


/*
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed to func_020146F8, not
 * in match.py's OVERLAY_ID_CONSUMERS; no other pool word holds 0x000000C2
 * outside this range (same blocker as pending ov021_func_021C5A54).
 */
int func_021CD348(int a, int *st, u8 *c)
{
    int r;

    switch (*st) {
    case 0:
        r = (int)func_020146F8((char *)(((struct Obj03150 *)c)->f0), ((struct Obj03150 *)c)->f10, (int)abs_id_C2, (int)(&d_021F5580), (int)(c + 0x1c));
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        func_021CD3A4(c, c + 0x1c);
        func_02045808((struct U16Vec *)(((struct Obj03150 *)c)->f3C));
        return 1;
    }
    return 0;
}


/*
 * Callee witnesses filed in wave A1 (witness lane).
 */
void func_021CD3A4(u8 *a, u8 *b)
{
    u16 *q = *(u16 * *)&((struct Obj03150 *)a)->f18;

    if (q) {
        if (((struct Obj06099 *)b)->f1C == 0)
            *q = 1;
        else
            *q = 0;
    }
    if (((struct Obj06099 *)b)->f1C == 1)
        return;
    switch (((struct Obj03150 *)a)->f4C) {
    case 5:
        func_0200C1F8((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        func_02027198();
        return;
    case 6:
        func_0200C210((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        return;
    case 7:
        func_02045838((struct U16Vec *)func_020275C4((void *)(((struct Obj03150 *)a)->f14)), (struct U16Vec *)(((struct Obj03150 *)a)->f3C));
        func_02165844((void *)(((struct Obj06099 *)b)->f20));
        return;
    }
}


u32 func_021CD400(u32 a, int b, int c)
{
    u32 i;
    const Ent *e = d_021DB450;

    for (i = 0; i < 4; i++, e++) {
        if (e->a == a && e->b <= (u32)b && b < e->b + 3 && e->c <= (u32)c && c < e->c + 3)
            return e->r;
    }
    return 0x1ab;
}


int func_021CD440(void *a, u16 *out)
{
    u16 x;
    void *o;
    u16 h;
    u16 w;

    x = func_02188C9C(a);
    o = func_021A3074(func_02188CB4(a));
    h = func_0216D83C(o);
    w = func_0216D86C(o);
    *out = func_021CD400(x, h, w);
    if (*out != 0x1ab)
        return 1;
    *out = x;
    return 0;
}
