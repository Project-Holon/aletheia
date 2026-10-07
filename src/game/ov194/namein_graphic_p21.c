/*
 * file:     namein_graphic_p21.c
 * unit:     yes
 * function: func_021F4CA4, func_021F4CA8, func_021F4CB0, func_021F4CF0, func_021F4D0C
 * address:  0x021F4CA4
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
#include "../../matched/include/Obj14512.h"
#include "../../matched/include/Obj24928.h"

struct Bank;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_020419E4(void);
extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
void func_021F4CA4(u8 *a0);
void func_021F4CA8(u8 *a0);
void func_021F4CB0(unsigned char *p, int a, int b);
void func_021F4CF0(u8 *p);
void func_021F4D0C(u8 *a0);

void func_021F4CA4(u8 *a0) {}

void func_021F4CA8(u8 *a0) { func_020419E4(); }


void func_021F4CB0(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021F55B4, a, b);
    *(int *)&((struct Obj14512 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14512 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F4CF0(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj24928 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}

void func_021F4D0C(u8 *a0) { func_0204A600(); }
