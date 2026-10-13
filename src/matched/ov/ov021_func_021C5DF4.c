/*
 * function: FISHING_EventMain
 * address:  0x021C5DF4
 * packet:   pkt_ov021_021C5DF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FISHING_StepCounter  0x021C5FA8  thumb  ov021
 *   FISHING_StartRodEffect  0x021C602C  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   FISHING_WaitBite  0x021C5FC0  thumb  ov021
 *   FISHING_ShowBiteMark  0x021C5FEC  thumb  ov021
 *   FISHING_HideBiteMark  0x021C6018  thumb  ov021
 *   FISHING_EndRodEffect  0x021C6054  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   func_02008DF0  0x02008DF0  thumb
 *   EFFECT_ENCOUNT_Reset  0x021AA8EC  thumb  ov021
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   EVENT_BATTLE_CreateScriptedBattle  0x0216E7C8  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    u32 f18;
    u32 f1C;
    u8 pad20[0x39];
    u8 f59;
    u16 f5A;
    u32 f5C;
    u32 f60;
    void *f64;
} Work;

extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
struct Sub02008C20Obj;
extern int FIELD_PLAYER_StepFormChange(u8 *p);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FISHING_StepCounter(Work *w, u32 n);
extern void FISHING_StartRodEffect(u8 *p);
extern u32 func_02005728(u32 v);
extern int FISHING_WaitBite(u8 *p, u32 lim);
extern void FISHING_ShowBiteMark(u8 *p);
extern void FISHING_HideBiteMark(u32 *p);
extern void FISHING_EndRodEffect(u32 *p);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
struct S0201235C;
extern void EFFECT_ENCOUNT_Reset(u8 *p);
extern int BTL_SETUP_Delete(int a0);
extern int EVENT_BATTLE_CreateScriptedBattle(int a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int FISHING_EventMain(void *task, int *state, Work *w)
{
    int r;

    switch (*state) {
    case 0:
        if (w->f5A != 0) {
            *state = 8;
            break;
        }
        FIELD_PLAYER_StartFormChange((u8 *)w->f18, 0x200);
        (*state)++;
    case 1:
        if (FIELD_PLAYER_StepFormChange((u8 *)w->f18) != 1)
            break;
        FLDMMDL_SetDrawStatus((void *)w->f1C, 0);
        GFL_USE_PlaySeDefaultVolume(0x684);
        (*state)++;
        break;
    case 2:
        if (FISHING_StepCounter(w, 15) == 0)
            break;
        FISHING_StartRodEffect((u8 *)w);
        if (w->f64 == 0) {
            *state = 5;
            break;
        }
        w->f5C = func_02005728(0x5a) + 0x1e;
        (*state)++;
        break;
    case 3:
        r = FISHING_WaitBite((u8 *)w, w->f5C);
        if (r == 1) {
            *state = 6;
            break;
        }
        if (r != 2)
            break;
        FISHING_ShowBiteMark((u8 *)w);
        (*state)++;
        break;
    case 4:
        r = FISHING_WaitBite((u8 *)w, 0x1e);
        if (r == 0)
            break;
        FISHING_HideBiteMark((u32 *)w);
        if (r == 1) {
            FISHING_EndRodEffect((u32 *)w);
            FLDMMDL_SetDrawStatus((void *)w->f1C, 3);
            SCRIPT_SYS_CallScriptEvent(task, (u16)0x2796, (u32)0, (u32)0, (u32)0x15);
            *state = 10;
            break;
        }
        if (r != 2)
            break;
        func_02008DF0((struct Sub02008C20Obj *)w->f10, 0x50);
        *state = 7;
        break;
    case 5:
        r = FISHING_WaitBite((u8 *)w, 0x78);
        if (r != 2) {
            if (r == 1)
                *state = 6;
            break;
        }
    case 6:
    case 7:
        FISHING_EndRodEffect((u32 *)w);
        if (w->f64 != 0) {
            if (w->f59 == 1)
                EFFECT_ENCOUNT_Reset(w->fC);
            BTL_SETUP_Delete((int)w->f64);
        }
        FLDMMDL_SetDrawStatus((void *)w->f1C, 1);
        SCRIPT_SYS_CallScriptEvent(task, (u16)(*state + 0x2792), (u32)0, (u32)0, (u32)0x15);
        *state = 8;
        break;
    case 8:
        FIELD_PLAYER_StartFormChange((u8 *)w->f18, 8);
        *state = 9;
    case 9:
        if (FIELD_PLAYER_StepFormChange((u8 *)w->f18) == 1)
            return 1;
        break;
    case 10:
        func_02008DF0((struct Sub02008C20Obj *)w->f10, 8);
        GAME_EVENT_ChangeEvent(task, (u32 *)EVENT_BATTLE_CreateScriptedBattle((int)w->f0, (int)w->f8, (int)w->f64, 0, (u8)(w->f59 == 1 ? 1 : 4)));
        return 0;
    }
    return 0;
}
