/*
 * file:     fld3d_ci_p13.c
 * unit:     yes
 * function: func_021C3400, func_021C340C
 * address:  0x021C3400
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
 *   func_0200BCA0  0x0200BCA0  thumb
 *   func_0200BCB8  0x0200BCB8  thumb
 */
#include "../../matched/include/Obj18300.h"
#include "../../matched/include/Obj18301.h"

struct Obj11233;
typedef int s32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0200BCA0(struct Obj11233 *p);
extern u32 func_0200BCB8(u32, u32, u32, u32);
int func_021C3400(void *a);
int func_021C340C(u32 a, u32 b, u32 c, u32 d);


/*
 * Unlabelled leaf in ov021 (the listing prints it as a `.word` run at
 * 0x021C3400, next to ov010's field-VM code); ov010's func_0215CE98 reaches
 * it across the overlay pair.  Eight-byte thunk: load [a+8] and tail-call
 * the ARM9 helper.
 */
int func_021C3400(void *a)
{
    return func_0200BCA0((struct Obj11233 *)(((struct Obj18300 *)a)->f8));
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C340C(u32 a, u32 b, u32 c, u32 d)
{
return ((func_0200BCB8(((struct Obj18301 *)((u8 *)(a)))->f8, b, c, d) << 24) >> 24);
}
