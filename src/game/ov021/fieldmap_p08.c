/*
 * file:     fieldmap_p08.c
 * unit:     yes
 * function: func_02188D50, func_02188D58, func_02188D5C, func_02188DA0
 * address:  0x02188D50
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
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02040E78  0x02040E78  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   d_021D3620     0x021D3620  data
 *   func_0203FC28  0x0203FC28  arm
 */
#include "../../matched/include/Obj17883.h"
#include "../../matched/include/Obj17884.h"

#define REG_DISPCNT (*(volatile u32 *)0x04000000)
struct DispConfig;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_0203F8F4(u16 heap);
extern void func_02040E78(u32 a, void *b, u32 c, u32 d);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_0203FC28(struct DispConfig *cfg);
void *func_02188D50(u8 *p);
u32 func_02188D58(u8 *p);
void func_02188D5C(u16 *p);
void func_02188DA0(void);
extern u16 d_021D3620[];


/*
 * Loads the 32-bit word at byte +0x128 of the object.
 */
void *func_02188D50(u8 *p)
{
    return ((struct Obj17883 *)p)->f128;
}


/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_02188D58(u8 *p)
{
    return ((struct Obj17884 *)p)->fC;
}


void func_02188D5C(u16 *p)
{
    func_0203F8F4(p[0]);
    func_02040E78(0, d_021D3620, 0x20, 0);
    func_02040E78(4, d_021D3620, 0x20, 0);
    func_0204363C(1);
    func_0204361C();
    REG_DISPCNT &= ~0xE000;
}


/*
 * Tail call with a fixed data pointer argument.
 *
 * Addresses are Black-image addresses.
 */
void func_02188DA0(void)
{
    func_0203FC28((struct DispConfig *)0x021D35F4);
}
