/*
 * function: PMS_SELECT_GRAPHIC_GetSceneActorUnit
 * address:  0x021C1718
 * packet:   pkt_ov110_021C1718
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching PMS_SELECT_GRAPHIC_ReadPointer in ov110 (pkt_ov110_021C1848).
 *
 * symbols:
 *   PMS_SELECT_GRAPHIC_ReadPointer  0x021C1848  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 PMS_SELECT_GRAPHIC_ReadPointer(u32 *p);
u32 PMS_SELECT_GRAPHIC_GetSceneActorUnit(u8 *p) { return PMS_SELECT_GRAPHIC_ReadPointer((u32 *)(p + 4)); }
