/*
 * function: HAND_COMMON_IsItemBoundToSpecies
 * address:  0x021E8638
 * packet:   pkt_ov093_021E8638
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_Main  0x021E867C  thumb  ov093
 *   func_021E868C  0x021E868C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int WIFIBATTLEMATCH_UTIL_Main(int b);
extern int func_021E868C(int b);

int HAND_COMMON_IsItemBoundToSpecies(int a, int b)
{
    switch (a) {
    case 0x1e7:
        if (b == 0x70)
            return 1;
        break;
    case 0x1ed:
        if (WIFIBATTLEMATCH_UTIL_Main(b) != 0)
            return 1;
        break;
    case 0x289:
        if (func_021E868C(b) != 0)
            return 1;
        break;
    }
    return 0;
}
