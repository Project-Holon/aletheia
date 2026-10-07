/*
 * function: func_021890A4
 * address:  0x021890A4
 * packet:   pkt_ov009_021890A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiFixBuddyIndices (gpibuddy.o)
 *
 * symbols:
 *   (none)
 */

typedef struct GPIProfile {
    int f0;
    int f4;
    int *f8;
    int *fC;
} GPIProfile;

int func_021890A4(int unused, GPIProfile *profile, int baseIndex)
{
    if (profile->f8 != 0 && *profile->f8 > baseIndex)
        (*profile->f8)--;
    else if (profile->fC != 0 && *profile->fC > baseIndex)
        (*profile->fC)--;
    return 1;
}
