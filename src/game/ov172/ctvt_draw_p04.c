/*
 * file:     ctvt_draw_p04.c
 * unit:     yes
 * function: func_021BD7D0, func_021BD820
 * address:  0x021BD7D0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */
#include "../../matched/include/Obj24105.h"

struct Bank;
struct BgTemplate;
typedef unsigned int u32;

extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(u32 p);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32 which);
extern void func_020409B4(u32 index);
void func_021BD7D0(void *a0);
void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type);


/*
 * Masks the display control word down to 0xffff1fff, hands the +0x1ac handle to
 * the two release probes and then drops priorities 7,6,5,4,1,0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD7D0(void *a0)
{
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    func_0204A5AC(func_0204B1CC((struct Bank *)(((struct Obj24105 *)a0)->f1AC)));
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(1);
    func_020403F4(0);
    func_020450C8();
    func_0203F9B4();
}


void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type)
{
    func_0203FCA0(bgId, tmpl, type);
    func_02040588(bgId, 1);
    func_020414AC(bgId);
    func_020409B4(bgId);
}
