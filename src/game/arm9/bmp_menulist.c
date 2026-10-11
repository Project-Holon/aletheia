/*
 * file:     bmp_menulist.c
 * unit:     yes
 * function: func_0201FF30, func_020200CC, func_0202020C, func_02020234, func_02020268, func_02020298, func_020202EC, func_020202FC, func_02020314, func_02020324, func_02020344, func_02020350, func_02020408, func_0202055C, func_020206C0, func_0202071C, func_02020780, func_020208B8, func_02020970, func_02020A34, func_02020A58, func_02020B5C, func_02020CA0, func_02020CF8, func_02020D0C, func_02020D10, func_02020D18, func_02020D3C, func_02020D5C, func_02020DC8, func_02020DEC, func_02020E08, func_02020E60, func_02020F84, func_02020FB4, func_02020FE4, func_02021014, func_020210C8, func_02021288, func_020212B0, func_020212E4, func_0202130C, func_02021350, func_0202136C, func_0202138C, func_020213AC
 * address:  0x0201FF30
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A7390     0x020A7390  data  a1
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045738  0x02045738  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_020437DC  0x020437DC  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02045730  0x02045730  arm
 *   func_0204169C  0x0204169C  arm
 *   func_02020D18_File  0x020A73A0  data
 *   func_02045808  0x02045808  arm
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_020439A0  0x020439A0  arm
 *   sub_0209E8CC_Obj  0x0209E8CC  data
 *   func_0200575C  0x0200575C  thumb
 *   func_020788AC  0x020788AC  arm
 *   func_02078C18  0x02078C18  arm
 *   g_020A73B0     0x020A73B0  data
 *   FS_CloseFile   0x02078A80  arm
 *   FS_SeekFile    0x02078B44  arm
 *   FS_ReadFile    0x02078B70  arm
 *   FS_GetLength   0x02078C28  arm
 *   sub_02030734   0x02030734  arm
 *   func_0202F170       0x0202F170  thumb
 *   func_020490F4       0x020490F4  arm
 *   func_02049250       0x02049250  arm
 *   func_02048F60       0x02048F60  arm
 *   item_gfx_member     0x0209EB6C  data
 *   item_gfx_member_x   0x0209E9E8  data
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   g_0209EAA0     0x0209EAA0  data
 *   g_0209E8EC     0x0209E8EC  data
 */
#include "../../matched/include/Obj11266.h"
#include "../../matched/include/Obj08775.h"
#include "../../matched/include/Obj08776.h"
#include "../../matched/include/Obj17238.h"
#include "../../matched/include/Obj17240.h"
#include "../../matched/include/Obj15729.h"

#define COLOR(l, s, b) ((u16)((((l) & 0x1f) << 10) | (((s) & 0x1f) << 5) | ((b) & 0x1f)))
struct CharBuf;
struct Descriptor;
struct Menu;
struct D;
struct Bmp;
struct Desc;
struct Handle;
struct Obj020437AC;
struct U16Vec;
struct PrintSys;
struct ArcFile;
struct MsgBank;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Src {
    u32 w[13];
};

typedef signed int     s32_0201FF30;

typedef signed short s16_0201FF30;

typedef signed char s8;

struct Ctl {
    u8 pad[0x18];
    u8 lo4 : 4;
    u8 hi4 : 4;
};

struct Target {
    u32 win;
    u8  dirty;
};

struct Item {
    void *text;
    u32   value;
};

typedef void (*Hook)(struct Menu *obj, u32 value, u8 y);

typedef void (*Notify)(struct Menu *obj, u32 value, void *arg);

/* The three bitfield layouts of the halfword at +0x1A. */
struct Flags1A_a {
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
};

struct Flags1A_b {
    u16 f1Alo : 7;
    u16 f1Amid : 2;
    u16 f1Atop : 7;
};

struct Flags1A_c {
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Amid2 : 8;
    u16 f1Atop : 1;
};

union Flags1A {
    struct Flags1A_a a;
    struct Flags1A_b b;
    struct Flags1A_c c;
};

struct Menu {
    struct Item *arr;
    Notify callback;
    Hook hook;
    void *unk0C;
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
    union Flags1A u;
    u32 f1C;
    u16 f20;
    u16 f22;
    u8 pad24[0x28 - 0x24];
    void *f28;
    void *f2C;
    void *f30;
    u8 f34lo : 4;
    u8 f34hi : 4;
    u8 f35lo : 4;
    u8 f35hi : 4;
    u8 f36 : 6;
    u8 f36top : 2;
    u8 f37;
    u8 f38 : 7;
    u8 f38top : 1;
    u8 pad39[0x3C - 0x39];
    void *f3C;
    u16 f40;
    u16 f42;
    u8 f44;
    u8 f45;
    u8 f46;
    u8 f47;
    u16 f48;
    u8 f4A;
};

struct Obj {
    u8    pad[0x3C];
    void *unk3C;
};

struct D {
    u8    pad[4];
    void *f4;
    void *f8;
};

typedef short          s16_02020CA0;

typedef int            s32_02020CA0;

struct Desc {
    u32   mode;
    void *f4;
    void *f8;
};

struct Handle {
    void *cell;
    u8    drawn;
};

struct FSFile {
    u8 raw[0x48];
};

struct ItemGfxMember {
    u16 lo;
    u16 hi;
};

/* The sub-record at +0x10 of the header, seventeen bytes of packed fields. */
struct Sub {
    u8 b00_0 : 1;
    u8 b00_1 : 1;
    u8 b00_2 : 1;
    u8 b00_3 : 1;
    u8 b00_4 : 1;
    u8 b00_5 : 1;
    u8 b00_6 : 1;
    u8 b00_7 : 1;

    u8 b01_0 : 1;
    u8 b01_1 : 1;
    u8 b01_2 : 1;
    u8 b01_3 : 1;
    u8 b01_4 : 4;

    u8 b02_0 : 4;
    u8 b02_4 : 4;

    u8 b03_0 : 4;
    u8 b03_4 : 4;

    u8 b04_0 : 4;
    u8 b04_4 : 2;
    u8 b04_6 : 1;
    u8 b04_7 : 1;

    u8 b05_0 : 1;
    u8 b05_1 : 1;
    u8 b05_2 : 1;
    u8 b05_3 : 1;
    u8 b05_4 : 1;
    u8 b05_5 : 1;
    u8 b05_6 : 1;
    u8 b05_7 : 1;

    u8 b06_0 : 1;
    u8 b06_1 : 1;
    u8 b06_2 : 1;
    u8 b06_3 : 1;
    u8 b06_4 : 1;

    s8 f07;
    s8 f08;
    s8 f09;
    s8 f0A;
    s8 f0B;
    s8 f0C;
    u8 f0D;
    u8 f0E;
    s8 f0F;
    s8 f10;
    s8 f11;
};

/* The record header. */
struct Rec {
    u16 f00;
    u8  f02;
    u8  f03;
    u8  f04;
    u8  f05;
    u8  f06;
    u8  f07;
    u16 b08_0  : 5;
    u16 b08_5  : 1;
    u16 b08_6  : 1;
    u16 b08_7  : 4;
    u16 b08_11 : 5;
    u8  f0A;
    u8  f0B;
    u8  f0C;
    u8  f0D;
    u8  f0E;
    u8  f0F;
    u8  f10;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020061E4(u32 id);
extern u32 func_020307B0(void *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern u8 func_02045738(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_02045334(struct Descriptor *win);
extern void *func_020437D4(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_0204169C(int channel);
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void *func_0200575C(u32 x);
extern void  func_020788AC(void *p);
extern void  func_02078C18(void *p, void *q);
extern void  FS_CloseFile(struct FSFile *file);
extern u32   FS_SeekFile(struct FSFile *file, int offset, u32 origin);
extern u32   FS_ReadFile(struct FSFile *file, void *dst, u32 size);
extern u32   FS_GetLength(struct FSFile *file);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   func_0202F170(u32 item);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
struct Menu *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
s32_0201FF30 func_020200CC(struct Menu *o);
void func_0202020C(struct Menu *o, u16 *a, u16 *b);
void func_02020234(struct Menu *p);
void func_02020268(struct Menu *obj, u8 a, u8 b, u8 c);
void func_02020298(struct Menu *obj, u8 a, u8 b, u8 c);
void func_020202EC(struct Menu *obj, u16 *out);
void func_020202FC(struct Menu *obj, u16 *a, u16 *b);
u16 func_02020314(struct Menu *obj);
u16 func_02020324(struct Menu *obj, u32 n);
u32 func_02020344(struct Menu *obj, u32 n);
u32 func_02020350(struct Menu *obj, u32 what);
void func_02020408(struct Menu *obj, const void *text, u32 x, u32 y, u32 sel);
void func_0202055C(struct Menu *obj, u16 row, u16 col, u16 n, u32 flag);
void func_020206C0(struct Menu *obj);
void func_0202071C(struct Menu *obj, u32 n);
u8 func_02020780(struct Menu *obj, u8 dir);
void func_020208B8(struct Menu *obj, u16 n, u32 flag);
u32 func_02020970(struct Menu *obj, u8 notify, u8 count, u8 dir);
void func_02020A34(struct Menu *obj, void *arg1);
void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size);
void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size);
void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile);
void func_02020CF8(struct Menu *p, int heap);
u32 func_02020D0C(struct Menu *p);
void func_02020D10(struct Menu *p, u32 v);
void *func_02020D18(u32 heap);
void func_02020D3C(struct D *p);
void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);
void func_02020DC8(char *p, int a);
void func_02020DEC(void *p, u32 x);
void *func_02020E08(u32 archive_id, u32 heap, u32 offset, u32 size);
u32 func_02020E60(u32 item, u32 which);
u32 func_02020F08(void);
u32 func_02020F0C(void);
u32 func_02020F10(void);
void *func_02020F14(u32 heap);
u32 func_02020F20(void *handle, u32 item, u32 arg);
void *func_02020F34(u32 item, u32 which, u32 heap);
void func_02020F84(void *dst, u32 entry, u32 heap);
void func_02020FB4(void *dst, u32 entry, u32 heap);
u32 func_02020FE4(void *a, u32 sel, u32 id);
u32 func_02021014(struct Rec *p, u32 sel);
int func_020210C8(struct Sub *q, u32 sel);
u32 func_02021288(u32 id);
u16 func_020212B0(u16 id);
u32 func_020212E4(u16 v);
u32 func_0202130C(u32 id);
u8 func_02021350(u16 id);
u32 func_0202136C(u16 v);
u8 func_0202138C(u16 v);
u16 func_020213AC(u32 i);
extern char g_020A7390[];
extern const char func_02020D18_File[];
extern u8 sub_0209E8CC_Obj[];
extern char g_020A73B0[];
extern struct ItemGfxMember item_gfx_member[];
extern struct ItemGfxMember item_gfx_member_x[];
extern const u16 g_0209EAA0[];
extern const u16 g_0209E8EC[];






struct Menu *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap)
{
    struct Menu *obj;
    int i;
    u32 *d;
    u32 *s;

    obj = (struct Menu *)func_02030734(heap, 0x50, 1, g_020A7390, 0x69);
    *(struct Src *)obj = *src;
    obj->f3C = func_02020D18(heap);
    obj->f40 = a;
    obj->f42 = b;
    obj->f44 = 0;
    obj->f45 = 0;
    obj->f46 = 0xFF;
    obj->f47 = 0;
    obj->f48 = (u16)heap;
    obj->f34lo = obj->f17hi;
    obj->f34hi = obj->f18lo;
    obj->f35lo = obj->f18hi;
    obj->f36 = (u8)obj->u.a.f1Alo;
    obj->f38 = (u8)obj->u.a.f1Amid2;
    obj->f38top = 0;
    if (obj->count < obj->rows) {
        obj->rows = obj->count;
    }
    while (*(u32 *)((u8 *)obj->arr + (obj->f40 + obj->f42) * 8 + 4) == (u32)-3) {
        obj->f42++;
    }
    {
        u8 *q = (u8 *)obj->f28;
        ((struct Obj11266 *)q)->f0 = (u32)obj->unk0C;
        q[4] = 0;
    }
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->unk0C)), obj->f18lo);
    func_0202055C(obj, obj->f40, 0, obj->rows, 1);
    func_020206C0(obj);
    func_02020A34(obj, (void *)1);
    return obj;
}






/*
 * The per-frame key handler of the menu-cursor object built by
 * func_0201FF30: same shape as func_0201FA04 one block down, over the wider
 * struct that unit_020206C0.c already spells out.  Sound ids 0x54C / 0x551 /
 * 0x548 sit in the trailing pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020200CC.c \
 *       --func func_020200CC --addr 0x020200CC --thumb
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/func_020200CC.c.txt,
 * 81 bytes out).  The note read the residue as an allocator choice (`tst`
 * versus a copy and `ands`); it was a misread of the image.  In the
 * f1Amid == 2 arm the masks are derived from the 0x80 still live in r2:
 * `lsls r1, r2, #2` is 0x200 and `adds r2, #0x80` is 0x100, so the arm reads
 * the L and R shoulder buttons (0x200, 0x100), not up/down (0x40, 0x80).
 * With the right constants the 0x40 test becomes a plain `tst` by itself,
 * and the switch closes once case 0 and default share one arm.
 * func_02020970's prototype is the EXACT one (u8 scalar parameters).
 */
s32_0201FF30 func_020200CC(struct Menu *o)
{
    u32 keys = func_020362DC();
    u32 one = 1;
    u32 held = func_0203633C();

    o->f47 = 0;

    if (keys & one) {
        func_020061E4(0x54C);
        return o->arr[o->f40 + o->f42].value;
    }
    if (o->f4A == 0) {
        u32 two = 2;
        if (keys & two) {
            func_020061E4(0x551);
            return two - 4;
        }
    }
    if (held & 0x40) {
        if (func_02020970(o, 1, 1, 0) == 0) {
            func_020061E4(0x548);
            o->f47 = 1;
        }
        return -1;
    }
    if (held & 0x80) {
        if (func_02020970(o, 1, 1, 1) == 0) {
            func_020061E4(0x548);
            o->f47 = 2;
        }
        return -1;
    }
    {
        u16 h, v;
        switch (o->u.b.f1Amid) {
        case 0:
        default:
            h = 0;
            v = 0;
            break;
        case 1:
            h = (u16)(held & 0x20);
            v = (u16)(held & 0x10);
            break;
        case 2:
            h = (u16)(held & 0x200);
            v = (u16)(held & 0x100);
            break;
        }
        if (h != 0) {
            if (func_02020970(o, 1, (u8)o->rows, 0) == 0) {
                func_020061E4(0x548);
                o->f47 = 3;
            }
            return -1;
        }
        if (v != 0) {
            if (func_02020970(o, 1, (u8)o->rows, 1) == 0) {
                func_020061E4(0x548);
                o->f47 = 4;
            }
            return -1;
        }
    }
    return -1;
}







void func_0202020C(struct Menu *o, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = o->f40;
    }
    if (b != 0) {
        *b = o->f42;
    }
    func_02020D3C((struct D *)o->f3C);
    func_020307B0(o);
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020234.c \
 *       --func func_02020234 --addr 0x02020234 --cc 1.1p1 --thumb
 */
void func_02020234(struct Menu *p)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->unk0C)), p->f18lo);
    func_0202055C(p, p->f40, 0, p->rows, 1);
    func_020206C0(p);
}







/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020268.c \
 *       --addr 0x02020268 --thumb
 *
 * The bmp_menulist.c attribute block 0x02020268..0x02020408, eight
 * functions of which only 0x02020268 was ever near a label.  The
 * worklist entry 0x020202CC (a "32-byte open function") is NOT a
 * function start: it is the middle of func_02020298 (the colour-override
 * setter), seeded into layout/function_starts.txt from a pending header
 * that misnamed sub_02022AC4's tail-call target (the pool word there is
 * 0x020222CD; see docs/notes/pkt_02022940.c.txt, wave 11).  The 32 bytes
 * the worklist counted are func_02020298's last eight instructions.
 *
 *   func_02020268  set the three colour nibbles f17hi / f18lo / f18hi
 *   func_02020298  set the override nibbles f34lo / f34hi / f35lo and the
 *                  override flag f38top (func_0201FF30 seeds the same
 *                  three from f17hi / f18lo / f18hi)
 *   func_020202EC  *out = f40 + f42 (list index of the cursor row)
 *   func_020202FC  optional out-pointers for f40 and f42
 *   func_02020314  tail call to func_02020324 with the cursor row f42
 *   func_02020324  pixel y of row n: f17lo + n * (u8)(f22 + f1Amid),
 *                  the expression unit_020206C0 inlines
 *   func_02020344  arr[n].value, the item's value word
 *   func_02020350  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */
void func_02020268(struct Menu *obj, u8 a, u8 b, u8 c)
{
    obj->f17hi = a;
    obj->f18lo = b;
    obj->f18hi = c;
}





void func_02020298(struct Menu *obj, u8 a, u8 b, u8 c)
{
    obj->f34lo = a;
    obj->f34hi = b;
    obj->f35lo = c;
    obj->f38top = 1;
}





void func_020202EC(struct Menu *obj, u16 *out)
{
    *out = obj->f40 + obj->f42;
}





void func_020202FC(struct Menu *obj, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = obj->f40;
    }
    if (b != 0) {
        *b = obj->f42;
    }
}







u16 func_02020314(struct Menu *obj)
{
    return func_02020324(obj, obj->f42);
}





u16 func_02020324(struct Menu *obj, u32 n)
{
    return (u16)(obj->f17lo + n * (u8)(obj->f22 + obj->u.a.f1Amid));
}





u32 func_02020344(struct Menu *obj, u32 n)
{
    return obj->arr[n].value;
}





u32 func_02020350(struct Menu *obj, u32 what)
{
    switch (what) {
    case 0:  return (u32)obj->callback;
    case 1:  return (u32)obj->hook;
    case 2:  return obj->count;
    case 3:  return obj->rows;
    case 5:  return obj->f14;
    case 6:  return obj->f15;
    case 7:  return obj->f16;
    case 8:  return obj->f17lo;
    case 9:  return obj->f22 + obj->u.a.f1Amid;
    case 10: return obj->f17hi;
    case 11: return obj->f18lo;
    case 12: return obj->f18hi;
    case 13: return obj->u.a.f1Alo;
    case 14: return obj->u.a.f1Amid;
    case 15: return obj->u.a.f1Apad;
    case 16: return obj->u.a.f1Amid2;
    case 17: return obj->u.a.f1Atop;
    case 18: return (u32)obj->unk0C;
    case 19: return obj->f1C;
    }
    return -1;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020408.c \
 *       --func func_02020408 --addr 0x02020408 --thumb
 *
 * Print one item's text into the menu window.  f38top selects the override
 * colours at +0x34/+0x35 (set by unit_02020268's func_02020298) over the
 * list's own at +0x17/+0x18; sel picks func_0201C724 (which also marks the
 * target dirty) over func_0201C7D0.  Closed in wave 13; the 2026-09-21 note
 * (docs/notes/func_02020408.c.txt) had it at 314 of 338 bytes.
 *
 * The packed colour is a 5:5:5 triple built by a masking macro,
 *     ((l & 0x1f) << 10) | ((s & 0x1f) << 5) | (b & 0x1f)
 * over the 4-bit nibbles: mwcc turns each mask-then-shift into the
 * `<< 27 / >> 17` and `<< 27 / >> 22` pairs and keeps the bare `ands 0x1f`
 * on the unshifted term, which is exactly the "5-bit destination over a
 * 4-bit source" shape the note described.  No 5-bit bitfield struct needed.
 *
 * THE IMAGE'S FOURTH ARM (f38top clear, sel == 0) READS THE OVERRIDE BYTES
 * +0x34/+0x35, not +0x17/+0x18 like the third arm.  That is what the bytes
 * say, and the C reproduces it; it reads like a copy-paste slip in the
 * original.  EXACT* only because the extent includes 2 bytes of padding.
 */
void func_02020408(struct Menu *obj, const void *text, u32 x, u32 y, u32 sel)
{
    if (text == 0)
        return;
    if (obj->f38top) {
        if (sel) {
            u32 a = (u32)obj->f2C;
            struct Target *t = (struct Target *)obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, (u32)obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)((struct Target *)obj->f28)->win), x, y, text, (u32)obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    } else {
        if (sel) {
            u32 a = (u32)obj->f2C;
            struct Target *t = (struct Target *)obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, (u32)obj->f30,
                          COLOR(obj->f17hi, obj->f18hi, obj->f18lo));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)((struct Target *)obj->f28)->win), x, y, text, (u32)obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    }
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202055C.c \
 *       --func func_0202055C --addr 0x0202055C --thumb
 *
 * Redraw n + 1 rows of the menu list from item `row`, starting at window
 * row `col`.  When flag is set and row > 0 the window is first scrolled by
 * one row: the band is cleared with func_02043AF4, the item above is
 * redrawn and func_02020CA0 moves the pixels.  Every item goes through the
 * optional per-item hook at +0x08 (obj, item value, y) and then
 * func_02020408 at x = f15, or f14 for a separator (value -3).
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/func_0202055C.c.txt,
 * 96 out).  That source misread three things, all fixed here from the image:
 * the hook's second argument inside the loop is the item's value word (still
 * live in r1 from the separator test), not 0; func_02020CA0's last argument
 * is (step*2/8) * (func_020437DC(bitmap) / 8), the bitmap's width in tiles,
 * not step >> 3; and the x colour is an int (no truncation after the
 * ternary).  Then the permuter's type:l(step:u8->int) (the value is still
 * (u8)-truncated at its one assignment) swapped the last two stack slots.
 * EXACT* only because the extent includes 2 bytes of padding.
 */
void func_0202055C(struct Menu *obj, u16 row, u16 col, u16 n, u32 flag)
{
    int step;
    int x;
    u8 y;
    int i;
    int lim;

    step = (u8)(obj->f22 + obj->u.a.f1Amid);
    if (row != 0 && flag != 0) {
        u32 bmp;
        u8 w;
        u8 k;
        x = (obj->arr[row - 1].value != (u32)-3) ? obj->f15 : obj->f14;
        bmp = (u32)func_02045770((struct Descriptor *)obj->unk0C);
        w = func_02045738((struct Descriptor *)obj->unk0C);
        func_02043AF4((struct Bmp *)bmp, 0, 0, (u16)(w * 8),
                      (u16)(obj->f17lo + (col + 1) * step * 2), obj->f18lo);
        y = (u8)(obj->f17lo + col * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row - 1].value, y);
        func_02020408(obj, obj->arr[row - 1].text, x, y, 0);
        k = obj->f18lo;
        func_02020CA0((void *)obj->unk0C, 0, step, (u8)((k << 4) | k),
                      (u16)((step * 2 / 8) * (func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C))) / 8)));
    }
    lim = (u16)(n + 1);
    for (i = 0; i < lim; i++) {
        x = (obj->arr[row].value != (u32)-3) ? obj->f15 : obj->f14;
        y = (u8)(obj->f17lo + (i + col) * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row].value, y);
        func_02020408(obj, obj->arr[row].text, x, y, 1);
        row++;
        if (row >= obj->count)
            return;
    }
}





/*
 * The two redraw entry points of the menu-cursor block, func_020206C0 and
 * func_0202071C, folded into one translation unit so 0x020206C0..0x0202077E
 * reproduces end to end.  Both dispatch on the same one-bit field at the top
 * of the u16 at +0x1A through a four-entry PC-relative halfword table whose
 * cases 1..3 are empty arms; the empty arms are what make the table exist
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Both pass the same derived byte, f17lo + <row> * (u8)(f22 + f1Amid), to
 * their callee; in func_020206C0 the row is the cursor's own f42 and the
 * value must be bound to a named local computed BEFORE the switch (as must
 * f16), or the compiler sinks both into the case-0 arm and the function is
 * four bytes short.  In func_0202071C the row is the function's second
 * argument and the same value is an inline argument, scheduled per site
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 */
void func_020206C0(struct Menu *obj)
{
    u8 a = obj->f17lo;
    u8 b = obj->f16;
    u8 v = (u8)(a + obj->f42 * (u8)(obj->f22 + obj->u.c.f1Amid));

    switch (obj->u.c.f1Atop) {
    case 0:
        func_02020D5C(obj->f3C, b, v, obj->f28, obj->f2C, (u32)obj->f30);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}




void func_0202071C(struct Menu *obj, u32 n)
{
    switch (obj->u.c.f1Atop) {
    case 0:
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C)),
                      obj->f16,
                      (s16_0201FF30)(u16)(obj->f17lo + n * (u8)(obj->f22 + obj->u.c.f1Amid)),
                      obj->f20,
                      obj->f22,
                      obj->f18lo);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020780.c \
 *       --func func_02020780 --addr 0x02020780 --thumb
 *
 * One cursor step of the scrolling menu list, dir 0 = up, else down.  The
 * cursor row (f42) moves inside the window, skipping items whose value word
 * is -3 (separators), and answers 1; at the window's middle row the list
 * scrolls instead (f40 -= 1 / += 1, cursor parked on the middle row) and it
 * answers 2; at either end of the list it answers 0.  The middle row is
 * rows - (rows/2 + rows%2) - 1 going up and rows/2 + rows%2 going down, 0
 * for a one-row window.
 *
 * Re-derived in wave 13 (the 2026-09-21 note, docs/notes/func_02020780.c.txt,
 * kept no source).  What pinned the register map obj=r0 row=r4 col=r3
 * rows=r2, which that note could not reach:
 *   - col (f40) is an int local, not u16 (u16 keeps obj out of r0);
 *   - rows is read into its local INSIDE each arm, not before the test
 *     (the image loads +0x12 after `cmp r1, #0`);
 *   - declaration order ncol, col, rows, mid, row (the permuter's
 *     decl-order row<->ncol; row declared first swaps r3/r4).
 * EXACT* only because the listing's extent includes the two bytes of
 * alignment padding after the function.
 */
u8 func_02020780(struct Menu *obj, u8 dir)
{
    int ncol;
    int col;
    u16 rows;
    u16 mid;
    u16 row;

    row = obj->f42;
    col = obj->f40;
    if (dir == 0) {
        rows = obj->rows;
        if (rows == 1) {
            mid = 0;
        } else {
            mid = rows - (rows / 2 + rows % 2) - 1;
        }
        if (col == 0) {
            while (row != 0) {
                row--;
                if (obj->arr[col + row].value != (u32)-3) {
                    obj->f42 = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row > mid) {
            row--;
            if (obj->arr[col + row].value != (u32)-3) {
                obj->f42 = row;
                return 1;
            }
        }
        obj->f42 = mid;
        ncol = col - 1;
    } else {
        rows = obj->rows;
        if (rows == 1) {
            mid = 0;
        } else {
            mid = rows / 2 + rows % 2;
        }
        if (col == obj->count - rows) {
            while ((int)row < rows - 1) {
                row++;
                if (obj->arr[col + row].value != (u32)-3) {
                    obj->f42 = row;
                    return 1;
                }
            }
            return 0;
        }
        while (row < mid) {
            row++;
            if (obj->arr[col + row].value != (u32)-3) {
                obj->f42 = row;
                return 1;
            }
        }
        obj->f42 = mid;
        ncol = col + 1;
    }
    obj->f40 = ncol;
    return 2;
}





void func_020208B8(struct Menu *obj, u16 n, u32 flag)
{
    u8 step;

    if (n >= (int)obj->rows) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->unk0C)), obj->f18lo);
        func_0202055C(obj, obj->f40, 0, obj->rows, 1);
        return;
    }

    step = (u8)(obj->f22 + obj->u.c.f1Amid);
    if (flag == 0) {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 1, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C(obj, obj->f40, 0, n, 1);
    } else {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 0, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C(obj, (u16)(obj->f40 + (obj->rows - n)), (u16)(obj->rows - n), n, 0);
    }
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020970.c \
 *       --func func_02020970 --addr 0x02020970 --thumb
 *
 * Move the menu cursor count steps in direction dir (func_02020780 does one
 * step and answers 0 = no move, 1 = cursor moved inside the window, 2 = the
 * list scrolled), then, if notify, redraw what changed.  Closed in wave 13
 * after the 2026-09-21 note (docs/notes/func_02020970.c.txt) left it at 34
 * bytes out.  What closed it, in order of weight:
 *   - ALL THREE SCALAR PARAMETERS ARE NARROW (u8 here; u16 compiles the
 *     same).  u8 count is what gives the guard its `cmp r0,#0 / bls` with
 *     the reload from the home slot (u32 count gives `cmp #1 / blo` or folds
 *     onto r2); u8/u16 notify and dir are what schedule the three home
 *     stores ahead of the obj copy.
 *   - the guard is `i < count` with i already 0, around a do/while;
 *   - a skipped row (item value -3) re-runs the step WITHOUT advancing i:
 *     a goto to the top of the body, not a continue (continue reaches the
 *     condition);
 *   - `case 0: default: return 1;` written first; without case 0 the switch
 *     becomes a compare chain, with a separate default it duplicates.
 */
u32 func_02020970(struct Menu *obj, u8 notify, u8 count, u8 dir)
{
    u8 acc;
    u8 moved;
    u8 i;
    u8 r;
    u16 saved;

    moved = 0;
    acc = 0;
    saved = obj->f42;
    i = 0;
    if (i < count) {
        do {
        again:
            r = func_02020780(obj, dir);
            acc |= r;
            if (r == 2) {
                moved++;
                if (obj->arr[obj->f40 + obj->f42].value == (u32)-3)
                    goto again;
            }
            i++;
        } while (i < count);
    }
    if (notify != 0) {
        switch (acc) {
        case 0:
        default:
            return 1;
        case 1:
            func_0202071C(obj, saved);
            func_020206C0(obj);
            func_02020A34(obj, 0);
            func_02045334((struct Descriptor *)obj->unk0C);
            break;
        case 2:
        case 3:
            func_0202071C(obj, saved);
            func_020208B8(obj, moved, dir);
            func_020206C0(obj);
            func_02020A34(obj, 0);
            break;
        }
    }
    return 0;
}





void func_02020A34(struct Menu *obj, void *arg1)
{
    if (obj->callback != 0) {
        obj->callback(obj, obj->arr[obj->f40 + obj->f42].value, arg1);
    }
}





void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size)
{
    u32  wt;
    u32  fill;
    s32_0201FF30  len;
    s32_0201FF30  y;
    s32_0201FF30  src;
    s32_0201FF30  dst;
    u32  t;
    s32_0201FF30  x;
    u8  *buf;

    buf = func_020437D4(bmp);
    fill = (color << 24) | (color << 16) | (color << 8) | color;
    wt = (u32)func_020437DC(bmp) >> 3;
    len = size;
    if (len == 0)
        len = (wt * ((u32)func_020437E4(bmp) >> 3)) << 5;

    switch (dir) {
    case 0:
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                *(u32 *)(buf + dst) =
                    (src < len) ? *(u32 *)(buf + src) : fill;
                t++;
            }
        }
        break;
    case 1:
        buf = buf + (len - 4);
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32 *q;
                u32  v;
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                if (src < len) {
                    v = *(u32 *)(buf - src);
                    q = (u32 *)(buf - dst);
                } else {
                    q = (u32 *)(buf - dst);
                    v = fill;
                }
                t++;
                *q = v;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}





void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size)
{
    u32  wt;
    u32  fill;
    s32_0201FF30  len;
    s32_0201FF30  y;
    s32_0201FF30  src;
    s32_0201FF30  dst;
    u32  t;
    s32_0201FF30  x;
    u8  *buf;

    buf = func_020437D4(bmp);
    fill = (color << 24) | (color << 16) | (color << 8) | color;
    wt = (u32)func_020437DC(bmp) >> 3;
    len = size;
    if (len == 0)
        len = (wt * ((u32)func_020437E4(bmp) >> 3)) << 6;

    switch (dir) {
    case 0:
        for (y = 0; y < len; y += 0x40) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32 v;
                dst = y + x * 8;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 3);
                if (src < len) {
                    v = *(u32 *)(buf + src);
                    *(u32 *)(buf + dst) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf + dst) = v;
                }
                if (src + 4 < len + 4) {
                    v = *(u32 *)(buf + (src + 4));
                    *(u32 *)(buf + (dst + 4)) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf + (dst + 4)) = v;
                }
                t++;
            }
        }
        break;
    case 1:
        buf = buf + (len - 8);
        for (y = 0; y < len; y += 0x40) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32  v;
                dst = y + x * 8;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 3);
                if (src < len) {
                    v = *(u32 *)(buf - src);
                    *(u32 *)(buf - dst) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf - dst) = v;
                }
                if (src - 4 < len - 4) {
                    v = *(u32 *)(buf - (src - 4));
                    dst = dst - 4;
                    *(u32 *)(buf - dst) = v;
                } else {
                    dst = dst - 4;
                    v = fill;
                    *(u32 *)(buf - dst) = v;
                }
                t++;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}






/*
 * UNBLOCKED 2026-09-21: the two THM_CALL sites at +0x36 and +0x4e now
 * attest `matched` off src/matched/func_02020A58.c and the newly filed
 * src/matched/func_02020B5C.c.  All 5 relocation sites resolve and the
 * verdict is EXACT*; promoted from src/pending/ unchanged apart from
 * this header.  EXACT* only because 0x02020CF8 has no label.
 *
 * Window-fill front end.  The window descriptor names a BG channel
 * (func_02045730, the +2 accessor) and carries the bitmap it draws into
 * (func_02045770, the +0xc handle).  func_0204169C says whether that
 * channel is 8bpp; the 4bpp path calls func_02020A58 and the 8bpp path
 * func_02020B5C, and the caller's tile offset is converted to a byte
 * offset by the depth: (t & 0x7ff) << 5 for 4bpp, (t & 0x3ff) << 6 for
 * 8bpp, i.e. 32 or 64 bytes per tile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020CA0.c \
 *       --func func_02020CA0 --addr 0x02020CA0 --cc 1.1p1 --thumb
 */
void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile)
{
    int   channel;
    void *bmp;

    channel = func_02045730(win);
    bmp = func_02045770(win);

    if (func_0204169C(channel) == 0)
        func_02020A58(bmp, a, b, c, (u16)(tile << 5));
    else
        func_02020B5C(bmp, a, b, c, (u16)(tile << 6));
}






/*
 * A whole translation unit, matched as one byte range.
 *
 * func_02020D0C and func_02020D10 carry no label in the generated listing:
 * they are a two-instruction word getter and a two-instruction byte setter
 * with no register-saving prologue, so disasm.py's prologue sweep never
 * fires on them and the listing prints them as a run of data between
 * func_02020CF8 and func_02020D18
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * func_02020D18 is a debug-allocator constructor in the
 * `sub_02030734(heap, size, count, file, line)` shape documented for
 * playtime.c: it allocates a 12-byte object tagged with the string at
 * 0x020A73A0 and line 0x3a, zeroing the first word when the allocation
 * succeeds.  0x020A73A0 spells "bmp_cursor.c", the second original source
 * file name this project has recovered (after playtime.c); the functions
 * keep their sub_<address> names because the file identity is attested and
 * the individual entry points are not.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020CF8.c \
 *       --addr 0x02020CF8 --thumb
 */
void func_02020CF8(struct Menu *p, int heap)
{
    func_02020DC8(p->f3C, heap);
    func_020206C0(p);
}



u32 func_02020D0C(struct Menu *p)
{
    return p->f1C;
}






void func_02020D10(struct Menu *p, u32 v)
{
    p->f4A = v;
}






void *func_02020D18(u32 heap)
{
    void *p = func_02030734((u16)heap, 0xc, 1, func_02020D18_File, 0x3a);

    if (p != 0) {
        ((struct Obj17240 *)p)->f0 = 0;
    }
    return p;
}






/*
 * A destructor: frees two owned sub-objects at +4 and +8 if present, then
 * hands the object itself to a common finalizer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020D3C.c \
 *       --func func_02020D3C --addr 0x02020D3C --cc 1.1p1 --thumb
 */
void func_02020D3C(struct D *p)
{
    if (p->f4 != 0) {
        func_02045808(p->f4);
    }
    if (p->f8 != 0) {
        func_020437AC(p->f8);
    }
    func_020307B0(p);
}




/*
 * Blits one cursor/icon out of its cell holder, choosing between two
 * targets by the descriptor's mode word: mode 1 draws through the
 * 0x0201C6FC window path and latches a "drawn" flag on the caller's
 * handle, anything else falls back to the plain 8x8 palette-0xf blit
 * at 0x020439A0 when a surface is configured, and releases the cell
 * afterwards.
 */
void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h,
                   void *dst, u32 f)
{
    if (d->mode == 1) {
        func_0201C6FC(dst, (u32)func_02045770(h->cell), (s16_02020CA0)x, (s16_02020CA0)y, d->f4, f);
        h->drawn = 1;
    } else if (d->f8 != 0) {
        func_020439A0(d->f8, func_02045770(h->cell), 0, 0,
                      x + 2, y + 2, 8, 8, 0xf);
        func_02045334(h->cell);
    }
}




void func_02020DC8(char *p, int a)
{
    ((struct Obj15729 *)p)->f8 = (u32)func_020436FC((void *)((int)sub_0209E8CC_Obj), 1, 1, 0x20, a);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020DEC.c \
 *       --func func_02020DEC --addr 0x02020DEC --cc 1.1p1 --thumb
 */
void func_02020DEC(void *p, u32 x)
{
    void *q;

    q = func_0200575C(x);
    func_020788AC(p);
    func_02078C18(p, q);
}





/*
 * "Read a byte range out of a whole file, by archive id", the raw-file
 * counterpart to the arc_tool.c NARC member API.  func_02020DEC (already
 * EXACT) opens the file whose path is name-table entry `archive_id`; this
 * function then seeks to `offset`, allocates `size` bytes on `heap` and
 * reads them in.  A zero `size` means "the whole file", which is why the
 * FS_GetLength call is guarded rather than unconditional.
 *
 * g_020A73B0 is the __FILE__ argument of the allocation site.  Its bytes
 * spell "file_util.c", and the run is fixed from outside this function by
 * the terminator of "bmp_cursor.c" immediately before it
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), so the
 * enclosing translation unit for both this function and func_02020DEC is
 * file_util.c.
 *
 * The only caller in the image is sub_0201407C, the a/0/1/3 record reader
 * (src/matched/sub_0201407C.c), which passes archive_id 13 with size 10:
 * a/0/1/3 is a flat 2820-byte file, not a NARC, so it cannot go through
 * the member API at all.  See the "Archive readers traced by call graph"
 * section of docs/ASSETS.md.
 *
 * `size` has to stay live in its own local across the guarded call: the
 * compiler keeps r5 as both the parameter and the FS_GetLength result, so
 * writing the length into a fresh variable and selecting afterwards costs
 * an extra move.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020E08.c \
 *       --func func_02020E08 --addr 0x02020E08 --cc 1.1p1 --thumb
 */
void *func_02020E08(u32 archive_id, u32 heap, u32 offset, u32 size)
{
    struct FSFile file;
    void *buf;

    func_02020DEC(&file, archive_id);
    if (size == 0) {
        size = FS_GetLength(&file);
    }
    buf = sub_02030734(heap, size, 0, g_020A73B0, 0xAC);
    FS_SeekFile(&file, offset, 0);
    FS_ReadFile(&file, buf, size);
    FS_CloseFile(&file);
    return buf;
}




/*
 * The item archive's own accessor block: 0x02020E60..0x02020F84, seven
 * functions, five of them unlabelled leaves that print as a `.word`/`.byte`
 * run in the listing (see docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).
 *
 * This is the file that closes the item chain
 * func_02021014 <- func_02020FE4 <- func_02020F34: three separate functions
 * here name the item archive id 0x18 as a plain immediate
 * (func_02020F14's handle open, func_02020F34's one-shot member read) and
 * two name the item graphics archive 0x19 (func_02020F08 answers it as a
 * constant, func_02020F34 reads members of it).  Archive ids are the
 * decimal spelling of the a/X/Y/Z path, so 0x18 = 24 = a/0/2/4 and
 * 0x19 = 25 = a/0/2/5.
 *
 * 626 is the last item id: a/0/2/4 has 627 members, 0..626.  Both bounds
 * checks in this file clamp an out of range id to 0 rather than rejecting.
 *
 * Blocked at MATCH, not EXACT: three relocation sites have no witness
 * outside this range.
 *   - item_gfx_member_x (0x0209E9E8) and func_0202F170 (0x0202F170) are
 *     named only from here anywhere in the image.
 *   - item_gfx_member (0x0209EB6C) has exactly one literal witness,
 *     0x02020F7C, which is func_02020F34's own pool and therefore inside
 *     this range.  func_02020E60's copy of the same word sits at
 *     0x02020EF4 but is not indexed as a literal pool by disasm.py: that
 *     pool is inside the `.byte` run this unit's leaf functions live in.
 *     Splitting func_02020E60 and func_02020F34 into two files does not
 *     fix it either: verified separately, the split leaves
 *     func_02020E60 attested (literal 0x02020F7C, now outside its range)
 *     and func_02020F34 still not, since its only witness is its own
 *     pool word.  `tu --suggest-split` agrees and leaves both out.
 *
 * The middle piece that --suggest-split does keep, the five leaf
 * accessors 0x02020F08..0x02020F34, is filed EXACT on its own as
 * src/matched/unit_02020F08.c; this file stays as the whole-range record.
 *
 * Every concrete byte of this range is reproduced; only the relocation
 * fields above stay wildcarded.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02020E60.c \
 *       --addr 0x02020E60 --thumb
 */
u32 func_02020E60(u32 item, u32 which)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        if (item == 0 || item == 0xFFFF) {
            break;
        }
        return item;
    case 1:
        if (item == 0) {
            return 1001;
        }
        if (item == 0xFFFF) {
            return 1003;
        }
        return item_gfx_member[item].lo;
    case 2:
        if (item == 0) {
            return 1002;
        }
        if (item == 0xFFFF) {
            return 1004;
        }
        return item_gfx_member[item].hi;
    case 3:
        return item_gfx_member_x[func_0202F170(item)].lo;
    case 4:
        return item_gfx_member_x[func_0202F170(item)].hi;
    }

    return 0;
}




u32 func_02020F08(void)
{
    return 0x19;
}




u32 func_02020F0C(void)
{
    return 1;
}




u32 func_02020F10(void)
{
    return 0;
}




void *func_02020F14(u32 heap)
{
    return func_020490F4(0x18, heap);
}




u32 func_02020F20(void *handle, u32 item, u32 arg)
{
    if (item > 626) {
        item = 0;
    }

    return (u32)func_02049250(handle, item, arg);
}




void *func_02020F34(u32 item, u32 which, u32 heap)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        return func_02048F60(0x18, item, heap);
    case 1:
        return func_02048F60(0x19, item_gfx_member[item].lo, heap);
    case 2:
        return func_02048F60(0x19, item_gfx_member[item].hi, heap);
    }

    return 0;
}





/*
 * One of a pair of near-identical entry points (func_02020F84 uses table 0x36,
 * func_02020FB4 table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id func_02021288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020F84.c  *       --func func_02020F84 --addr 0x02020F84 --cc 1.1p1 --thumb
 */
void func_02020F84(void *dst, u32 entry, u32 heap)
{
    void *arc;

    if (entry > 0x272) {
        entry = 0;
    }
    arc = func_02045B38(0, 2, 0x36, heap);
    func_02045CAC(arc, entry, dst);
    func_02045C04(arc);
}





/*
 * One of a pair of near-identical entry points (func_02020F84 uses table 0x36,
 * func_02020FB4 table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id func_02021288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020FB4.c  *       --func func_02020FB4 --addr 0x02020FB4 --cc 1.1p1 --thumb
 */
void func_02020FB4(void *dst, u32 entry, u32 heap)
{
    void *arc;

    if (entry > 0x272) {
        entry = 0;
    }
    arc = func_02045B38(0, 2, 0x35, heap);
    func_02045CAC(arc, entry, dst);
    func_02045C04(arc);
}





/*
 * One-shot wrapper over the record getter of src/matched/unit_02021014.c:
 * build a temporary record for the id (with bit 15 forced on and the rest of
 * the id masked to fifteen bits), read one property out of it, free it, and
 * answer the property.
 *
 * 0x8000 costs no second pool word: the compiler keeps 0x7FFF in r3 for the
 * mask and derives the set bit from it with `adds r2, r3, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020FE4.c \
 *       --func func_02020FE4 --addr 0x02020FE4 --cc 1.1p1 --thumb
 */
u32 func_02020FE4(void *a, u32 sel, u32 id)
{
    void *rec;
    u32   v;

    rec = func_02020F34((u32)a, 0, (u16)((id & 0x7FFF) | 0x8000));
    v = func_02021014(rec, sel);
    func_020307B0(rec);
    return v;
}





/*
 * A whole translation unit range, matched as one byte range.
 *
 * The two halves of one property-getter interface over a packed record: a
 * caller hands in a record pointer and a property id, and gets an unsigned
 * quantity back.  Ids 0..0x11 are answered by func_02021014 out of the record
 * header; anything above that is delegated, for one of the two header layouts,
 * to func_020210C8 on the sub-record at +0x10, which answers ids 0x12..0x3E out
 * of a seventeen-byte bitfield block.
 *
 * The two are one file rather than two because func_02021014's call to
 * func_020210C8 is the only branch to that address anywhere in the image: as
 * separate files neither can attest the other and both cap at MATCH, while in
 * one translation unit the call is `local` and needs no image evidence at all
 * (docs/AGENT-BRIEF.md section 5, the `local` class).
 *
 * Two shape findings, both of which cost real bytes:
 *
 *  - func_02021014's dispatch runs in r2, not in the switch value's own r1
 *    (docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md: the
 *    index register is the switch value's register only when that register is
 *    dead across the arms).  Here it is not dead, and the reason is the
 *    delegation: func_020210C8 takes the property id as its second argument,
 *    which is already sitting in r1, so the call site sets only r0 and r1 stays
 *    live to the end of the function.  Declaring func_020210C8 as a one
 *    argument function is byte for byte right everywhere else and wrong in
 *    those nine bytes.  func_020210C8's own `subs r1, #0x12` is the independent
 *    confirmation that its second parameter is the same id.
 *  - the fall-through of func_02021014 is a two-case `switch` on the header
 *    byte at +0xC, not a chain of `if`s: the switch form emits
 *    cmp/beq, cmp/beq, b-to-default, the `if` chain emits the inverted
 *    bne-over form and is two bytes shorter.
 *
 * The `ldrsb r0, [r0, r1]` arms of func_020210C8 are the signedness evidence
 * for the six plain fields at +7..+0xC and the three at +0xF..+0x11: there is
 * no immediate-offset `ldrsb`, so a signed byte load has to materialise its
 * offset in a register (docs/idioms/ldrsh-register-offset-is-signedness.md).
 * +0xD and +0xE load with a plain `ldrb` and are unsigned, which is why the
 * declared return type has to be signed for the rest to sign-extend.
 *
 * Addresses are Black-image addresses.  The bitfield block's contents are
 * content data, not code shape: if Pokemon White sizes this record
 * differently, the field list here is the thing to re-derive, not the dispatch.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02021014.c \
 *       --addr 0x02021014 --thumb
 */
u32 func_02021014(struct Rec *p, u32 sel)
{
    switch (sel) {
    case 0:
        return p->f00 * 10;
    case 1:
        return p->f02;
    case 2:
        return p->f03;
    case 3:
        return p->b08_5;
    case 4:
        return p->b08_6;
    case 5:
        return p->b08_7;
    case 6:
        return p->f0A;
    case 7:
        return p->f0B;
    case 8:
        return p->f04;
    case 9:
        return p->f05;
    case 10:
        return p->f06;
    case 11:
        return p->f07;
    case 12:
        return p->b08_0;
    case 13:
        return p->b08_11;
    case 14:
        return p->f0C;
    case 15:
        return p->f0D;
    case 16:
        return p->f0E;
    case 17:
        return p->f0F;
    }

    switch (p->f0C) {
    case 0:
        return p->f10;
    case 1:
        return func_020210C8((struct Sub *)&p->f10, sel);
    }
    return 0;
}



int func_020210C8(struct Sub *q, u32 sel)
{
    switch (sel) {
    case 0x12:
        return q->b00_0;
    case 0x13:
        return q->b00_1;
    case 0x14:
        return q->b00_2;
    case 0x15:
        return q->b00_3;
    case 0x16:
        return q->b00_4;
    case 0x17:
        return q->b00_5;
    case 0x18:
        return q->b00_6;
    case 0x19:
        return q->b00_7;
    case 0x1A:
        return q->b01_0;
    case 0x1B:
        return q->b01_1;
    case 0x1C:
        return q->b01_2;
    case 0x1D:
        return q->b01_3;
    case 0x1E:
        return q->b01_4;
    case 0x1F:
        return q->b02_0;
    case 0x20:
        return q->b02_4;
    case 0x21:
        return q->b03_0;
    case 0x22:
        return q->b03_4;
    case 0x23:
        return q->b04_0;
    case 0x24:
        return q->b04_4;
    case 0x25:
        return q->b04_6;
    case 0x26:
        return q->b04_7;
    case 0x27:
        return q->b05_0;
    case 0x28:
        return q->b05_1;
    case 0x29:
        return q->b05_2;
    case 0x2A:
        return q->b05_3;
    case 0x2B:
        return q->b05_4;
    case 0x2C:
        return q->b05_5;
    case 0x2D:
        return q->b05_6;
    case 0x2E:
        return q->b05_7;
    case 0x2F:
        return q->b06_0;
    case 0x30:
        return q->b06_1;
    case 0x31:
        return q->b06_2;
    case 0x32:
        return q->b06_3;
    case 0x33:
        return q->b06_4;
    case 0x34:
        return q->f07;
    case 0x35:
        return q->f08;
    case 0x36:
        return q->f09;
    case 0x37:
        return q->f0A;
    case 0x38:
        return q->f0B;
    case 0x39:
        return q->f0C;
    case 0x3A:
        return q->f0D;
    case 0x3B:
        return q->f0E;
    case 0x3C:
        return q->f0F;
    case 0x3D:
        return q->f10;
    case 0x3E:
        return q->f11;
    }
    return 0;
}




/*
 * The membership test for the two id windows this file's tables are indexed
 * by: 0x148..0x1A9 and 0x26A..0x26C.  Written as one disjunction so that both
 * true arms share the single `movs r0, #1` exit and both false arms the single
 * `movs r0, #0` (docs/idioms/disjunction-must-be-one-expression-to-share-its-
 * exit.md); as two separate `if` statements each window grows its own return.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021288.c \
 *       --func func_02021288 --addr 0x02021288 --cc 1.1p1 --thumb
 */
u32 func_02021288(u32 id)
{
    if ((id >= 0x148 && id <= 0x1A9) || (id >= 0x26A && id <= 0x26C)) {
        return 1;
    }
    return 0;
}





/*
 * Halfword lookup keyed by one of the two id windows func_02021288 accepts:
 * 0x148..0x1A9 maps to entries 0..0x61 of the table at 0x0209EAA0 and
 * 0x26A..0x26C continues at 0x62..0x64, which is why the second window's
 * subtrahend is 0x208 rather than its own start.  Ids outside both windows
 * answer 0.
 *
 * The two subtrahends are one constant: the compiler keeps 0x26A in r0 for the
 * window test and derives 0x208 from it with `subs r0, #0x62` rather than
 * spending a second pool word.
 *
 * The id parameter is `u16` and the subtraction is written back into it, not
 * into a fresh local.  That is what puts the index in r4, the parameter's own
 * callee-saved home, and leaves r0 free for the table base: with a separate
 * `u16 i` local the narrowed index is a dead temporary, lands in r0, and the
 * last three instructions come out in the other order, five bytes wrong.  A
 * `u32` parameter with an explicit `(u16)` cast is the same five bytes wrong,
 * so the `u16` parameter type is real evidence and not a spelling choice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020212B0.c \
 *       --func func_020212B0 --addr 0x020212B0 --cc 1.1p1 --thumb
 */
u16 func_020212B0(u16 id)
{
    if (func_02021288(id) == 0) {
        return 0;
    }
    if (id >= 0x26A) {
        id -= 0x208;
    } else {
        id -= 0x148;
    }
    return g_0209EAA0[id];
}





/*
 * Linear search of the six-entry tail of the same halfword table
 * func_020212B0 indexes, entries 0x5C..0x61.  The 0xB8 byte offset is kept out
 * of the `ldrh` encoding because it is past the halfword load's +62 reach
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md), so the address comes
 * out as base, plus the scaled index, plus a separate `adds r1, #0xb8`.
 *
 * The counter is a `u8`: the increment is `adds`/`lsls #0x18`/`lsrs #0x18`
 * through a scratch register, which a `u32` counter does not produce.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020212E4.c \
 *       --func func_020212E4 --addr 0x020212E4 --cc 1.1p1 --thumb
 */
u32 func_020212E4(u16 v)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        if (v == g_0209EAA0[0x5C + i]) {
            return 1;
        }
    }
    return 0;
}





/*
 * Maps an id in one of func_02021288's two accepted windows onto a byte-wide
 * slot number, in three ranges with three different subtrahends: 0x26A.. off
 * 0x20E, 0x1A4..0x269 off 0x145, and the rest off 0x148.  Ids the window test
 * rejects answer 0xFF.
 *
 * Only two pool words: 0x26A is loaded once and 0x1A4 derived from it with
 * `subs r0, #0xc6`, the same constant-sharing func_020212B0 does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202130C.c \
 *       --func func_0202130C --addr 0x0202130C --cc 1.1p1 --thumb
 */
u32 func_0202130C(u32 id)
{
    if (func_02021288(id) == 0) {
        return 0xFF;
    }
    if (id >= 0x26A) {
        return (u8)(id - 0x20E);
    }
    if (id >= 0x1A4) {
        return (u8)(id - 0x145);
    }
    return (u8)(id - 0x148);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021350.c  *       --func func_02021350 --addr 0x02021350 --cc 1.1p1 --thumb
 */
u8 func_02021350(u16 id)
{
    if (id >= 0x1A4 && id <= 0x1A9) {
        return (u8)(id - 0x1A4);
    }
    return 0xFF;
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202136C.c  *       --func func_0202136C --addr 0x0202136C --cc 1.1p1 --thumb
 */
u32 func_0202136C(u16 v)
{
    u32 i;

    for (i = 0; i < 0xC; i++) {
        if (v == g_0209E8EC[i]) {
            return 1;
        }
    }
    return 0;
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202138C.c  *       --func func_0202138C --addr 0x0202138C --cc 1.1p1 --thumb
 */
u8 func_0202138C(u16 v)
{
    u32 i;

    for (i = 0; i < 0xC; i++) {
        if (v == g_0209E8EC[i]) {
            return (u8)i;
        }
    }
    return 0;
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020213AC.c  *       --func func_020213AC --addr 0x020213AC --cc 1.1p1 --thumb
 */
u16 func_020213AC(u32 i)
{
    if (i >= 0xC) {
        return 0;
    }
    return g_0209E8EC[i];
}
