/*
 * function: HAND_TOKUSEI_EffectSporeOnDamageReaction
 * address:  0x021D9DB0
 * packet:   pkt_ov093_021D9DB0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_CALC_Random   0x021D78AC  thumb ov093
 *   BTL_CALC_MakeDefaultSickCont   0x021D7D18  thumb ov093
 *   HAND_TOKUSEI_TryAddContactSick   0x021D9E08  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

union USlot {
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

extern int BTL_EVENT_GetVar(int a);
extern u32 BTL_CALC_Random(u32 range);
extern union USlot BTL_CALC_MakeDefaultSickCont(int x);
extern void HAND_TOKUSEI_TryAddContactSick(int a, int b, int c, union USlot d, int e);

void HAND_TOKUSEI_EffectSporeOnDamageReaction(int a, int b, int c)
{
    u32 r;
    int k;
    union USlot s;

    if (c != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_GetVar(0x46) != 0)
        return;
    r = BTL_CALC_Random(0x1e);
    if (r > 0x14) {
        k = 5;
    } else {
        k = 1;
        if (r <= 10)
            k = 2;
    }
    s = BTL_CALC_MakeDefaultSickCont(k);
    HAND_TOKUSEI_TryAddContactSick(b, c, k, s, 0x1e);
}
