/*
 * function: func_021BC6CC
 * address:  0x021BC6CC
 * packet:   pkt_021BC6CC
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern int G3D_SYSTEM_Exit(int);

void func_021BC6CC(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}
