/*
 * function: HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp
 * address:  0x021DC0BC
 * packet:   pkt_ov093_021DC0BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 d);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp(int u, int a, int b)
{
    void *m;
    u32 n;
    if (b == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam((int *)a, b);
        n = func_021D59B4(m, 0xd);
        if (n <= BTL_CALC_DivideMaxHp(m, 2)) {
            BTL_EVENT_MultiplyVar(0x35, 2 << 10);
        }
    }
}
