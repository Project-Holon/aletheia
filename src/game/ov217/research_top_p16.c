/*
 * file:     research_top_p16.c
 * unit:     yes
 * function: func_021BD370, func_021BD38C, func_021BD3A4, func_021BD3B4, func_021BD458, func_021BD474, func_021BD47C, func_021BD4CC, func_021BD4F0, func_021BD50C, func_021BD520, func_021BD53C, func_021BD56C, func_021BD588, func_021BD5B4, func_021BD5C4, func_021BD5E0, func_021BD5F4, func_021BD61C, func_021BD62C, func_021BD708, func_021BD710, func_021BD718, func_021BD868, func_021BD89C, func_021BDC18, func_021BDF58, func_021BE040
 * address:  0x021BD370
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
 *   func_020437AC  0x020437AC  arm
 *   func_02025538  0x02025538  thumb
 *   func_02025588  0x02025588  thumb
 *   func_021BC708  0x021BC708  thumb  ov217
 *   func_020255A0  0x020255A0  thumb
 *   func_02025774  0x02025774  thumb
 *   func_020257D0  0x020257D0  thumb
 *   d_021C31BC 0x021C31BC data a4
 *   func_0202570C  0x0202570C  thumb
 *   func_02021540  0x02021540  thumb
 *   func_021C29C8  0x021C29C8  thumb  ov217
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   d_021C3260 0x021C3260 data a4
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *   func_021BC720  0x021BC720  thumb  ov217
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021BC610  0x021BC610  thumb  ov217
 *   func_021C09AC  0x021C09AC  thumb  ov217
 *   func_021BFA14  0x021BFA14  thumb  ov217
 *   func_021BFA30  0x021BFA30  thumb  ov217
 *   func_021BF74C  0x021BF74C  thumb  ov217
 *   func_021BF754  0x021BF754  thumb  ov217
 *   func_021BFB04  0x021BFB04  thumb  ov217
 *   func_021BFB24  0x021BFB24  thumb  ov217
 *   func_021BE094  0x021BE094  thumb  ov217
 *   func_021BE0D0  0x021BE0D0  thumb  ov217
 *   func_021BE108  0x021BE108  thumb  ov217
 *   func_021BE21C  0x021BE21C  thumb  ov217
 *   func_021BE33C  0x021BE33C  thumb  ov217
 *   func_021BE36C  0x021BE36C  thumb  ov217
 *   func_021BE384  0x021BE384  thumb  ov217
 *   func_021BF6D4  0x021BF6D4  thumb  ov217
 *   func_021BF710  0x021BF710  thumb  ov217
 *   func_021BED9C  0x021BED9C  thumb  ov217
 *   func_021C20C4  0x021C20C4  thumb  ov217
 *   func_021BF600  0x021BF600  thumb  ov217
 *   func_021BF5E4  0x021BF5E4  thumb  ov217
 *   func_021BEDC4  0x021BEDC4  thumb  ov217
 *   func_021BEDEC  0x021BEDEC  thumb  ov217
 *   func_021BE490  0x021BE490  thumb  ov217
 *   func_021BE4A4  0x021BE4A4  thumb  ov217
 *   func_0204A600  0x0204A600  arm
 *   func_021BFB14  0x021BFB14  thumb  ov217
 *   func_021BFB38  0x021BFB38  thumb  ov217
 *   func_021BFB74  0x021BFB74  thumb  ov217
 *   func_021BFBC0  0x021BFBC0  thumb  ov217
 *   func_021BFE40  0x021BFE40  thumb  ov217
 *   func_021BEFF8  0x021BEFF8  thumb  ov217
 *   func_021BFF78  0x021BFF78  thumb  ov217
 *   func_021BFFC8  0x021BFFC8  thumb  ov217
 *   func_021C00AC  0x021C00AC  thumb  ov217
 *   func_021C00FC  0x021C00FC  thumb  ov217
 *   func_021C0124  0x021C0124  thumb  ov217
 *   func_021C0174  0x021C0174  thumb  ov217
 *   func_021C01B8  0x021C01B8  thumb  ov217
 *   func_021C0250  0x021C0250  thumb  ov217
 *   func_021C02C8  0x021C02C8  thumb  ov217
 *   func_021C03A0  0x021C03A0  thumb  ov217
 *   func_021C0408  0x021C0408  thumb  ov217
 *   func_021C04CC  0x021C04CC  thumb  ov217
 *   func_021C04FC  0x021C04FC  thumb  ov217
 *   func_021C05B0  0x021C05B0  thumb  ov217
 *   func_021C06C8  0x021C06C8  thumb  ov217
 *   func_021C06F0  0x021C06F0  thumb  ov217
 *   func_021BFC60  0x021BFC60  thumb  ov217
 *   func_021BFBFC  0x021BFBFC  thumb  ov217
 *   func_021BFE8C  0x021BFE8C  thumb  ov217
 *   func_021BFF00  0x021BFF00  thumb  ov217
 *   func_021C07BC  0x021C07BC  thumb  ov217
 *   func_021C083C  0x021C083C  thumb  ov217
 *   func_021C0878  0x021C0878  thumb  ov217
 *   func_021C08D4  0x021C08D4  thumb  ov217
 *   func_021C08C4  0x021C08C4  thumb  ov217
 *   func_021BF100  0x021BF100  thumb  ov217
 *   func_021BF11C  0x021BF11C  thumb  ov217
 *   func_021BF13C  0x021BF13C  thumb  ov217
 *   func_021BF15C  0x021BF15C  thumb  ov217
 *   func_021BF264  0x021BF264  thumb  ov217
 *   func_021BF2FC  0x021BF2FC  thumb  ov217
 *   func_021BF38C  0x021BF38C  thumb  ov217
 *   func_021BF3B4  0x021BF3B4  thumb  ov217
 *   func_021BF3D8  0x021BF3D8  thumb  ov217
 *   func_021BF08C  0x021BF08C  thumb  ov217
 *   func_021BF47C  0x021BF47C  thumb  ov217
 *   func_021BF55C  0x021BF55C  thumb  ov217
 *   func_021BF594  0x021BF594  thumb  ov217
 *   func_021BEAF8  0x021BEAF8  thumb  ov217
 *   func_021BE8FC  0x021BE8FC  thumb  ov217
 *   func_021BE46C  0x021BE46C  thumb  ov217
 *   func_021BE498  0x021BE498  thumb  ov217
 *   func_021BE934  0x021BE934  thumb  ov217
 *   func_021BE448  0x021BE448  thumb  ov217
 *   func_021BE4DC 0x021BE4DC thumb ov217
 *   func_021BE4E0 0x021BE4E0 thumb ov217
 *   func_021C0918 0x021C0918 thumb ov217
 *   func_021C093C 0x021C093C thumb ov217
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C08  0x02035C08  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021C09B8  0x021C09B8  thumb  ov217
 *   func_021BE454  0x021BE454  thumb  ov217
 *   func_021BE614  0x021BE614  thumb  ov217
 *   func_021BE678  0x021BE678  thumb  ov217
 *   func_021BE704  0x021BE704  thumb  ov217
 *   func_021BE790  0x021BE790  thumb  ov217
 *   func_021BE7B4  0x021BE7B4  thumb  ov217
 *   func_021BE808  0x021BE808  thumb  ov217
 *   func_021BEB40  0x021BEB40  thumb  ov217
 *   func_021BEC00  0x021BEC00  thumb  ov217
 *   func_021BF758  0x021BF758  thumb  ov217
 *   func_021BF810  0x021BF810  thumb  ov217
 *   func_021BE4E8  0x021BE4E8  thumb  ov217
 *   func_021BE580  0x021BE580  thumb  ov217
 *   func_02006238  0x02006238  thumb
 *   func_021BF704  0x021BF704  thumb  ov217
 *   func_021BF568  0x021BF568  thumb  ov217
 *   func_021BEC84  0x021BEC84  thumb  ov217
 *   func_021BF76C  0x021BF76C  thumb  ov217
 *   func_021C1184  0x021C1184  thumb  ov217
 *   func_021C1154  0x021C1154  thumb  ov217
 *   func_021BE930  0x021BE930  thumb  ov217
 *   func_021BE7F0  0x021BE7F0  thumb  ov217
 *   func_021BF574  0x021BF574  thumb  ov217
 *   func_021BEEA4  0x021BEEA4  thumb  ov217
 *   func_021BEF30 0x021BEF30 thumb ov217
 *   func_021BEFC0 0x021BEFC0 thumb ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../../matched/include/Obj25885.h"
#include "../../matched/include/Obj25886.h"
#include "../../matched/include/Obj25887.h"
#include "../../matched/include/Obj25889.h"
#include "../../matched/include/Obj00025.h"
#include "../../matched/include/Obj10958.h"
#include "../../matched/include/Obj25893.h"
#include "../../matched/include/Obj25894.h"
#include "../../matched/include/Obj14735.h"
#include "../../matched/include/Obj00021.h"
#include "../../matched/include/Obj25895.h"
#include "../../matched/include/Obj25896.h"
#include "../../matched/include/Obj06712.h"

struct Obj020437AC;
struct Sys;
struct Grid;
struct Obj;
struct PalAnmSlot;
struct Vec2;
struct Node;
struct W;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short s16;

struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry { s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

typedef signed char    s8;

struct Entry021C3260 {
    int a;
    int b;
    unsigned char c;
    unsigned char pad[11];
};

typedef struct { unsigned short x, y; } Pos;

extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_02025588(void *p);
extern u32 func_021BC708(void *,u32);
extern struct Grid *func_020255A0(struct Sys *,const struct Param *);
extern void func_02025774(u8 *,u32);
extern void func_020257D0(struct Obj *);
extern void func_0202570C(struct Grid *g);
extern void *func_02021518(u32);
extern void func_0202155C(struct PalAnmSlot *, u32, u32, u32);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
extern u32 func_02021540(void *a0);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_021C29C8(u32 a0);
extern u32 func_021C29D8(void *a0);
extern void func_021C29E8(void *p, u32 b, u32 c, u32 d);
extern int func_021C2A08(char *p);
extern u32 func_021BC720(void *p, u32 i);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *a, unsigned int b);
extern void func_0203D34C(u32 a, u32 b);
extern int func_020056A0(void (*)(void), void *, int);
extern void func_021BC610(u32 a0, u32 a1);
extern void func_02030EAC(struct Node *n);
extern u32 func_021C09AC(void *p);
extern u32 func_021BFA14(u32 a0);
extern void func_021BFA30(char *p);
extern void func_021BF74C(void *a, void *b);
extern void func_021BF754(void *p, u32 v);
extern u32 func_021BFB04(void *a0);
extern void func_021BFB24(u8 *a0);
extern void func_021BE094(u32 a0);
extern void func_021BE0D0(u32 a0);
extern void func_021BE108(char *p);
extern void func_021BE21C(char *p);
extern void func_021BE33C(u32 a0);
extern void func_021BE36C(u32 a0);
extern void func_021BE384(u8 *a0);
extern void func_021BF6D4(char *p);
extern void func_021BF710(void *p);
extern void func_0204A600(void *h);
extern void func_021BED9C(char *p);
extern void func_021C20C4(void *h);
extern void func_021BF600(u8 *a0);
extern void func_021BF5E4(int *p);
extern void func_021BEDC4(char *p);
extern void func_021BEDEC(char *p);
extern void func_021BE490(void *p);
extern void func_021BE4A4(u32 a0);
extern void func_021BFB14(u32 a0);
extern void func_021BFB38(u32 a0);
extern void func_021BFB74(struct W *p);
extern void func_021BFBC0(u32 a0);
extern void func_021BFE40(u8 *p);
extern void func_021BEFF8(u8 *p);
extern void func_021BFF78(void);
extern void func_021BFFC8(char *p);
extern void func_021C00AC(char *p);
extern void func_021C00FC(void *p);
extern void func_021C0124(char *p);
extern void func_021C0174(void *p);
extern void func_021C01B8(char *p);
extern void func_021C0250(char *p);
extern void func_021C02C8(char *p);
extern void func_021C03A0(u8 *p);
extern void func_021C0408(u8 *p);
extern void func_021C04CC(u8 *p);
extern void func_021C04FC(u8 *p);
extern void func_021C05B0(u8 *p);
extern void func_021C06C8(u8 *p);
extern void func_021C06F0(u8 *p);
extern void func_021BFC60(char *p);
extern void func_021BFBFC(char *p);
extern void func_021BFE8C(char *p);
extern void func_021BFF00(char *p);
extern void func_021C07BC(u8 *p);
extern void func_021C083C(u8 *p);
extern void func_021C0878(u8 *p);
extern void func_021C08D4(char *p);
extern void func_021C08C4(u32 a0);
extern void func_021BF100(char *p);
extern void func_021BF11C(char *p);
extern void func_021BF13C(char *p);
extern void func_021BF15C(char *p);
extern void func_021BF264(char *p);
extern void func_021BF2FC(char *p);
extern void func_021BF38C(char *p);
extern void func_021BF3B4(char *p);
extern void func_021BF3D8(char *p);
extern void func_021BF08C(char *p);
extern void func_021BF47C(char *p);
extern void func_021BF55C(void *p);
extern void func_021BF594(char *p, int i);
extern void func_021BEAF8(u8 *p);
extern void func_021BE8FC(void);
extern u32 func_021BE46C(u8 *a0);
extern void func_021BE498(u8 *a0, u32 a1);
extern int func_021BE934(char *p);
extern void func_021BE448(void *p);
extern u32 func_021BE4DC(void *p);
extern void func_021BE4E0(void *p);
extern void func_021C0918(u8 *a0);
extern int func_021C093C(u8 *a0);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *rect);
extern void *func_021C09B8(void *p);
extern void func_020061E4(u32 a);
extern void func_021BE454(u8 *a0, u32 a1);
extern u32 func_021BE614(u32 a0, u32 a1);
extern void func_021BE678(char *p);
extern void func_021BE704(char *p);
extern u32 func_021BE790(u32 a0);
extern u32 func_021BE7B4(u32 a0);
extern void func_021BE808(char *p);
extern u32 func_021BEB40(u32 a0);
extern void func_021BEC00(u32 *p);
extern u32 func_021BF758(void *p);
extern u32 func_021BF810(void *p);
extern void func_021BE4E8(u8 *p);
extern void func_021BE580(u8 *p);
extern int func_02006238(void);
extern void func_021BF704(void *p);
extern void func_021BF568(void *p);
extern void func_021BEC84(u8 *p, int mode);
extern u8 *func_021BF76C(void *p);
extern void func_021C1184(u8 *h, u32 v);
extern void func_021C1154(u8 *h);
extern void func_021BE930(void *p, u32 v);
extern u32 func_021BE7F0(u32 a0);
extern void func_021BF574(void *p);
extern void func_021BEEA4(char *p);
extern void func_021BEF30(char *);
extern void func_021BEFC0(u8 *, u32);
void func_021BD370(int *p);
void func_021BD38C(char *p);
void func_021BD3A4(u8 *a0);
void func_021BD3B4(u8 *p);
void func_021BD458(int *p);
void func_021BD474(void *p);
void func_021BD47C(u8 *p);
u32 func_021BD4CC(u32 a0);
void func_021BD4F0(char *p);
void func_021BD50C(void *p);
void func_021BD520(int *p);
void func_021BD53C(int *p);
void func_021BD56C(int *p);
void func_021BD588(void *p);
void func_021BD5B4(u32 a0);
void func_021BD5C4(char *p);
void func_021BD5E0(u32 a0);
void *func_021BD5F4(void *p);
u32 func_021BD61C(void *a0);
void func_021BD62C(unsigned char *p);
u32 func_021BD708(void *p);
u32 func_021BD710(void *p);
void func_021BD718(unsigned char *p);
void func_021BD868(u32 a0);
void func_021BD89C(u8 *p);
void func_021BDC18(u8 *p);
void func_021BDF58(u8 *p);
void func_021BE040(u8 *p);
extern const struct Entry d_021C31BC[];
extern const struct Entry021C3260 d_021C3260[];


/*
 * Addresses are Black-image addresses.
 */
void func_021BD370(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_020437AC((struct Obj020437AC *)p[i + 0x50]);
}


void func_021BD38C(char *p)
{
    int i = 0x47;
    *(void **)(p + (i << 2) + 0x10) =
        func_02025538(((struct Obj25885 *)p)->f8, *(void **)(p + (i << 2)));
}


void func_021BD3A4(u8 *a0)
{
    func_02025588((void *)((u32)(((struct Obj25886 *)a0)->f12C)));
}

void func_021BD3B4(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct Entry *q;
    u8 *dest;
    sysOff=0x12C;
    outOff=0x130;
    callOff=0x130;
    uploadOff=0x130;
    for(i=0;i<4;i++) {
        dest=p+i*4;
        param.bmp=((struct Obj25887 *)dest)->f140;
        q=&d_021C31BC[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BC708(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=func_020255A0(*(struct Sys **)(p+sysOff),&param);
        func_02025774(*(u8 **)(dest+callOff),0);
        func_020257D0(*(struct Obj **)(dest+uploadOff));
    }
}


void func_021BD458(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0202570C((struct Grid *)p[i + 0x4C]);
}


void func_021BD474(void *p)
{
    ((struct Obj25889 *)p)->f98 = 0;
}

void func_021BD47C(u8 *p)
{
    *(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98 = func_02021518(((struct Obj00025 *)p)->f8);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 0, 512, ((struct Obj00025 *)p)->f8);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 2, 512, ((struct Obj00025 *)p)->f8);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 0, 0, 512);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 2, 0, 512);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001E THM_CALL func_02021540       -> unresolved: 02021540 (arm, from name) has no witness outside 021BD4CC..021BD4F0
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD4CC(u32 a0)
{
    func_020215A0((struct PalAnmSlot *)(((struct Obj10958 *)((u8*)a0))->f98), 0);
    func_020215A0((struct PalAnmSlot *)(((struct Obj10958 *)((u8*)a0))->f98), 2);
    return func_02021540((void *)(((struct Obj10958 *)((u8*)a0))->f98));
}


void func_021BD4F0(char *p)
{
    int i;
    for (i = 0; i < 6; i++)
        ((int *)(p + 0x9c))[i] = func_021C29C8(((struct Obj00025 *)p)->f8);
}


/*
 * Clear six u32 slots at +0x9c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD50C(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x9c) = 0;
}


void func_021BD520(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29D8((void *)p[i + 0x27]);
}


void func_021BD53C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29E8((void *)p[i + 0x27], d_021C3260[i].a, d_021C3260[i].b, d_021C3260[i].c);
}


void func_021BD56C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C2A08((char *)p[i + 0x27]);
}


void func_021BD588(void *p)
{
    int obj = func_021BC720(p, 1);
    Pos pos;
    pos.x = 0x80;
    pos.y = 0x60;
    func_0204B404((struct Obj *)obj, (const struct Vec2 *)(&pos), 0);
    func_0204B3DC((struct Obj *)obj, 1);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD5B4(u32 a0)
{
    func_0203D34C(1, ((struct Obj25893 *)(((u8*)a0 + 0)))->f8);
}


void func_021BD5C4(char *p)
{
    ((struct Obj25894 *)p)->f154 = func_020056A0((void (*)(void))func_021BC610, p, 0);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void func_021BD5E0(u32 a0)
{
    func_02030EAC((struct Node *)(((struct Obj14735 *)(((u8*)a0)))->f154));
    ((struct Obj14735 *)(((u8*)a0)))->f154 = 0;
}


void *func_021BD5F4(void *p)
{
    void *r;
    void *a;
    a = (void *)func_021C09AC(p);
    r = (void *)func_021BFA14((u32)a);
    func_021BFA30(r);
    func_021BF74C(r, a);
    func_021BF754(r, (u32)p);
    return r;
}

u32 func_021BD61C(void *a0)
{
    func_021BFB24((u8 *)a0);
    return func_021BFB04(a0);
}


void func_021BD62C(unsigned char *p)
{
    switch (((struct Obj00021 *)p)->f20) {
    case 0: func_021BD718(p); break;
    case 1: func_021BD868((u32)p); break;
    case 2: func_021BD89C(p); break;
    case 3: func_021BDC18(p); break;
    case 4: func_021BDF58(p); break;
    case 5: func_021BE040(p); break;
    case 6: func_021BE094((u32)p); break;
    case 7: func_021BE0D0((u32)p); break;
    case 8: func_021BE108((char *)p); break;
    case 9: func_021BE21C((char *)p); break;
    case 10: func_021BE33C((u32)p); break;
    case 11: func_021BE36C((u32)p); break;
    case 12: func_021BE384((u8 *)p); break;
    case 13: return;
    }
    func_021BF6D4((char *)p);
    func_021BF710(p);
    if (((struct Obj00021 *)p)->f3C4 != 0) {
        func_0204A600(((struct Obj00021 *)p)->f3C4);
        func_021BED9C((char *)p);
        func_021C20C4(((struct Obj00021 *)p)->f2D0);
        func_021BF600(p);
        func_021BF5E4((int *)p);
        func_021BEDC4((char *)p);
        func_021BEDEC((char *)p);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    func_021BE490(p);
    func_021BE4A4((u32)p);
}


u32 func_021BD708(void *p)
{
    return ((struct Obj25895 *)p)->f3E0;
}


/*
 * Field getter, u32 at +0x3e4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD710(void *p)
{
    return ((struct Obj25896 *)p)->f3E4;
}


void func_021BD718(unsigned char *p)
{
    int r;
    func_021BFB14((u32)p);
    func_021BFB38((u32)p);
    func_021BFB74((struct W *)p);
    func_021BFBC0((u32)p);
    func_021BFE40(p);
    func_021BEFF8(p);
    func_021BFF78();
    func_021BFFC8((char *)p);
    func_021C00AC((char *)p);
    func_021C00FC(p);
    func_021C0124((char *)p);
    func_021C0174(p);
    func_021C01B8((char *)p);
    func_021C0250((char *)p);
    func_021C02C8((char *)p);
    func_021C03A0(p);
    func_021C0408(p);
    func_021C04CC(p);
    func_021C04FC(p);
    func_021C05B0(p);
    func_021C06C8(p);
    func_021C06F0(p);
    func_021BFC60((char *)p);
    func_021BFBFC((char *)p);
    func_021BFE8C((char *)p);
    func_021BFF00((char *)p);
    func_021C07BC(p);
    func_021C083C(p);
    func_021C0878(p);
    func_021C08D4((char *)p);
    func_021C08C4((u32)p);
    func_021BF100((char *)p);
    func_021BF11C((char *)p);
    func_021BF13C((char *)p);
    func_021BF15C((char *)p);
    func_021BF264((char *)p);
    func_021BF2FC((char *)p);
    func_021BF38C((char *)p);
    func_021BF3B4((char *)p);
    func_021BF3D8((char *)p);
    func_021BF08C((char *)p);
    func_021BF47C((char *)p);
    func_021BF55C(p);
    func_021BF594((char *)p, 0);
    func_021BF594((char *)p, 7);
    func_021BEAF8(p);
    *(int *)&((struct Obj00021 *)p)->f3C4 = 1;
    func_021BE8FC();
    r = func_021BE46C(p);
    func_021BE498(p, 1);
    func_021BE498(p, r);
    if (r == 3)
        func_021BE934((char *)p);
    func_021BE448(p);
}


#pragma thumb on


void func_021BD868(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
        func_021C0918((u8 *)a0);
        func_021BE4E0((void *)a0);
        break;
    case 1:
        if (func_021C093C((u8 *)a0) != 0) {
            func_021BE448((void *)a0);
        }
        break;
    }
}


void func_021BD89C(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    func_0203630C();
    keys = func_020362DC();
    hit = func_02035C08(p + 0x2FE);
    sub = func_02035C08(func_021C09B8(((struct Obj00021 *)p)->f0));
    if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && ((struct Obj00021 *)p)->f3D8 != 0 && *(int *)&((struct Obj00021 *)p)->f3D4 != 0) {
        func_021BE448(p);
        func_021BE498(p, 8);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
        return;
    }
    if (func_021BF758(p) != 0 || sub == 0) {
        func_021BE454(p, 1);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
        return;
    }
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        return;
    }
    if (hit == 6 && *(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
        ((struct Obj00021 *)p)->f3CC = 1;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_020061E4(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_021BE614((u32)p, 0);
        }
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 3) {
        func_021BE614((u32)p, 1);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 4) {
        func_021BE614((u32)p, 2);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 5) {
        func_021BE614((u32)p, 3);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 0) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: func_021BE704((char *)p); break;
        case 1: func_021BE7B4((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (hit == 1) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: func_021BE678((char *)p); break;
        case 1: func_021BE790((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (keys & 2) {
        func_021BE454(p, 0);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
    }
}


void func_021BDC18(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    func_0203630C();
    keys = func_020362DC();
    hit = func_02035C08(p + 0x2FE);
    sub = func_02035C08(func_021C09B8(((struct Obj00021 *)p)->f0));
    if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && ((struct Obj00021 *)p)->f3D8 != 0 && *(int *)&((struct Obj00021 *)p)->f3D4 != 0) {
        func_021BE448(p);
        func_021BE498(p, 9);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 3);
        return;
    }
    if (func_021BF758(p) != 0 || sub == 0) {
        func_021BE454(p, 1);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
        return;
    }
    if (keys & 0x40) {
        func_021BE4E8(p);
    } else if (keys & 0x80) {
        func_021BE580(p);
    } else if (hit == 6 && *(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
        ((struct Obj00021 *)p)->f3CC = 1;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_020061E4(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_021BE614((u32)p, 0);
        }
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 3) {
        func_021BE614((u32)p, 1);
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 4) {
        func_021BE614((u32)p, 2);
    } else if (hit == 5) {
        func_021BE614((u32)p, 3);
    } else if ((keys & 0x20) || hit == 0) {
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: func_021BE704((char *)p); break;
        case 1: func_021BE7B4((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if ((keys & 0x10) || hit == 1) {
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: func_021BE678((char *)p); break;
        case 1: func_021BE790((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if ((keys & 1) && *(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0
               && (*(int *)&((struct Obj00021 *)p)->f34 == 0 || *(int *)&((struct Obj00021 *)p)->f34 == 4)) {
        ((struct Obj00021 *)p)->f3CC = 0;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 3);
    } else if (keys & 2) {
        func_021BE454(p, 0);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
    }
}


void func_021BDF58(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BFC60((char *)p);
        func_021BF704(p);
        func_021BF568(p);
        func_021BEC84(p, 0);
        func_021BEC84(p, 1);
        func_021C1184(func_021BF76C(p), 1);
        func_021C1154(func_021BF76C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (((struct Obj00021 *)p)->f28 >= 0x78)
                func_021BE4E0(p);
            else
                func_020061E4(0x76B);
        }
        break;
    case 2:
        *(int *)&((struct Obj00021 *)p)->f3C8 = 1;
        func_021BE930(p, 1);
        func_021BF3D8((char *)p);
        func_021BEFF8(p);
        func_021BE7F0((u32)p);
        func_021BF574(p);
        func_021BF08C((char *)p);
        func_021BF15C((char *)p);
        func_021BF264((char *)p);
        func_021BF3B4((char *)p);
        func_021BF2FC((char *)p);
        func_021BEEA4((char *)p);
        func_021BF47C((char *)p);
        if (((struct Obj00021 *)p)->f3CC == 0)
            func_021BE934((char *)p);
        func_020061E4(0x76C);
        func_021BE448(p);
        break;
    }
}

void func_021BE040(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BEF30((char *)p);
        func_021BE4E0(p);
        break;
    case 1:
        if (((struct Obj06712 *)p)->f28 % 10u == 0) {
            u8 index = p[765];
            p[765] = index + 1;
            func_021BEFC0(p, index);
        }
        if (p[764] <= p[765]) func_021BE448(p);
        break;
    }
}
