/*
 * function: SCRCMD_SCREENEFFECTS_DeleteBuildModelNode
 * address:  0x021B2D98
 * packet:   pkt_ov021_021B2D98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_BUILDMODEL_GetNodeByHandle  0x0218BA98  thumb  ov021
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb
 *   SCRCMD_SCREENEFFECTS_GetBuildModelMgr  0x021B2BD8  thumb  ov021
 */

typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRCMD_SCREENEFFECTS_GetBuildModelMgr(u32 a);
extern u32 FIELD_BUILDMODEL_GetNodeByHandle(u32, u32);
extern void FIELD_BUILDMODEL_DeleteNode(u32);

int SCRCMD_SCREENEFFECTS_DeleteBuildModelNode(u32 a, u32 b)
{
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u32 o = FIELD_BUILDMODEL_GetNodeByHandle(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(b), x);

    if (o != 0) {
        FIELD_BUILDMODEL_DeleteNode(o);
    }
    return 0;
}
