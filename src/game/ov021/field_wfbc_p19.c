/*
 * file:     field_wfbc_p19.c
 * unit:     yes
 * function: func_02194A58, func_02194A74, func_02194A84, func_02194A94
 * address:  0x02194A58
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
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 */
#include "../../matched/include/Obj02343.h"
#include "../../matched/include/Obj17942.h"

struct Descriptor;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 pad[0x10]; u32 x10; u8 x14; u8 x15; } Obj;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
int func_02194A58(u32 a);
int func_02194A74(u32 a);
int func_02194A84(u16 *p, int i);
u32 func_02194A94(Obj *a, u32 b, u32 c, u32 d, u8 e);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02194A58(u32 a)
{
((struct Obj02343 *)((u8 *)(a)))->f0 = 0;
((struct Obj02343 *)((u8 *)(a)))->f8 = 0;
((struct Obj02343 *)((u8 *)(a)))->f2C = 0;
((struct Obj02343 *)((u8 *)(a)))->f2E = 0;
((struct Obj02343 *)((u8 *)(a)))->f30 = 0;
((struct Obj02343 *)((u8 *)(a)))->f32 = 0;
((struct Obj02343 *)((u8 *)(a)))->f34 = 0;
((struct Obj02343 *)((u8 *)(a)))->f36 = 0;
((struct Obj02343 *)((u8 *)(a)))->f38 = 0;
((struct Obj02343 *)((u8 *)(a)))->f3A = 0;
((struct Obj02343 *)((u8 *)(a)))->f3C = 0;
return a;
}


int func_02194A74(u32 a)
{
if (((struct Obj17942 *)((u8 *)(a)))->f0 == 0) {
    return 1;
}
return 0;
}


/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): predicate
 * on a u16 field.  Listing bytes 00 88 04 28 01 D1 01 20 70 47 00 20 70 47.
 *
 * Addresses are Black-image addresses.
 */
int func_02194A84(u16 *p, int i)
{
    return *p == 4;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_02194A94(Obj *a, u32 b, u32 c, u32 d, u8 e)
{
    u32 w;

    w = func_020450F0((u8)a->x10, b, c, d, e, a->x15, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w)), 15);
    func_02045334((struct Descriptor *)w);
    return w;
}
