/*
 * function: HAND_ITEM_LightClay_ExtendScreen
 * address:  0x021DEDF8
 * packet:   pkt_ov093_021DEDF8
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
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_SICKCONT_AddIndex  0x021E8C50  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int HAND_ITEM_GetParam(int a, int b);
union U;
extern void BTL_SICKCONT_AddIndex(union U *p, u32 v);

void HAND_ITEM_LightClay_ExtendScreen(int a, int b, int c)
{
    int t;
    u8 k;

    if (c == BTL_EVENT_GetVar(2) && (u32)BTL_EVENT_GetVar(0x53) <= 1) {
        t = BTL_EVENT_GetVar(0x1e);
        k = HAND_ITEM_GetParam(a, 2);
        BTL_SICKCONT_AddIndex((union U *)(&t), k);
        BTL_EVENT_OverwriteVar(0x1e, t);
    }
}
