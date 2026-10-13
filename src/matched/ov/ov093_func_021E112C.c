/*
 * function: HAND_WAZA_SecretPowerGetGroundEffect
 * address:  0x021E112C
 * packet:   pkt_ov093_021E112C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetFieldSituationType  0x021C8174  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_SERVER_FLOW_GetFieldSituationType(int *p);

u8 HAND_WAZA_SecretPowerGetGroundEffect(int *a, u8 *p1, u8 *p2)
{
    u8 r;
    u8 x;
    u8 y;
    int n;

    n = BTL_SERVER_FLOW_GetFieldSituationType(a);
    switch (n) {
    case 1:
    case 2:
    case 3:
    case 8:
    case 15:
        x = 1;
        y = 6;
        r = 1;
        break;
    case 4:
    case 14:
    default:
        x = 0;
        y = 1;
        r = 0;
        break;
    case 10:
        x = 2;
        y = 0;
        r = 6;
        break;
    case 0:
    case 5:
        x = 0;
        y = 2;
        r = 7;
        break;
    case 6:
    case 11:
    case 12:
        x = 1;
        y = 1;
        r = 5;
        break;
    case 9:
        x = 1;
        y = 5;
        r = 2;
        break;
    case 7:
    case 13:
        x = 0;
        y = 3;
        r = (n == 7) ? y : 4;
        break;
    }
    if (p1)
        *p1 = x;
    if (p2)
        *p2 = y;
    return r;
}
