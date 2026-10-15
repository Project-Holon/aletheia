/*
 * function: FIELDMAP_SetBgMode
 * address:  0x02188DA0
 * packet:   pkt_02188DA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a fixed data pointer argument.
 *
 * symbols:
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

void FIELDMAP_SetBgMode(void)
{
    BG_SYS_SetGraphicsMode((struct DispConfig *)0x021D35F4);
}
