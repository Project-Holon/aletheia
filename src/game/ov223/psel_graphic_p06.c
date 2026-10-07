/*
 * file:     psel_graphic_p06.c
 * unit:     yes
 * function: func_021BC5E8, func_021BC5F0, func_021BC630
 * address:  0x021BC5E8
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_021BC944     0x021BC944  data  a4
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */
#include "../../matched/include/Obj26103.h"

struct Bank;
struct Cfg;
typedef unsigned char  u8;

typedef unsigned int   u32;

extern void func_020419E4(void);
extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021BC5E8(void *a0);
void func_021BC5F0(int *out, int a, int b);
void func_021BC630(char *p);
extern int d_021BC944;

void func_021BC5E8(void *a0){func_020419E4();}


void func_021BC5F0(int *out, int a, int b)
{
    func_02082BCC(out, 0, 4);
    func_0204A48C((const struct Cfg *)(&d_021BC944), a, b);
    *out = (int)func_0204B100(0x80, 0, b);
    func_0204B270((void *)*out);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BC630(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26103 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}
