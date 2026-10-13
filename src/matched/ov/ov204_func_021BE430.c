/*
 * function: func_021BE430
 * address:  0x021BE430
 * packet:   pkt_021BE430
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);

u32 func_021BE430(void)
{
    if (TOUCHPANEL_GetTrg() != 0 || KEY_GetTrg() != 0) {
        return 1;
    }
    return 0;
}

