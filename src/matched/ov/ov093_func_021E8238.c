/*
 * function: HAND_WAZA_MiracleEyeSetDarkType
 * address:  0x021E8238
 * packet:   pkt_ov093_021E8238
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
 *   BTLV_CORE_SetSlotValue  0x021E8B28  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
union U;
extern void BTLV_CORE_SetSlotValue(union U *p, u16 v);

void HAND_WAZA_MiracleEyeSetDarkType(int a, int b, int c)
{
    u32 v;

    if (c == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(0x1e);
        BTLV_CORE_SetSlotValue((union U *)(&v), 0x10);
        BTL_EVENT_OverwriteVar(0x1e, v);
    }
}
