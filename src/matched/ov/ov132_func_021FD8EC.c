/*
 * unit: yes
 * function: STA_NET_GetSlotValueByIndex, STA_NET_GetSlotWordByIndex
 * address: 0x021FD8EC
 * packet: pkt_ov132_021FD8EC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u8 STA_NET_GetSlotValueByIndex(char *p, int index) {return *(u8 *)((u32)p+index*0x30+0x72);}
u32 STA_NET_GetSlotWordByIndex(char *p,u32 index){return *(u32 *)((u32)p+index*0x30+0x80);}
