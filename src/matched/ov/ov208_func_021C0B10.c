/*
 * function: ov208_func_021C0B10
 * address:  0x021C0B10
 * packet:   pkt_ov208_021C0B10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 */
#include "../include/Obj14654.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);

void ov208_func_021C0B10(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(7, *heap);
    ((struct Obj14654 *)p)->f54 = func_0204ACEC(h, func_0201BC3C(), 1, 0, *heap);
    ((struct Obj14654 *)p)->f58 = func_0204AF28(h, func_0201BC78(), func_0201BCEC(), *heap);
    func_02049238(h);
}
