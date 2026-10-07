/*
 * file:     field_msgbg_p54.c
 * unit:     yes
 * function: func_021905C8, func_02190604, func_0219061C, func_02190620
 * address:  0x021905C8
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
 *   func_0201C724  0x0201C724  thumb  arm9
 *   func_02045770  0x02045770  arm  arm9
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../../matched/include/Obj12064.h"

struct Descriptor;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_021905C8;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef short          s16_02190604;

typedef signed short   s16_02190620;

typedef signed char    s8;

extern void *func_02045770(struct Descriptor *a);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020409B4(u32);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 func_02045730(struct Descriptor *p);
void func_021905C8(Slot *s, int x, int y, u32 z, u16 w, u32 v);
void func_02190604(Slot *s, int x, int y, u32 z, u16 w);
u32 func_0219061C(u32 *p);
int func_02190620(u32 a);


/*
 * Addresses are Black-image addresses.
 */
void func_021905C8(Slot *s, int x, int y, u32 z, u16 w, u32 v)
{
    u32 t;

    t = s->f0c;
    func_0201C724((void *)t, (u32)func_02045770((struct Descriptor *)s->f1c), (s16_021905C8)x, (s16_021905C8)y, z, v, w);
    s->f20 = 1;
}


void func_02190604(Slot *s, int x, int y, u32 z, u16 w)
{
    func_021905C8(s, x, y, z, w, s->f08);
}


/*
 * Unlabelled leaf getter, callee of the thunk at 0x0219077C.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219061C(u32 *p)
{
    return p[1];
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02190620(u32 a)
{
func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj12064 *)((u8 *)(a)))->f14)), 255);
return func_020409B4(func_02045730((struct Descriptor *)(((struct Obj12064 *)((u8 *)(a)))->f14)));
}
