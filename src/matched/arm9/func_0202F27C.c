/*
 * function: SAVE_EVENT_StoreTodayDate
 * address:  0x0202F27C
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GF_STANDARD_GetCachedDate   0x0203F4E4  arm
 *   POKE_TOOL_SetBoxValue   0x02017E64  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_EVENT_StoreTodayDate.c \
 *       --func SAVE_EVENT_StoreTodayDate --addr 0x0202F27C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct RtcDate;
extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);

void SAVE_EVENT_StoreTodayDate(void *a0)
{
    u32 buf[4];

    GF_STANDARD_GetCachedDate((struct RtcDate *)buf);

    POKE_TOOL_SetBoxValue(a0, 0x92, buf[0]);
    POKE_TOOL_SetBoxValue(a0, 0x93, buf[1]);
    POKE_TOOL_SetBoxValue(a0, 0x94, buf[2]);
}
