/*
 * function: HAND_WAZA_WakeUpSlapOnWazaPower
 * address:  0x021E2B18
 * packet:   pkt_ov093_021E2B18
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
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   HAND_COMMON_EventScaleDamage  0x021E8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void HAND_COMMON_EventScaleDamage(int n);

void HAND_WAZA_WakeUpSlapOnWazaPower(int u, void *p, int k)
{
    void *q;
    if (k == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(p, (u8)BTL_EVENT_GetVar(4));
        if (BTL_POKEPARAM_HasSubstitute((u8 *)((int)q)) == 0) {
            if (BTL_POKEPARAM_HasSick(q, 2) != 0)
                HAND_COMMON_EventScaleDamage(2);
        }
    }
}
