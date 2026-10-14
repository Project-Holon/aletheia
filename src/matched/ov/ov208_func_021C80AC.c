/*
 * function: ZUKAN_DETAIL_FORM_SelectModelPosition
 * address:  0x021C80AC
 * packet:   pkt_ov208_021C80AC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7FF8 0x021C7FF8  thumb  ov208
 *
 * Last-but-one labelled function in ov208; next labelled follower is
 * ZUKAN_DETAIL_FORM_CopyModelPosition. Maps the loader's mode byte (0/1/2 -> 0/3/4) and tail-calls
 * func_021C7FF8(r0, mapped, r2).
 */

extern void func_021C7FF8(int, int, int);

void ZUKAN_DETAIL_FORM_SelectModelPosition(int a, int b, int c)
{
    int m = 0;

    switch (b) {
    case 0:
        break;
    case 1:
        m = 3;
        break;
    case 2:
        m = 4;
        break;
    }
    func_021C7FF8(a, m, c);
}
