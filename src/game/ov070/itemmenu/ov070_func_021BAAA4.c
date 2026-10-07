/*
 * function: func_021BAAA4
 * address:  0x021BAAA4
 * packet:   pkt_ov070_021BAAA4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_020499D4  0x020499D4  arm
 *   func_02049238  0x02049238  arm
 */
#include "../../../matched/include/Obj06176.h"

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);

void func_021BAAA4(int p, int mode)
{
    void *h = func_020490F4(0x58, ((struct Obj06176 *)p)->f544);

    if (mode != 2) {
        func_020499D4(h, 0x17, 5, 0, (u16)((struct Obj06176 *)p)->f800, 0, 0, ((struct Obj06176 *)p)->f544);
    } else {
        func_020499D4(h, 0x18, 5, 0, (u16)((struct Obj06176 *)p)->f800, 0, 0, ((struct Obj06176 *)p)->f544);
    }
    func_02049238(h);
}
