/*
 * unit:     yes
 * function: HAND_WAZA_EruptionOnWazaPower, HAND_WAZA_AddWringOut
 * address:  0x021E2988
 * packet:   pkt_ov093_021E2988
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
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gWringOutHandlers     0x021F2564  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 WAZA_TOOL_GetPower(void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 v);
extern int gWringOutHandlers[];

void HAND_WAZA_EruptionOnWazaPower(void *a, void *b, int c)
{
    void *m;
    u32 x;
    u32 y;
    u32 r;
    u32 t;

    if (c == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam(b, c);
        x = BTL_POKEPARAM_GetValue(m, 0xD);
        y = BTL_POKEPARAM_GetValue(m, 0xE);
        t = WAZA_TOOL_GetPower((void *)BTL_EVENT_GetFactorKey(a));
        r = t * x / y;
        if (r == 0)
            r = 1;
        BTL_EVENT_OverwriteVar(0x30, r);
    }
}

int *HAND_WAZA_AddWringOut(int *p)
{
    *p = 1;
    return gWringOutHandlers;
}
