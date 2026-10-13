/*
 * function: BTL_MAIN_DecodeMessageCodeBasic
 * address:  0x021B87E8
 * packet:   pkt_ov093_021B87E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetEnemyLanePosFromWork  0x021B8C50  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_MAIN_GetEnemyLanePosFromWork(char **p, u32 v, int k);

u8 BTL_MAIN_DecodeMessageCodeBasic(void *p, u32 k, u32 v, u8 *out)
{
    switch (k) {
    case 0:
    case 4:
    case 7:
    default:
        return 0;
    case 1:
    case 2:
    case 6:
        *out = BTL_MAIN_GetEnemyLanePosFromWork(p, v, 0);
        break;
    case 3:
        *out = v;
        break;
    case 5:
    case 8:
        out[0] = 0;
        out[1] = 1;
        return 2;
    }
    return 1;
}
