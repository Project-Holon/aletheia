/*
 * file:     unit_021D4240_p01.c
 * unit:     yes
 * function: func_021D4240, func_021D4244, func_021D424C, func_021D4384, func_021D44BC, func_021D4590, func_021D45BC, func_021D45E8
 * address:  0x021D4240
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D5780 0x021D5780 data a4
 *   d_021D57A0 0x021D57A0 data a4
 *   d_021D57C0 0x021D57C0 data a4
 *   d_021D57E0 0x021D57E0 data a4
 *   d_021D5800 0x021D5800 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj01404.h"
#include "../../matched/include/Obj02472.h"
#include "../../matched/include/Obj06456.h"

struct BgTemplate;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Config { u32 w[8]; } Config;

typedef signed short s16;

typedef struct { int f00, f04, f08, f0c; } Row;

typedef struct { char pad00[0xc]; u16 heap; u16 pad0e; void *f10[11]; int pad3c; void *f40; void *f44; int pad48; void *f4C; int pad50; void *f54; char pad58[0x348-0x58]; int f348; } Object_021D4384;

typedef struct { char pad00[0x10]; void *f10[11]; } Object_021D44BC;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *, unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02051C6C(void *);
extern void func_02041B6C(u32);
void func_021D4240(u32 *p,u32 a);
void func_021D4244(void *p, u32 a, int a2);
void func_021D424C(void *a0);
void func_021D4384(int count, int *values, Object_021D4384 *p, Row *rows, const int *xs, const int *ys);
void func_021D44BC(int i, Object_021D44BC *p, Row *row, const int *xs, const int *ys);
void func_021D4590(u32 i,u32 p);
void func_021D45BC(u32 i,u32 p);
void func_021D45E8(char *p);
extern const Config d_021D5780, d_021D57A0, d_021D57C0, d_021D57E0, d_021D5800;

void func_021D4240(u32 *p,u32 a) {*p=a;}

void func_021D4244(void *p, u32 a, int a2) {func_021D4240(p,a);}

void func_021D424C(void *a0)
{
    Config a, b, c, d, e;
    a = d_021D5780;
    func_0203FCA0(0, (const struct BgTemplate *)(&a), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b = d_021D57A0;
    func_0203FCA0(4, (const struct BgTemplate *)(&b), 0);
    func_02040588(4, 1);
    func_020409B4(4);
    c = d_021D57C0;
    func_0203FCA0(5, (const struct BgTemplate *)(&c), 0);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    d = d_021D57E0;
    func_0203FCA0(6, (const struct BgTemplate *)(&d), 0);
    func_02040588(6, 1);
    func_020409B4(6);
    e = d_021D5800;
    func_0203FCA0(7, (const struct BgTemplate *)(&e), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}

void func_021D4384(int count, int *values, Object_021D4384 *p, Row *rows, const int *xs, const int *ys)
{
    int i, x, y;
    p->f348 = count;
    func_02049B40(23, 5, 4, 384, 32, p->heap);
    for (i = 0; i < 11; i++) {
        if (p->f10[i]) {
            func_020456F8(p->f10[i]);
            func_0201F7A8(p->f10[i], 2);
            func_020452E8(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    for (i = 0; i < count; i++) {
        p->f10[i] = (void *)func_020450F0(7, (u8)rows[i].f00, (u8)rows[i].f04, (u8)rows[i].f08, rows[i].f0c, 13, 0);
        func_02043B5C(func_02045770(p->f10[i]), 0);
        func_02045CAC(p->f44, (int)values[i], p->f54);
        if (xs) x = xs[i] - (func_0201D304(p->f54, (u32)p->f4C, 0) >> 1);
        else x = 0;
        if (ys) y = ys[i] - (func_0201D42C(p->f54, p->f4C) >> 1);
        else y = 0;
        func_0201C7D0(func_02045770(p->f10[i]), x, y, p->f54, p->f4C, 0x39e3);
        func_02045334(p->f10[i]);
        func_02045374(p->f10[i]);
    }
    if (p->f40) func_02051C6C(p->f40);
    p->f40 = 0;
    func_02041B6C(7);
}

/*
 * lever: x initialized after construction lets its zero share the outgoing stack argument.
 */
void func_021D44BC(int i, Object_021D44BC *p, Row *row, const int *xs, const int *ys)
{
    int x, y;
    if (p->f10[i]) {
        func_020456F8(p->f10[i]);
        func_0201F7A8(p->f10[i], 2);
        func_020452E8(p->f10[i]);
        p->f10[i] = 0;
    }
    p->f10[i] = (void *)func_020450F0(7, (u8)row->f00, (u8)row->f04, (u8)row->f08, row->f0c, 13, 0);
    x = 0;
    func_02043B5C(func_02045770(p->f10[i]), 0);
    if (xs) x = xs[i] - (func_0201D304(((struct Obj01404 *)p)->f54, *(u32 *)&((struct Obj01404 *)p)->f4C, 0) >> 1);
    if (ys) y = ys[i] - (func_0201D42C(((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C) >> 1);
    else y = 0;
    func_0201C7D0(func_02045770(p->f10[i]), x, y, ((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C, 0x39e3);
    func_02045334(p->f10[i]);
    func_02045374(p->f10[i]);
    func_02041B6C(7);
}

void func_021D4590(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {func_020456F8(*(void **)(p+0x10+i*4));func_0201F7A8(*(void **)(p+0x10+i*4),2);func_020452E8(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;func_02041B6C(5);}

void func_021D45BC(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {func_020456F8(*(void **)(p+0x10+i*4));func_0201F7A8(*(void **)(p+0x10+i*4),2);func_020452E8(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;func_02041B6C(7);}

/*
 * extent: Two zero padding bytes after the return, next function 021D4630.
 */
void func_021D45E8(char *p)
{
    int i;
    char *q;
    if (((struct Obj02472 *)p)->f40) func_02051C6C(((struct Obj02472 *)p)->f40);
    *(int *)&((struct Obj02472 *)p)->f40 = 0;
    for (i = 0; i < 11; i++) {
        q = p + i * 4;
        if (((struct Obj06456 *)q)->f10) {
            func_020456F8(((struct Obj06456 *)q)->f10);
            func_02041B6C(5);
            func_0201F7A8(((struct Obj06456 *)q)->f10, 2);
            func_020452E8(((struct Obj06456 *)q)->f10);
        }
        *(int *)&((struct Obj06456 *)q)->f10 = 0;
    }
    ((struct Obj02472 *)p)->f348 = 0;
}
