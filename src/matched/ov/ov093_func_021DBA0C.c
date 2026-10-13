/*
 * function: HAND_TOKUSEI_ShadowTag_PreventEscape
 * address:  0x021DBA0C
 * packet:   pkt_ov093_021DBA0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_TOKUSEI_ShadowTag_PreventEscape(int a, int p, int x)
{
    u8 buf[4];
    u32 n;
    u8 i;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(2), (int)x) == 0) {
        n = BTL_SERVER_FLOW_CollectAlivePokeIds((int *)p, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke((u8 *)p, x) | 0x100), buf);
        for (i = 0; i < n; i++) {
            if (func_021D59B4(BTL_SERVER_FLOW_GetPokeParam((int *)p, buf[i]), 0x11) == 0x17)
                return;
        }
        BTL_EVENT_OverwriteVar(0x41, 1);
    }
}
