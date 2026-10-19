/*
 * function: HAND_ITEM_BindingBandSickCont
 * address:  0x021DFCE8
 * packet:   pkt_ov093_021DFCE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SICKCONT_SetFlag  0x021E8BD0  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
union U;
extern void BTL_SICKCONT_SetFlag(union U *p, int v);

void HAND_ITEM_BindingBandSickCont(int a, int b, int c)
{
    int v;

    if (c != BTL_EVENT_GetVar(3))
        return;
    v = BTL_EVENT_GetVar(30);
    BTL_SICKCONT_SetFlag((union U *)(&v), 1);
    BTL_EVENT_OverwriteVar(30, v);
}
