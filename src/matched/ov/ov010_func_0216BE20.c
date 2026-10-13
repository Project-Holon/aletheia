/*
 * function: FIELD_G3D_MAP_FindEventMonInParty
 * address:  0x0216BE20
 * packet:   pkt_ov010_0216BE20
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0202F488  0x0202F488  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_0202F488(int a0, int a1);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int FIELD_G3D_MAP_FindEventMonInParty(int a, int b, int e, int d, u16 *out)
{
    int found;
    int n;
    int i;
    void *obj;

    n = func_0201AA18((void *)a);
    found = 0;
    *out = 0;
    for (i = 0; i < n; i++) {
        obj = func_0201AB28((void *)a, i);
        if (func_0202F488((int)obj, d) == 0) {
            continue;
        }
        if (b != POKE_TOOL_GetPartyValue(obj, 5, 0)) {
            continue;
        }
        if (e != 0) {
            if (e == POKE_TOOL_GetPartyValue(obj, 0x36, 0)
                || e == POKE_TOOL_GetPartyValue(obj, 0x37, 0)
                || e == POKE_TOOL_GetPartyValue(obj, 0x38, 0)
                || e == POKE_TOOL_GetPartyValue(obj, 0x39, 0)) {
                continue;
            }
        }
        found = 1;
        *out = i;
        break;
    }
    return found;
}
