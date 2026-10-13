/*
 * function: WIH_DWC_TickTimers
 * address:  0x02010498
 * packet:   pkt_0201045C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *           function_starts.txt line 337 seeds this leaf at 0x0201049C (4 bytes
 *           too high); the real prologue and byte-exact fit are at 0x02010498,
 *           per docs/notes/unit_0201045C.c.txt.
 * blocked:  +005C ABS32 gWihDwc : unresolved: no address for 'gWihDwc':
 *           not in the symbols: block, not an address-bearing name, not in
 *           layout/symbols_sdk.json
 * symbols:
 *   gWihDwc     0x021461E0  data
 */
#include "../include/Obj01818.h"
#include "../include/G_WihCtx.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct WihCtx gWihDwc;
extern void func_02082D44(u8 *p, u8 *rec);

void WIH_DWC_TickTimers(void)
{
    u8 *o = (*(u8 * *)&gWihDwc);

    if (o != 0 && ((struct Obj01818 *)o)->f30C != 0)
        return;
    if (o == 0)
        return;
    if (((struct Obj01818 *)o)->f318 > 0)
        ((struct Obj01818 *)o)->f318 = ((struct Obj01818 *)o)->f318 - 1;
    o = (*(u8 * *)&gWihDwc);
    if (((struct Obj01818 *)o)->f31C > 0)
        ((struct Obj01818 *)o)->f31C = ((struct Obj01818 *)o)->f31C - 1;
    o = (*(u8 * *)&gWihDwc);
    if (((struct Obj01818 *)o)->f320 > 0)
        ((struct Obj01818 *)o)->f320 = ((struct Obj01818 *)o)->f320 - 1;
    o = (*(u8 * *)&gWihDwc);
    if (((struct Obj01818 *)o)->f324 > 0)
        ((struct Obj01818 *)o)->f324 = ((struct Obj01818 *)o)->f324 - 1;
}
