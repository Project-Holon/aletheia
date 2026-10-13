/*
 * function: func_021F70F0
 * address:  0x021F70F0
 * packet:   pkt_ov094_021F70F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Copies the light at word 1's vectors at +0x20 and +0x38 out to b and c.
 *
 * symbols:
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetUp 0x02048B30 arm
 */
extern void G3D_CAMERA_GetEye(void *, void *);
extern void G3D_CAMERA_GetUp(void *, int);

void func_021F70F0(void **p, void *b, int c)
{
    G3D_CAMERA_GetEye(p[1], b);
    G3D_CAMERA_GetUp(p[1], c);
}
