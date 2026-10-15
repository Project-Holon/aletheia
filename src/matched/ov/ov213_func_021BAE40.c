/*
 * function: COMM_BTL_DEMO_GRAPHIC_DeleteG3d
 * address:  0x021BAE40
 * packet:   pkt_021BAE40
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 */

typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(int);

void COMM_BTL_DEMO_GRAPHIC_DeleteG3d(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}