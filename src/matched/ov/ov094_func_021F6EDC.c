/*
 * function: BTLV_CAMERA_SetEyeAndTarget
 * address:  0x021F6EDC
 * packet:   pkt_ov094_021F6EDC
 * region:   ov094
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent is two bytes long; the follower is an unlabelled
 * leaf that disasm.py did not label.
 *
 * symbols:
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   G3D_CAMERA_SetUp  0x02048B44  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   BTLV_CAMERA_SyncOrbitFromCamera  0x021F73A4  thumb  ov094
 */

extern void G3D_CAMERA_SetEye(int, const int *);
extern void G3D_CAMERA_SetUp(int, int);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void BTLV_CAMERA_SyncOrbitFromCamera(int *);

void BTLV_CAMERA_SetEyeAndTarget(int *p, int *a, int *b)
{
    if (a) {
        p[6] = a[0];
        p[7] = a[1];
        p[8] = a[2];
        G3D_CAMERA_SetEye(p[1], a);
    }
    if (b) {
        p[9] = b[0];
        p[10] = b[1];
        p[11] = b[2];
        G3D_CAMERA_SetUp(p[1], (int)b);
    }
    G3D_CAMERA_Reset((struct Light *)p[1]);
    BTLV_CAMERA_SyncOrbitFromCamera(p);
}
