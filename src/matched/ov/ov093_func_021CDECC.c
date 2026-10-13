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
 *   func_021CDF1C 0x021CDF1C thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
#include "../include/Obj04362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021CDF1C(u8 *);
extern int func_021D59B4(u8 *p, int k);
void BTL_CLIENT_StoreMonParam(u8 *p) { void *a; a=func_021CDF1C(p); if(a) ((struct Obj04362 *)p)->f19C=func_021D59B4(a,13); }
