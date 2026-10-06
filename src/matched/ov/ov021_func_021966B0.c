/*
 * function: func_021966B0
 * address:  0x021966B0
 * packet:   pkt_ov021_021966B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 */
#include "../include/Obj00093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void func_02040588(u32 a, u32 b);

void func_021966B0(u8 *p, u32 a)
{
    void *h;

    h = func_020490F4(0x1D, ((struct Obj00093 *)p)->f10);
    func_02049990(h, a, 6, 0, (u16)((struct Obj00093 *)p)->f40, 0, 0, ((struct Obj00093 *)p)->f10);
    func_02049238(h);
    func_02040588(6, 1);
}
