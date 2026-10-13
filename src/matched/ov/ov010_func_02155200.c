/*
 * function: MUSICAL_EVENT_TrimPartyToThree
 * address:  0x02155200
 * packet:   pkt_ov010_02155200
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Trims a list to its first three entries by removing entry 3 until only three remain.
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_RemoveMember  0x0201A9C8  thumb
 */

typedef unsigned int u32;

typedef signed int     s32;
struct Party;
extern u32 POKEPARTY_GetCount(void *p);
extern u32 POKEPARTY_RemoveMember(struct Party *p, s32 idx);

void MUSICAL_EVENT_TrimPartyToThree(void *list)
{
    int i;
    int n;

    n = POKEPARTY_GetCount(list);
    for (i = 3; i < n; i++)
        POKEPARTY_RemoveMember(list, 3);
}
