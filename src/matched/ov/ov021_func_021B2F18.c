/*
 * function: SCRCMD_SCREENEFFECTS_StepFadeTask
 * address:  0x021B2F18
 * packet:   pkt_ov021_021B2F18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_SCREENEFFECTS_StepFadeTask 0x021B2F18 thumb
 *   BG_SYS_GetMainVisiblePlanes 0x02043658 arm
 *   FIELDMAP_SetBgMode 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   FIELDMAP_ResetBgAffineShowMsg 0x02188DB0 thumb ov021
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   FIELDMAP_SetScriptEffectBusy 0x02189A1C thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */

extern unsigned int BG_SYS_GetMainVisiblePlanes(void);
extern void FIELDMAP_SetBgMode(void);
extern void func_02043534(unsigned int planes);
typedef unsigned char  u8;
struct Node;
extern void FIELDMAP_ResetBgAffineShowMsg(u8 *a);
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void FIELDMAP_SetScriptEffectBusy(u8 *p, u32 v);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);

void SCRCMD_SCREENEFFECTS_StepFadeTask(int p, int *q)
{
    int x;
    int y;
    int z;
    int w;
    int c;
    void *t;

    switch (q[5]) {
    case 0:
        if ((unsigned int)q[4] <= 1) {
            x = -1;
        } else {
            x = 4;
        }
        if (q[4] == 0 || q[4] == 2) {
            y = 16;
            z = 0;
            t = (void *)BG_SYS_GetMainVisiblePlanes();
            FIELDMAP_SetBgMode();
            func_02043534((unsigned int)t);
            FIELDMAP_ResetBgAffineShowMsg((u8 *)q[1]);
        } else {
            y = 0;
            z = 16;
        }
        if (q[2] == 0) {
            w = 3;
        } else {
            w = 12;
        }
        FADE_Start(w, y, z, x);
        q[5] = q[5] + 1;
        break;
    case 1:
        c = 0;
        if (q[3] == 1) {
            c = 1;
        }
        if (FADE_IsActive() == 0) {
            c = 1;
        }
        if (c) {
            FIELDMAP_SetScriptEffectBusy((u8 *)q[1], 0);
            func_02030EAC((struct Node *)p);
            func_020307B0(q);
        }
        break;
    }
}
