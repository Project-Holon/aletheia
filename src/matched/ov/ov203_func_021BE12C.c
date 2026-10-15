/*
 * function: DEMO3D_GRAPHIC_DeleteG3d
 * address:  0x021BE12C
 * packet:   pkt_021BE12C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 */

extern int G3D_LIGHT_DeleteSlots(int);
extern void G3D_SYSTEM_Exit(int);

void DEMO3D_GRAPHIC_DeleteG3d(int *p)
{
    G3D_SYSTEM_Exit(G3D_LIGHT_DeleteSlots(p[1]));
}
