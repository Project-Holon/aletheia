/*
 * function: FX_Inv
 * address:  0x0207C778
 * packet:   pkt_0207C778
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FX_InvAsync  0x0207C8A0  arm
 *   func_0207C86C  0x0207C86C  arm
 */

typedef long fx32;

extern void FX_InvAsync(fx32 denom);
typedef unsigned int   u32;
extern u32 func_0207C86C(void);

fx32 FX_Inv(fx32 v)
{
    FX_InvAsync(v);
    return func_0207C86C();
}
