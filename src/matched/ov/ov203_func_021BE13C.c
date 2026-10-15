/*
 * function: DEMO3D_GRAPHIC_ApplyLookAt
 * address:  0x021BE13C
 * packet:   pkt_021BE13C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 */

extern void G3D_SYSTEM_DrawStart(void *);
extern void G3D_SYSTEM_ApplyLookAt(void);

void DEMO3D_GRAPHIC_ApplyLookAt(void *a)
{
    G3D_SYSTEM_DrawStart(a);
    G3D_SYSTEM_ApplyLookAt();
}