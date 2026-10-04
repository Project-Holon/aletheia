/*
 * function: func_021DC970
 * address:  0x021DC970
 * packet:   pkt_021DC970
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAB04  0x021EAB04  thumb  ov170
 *   func_020419E4  0x020419E4  arm
 *   func_0204A648  0x0204A648  arm
 *   func_02021D50  0x02021D50  thumb
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 */
#include "../include/Obj12145.h"
typedef unsigned char u8;
typedef unsigned int u32;

struct S02021D50;
extern void func_021EAB04(unsigned char *w);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void func_02021D50(struct S02021D50 *p);
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];

void func_021DC970(u32 a, char *p)
{
    func_021EAB04((unsigned char *)(((struct Obj12145 *)p)->f2C));
    func_020419E4();
    func_0204A648();
    func_02021D50((struct S02021D50 *)(*(u32 *)(((struct Obj12145 *)p)->f2C + 0x6c)));
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3ff8) |= 1;
}
