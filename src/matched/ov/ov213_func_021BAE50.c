/*
 * function: func_021BAE50
 * address:  0x021BAE50
 * packet:   pkt_021BAE50
 * region:   ov213
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

void func_021BAE50(int *p)
{
    G3D_SYSTEM_DrawStart(p);
    G3D_CAMERA_Reset((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}
