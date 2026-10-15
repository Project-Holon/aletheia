/*
 * function: BTLV_CAMERA_Create
 * address:  0x021F6E3C
 * packet:   pkt_ov094_021F6E3C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   BTLV_CAMERA_SyncOrbitFromCamera  0x021F73A4  thumb  ov094
 *   BTLV_CAMERA_GetDefaultEyeAndTarget  0x021F7208  thumb  ov094
 *   gBtlvCameraFileName     0x0220AC60  data   ov094  a1
 *   gBtlvCameraInitEye     0x02209CF4  data   ov094
 *   gBtlvCameraInitUp     0x02209D00  data   ov094
 *   gBtlvCameraInitTarget     0x02209CE8  data   ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} VecFx32;

typedef struct {
    int f0;
    int h4;
    char pad08[0x10];
    VecFx32 v18;        /* 0x18 */
    VecFx32 v24;        /* 0x24 */
    char pad30[0xb4 - 0x30];
    u16 hb4;            /* 0xb4 */
} Obj;

extern const char gBtlvCameraFileName[];
extern char gBtlvCameraInitEye[];
extern char gBtlvCameraInitUp[];
extern char gBtlvCameraInitTarget[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void BTLV_CAMERA_SyncOrbitFromCamera(int *p);
extern void BTLV_CAMERA_GetDefaultEyeAndTarget(VecFx32 *a, VecFx32 *b);

Obj *BTLV_CAMERA_Create(int a, u16 b)
{
    Obj *o = GFL_HEAP_Alloc(b, 0xb8, 1, gBtlvCameraFileName, 0x56);

    o->hb4 = b;
    o->f0 = a;
    o->h4 = G3D_CAMERA_Create(0, 0x399, 0xf97, 0x159a, 0, 0x1000, 0x200000, 0,
                          gBtlvCameraInitEye, gBtlvCameraInitUp, gBtlvCameraInitTarget, b);
    BTLV_CAMERA_SyncOrbitFromCamera((int *)o);
    G3D_CAMERA_Reset((struct Light *)o->h4);
    BTLV_CAMERA_GetDefaultEyeAndTarget(&o->v18, &o->v24);
    return o;
}
