/*
 * function: HAND_WAZA_TrapOnDecideAddSick
 * address:  0x021E1320
 * packet:   pkt_ov093_021E1320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTLV_CORE_SetSlotValue  0x021E8B28  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
union U;
extern void BTLV_CORE_SetSlotValue(union U *p, u16 v);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_TrapOnDecideAddSick(void *a, int b, int c)
{
    int v;
    u16 n;

    if (c != BTL_EVENT_GetVar(3))
        return;
    n = BTL_EVENT_GetFactorKey(a);
    v = BTL_EVENT_GetVar(30);
    BTLV_CORE_SetSlotValue((union U *)(&v), n);
    BTL_EVENT_OverwriteVar(30, v);
}
