/*
 * function: HAND_WAZA_SpitUpOnGetMovePower
 * address:  0x021E17B0
 * packet:   pkt_ov093_021E17B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The product passed through a static inline helper is computed before the
 * helper's constant first argument is loaded (no result copy).
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern int BTL_EVENT_OverwriteVar(int a, unsigned int b);

static inline void func_021E17B0_set48(int v)
{
    BTL_EVENT_OverwriteVar(48, v);
}

void HAND_WAZA_SpitUpOnGetMovePower(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        func_021E17B0_set48(BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 0) * 100);
}
