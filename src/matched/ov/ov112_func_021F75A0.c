/*
 * function: STA_ACT_LIGHT_UpdateElem
 * address: 0x021F75A0
 * packet: pkt_ov112_021F75A0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 * symbols:
 *   STA_ACT_LIGHT_GetRenderHandle 0x021F8120 thumb ov112
 *   STA_ACT_LIGHT_CopyElemB 0x021F75D8 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int STA_ACT_LIGHT_GetRenderHandle(int a, u8 *p);
extern void STA_ACT_LIGHT_CopyElemB(u8 *,u8 *);
void STA_ACT_LIGHT_UpdateElem(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) { if(STA_ACT_LIGHT_GetRenderHandle((int)p,p+20+i*264)==1) STA_ACT_LIGHT_CopyElemB(p,p+20+i*264); } }
