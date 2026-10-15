/*
 * function: THE_END_GRAPHIC_DeleteCamera
 * address:  0x021B9B8C
 * packet:   pkt_021B9B8C
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_CAMERA_Delete   0x02048AC4  arm
 *   G3D_SYSTEM_Exit   0x02046788  arm
 */
typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);

void THE_END_GRAPHIC_DeleteCamera(unsigned int *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}
