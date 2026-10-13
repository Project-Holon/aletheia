/*
 * function: FLDMMDL_MOVE_IsButtonBHeld
 * address:  0x0219B8A8
 * packet:   pkt_ov021_0219B8A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern unsigned int func_0203630C(void);

int FLDMMDL_MOVE_IsButtonBHeld(void)
{
    if (func_0203630C() & 2) {
        return 1;
    }
    return 0;
}
