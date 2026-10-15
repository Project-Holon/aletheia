/*
 * function: PSEL_GRAPHIC_ApplyLookAt
 * address:  0x021BC6DC
 * packet:   pkt_ov223_021BC6DC
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_CAMERA_Reset    0x02048AD0  arm
 *   G3D_SYSTEM_ApplyLookAt    0x020479D8  arm
 */

extern void G3D_SYSTEM_DrawStart(void *p);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);

void PSEL_GRAPHIC_ApplyLookAt(int *p)
{
    G3D_SYSTEM_DrawStart(p);
    G3D_CAMERA_Reset((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}
