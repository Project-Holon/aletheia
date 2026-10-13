/*
 * function: FIELD_MENU_LoadFrameBg
 * address:  0x021A8AFC
 * packet:   pkt_ov021_021A8AFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MENU_LoadScreen  0x021A92A4  thumb
 *   func_02040588  0x02040588  arm
 */

typedef unsigned int   u32;
extern void FIELD_MENU_LoadScreen(u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);

void FIELD_MENU_LoadFrameBg(int a, int b)
{
    FIELD_MENU_LoadScreen(a, 4);
    if (b != 0) {
        func_02040588(4, 0);
    }
}
