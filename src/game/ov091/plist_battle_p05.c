/*
 * file:     plist_battle_p05.c
 * unit:     yes
 * function: func_021BAE94, func_021BAF28, func_021BAFA0
 * address:  0x021BAE94
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BB554  0x021BB554  thumb  ov091
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202D01C  0x0202D01C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   g_020A7370     0x020A7370  data
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021B9CF4  0x021B9CF4  thumb  ov091
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021BB050  0x021BB050  thumb  ov091
 *   func_021BB56C  0x021BB56C  thumb  ov091
 *   func_0204B404  0x0204B404  arm
 */
#include "../../matched/include/Obj03183.h"
#include "../../matched/include/Obj20875.h"
#include "../../matched/include/Obj20876.h"
#include "../../matched/include/Obj06211.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj03679.h"

struct Bmp;
struct Descriptor;
struct Obj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

extern int func_021B9A84(u32 p);
extern u8 func_021BB554(u8 *s);
extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern u8 func_0202D01C(u32 a, u32 b, u32 c);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_021B9CF4(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021BB050(int unused, u8 *s, int k);
extern void func_021BB56C(u32 p, int x, int y, u16 *out);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BAE94(u8 *a, u8 *s);
void func_021BAF28(u8 *a, u8 *s);
void func_021BAFA0(u8 *a, u8 *s, int k);
extern void *g_020A7370;


void func_021BAE94(u8 *a, u8 *s)
{
    u8 r;
    int x;
    int y;
    int h;
    u32 w;

    if (func_021B9A84((u32)a) != 0)
        return;
    if (((struct Obj20876 *)(*(u8 * *)&((struct Obj20875 *)a)->f280))->f34 == 6)
        return;
    r = func_021BB554(s);
    h = func_0202D01C(((struct Obj03183 *)s)->f6, func_02017E1C((void *)((struct Obj03183 *)s)->f0, 0xa1, 0), 0x30);
    w = (u32)func_02045770((struct Descriptor *)((struct Obj03183 *)s)->f20);
    if (r == 2 || r == 3) {
        x = 0xe;
        y = 0xf;
    } else if (r == 1) {
        x = 0xc;
        y = 0xd;
    } else {
        x = 0xa;
        y = 0xb;
    }
    func_02043AF4((struct Bmp *)w, 0x3d, 0x1b, h, 1, x);
    func_02043AF4((struct Bmp *)w, 0x3d, 0x1c, h, 1, y);
    func_0204B3DC((struct Obj *)((struct Obj03183 *)s)->f38, 1);
}


void func_021BAF28(u8 *a, u8 *s)
{
    u32 r6;
    u32 r7;

    r6 = (u32)func_0201EC64(((struct Obj06211 *)a)->f0);
    r7 = (u32)func_02045EC0(g_020A7370, 0x28a);
    func_0201EE0C((struct WordSet *)r6, 0, (const void *)r7, 0, 1, 2);
    func_021B9CF4(a, ((struct Obj03183 *)s)->f20, (void *)r6, 3, 0x29, 9, 0x440);
    func_02045808((struct U16Vec *)r7);
    func_0201ED04((struct WordSet *)r6);
    func_0204B3DC((struct Obj *)((struct Obj03183 *)s)->f38, 0);
    func_0204B878((struct Obj *)(((struct Obj03183 *)s)->f30), 1);
    ((struct Obj03183 *)s)->f18 = 1;
}


static inline s16 *get(u8 *s, int x, int y, s16 *buf)
{
    func_021BB56C((u32)s, x, y, (u16 *)buf);
    return buf;
}


void func_021BAFA0(u8 *a, u8 *s, int k)
{
    s16 b1[2];
    s16 b0[2];
    s16 *p;

    if (k == 1) {
        if ((u8)(a[0xc] + 253) <= 1)
            func_021BB050((int)a, s, 8);
        else if (func_021B9A84((u32)a) == 1 && ((struct Obj03679 *)s)->f1C < 6)
            func_021BB050((int)a, s, 8);
        else
            func_021BB050((int)a, s, 6);
        func_0204B878((struct Obj *)(((struct Obj03679 *)s)->f34), 1);
        p = get(s, 0x1a, 0x13, b1);
    } else {
        if ((a[0xc] == 3 && ((struct Obj00009 *)a)->f30 == s[4]) ||
            (a[0xc] == 4 && ((struct Obj00009 *)a)->f34 == s[4]))
            func_021BB050((int)a, s, 5);
        else if (func_021B9A84((u32)a) == 1 && ((struct Obj03679 *)s)->f1C < 6)
            func_021BB050((int)a, s, 5);
        else
            func_021BB050((int)a, s, 3);
        func_0204B878((struct Obj *)(((struct Obj03679 *)s)->f34), 0);
        p = get(s, 0x18, 0x10, b0);
    }
    func_0204B404((struct Obj *)(((struct Obj03679 *)s)->f30), (const struct Vec2 *)p, 0);
    ((struct Obj03679 *)s)->f10 = k;
}
