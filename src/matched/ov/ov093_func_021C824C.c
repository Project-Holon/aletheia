/*
 * function: BTL_SERVER_FLOW_CanUseHeldItem
 * address: 0x021C824C
 * packet: pkt_ov093_021C824C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_FIELD_IsStaticSlotInUse 0x021EF948 thumb ov093
 */
#include "../include/Obj21115.h"
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_FIELD_IsStaticSlotInUse(int);
int BTL_SERVER_FLOW_CanUseHeldItem(u8 *p, int v) { void *m; m=BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj21115 *)p)->f8,v); if(BTL_POKEPARAM_GetValue(m,17)==103) return 0; if(BTL_POKEPARAM_HasSick(m,19)) return 0; if(BTL_FIELD_IsStaticSlotInUse(7)==0) return 1; return 0; }
