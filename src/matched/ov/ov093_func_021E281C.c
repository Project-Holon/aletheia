/*
 * unit:     yes
 * function: HAND_WAZA_RevengeDoublePowerOnHit, HAND_WAZA_FlailGetHandlers
 * address:  0x021E281C
 * packet:   pkt_ov093_021E281C
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
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   gFlailHandlers     0x021F26AC  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern void BTLV_CORE_EventScaleDamage(int n);
extern int gFlailHandlers[];

void HAND_WAZA_RevengeDoublePowerOnHit(int a, void *b, int c)
{
    void *v;
    u8 t;
    u8 j;
    u16 buf[4];

    if (c == BTL_EVENT_GetVar(3)) {
        v = BTL_SERVER_FLOW_GetPokeParam(b, c);
        t = BTL_EVENT_GetVar(4);
        j = 0;
        while (BTL_POKEPARAM_GetHitRecord(v, 0, j++, buf) != 0) {
            if (((u8 *)buf)[5] == t && buf[1] != 0) {
                BTLV_CORE_EventScaleDamage(2);
                return;
            }
        }
    }
}

int *HAND_WAZA_FlailGetHandlers(int *p)
{
    *p = 1;
    return gFlailHandlers;
}
