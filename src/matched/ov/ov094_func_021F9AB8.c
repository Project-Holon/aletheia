/*
 * function: BTLV_EFFVM_CmdSetupCamera
 * address:  0x021F9AB8
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * note: d_0220ACA0 holds six vectors but is declared with a short bound. Cases 14, 18 and
 *   19 index past it; MWCC then treats those loads as possibly aliasing A/B and keeps each
 *   load after the preceding store (any bound 1..4 matches; in-bounds models such as [6],
 *   [2][3] or a pair struct hoist the last load above the B.y store).
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_RefreshMcssOrtho  0x021FDB20  thumb  ov094
 *   BTLV_EFFECT_GetMode  0x021F8710  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_EnableOrthoMode  0x021FF16C  thumb  ov094
 *   BTLV_EFFVM_SpriteCleanupTaskMain  0x021FE9F0  thumb  ov094
 *   BTLV_CAMERA_GetDefaultEyeAndTarget  0x021F7208  thumb  ov094
 *   BTLV_EFFECT_GetCamera  0x021F8684  thumb  ov094
 *   BTLV_CAMERA_SetEyeAndTarget  0x021F6EDC  thumb  ov094
 *   BTLV_CAMERA_StartMove  0x021F6F48  thumb  ov094
 *   d_0220ACA0  0x0220ACA0  data  a4
 *   d_0220ACE8  0x0220ACE8  data  a4
 *   d_0220AD00  0x0220AD00  data  a4
 *   d_0220AD78  0x0220AD78  data  a4
 *   d_0220ADA8  0x0220ADA8  data  a4
 *   d_0220ADD8  0x0220ADD8  data  a4
 *   d_0220AE20  0x0220AE20  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} VecFx32;

typedef struct {
    unsigned b0:1;
    unsigned f1:1;
    unsigned b2:11;
    unsigned f13:1;
    unsigned b14:1;
    unsigned f15:1;
    unsigned rest:16;
} Flags;

typedef struct {
    Flags flags;
    char pad04[0xdc - 4];
    int dc;             /* 0xdc */
    int e0;             /* 0xe0 */
    char pade4[0x23c - 0xe4];
    int ret;            /* 0x23c */
    char pad240[0x248 - 0x240];
    u8 b248;            /* 0x248 */
    char pad249[0x284 - 0x249];
    int h284;           /* 0x284 */
    VecFx32 a288;       /* 0x288 */
    VecFx32 b294;       /* 0x294 */
} Ctx;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void BTLV_EFFVM_RefreshMcssOrtho(Ctx *c);
extern int BTLV_EFFECT_GetMode(void);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_EnableOrthoMode(void *w);
extern void BTLV_EFFVM_SpriteCleanupTaskMain(int a, int b, int n, int s, int z);
extern void BTLV_CAMERA_GetDefaultEyeAndTarget(VecFx32 *a, VecFx32 *b);
extern int BTLV_EFFECT_GetCamera(void);
extern void BTLV_CAMERA_SetEyeAndTarget(int *p, int *a, int *b);
extern void BTLV_CAMERA_StartMove(int cam, VecFx32 *a, VecFx32 *b, int n, int s, int t);

extern const VecFx32 d_0220ACA0[2];
extern const VecFx32 d_0220ACE8[];
extern const VecFx32 d_0220AD00[];
extern const VecFx32 d_0220AD78[];
extern const VecFx32 d_0220ADA8[];
extern const VecFx32 d_0220ADD8[];
extern const VecFx32 d_0220AE20[];

int BTLV_EFFVM_CmdSetupCamera(void *r, Ctx *c)
{
    VecFx32 A;
    VecFx32 B;
    int type;
    int mode;
    int n;
    int s;
    int t;
    int k;
    int v;

    type = VM_GetU32(r);
    mode = VM_GetU32(r);
    n = VM_GetU32(r);
    s = VM_GetU32(r);
    t = VM_GetU32(r);
    if (c->flags.f15) {
        return c->ret;
    }
    if (mode == 13 && c->h284 == 0) {
        mode = 8;
    }
    if (mode != 8 && mode != 15 && mode != 16 && mode != 14 && mode != 17) {
        BTLV_EFFVM_RefreshMcssOrtho(c);
    } else {
        c->flags.f1 = 1;
    }
    switch (mode) {
    case 15:
    case 16:
        k = BTLV_EFFECT_GetMode();
        if (mode == 15) {
            v = c->dc;
        } else {
            v = c->e0;
        }
        switch (k) {
        case 0:
            return c->ret;
        case 1:
        case 2:
            switch (v) {
            case 2:
                mode = 2;
                break;
            case 3:
                mode = 8;
                if (k != 1) {
                    mode = 18;
                }
                break;
            case 4:
                mode = 4;
                if (k != 1) {
                    mode = 8;
                }
                break;
            case 5:
                mode = 8;
                break;
            case 6:
                mode = 8;
                if (k != 1) {
                    mode = 6;
                }
                break;
            case 7:
            default:
                return c->ret;
            }
            break;
        case 3:
            if (v == 4 || v == 6) {
                mode = 19;
            }
            break;
        }
        break;
    case 14:
        k = BTLV_EFFECT_GetMode();
        if (k == 0 || k == 3) {
            return c->ret;
        }
        break;
    case 20:
        k = BTLV_EFFECT_GetMode();
        if (k == 0 || k == 3) {
            BTLV_MCSS_EnableOrthoMode((void *)BTLV_EFFECT_GetMcss());
            return c->ret;
        }
        mode = 14;
        break;
    case 21:
        k = BTLV_EFFECT_GetMode();
        if (k == 0 || k == 3) {
            mode = c->dc;
        } else if (c->dc & 1) {
            mode = 1;
        } else {
            mode = 14;
        }
        break;
    case 17:
        mode = 8;
        break;
    case 9:
    case 10:
        k = BTLV_EFFECT_GetMode();
        mode = c->dc;
        if (k == 3 && (mode == 4 || mode == 6)) {
            mode = 19;
        }
        break;
    case 11:
    case 12:
        switch (c->b248) {
        case 0:
        case 1:
        case 2:
        case 3:
            mode = c->e0;
            if (mode == 0xff) {
                mode = (c->dc & 1) ^ 1;
            }
            break;
        case 5:
        case 7:
        case 9:
        case 13:
            mode = c->e0;
            if (mode != 0xff) {
                break;
            }
        case 11:
            mode = (c->dc & 1) ^ 1;
            break;
        case 6:
        case 12:
            mode = c->dc & 1;
            break;
        case 4:
        case 8:
        case 10:
            k = BTLV_EFFECT_GetMode();
            if (k == 0 || k == 3) {
                mode = (c->dc & 1) ^ 1;
            } else {
                mode = 14;
            }
            break;
        }
        break;
    }
    switch (mode) {
    case 0:
    case 1:
        A.x = d_0220ACE8[mode].x;
        A.y = d_0220ACE8[mode].y;
        A.z = d_0220ACE8[mode].z;
        B.x = d_0220AD00[mode].x;
        B.y = d_0220AD00[mode].y;
        B.z = d_0220AD00[mode].z;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        k = BTLV_EFFECT_GetMode();
        if (k == 3) {
            A.x = d_0220ACE8[mode - 2].x;
            A.y = d_0220ACE8[mode - 2].y;
            A.z = d_0220ACE8[mode - 2].z;
            B.x = d_0220AD00[mode - 2].x;
            B.y = d_0220AD00[mode - 2].y;
            B.z = d_0220AD00[mode - 2].z;
        } else if (k == 1) {
            A.x = d_0220AD78[mode - 2].x;
            A.y = d_0220AD78[mode - 2].y;
            A.z = d_0220AD78[mode - 2].z;
            B.x = d_0220ADA8[mode - 2].x;
            B.y = d_0220ADA8[mode - 2].y;
            B.z = d_0220ADA8[mode - 2].z;
        } else {
            A.x = d_0220ADD8[mode - 2].x;
            A.y = d_0220ADD8[mode - 2].y;
            A.z = d_0220ADD8[mode - 2].z;
            B.x = d_0220AE20[mode - 2].x;
            B.y = d_0220AE20[mode - 2].y;
            B.z = d_0220AE20[mode - 2].z;
        }
        break;
    case 6:
    case 7:
        A.x = d_0220ADD8[mode - 2].x;
        A.y = d_0220ADD8[mode - 2].y;
        A.z = d_0220ADD8[mode - 2].z;
        B.x = d_0220AE20[mode - 2].x;
        B.y = d_0220AE20[mode - 2].y;
        B.z = d_0220AE20[mode - 2].z;
        break;
    case 13:
        A.x = c->a288.x;
        A.y = c->a288.y;
        A.z = c->a288.z;
        B.x = c->b294.x;
        B.y = c->b294.y;
        B.z = c->b294.z;
        break;
    case 14:
        A.x = d_0220ACA0[0].x;
        A.y = d_0220ACA0[0].y;
        A.z = d_0220ACA0[0].z;
        B.x = d_0220ACA0[2].x;
        B.y = d_0220ACA0[2].y;
        B.z = d_0220ACA0[2].z;
        if (c->flags.f1) {
            BTLV_EFFVM_SpriteCleanupTaskMain(0xa66, 0xb9a, n, s, 0);
            c->flags.f13 = 1;
        }
        break;
    case 19:
        A.x = d_0220ACA0[3].x;
        A.y = d_0220ACA0[3].y;
        A.z = d_0220ACA0[3].z;
        B.x = d_0220ACA0[1].x;
        B.y = d_0220ACA0[1].y;
        B.z = d_0220ACA0[1].z;
        if (c->flags.f1) {
            BTLV_EFFVM_SpriteCleanupTaskMain(0xa66, 0xb9a, n, s, 0);
            c->flags.f13 = 1;
        }
        break;
    case 18:
        A.x = d_0220ACA0[5].x;
        A.y = d_0220ACA0[5].y;
        A.z = d_0220ACA0[5].z;
        B.x = d_0220ACA0[4].x;
        B.y = d_0220ACA0[4].y;
        B.z = d_0220ACA0[4].z;
        break;
    default:
        BTLV_CAMERA_GetDefaultEyeAndTarget(&A, &B);
        if (c->flags.f13) {
            BTLV_EFFVM_SpriteCleanupTaskMain(0x1000, 0x1000, n, s, 0);
            c->flags.f13 = 0;
        }
        break;
    }
    switch (type) {
    case 0:
        BTLV_CAMERA_SetEyeAndTarget((int *)BTLV_EFFECT_GetCamera(), (int *)(&A), (int *)(&B));
        break;
    case 1:
        BTLV_CAMERA_StartMove(BTLV_EFFECT_GetCamera(), &A, &B, n, s, t);
        break;
    }
    return c->ret;
}
