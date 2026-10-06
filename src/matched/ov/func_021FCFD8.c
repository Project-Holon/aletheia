/*
 * function: func_021FCFD8
 * address:  0x021FCFD8
 * packet:   pkt_021FCFD8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *
 * The 0x12fc-field variant: opens the 0x60x0x48 handle, then only when
 * *(u32 *)(p + 0x12fc) == 0 adds the 0xf/0x23 pair through 49658/498F4 and
 * the second 49B40 window.  Both tests reload the same field.
 */
#include "../include/Obj00240.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);

void func_021FCFD8(u8 *p)
{
    void *h;

    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(4, 1, 2, 0, 0x48);
    h = func_020490F4(0x60, 0x48);
    func_02049658(h, 0x10, 1, 0, 0xc00, 1, 0x48);
    func_02049B68(h, 6, 0, 0, 0x60, 0x48);
    if (((struct Obj00240 *)p)->f12FC == 0) {
        func_02049658(h, 0xf, 6, 0, 0, 0, 0x48);
        func_020498F4(h, 0x23, 6, 0, 0, 0, 0x48);
    }
    func_02049238(h);
    if (((struct Obj00240 *)p)->f12FC == 0) {
        func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}
