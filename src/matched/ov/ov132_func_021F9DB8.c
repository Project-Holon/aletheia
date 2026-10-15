/*
 * unit: no
 * function: STA_ACTING_SetSlot
 * address: 0x021F9DB8
 * packet: pkt_ov132_021F9DB8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void STA_ACTING_SetSlot(void *p,void *v,u32 i){*(void **)((u8 *)p+i*4+0x58)=v;}
