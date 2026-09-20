/*
 * function: func_02013D74
 * address:  0x02013D74
 * packet:   pkt_02013D74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013A94  0x02013A94  thumb
 *   func_02013D9C  0x02013D9C  thumb
 */

extern int func_02013A94(void);
extern int func_02013D9C(void);

int func_02013D74(void)
{
    unsigned int val = (unsigned int)func_02013A94();
    if (val >= 0x121) {
        if (val <= (0x121 + 0x1b)) {
            return 1;
        }
    }
    if (func_02013D9C() == 1) {
        return 1;
    }
    return 0;
}
