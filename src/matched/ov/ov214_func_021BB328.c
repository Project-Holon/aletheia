/*
 * function: func_021BB328
 * address: 0x021BB328
 * packet: pkt_ov214_021BB328
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   records 0x021BB5B8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 records[];
extern void func_020403F4(u8),func_020450C8(void),func_0203F9B4(void),func_02082BCC(void *,u32,u32);
void func_021BB328(void *p) { u32 i;for(i=0;i<3;i++)func_020403F4(*(u32 *)(records+i*44));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4); }
