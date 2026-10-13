/*
 * function: PMS_SELECT_GRAPHIC_UpdateScene
 * address: 0x021C1704
 * packet: pkt_ov110_021C1704
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_SELECT_GRAPHIC_DrawSceneActors 0x021C1838 thumb ov110
 *   PMS_SELECT_GRAPHIC_UpdateSceneNothing 0x021C17D0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMS_SELECT_GRAPHIC_DrawSceneActors(void *);
extern void PMS_SELECT_GRAPHIC_UpdateSceneNothing(void *);
void PMS_SELECT_GRAPHIC_UpdateScene(u8 *p) { PMS_SELECT_GRAPHIC_DrawSceneActors(p+4); PMS_SELECT_GRAPHIC_UpdateSceneNothing(p); }
