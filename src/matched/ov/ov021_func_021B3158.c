/*
 * function: SCRCMD_PROC_FLD_StepShopTask
 * address:  0x021B3158
 * packet:   pkt_ov021_021B3158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback armed by SCRCMD_SHOP_StartShop; steps the 0x214-byte work block it
 * allocated.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   SCRCMD_SHOP_PrepareFieldCamera  0x021B30C8  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELD_MSGBG_SetBlendThunk  0x02193060  thumb  ov021
 *   SCRCMD_PROC_FLD_StepShop  0x021B35A4  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021D9738     0x021D9738  data   ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    u8  state;
    u8  sub;
    u8  b2;
    u8  b3;
    u32 f04;
    u8  f08;
} Work;

typedef struct Buf24 {
    u32 w[6];
} Buf24;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Ctx;
extern void *SCRIPT_WORK_GetUserWorkPtr(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *a);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void SCRCMD_SHOP_PrepareFieldCamera(u32 *p, u32 b, void *h);
extern int FIELD_CAMERA_IsMoving(u8 *a);
extern void FIELD_MSGBG_SetBlendThunk(u32 a);
extern int SCRCMD_PROC_FLD_StepShop(u32 a, char *p, u32 c, u8 d);
extern void FIELD_CAMERA_StartMoveToSaved(u8 *p, u8 *src, u16 v);
extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
extern void FIELD_CAMERA_PopState(u8 *a);
extern u32 func_020307B0(void *p);
extern const Buf24 d_021D9738;

int SCRCMD_PROC_FLD_StepShopTask(u32 a, u32 b)
{
    Work **slot;
    Work *w;
    void *t;
    void *x;
    void *h;
    Buf24 buf;

    slot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork((void *)b));
    w = *slot;
    t = SCRCMD_WORK_GetGameSystem((void *)b);
    x = GAMESYSTEM_GetFieldMap((void *)t);
    h = FIELDMAP_GetCamera(x);
    switch (w->state) {
    case 0:
        FIELD_CAMERA_EndDelay(h);
        w->state++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled(h) == 0) {
            w->state++;
        }
        break;
    case 2:
        SCRCMD_SHOP_PrepareFieldCamera((u32 *)w, (u32)x, h);
        w->state++;
        break;
    case 3:
        if (FIELD_CAMERA_IsMoving(h) == 0) {
            w->state++;
            w->f08 = 0;
            FIELD_MSGBG_SetBlendThunk(0);
        }
        break;
    case 4:
        if (SCRCMD_PROC_FLD_StepShop((u32)t, (char *)(&w->f08), w->b2, w->b3)) {
            w->state++;
        }
        break;
    case 5:
        buf = d_021D9738;
        FIELD_CAMERA_StartMoveToSaved(h, (u8 *)(&buf), 8);
        w->state++;
        w->sub = 0;
        break;
    case 6:
        if (FIELD_CAMERA_IsMoving(h) == 0) {
            FIELD_CAMERA_ResumeTargetTrace((u32)h);
            FIELD_CAMERA_SetAreasEnabled(h, w->f04);
            FIELD_CAMERA_RestartDelay(h);
            FIELD_CAMERA_PopState(h);
            FIELD_MSGBG_SetBlendThunk(1);
            w->state++;
        }
        break;
    case 7:
        func_020307B0(*slot);
        return 1;
    }
    return 0;
}
