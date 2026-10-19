/*
 * function: WIFIBATTLEMATCH_NET_CompareParty
 * address:  0x021D9BC4
 * packet:   pkt_021D9BC4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   POKE_TOOL_GetBoxParamSize  0x020173E8  thumb
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *
 * Equality of two lists: same count, and every pair of entries compares equal over the record size 0x020173E8 returns; 1 when equal, else 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern unsigned int POKEPARTY_GetCount(void *list);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u8 *POKE_TOOL_CastToBoxParam(u32 entry);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern int GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

int WIFIBATTLEMATCH_NET_CompareParty(u32 a, u32 b)
{
    u32 n = POKEPARTY_GetCount((void *)a);
    u32 i;

    if (n == POKEPARTY_GetCount((void *)b)) {
        for (i = 0; i < n; i++) {
            u32 ea = (u32)POKEPARTY_GetMember((void *)a, i);
            u32 eb = (u32)POKEPARTY_GetMember((void *)b, i);
            u8 *pa = POKE_TOOL_CastToBoxParam(ea);
            u8 *pb = POKE_TOOL_CastToBoxParam(eb);
            if (GF_STANDARD_CompareBytes(pa, pb, POKE_TOOL_GetBoxParamSize()) != 0)
                return 0;
        }
        return 1;
    }
    return 0;
}
