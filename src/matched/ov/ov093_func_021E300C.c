/*
 * unit:     yes
 * function: HAND_WAZA_GustOnWazaPower, HAND_WAZA_AddSkyUppercut
 * address:  0x021E300C
 * packet:   pkt_ov093_021E300C
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
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   HAND_COMMON_EventScaleDamage  0x021E8860  thumb  ov093
 *   gSkyUppercutHandlers  0x021F2464  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void HAND_COMMON_EventScaleDamage(int n);
extern u8 gSkyUppercutHandlers[];

void HAND_WAZA_GustOnWazaPower(int u, void *p, int key)
{
    int k = 3;
    if (key == BTL_EVENT_GetVar(k)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(p, (u8)BTL_EVENT_GetVar(4)), k) != 0)
            HAND_COMMON_EventScaleDamage(2);
    }
}

u8 *HAND_WAZA_AddSkyUppercut(u32 *out)
{
    *out = 1;
    return gSkyUppercutHandlers;
}
