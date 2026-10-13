/*
 * function: PMS_SELECT_GRAPHIC_SceneTask
 * address: 0x021C1724
 * packet: pkt_ov110_021C1724
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_SELECT_GRAPHIC_TransferSceneBgs 0x021C17D4 thumb ov110
 *   PMS_SELECT_GRAPHIC_VBlankSceneActors 0x021C1840 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMS_SELECT_GRAPHIC_TransferSceneBgs(void *);
extern void PMS_SELECT_GRAPHIC_VBlankSceneActors(void *);
void PMS_SELECT_GRAPHIC_SceneTask(int a,u8 *p) { PMS_SELECT_GRAPHIC_TransferSceneBgs(p); PMS_SELECT_GRAPHIC_VBlankSceneActors(p+4); }
