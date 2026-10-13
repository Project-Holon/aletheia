/*
 * function: SCRCMD_MSGWIN_YesNoEventMain
 * address:  0x021B0084
 * packet:   pkt_ov021_021B0084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_SetWaitCount  0x0215A684  thumb  ov010
 *   SCRCMD_WORK_CountDownWait  0x0215A690  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 * State 2 is a nested switch on FIELD_MSGBG_YesNoMenuMain's result (case 0, case 2
 * empty, default) with the flag store and the state increment written out
 * in each arm: the compiler cross-jumps the default arm into case 0's
 * tail, which is why `movs r1,#1; b` sits after the shared increment.
 * An if/else chain puts that arm inline. The listing extent includes two
 * bytes of padding.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a0;
    u16 *flag;
    u32 h;
} Ctx;

struct Handle;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void SCRCMD_WORK_SetWaitCount(int *p, unsigned short v);
extern int SCRCMD_WORK_CountDownWait(char *a0);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);

int SCRCMD_MSGWIN_YesNoEventMain(u32 a0, int *st, Ctx *c)
{
    SCRCMD_WORK_GetScriptWork((void *)c->a0);
    switch (*st) {
    case 0:
        SCRCMD_WORK_SetWaitCount((int *)c->a0, 8);
        (*st)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait((char *)c->a0) == 1) {
            c->h = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)c->a0))), 0);
            (*st)++;
        }
        break;
    case 2:
        switch (FIELD_MSGBG_YesNoMenuMain((struct Handle *)c->h)) {
        case 0:
            *c->flag = 0;
            (*st)++;
            break;
        case 2:
            break;
        default:
            *c->flag = 1;
            (*st)++;
            break;
        }
        break;
    case 3:
        FIELD_MSGBG_DeleteMenuFunc((void *)c->h);
        return 1;
    }
    return 0;
}
