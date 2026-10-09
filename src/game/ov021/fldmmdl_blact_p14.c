/*
 * file:     fldmmdl_blact_p14.c
 * unit:     yes
 * function: func_0219EFFC, func_0219F018, func_0219F01C, func_0219F030, func_0219F048, func_0219F04C, func_0219F050, func_0219F054
 * address:  0x0219EFFC
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
 *   func_020307B0  0x020307B0  arm
 *   func_0219EF14  0x0219EF14  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 */
#include "../../matched/include/Obj09178.h"

struct Desc;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_020307B0(void *p);
extern u32 func_0219EF14(u32);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
int func_0219EFFC(u32 a);
u8 *func_0219F018(u8 *p);
int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
int func_0219F030(void *a, u32 b, u32 c, u32 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EFFC(u32 a)
{
if (((struct Obj09178 *)((u8 *)(a)))->f0 != 0) {
    func_020307B0((void *)(((struct Obj09178 *)((u8 *)(a)))->f0));
    ((struct Obj09178 *)((u8 *)(a)))->f0 = 0;
}
return func_0219EF14((a + 8));
}


/*
 * Returns the object pointer advanced by 0x8 bytes.
 */
u8 *func_0219F018(u8 *p)
{
    return p + 0x8;
}


int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id)
{
return (int)func_02158768(a, ((c << 16) >> 16), e1, *(u16 *)((u8 *)((u8 *)&e1) + 4));
}


int func_0219F030(void *a, u32 b, u32 c, u32 d)
{
func_0216DAC8((unsigned int *)a, 1);
return (int)func_0216D568(a, (1 << 15));
}

void func_0219F048(void)
{
}

void func_0219F04C(void)
{
}

void func_0219F050(void)
{
}

void func_0219F054(void)
{
}
