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
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020362DC(void);

int FLDMMDL_MOVECODE_IsBButtonPressed(void)
{
    if (func_020362DC() & 2) {
        return 1;
    }
    return 0;
}
