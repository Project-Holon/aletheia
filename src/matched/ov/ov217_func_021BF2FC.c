/*
 * function: func_021BF2FC
 * address:  0x021BF2FC
 * packet:   pkt_ov217_021BF2FC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021C0F78 0x021C0F78 thumb ov217
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF810(void *p);
extern void func_021C0F78(u32 a, void *b);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021BF2FC(char *p)
{
    u32 k;
    u32 x;
    void *a, *b;
    void *c;
    if (((struct Obj00021 *)p)->f3C8 != 0) {
        switch (((struct Obj00021 *)p)->f2CC) {
        case 0:
            k = 0xf;
            break;
        case 1:
            k = 0x11;
            break;
        }
    } else {
        switch (((struct Obj00021 *)p)->f2CC) {
        case 0:
            k = 0x10;
            break;
        case 1:
            k = 0x12;
            break;
        }
    }
    x = func_021BF810(p);
    c = ((struct Obj00021 *)p)->f18;
    a = func_02045EC0(((struct Obj00021 *)p)->fC, k);
    b = func_020457B0(0x80, ((struct Obj00021 *)p)->f4);
    func_0201EFA4(c, 0, x, 6, 1, 1);
    func_0201F250(c, b, a);
    func_021C0F78(((struct Obj00021 *)p)->f35C, b);
    func_02045808(a);
    func_02045808(b);
}
