/*
 * function: ZUKAN_SEARCH_SCREEN_VBlank
 * address: 0x021BC2D8
 * packet: pkt_ov211_021BC2D8
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 * lever: the linker region symbol cast to unsigned keeps base and 0x3FF8 as separate pooled values; literal 02FE3FF8 was 24 bytes, 14 mismatches.
 */
extern void BG_SYS_Update(void);extern unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];
void ZUKAN_SEARCH_SCREEN_VBlank(void){BG_SYS_Update();*(unsigned *)((unsigned)SDK_AUTOLOAD_MAIN_TWL_START+0x3FF8)|=1;}
