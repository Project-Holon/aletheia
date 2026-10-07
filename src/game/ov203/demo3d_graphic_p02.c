/*
 * file:     demo3d_graphic_p02.c
 * unit:     yes
 * function: func_021BE078, func_021BE07C, func_021BE084
 * address:  0x021BE078
 * region:   ov203
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
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
#include "../../matched/include/Obj14586.h"

struct Cfg;
struct Bank;
typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_020419E4(void);
extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
void func_021BE078(void *a0);
void func_021BE07C(void *a0);
void func_021BE084(unsigned char *p, int a, int b);

void func_021BE078(void *a0){}

void func_021BE07C(void *a0){func_020419E4();}


void func_021BE084(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021BFB60, a, b);
    ((struct Obj14586 *)p)->f0 = func_0204B100(0x20, 0, b);
    func_0204B270(((struct Obj14586 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
