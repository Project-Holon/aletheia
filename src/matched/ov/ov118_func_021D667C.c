/*
 * function: func_021D667C
 * address:  0x021D667C
 * packet:   pkt_021D667C
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03771.h"
#include "../include/Obj22686.h"

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);

void func_021D667C(void *p)
{
    void *h = func_020490F4(0x67, ((struct Obj03771 *)p)->f5F4);
    ((struct Obj03771 *)p)->f8A8 = func_0204A6C8(h, 2, 0, 0, ((struct Obj03771 *)p)->f5F4);
    ((struct Obj03771 *)p)->f88C = func_0204AC18(h, 3, 0, 0xE0, 0, 1, ((struct Obj03771 *)p)->f5F4);
    ((struct Obj03771 *)p)->f8BC = func_0204AF28(h, 1, 0, ((struct Obj03771 *)p)->f5F4);
    func_02049238(h);
    ((struct Obj22686 *)((char *)((struct Obj03771 *)p)->fC))->fB0 = 0;
}
