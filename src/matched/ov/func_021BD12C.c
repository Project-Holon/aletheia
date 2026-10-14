/*
 * function: ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt
 * address:  0x021BD12C
 * packet:   pkt_021BD12C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawStart  0x02047964  arm  arm9
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm  arm9
 *   G3D_CAMERA_Reset  0x02048AD0  arm  arm9
 *   (none)
 *
 * Calls 0x02047964 on p, then 0x02048AD0 on the word at [p], then 0x020479D8.
 */

extern void G3D_SYSTEM_DrawStart(void *);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);

void ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt(int *p)
{
    G3D_SYSTEM_DrawStart(p);
    G3D_CAMERA_Reset((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}
