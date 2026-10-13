/*
 * function: BTL_ABILITY_HeatproofHalveBurnDamage
 * address:  0x021DA868
 * packet:   pkt_ov093_021DA868
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_CALC_Max   0x021D7B08  thumb ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern int BTL_CALC_Max(int a, int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void BTL_ABILITY_HeatproofHalveBurnDamage(int a, int b, int c)
{
    int t;

    if (c != BTL_EVENT_GetVar(2))
        return;
    if (BTL_EVENT_GetVar(0x1d) != 4)
        return;
    t = BTL_EVENT_GetVar(0x32);
    BTL_EVENT_OverwriteVar(0x32, BTL_CALC_Max(t / 2, 1));
}
