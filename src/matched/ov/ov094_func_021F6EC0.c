/*
 * function: func_021F6EC0
 * address:  0x021F6EC0
 * packet:   pkt_ov094_021F6EC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the handle at word 1, then frees the object.
 *
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   func_020307B0 0x020307B0 arm
 */
extern unsigned int G3D_CAMERA_Delete(void *ptr);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021F6EC0(void **p)
{
    G3D_CAMERA_Delete(p[1]);
    func_020307B0(p);
}
