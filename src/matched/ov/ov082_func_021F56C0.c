/*
 * function: FLD_FACEUP_SaveBgPriorities
 * address: 0x021F56C0
 * packet: pkt_ov082_021F56C0
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Get 0x020416D4 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 BG_SYS_Get(u32 layer);
void FLD_FACEUP_SaveBgPriorities(u8 *p) { int i; for(i=0;i<4;i++) p[i]=BG_SYS_Get((u8)i); }
