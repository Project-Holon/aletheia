/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera
 * address:  0x021BA130
 * packet:   pkt_ov221_021BA130
 * region:   ov221
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 */

typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern int G3D_SYSTEM_Exit(int);

int CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(int *p)
{
    return G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}
