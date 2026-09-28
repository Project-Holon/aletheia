/*
 * function: func_021867C0
 * address:  0x021867C0
 * packet:   pkt_ov009_021867C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiResetProfile (gpi.o)
 *
 * The object keeps profile in r1 (a leading unused parameter takes r0).
 *
 * symbols:
 *   (none)
 */

typedef struct GPIProfile {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
} GPIProfile;

int func_021867C0(int unused, GPIProfile *profile)
{
    profile->f8 = 0;
    profile->fC = 0;
    profile->f14 = 0;
    profile->f18 = 0;
    profile->f1C = 0;
    profile->f20 = 0;
    profile->f28 = 0;
    return 1;
}
