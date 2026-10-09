/*
 * file:     unit_021BD3CC.c
 * function: func_021BD3CC
 * address:  0x021BD3CC
 * packet:   pkt_021BD3CC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BD3CC 0x021BD3CC arm
 *   func_021DA04C 0x021DA04C data
 *
 * Table lookup through the function-pointer table at 0x021DA04C.
 * Addresses are Black-image addresses.
 */

extern unsigned char func_021C0EC8(void);
extern int func_021DA04C[];

int func_021BD3CC(void)
{
    return func_021DA04C[func_021C0EC8()];
}
