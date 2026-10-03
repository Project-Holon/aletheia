/*
 * function: func_021BC5C8
 * address:  0x021BC5C8
 * packet:   pkt_021BC5C8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * blocker: +0006 THM_CALL func_0204047C       -> unresolved: 0204047C (arm, from name) has no witness outside 021BC5C8..021BC5DC
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0204047C(int idx, unsigned short val);

void func_021BC5C8(void)
{
    func_0204047C(0, 0);
    func_0204047C(1, 1);
}

