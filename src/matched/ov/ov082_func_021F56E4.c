/*
 * function: FLD_FACEUP_RestoreBgPriorities
 * address: 0x021F56E4
 * packet: pkt_ov082_021F56E4
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 */
typedef unsigned char u8;
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
void FLD_FACEUP_RestoreBgPriorities(u8 *p) { int i; for(i=0;i<4;i++) BG_SYS_SetVisibleLayer((u8)i,p[i]); }
