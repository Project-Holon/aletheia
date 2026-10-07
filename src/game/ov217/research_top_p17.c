/*
 * file:     research_top_p17.c
 * unit:     yes
 * function: func_021BE094, func_021BE0D0, func_021BE108, func_021BE21C, func_021BE33C, func_021BE36C, func_021BE384, func_021BE448, func_021BE454, func_021BE460, func_021BE468, func_021BE46C, func_021BE490, func_021BE498
 * address:  0x021BE094
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
 *   func_021BE4DC  0x021BE4DC  thumb  ov217
 *   func_021BE4E0  0x021BE4E0  thumb  ov217
 *   func_021BF5BC  0x021BF5BC  thumb  ov217
 *   func_021BF60C  0x021BF60C  thumb  ov217
 *   func_021BF6A4  0x021BF6A4  thumb  ov217
 *   func_021BEAF8  0x021BEAF8  thumb  ov217
 *   func_021BF658  0x021BF658  thumb  ov217
 *   func_021BED10 0x021BED10 thumb ov217
 *   func_021C1184 0x021C1184 thumb ov217
 *   func_021C1178 0x021C1178 thumb ov217
 *   func_02006238 0x02006238 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021BF704 0x021BF704 thumb ov217
 *   func_021BF728 0x021BF728 thumb ov217
 *   func_021BFC60 0x021BFC60 thumb ov217
 *   func_021BF08C 0x021BF08C thumb ov217
 *   func_021BF15C 0x021BF15C thumb ov217
 *   func_021BF3B4 0x021BF3B4 thumb ov217
 *   func_021BF38C 0x021BF38C thumb ov217
 *   func_021BEEA4 0x021BEEA4 thumb ov217
 *   func_021BF3D8 0x021BF3D8 thumb ov217
 *   func_021BEF98 0x021BEF98 thumb ov217
 *   func_021BEC64 0x021BEC64 thumb ov217
 *   func_021BEC0C 0x021BEC0C thumb ov217
 *   func_021BF264 0x021BF264 thumb ov217
 *   func_021BF2FC 0x021BF2FC thumb ov217
 *   func_021BF4AC 0x021BF4AC thumb ov217
 *   func_021BF47C 0x021BF47C thumb ov217
 *   func_021BF77C 0x021BF77C thumb ov217
 *   func_021BE9B8 0x021BE9B8 thumb ov217
 *   func_021BE934 0x021BE934 thumb ov217
 *   func_021BE90C  0x021BE90C  thumb  ov217
 *   func_021BFB54  0x021BFB54  thumb  ov217
 *   func_021BFBA0  0x021BFBA0  thumb  ov217
 *   func_021BFBD0  0x021BFBD0  thumb  ov217
 *   func_021BFC28  0x021BFC28  thumb  ov217
 *   func_021BFED4  0x021BFED4  thumb  ov217
 *   func_021BFF5C  0x021BFF5C  thumb  ov217
 *   func_021C0084  0x021C0084  thumb  ov217
 *   func_021C00F8  0x021C00F8  thumb  ov217
 *   func_021C0114  0x021C0114  thumb  ov217
 *   func_021C0170  0x021C0170  thumb  ov217
 *   func_021C018C  0x021C018C  thumb  ov217
 *   func_021C0230  0x021C0230  thumb  ov217
 *   func_021C02A8  0x021C02A8  thumb  ov217
 *   func_021C0358  0x021C0358  thumb  ov217
 *   func_021C03D0  0x021C03D0  thumb  ov217
 *   func_021C0494  0x021C0494  thumb  ov217
 *   func_021C06AC  0x021C06AC  thumb  ov217
 *   func_021C06E0  0x021C06E0  thumb  ov217
 *   func_021C0794  0x021C0794  thumb  ov217
 *   func_021C0800  0x021C0800  thumb  ov217
 *   func_021C085C  0x021C085C  thumb  ov217
 *   func_021C08A8  0x021C08A8  thumb  ov217
 *   func_021C08F0  0x021C08F0  thumb  ov217
 *   func_021C0968  0x021C0968  thumb  ov217
 *   func_021C09E0  0x021C09E0  thumb  ov217
 *   func_021C09EC  0x021C09EC  thumb  ov217
 *   func_021C09C4  0x021C09C4  thumb  ov217
 *   func_021C09C8  0x021C09C8  thumb  ov217
 *   func_021C09CC  0x021C09CC  thumb  ov217
 *   func_021C0E4C  0x021C0E4C  thumb  ov217
 */
#include "../../matched/include/Obj00021.h"
#include "../../matched/include/Obj25897.h"
#include "../../matched/include/Obj25898.h"
#include "../../matched/include/Obj25899.h"
#include "../../matched/include/Obj25900.h"
#include "../../matched/include/Obj25901.h"
#include "../../matched/include/Obj25902.h"
#include "../../matched/include/Obj25904.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern u32 func_021BE4DC(void *p);
extern void func_021BE4E0(void *p);
extern void func_021BF5BC(u8 *a0, u32 a1);
extern void func_021BF60C(char *p);
extern u32 func_021BF6A4(u8 *a0);
extern void func_021BEAF8(u8 *p);
extern void func_021BF658(char *p);
extern u8 *func_021BF77C(void *p);
extern void func_021BED10(u8 *p, u32 mode);
extern void func_021C1184(u8 *h, u32 v);
extern void func_021C1178(u8 *h);
extern int func_02006238(void);
extern void func_020061E4(u32 a);
extern void func_021BF704(void *p);
extern void func_021BF728(void *p);
extern void func_021BFC60(char *p);
extern void func_021BF08C(char *p);
extern void func_021BF15C(char *p);
extern void func_021BF3B4(char *p);
extern void func_021BF38C(char *p);
extern void func_021BEEA4(char *p);
extern void func_021BF3D8(char *p);
extern void func_021BEF98(char *p);
extern void func_021BEC64(void *p);
extern void func_021BEC0C(void *p);
extern void func_021BF264(char *p);
extern void func_021BF2FC(char *p);
extern void func_021BF4AC(char *p);
extern void func_021BF47C(char *p);
extern void func_021BE9B8(u8 *p);
extern int func_021BE934(char *p);
extern int func_0204E804(void);
extern void func_021BE90C(void);
extern void func_021BFB54(u8 *a0);
extern void func_021BFBA0(int *p);
extern void func_021BFBD0(u8 *a0);
extern void func_021BFC28(char *p);
extern void func_021BFED4(u8 *a0);
extern void func_021BFF5C(int *p);
extern u32 func_021C0084();
extern u32 func_021C00F8();
extern u32 func_021C0114();
extern u32 func_021C0170();
extern u32 func_021C018C();
extern void func_021C0230(int *p);
extern u32 func_021C02A8(u32 a0);
extern u32 func_021C0358(u32 a0);
extern void func_021C03D0(int *p);
extern void func_021C0494(int *p);
extern void func_021C06AC(int *p);
extern void func_021C06E0(u8 *a0);
extern void func_021C0794(int *p);
extern u32 func_021C0800(u32 a0);
extern void func_021C085C(int *p);
extern void func_021C08A8(int *);
extern void func_021C08F0(u8 *a0);
extern void func_021C0968(unsigned char *a0);
extern void func_021C09E0(u32 a0);
extern void func_021C09EC(u32 a0);
extern void func_021C09C4(u8 *, u32);
extern u32 func_021C09C8(void *p);
extern u32 func_021C09CC(void *p);
extern void func_021C0E4C(u32, u32);
void func_021BE094(u32 a0);
void func_021BE0D0(u32 a0);
void func_021BE108(char *p);
void func_021BE21C(char *p);
void func_021BE33C(u32 a0);
void func_021BE36C(u32 a0);
void func_021BE384(u8 *a0);
void func_021BE448(void *p);
void func_021BE454(u8 *a0, u32 a1);
void func_021BE460(void *p, u32 v);
u32 func_021BE468(void *p);
u32 func_021BE46C(u8 *a0);
void func_021BE490(void *p);
void func_021BE498(u8 *a0, u32 a1);

/*
 * Same two-case entry as func_021BE0D0; mode 0 arms the +5 handle and
 * func_021BF60C().
 *
 * Addresses are Black-image addresses.
 */
void func_021BE094(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF5BC((u8 *)a0, 5);
    func_021BF60C((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BE448((void *)a0);
    }
    break;
    }
}

void func_021BE0D0(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF658((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BEAF8((u8 *)a0);
    func_021BE448((void *)a0);
    }
    break;
    }
}

void func_021BE108(char *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        ((struct Obj00021 *)p)->f3D0 = 1;
        func_021BF704(p);
        func_021BF728(p);
        func_021BFC60(p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF3B4(p);
        func_021BF38C(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BEF98(p);
        func_021BED10((u8 *)p, 0);
        func_021BED10((u8 *)p, 1);
        func_021BEC64(p);
        func_021C1184(func_021BF77C(p), 1);
        func_021C1178(func_021BF77C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (((struct Obj00021 *)p)->f28 >= 0x3c) {
                func_021BE4E0(p);
                return;
            }
            func_020061E4(0x76b);
        }
        break;
    case 2:
        ((struct Obj00021 *)p)->f3D0 = 0;
        func_021BEC0C(p);
        func_021C1184(func_021BF77C(p), 0);
        func_021BF08C(p);
        func_021BF3B4(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BF4AC(p);
        func_021BF47C(p);
        func_020061E4(0x76c);
        func_021BE448(p);
        break;
    }
}

void func_021BE21C(char *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        ((struct Obj00021 *)p)->f3D0 = 1;
        func_021BF704(p);
        func_021BF728(p);
        func_021BFC60(p);
        func_021BE9B8((u8 *)p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF3B4(p);
        func_021BF38C(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BEF98(p);
        func_021BED10((u8 *)p, 0);
        func_021BED10((u8 *)p, 1);
        func_021BEC64(p);
        func_021C1184(func_021BF77C(p), 1);
        func_021C1178(func_021BF77C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (((struct Obj00021 *)p)->f28 >= 0x3c) {
                func_021BE4E0(p);
                return;
            }
            func_020061E4(0x76b);
        }
        break;
    case 2:
        ((struct Obj00021 *)p)->f3D0 = 0;
        func_021BEC0C(p);
        func_021C1184(func_021BF77C(p), 0);
        func_021BF08C(p);
        func_021BE934(p);
        func_021BF3B4(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BF4AC(p);
        func_021BF47C(p);
        func_020061E4(0x76c);
        func_021BE448(p);
        break;
    }
}

/*
 * Same two-case entry with func_021BE90C() and the ARM9 query func_0204E804().
 *
 * Addresses are Black-image addresses.
 */
void func_021BE33C(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BE90C();
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_0204E804() == 0) {
    func_021BE448((void *)a0);
    }
    break;
    }
}

/*
 * Calls func_021BE448() while func_021BE468() is below the record's +0x28
 * count.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE36C(u32 a0)
{
    if (func_021BE468((void *)a0) < ((struct Obj25897 *)(((u8*)a0)))->f28) {
    func_021BE448((void *)a0);
    }
}

void func_021BE384(u8 *a0)
{
    func_021C08A8((int *)a0);
    func_021C085C((int *)a0);
    func_021C09E0(*(u32 *)&((struct Obj00021 *)((u8*)a0))->f0);
    func_021C09EC(*(u32 *)&((struct Obj00021 *)((u8*)a0))->f0);
    func_021C08F0((u8 *)a0);
    func_021BFF5C((int *)a0);
    func_021BFED4(a0);
    func_021BFC28((char *)a0);
    func_021C0800((u32)a0);
    func_021C06AC((int *)a0);
    func_021C0794((int *)a0);
    func_021C06E0((u8 *)a0);
    func_021C0494((int *)a0);
    func_021C03D0((int *)a0);
    func_021C02A8((u32)a0);
    func_021C0358((u32)a0);
    func_021C0230((int *)a0);
    func_021C018C(a0);
    func_021C0170(a0);
    func_021C0114(a0);
    func_021C00F8(a0);
    func_021C0084(a0);
    func_021BFBD0((u8 *)a0);
    func_021BFBA0((int *)a0);
    func_021BFB54((u8 *)a0);
    func_021BE460((void *)a0, 0);
    func_021BE498((u8 *)a0, 13);
    func_021BE448((void *)a0);
    func_021C0968((unsigned char *)a0);
    *(u32 *)&((struct Obj00021 *)(((u8*)a0)))->f3C4 = 0;
    ((struct Obj00021 *)(((u8*)a0)))->f3E0 = 1;
}


void func_021BE448(void *p)
{
    ((struct Obj25898 *)p)->f3DC = 1;
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09C4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE454(u8 *a0, u32 a1)
{
    func_021C09C4(*(u8 * *)&((struct Obj25899 *)a0)->f0, a1);
}


void func_021BE460(void *p, u32 v)
{
    ((struct Obj25900 *)p)->f3E4 = v;
}


u32 func_021BE468(void *p)
{
    return ((struct Obj25901 *)p)->f2C;
}

/*
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE46C(u8 *a0)
{
    u32 v = ((struct Obj25902 *)a0)->f0;
    u32 a = func_021C09C8((void *)v);
    u32 b = func_021C09CC((void *)v);
    if (a != 0 && b == 0) {
    return 3;
    }
    return 2;
}


/*
 * Increment the u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE490(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x28);
    *c += 1;
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to func_021C0E4C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE498(u8 *a0, u32 a1)
{
    func_021C0E4C((u32)(((struct Obj25904 *)a0)->f1C), a1);
}
