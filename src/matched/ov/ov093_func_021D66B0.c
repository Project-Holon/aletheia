/*
 * function: BTL_POKEPARAM_SetTypes
 * address: 0x021D66B0
 * packet: pkt_ov093_021D66B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTLV_CORE_GetHighByte 0x021E8CFC thumb ov093
 *   BTLV_CORE_GetLowByte 0x021E8D04 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTLV_CORE_GetHighByte(int);
extern int BTLV_CORE_GetLowByte(int x);
void BTL_POKEPARAM_SetTypes(u8 *p,int n) { p[0xf8]=BTLV_CORE_GetHighByte(n); p[0xf9]=BTLV_CORE_GetLowByte(n); }
