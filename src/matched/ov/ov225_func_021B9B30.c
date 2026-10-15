/*
 * function: MANUAL_GRAPHIC_VBlankClactUnit, MANUAL_GRAPHIC_GetUnitHandle
 * address: 0x021B9B30
 * packet: pkt_ov225_021B9B30
 * region: ov225
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void MANUAL_GRAPHIC_VBlankClactUnit(void *a0) {CLACT_VBlankSystem();}
u32 MANUAL_GRAPHIC_GetUnitHandle(const u32 *p) {return *p;}
