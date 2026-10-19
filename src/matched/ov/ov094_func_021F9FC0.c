/*
 * function: BTLV_EFFVM_CmdRotateCameraOrbit
 * address:  0x021F9FC0
 * packet:   pkt_ov094_021F9FC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_RefreshMcssOrtho  0x021FDB20  thumb  ov094
 *   BTLV_EFFECT_GetCamera  0x021F8684  thumb  ov094
 *   BTLV_CAMERA_RotateOrbit  0x021F6F20  thumb  ov094
 *   BTLV_CAMERA_AdvanceOrbitEye  0x021F7108  thumb  ov094
 *   BTLV_CAMERA_StartMove  0x021F6F48  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x23C];
    int ret;            /* 0x23C */
} Ctx;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void BTLV_EFFVM_RefreshMcssOrtho(Ctx *c);
extern int BTLV_EFFECT_GetCamera(void);
extern void BTLV_CAMERA_RotateOrbit(int cam, int a, int b);
extern void BTLV_CAMERA_AdvanceOrbitEye(int *p, int a, int b, int *out, int *base);
extern void BTLV_CAMERA_StartMove(int cam, int *a, int *b, int n, int s, int t);

int BTLV_EFFVM_CmdRotateCameraOrbit(void *r, Ctx *c)
{
    int E[3];
    int F[3];
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int type;

    type = VM_GetU32(r);
    v1 = VM_GetU32(r);
    v2 = VM_GetU32(r);
    v3 = VM_GetU32(r);
    v4 = VM_GetU32(r);
    v5 = VM_GetU32(r);
    BTLV_EFFVM_RefreshMcssOrtho(c);
    switch (type) {
    case 0:
        BTLV_CAMERA_RotateOrbit(BTLV_EFFECT_GetCamera(), v1, v2);
        break;
    case 1:
        BTLV_CAMERA_AdvanceOrbitEye((int *)BTLV_EFFECT_GetCamera(), v1, v2, E, F);
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), E, F, v3, v4, v5);
        break;
    }
    return c->ret;
}
