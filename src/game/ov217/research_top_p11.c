/*
 * file:     research_top_p11.c
 * unit:     yes
 * function: func_021BC644, func_021BC688, func_021BC6D0, func_021BC6DC, func_021BC6E4, func_021BC6EC, func_021BC6F4, func_021BC708, func_021BC714, func_021BC720, func_021BC72C, func_021BC740, func_021BC758, func_021BC774, func_021BC818, func_021BC820, func_021BC8B4, func_021BC8D0, func_021BC8D8, func_021BC8E4, func_021BC910, func_021BC924, func_021BC93C, func_021BC94C, func_021BC954, func_021BC960, func_021BC9FC, func_021BCAC0
 * address:  0x021BC644
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0DF0 0x021C0DF0 thumb ov217
 *   func_021C0DF4 0x021C0DF4 thumb ov217
 *   func_021C0DF8 0x021C0DF8 thumb ov217
 *   func_021BC3B8 0x021BC3B8 thumb ov217
 *   func_021BC3AC 0x021BC3AC thumb ov217
 *   func_021C0E04 0x021C0E04 thumb ov217
 *   func_021C0E00 0x021C0E00 thumb ov217
 *   func_021C0DFC 0x021C0DFC thumb ov217
 *   func_021BC63C  0x021BC63C  thumb  ov217
 *   func_021C09F8  0x021C09F8  thumb  ov217
 *   func_02025774  0x02025774  thumb
 *   d_021C3068  0x021C3068  data  ov217  a4
 *   func_021BCD6C 0x021BCD6C thumb ov217
 *   func_021BCF4C 0x021BCF4C thumb ov217
 *   func_021BCFB4 0x021BCFB4 thumb ov217
 *   func_021BCDDC 0x021BCDDC thumb ov217
 *   func_021BD474 0x021BD474 thumb ov217
 *   func_021BD078 0x021BD078 thumb ov217
 *   func_021BD50C 0x021BD50C thumb ov217
 *   func_021BC628 0x021BC628 thumb ov217
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045B38 0x02045B38 arm
 *   d_021C3078 0x021C3078 data a4
 *   func_02045C04  0x02045C04  arm
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *   d_021C30B2 0x021C30B2 data a1 ov217
 *   d_021C3190 0x021C3190 data a4
 *   d_021C3070 0x021C3070 data a4 ov217
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02045088 0x02045088 arm
 *   d_021C30C0 0x021C30C0 data a4 ov217
 *   d_021C3110 0x021C3110 data a4 ov217
 *   d_021C3130 0x021C3130 data a4 ov217
 *   d_021C30F0 0x021C30F0 data a4 ov217
 *   d_021C3150 0x021C3150 data a4
 *   d_021C3170 0x021C3170 data a4 ov217
 */
#include "../../matched/include/Obj04639.h"
#include "../../matched/include/Obj25871.h"
#include "../../matched/include/Obj25872.h"
#include "../../matched/include/Obj25873.h"
#include "../../matched/include/Obj00850.h"
#include "../../matched/include/Obj00025.h"
#include "../../matched/include/Obj25875.h"
#include "../../matched/include/Obj25876.h"
#include "../../matched/include/Obj25878.h"
#include "../../matched/include/Obj25879.h"
#include "../../matched/include/Obj25880.h"

struct BigObj;
struct GfFont;
struct MsgBank;
struct Rec;
struct DispConfig;
struct BgTemplate;
struct S_021BC644 { char pad0[4]; void *f4; char pad8[0x2a]; unsigned char f32; char pad33; int f34; };

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct S_021BC8E4 { char pad0[8]; u16 h8; char pad[6]; int arr[2]; };

extern u32 func_021C0DF0(void *p);
extern u32 func_021C0DF4(void *p);
extern u32 func_021C0DF8(void *p);
extern void func_021BC3B8(u32 a0);
extern int func_021BC3AC(void);
extern void func_021C0E04(void *, u32);
extern void func_021C0E00(void *, u32);
extern void func_021C0DFC(void *, u8);
extern u32 func_021BC63C(void *p);
extern u32 func_021C09F8(void *p);
extern void func_02025774(u8 *g, u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020056BC(void);
extern void func_021BCD6C(void *);
extern void func_021BCF4C(void *);
extern void func_021BCFB4(void *);
extern void func_021BCDDC(void *);
extern void func_021BD474(void *);
extern void func_021BD078(void *);
extern void func_021BD50C(void *);
extern u32 func_020307B0(void *p);
extern u32 func_021BC628(u8 *a0);
extern u32 func_0201296C(const struct BigObj *);
extern u32 func_020142E8(void *, int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern int func_021C0E08(int a0, int a1);
extern void func_021C0E3C(void *p);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_02045088(u16);
extern u32 func_020403F4();
extern void func_020450C8(void);
void func_021BC644(struct S_021BC644 *p);
void func_021BC688(char *p);
u32 func_021BC6D0(void *p);
u32 func_021BC6DC(void *p);
u32 func_021BC6E4(void *p);
void func_021BC6EC(void *p, u8 v);
u32 func_021BC6F4(u32 a0, u32 a1);
u32 func_021BC708(void *p, u32 i);
u32 func_021BC714(void *p, u32 i);
u32 func_021BC720(void *p, u32 i);
void func_021BC72C(u8 *a0, u32 a1, u8 *a2);
int func_021BC740(char *p, int i);
u32 func_021BC758(u32 a0);
void func_021BC774(u8 *p);
u32 func_021BC818(void *a0);
void func_021BC820(u8 *p);
void func_021BC8B4(u32 a0);
void func_021BC8D0(void *p);
void func_021BC8D8(u8 *a0);
void func_021BC8E4(struct S_021BC8E4 *p);
void func_021BC910(void *p);
void func_021BC924(int *p);
void func_021BC93C(u32 a0);
void func_021BC94C(void *p);
void func_021BC954(u8 *a0);
void func_021BC960(u8 *p);
void func_021BC9FC(char *p);
u32 func_021BCAC0(u8 *a0);
extern int d_021C3068[];
extern const unsigned int d_021C3078[];
extern const u8 d_021C30B2[];
extern const u8 d_021C3190[];
extern const u8 d_021C3070[];
extern struct DispConfig d_021C30C0;
extern const struct BgTemplate d_021C3110, d_021C3130, d_021C30F0, d_021C3150, d_021C3170;


void func_021BC644(struct S_021BC644 *p)
{
    int v;
    if (p->f4 != 0) {
        v = func_021C0DF8(p->f4);
        if (v < -24) {
            v = -24;
        }
        if (v > 72) {
            v = 72;
        }
        func_021BC3B8(v);
        v = func_021C0DF4(p->f4);
        if (v < 0) {
            v = 0;
        }
        if (v > 240) {
            v = 240;
        }
        p->f34 = v;
        p->f32 = func_021C0DF0(p->f4);
    }
}

/*
 * Extent ends in two zero alignment bytes at 021BC6CE.
 * 021BC3AC is void in its source but forwards to 02040804. Original reads
 * r0 as a signed coordinate, so declare int and preserve its visible input.
 */
void func_021BC688(char *p)
{
    int y;
    if (*(u32 *)&((struct Obj04639 *)p)->f4 != 0) {
        y = func_021BC3AC();
        if (y < -24) y = -24;
        if (y > 72) y = 72;
        func_021C0E04(((struct Obj04639 *)p)->f4, y);
        y = ((struct Obj04639 *)p)->f34;
        if (y < 0) y = 0;
        if (y > 240) y = 240;
        func_021C0E00(((struct Obj04639 *)p)->f4, y);
        func_021C0DFC(((struct Obj04639 *)p)->f4, ((struct Obj04639 *)p)->f32);
    }
}

u32 func_021BC6D0(void *p)
{
    return func_021C09F8((void *)func_021BC63C(p));
}


u32 func_021BC6DC(void *p)
{
    return ((struct Obj25871 *)p)->f30;
}


/*
 * Field getter, u8 at +0x31.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC6E4(void *p)
{
    return ((struct Obj25872 *)p)->f31;
}


void func_021BC6EC(void *p, u8 v)
{
    ((struct Obj25873 *)p)->f31 = v;
}

u32 func_021BC6F4(u32 a0, u32 a1)
{
    if (a1 < func_021BC6DC((void *)a0)) {
    return 1;
    }
    return 0;
}


/*
 * Indexed u32 read: element i of the table at +0xf8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC708(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0xf8);
}


/*
 * Indexed u32 read: element i of the table at +0x114.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC714(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x114);
}


u32 func_021BC720(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x120);
}


void func_021BC72C(u8 *a0, u32 a1, u8 *a2)
{
    func_02025774((u8 *)((u32)(*(u32*)(a0 + (a1)*4 + 304))), (u32)(a2 + 0));
}


int func_021BC740(char *p, int i)
{
    return *(int *)(p + (d_021C3068[i] << 2) + 0x130);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC758(u32 a0)
{
    return (u32)func_02030734(a0, 364, 0, (const char *)0x21C3FFC, 3687);
}

/*
 * Extent ends in two zero alignment bytes at 021BC816.
 */
void func_021BC774(u8 *p)
{
    ((struct Obj00850 *)p)->f4 = 0;
    ((struct Obj00850 *)p)->f1C = 0;
    ((struct Obj00850 *)p)->f24 = 0;
    ((struct Obj00850 *)p)->f158 = 0;
    ((struct Obj00850 *)p)->f28 = 15;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x30] = 0;
    ((struct Obj00850 *)p)->f2C = 0;
    p[0x31] = 255;
    ((struct Obj00850 *)p)->f150 = func_020056BC();
    ((struct Obj00850 *)p)->f34 = 0;
    ((struct Obj00850 *)p)->f38 = 0;
    ((struct Obj00850 *)p)->f3C = 0;
    ((struct Obj00850 *)p)->f40 = 0;
    ((struct Obj00850 *)p)->f44 = 0;
    ((struct Obj00850 *)p)->f48 = 0;
    ((struct Obj00850 *)p)->f15C = 0;
    ((struct Obj00850 *)p)->f160 = 0;
    ((struct Obj00850 *)p)->f168 = 0;
    ((struct Obj00850 *)p)->f164 = 0;
    ((struct Obj00850 *)p)->f154 = 0;
    func_021BC94C(p);
    func_021BC910(p);
    func_021BC8D0(p);
    func_021BCD6C(p);
    func_021BCF4C(p);
    func_021BCFB4(p);
    func_021BCDDC(p);
    func_021BD474(p);
    func_021BD078(p);
    func_021BD50C(p);
}


/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC818(void *a0)
{
    return func_020307B0(a0);
}

void func_021BC820(u8 *p)
{
    void *bitmap;
    int n;
    bitmap = (void *)func_0201296C((const struct BigObj *)func_021BC628(p));
    n = 1;
    if (func_020142E8(bitmap, 240) == 1) n++;
    if (func_020142E8(bitmap, 241) == 1) n++;
    if (func_020142E8(bitmap, 242) == 1) n++;
    if (func_020142E8(bitmap, 243) == 1) n++;
    if (func_020142E8(bitmap, 244) == 1) n++;
    if (func_020142E8(bitmap, 245) == 1) n++;
    if (func_020142E8(bitmap, 246) == 1) n++;
    if (func_020142E8(bitmap, 247) == 1) n++;
    if (func_020142E8(bitmap, 248) == 1) n++;
    p[0x30] = n;
}

void func_021BC8B4(u32 a0)
{
    u8 s[4];
    *(u32 *)&((struct Obj00025 *)(((u8*)a0)))->fC = (u32)func_0201D7EC(23, 0, 0, 0, (u32)(((struct Obj00025 *)(((u8*)a0)))->f8));
}


/*
 * Clear the u32 at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC8D0(void *p)
{
    ((struct Obj25875 *)p)->fC = 0;
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 12)) to func_0201D83C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC8D8(u8 *a0)
{
    func_0201D83C((void *)((u32)(((struct Obj25876 *)a0)->fC)));
}


void func_021BC8E4(struct S_021BC8E4 *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p->arr[i] = (int)func_02045B38(0, 2, (u16)d_021C3078[i], p->h8);
    }
}


void func_021BC910(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x10) = 0;
}


void func_021BC924(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_02045C04((struct Rec *)p[i + 4]);
}

void func_021BC93C(u32 a0)
{
    ((struct Obj00025 *)(((u8*)a0 + 0)))->f18 = func_021C0E08(10, ((struct Obj00025 *)(((u8*)a0 + 0)))->f8);
}


/*
 * Clear the u32 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC94C(void *p)
{
    ((struct Obj25878 *)p)->f18 = 0;
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 24)) to func_021C0E3C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC954(u8 *a0)
{
    func_021C0E3C((void *)((u32)(((struct Obj25879 *)a0)->f18)));
}

/*
 * Pool +94 names 021C3190; no cross-overlay loading proof. Drop contested
 * ov217 token to use the sole-ref/data witness without swapping tables.
 */
void func_021BC960(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p[i * 4 + 0x5A] = d_021C30B2[i * 4];
        p[i * 4 + 0x5B] = d_021C30B2[i * 4 + 1];
        p[i * 4 + 0x58] = d_021C30B2[i * 4 + 2];
        p[i * 4 + 0x59] = d_021C30B2[i * 4 + 3];
    }
    for (i = 0; i < 11; i++) {
        p[i * 4 + 0x66] = d_021C3190[i * 4];
        p[i * 4 + 0x67] = d_021C3190[i * 4 + 1];
        p[i * 4 + 0x64] = d_021C3190[i * 4 + 2];
        p[i * 4 + 0x65] = d_021C3190[i * 4 + 3];
    }
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0x92] = d_021C3070[i * 4];
        p[i * 4 + 0x93] = d_021C3070[i * 4 + 1];
        p[i * 4 + 0x90] = d_021C3070[i * 4 + 2];
        p[i * 4 + 0x91] = d_021C3070[i * 4 + 3];
    }
}

void func_021BC9FC(char *p)
{
    func_0203FC28(&d_021C30C0);
    func_0203FCA0(6, &d_021C3110, 0);
    func_0203FCA0(7, &d_021C3130, 0);
    func_0203FCA0(0, &d_021C30F0, 0);
    func_0203FCA0(2, &d_021C3150, 0);
    func_0203FCA0(3, &d_021C3170, 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_02040588(1, 1);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_0207D63C(0x04001050, 2, 1, 16, 5);
    func_0207D63C(0x04000050, 4, 2, 16, 5);
    func_02045088(((struct Obj25880 *)p)->f8);
}

u32 func_021BCAC0(u8 *a0)
{
    func_020450C8();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(0);
    func_020403F4(7);
    return func_020403F4(6);
}
