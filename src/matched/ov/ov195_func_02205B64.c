/*
 * function: SHINKA_DEMO_GRAPHIC_UpdateSubBg
 * address: 0x02205B64
 * packet: pkt_ov195_02205B64
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void BG_SYS_Update(void);
void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *a0){BG_SYS_Update();}
