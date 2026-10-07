/*
 * file:     field_wfbc_p24.c
 * unit:     yes
 * function: func_02195490, func_021954CC, func_02195530
 * address:  0x02195490
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
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048B60  0x02048B60  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049624  0x02049624  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   func_0207FA0C  0x0207FA0C  arm
 *   func_0207FA40  0x0207FA40  arm
 *   func_0207FADC  0x0207FADC  arm
 *   d_021DDA84     0x021DDA84  data  a4
 *   d_021DDAA4     0x021DDAA4  data  a4
 */
#include "../../matched/include/Obj05860.h"
#include "../../matched/include/Obj04218.h"
#include "../../matched/include/Obj12626.h"

struct Light;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02048AD0(u32);
extern u32 func_02048AFC(u32, u32, u32, u32);
extern u32 func_02048B20(u32, u32);
extern u32 func_02048B44(u32, u32);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_020414EC(u32 a);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0207F7A0();
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207F7FC(void *p, u32 off, u32 size);
extern void func_0207F9B4();
extern void func_0207FA0C();
extern void func_0207FA40(void *p, u32 off, u32 size);
extern void func_0207FADC();
int func_02195490(u32 a, u32 b, u32 c, u32 d);
u32 func_021954CC(u32 p, u8 *e);
void func_02195530(char *p);
extern u32 d_021DDA84[];
extern u32 d_021DDAA4[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02195490(u32 a, u32 b, u32 c, u32 d)
{
func_02048AFC(((struct Obj05860 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
func_02048B20(((struct Obj05860 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
func_02048B44(((struct Obj05860 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
func_02048B60((struct Light *)(((struct Obj05860 *)((u8 *)(a)))->f4), (const u32 *)(a + ((202 << 4) + 36)));
return func_02048AD0(((struct Obj05860 *)((u8 *)(a)))->f4);
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021954CC(u32 p, u8 *e)
{
    u32 k;

    func_020414EC(((struct Obj04218 *)e)->f10 & 0xFF);
    k = 0;
    switch (((struct Obj04218 *)e)->f10) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        k = 4;
        break;
    }
    func_02049B40(5, 0, k, e[0x14] << 5, 0x20, ((struct Obj04218 *)e)->f0);
    return func_02049624((void *)5, (void *)5, (void *)(((struct Obj04218 *)e)->f10), (void *)(((struct Obj04218 *)e)->fC), 0, 0, ((struct Obj04218 *)e)->f0);
}


void func_02195530(char *p)
{
    func_0207F7A0();
    DC_FlushRange(d_021DDA84, 0x20);
    func_0207F7FC(d_021DDA84, (u16)((struct Obj12626 *)p)->fCC8 << 3, 0x20);
    func_0207F9B4();
    func_0207FA0C();
    DC_FlushRange(d_021DDAA4, 0x20);
    func_0207FA40(d_021DDAA4, (u16)((struct Obj12626 *)p)->fCCC << 3, 0x20);
    func_0207FADC();
}
