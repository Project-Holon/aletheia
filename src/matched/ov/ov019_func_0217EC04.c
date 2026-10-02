/*
 * function: func_0217EC04
 * address: 0x0217EC04
 * packet: pkt_ov019_0217EC04
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02008550 0x02008550 thumb
 *   d_0218031C 0x0218031C data a2
 * Followers EC1C, EC28 and EC34 are already filed separately.
 */
typedef unsigned short u16;
extern int func_02008550(void *p);
extern const u16 d_0218031C[];
u16 func_0217EC04(void ***ctx)
{
    return d_0218031C[func_02008550(**ctx)];
}
