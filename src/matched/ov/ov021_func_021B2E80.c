/*
 * function: SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone
 * address:  0x021B2E80
 * packet:   pkt_ov021_021B2E80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetNodeByHandle  0x0218BA98  thumb  ov021
 *   FIELD_BUILDMODEL_TryOpenNodeCurrentSlot  0x0218C8D8  thumb  ov021
 *   FIELD_BUILDMODEL_IsNodeSeBusy  0x0218C9A4  thumb  ov021
 *   SCRCMD_SCREENEFFECTS_GetBuildModelMgr  0x021B2BD8  thumb  ov021
 *   gScrcmdScreeneffectsNodeHandle     0x021EE720  data  a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 gScrcmdScreeneffectsNodeHandle;
extern int SCRCMD_SCREENEFFECTS_GetBuildModelMgr(u32 a);
extern u32 FIELD_BUILDMODEL_GetNodeByHandle(u32, u32);
extern int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(void *p);
extern int FIELD_BUILDMODEL_IsNodeSeBusy(void *p);

int SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone(u32 a, u32 b)
{
    u32 o = FIELD_BUILDMODEL_GetNodeByHandle(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(b), gScrcmdScreeneffectsNodeHandle);

    if (o == 0) {
        return 1;
    }
    if (FIELD_BUILDMODEL_TryOpenNodeCurrentSlot((void *)o) == 0) {
        return 0;
    }
    if (FIELD_BUILDMODEL_IsNodeSeBusy((void *)o) == 0) {
        return 1;
    }
    return 0;
}
