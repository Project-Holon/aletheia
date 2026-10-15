/*
 * function: STA_ACT_LIGHT_UpdateBillboard
 * address: 0x021F7160
 * packet: pkt_ov112_021F7160
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 * symbols:
 *   STA_ACT_LIGHT_CalcSpriteXform 0x021F7204 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void STA_ACT_LIGHT_CalcSpriteXform(u8 *,u8 *);
void STA_ACT_LIGHT_UpdateBillboard(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) STA_ACT_LIGHT_CalcSpriteXform(p,p+20+i*264); }
