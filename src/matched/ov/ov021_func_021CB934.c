/*
 * function: func_021CB934
 * address:  0x021CB934
 * packet:   pkt_ov021_021CB934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task step: fades out, runs the ov021 sub-screen on the +0xc argument, stores whether it was cancelled at *w[1].
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_SetWaitCount  0x0215A684  thumb  ov010
 *   SCRCMD_WORK_CountDownWait  0x0215A690  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *owner;
    u16 *result;
    u32 screen;
    u32 arg;
} Work;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Ctx;
extern void SCRCMD_WORK_SetWaitCount(int *p, unsigned short v);
extern int SCRCMD_WORK_CountDownWait(char *a0);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
struct Handle;
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);

int func_021CB934(void *task, int *state, Work *w)
{
    SCRCMD_WORK_GetScriptWork(w->owner);
    switch (*state) {
    case 0:
        SCRCMD_WORK_SetWaitCount(w->owner, 8);
        (*state)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait(w->owner) == 1) {
            w->screen = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(w->owner))), w->arg);
            (*state)++;
        }
        break;
    case 2:
        switch (FIELD_MSGBG_YesNoMenuMain((struct Handle *)w->screen)) {
        case 0:
            *w->result = 0;
            (*state)++;
            break;
        case 2:
            break;
        default:
            *w->result = 1;
            (*state)++;
            break;
        }
        break;
    case 3:
        FIELD_MSGBG_DeleteMenuFunc((void *)w->screen);
        return 1;
    }
    return 0;
}
