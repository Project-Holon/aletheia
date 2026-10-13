/*
 * function: func_021F6DE8
 * address:  0x021F6DE8
 * packet:   pkt_021F6DE8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *

 *
 * Read port 6 and report whether the follow-up check accepted it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern u32 func_0202136C(u16 v);

int func_021F6DE8(u32 handle)
{
    int ok = 0;
    u16 v = (u16)POKE_TOOL_GetPartyValue((void *)handle, 6, 0);

    if (func_0202136C(v) != 0) {
        ok = 1;
    }
    return ok;
}
