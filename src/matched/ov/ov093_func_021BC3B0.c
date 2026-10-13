/*
 * function: BTL_SERVER_FLOW_PushBagModePositions
 * address:  0x021BC3B0
 * packet:   pkt_ov093_021BC3B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_IsClientUsed  0x021BB890  thumb  ov093
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   func_021BC408  0x021BC408  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_SERVER_IsClientUsed(u8 *p, u8 i);
extern u32 BTL_MAIN_GetRule(void **p);
extern int func_021BC408(u8 *p, u8 i, u32 *out);
extern void BTL_SERVER_CMD_Push(int p, int k, u8 a, u8 b);

void BTL_SERVER_FLOW_PushBagModePositions(int *p)
{
    u32 i;
    u32 x;
    u32 v;

    if (p[6] == 1) {
        for (i = 0; i < 4; i++) {
            if (BTL_SERVER_IsClientUsed((u8 *)p[0], i) != 0) {
                if (BTL_MAIN_GetRule((void **)p[1]) != 2)
                    v = 1;
                else
                    v = func_021BC408((u8 *)p + 0x1ab8, i, &x) + 1;
                BTL_SERVER_CMD_Push(p[3], 0x29, i, v);
            }
        }
    }
}
