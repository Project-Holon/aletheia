/*
 * function: BTLV_EFFVM_CmdMoveCameraEased
 * address:  0x021FA048
 * packet:   pkt_ov094_021FA048
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFECT_GetCamera  0x021F8684  thumb  ov094
 *   BTLV_CAMERA_StartMoveWithEasing  0x021F7000  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x23C];
    int ret;            /* 0x23C */
} Ctx;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_GetCamera(void);
extern void BTLV_CAMERA_StartMoveWithEasing(int cam, int mode, int v, int unused, int n, int g, int h);

int BTLV_EFFVM_CmdMoveCameraEased(void *r, Ctx *c)
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;

    v0 = VM_GetU32(r);
    v1 = VM_GetU32(r);
    v2 = VM_GetU32(r);
    v3 = VM_GetU32(r);
    v4 = VM_GetU32(r);
    v5 = VM_GetU32(r);
    BTLV_CAMERA_StartMoveWithEasing(BTLV_EFFECT_GetCamera(), v0, v1, v2, v3, v4, v5);
    return c->ret;
}
