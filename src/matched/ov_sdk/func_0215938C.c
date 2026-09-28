/*
 * function: func_0215938C
 * address:  0x0215938C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * One when the test fails, else the second call.
 *
 * symbols:
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 */

extern int func_021578C8(void);
extern int func_02157D8C(void);

int func_0215938C(void)
{
    if (func_021578C8() == 0) {
        return 1;
    }

    return func_02157D8C();
}

