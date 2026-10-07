/*
 * file:     trial_house_p01.c
 * unit:     yes
 * function: func_021CEDA0, func_021CEE00, func_021CEE48, func_021CEE78, func_021CEF08, func_021CEF1C, func_021CF068
 * address:  0x021CEDA0
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
 *   func_021909E4  0x021909E4  thumb  ov021
 *   func_0203D000  0x0203D000  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_0203CF10  0x0203CF10  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02008494  0x02008494  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02190A6C  0x02190A6C  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008534  0x02008534  thumb
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 */
#include "../../matched/include/Obj00011.h"
#include "../../matched/include/Obj09739.h"
#include "../../matched/include/Obj04295.h"

struct Handle;
struct WordSet;
struct MsgBank;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
typedef unsigned char  u8;

typedef short          s16;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8  name[0x20];
    u8  mac[6];
    u8  used;
    u8  pad;
    s16 timer;
    u8  pad2[2];
} Ent_021CEDA0;

typedef struct {
    u32  f0;
    u32  f4;
    Ent_021CEDA0  e[16];
    Ent_021CEDA0 *cur;
    u8   pad[5];
    u8   f2d1;
    u8   pad2[2];
    u16  f2d4;
} N;

typedef struct Sub021CEE48 {
    u8 pad0[6];
    u16 id;
} Sub021CEE48;

typedef struct Ent021CEE48 {
    u8 pad0[0x20];
    Sub021CEE48 sub;
} Ent021CEE48;

typedef struct {
    u8  name[0x20];
    u8  mac[6];
    u8  used;
    u8  pad;
    s16 timer;
    u8  pad2[2];
} Ent_021CEE78;

typedef signed int     s32;

typedef struct {
    u8 pad0[0x26];
    u8 on;
    u8 pad27[5];
} Ent_021CEF1C;

typedef struct {
    u32 f0, f4, f8;
    u8 padc[0x13c - 0xc];
    u32 f13c;
    u32 f140;
    Ent_021CEF1C ents[16];
    u8 pad404[0x40e - 0x404];
    u8 f40e;
    u8 pad40f[0x528 - 0x40f];
    u16 f528;
} S;

extern int func_021909E4(struct Handle *h);
extern void func_0203D000(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021CE9E4(u8 *p, u32 m);
extern u32 func_0203CF10(u32 a);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_02008494(void *src, void *dst);
extern u16 func_02045A98(void);
extern void func_02190A6C(u32 a);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190A64(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020362DC(void);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_0219049C(u8 *p);
extern int func_021909BC(void *a);
int func_021CEDA0(u8 *p);
void func_021CEE00(u8 *p);
void func_021CEE48(u8 *p);
void func_021CEE78(u8 *p, u8 *a, u32 b);
void func_021CEF08(u8 *p, int i);
void func_021CEF1C(S *p);
int func_021CF068(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
int func_021CEDA0(u8 *p)
{
    N *n = (N *)(p + 0x13c);
    int r;

    r = func_021909E4((struct Handle *)n->f4);
    switch (r) {
    case -2:
        return 0;
    case -1:
        break;
    default:
        if (n->e[r].used == 1) {
            n->cur = &n->e[r];
            func_0203D000(n->cur->name + 0x20);
            func_0201F02C((struct WordSet *)(((struct Obj00011 *)p)->f4), 0, (void *)((int)n->cur));
            func_021CE9E4(p, 0x20);
            n->f2d4 = 0;
        }
        break;
    }
    return 1;
}


void func_021CEE00(u8 *p)
{
    u8 *q = p + 0x13c;
    int i;

    for (i = 0; i < 16; i++) {
        u8 *e = q + i * 0x2c;

        if (e[0x2e] == 1) {
            ((struct Obj09739 *)e)->f30 -= 1;
            if (((struct Obj09739 *)e)->f30 <= 0) {
                func_021CEF08(p, i);
                q[0x2d1] = 1;
            }
        }
    }
}


/*
 * func_021CEE78 takes three arguments: the entry itself is the third, which
 * is why the 0203CF10 result lives in r2 and is copied to r1 for the +0x20
 * address.  (The earlier two-argument prototype left it in r1.)
 */
void func_021CEE48(u8 *p)
{
    int i;
    Ent021CEE48 *e;

    for (i = 0; i < 0x10; i++) {
        e = (Ent021CEE48 *)func_0203CF10(i);
        if (e != 0 && e->sub.id == 0x3a0b) {
            func_021CEE78(p, (u8 *)&e->sub, (u32)e);
        }
    }
}


/*
 * the range). Verified EXACT arm9 thumb leaf C for it:
 *   extern void func_02082D44(const void *a, void *b, unsigned n);  (arm)
 *   void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 *
 * Addresses are Black-image addresses.
 */
void func_021CEE78(u8 *p, u8 *a, u32 b)
{
    N *n = (N *)(p + 0x13c);
    int i;

    for (i = 0; i < 16; i++) {
        if (n->e[i].used == 1 && func_0203EFC8(n->e[i].mac, a, 6) == 0) {
            n->e[i].timer = 150;
            return;
        }
    }
    for (i = 0; i < 16; i++) {
        if (n->e[i].used == 0) {
            func_02082D44(a, n->e[i].mac, 6);
            func_02008494((void *)b, n->e[i].name);
            n->e[i].timer = 150;
            n->e[i].used = 1;
            n->f2d1 = 1;
            return;
        }
    }
}


void func_021CEF08(u8 *p, int i)
{
    (p + i * 0x2c)[0x16a] = 0;
}


void func_021CEF1C(S *p)
{
    u16 ch;
    u32 c, a, b, d;
    int i;

    ch = func_02045A98();
    if (p->f40e == 1) {
        func_02190A6C(p->f13c);
    }
    a = (u32)func_020457B0(0x40, p->f528);
    b = (u32)func_020457B0(0x40, p->f528);
    c = (u32)func_020457B0(0x40, p->f528);
    d = (u32)func_020457B0(4, p->f528);
    func_02045CAC((struct MsgBank *)p->f8, 0x1a, (void *)a);
    func_02045CAC((struct MsgBank *)p->f8, 0x1b, (void *)b);
    for (i = 0; i < 16; i++) {
        func_0201EFA4((struct WordSet *)p->f4, 0, i + 1, 2, 2, 1);
        if (p->ents[i].on == 1) {
            func_0201F02C((struct WordSet *)p->f4, 1, &p->ents[i]);
            func_0201EFA4((struct WordSet *)p->f4, 2, func_02008534((const struct Sub0200852CObj *)(&p->ents[i])), 5, 2, 1);
            func_0201F250((struct WordSet *)p->f4, (void *)c, (void *)b);
        } else {
            func_02045924((struct Strbuf *)d, &ch);
            func_0201EE0C((struct WordSet *)p->f4, 1, (const void *)d, 0, 1, 2);
            func_0201EE0C((struct WordSet *)p->f4, 2, (const void *)d, 0, 1, 2);
            func_0201F250((struct WordSet *)p->f4, (void *)c, (void *)a);
        }
        func_02190A64(p->f13c, c, i, p->f528);
    }
    func_02045808((struct U16Vec *)b);
    func_02045808((struct U16Vec *)a);
    func_02045808((struct U16Vec *)c);
    func_02045808((struct U16Vec *)d);
    p->f40e = 1;
}


int func_021CF068(u8 *p)
{
    u8 *q = p + 0x130;
    u32 r;

    switch (q[8]) {
    case 0:
        if (func_020362DC() & 2) {
            ((struct Obj04295 *)q)->f0 = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0)), 0);
            func_021CE9E4(p, 0x23);
            q[8] = 1;
        }
        break;
    case 1:
        r = func_02190C78((struct Handle *)(((struct Obj04295 *)q)->f0));
        if (func_0219049C((u8 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0))) == 1 && p[0x576] == 1)
            r = 1;
        if (r != 2) {
            func_021909BC((void *)(((struct Obj04295 *)q)->f0));
            ((struct Obj04295 *)q)->f0 = 0;
            if (r == 1) {
                q[8] = 0;
                func_021CE9E4(p, 0x22);
            } else {
                return 2;
            }
        }
        return 1;
    }
    return 0;
}
