/*
 * function: func_02174B2C
 * address:  0x02174B2C
 * packet:   pkt_ov011_02174B2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_021737A8  0x021737A8  thumb ov011
 */

int func_0203D1C0(unsigned char a);
int func_021737A8(void);

void func_02174B2C(unsigned char *p)
{
    int i;

    if (p[0x8FF] != 0) {
        p[0x8FF]--;
        return;
    }
    for (i = 0; i < p[0x902]; i++) {
        if (func_0203D1C0(i) == 1 && !(p[0x8FB] & (1 << i))) {
            func_021737A8();
            p[0x8FF] = 30;
            return;
        }
    }
}
