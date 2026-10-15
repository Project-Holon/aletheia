/*
 * function: gsiInterlockedIncrement
 * address:  0x0217F0B4
 * packet:   pkt_ov009_0217F0B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiInterlockedIncrement (gsplatformthread)
 *
 * symbols:
 *   func_020879B4                  0x020879B4  arm
 *   func_020879C8                  0x020879C8  arm
 */

extern unsigned long func_020879B4(void);
extern unsigned long func_020879C8(unsigned long state);

unsigned int gsiInterlockedIncrement(unsigned int *value)
{
    unsigned long state;
    unsigned int ret;

    state = func_020879B4();
    ret = (*value) + 1;
    *value = ret;
    func_020879C8(state);
    return ret;
}
