/*
 * function: func_021FBC1C
 * address:  0x021FBC1C
 * packet:   pkt_021FBC1C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9660  0x021F9660  thumb  ov135
 *   g_022033FC  0x022033FC  data  ov135

 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0x19/0x15 code from the table.
 */
#include "../include/Obj00098.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
struct Obj;
extern void func_0204B3DC(struct Obj *v, unsigned int k);
extern void func_021F9660(u8 *p, u32 k);
extern void func_0201F868(void *p);
extern u8 g_022033FC[];

int func_021FBC1C(u8 *p)
{
    if (func_0204B98C((struct Actor *)(*(u32 *)&((struct Obj00098 *)p)->f8)) != 0) {
        return -1;
    }
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 0x3);
    func_0201F868((void *)(*(u32 *)&((struct Obj00098 *)p)->f30));
    *(u32 *)&((struct Obj00098 *)p)->f48 = (*(s32 *)(g_022033FC + ((struct Obj00098 *)p)->f38 * 8) != 1) ? 0x19 : 0x15;
    return -1;
}
