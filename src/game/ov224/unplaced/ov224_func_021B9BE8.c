/*
 * function: func_021B9BE8
 * address:  0x021B9BE8
 * packet:   pkt_021B9BE8
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(u32 x);

void func_021B9BE8(u32 *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}
