/*
 * file:     field_3dbg_p06.c
 * unit:     yes
 * function: func_021A1590, func_021A15A4, func_021A15D4
 * address:  0x021A1590
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
 *   func_021EFF2C  0x021EFF2C  thumb  ov035
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_23      0x00000023  data
 *   func_02030734  0x02030734  arm
 *   d_021DDE5C     0x021DDE5C  data
 *   func_021A1780  0x021A1780  thumb  ov021
 *   func_021A1750  0x021A1750  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj06005.h"
#include "../../matched/include/Obj07489.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed char    s8;

extern void func_021EFF2C(char *p);
extern void func_02034A5C(int handle);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(u32);
extern int func_021A1750(u32 a);
extern u32 func_021A1780(u8 *p);
void func_021A1590(u32 *p);
u8 *func_021A15A4(u8 *p, u32 heap);
int func_021A15D4(u32 a);
extern unsigned char abs_id_23[];
extern char d_021DDE5C[];


/*
 * Addresses are Black-image addresses.
 */
void func_021A1590(u32 *p)
{
    func_021EFF2C((char *)p[8]);
    func_02034A5C((int)abs_id_23);
}


u8 *func_021A15A4(u8 *p, u32 heap)
{
    u8 *q = (u8 *)func_02030734((u16)heap, 0x70, 1, d_021DDE5C, 0x95);
    ((struct Obj06005 *)q)->f0 = ((struct Obj07489 *)p)->f0;
    ((struct Obj06005 *)q)->f2 = ((struct Obj07489 *)p)->f2;
    ((struct Obj06005 *)q)->f4 = ((struct Obj07489 *)p)->f4;
    q[0x1e] = p[8];
    ((struct Obj06005 *)q)->f8 = 1;
    return q;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A15D4(u32 a)
{
if (func_021A1780((u8 *)(a + 32)) != 0) {
    func_021A1750((a + 32));
}
return func_020307B0(a);
}
