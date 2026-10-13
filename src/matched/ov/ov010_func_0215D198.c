/*
 * function: SCRCMD_PROC_GetDaycareGenderKind
 * address:  0x0215D198
 * packet:   pkt_ov010_0215D198
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int SCRCMD_PROC_GetDaycareGenderKind(void *x)
{
    int a = POKE_TOOL_GetPartyValue(x, 5, 0);
    int b = POKE_TOOL_GetPartyValue(x, 0x6e, 0);
    if (a == 0x20 || a == 0x1d) {
        a = 0;
        if (POKE_TOOL_GetPartyValue(x, 0x75, 0) == 0)
            return a;
    }
    switch (b) {
    case 2:
    default: return 0;
    case 0: return 1;
    case 1: return 2;
    }
}
