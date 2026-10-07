/*
 * file:     field_wfbc_p18.c
 * unit:     yes
 * function: func_02194A24, func_02194A34, func_02194A48
 * address:  0x02194A24
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
 *   func_02195E54  0x02195E54  thumb  ov021
 *   func_02195E90  0x02195E90  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 */
#include "../../matched/include/Obj17941.h"

struct FrameStyle;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02195E54(u32, u32, u32, u32);
extern u32 func_020409B4(u32);
extern void func_02195E90(struct FrameStyle *style, void *win);
extern u32 func_020452E8(struct Descriptor *d);
int func_02194A24(u32 a, u32 b, u32 c, u32 d);
int func_02194A34(u32 a, u32 b);
u32 func_02194A48(u32 a, struct Descriptor *b);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02194A24(u32 a, u32 b, u32 c, u32 d)
{
return func_02195E54(a, b, ((c << 24) >> 24), 0);
}


int func_02194A34(u32 a, u32 b)
{
func_02195E90((struct FrameStyle *)a, (void *)b);
return func_020409B4(((((struct Obj17941 *)((u8 *)(a)))->f10 << 24) >> 24));
}


u32 func_02194A48(u32 a, struct Descriptor *b)
{
func_02195E90((struct FrameStyle *)a, (void *)b);
return func_020452E8(b);
}
