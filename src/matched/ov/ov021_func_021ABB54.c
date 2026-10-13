/*
 * function: FLD_SCENEAREA_LOADER_ApplyStripCameraStop
 * address:  0x021ABB54
 * packet:   pkt_ov021_021ABB54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_SCENEAREA_GetCamera  0x021AB760  thumb
 *   FIELD_CAMERA_StopDelay  0x0218F0D4  thumb
 *   FLD_SCENEAREA_LOADER_ApplyStripCamera  0x021ABABC  thumb
 */

typedef struct {
    int pad[7];
    int f1c;
} S;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FLD_SCENEAREA_GetCamera(u8 *p);
extern void FIELD_CAMERA_StopDelay(u8 *a, int b);
typedef unsigned short u16;
extern void FLD_SCENEAREA_LOADER_ApplyStripCamera(int a0, const u16 *p, void *q);

void FLD_SCENEAREA_LOADER_ApplyStripCameraStop(int a, S *s, int c)
{
    int h = FLD_SCENEAREA_GetCamera((u8 *)a);
    if (s->f1c != 0) {
        FIELD_CAMERA_StopDelay((u8 *)h, s->f1c);
    }
    FLD_SCENEAREA_LOADER_ApplyStripCamera(a, (const u16 *)s, (void *)c);
}
