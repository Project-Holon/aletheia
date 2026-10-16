/*
 * function: WORLDTRADE_BOX_CheckMonRestrictionB
 * address:  0x021F6C28
 * packet:   pkt_021F6C28
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb  arm9
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb  arm9
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 *

 *
 * Restart the channel: take a stamp, force port 6 to zero and hand the handle over.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);

int WORLDTRADE_BOX_CheckMonRestrictionB(u32 handle)
{
    u32 stamp = POKE_TOOL_DecodeBoxParam((struct Sav *)handle);

    POKE_TOOL_GetBoxValue((void *)handle, 6, 0);
    POKE_TOOL_EncodeBoxParam((struct Sav *)handle, stamp);
    return 0;
}
