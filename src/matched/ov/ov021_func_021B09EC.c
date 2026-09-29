/*
 * function: func_021B09EC
 * address:  0x021B09EC
 * packet:   pkt_ov021_021B09EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B09EC  0x021B09EC  thumb
 */

void func_021B09EC(int sel, int *a, int *b)
{
    *a = 0;
    *b = 0;
    switch (sel) {
    case 3:
        *b = 7;
        break;
    case 4:
        *a = 1;
        *b = 5;
        break;
    case 5:
        *b = 8;
        break;
    case 6:
        *a = 1;
        *b = 6;
        break;
    case 2:
        *a = 1;
        break;
    case 1:
        break;
    case 0:
        *a = 1;
        *b = 2;
        break;
    }
}
