/*
 * function: HAND_WAZA_FeintBreakSideGuard
 * address:  0x021E42B0
 * packet:   pkt_ov093_021E42B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   BTL_MAIN_IsZero  0x021B9A5C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckSideEffectActive  0x021C82C4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern u8 BTL_MAIN_IsZero(u32 x);
extern int BTL_SERVER_FLOW_CheckSideEffectActive(int a, int b, int c);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_FeintBreakSideGuard(int a0, u8 *s, int k, int *pf)
{
    int v;
    u32 i;
    u8 *e;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(k));
        if (BTL_SERVER_FLOW_CheckSideEffectActive((int)s, v, 9) != 0 || BTL_SERVER_FLOW_CheckSideEffectActive((int)s, v, 10) != 0) {
            e = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 0x1a, k);
            e[7] = v;
            e[4] = 3;
            for (i = 1; i < 3; i++)
                e[4 + i] = 0;
            if (e[4] > 2)
                e[6] |= 2;
            if (e[4] > 2)
                e[6] |= 4;
            BTL_SERVER_FLOW_CommitCmdRecord(s, e);
            *pf = 1;
        }
    }
}
