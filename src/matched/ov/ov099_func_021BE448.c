/*
 * function: func_021BE448
 * address: 0x021BE448
 * packet: pkt_ov099_021BE448
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BE4BA.
 * lever: case 0 assigns 15 between cases 2 and 3, reusing case 2's break.
 * symbols:
 *   func_021BDD60 0x021BDD60 thumb ov099
 */
extern int func_021BDD60(unsigned int);
int func_021BE448(unsigned int a, int b)
{
    int r = 15;
    switch (a) {
    case 4:
        if (b == 2) r = 4;
        else r = 3;
        break;
    case 5:
        if (b == 2) r = 6;
        else r = 5;
        break;
    case 6:
        if (b == 2) r = 10;
        else r = 9;
        break;
    case 2: r = 2; break;
    case 0: r = 15; break;
    case 3: r = 1; break;
    default:
        if (func_021BDD60(a) != 0) {
            if (b == 2) r = 8;
            else r = 7;
        } else if (a >= 15) {
            r = 14;
        }
        break;
    }
    return r;
}
