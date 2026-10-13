/*
 * unit:     yes
 * function: HAND_WAZA_ElectroBallSetPowerBySpeed, HAND_WAZA_AddEchoedVoice
 * address:  0x021E7164
 * packet:   pkt_ov093_021E7164
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F24EC     0x021F24EC  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(u8 *p, u8 *x, int flag);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int d_021F24EC[];

void HAND_WAZA_ElectroBallSetPowerBySpeed(int u, int a, int b)
{
    int x, y, q, v;

    if (b == BTL_EVENT_GetVar(3)) {
        x = (int)BTL_SERVER_FLOW_GetPokeParam((int *)a, b);
        y = (int)BTL_SERVER_FLOW_GetPokeParam((int *)a, (u8)BTL_EVENT_GetVar(4));
        x = BTL_SERVER_FLOW_CalcPokeSpeedWrapper((u8 *)a, (u8 *)x, 0);
        y = BTL_SERVER_FLOW_CalcPokeSpeedWrapper((u8 *)a, (u8 *)y, 0);
        q = x / y;
        if (q >= 4)
            v = 150;
        else if (q >= 3)
            v = 120;
        else if (q >= 2)
            v = 80;
        else {
            v = 60;
            if (q < 1)
                v = 40;
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}

int *HAND_WAZA_AddEchoedVoice(int *p)
{
    *p = 1;
    return d_021F24EC;
}
