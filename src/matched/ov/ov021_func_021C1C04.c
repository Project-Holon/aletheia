/*
 * function: FLD3D_CI_Delete
 * address:  0x021C1C04
 * packet:   pkt_ov021_021C1C04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the effect handles and frees the object (EXACT*: trailing pad).
 *
 * symbols:
 *   G3D_UTIL_Delete  0x02047E54  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm  arm9
 */

typedef unsigned int u32;

struct Rec;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_UTIL_Delete(struct Rec *p);
extern u32 func_020307B0(void *p);

void FLD3D_CI_Delete(u32 *p)
{
    G3D_CAMERA_Delete((void *)p[1]);
    G3D_CAMERA_Delete((void *)p[2]);
    G3D_UTIL_Delete((struct Rec *)p[5]);
    func_020307B0(p);
}
