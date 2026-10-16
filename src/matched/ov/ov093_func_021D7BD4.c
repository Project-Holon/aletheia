/*
 * function: BTL_CALC_GetWeatherDamage
 * address:  0x021D7BD4
 * packet:   pkt_ov093_021D7BD4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_POKEPARAM_HasType(void *p, int k);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);

int BTL_CALC_GetWeatherDamage(void *p, int k)
{
    u16 r;

    switch (k) {
    case 4:
        if (BTL_POKEPARAM_HasType(p, 5) != 0) return 0;
        if (BTL_POKEPARAM_HasType(p, 8) != 0) return 0;
        if (BTL_POKEPARAM_HasType(p, 4) != 0) return 0;
        break;
    case 3:
        if (BTL_POKEPARAM_HasType(p, 0xe) != 0) return 0;
        break;
    default:
        return 0;
    }
    r = BTL_POKEPARAM_GetValue(p, 0xe) / 16;
    if (r == 0) r = 1;
    return r;
}
