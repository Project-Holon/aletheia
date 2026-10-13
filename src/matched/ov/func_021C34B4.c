/*
 * function: SODATEYA_GetWithdrawCost
 * address:  0x021C34B4
 * packet:   pkt_021C34B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SODATEYA_GetLevelsGained  0x021C3490  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int SODATEYA_GetLevelsGained(void **p, int i);

int SODATEYA_GetWithdrawCost(void **a, int b)
{
return ((SODATEYA_GetLevelsGained((void **)a, b) + 1) * 100);
}

