/*
 * function: MUSICAL_EVENT_SetPartyLevel50
 * address:  0x02155160
 * packet:   pkt_ov010_02155160
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Walks every entry of a list and applies func_02019CA0 with 50.
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_02019CA0  0x02019CA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 POKEPARTY_GetCount(void *list);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void func_02019CA0(void *p, u32 v);

void MUSICAL_EVENT_SetPartyLevel50(void *list)
{
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(list); i++)
        func_02019CA0(POKEPARTY_GetMember(list, i), 50);
}
