/*
 * function: BTLV_CAMERA_RotateOrbit
 * address:  0x021F6F20
 * packet:   pkt_ov094_021F6F20
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the transform at 0x18/0x24, then loads it into the handle at word 1 and commits.
 *
 * symbols:
 *   BTLV_CAMERA_ComputeOrbitOffset 0x021F7108 thumb ov094
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 */
typedef struct {
    char pad[4];
    void *h;            /* 0x04 */
    char pad08[0x18 - 8];
    int m[3];           /* 0x18 */
    int v[3];           /* 0x24 */
} Obj;

extern void BTLV_CAMERA_ComputeOrbitOffset(int *p, int a, int b, int *out, int *base);
extern void G3D_CAMERA_SetEye(void *, int *);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);

void BTLV_CAMERA_RotateOrbit(Obj *p, int a, int b)
{
    BTLV_CAMERA_ComputeOrbitOffset((int *)p, a, b, p->m, p->v);
    G3D_CAMERA_SetEye(p->h, p->m);
    G3D_CAMERA_Reset(p->h);
}
