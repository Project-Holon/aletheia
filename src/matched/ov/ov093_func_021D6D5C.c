/*
 * function: BTL_POKEPARAM_SetSubstituteHp
 * address: 0x021D6D5C
 * packet: pkt_ov093_021D6D5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_CureSick 0x021D6238 thumb ov093
 */
#include "../include/Obj21239.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilSlots;
extern void BTL_POKEPARAM_CureSick(struct UtilSlots *,int);
void BTL_POKEPARAM_SetSubstituteHp(u8 *p,u16 n) { ((struct Obj21239 *)p)->f1F2=n; BTL_POKEPARAM_CureSick((struct UtilSlots *)p,8); }
