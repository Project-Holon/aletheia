/*
 * file:     c_gear_p06.c
 * unit:     yes
 * function: func_021F1F24, func_021F1F70, func_021F1F80, func_021F20AC, func_021F2130, func_021F2180, func_021F21B4, func_021F21F8, func_021F2370, func_021F23CC, func_021F24C0, func_021F24FC, func_021F2508
 * address:  0x021F1F24
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02051C6C  0x02051C6C  arm
 *   func_021F1E98  0x021F1E98  thumb  ov029
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02040588  0x02040588  arm
 *   func_0203568C 0x0203568C arm
 *   d_021F3520 0x021F3520 data a1
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204B918  0x0204B918  arm
 *   func_0204B908  0x0204B908  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_021F133C  0x021F133C  thumb  ov029
 *   func_0204B404  0x0204B404  arm
 *   func_0204B800  0x0204B800  arm
 *   func_02051C88  0x02051C88  arm
 *   func_021F2D50  0x021F2D50  thumb  ov029
 *   func_021F2DC8  0x021F2DC8  thumb  ov029
 *   func_021F2DA8  0x021F2DA8  thumb  ov029
 *   func_021F05D0  0x021F05D0  thumb  ov029
 *   func_021F0728  0x021F0728  thumb  ov029
 *   func_021F1CD8  0x021F1CD8  thumb  ov029
 *   func_021F0D48 0x021F0D48 thumb ov029
 *   func_021F1060  0x021F1060  thumb  ov029
 *   func_021F0300  0x021F0300  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F1010  0x021F1010  thumb  ov029
 *   func_021F0370  0x021F0370  thumb  ov029
 *   func_021F1A64  0x021F1A64  thumb  ov029
 *   func_021F1B50  0x021F1B50  thumb  ov029
 *   func_021F1B30  0x021F1B30  thumb  ov029
 *   func_021F1BE4  0x021F1BE4  thumb  ov029
 *   func_021F0F70  0x021F0F70  thumb  ov029
 *   func_021F2BF0  0x021F2BF0  thumb  ov029
 *   func_021F0FF0  0x021F0FF0  thumb  ov029
 *   func_021F1BBC  0x021F1BBC  thumb  ov029
 *   func_021F0E70  0x021F0E70  thumb  ov029
 *   func_021F11B4  0x021F11B4  thumb  ov029
 *   func_021F122C  0x021F122C  thumb  ov029
 *   func_021F1A44  0x021F1A44  thumb  ov029
 *   func_021F0AA0  0x021F0AA0  thumb  ov029
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020072CC  0x020072CC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02009210  0x02009210  thumb
 *   func_0200910C  0x0200910C  thumb
 *   func_0200C6F0  0x0200C6F0  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040AE0  0x02040AE0  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021F3554     0x021F3554  data  a4
 *   func_02030D28  0x02030D28  arm
 *   func_02021D50 0x02021D50 thumb
 */
#include "../../matched/include/Obj07621.h"
#include "../../matched/include/Obj00811.h"
#include "../../matched/include/Obj00042.h"
#include "../../matched/include/Obj00106.h"
#include "../../matched/include/Obj20396.h"
#include "../../matched/include/Obj13047.h"

struct Bank;
struct RtcTime;
struct Obj;
struct Node;
struct Vec2;
struct Ctx;
struct Big;
struct Sub02009210Obj;
struct Ctrl;
struct Sub020090B0Obj;
struct Buf2000;
struct Sub02007324Ctrl;
struct S02021D50;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

typedef signed int     s32;

extern void func_02051C6C(void *p);
extern void func_021F1E98(char *p);
extern void func_0204B084(int);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_020403F4(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_0203568C(void);
extern void func_0203F4CC(struct RtcTime *time);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u16 func_0204B918(struct Obj *p);
extern void func_0204B908(int a0, int a1);
extern int func_02085D3C(void);
extern int func_021F133C(char *p, int v, int *o1, int *o2);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B800(struct Node *node, u32 val);
extern s32 func_02051C88(struct Ctx *c);
extern void func_021F2D50(u8 *p);
extern void func_021F2DC8(char *p);
extern int func_021F2DA8(u8 *p);
extern void func_021F05D0(u8 *p);
extern void func_021F0728(u8 *p);
extern void func_021F1CD8(char *p);
extern int func_021F0D48(char *p);
extern int func_021F1060(u8 *p);
extern void func_021F0300(u8 *p);
extern void func_021EFEF8(char *p, void (*f)(void), int line);
extern void func_021F1010(void *p);
extern void func_021F0370(void *p);
extern void func_021F1A64(char *p, int a);
extern void func_021F1B50(char *p);
extern void func_021F1B30(char *p, int a);
extern int func_021F1BE4(char *p);
extern void func_021F0F70(char *p);
extern int func_021F2BF0(char *p);
extern void func_021F0FF0(char *p);
extern void func_021F1BBC(char *p);
extern void func_021F0E70(char *p);
extern int func_021F11B4(char *p);
extern void func_021F122C(char *p);
extern void func_021F1A44(char *p, int a);
extern void func_021F0AA0(char *p);
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_020072CC(struct Ctrl *sv, u32 id, u8 heap, void *buf, u32 size);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern u16 func_0200910C(const struct Sub020090B0Obj *obj);
extern u32 func_0200C6F0(struct Buf2000 *p);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern u32 func_0204162C(int channel);
extern void func_020409B4(u32 a);
extern void func_0200734C(struct Sub02007324Ctrl *sv, u32 id);
extern u32 func_020307B0(void *p);
extern void func_02030D28(struct Ctx *c);
extern void func_02021D50(struct S02021D50 *p);
void func_021F1F24(char *p);
u8 func_021F1F70(void);
void func_021F1F80(char *p);
void func_021F20AC(char *p);
void func_021F2130(char *p);
void func_021F2180(char *p);
void func_021F21B4(char *p);
void func_021F21F8(char *p);
void func_021F2370(char *p);
int func_021F23CC(u8 *p, int a);
void func_021F24C0(char *p);
void func_021F24FC(unsigned char *p);
void func_021F2508(void *task, char *p);
extern const u8 d_021F3520[];
extern int d_021F3554;


void func_021F1F24(char *p)
{
    if (((struct Obj07621 *)p)->f10)
        func_02051C6C((void *)(((struct Obj07621 *)p)->f10));
    func_021F1E98(p);
    func_0204B084(((struct Obj07621 *)p)->f38);
    func_0204B1CC((struct Bank *)(((struct Obj07621 *)p)->f34));
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
}

u8 func_021F1F70(void)
{
    return d_021F3520[func_0203568C()];
}


static inline void SetFrame(int o, int v)
{
    if (v != func_0204B918((struct Obj *)o)) {
        func_0204B908(o, (u16)v);
    }
}


void func_021F1F80(char *p)
{
    RtcTime t;
    int o;
    int v;

    func_0203F4CC((struct RtcTime *)(&t));
    func_0204B3DC((struct Obj *)((struct Obj00811 *)p)->f12C, 0);

    o = ((struct Obj00811 *)p)->f130;
    v = t.hour / 10;
    SetFrame(o, v);
    if (v == 0) {
        func_0204B3DC((struct Obj *)o, 0);
    } else {
        func_0204B3DC((struct Obj *)o, 1);
    }

    o = ((struct Obj00811 *)p)->f134;
    v = t.hour % 10;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f138;
    v = t.second & 1;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f13C;
    v = t.minute / 10;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f140;
    v = t.minute % 10;
    SetFrame(o, v);

    o = ((struct Obj00811 *)p)->f144;
    if (func_02085D3C()) {
        SetFrame(o, func_021F1F70());
    } else {
        SetFrame(o, func_0203568C() == 5);
    }
}


void func_021F20AC(char *p)
{
    int i;
    int a;
    int b;
    short s[2];

    for (i = 0; i < 3; i++) {
        if (func_021F133C(p, i + 1, &a, &b)) {
            a = a * 8;
            b = b * 8;
            s[0] = a + 0x10;
            s[1] = b + 0xf;
            func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x158)), (const struct Vec2 *)s, 0);
            a += 0x20;
            func_0204B800((struct Node *)(*(int *)(p + i * 4 + 0x158)), (a / 8) & 0xff);
        } else {
            s[0] = -0x40;
            s[1] = 0;
            func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x158)), (const struct Vec2 *)s, 0);
        }
    }
}


void func_021F2130(char *p)
{
    func_02051C88((struct Ctx *)(((struct Obj00042 *)p)->f10));
    func_021F2D50((u8 *)p);
    func_021F2DC8(p);
    func_021F1F80(p);
    if (func_021F2DA8((u8 *)p) == 0) {
        if (((struct Obj00042 *)p)->f45A) {
            func_021F05D0((u8 *)p);
            func_021F0728((u8 *)p);
            func_021F1CD8(p);
        }
    } else {
        ((struct Obj00042 *)p)->f214 = 0;
    }
}

void func_021F2180(char *p)
{
    if (*(void (**)(void *))(p + 0x1fc) != 0)
        (*(void (**)(void *))(p + 0x1fc))(((struct Obj00042 *)p)->f200);
    *(void (**)(void *))(p + 0x1fc) = 0;
    ((struct Obj00042 *)p)->f200 = 0;
    if (func_021F0D48(p))
        func_021F2130(p);
}


void func_021F21B4(char *p)
{
    void (*f)(int);

    if (func_021F1060((u8 *)p) == 0) {
        f = *(void (**)(int))(p + 0x1fc);
        if (f)
            f(*(int *)&((struct Obj00042 *)p)->f200);
        *(int *)&((struct Obj00042 *)p)->f1FC = 0;
        *(int *)&((struct Obj00042 *)p)->f200 = 0;
        return;
    }
    func_021F0300((u8 *)p);
    func_021EFEF8(p, (void *)func_021F2180, 0xF92);
}


void func_021F21F8(char *p)
{
    switch (((struct Obj00106 *)p)->f455) {
    case 0:
        func_021F1010(p);
        func_021F0370(p);
        func_021F1A64(p, 0);
        (((struct Obj00106 *)p)->f455)++;
        return;
    case 1:
        if (func_021F0D48(p)) {
            func_021F1B50(p);
            func_021F1B30(p, 1);
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 2:
        if (func_021F1BE4(p)) {
            func_021F0F70(p);
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 3:
        if (func_021F2BF0(p)) {
            func_021F0FF0(p);
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        if (((struct Obj00106 *)p)->f456 < 8) {
            (((struct Obj00106 *)p)->f456)++;
            return;
        }
        func_021F1B30(p, 0);
        func_021F1BBC(p);
        func_021F0E70(p);
        (((struct Obj00106 *)p)->f455)++;
        ((struct Obj00106 *)p)->f456 = 0;
        return;
    case 4:
        if (func_021F2BF0(p)) {
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        if (func_021F11B4(p) == 1) {
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 5:
        if (func_021F2BF0(p)) {
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        (((struct Obj00106 *)p)->f456)++;
        if (((struct Obj00106 *)p)->f456 >= 8) {
            func_021F122C(p);
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 6:
        (((struct Obj00106 *)p)->f456)++;
        if (((struct Obj00106 *)p)->f456 >= 8) {
            func_021F1A64(p, 1);
            func_021F1A44(p, 0);
            func_021EFEF8(p, (void (*)(void))func_021F21B4, 0x100b);
            return;
        }
        break;
    case 7:
        func_021F1BBC(p);
        func_021F0E70(p);
        func_021F0AA0(p);
        func_021F122C(p);
        ((struct Obj00106 *)p)->f456 = 8;
        ((struct Obj00106 *)p)->f455 = 6;
        break;
    }
}


void func_021F2370(char *p)
{
    if (((struct Obj00106 *)p)->f456 == 0) {
        func_021F0E70(p);
        func_021F1A64(p, 1);
        func_021F1A44(p, 0);
        func_021F1BBC(p);
        func_021F1010(p);
        func_021F0370(p);
    }
    ((struct Obj00106 *)p)->f456 += 1;
    if (((struct Obj00106 *)p)->f456 >= 0x10) {
        ((struct Obj00106 *)p)->f456 = 0;
        func_021EFEF8(p, (void (*)(void))func_021F21B4, 0x1041);
    }
}


/*
 * base is a u32 holding (u16)p->f14 and re-cast (u16) in the palette add:
 * that is the second lsls/lsrs pair.  The 0x0200910C result goes to a
 * local before base is loaded (the load sits between the call and cmp);
 * declaring i before buf gives i r4 and buf r5.
 */
int func_021F23CC(u8 *p, int a)
{
    int result;
    u32 h;
    u16 crc;
    u32 base;
    u16 x;
    int i;
    u8 *buf;
    u16 *pal;

    result = 0;
    buf = func_02030734(0x70, 0x3000, 0, (const char *)&d_021F3554, 0x104E);
    h = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
    if (func_020072CC((struct Ctrl *)h, 4, 0x70, buf, 0x3000) == 1) {
        crc = func_0203F1FC(buf, 0x2600);
        x = func_0200910C((const struct Sub020090B0Obj *)func_02009210((void *)h));
        base = (u16)((struct Obj20396 *)p)->f14;
        if (crc == x && func_0200C6F0((struct Buf2000 *)buf) != 0) {
            result = 1;
            for (i = 0; i < 15; i++) {
                func_02040B1C(6, buf + i * 0x220, 0x220, base + (i + 5) * 0x20);
            }
            func_02040E78(6, buf + 0x1FE0, 0x20, 0x140);
            func_02040AE0(5, buf + 0x2000, 0x600);
            pal = (u16 *)func_0204162C(5);
            for (i = 0; i < 0x600 / 2; i++) {
                pal[i] += (u16)base;
            }
            func_020409B4(5);
        }
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 4);
    func_020307B0(buf);
    return result;
}


void func_021F24C0(char *p)
{
    func_021F0FF0(p);
    if (*(int *)&((struct Obj00106 *)p)->f204 != 0)
        func_02030D28((struct Ctx *)(*(int *)&((struct Obj00106 *)p)->f204));
    func_021F0E70(p);
    func_021F1010(p);
    if (*(int *)&((struct Obj00106 *)p)->f204 != 0)
        func_02030D28((struct Ctx *)(*(int *)&((struct Obj00106 *)p)->f204));
    ((struct Obj00106 *)p)->f451 = 1;
}

void func_021F24FC(unsigned char *p)
{
    p[0x451] = 2;
}

void func_021F2508(void *task, char *p)
{
    if (((struct Obj13047 *)p)->f210 != 0)
        func_02021D50(((struct Obj13047 *)p)->f210);
}
