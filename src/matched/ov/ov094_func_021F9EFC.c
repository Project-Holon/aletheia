/*
 * function: BTLV_EFFVM_CmdMoveCameraTo
 * address:  0x021F9EFC
 * packet:   pkt_ov094_021F9EFC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_RefreshMcssOrtho  0x021FDB20  thumb  ov094
 *   BTLV_EFFECT_GetCamera  0x021F8684  thumb  ov094
 *   BTLV_CAMERA_SetEyeAndTarget  0x021F6EDC  thumb  ov094
 *   BTLV_CAMERA_StartMove  0x021F6F48  thumb  ov094
 *   BTLV_CAMERA_GetEyeAndTarget  0x021F70F0  thumb  ov094
 *   VEC_Add  0x0207C9D0  arm
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
extern void BTLV_CAMERA_SetEyeAndTarget(int *p, int *a, int *b);
extern void BTLV_CAMERA_StartMove(int cam, int *a, int *b, int n, int s, int t);
extern void BTLV_CAMERA_GetEyeAndTarget(void **p, void *b, int c);
extern void VEC_Add(int *a, int *b, int *c);

int BTLV_EFFVM_CmdMoveCameraTo(void *r, Ctx *c)
{
    int A[3];
    int B[3];
    int C[3];
    int D[3];
    int n;
    int s;
    int t;
    int type;

    type = VM_GetU32(r);
    A[0] = VM_GetU32(r);
    A[1] = VM_GetU32(r);
    A[2] = VM_GetU32(r);
    B[0] = VM_GetU32(r);
    B[1] = VM_GetU32(r);
    B[2] = VM_GetU32(r);
    n = VM_GetU32(r);
    s = VM_GetU32(r);
    t = VM_GetU32(r);
    BTLV_EFFVM_RefreshMcssOrtho(c);
    switch (type) {
    case 0:
        BTLV_CAMERA_SetEyeAndTarget((int *)BTLV_EFFECT_GetCamera(), A, B);
        break;
    case 1:
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), A, B, n, s, t);
        break;
    case 2:
        BTLV_CAMERA_GetEyeAndTarget((void **)BTLV_EFFECT_GetCamera(), C, (int)D);
        VEC_Add(C, A, A);
        VEC_Add(D, B, B);
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), A, B, n, s, t);
        break;
    }
    return c->ret;
}
