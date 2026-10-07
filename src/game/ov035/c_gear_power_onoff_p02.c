/*
 * file:     c_gear_power_onoff_p02.c
 * unit:     yes
 * function: func_021F000C, func_021F0100, func_021F0140, func_021F015C, func_021F0168
 * address:  0x021F000C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   d_021F05B0    0x021F05B0 data a4
 *   d_021F05BC    0x021F05BC data ov035 a4
 *   d_021F05C8    0x021F05C8 data ov035 a4
 *   d_021F05E8    0x021F05E8 data ov035 a4
 *   d_021F0608    0x021F0608 data ov035 a4
 *   func_0203FB44 0x0203FB44 arm
 *   sub_020403F4  0x020403F4 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045790 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 */
#include "../../matched/include/Obj13078.h"
#include "../../matched/include/Obj20480.h"
#include "../../matched/include/Obj04315.h"
#include "../../matched/include/Obj20481.h"

struct BgTemplate;
struct Ctx;
struct Sub0200852CObj;
struct R;
struct TaskMenuState;
struct CharBuf;
struct Descriptor;
struct Cfg;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 layer);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(void *h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
    u32 heap);
extern void func_02049238(void *h);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void sub_020403F4(u32 i);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02049B40(int, int, int, int, int, int);
extern void *func_0201F5DC(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045790(struct Descriptor *p, u8 v);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern int func_0203101C(int, int, int, int);
extern int func_02028590(int, int, int, int);
void func_021F000C(char *p, u32 heap);
void func_021F0100(char *p);
void func_021F0140(char *p, u16 heap);
void func_021F015C(char *p);
void func_021F0168(int *p, int a1);
extern const u32 d_021F05B0[];
extern const u32 d_021F05BC[];
extern const u8 d_021F05C8[];
extern const u8 d_021F05E8[];
extern const u8 d_021F0608[];


void func_021F000C(char *p, u32 heap)
{
    int i;
    void *h;
    u32 r;

    for (i = 4; i <= 7; i++)
        func_02040588((u8)i, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F0608, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588((u8)6, 1);
    func_0203FCA0(5, (const struct BgTemplate *)d_021F05C8, 0);
    func_020414EC(5);
    func_020409B4(5);
    func_02040588((u8)5, 1);
    func_0203FCA0(4, (const struct BgTemplate *)d_021F05E8, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02040588((u8)4, 1);
    h = func_020490F4(0x1E, heap);
    i = func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4(((struct Obj13078 *)p)->f4)));
    func_02049B68(h, d_021F05BC[i], 4, 0, 1, heap);
    r = func_02049740(h, d_021F05B0[i], 6, 0, 0, heap);
    ((struct Obj13078 *)p)->f10 = r;
    func_02049990(h, 3, 6, 0, (u16)r, 0, 0, heap);
    func_02049238(h);
}


void func_021F0100(char *p)
{
    unsigned int v = ((struct Obj20480 *)p)->f10;
    func_0203FB44(6, (unsigned short)v, (unsigned short)(v >> 16));
    sub_020403F4(6);
    sub_020403F4(5);
    sub_020403F4(4);
    func_02040588(6, 0);
    func_02040588(5, 0);
    func_02040588(4, 0);
}

void func_021F0140(char *p, u16 heap)
{
    ((struct Obj04315 *)p)->f40 = func_02027F60(4, 3, ((struct Obj04315 *)p)->f34, ((struct Obj04315 *)p)->f3C, heap);
}


void func_021F015C(char *p)
{
    func_02027FD8((struct TaskMenuState *)(((struct Obj20481 *)p)->f40));
}


void func_021F0168(int *p, int a1)
{
    func_02049B40(0x17, 5, 4, 0x20, 0x20, a1);
    p[5] = (int)func_0201F5DC((void *)5, 2, 0, a1);
    p[6] = func_020450F0(5, 1, 1, 0x1E, 6, 1, 1);
    p[7] = func_020450F0(5, 1, 0xD, 0x1E, 0xA, 1, 1);
    func_02045790((struct Descriptor *)p[6], 4);
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)p[6]), 0xF);
    func_02045334((struct Descriptor *)p[6]);
    func_02045374((struct Cfg *)p[6]);
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)p[7]), 0xF);
    func_02045334((struct Descriptor *)p[7]);
    func_02045374((struct Cfg *)p[7]);
    p[8] = func_0203101C(a1, a1, 1, 4);
    p[0xC] = func_02028590(0xF, 0, 1, a1);
}
