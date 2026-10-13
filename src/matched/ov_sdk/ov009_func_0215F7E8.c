/*
 * function: SOC_SetResolver
 * address:  0x0215F7E8
 * packet:   pkt_ov009_0215F7E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_SetResolver (libsoc.TWL.HYB.a(soc.o))
 *
 * symbols:
 *   func_0215EEE0  0x0215EEE0  arm  ov009
 */

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

extern int func_0215EEE0(unsigned long dns1, unsigned long dns2);

int SOC_SetResolver(unsigned long *dns1, unsigned long *dns2)
{
	return func_0215EEE0(SWAP32(*dns1), SWAP32(*dns2));
}
