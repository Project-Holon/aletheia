/*
 * function: func_021F6178
 * address:  0x021F6178
 * packet:   pkt_021F6178
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4D50  0x021F4D50  thumb  ov135
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9

 * Create the resource, register the three 5d/5e/5f entries and latch state 0xa.
 */
#include "../include/Obj00448.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 BMP_MENUWORK_Create(u32 a, u32 b);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_021F4D50(u8 *p, u16 a, int count, int b);

int func_021F6178(u8 *p)
{
    *(u32 *)&((struct Obj00448 *)p)->fDE8 = BMP_MENUWORK_Create(3, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5d, 1, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5e, 2, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5f, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    ((struct Obj00448 *)p)->f28 = 0xa;
    return 2;
}
