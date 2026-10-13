/*
 * function: FLDMMDL_MOVECODE_IsBButtonPressed
 * address:  0x0219B0C4
 * packet:   pkt_ov021_0219B0C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 KEY_GetTrg(void);

int FLDMMDL_MOVECODE_IsBButtonPressed(void)
{
    if (KEY_GetTrg() & 2) {
        return 1;
    }
    return 0;
}
