/*
 * function: FLD_SCENEAREA_LOADER_Delete
 * address:  0x021AB81C
 * packet:   pkt_ov021_021AB81C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_SCENEAREA_LOADER_Unload  0x021AB868  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    int pad[2];
    int f8[2];
} S;

extern void FLD_SCENEAREA_LOADER_Unload(S *s);
extern void ARC_TOOL_DeleteHandle(int a);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void FLD_SCENEAREA_LOADER_Delete(S *s)
{
    int i;
    FLD_SCENEAREA_LOADER_Unload(s);
    for (i = 0; i < 2; i++) {
        ARC_TOOL_DeleteHandle(s->f8[i]);
    }
    func_020307B0(s);
}
