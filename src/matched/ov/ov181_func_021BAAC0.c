/*
 * function: func_021BAAC0
 * address:  0x021BAAC0
 * packet:   pkt_021BAAC0
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 */

typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

int func_021BAAC0(void)
{
    BG_SYS_SetMainPlaneVisible(1, 1);
    return 1;
}
