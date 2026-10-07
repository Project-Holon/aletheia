/*
 * file:     unit_021B95A0_p03.c
 * unit:     yes
 * function: func_021B9BD0, func_021B9BFC, func_021B9C04, func_021B9D58, func_021B9D60, func_021B9D68, func_021B9E28, func_021B9F70, func_021B9FC0, func_021BA010
 * address:  0x021B9BD0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045808  0x02045808  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02045738  0x02045738  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   d_021BB820     0x021BB820  data  ov068  a4
 *   func_020419E4  0x020419E4  arm
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02061CA4  0x02061CA4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BB704     0x021BB704  data  ov068  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204B908  0x0204B908  arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204A648 0x0204A648 arm
 */
#include "../../matched/include/Obj13138.h"
#include "../../matched/include/Obj20637.h"
#include "../../matched/include/Obj09869.h"

struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct StrObj;
struct U16Vec;
struct Bank;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef struct {
    u32 msg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Ent_021B9C04;

typedef signed int     s32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Ent_021B9E28;

extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 a);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(u32 a, u32 b, u32 n);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_02082BCC(void *p, int c, u32 n);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 a, u32 b);
extern void func_02043598(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204ABF0(void *, int, int, int, int);
extern int func_0204A6C8(void *, int, int, int, int);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern int func_0204B294(int, int, int, int, Local *, int, int);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_0203CD98(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 a);
extern void func_0204A8D4(u32 a);
extern void func_0204AFD8(u32 a);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204B908(int a0, int a1);
extern void func_0204A600(void);
extern void func_0204A648(void);
void func_021B9BD0(u8 *p);
int func_021B9BFC(int *p, int i);
void func_021B9C04(u32 *p);
void func_021B9D58(char *p);
void func_021B9D60(char *a0);
void func_021B9D68(u16 *out, u16 *ang, int inc, u32 idx, u8 slot, u16 c0, u16 c1);
void func_021B9E28(int *p, void *res, u32 heap);
void func_021B9F70(u32 *p);
void func_021B9FC0(u8 *p);
void func_021BA010(char *a0);
extern Ent_021B9C04 d_021BB820[];
extern s16  d_020A1B38[];
extern char d_020A1448[];
extern Ent_021B9E28 d_021BB704[];

void func_021B9BD0(u8 *p)
{
    func_021B9D68((u16 *)(p + 0x50), (u16 *)(p + 0x4c), 0x400, 7, 1,
                 ((struct Obj13138 *)p)->f72, ((struct Obj13138 *)p)->f74);
}

int func_021B9BFC(int *p, int i)
{
    return p[i];
}


/*
 * The rounded width goes through a u8 local that is both stored to the
 * table row and passed on (the call reloading the field is 4 bytes longer).
 * func_0201D304 takes the string first and the font second.
 */
void func_021B9C04(u32 *p)
{
    u32 font;
    u32 msg;
    u32 str;
    u32 w;
    int i;
    int x;
    Ent_021B9C04 *e;
    u8 wv;

    font = (u32)func_0201D7EC(0x17, 0, 0, 0, 0x1c);
    msg = (u32)func_02045B38(0, 2, 0x1d, 0x1c);
    for (i = 0; i < 16; i++) {
        x = 0;
        switch (i) {
        case 0:
            x = 7;
            break;
        case 1:
            x = 4;
            break;
        case 2:
            x = 2;
            break;
        }
        e = &d_021BB820[i];
        str = (u32)func_02045EC0((struct MsgBank *)msg, d_021BB820[i].msg);
        wv = (x + func_0201D304((struct StrObj *)str, font, 0) + 7) >> 3;
        e->w = wv;
        p[i] = func_020450F0(1, e->x, e->y, wv, e->h, 0, 1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[i])), 0);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)p[i])), x, 0, (void *)str, (void *)font);
        w = p[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_02045808((struct U16Vec *)str);
    }
    w = *(u32 *)(p[22] + 0x14);
    func_02082A90(w, (u32)func_020437D4((const struct Bmp *)((u32)func_02045770((struct Descriptor *)p[16]))), 0x600);
    str = (u32)func_02045EC0((struct MsgBank *)msg, 0);
    x = func_02045738((struct Descriptor *)p[16]) * 4;
    x -= func_0201D304((struct StrObj *)str, font, 0) >> 1;
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)p[16])), x, 4, (void *)str, (void *)font, 0x3dc1);
    w = p[16];
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(func_02045730((struct Descriptor *)w));
    func_02045808((struct U16Vec *)str);
    func_02045C04((struct Rec *)msg);
    func_0201D83C((void *)font);
}


void func_021B9D58(char *p)
{
    ((struct Obj20637 *)p)->f4C = 0;
}

void func_021B9D60(char *a0)
{
    void func_020419E4(void);
    func_020419E4();
}


/*
 * BGR555 cross-fade of one palette entry: advance the u16 phase at *ang by
 * inc (wrapping at 0x10000), take f = (table[phase >> 4 pair, second entry]
 * + 0x1000) / 2 as an s16 from the table at 0x020A1B38, blend each channel
 * of c0 toward c1 by f >> 12, store to *out and hand it to func_02061CA4.
 * Twin: arm9 func_0202EA40 (blink_palanm.c).  What closed it: all six
 * channels as u8 locals extracted in mask-then-shift form, the blended
 * channels as s32 with a u8 cast, and the pack `(b << 10) | (r | (g << 5))`
 * (the channel ORed last is evaluated first: blue, red, green).  Shift-then-
 * mask extraction, or the unnested pack, compiles 184 bytes.
 */
void func_021B9D68(u16 *out, u16 *ang, int inc, u32 idx, u8 slot, u16 c0, u16 c1)
{
    int t;
    s16 f;
    u8 r0, g0, b0, r1, g1, b1;
    s32 r, g, b;

    t = *ang + inc;
    if (t >= 0x10000) {
        *ang = t - 0x10000;
    } else {
        *ang = t;
    }
    f = (d_020A1B38[((*ang >> 4) << 1) + 1] + 0x1000) / 2;
    r0 = c0 & 0x1f;
    g0 = (c0 & 0x3e0) >> 5;
    b0 = (c0 & 0x7c00) >> 10;
    r1 = c1 & 0x1f;
    g1 = (c1 & 0x3e0) >> 5;
    b1 = (c1 & 0x7c00) >> 10;
    b = (u8)(b0 + (((b1 - b0) * f) >> 12));
    r = (u8)(r0 + (((r1 - r0) * f) >> 12));
    g = (u8)(g0 + (((g1 - g0) * f) >> 12));
    *out = (u16)((b << 10) | (r | (g << 5)));
    func_02061CA4((void *)15, idx * 32 + slot * 2, (u32)out, 2);
}


void func_021B9E28(int *p, void *res, u32 heap)
{
    Local s;
    void *h;
    int i;

    func_02082BCC(p, 0, 0x54);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)res, heap);
    p[0] = (int)func_0204B100(0x80, 0, heap);
    func_0204B270((struct Bank *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    h = func_020490F4(0x1b, heap);
    p[1] = func_0204ABF0(h, 6, 0, 0, heap);
    p[2] = func_0204A6C8(h, 5, 0, 0, heap);
    p[3] = func_0204AF28(h, 4, 3, heap);
    p[4] = func_0204A6C8(h, 0xc, 0, 0, heap);
    p[5] = func_0204AF28(h, 0xb, 0xa, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    s.e = 2;
    s.d = 2;
    for (i = 2; i < 13; i++) {
        s.a = d_021BB704[i - 2].f8;
        s.b = d_021BB704[i - 2].fC;
        p[6 + i] = func_0204B294(p[0], p[2], p[1], p[3], &s, 0, heap);
        func_0204B92C((struct Obj *)p[6 + i], 0);
    }
    func_02082BCC(&s, 0, 8);
    s.a = 0x80;
    s.b = 0x60;
    s.e = 2;
    s.d = 1;
    p[7] = func_0204B294(p[0], p[4], p[1], p[5], &s, 0, heap);
    func_0204B6F4((struct Obj *)p[7], 6, 1);
    if (func_0203CD98())
        func_0203D34C(1, heap);
}


void func_021B9F70(u32 *p)
{
    int i;

    for (i = 0; i < 14; i++) {
        if (p[i + 6] != 0) {
            func_0204B3B4((struct Obj *)p[i + 6]);
        }
    }
    func_0204ADA4(p[1]);
    func_0204A8D4(p[2]);
    func_0204AFD8(p[3]);
    func_0204A8D4(p[4]);
    func_0204AFD8(p[5]);
    func_0204B1CC((struct Bank *)p[0]);
    func_0204A5AC();
    func_02082BCC(p, 0, 0x54);
}


void func_021B9FC0(u8 *p)
{
    int i;
    u16 t;

    t = (((struct Obj09869 *)p)->f50)++;
    if (t > 0x60) {
        ((struct Obj09869 *)p)->f50 = 0;
    }
    for (i = 2; i < 13; i++) {
        func_0204B908(*(u32 *)(p + i * 4 + 0x18), (u16)(((struct Obj09869 *)p)->f50 / 12));
    }
    func_0204A600();
}

void func_021BA010(char *a0) { func_0204A648(); }
