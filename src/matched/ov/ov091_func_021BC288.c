/*
 * function: PLIST_MENU_ApplyGenesectDriveForm
 * address:  0x021BC288
 * packet:   pkt_ov091_021BC288
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_GetBoxParamIndex  0x02019D00  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u32 POKE_TOOL_GetBoxParamIndex(u32 id);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);

void PLIST_MENU_ApplyGenesectDriveForm(int unused, int a, int b)
{
    int t = 0;
    int r;
    if (POKE_TOOL_GetPartyValue((void *)a, 5, 0) == 0x289) {
        t = POKE_TOOL_GetPartyValue((void *)a, 0x6f, t);
        r = POKE_TOOL_GetBoxParamIndex(b);
        if (t != r) {
            POKE_TOOL_ChangeForm((void *)a, (u16)r);
        }
    }
}
