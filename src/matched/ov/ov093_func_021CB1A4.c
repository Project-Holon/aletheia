/*
 * function: BTL_SERVER_FLOW_GetPartnerPoke
 * address: 0x021CB1A4
 * packet: pkt_ov093_021CB1A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_MapPosForRule 0x021B8CB0 thumb ov093
 *   BTL_MAIN_GetSlotClientAndNth 0x021B8E28 thumb ov093
 *   BTL_SERVER_GetClientChecked 0x021BB85C thumb ov093
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 */
#include "../include/Obj09979.h"
typedef unsigned char u8;
struct Unk021B8CB0;
extern u8 BTL_MAIN_MapPosForRule(struct Unk021B8CB0 **p, u8 x);
extern void BTL_MAIN_GetSlotClientAndNth(u8 *, u8, u8 *, u8 *);
extern u8 *BTL_SERVER_GetClientChecked(u8 *, unsigned int);
typedef unsigned int   u32;
struct S2;
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
void *BTL_SERVER_FLOW_GetPartnerPoke(u8 *p, u8 n)
{
    u8 out[2];
    BTL_MAIN_GetSlotClientAndNth(*(u8 * *)&((struct Obj09979 *)p)->f4, BTL_MAIN_MapPosForRule(((struct Obj09979 *)p)->f4, n), out + 1, out);
    return (void *)BTL_SLOT_GetPoke(*(void **)(BTL_SERVER_GetClientChecked(*(u8 * *)&((struct Obj09979 *)p)->f0, out[1]) + 4), out[0]);
}
