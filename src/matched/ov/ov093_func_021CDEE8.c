/*
 * function: BTL_CLIENT_HasMonParamDropped
 * address: 0x021CDEE8
 * packet: pkt_ov093_021CDEE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_CLIENT_GetLeadPartyMon 0x021CDF1C thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj04362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *BTL_CLIENT_GetLeadPartyMon(u8 *);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 _u32_div_f(u32,u32);
u32 BTL_CLIENT_HasMonParamDropped(u8 *p) { void *a; u32 now,old; a=BTL_CLIENT_GetLeadPartyMon(p); if(a) { now=BTL_POKEPARAM_GetValue(a,13); old=((struct Obj04362 *)p)->f19C; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }
