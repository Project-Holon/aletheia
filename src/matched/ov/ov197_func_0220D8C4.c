/*
 * function: B_BAG_MAIN_CreateCursor
 * address: 0x0220D8C4
 * packet: pkt_ov197_0220D8C4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   CURSOR_MOVE_SetMode 0x02025D24 thumb
 *   B_BAG_MAIN_LayoutCursor 0x0220D98C thumb ov197
 *   d_0220DF90 0x0220DF90 data a4
 *   d_0220DF9C 0x0220DF9C data a4
 */
#include "../include/Obj03347.h"
#include "../include/Obj25121.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
extern struct Struct_02025CD0 *CURSOR_MOVE_Create(u32, u32, u32, u32, u8, u16);
extern void CURSOR_MOVE_EnableInput(struct Struct_02025D1C *);
extern void CURSOR_MOVE_SetMode(struct Struct_02025D24 *);
extern void B_BAG_MAIN_LayoutCursor(u8 *, u32);
extern const u32 d_0220DF90[], d_0220DF9C[];
void B_BAG_MAIN_CreateCursor(u8 *p, u32 index, u32 value)
{
    *(struct Struct_02025CD0 * *)&((struct Obj03347 *)p)->f144 = CURSOR_MOVE_Create(d_0220DF9C[index], d_0220DF90[index], (u32)p, ((struct Obj03347 *)p)->f598, (u8)value, ((struct Obj25121 *)(*(u8 * *)&((struct Obj03347 *)p)->f0))->fC);
    CURSOR_MOVE_EnableInput(*(struct Struct_02025D1C * *)&((struct Obj03347 *)p)->f144);
    CURSOR_MOVE_SetMode(*(struct Struct_02025D24 * *)&((struct Obj03347 *)p)->f144);
    B_BAG_MAIN_LayoutCursor(p, value);
}
