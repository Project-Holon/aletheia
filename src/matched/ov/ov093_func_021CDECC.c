/*
 * function: BTL_CLIENT_StoreMonParam
 * address: 0x021CDECC
 * packet: pkt_ov093_021CDECC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_CLIENT_GetLeadPartyMon 0x021CDF1C thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 */
#include "../include/Obj04362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *BTL_CLIENT_GetLeadPartyMon(u8 *);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
void BTL_CLIENT_StoreMonParam(u8 *p) { void *a; a=BTL_CLIENT_GetLeadPartyMon(p); if(a) ((struct Obj04362 *)p)->f19C=BTL_POKEPARAM_GetValue(a,13); }
