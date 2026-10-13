/*
 * function: func_021B9B30, func_021B9B38
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
void func_021B9B30(void *a0) {CLACT_VBlankSystem();}
u32 func_021B9B38(const u32 *p) {return *p;}
