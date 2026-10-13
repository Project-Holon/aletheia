/*
 * function: SWEET_SCENT_EventMain
 * address:  0x021C60B8
 * packet:   pkt_ov021_021C60B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   FLD3D_CI_StartPartyMemberSequence  0x021C1D68  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   SWEET_SCENT_CheckWeatherClear  0x021C61D4  thumb  ov021
 *   SWEET_SCENT_StartFade  0x021C61EC  thumb  ov021
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELD_ENCOUNT_CheckWildEncount  0x021A9F40  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 f0;
    u8 pad1[3];
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
} Work;

extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
struct Evt;
extern int FIELD_PLAYER_StepFormChange(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern int FLDMMDL_EndAcmd(char *p);
struct Ctx;
extern void *FIELDMAP_GetFld3dCi(u8 *p);
extern int FLD3D_CI_StartPartyMemberSequence(int a, int b, int c);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int SWEET_SCENT_CheckWeatherClear(u32 a);
extern void SWEET_SCENT_StartFade(void *a, void *b, void *c);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern int FIELD_ENCOUNT_CheckWildEncount(struct Ctx *ctx, int mode);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u32 *FLDMMDL_SysResumeMove(void *c);

int SWEET_SCENT_EventMain(void *task, int *state, Work *w)
{
    void *t;

    switch (*state) {
    case 0:
        if (w->f0 >= 6) {
            *state = 5;
            break;
        }
        FIELD_PLAYER_StartFormChange(w->f10, 0x80);
        (*state)++;
    case 1:
        if (FIELD_PLAYER_StepFormChange(w->f10) != 1)
            break;
        FLDMMDL_SetAcmd(FIELD_PLAYER_GetMmdl(w->f10), 0xa2);
        (*state)++;
        break;
    case 2:
        if (FLDMMDL_EndAcmd(FIELD_PLAYER_GetMmdl(w->f10)) != 1)
            break;
        t = (void *)FLD3D_CI_StartPartyMemberSequence(w->f4, (int)FIELDMAP_GetFld3dCi(w->fC), w->f0);
        if (t != 0)
            GAME_EVENT_CallEvent(task, t);
        (*state)++;
        break;
    case 3:
        FIELD_PLAYER_StartFormChange(w->f10, 8);
        (*state)++;
    case 4:
        if (FIELD_PLAYER_StepFormChange(w->f10) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (SWEET_SCENT_CheckWeatherClear((u32)w) == 0) {
            *state = 8;
            break;
        }
        SWEET_SCENT_StartFade(task, (void *)w->f4, w->fC);
        *state = 6;
        break;
    case 6:
        t = (void *)FIELD_ENCOUNT_CheckWildEncount((struct Ctx *)FIELDMAP_GetEncount(w->fC), 2);
        if (t == 0) {
            *state = 7;
            break;
        }
        GAME_EVENT_CallEvent(task, t);
        *state = 9;
        break;
    case 7:
        SCRIPT_SYS_CallScriptEvent(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        SCRIPT_SYS_CallScriptEvent(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(w->fC));
        return 1;
    }
    return 0;
}
