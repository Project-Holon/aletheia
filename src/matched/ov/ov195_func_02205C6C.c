/*
 * function: SHINKA_DEMO_GRAPHIC_Draw3dEnd
 * address:  0x02205C6C
 * packet:   pkt_02205C6C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */

extern void G3D_SYSTEM_DrawEnd(void);

void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *p)
{
    G3D_SYSTEM_DrawEnd();
}
