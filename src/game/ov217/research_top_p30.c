/*
 * file:     research_top_p30.c
 * unit:     yes
 * function: func_021BF6D4, func_021BF704, func_021BF710, func_021BF728, func_021BF734, func_021BF740, func_021BF74C, func_021BF750, func_021BF754, func_021BF758, func_021BF764, func_021BF76C, func_021BF77C, func_021BF78C, func_021BF7CC, func_021BF7E0, func_021BF7F4, func_021BF810, func_021BF834, func_021BF844, func_021BF854, func_021BF878, func_021BF894, func_021BF8B0, func_021BF910, func_021BF968, func_021BF9CC, func_021BF9F0, func_021BF9FC, func_021BFA08, func_021BFA14, func_021BFA30, func_021BFB04, func_021BFB0C, func_021BFB14, func_021BFB24, func_021BFB30, func_021BFB38, func_021BFB54, func_021BFB60, func_021BFB74, func_021BFBA0, func_021BFBB8, func_021BFBC0, func_021BFBD0, func_021BFBDC, func_021BFBFC, func_021BFC28, func_021BFC50, func_021BFC60, func_021BFE40, func_021BFE80, func_021BFE8C, func_021BFED4, func_021BFEE4, func_021BFF00, func_021BFF5C, func_021BFF78
 * address:  0x021BF6D4
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
 *   func_020270E0 0x020270E0 thumb
 *   func_021C09B0  0x021C09B0  thumb  ov217
 *   func_021C09B4  0x021C09B4  thumb  ov217
 *   func_021C09F8  0x021C09F8  thumb  ov217
 *   func_021C11F4  0x021C11F4  thumb  ov217
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E44C 0x0200E44C thumb
 *   d_021C363C 0x021C363C data ov217 a1
 *   d_021C3646 0x021C3646 data ov217 a1
 *   d_021C3632 0x021C3632 data ov217 a1
 *   func_0200E3A0 0x0200E3A0 thumb
 *   func_0200E3A4 0x0200E3A4 thumb
 *   func_021C2644 0x021C2644 thumb ov217
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_0200E458  0x0200E458  thumb
 *   func_020056BC 0x020056BC thumb
 *   func_021C019C 0x021C019C thumb ov217
 *   func_021C0384 0x021C0384 thumb ov217
 *   func_021C03EC 0x021C03EC thumb ov217
 *   func_021C04B0 0x021C04B0 thumb ov217
 *   func_021C07B0 0x021C07B0 thumb ov217
 *   func_021C0820 0x021C0820 thumb ov217
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045B38 0x02045B38 arm
 *   d_021C3650 0x021C3650 data a4
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021C10C8 0x021C10C8 thumb ov217
 *   func_021C10D8 0x021C10D8 thumb ov217
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200E4B0 0x0200E4B0 thumb
 *   func_0200E4F8 0x0200E4F8 thumb
 *   d_021C367C 0x021C367C data a1
 *   d_021C3D44 0x021C3D44 data a1
 *   d_021C386C 0x021C386C data a1
 *   d_021C3900 0x021C3900 data a1
 *   d_021C3994 0x021C3994 data a1
 *   d_021C3758 0x021C3758 data a1
 *   func_021C2070 0x021C2070 thumb ov217
 *   func_021C209C  0x021C209C  thumb  ov217
 *   func_021C26E8 0x021C26E8 thumb ov217
 *   func_021C2740 0x021C2740 thumb ov217
 *   func_021C270C  0x021C270C  thumb  ov217
 *   func_0207D988 0x0207D988 arm
 *   func_0207DB1C 0x0207DB1C arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   d_021C365C 0x021C365C data a4
 */
#include "../../matched/include/Obj25931.h"
#include "../../matched/include/Obj25932.h"
#include "../../matched/include/Obj00021.h"
#include "../../matched/include/Obj25933.h"
#include "../../matched/include/Obj25934.h"
#include "../../matched/include/Obj25935.h"
#include "../../matched/include/Obj25936.h"
#include "../../matched/include/Obj25937.h"
#include "../../matched/include/Obj25938.h"
#include "../../matched/include/Obj25939.h"
#include "../../matched/include/Obj25940.h"
#include "../../matched/include/Obj08436.h"
#include "../../matched/include/Obj25941.h"
#include "../../matched/include/Obj25942.h"
#include "../../matched/include/Obj25943.h"
#include "../../matched/include/Obj25944.h"
#include "../../matched/include/Obj25945.h"
#include "../../matched/include/Obj25946.h"
#include "../../matched/include/Obj00926.h"
#include "../../matched/include/Obj25948.h"
#include "../../matched/include/Obj14742.h"
#include "../../matched/include/Obj25949.h"
#include "../../matched/include/Obj25950.h"
#include "../../matched/include/Obj14743.h"
#include "../../matched/include/Obj25951.h"
#include "../../matched/include/Obj25953.h"
#include "../../matched/include/Obj14745.h"
#include "../../matched/include/Obj25954.h"
#include "../../matched/include/Obj14746.h"
#include "../../matched/include/G_Bg.h"
#include "../../matched/include/Obj25955.h"
#include "../../matched/include/Obj14747.h"
#include "../../matched/include/Obj25956.h"
#include "../../matched/include/Obj25957.h"

struct Big;
struct PlayTime;
struct GfFont;
struct MsgBank;
struct Rec;
struct WordSet;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

typedef struct W { u32 w0; u16 h; u16 pad; u32 w8; u32 obj[3]; } W;

struct Entry { u8 a, b, c, d; };

struct Params_021BFE8C { u32 handles[3]; u16 a, b, c, d, e; };

struct Params_021BFF00 { u32 handles[3]; u16 a, b, c; };

extern u8 func_020270E0(void);
extern u32 func_021C09B0(u32 *p);
extern u32 func_021C09B4(void *p);
extern u32 func_021C09F8(void *);
extern int func_021C11F4(u8 *p);
extern void *func_02012EBC(struct Big *);
extern void *func_0200E394(void *a0);
extern int func_0200E44C(int,int);
extern void *func_0200E3A0(void *a);
extern u32 func_0200E3A4(const u8 *, int);
extern u32 func_021C2644(void *, u32, u8);
extern int func_02012FCC(int);
extern u16 func_0200864C(const struct PlayTime *p);
extern u16 func_0200E458(const u16 *, int);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020056BC(void);
extern void func_021C019C(void *p);
extern void func_021C0384(void *p);
extern void func_021C03EC(void *p);
extern void func_021C04B0(void *p);
extern void func_021C07B0(void *p);
extern void func_021C0820(void *p);
extern u32 func_020307B0(void *p);
extern int func_021C0E08(int a0, int a1);
extern void func_021C0E3C(void *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_021C10C8(u32 a0);
extern u32 func_021C10D8(void *a0);
extern void func_02082BCC(u32, u32, u32);
extern u32 func_0200E47C(u8 *p, int i);
extern u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);
extern int func_0200E4F8(int a0, int a1, int a2);
extern u32 func_021C2070(u32, u32);
extern u32 func_021C209C(void *a0);
extern u32 func_021C26E8(u32, u32, u32);
extern void func_021C2740(u32, u32);
extern u32 func_021C270C(void *a0);
extern void func_0207D988(void);
extern void func_0207DB1C(void);
extern void func_0207DCF8(const void *);
void func_021BF6D4(char *p);
void func_021BF704(void *p);
void func_021BF710(void *p);
void func_021BF728(void *p);
u32 func_021BF734(u8 *a0);
u32 func_021BF740(u8 *a0);
void func_021BF74C(void *p, u16 v);
u32 func_021BF750(void *p);
void func_021BF754(void *p, u32 v);
u32 func_021BF758(void *p);
void func_021BF764(void *p, u32 v);
u8 *func_021BF76C(void *p);
u8 *func_021BF77C(void *p);
u32 func_021BF78C(u32 a0);
u32 func_021BF7CC(void *p);
u32 func_021BF7E0(void *p);
u32 func_021BF7F4(void *p);
u32 func_021BF810(void *p);
u32 func_021BF834(void *p);
u32 func_021BF844(void *p);
u32 func_021BF854(char *p);
u32 func_021BF878(void *p);
u32 func_021BF894(void *p);
u8 func_021BF8B0(u8 *p);
u32 func_021BF910(u8 *p);
u32 func_021BF968(u8 *p);
u16 func_021BF9CC(u32 a0);
u32 func_021BF9F0(void *p, u32 i);
u32 func_021BF9FC(void *p, u32 i);
u32 func_021BFA08(void *p, u32 i);
u32 func_021BFA14(u32 a0);
void func_021BFA30(char *p);
u32 func_021BFB04(void *a0);
void func_021BFB0C(void *p);
void func_021BFB14(u32 a0);
void func_021BFB24(u8 *a0);
void func_021BFB30(void *p);
void func_021BFB38(u32 a0);
void func_021BFB54(u8 *a0);
void func_021BFB60(void *p);
void func_021BFB74(W *p);
void func_021BFBA0(int *p);
void func_021BFBB8(void *p);
void func_021BFBC0(u32 a0);
void func_021BFBD0(u8 *a0);
void func_021BFBDC(void *p);
void func_021BFBFC(char *p);
void func_021BFC28(char *p);
void func_021BFC50(u8 *a0);
void func_021BFC60(char *p);
void func_021BFE40(u8 *p);
void func_021BFE80(void *p);
void func_021BFE8C(char *p);
void func_021BFED4(u8 *a0);
void func_021BFEE4(void *p);
void func_021BFF00(char *p);
void func_021BFF5C(int *p);
void func_021BFF78(void);
extern const u8 d_021C363C[];
extern const u8 d_021C3646[];
extern const u8 d_021C3632[];
extern u32 d_021C3650[];
extern u8 d_021C367C[];
extern u8 d_021C3D44[][17];
extern struct Bg d_021C386C;
extern u8 d_021C3900[];
extern u8 d_021C3994[];
extern const struct Entry d_021C3758[];
extern const u16 d_021C365C[];

void func_021BF6D4(char *p)
{
    if (func_020270E0() == 1) {
        u16 a = func_021BF834(p);
        if (a != (u16)(u32)func_021BF9CC((u32)p)) {
            ((struct Obj25931 *)p)->f3D8 = 1;
        }
    }
}


/*
 * Clear the u32 at +0x3d8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF704(void *p)
{
    ((struct Obj25932 *)p)->f3D8 = 0;
}


void func_021BF710(void *p)
{
    if (((struct Obj00021 *)p)->f30 < 0xf0) {
        ((struct Obj00021 *)p)->f30 += 1;
    } else {
        ((struct Obj00021 *)p)->f3D4 = 1;
    }
}


void func_021BF728(void *p)
{
    ((struct Obj00021 *)p)->f30 = 0;
    ((struct Obj00021 *)p)->f3D4 = 0;
}


u32 func_021BF734(u8 *a0)
{
    return func_021C09B0((u32 *)(((struct Obj25933 *)a0)->f0));
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09B4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF740(u8 *a0)
{
    return func_021C09B4((void *)(((struct Obj25934 *)a0)->f0));
}


/*
 * Field setter, u16 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF74C(void *p, u16 v)
{
    ((struct Obj25935 *)p)->f4 = v;
}


/*
 * Field getter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF750(void *p)
{
    return ((struct Obj25936 *)p)->f0;
}


/*
 * Field setter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF754(void *p, u32 v)
{
    ((struct Obj25937 *)p)->f0 = v;
}

u32 func_021BF758(void *p)
{
    return func_021C09F8((void *)func_021BF750(p));
}


/*
 * Field setter, u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF764(void *p, u32 v)
{
    ((struct Obj25938 *)p)->f2CC = v;
}


u8 *func_021BF76C(void *p)
{
    u32 i = ((struct Obj25939 *)p)->f2CC;
    return *(u8 **)((char *)p + i * 4 + 0x2bc);

}


u8 *func_021BF77C(void *p)
{
    u32 i = ((struct Obj25940 *)p)->f2CC;
    return *(u8 **)((char *)p + i * 4 + 0x2c4);

}

u32 func_021BF78C(u32 a0)
{
    if (func_021C11F4(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2BC) != 0 || func_021C11F4(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2C0) != 0 || func_021C11F4(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2C4) != 0 || func_021C11F4(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2C8) != 0) {
    return 0;
    }
    return 1;
}


u32 func_021BF7CC(void *p)
{
    u32 i = ((struct Obj25941 *)p)->f2B8;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3c);
}


u32 func_021BF7E0(void *p)
{
    u32 i = ((struct Obj25942 *)p)->f2B8;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3d);
}


/*
 * Element field: u16 at +0x44 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF7F4(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x44 + i * 0xd4 + j * 0xc);
}

u32 func_021BF810(void *p)
{
    u32 r = 0;
    switch (((struct Obj25943 *)p)->f2CC) {
    case 0:
        r = func_021BF834(p);
        break;
    case 1:
        r = func_021BF844(p);
        break;
    }
    return r;
}


/*
 * Element field: u16 at +0x3e of record 0xd4 bytes, selected by the u8 at +0x2b8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF834(void *p)
{
    u32 i = ((struct Obj25944 *)p)->f2B8;
    return *(u16 *)((char *)p + i * 0xd4 + 0x3e);
}


u32 func_021BF844(void *p)
{
    u32 i = ((struct Obj25945 *)p)->f2B8;
    return *(u32 *)((char *)p + i * 0xd4 + 0x40);
}

/*
 * Addresses are Black-image addresses.
 */
u32 func_021BF854(char *p)
{
    switch (((struct Obj25946 *)p)->f2CC) {
    case 0:
        return func_021BF878(p);
    case 1:
        return func_021BF894(p);
    }
    return 0;
}


/*
 * Element field: u16 at +0x4a of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF878(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x4a + i * 0xd4 + j * 0xc);
}


/*
 * Element field: u32 at +0x4c of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF894(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u32 *)((char *)p + 0x4c + i * 0xd4 + j * 0xc);
}

/*
 * lever: pointer-typed lookup base keeps the original r4/r5 allocation; E44C full body reads only r0/r1 and forwards neither legacy trailing input.
 * F740 tail-forwards to C09B4's pointer getter; E394 tail-forwards to 071CC's returned save block.
 * E44C's full body reads only r0/r1 and has no forwarding calls; legacy two trailing inputs omitted.
 */
u8 func_021BF8B0(u8 *p)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=func_0200E394(func_02012EBC((struct Big *)func_021BF740(p)));
    for (i=0;i<3;i++) bytes[i]=func_0200E44C((int)base,i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}

u32 func_021BF910(u8 *p)
{
    void *bits;
    u32 index;
    u16 n;
    bits = func_0200E3A0(func_0200E394(func_02012EBC((struct Big *)func_021BF740(p))));
    index = func_021BF7CC(p);
    if (index == 29) return func_021BF968(p);
    n = func_0200E3A4((const u8 *)bits, index);
    if (n == 0) return 0;
    n--;
    return (u8)func_021C2644(p + 0x38, p[0x2b8], n);
}

/*
 * extent: trailing 00 00 at 021BF9CA is two-byte alignment padding.
 * prototype: 02012FCC legacy trailing arguments omitted: full 12-byte body only reads r0, then returns its field at 0x6ac; no forwarding.
 * prototype: full 02012FCC body only reads r0, does not forward r1-r3; legacy trailing inputs omitted.
 */
u32 func_021BF968(u8 *p)
{
    u32 v = func_0200864C((const struct PlayTime *)func_02012FCC(func_021BF740(p)));
    if (v < 10) return 135;
    if (v < 20) return 136;
    if (v < 30) return 137;
    if (v < 40) return 138;
    if (v < 50) return 139;
    if (v < 60) return 140;
    if (v < 70) return 141;
    if (v < 80) return 142;
    if (v < 90) return 143;
    if (v < 100) return 144;
    return 145;
}

/*
 * Reconstructed from the listing.
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001C THM_CALL func_0200E458       -> unresolved: 0200E458 (arm, from name) has no witness outside 021BF9CC..021BF9EE
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BF9CC(u32 a0)
{
    return func_0200E458((const u16 *)func_0200E394(func_02012EBC((struct Big *)func_021BF740((u8 *)a0))), func_021BF7CC((void *)a0));
}


u32 func_021BF9F0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x368);
}


u32 func_021BF9FC(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x384);
}


u32 func_021BFA08(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x394);
}

u32 func_021BFA14(u32 a0)
{
    return (u32)func_02030734(a0, 1000, 0, (const char *)0x21C400C, 4096);
}

void func_021BFA30(char *p)
{
    int i;
    ((struct Obj00926 *)p)->f20 = 0;
    ((struct Obj00926 *)p)->f24 = 0;
    ((struct Obj00926 *)p)->f3DC = 0;
    ((struct Obj00926 *)p)->f2C = 0xf;
    ((struct Obj00926 *)p)->f28 = 0;
    ((struct Obj00926 *)p)->f30 = 0;
    ((struct Obj00926 *)p)->f34 = 0;
    ((struct Obj00926 *)p)->f3C4 = 0;
    ((struct Obj00926 *)p)->f3C8 = 0;
    ((struct Obj00926 *)p)->f3CC = 0;
    ((struct Obj00926 *)p)->f3D0 = 0;
    ((struct Obj00926 *)p)->f3D4 = 0;
    ((struct Obj00926 *)p)->f3D8 = 0;
    ((struct Obj00926 *)p)->f2B8 = 0;
    ((struct Obj00926 *)p)->f2B9 = 0;
    ((struct Obj00926 *)p)->f2CC = 0;
    ((struct Obj00926 *)p)->f3BC = func_020056BC();
    ((struct Obj00926 *)p)->f2FC = 0;
    ((struct Obj00926 *)p)->f2FD = 0;
    ((struct Obj00926 *)p)->f3E4 = 0;
    ((struct Obj00926 *)p)->f3E0 = 0;
    for (i = 0; i < 7; i++) {
        *(u32 *)(p + i * 4 + 0x368) = 0;
    }
    func_021BFC50((u8 *)p);
    func_021BFB0C(p);
    func_021BFBDC(p);
    func_021BFE80(p);
    func_021BFEE4(p);
    func_021BFB60(p);
    func_021BFBB8(p);
    func_021BFB30(p);
    func_021C019C(p);
    func_021C0384(p);
    func_021C03EC(p);
    func_021C04B0(p);
    func_021C07B0(p);
    func_021C0820(p);
}


u32 func_021BFB04(void *a0)
{
    return func_020307B0(a0);
}


/*
 * Clear the u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB0C(void *p)
{
    ((struct Obj25948 *)p)->f1C = 0;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB14(u32 a0)
{
    ((struct Obj14742 *)(((u8*)a0 + 0)))->f1C = func_021C0E08(10, ((struct Obj14742 *)(((u8*)a0 + 0)))->f4);
}


void func_021BFB24(u8 *a0)
{
    func_021C0E3C((void *)((u32)(((struct Obj25949 *)a0)->f1C)));
}


/*
 * Clear the u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB30(void *p)
{
    ((struct Obj25950 *)p)->f8 = 0;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB38(u32 a0)
{
    u8 s[4];
    ((struct Obj14743 *)(((u8*)a0)))->f8 = (u32)func_0201D7EC(23, 0, 0, 0, (u32)(((struct Obj14743 *)(((u8*)a0)))->f4));
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 8)) to func_0201D83C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB54(u8 *a0)
{
    func_0201D83C((void *)((u32)(((struct Obj25951 *)a0)->f8)));
}


/*
 * Clear three u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB60(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}

void func_021BFB74(W *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->obj[i] = (u32)func_02045B38(0, 2, (u16)d_021C3650[i], (u16)p->h);
    }
}


void func_021BFBA0(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02045C04((struct Rec *)p[i + 3]);
}


/*
 * Clear the u32 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFBB8(void *p)
{
    ((struct Obj25953 *)p)->f18 = 0;
}

void func_021BFBC0(u32 a0)
{
    ((struct Obj14745 *)(((u8*)a0 + 0)))->f18 = (u32)func_0201EC64(((struct Obj14745 *)(((u8*)a0 + 0)))->f4);
}


void func_021BFBD0(u8 *a0)
{
    func_0201ED04((struct WordSet *)((u32)(((struct Obj25954 *)a0)->f18)));
}


/*
 * Clear two pairs of u32 slots at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFBDC(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)((char *)p + i * 4 + 0x2bc) = 0;
        *(u32 *)((char *)p + i * 4 + 0x2c4) = 0;
    }
}

void func_021BFBFC(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x2bc) = func_021C10C8(((struct Obj14746 *)p)->f4);
        *(u32 *)(p + i * 4 + 0x2c4) = func_021C10C8(((struct Obj14746 *)p)->f4);
    }
}

void func_021BFC28(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C10D8((void *)(*(u32 *)(p + i * 4 + 0x2bc)));
        func_021C10D8((void *)(*(u32 *)(p + i * 4 + 0x2c4)));
    }
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(a0 + 56), 0, 640 to func_02082BCC.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFC50(u8 *a0)
{
    func_02082BCC((u32)(a0 + 56), 0, 640);
}

/*
 * blocker (2026-10-02, lane04 wC1): 203 bytes differ, relocations all resolve.
 * Locals now laid out like the original (sh, A, B, va, vb, buf declaration
 * order gives the right stack slots). Left: the original keeps the first
 * loop counter in memory (sp+0x20) and addresses buf+3 as reg+reg, has one
 * more spill word (frame sub sp 0x4c vs 0x48), first byte in sp+0x1c, and
 * spills grp[1] to sp+8. Opus lane to finish.
 *
 * Addresses are Black-image addresses.
 *
 * Note 2026-10-04 (wD2 lane04): n, i, first now sit in the original slots (declare `int n` before
 * `i`, then `first`; 195 bytes differ). Left: the u8 c1 spill (original sp+8, the last slot, below the four
 * loop pointer temps at 0x18..0xc; here 0x18), k lives in memory (sp+4), and buf+3 is formed as
 * `add r1,sp,#0x28; adds r1,#3` then reg+reg (here folded to [r0,#3]); a two-array struct
 * {u8 a[3]; u8 b[3]} did not change that.
 * Note 2026-10-05 (wD4 lane12): MATCH, all 480 bytes. Keys: buf is two
 * separate u8 arrays grp[3] (declared first, lands at sp+0x2B) and cnt[3]
 * (sp+0x28), which gives the `add sp,#0x28; adds #3` reg+reg form; no c0/c1/c2
 * locals (grp[x] re-read, the compiler CSE temp takes the sp+8 slot below the
 * loop temps); no `a` local for va[k]; `s = sh[k][j]` before `r = q + j*12`.
 * Only blocker: arm9 callee 0x0200E47C had no label. Filed it as
 * src/matched/arm9/func_0200E47C.c (EXACT, 10 bytes); this goes EXACT once
 * that file has a shard (integrator).
 * Note 2026-10-04 (wD1 lane06): Not retried (203 bytes, stack slot order only). No new finding.
 */
void func_021BFC60(char *p)
{
    u16 sh[3][17];
    u32 A[3][17];
    u32 B[3][17];
    u32 va[3];
    u32 vb[3];
    u8 grp[3];
    u8 cnt[3];
    int n;
    int i, j, k;
    void *h;
    u8 first;
    h = func_0200E394(func_02012EBC((struct Big *)func_021BF740((u8 *)p)));
    first = func_021BF8B0((u8 *)p);
    i = 0;
    grp[0] = func_0200E44C((int)h, 0);
    grp[1] = func_0200E44C((int)h, 1);
    grp[2] = func_0200E44C((int)h, 2);
    cnt[0] = d_021C367C[grp[0]];
    cnt[1] = d_021C367C[grp[1]];
    cnt[2] = d_021C367C[grp[2]];
    va[0] = func_0200E458(h, grp[0]);
    va[1] = func_0200E458(h, grp[1]);
    va[2] = func_0200E458(h, grp[2]);
    vb[0] = func_0200E47C(h, grp[0]);
    vb[1] = func_0200E47C(h, grp[1]);
    vb[2] = func_0200E47C(h, grp[2]);
    for (i = 0; i < 3; i++) {
        u8 g = grp[i];
        n = cnt[i];
        for (j = 0; j < n; j++) {
            sh[i][j] = d_021C3D44[g][j];
            A[i][j] = func_0200E4B0(h, g, j + 1);
            B[i][j] = func_0200E4F8((int)h, g, j + 1);
        }
    }
    *(u8 *)(p + 0x38) = first;
    for (k = 0; k < 3; k++) {
        char *q = p + k * 0xd4;
        *(u8 *)(q + 0x3c) = grp[k];
        *(u8 *)(q + 0x3d) = cnt[k];
        *(u16 *)(q + 0x3e) = va[k];
        *(u32 *)(q + 0x40) = va[k] + vb[k];
        if (*(u32 *)(q + 0x40) > 999999) {
            *(u32 *)(q + 0x40) = 999999;
        }
        for (j = 0; j < 17; j++) {
            u16 s = sh[k][j];
            char *r = q + j * 12;
            u32 x;
            *(u16 *)(r + 0x44) = s;
            *(u8 *)(r + 0x46) = ((u8 *)&d_021C386C)[s];
            *(u8 *)(r + 0x47) = d_021C3900[s];
            *(u8 *)(r + 0x48) = d_021C3994[s];
            x = A[k][j];
            *(u16 *)(r + 0x4a) = x;
            *(u32 *)(r + 0x4c) = x + B[k][j];
        }
    }
}

void func_021BFE40(u8 *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        p[i * 4 + 0x300] = d_021C3758[i].a;
        p[i * 4 + 0x301] = d_021C3758[i].b;
        p[i * 4 + 0x2fe] = d_021C3758[i].c;
        p[i * 4 + 0x2ff] = d_021C3758[i].d;
    }
}


/*
 * Clear the u32 at +0x2d0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFE80(void *p)
{
    ((struct Obj25955 *)p)->f2D0 = 0;
}

void func_021BFE8C(char *p)
{
    struct Params_021BFE8C args;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 0;
    args.c = 1;
    args.d = 2;
    args.e = 3;
    ((struct Obj14747 *)p)->f2D0 = func_021C2070(((struct Obj14747 *)p)->f4, (u32)&args);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 720)), 720 to func_021C209C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFED4(u8 *a0)
{
    func_021C209C((void *)(((struct Obj25956 *)a0)->f2D0));
}


/*
 * Clear ten u32 slots at +0x2d4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFEE4(void *p)
{
    int i;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0x2d4) = 0;
}

/*
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 */
void func_021BFF00(char *p)
{
    struct Params_021BFF00 args;
    int i;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 12;
    args.c = 13;
    for (i = 0; i < 10; i++) {
        *(u32 *)(p + i * 4 + 0x2d4) = func_021C26E8(((struct Obj25957 *)p)->f4, (u32)&args, func_021BF9FC(p, 3));
        func_021C2740(*(u32 *)(p + i * 4 + 0x2d4), 0);
    }
}


void func_021BFF5C(int *p)
{
    int i;
    for (i = 0; i < 10; i++)
        func_021C270C((void *)p[i + 0xB5]);
}

/*
 * prototype: 0207DCF8 full body fixes r1/r2 and forwards only entry r0 to 02082A60; full target overwrites entry r3 and reads no stack arguments.
 * data: pool 021BFFC4 contains 5c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 * volatile: hardware stores 021BFF88/8C/90/94; 04000060 re-read at 021BFF96 and 021BFFA4.
 */
void func_021BFF78(void)
{
    func_0207D988();
    func_0207DB1C();
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    func_0207DCF8(d_021C365C);
}
