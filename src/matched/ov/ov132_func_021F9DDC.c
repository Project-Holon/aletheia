/*
 * unit: no
 * function: STA_ACTING_GetCharSlot
 * address: 0x021F9DDC
 * packet: pkt_ov132_021F9DDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void *STA_ACTING_GetCharSlot(void *p,u8 i){return *(void **)((u8 *)p+(u32)i*4+0x94);}
