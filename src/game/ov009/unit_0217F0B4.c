/*
 * file:     unit_0217F0B4.c
 * unit:     yes
 * function: func_0217F0B4, func_0217F0D8
 * address:  0x0217F0B4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020879B4                  0x020879B4  arm
 *   func_020879C8                  0x020879C8  arm
 */
extern unsigned long func_020879B4(void);
extern unsigned long func_020879C8(unsigned long state);
unsigned int func_0217F0B4(unsigned int *value);
unsigned int func_0217F0D8(unsigned int *value);


/*
 * sdk:      gsiInterlockedIncrement (gsplatformthread)
 */
unsigned int func_0217F0B4(unsigned int *value)
{
    unsigned long state;
    unsigned int ret;

    state = func_020879B4();
    ret = (*value) + 1;
    *value = ret;
    func_020879C8(state);
    return ret;
}


/*
 * sdk:      gsiInterlockedDecrement (gsplatformthread)
 */
unsigned int func_0217F0D8(unsigned int *value)
{
    unsigned long state;
    unsigned int ret;

    state = func_020879B4();
    ret = (*value) - 1;
    *value = ret;
    func_020879C8(state);
    return ret;
}
