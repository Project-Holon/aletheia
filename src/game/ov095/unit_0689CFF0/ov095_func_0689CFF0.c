/*
 * function: func_0689CFF0
 * address: 0x0689CFF0
 * packet: pkt_ov095_0689CFF0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0689D014 0x0689D014 arm ov095
 */
#include "../../../matched/include/Obj21912.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_0689D014(void *, int, u32);
void func_0689CFF0(void *p)
{
    u32 i;
    func_0689D014(p, 0, 964);
    ((struct Obj21912 *)p)->f0 = 0;
    for (i = 0; i < 120; i++) {
        *(u16 *)((u32)p + i * 8 + 8) = 0;
    }
}
