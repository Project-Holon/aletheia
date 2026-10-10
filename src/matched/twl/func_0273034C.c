/*
 * function: func_0273034C
 * address: 0x0273034C
 * packet: pkt_twl_0273034C
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_0273034C.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;

/* Register readers: the argument is a register-block base, the mask picks the field. */
u32 func_0273034C(u32 a)
{
    return *(u8 *)(a + 0x04004040) & 1;
}
