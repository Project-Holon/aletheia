/*
 * function: ZKNSEARCH_MAIN_InitCursorMove
 * address: 0x021BFEAC
 * packet: pkt_ov210_021BFEAC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   ZKNSEARCH_MAIN_SetCursorTile 0x021BFF30 thumb ov210
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   d_021C0B60 0x021C0B60 data a4
 *   d_021C0B14 0x021C0B14 data a4
 */
#include "../include/Obj10923.h"
extern const unsigned d_021C0B60[], d_021C0B14[];
extern unsigned char func_020355C4(void);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
struct Struct_02025D1C;
extern struct Struct_02025CD0 *CURSOR_MOVE_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void ZKNSEARCH_MAIN_SetCursorTile(int, unsigned, unsigned);
extern void CURSOR_MOVE_EnableInput(struct Struct_02025D1C *obj);
void ZKNSEARCH_MAIN_InitCursorMove(char *ctx, int index)
{
    if (func_020355C4() == 1) {
        ((struct Obj10923 *)ctx)->f2B0 = CURSOR_MOVE_Create((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 0, index, 123);
    } else {
        ((struct Obj10923 *)ctx)->f2B0 = CURSOR_MOVE_Create((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 1, index, 123);
        ZKNSEARCH_MAIN_SetCursorTile((int)ctx, index, 3);
    }
    CURSOR_MOVE_EnableInput(((struct Obj10923 *)ctx)->f2B0);
}
