/*
 * function: WAZA_TOOL_IsHmMove
 * address:  0x0202F72C
 * packet:   pkt_0202F72C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: twelve-byte tail forwarder (pool word and bx) to FILE_UTIL_IsHmMove with
 *   the second argument; witness for ov131 P_STA_SKILL_HandleTouchForget (bl at +0x13A),
 *   whose call supplies a pointer, a halfword and a second halfword.
 * symbols:
 *   FILE_UTIL_IsHmMove  0x020212E4  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FILE_UTIL_IsHmMove(u16 v);

u32 WAZA_TOOL_IsHmMove(void *a, u16 b, u16 c)
{
    return FILE_UTIL_IsHmMove(b);
}
