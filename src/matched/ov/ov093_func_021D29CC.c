/*
 * function: BTL_CLIENT_StepAddEffortValues
 * address:  0x021D29CC
 * packet:   pkt_ov093_021D29CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   gEffortValueParams     0x021EFF88  data  ov093  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u16 gEffortValueParams[];

int BTL_CLIENT_StepAddEffortValues(u32 *a, int b, u32 *c)
{
    void *m;
    u32 i;
    int k;
    u32 v;

    m = BTL_POKEPARAM_GetMon(BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]));
    for (i = 0; i < 6; i++) {
        if (gEffortValueParams[i + 1] != 0) {
            k = gEffortValueParams[i];
            v = c[i + 1] + POKE_TOOL_GetPartyValue(m, k, 0);
            if (v > 0xff) {
                v = 0xff;
            }
            POKE_TOOL_SetPartyValue(m, k, v);
        }
    }
    return 1;
}
