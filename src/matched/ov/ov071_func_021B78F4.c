/*
 * function: MONOLITH_TOOL_SLOT_SELECT_LoadGraphics
 * address: 0x021B78F4
 * packet: pkt_ov071_021B78F4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   MONOLITH_TOOL_DrawSlotCounts 0x021B7234 thumb ov071
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void MONOLITH_TOOL_DrawSlotCounts(void *,int,int);
extern void BG_SYS_PushTile(unsigned);
void MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(void *p, void **q) {func_020498F4(q[12],6,6,0,0,1,0x61);MONOLITH_TOOL_DrawSlotCounts(p,1,6);BG_SYS_PushTile(6);}
