/*
 * function: func_021B8B24
 * address:  0x021B8B24
 * packet:   pkt_ov070_021B8B24
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202E940  0x0202E940  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0202E9AC  0x0202E9AC  thumb
 *   func_02049238  0x02049238  arm
 */
#include "../include/Obj07690.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct CodeIn;

extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
typedef unsigned char  u8;
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void func_02049238(void *arc);

void func_021B8B24(int p)
{
    void *h;
    *(struct CodeIn * *)&((struct Obj07690 *)p)->f850 =
        func_0202E940(0x10, 0x10, 0xFFFE, ((struct Obj07690 *)p)->f544);
    h = func_020490F4(0x58, ((struct Obj07690 *)p)->f544);
    func_0202E9AC(*(struct CodeIn * *)&((struct Obj07690 *)p)->f850, h, 0x15, 0x10, 0x20);
    func_02049238(h);
}
