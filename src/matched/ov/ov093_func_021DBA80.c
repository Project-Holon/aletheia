/*
 * function: HAND_TOKUSEI_ArenaTrap_PreventEscape
 * address:  0x021DBA80
 * packet:   pkt_ov093_021DBA80
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
 *   BTL_SERVER_FLOW_IsPokeGroundedById  0x021C8234  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
extern int BTL_SERVER_FLOW_IsPokeGroundedById(u8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_TOKUSEI_ArenaTrap_PreventEscape(int a, int p, int x)
{
    u8 buf[4];
    u32 n;
    u8 i;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(2), x) == 0) {
        n = BTL_SERVER_FLOW_CollectAlivePokeIds((int *)p, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke((u8 *)p, x) | 0x100), buf);
        for (i = 0; i < n; i++) {
            if (BTL_SERVER_FLOW_IsPokeGroundedById((u8 *)p, buf[i]) == 0) {
                BTL_EVENT_OverwriteVar(0x41, 1);
                return;
            }
        }
    }
}
