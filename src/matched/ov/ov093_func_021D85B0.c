/*
 * function: HAND_TOKUSEI_GetPokeSpeed
 * address: 0x021D85B0
 * packet: pkt_ov093_021D85B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetStatRaw 0x021D58A8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_POKEPARAM_GetStatRaw(u8 *,int);
u16 HAND_TOKUSEI_GetPokeSpeed(u8 *p) { return BTL_POKEPARAM_GetStatRaw(p,12); }
