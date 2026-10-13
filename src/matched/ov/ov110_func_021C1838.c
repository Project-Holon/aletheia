/*
 * function: PMS_SELECT_GRAPHIC_DrawSceneActors
 * address:  0x021C1838
 * packet:   pkt_ov110_021C1838
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void CLACT_DrawSystem(void);
void PMS_SELECT_GRAPHIC_DrawSceneActors(void *a0) { CLACT_DrawSystem(); }
