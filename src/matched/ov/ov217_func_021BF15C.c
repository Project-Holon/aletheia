/*
 * function: func_021BF15C
 * address:  0x021BF15C
 * packet:   pkt_ov217_021BF15C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BF7F4 0x021BF7F4 thumb ov217
 *   func_021BF854 0x021BF854 thumb ov217
 *   func_021C0FF8 0x021C0FF8 thumb ov217
 *   func_021C0F78 0x021C0F78 thumb ov217
 *   func_021C11C8 0x021C11C8 thumb ov217
 *   func_021C11DC 0x021C11DC thumb ov217
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 *func_021BF76C(void *p);
extern u32 func_021BF810(void *p);
extern u32 func_021BF7F4(void *p);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern u32 func_021BF854(char *p);
extern void func_021C0FF8(u8 *p, int visible);
extern void func_021C0F78(u8 *p, struct U16Vec *text);
extern u8 func_021C11C8(u8 *p, u8 key);
extern u8 func_021C11DC(u8 *p, u8 key);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EE0C(void *a, u32 b, void *c, u32 d, u32 e, u32 f);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021BF15C(char *p)
{
    u32 t = ((struct Obj00021 *)p)->f354;
    u8 *o = func_021BF76C(p);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (((struct Obj00021 *)p)->f3C8 == 0 || ((struct Obj00021 *)p)->f3D0 == 1) {
        func_021C0FF8((u8 *)t, 0);
        return;
    }
    if (func_021BF810(p) == 0) {
        func_021C0FF8((u8 *)t, 0);
        return;
    }
    k = func_021BF7F4(p);
    a = func_021C11C8(o, (u8)k);

    b = func_021BF854(p);
    c = func_021C11DC(o, (u8)k);
    x = func_02045EC0(((struct Obj00021 *)p)->fC, 0xd);
    y = func_02045EC0(((struct Obj00021 *)p)->f14, k);
    z = func_020457B0(0x80, ((struct Obj00021 *)p)->f4);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 0, a + 1, 2, 1, 1);
    func_0201EE0C(((struct Obj00021 *)p)->f18, 1, y, 0, 1, 2);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 2, b, 5, 1, 1);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 3, c, 3, 1, 1);
    func_0201F250(((struct Obj00021 *)p)->f18, z, x);
    func_021C0F78((u8 *)t, z);
    func_021C0FF8((u8 *)t, 1);
    func_02045808(x);
    func_02045808(z);
    func_02045808(y);
}
