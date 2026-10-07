/*
 * file:     scrcmd_proc_fld_p04.c
 * unit:     yes
 * function: func_021B3D60, func_021B3DEC, func_021B3F00, func_021B3F3C, func_021B3FA0, func_021B40A8, func_021B40D4, func_021B41AC, func_021B4264, func_021B42D0, func_021B43EC
 * address:  0x021B3D60
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
 *   func_02020E60 0x02020E60 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021D96E0     0x021D96E0  data   ov021  a2
 *   d_021D96E8     0x021D96E8  data   ov021  a2
 *   d_021D96F0     0x021D96F0  data   ov021  a2
 *   d_021D96F8     0x021D96F8  data   ov021  a2
 *   d_021D9700     0x021D9700  data   ov021  a2
 *   func_020490F4  0x020490F4  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_021B3C78  0x021B3C78  thumb  ov021
 *   func_021B3CFC  0x021B3CFC  thumb  ov021
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   d_021DE18C    0x021DE18C data ov021 a4
 *   d_021DE170    0x021DE170 data ov021 a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_020457B0 0x020457B0 arm
 *   func_0200DABC 0x0200DABC thumb
 *   func_0200C274 0x0200C274 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   d_021D945C    0x021D945C data a4
 *   func_021B468C 0x021B468C thumb ov021
 *   func_021B4510 0x021B4510 thumb ov021
 *   func_021B45A0 0x021B45A0 thumb ov021
 *   func_0201F91C 0x0201F91C thumb
 *   func_0201FF30 0x0201FF30 thumb
 */
#include "../../matched/include/Obj03132.h"
#include "../../matched/include/Obj00357.h"
#include "../../matched/include/Obj00037.h"
#include "../../matched/include/Obj02711.h"
#include "../../matched/include/Obj12844.h"
#include "../../matched/include/Obj02712.h"
#include "../../matched/include/Obj07523.h"
#include "../../matched/include/Obj01502.h"

struct Sub0204A9D0;
struct Obj;
struct Bank;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct PrintSys;
struct Blk1AC;
struct Blk34;
struct CharBuf;
struct WordSet;
struct Slot;
struct Src;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

typedef short          s16;

typedef struct {
    u32 f0;
    u8  f4;
    u8  f5;
    u8  f6;
    u8  f7;
    u16 f8;
} WinTmpl;

typedef struct {
    void *arr;
    void *cb04;
    void *cb08;
    u32 w0c;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

extern u32 func_02020E60(u32 a, u32 b);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204ADEC(u32 a, u32 b, u32 c);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, unsigned int);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_021B3C78(char *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021B3CFC(char *w);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02049238(void *a);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201C440(void *p);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 func_0200DABC(struct Blk1AC *p);
extern u32 func_0200C274(struct Blk34 *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void func_021B468C(u32 a, u32 idx);
extern void func_021B4510(u8 *p, int a, u8 b);
extern void func_021B45A0(u32 unused, int a, u8 b);
extern u32 func_0201F91C(struct Slot *s);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
void func_021B3D60(char *w, u32 b);
void func_021B3DEC(char *w);
void func_021B3F00(u8 *w);
void func_021B3F3C(char *w);
void func_021B3FA0(char *w);
void func_021B40A8(u8 *w);
void func_021B40D4(char *w);
void func_021B41AC(char *w, u16 b);
void func_021B4264(char *w, u32 b);
void func_021B42D0(char *w, u32 a, u32 b);
void func_021B43EC(char *w);
extern const Rect d_021D96E0;
extern const Rect d_021D96E8;
extern const Rect d_021D96F0;
extern const Rect d_021D96F8;
extern const Rect d_021D9700;
extern WinTmpl *d_021DE18C[];
extern WinTmpl *d_021DE170[];
extern u32 d_021D945C[];


void func_021B3D60(char *w, u32 b)
{
    u32 y;
    u32 x;
    u32 p;
    u32 q;

    if (b <= 0x272) {
        p = (u32)func_02049F78((void *)(((struct Obj03132 *)w)->f1F8), func_02020E60(b, 2), (u32)(&x), ((struct Obj03132 *)w)->f4);
        q = (u32)func_02049E74((void *)(((struct Obj03132 *)w)->f1F8), func_02020E60(b, 1), 0, (u32)(&y), ((struct Obj03132 *)w)->f4);
        func_0204ADEC(((struct Obj03132 *)w)->f1EC, x, 1);
        func_0204A9D0(((struct Obj03132 *)w)->f1F0, (struct Sub0204A9D0 *)y);
        func_020307B0((void *)p);
        func_020307B0((void *)q);
        func_0204B3DC((struct Obj *)((struct Obj03132 *)w)->f1D0, 1);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj03132 *)w)->f1D0, 0);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021B3DEC(char *w)
{
    ((struct Obj00357 *)w)->f1C0 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1D8, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1DC, &d_021D96E0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C4 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96E8, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C8 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1CC = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F8, 0, ((struct Obj00357 *)w)->f4);
    func_0204B92C((struct Obj *)((struct Obj00357 *)w)->f1CC, 1);
    ((struct Obj00357 *)w)->f1D0 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1F0, ((struct Obj00357 *)w)->f1EC,
                                        ((struct Obj00357 *)w)->f1F4, &d_021D9700, 0, ((struct Obj00357 *)w)->f4);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1C4, 0);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1C8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1CC, 0);
}


void func_021B3F00(u8 *w)
{
    ((struct Obj00037 *)w)->f1BC = (u32)func_0204B100(5, 1, ((struct Obj00037 *)w)->f4);
    func_0204B22C((struct Bank *)(((struct Obj00037 *)w)->f1BC), 1);
    func_021B3C78((char *)w);
    ((struct Obj00037 *)w)->f1F8 = func_020490F4(0x19, ((struct Obj00037 *)w)->f4);
    func_021B3CFC((char *)w);
    func_021B3DEC((char *)w);
}


void func_021B3F3C(char *w)
{
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1F4));
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1E8));
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1DC));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1F0));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1E4));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1D8));
    func_0204ADA4((u32)(((struct Obj02711 *)w)->f1EC));
    func_0204ADA4((u32)(((struct Obj02711 *)w)->f1D4));
    func_02049238(((struct Obj02711 *)w)->f1F8);
    func_0204B1CC(((struct Obj02711 *)w)->f1BC);
}


void func_021B3FA0(char *w)
{
    WinTmpl **tbl;
    WinTmpl *e;
    int i;
    u32 t;
    u32 bg;

    tbl = d_021DE18C;
    if (((struct Obj00037 *)w)->f163 != 1) {
        tbl = d_021DE170;
    }
    for (i = 0; i < 7; i++) {
        e = tbl[i];
        ((u32 *)(w + 0x164))[i] = func_020450F0((u8)e->f0, e->f4, e->f5, e->f6, e->f7, (u8)e->f8, 1);
    }
    t = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x14);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)((struct Obj00037 *)w)->f164)), 0, 0, (void *)t, (void *)(((struct Obj00037 *)w)->f8), 0x3C4F);
    func_02045808((struct U16Vec *)t);
    ((struct Obj00037 *)w)->f1A8 = ((struct Obj00037 *)w)->f16C;
    ((struct Obj00037 *)w)->f1AC = 0;
    ((struct Obj00037 *)w)->f1B0 = func_0201C440((void *)(((struct Obj00037 *)w)->f4));
    if (((struct Obj00037 *)w)->f163 == 1) {
        bg = ((struct Obj00037 *)w)->f168;
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_020409B4(func_02045730((struct Descriptor *)bg));
    } else {
        bg = ((struct Obj00037 *)w)->f164;
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_020409B4(func_02045730((struct Descriptor *)bg));
        bg = ((struct Obj00037 *)w)->f168;
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_020409B4(func_02045730((struct Descriptor *)bg));
    }
}


void func_021B40A8(u8 *w)
{
    int i;

    func_0201C6EC((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    func_0201C4C0((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    for (i = 0; i < 7; i++) {
        func_020452E8((struct Descriptor *)(*(u32 *)(w + 0x164 + i * 4)));
    }
}


void func_021B40D4(char *w)
{
    u32 t7, t6, s, bg;

    if (((struct Obj00037 *)w)->f163 == 1) {
        t7 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x16);
        t6 = (u32)func_020457B0(10, ((struct Obj00037 *)w)->f4);
        func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), 0, func_0200DABC((struct Blk1AC *)(((struct Obj00037 *)w)->f18)), 4, 1, 1);
    } else {
        t7 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x15);
        t6 = (u32)func_020457B0(10, ((struct Obj00037 *)w)->f4);
        func_0201EFA4((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), 0, func_0200C274((struct Blk34 *)(((struct Obj00037 *)w)->fC)), 7, 1, 1);
    }
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), (void *)t6, (void *)t7);
    s = (u32)func_02045770((struct Descriptor *)((struct Obj00037 *)w)->f168);
    func_02043B5C((struct CharBuf *)s, 0);
    func_0201C7D0((void *)s, 0, 0, (void *)t6, (void *)(((struct Obj00037 *)w)->f8), 0x3C4F);
    bg = ((struct Obj00037 *)w)->f168;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
    func_02045808((struct U16Vec *)t6);
    func_02045808((struct U16Vec *)t7);
}


/*
 * The spilled second parameter is a u16 (func_021B3370 passes a u16 field
 * to func_02007FB8 in the same slot): as u32 its entry spill
 * `str r1, [sp, #8]` lands after the `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B41AC(char *w, u16 b)
{
    u32 t7, t6, s, bg;

    t7 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj02712 *)w)->f188), 0x17);
    t6 = (u32)func_020457B0(0x14, ((struct Obj02712 *)w)->f4);
    func_0201F73C((void *)(((struct Obj02712 *)w)->f170), 2, 0xE4, 9);
    func_0201EFA4((struct WordSet *)(((struct Obj02712 *)w)->f190), 0, func_02007FB8((u8 *)(((struct Obj02712 *)w)->f10), b, ((struct Obj02712 *)w)->f4), 3, 0, 1);
    func_0201F250((struct WordSet *)(((struct Obj02712 *)w)->f190), (void *)t6, (void *)t7);
    s = (u32)func_02045770((struct Descriptor *)((struct Obj02712 *)w)->f170);
    func_02043B5C((struct CharBuf *)s, 0xF);
    func_0201C7D0((void *)s, 0, 0, (void *)t6, (void *)(((struct Obj02712 *)w)->f8), 0x44F);
    bg = ((struct Obj02712 *)w)->f170;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
    func_02045808((struct U16Vec *)t6);
    func_02045808((struct U16Vec *)t7);
}


void func_021B4264(char *w, u32 b)
{
    u32 win;
    u32 t;
    u32 bg;

    win = (u32)func_02045770((struct Descriptor *)((struct Obj07523 *)w)->f178);
    func_02043B5C((struct CharBuf *)win, 0);
    if (b <= 0x272) {
        t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj07523 *)w)->f18C), b);
        func_0201C7D0((void *)win, 0, 0, (void *)t, (void *)(((struct Obj07523 *)w)->f8), 0x3C40);
        func_02045808((struct U16Vec *)t);
    }
    bg = ((struct Obj07523 *)w)->f178;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
}


void func_021B42D0(char *w, u32 a, u32 b)
{
    u32 t1, t2, t3, s, bg;

    t1 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01502 *)w)->f188), 0x18);
    t2 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01502 *)w)->f188), d_021D945C[((struct Obj01502 *)w)->f163]);
    t3 = (u32)func_020457B0(0x14, ((struct Obj01502 *)w)->f4);
    s = (u32)func_02045770((struct Descriptor *)((struct Obj01502 *)w)->f174);
    func_02043B5C((struct CharBuf *)s, 0xF);
    func_0201F73C((void *)(((struct Obj01502 *)w)->f174), 2, 0xE4, 9);
    func_0201EFA4((struct WordSet *)(((struct Obj01502 *)w)->f190), 0, a, 2, 0, 1);
    func_0201F250((struct WordSet *)(((struct Obj01502 *)w)->f190), (void *)t3, (void *)t1);
    func_0201C7D0((void *)s, 0, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    func_0201EFA4((struct WordSet *)(((struct Obj01502 *)w)->f190), 0, a * b, 7, 1, 1);
    func_0201F250((struct WordSet *)(((struct Obj01502 *)w)->f190), (void *)t3, (void *)t2);
    if (((struct Obj01502 *)w)->f163 == 0) {
        func_0201C7D0((void *)s, 0x23, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    } else {
        func_0201C7D0((void *)s, 0x1D, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    }
    bg = ((struct Obj01502 *)w)->f174;
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
    func_02045808((struct U16Vec *)t3);
    func_02045808((struct U16Vec *)t2);
    func_02045808((struct U16Vec *)t1);
}


/*
 * Builds a 0x34-byte list template on the stack (layout as read by
 * func_0201FF30) and creates the list object from it.
 */
void func_021B43EC(char *w)
{
    Tmpl t;

    t.arr = ((struct Obj00037 *)w)->f180;
    t.cb04 = (void *)func_021B468C;
    if (((struct Obj00037 *)w)->f162 == 0) {
        t.cb08 = (void *)func_021B4510;
    } else {
        t.cb08 = (void *)func_021B45A0;
    }
    t.w0c = ((struct Obj00037 *)w)->f16C;
    t.count = func_0201F91C(((struct Obj00037 *)w)->f180);
    t.rows = 7;
    t.f14 = 0;
    t.f15 = 0;
    t.f16 = 0;
    t.f17lo = 8;
    t.f17hi = 0xC;
    t.f18lo = 0;
    t.f18hi = 0xD;
    t.f1Alo = 0;
    t.f1Amid = 0;
    t.f1Apad = 1;
    t.f1Amid2 = 0;
    t.f1Atop = 1;
    t.w1c = w;
    t.h20 = 0xC;
    t.h22 = 0x10;
    t.w24 = 0;
    t.w28 = w + 0x1A8;
    t.w2c = ((struct Obj00037 *)w)->f1B0;
    t.w30 = ((struct Obj00037 *)w)->f8;
    ((struct Obj00037 *)w)->f1A4 = (unsigned int)func_0201FF30((struct Src *)(&t), 0, 0, ((struct Obj00037 *)w)->f4);
}
