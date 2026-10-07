/*
 * file:     unit_021B9B44_p02.c
 * unit:     yes
 * function: func_021B9F24, func_021B9F58, func_021B9F70, func_021B9F9C, func_021B9FC8, func_021B9FF0, func_021BA2A4, func_021BA2D8, func_021BA350, func_021BA384, func_021BA400, func_021BA438, func_021BA470, func_021BA480
 * address:  0x021B9F24
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02025CD0 0x02025CD0 thumb
 *   d_021BA71C 0x021BA71C data a4
 *   d_021BA5EC 0x021BA5EC data a4
 *   func_02025D14 0x02025D14 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0202616C 0x0202616C thumb
 *   func_0204B404 0x0204B404 arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045994  0x02045994  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02035C08 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   d_021BA5FC 0x021BA5FC data a4
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020260E0 0x020260E0 thumb
 *   func_021BA520  0x021BA520  thumb  ov069
 *   func_0202CC70  0x0202CC70  thumb
 */
#include "../../matched/include/Obj09876.h"
#include "../../matched/include/Obj01132.h"
#include "../../matched/include/Obj13148.h"
#include "../../matched/include/Obj13149.h"
#include "../../matched/include/Obj00432.h"
#include "../../matched/include/Obj06173.h"
#include "../../matched/include/Obj03659.h"

struct Struct_02025CD0;
struct Rec;
struct Obj;
struct Vec2;
struct WordSet;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct Strbuf;
struct Sound;
struct WinMgr;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct Point { u16 x, y; } Point;

struct Rec { u8 pad0[0x12]; u8 a; u8 b; u8 pad1[4]; u16 name[5]; };

typedef struct Ent {
    unsigned char pad[0x20];
    u8 f0 : 1;
    u8 f1 : 1;
} Ent;

typedef struct Obj {
    unsigned char pad000[4];
    struct WinMgr *f4;
    char *f8;
    unsigned char pad00C[0x160 - 0xC];
    u16 page;
    u16 f162;
    int f164;
} Obj;

extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern u32 func_02025D14(void *a0);
extern void func_020061E4(u32 a);
extern void *func_0202616C(void **obj, unsigned int idx);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *, u32, u32, u32, u32, u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void *func_0202435C(void *slots, unsigned int heap);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern int func_02035C08(const void *key);
extern unsigned func_020362DC(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021BA520(u8 *a0, int a1, void *a2, int a3);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
void func_021B9F24(char *p);
int func_021B9F58(char *p);
void func_021B9F68(void);
void func_021B9F6C(void);
void func_021B9F70(char *p, int i);
void func_021B9F9C(char *p, int i);
void func_021B9FC8(char *p, int i);
void func_021B9FF0(char *p, struct Rec *tbl, int idx);
int func_021BA2A4(char *p);
void func_021BA2D8(char *o, int k);
void func_021BA350(char *p);
void func_021BA384(char *o, int i, int n);
int func_021BA400(char *p, int k);
void func_021BA438(char *p, int i);
int func_021BA470(int a, int b, int c);
void func_021BA480(Obj *o);
extern const char d_021BA71C[], d_021BA5EC[];
extern const char d_021BA5FC[];

void func_021B9F24(char *p)
{
    ((struct Obj09876 *)p)->f14C = func_02025CD0((u32)d_021BA71C, (u32)d_021BA5EC, (u32)p, 1, 0, 0x80);
    func_021B9FC8(p, 0);
}

/*
 * evidence: 02025D14 forwards r0 to 02030164, whose body reads the pointer
 * and returns a predicate; its legacy void(void) declaration is incomplete.
 */
int func_021B9F58(char *p)
{
    return func_02025D14(((struct Obj01132 *)p)->f14C);
}

void func_021B9F68(void) {}

void func_021B9F6C(void) {}

void func_021B9F70(char *p, int i)
{
    func_021B9FF0(p, ((struct Obj13148 *)p)->f8, (int)((unsigned)i + (unsigned)((struct Obj13148 *)p)->f160 * 10u));
    func_021B9FC8(p, i);
    func_020061E4(0x548);
}

void func_021B9F9C(char *p, int i)
{
    func_021B9FF0(p, ((struct Obj13149 *)p)->f8, (int)((unsigned)i + (unsigned)((struct Obj13149 *)p)->f160 * 10u));
    func_021B9FC8(p, i);
    func_020061E4(0x548);
}

void func_021B9FC8(char *p, int i)
{
    Point pt;
    u8 *v;
    v = func_0202616C(((struct Obj09876 *)p)->f14C, i);
    pt.x = v[0];
    pt.y = v[1];
    func_0204B404(((struct Obj09876 *)p)->f124, (const struct Vec2 *)(&pt), 0);
}

void func_021B9FF0(char *p, struct Rec *tbl, int idx)
{
    u32 a;
    u32 b;
    struct Rec *rec;
    char *name;
    int off;
    struct U16Vec *vec;
    struct Descriptor *d;
    int n;
    off = idx * 0x22;
    rec = &tbl[idx];
    a = rec->a;
    b = rec->b;
    name = (char *)rec + 0x18;
    vec = func_020457B0(0x10, 0x80);
    func_0201EFA4(*(struct WordSet **)(p + 0xF8), 0, *(u32 *)(*(char **)(p + 0x154) + 4), 2, 0, 1);
    func_0201EFA4(*(struct WordSet **)(p + 0xF8), 1, *(u32 *)(*(char **)(p + 0x154) + 8), 3, 0, 1);
    func_0201F048(*(struct WordSet **)(p + 0xF8), 2, a);
    func_0201F094(*(struct WordSet **)(p + 0xF8), 3, a, b);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x3C)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x40)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x44)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x4C)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x54)), 0);
    if (idx < *(int *)(p + 0x164)) {
        void *ws;
        void *str;
        n = 8;
        func_02045994((struct Strbuf *)vec, (const u16 *)((char *)tbl + off), n);
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xC0)), 0, 0, (u32)vec, (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xC4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + n + 0xFC));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xB0)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xB4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x108));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xB8)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xBC) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x110));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xD0)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x114));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xD0)), 0, 0x10, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        str = func_0202435C((void *)name, 0x80);
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xE0)), 0, 0, (u32)str, (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xE4) = 1;
        func_02045808((struct U16Vec *)str);
    } else {
        d = *(struct Descriptor **)(p + 0x44);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
        d = *(struct Descriptor **)(p + 0x4C);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
        d = *(struct Descriptor **)(p + 0x54);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
    }
    func_02045808(vec);
}

int func_021BA2A4(char *p)
{
    int k;
    k = func_02035C08(d_021BA5FC);
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        k = 2;
    }
    func_021BA2D8(p, k);
    return k;
}


void func_021BA2D8(char *o, int k)
{
    switch (k) {
    case 0:
        if (func_021BA400(o, k) != 0) {
            func_020061E4(0x548);
            func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f12C), 12);
            func_021BA438(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 1:
        if (func_021BA400(o, k) != 0) {
            func_020061E4(0x548);
            func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f130), 13);
            func_021BA438(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 2:
        ((struct Obj00432 *)o)->f158 = 2;
        func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f128), 9);
        break;
    }
}

void func_021BA350(char *p)
{
    ((struct Obj06173 *)p)->f160 = 0;
    ((struct Obj06173 *)p)->f162 = ((struct Obj06173 *)p)->f164 / 10;
    if (((struct Obj06173 *)p)->f164 % 10 != 0)
        (((struct Obj06173 *)p)->f162)++;
}


void func_021BA384(char *o, int i, int n)
{
    if (n == 1) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 0);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 0);
    } else if (i == 0) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 0);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 1);
    } else if (i != 0 && i < n - 1) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 1);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 1);
    } else if (i == n - 1) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 1);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 0);
    }
}

int func_021BA400(char *p, int k)
{
    int result = 0;
    if (k == 0) {
        if (((struct Obj00432 *)p)->f160 != 0) {
            ((struct Obj00432 *)p)->f160 = ((struct Obj00432 *)p)->f160 - 1;
            result = 1;
        }
    } else if (k == 1) {
        if (((struct Obj00432 *)p)->f160 < ((struct Obj00432 *)p)->f162 - 1) {
            ((struct Obj00432 *)p)->f160 = ((struct Obj00432 *)p)->f160 + 1;
            result = 1;
        }
    }
    return result;
}

/*
 * extent: Two bytes of alignment padding follow.
 * lever: Inline the getter result into the sum; a named result reverses
 * the final adds operands (one concrete byte).
 */
void func_021BA438(char *p, int i)
{
    ((struct Obj00432 *)p)->f160 = i;
    func_021BA384(p, i, ((struct Obj00432 *)p)->f162);
    func_021BA480((struct Obj *)p);
    func_021B9FF0(p, ((struct Obj00432 *)p)->f8, ((struct Obj00432 *)p)->f160 * 10 + func_020260E0(((struct Obj00432 *)p)->f14C));
}

/*
 * Unlabelled leaf: remaining count after a - 10 per page, capped at 10.
 */
int func_021BA470(int a, int b, int c)
{
    int r = c - a * 10;

    if (r > 10)
        r = 10;
    return r;
}


void func_021BA480(Obj *o)
{
    void *buf;
    int n;
    int i;

    buf = func_020457B0(0x10, 0x80);
    n = func_021BA470(o->page, o->f162, o->f164);
    i = 0;
    if (n > 0) {
        do {
            func_02045994(buf, (const u16 *)(o->f8 + (i + o->page * 10) * 0x22), 8);
            func_021BA520((u8 *)o, i, buf, ((Ent *)(o->f8 + (i + o->page * 10) * 0x22))->f1);
            i++;
        } while (i < n);
    }
    for (; i < 10; i++)
        func_0202CC70(o->f4, i);
    func_02045808(buf);
}
