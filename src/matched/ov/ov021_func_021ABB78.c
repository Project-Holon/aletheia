/*
 * function: FLD_SCENEAREA_LOADER_ApplyStripCameraResume
 * address:  0x021ABB78
 * packet:   pkt_ov021_021ABB78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_SCENEAREA_GetCamera  0x021AB760  thumb
 *   FLD_SCENEAREA_LOADER_ApplyStripCamera  0x021ABABC  thumb
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb
 */

typedef struct {
    int pad[7];
    int f1c;
} S;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FLD_SCENEAREA_GetCamera(u8 *p);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
typedef unsigned short u16;
extern void FLD_SCENEAREA_LOADER_ApplyStripCamera(int a0, const u16 *p, void *q);

void FLD_SCENEAREA_LOADER_ApplyStripCameraResume(int a, S *s, int c)
{
    int h = FLD_SCENEAREA_GetCamera((u8 *)a);
    FLD_SCENEAREA_LOADER_ApplyStripCamera(a, (const u16 *)s, (void *)c);
    if (s->f1c != 0) {
        FIELD_CAMERA_RestartDelay((unsigned char *)h);
    }
}
