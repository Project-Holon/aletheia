/*
 * file:     queue_p03.c
 * unit:     yes
 * function: func_021C09EC, func_021C09F8, func_021C09FC, func_021C0A04, func_021C0A38, func_021C0A54
 * address:  0x021C09EC
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
 *   func_021C0D6C  0x021C0D6C  thumb  ov217
 *   func_02082BCC  0x02082BCC  arm
 *   func_021C0AF8  0x021C0AF8  thumb  ov217
 *   func_021C0B8C  0x021C0B8C  thumb  ov217
 *   func_021C0BB4  0x021C0BB4  thumb  ov217
 *   func_021C0C38  0x021C0C38  thumb  ov217
 *   func_021C0CF0  0x021C0CF0  thumb  ov217
 */
#include "../../matched/include/Obj25982.h"
#include "../../matched/include/Obj25983.h"
#include "../../matched/include/Obj00791.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

extern void func_021C0D6C(u8 *p, u32 i);
extern void func_02082BCC(void *dst, int val, u32 n);
extern void func_021C0AF8(void *p);
extern void func_021C0B8C(void *p);
extern void func_021C0BB4(void *p);
extern void func_021C0C38(void *p);
extern void func_021C0CF0(void *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
void func_021C09EC(u32 a0);
u32 func_021C09F8(void *p);
void func_021C09FC(void *p);
void func_021C0A04(u8 *p);
u32 func_021C0A38(u32 a0);
u32 func_021C0A54(void *a0);


/*
 * Tail-call veneer: forwards arg(s) a0, 0 to func_021C0D6C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09EC(u32 a0)
{
    func_021C0D6C((u8 *)a0, 0);
}


/*
 * Field getter, u32 at +0x3c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C09F8(void *p)
{
    return ((struct Obj25982 *)p)->f3C;
}


/*
 * Set the u32 at +0x3c to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021C09FC(void *p)
{
    ((struct Obj25983 *)p)->f3C = 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C0A04(u8 *p)
{
    func_02082BCC(p, 0, 0x40);
    ((struct Obj00791 *)p)->f30 = 0;
    ((struct Obj00791 *)p)->f34 = 0;
    func_021C0AF8(p);
    func_021C0B8C(p);
    func_021C0BB4(p);
    func_021C0C38(p);
    func_021C0CF0(p);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0A38(u32 a0)
{
    return (u32)func_02030734(a0, 64, 0, (const char *)0x21C4020, 481);
}


u32 func_021C0A54(void *a0)
{
    return func_020307B0(a0);
}
