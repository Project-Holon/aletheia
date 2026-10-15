/*
 * function: EVENT_PERAP_RECORD_Main
 * address:  0x021D1C8C
 * packet:   pkt_021D1C8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fifteen-state field sequence: sets up handles, runs fades and a message task, then tears down.
 *
 * symbols:
 *   PM_VOICE_Play  0x02006984  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   SND_MIC_Init  0x02006CBC  thumb
 *   SND_MIC_Exit  0x02006D44  thumb
 *   SND_MIC_AddElapsed  0x02006D64  thumb
 *   SND_MIC_IsLimitReached  0x02006D94  thumb
 *   SND_MIC_StartRecording  0x02006DD8  thumb
 *   SND_MIC_StoreRecording  0x02006E18  thumb
 *   func_02007B50  0x02007B50  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   FIELD_SOUND_SYSTEM_StartPushTask  0x020295A4  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   UI_SetKeepAwakeFlagsGlobal  0x02034F84  arm
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintStr  0x02190EB8  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   FIELD_MSGBG_ClearSysWin  0x02190F7C  thumb  ov021
 *   FIELD_MSGBG_GetSysWinBmpWin  0x02190F9C  thumb  ov021
 *   EVENT_PERAP_RECORD_OnRecorded  0x021D1F48  thumb  ov021
 *   EVENT_PERAP_RECORD_PauseMmdls  0x021D1F50  thumb  ov021
 *   EVENT_PERAP_RECORD_ResumeMmdls  0x021D1F64  thumb  ov021
 *   EVENT_PERAP_RECORD_HopPokeIcon  0x021D2040  thumb  ov021
 *   EVENT_PERAP_RECORD_SetupWindow  0x021D20BC  thumb  ov021
 *   EVENT_PERAP_RECORD_Cleanup  0x021D2124  thumb  ov021
 *   GFL_USE_GetMainTaskList   0x020056BC  thumb
 *   PM_VOICE_IsActive   0x02006BD0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *x00;      /* 0x00 */
    void *x04;      /* 0x04 */
    u8 pad08[0xC];
    void *x14;      /* 0x14 */
    void *x18;      /* 0x18 */
    void *x1C;      /* 0x1C */
    void *x20;      /* 0x20 */
    void *x24;      /* 0x24 */
    void *x28;      /* 0x28 */
    void *x2C;      /* 0x2C */
    u32 pad30;
    void *x34;      /* 0x34 */
    u8 pad38[0x18];
    void *x50;      /* 0x50 */
    int x54;        /* 0x54 */
} Work;

extern int EVENT_PERAP_RECORD_PauseMmdls(u32 a);
struct P;
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
struct Fx;
struct Obj2;
extern struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(struct Fx *a, u32 b);
struct Evt;
struct Handle;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void EVENT_PERAP_RECORD_SetupWindow(u32 *w);
extern int func_02007B50(void *);
extern void FIELD_MSGBG_SysWinPrintMsg(u32 *p, u32 b, u32 c, u32 d);
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
struct Rec;
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
extern void FIELD_MSGBG_ClearSysWin(struct P *p);
extern void UI_SetKeepAwakeFlagsGlobal(u32);
extern void *SND_MIC_Init(u32);
extern void *GFL_USE_GetMainTaskList(void *);
extern void *FIELD_MSGBG_GetSysWinBmpWin(void **p);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void SND_MIC_AddElapsed(u32);
extern u32 SND_MIC_IsLimitReached(void);
extern void TIME_ICON_Delete(u8 *p);
extern u8 *FIELD_SOUND_SYSTEM_StartPushTask(u8 *p, u32 a);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 SND_MIC_StartRecording(void *a, u32 b);
extern void EVENT_PERAP_RECORD_OnRecorded(void *unused, int *done);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void FIELD_MSGBG_SysWinPrintStr(struct P *p, u32 b, u16 c, u32 d);
extern void SND_MIC_Exit(void);
extern void UI_ClearKeepAwakeFlagsGlobal(u32);
extern void *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(void *a, u32 b, u32 c);
extern void SND_MIC_StoreRecording(void *);
extern int EVENT_PERAP_RECORD_HopPokeIcon(u8 *w);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 PM_VOICE_IsActive(u32 i);
extern void EVENT_PERAP_RECORD_Cleanup(Work *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern int FIELD_MSGBG_DeleteSysWin(u32 a);
extern u32 FIELD_MSGBG_DeleteMsgData(struct Rec *a0);
extern int EVENT_PERAP_RECORD_ResumeMmdls(u32 a);

int EVENT_PERAP_RECORD_Main(void *proc, int *seq, Work *w)
{
    void *a;
    void *t;
    u32 buf;

    switch (*seq) {
    case 0:
        EVENT_PERAP_RECORD_PauseMmdls((u32)w);
        *seq = 1;
        break;
    case 1:
        w->x18 = t = (void *)FIELD_MSGBG_CreateMsgData((u32)w->x1C, 88);
        w->x20 = FIELD_MSGBG_CreateBottomSysWin(w->x1C, (u32)t);
        w->x28 = GF_FONT_Create_EC64(21);
        w->x2C = STRBUF_Create(0x400, 21);
        EVENT_PERAP_RECORD_SetupWindow((u32 *)w);
        if (func_02007B50(w->x00) == 1) {
            FIELD_MSGBG_SysWinPrintMsg(w->x20, 0, 0, 0);
            *seq = 2;
        } else {
            FIELD_MSGBG_SysWinPrintMsg(w->x20, 0, 0, 6);
            *seq = 4;
        }
        break;
    case 2:
        if (FIELD_MSGBG_SysWinMain(w->x20) == 1) {
            w->x24 = FIELD_MSGBG_CreateYesNoMenu(w->x1C, 0);
            *seq = 3;
        }
        break;
    case 3:
        switch (FIELD_MSGBG_YesNoMenuMain(w->x24)) {
        case 0:
            FIELD_MSGBG_DeleteMenuFunc((void *)w->x24);
            FIELD_MSGBG_ClearSysWin(w->x20);
            FIELD_MSGBG_SysWinPrintMsg(w->x20, 0, 0, 6);
            *seq = 4;
            break;
        case 1:
            FIELD_MSGBG_DeleteMenuFunc((void *)w->x24);
            *seq = 13;
            break;
        }
        break;
    case 4:
        if (FIELD_MSGBG_SysWinMain(w->x20) == 1) {
            UI_SetKeepAwakeFlagsGlobal(8);
            a = GFL_USE_GetMainTaskList(SND_MIC_Init(21));
            w->x34 = TIME_ICON_Create(a, FIELD_MSGBG_GetSysWinBmpWin(w->x20), 15, 16, 21);
            *seq = 5;
        }
        break;
    case 5:
        SND_MIC_AddElapsed(2);
        if (SND_MIC_IsLimitReached() == 1) {
            TIME_ICON_Delete(w->x34);
            FIELD_MSGBG_ClearSysWin(w->x20);
            FIELD_MSGBG_SysWinPrintMsg(w->x20, 0, 0, 1);
            GAME_EVENT_CallEvent(proc, (struct Evt **)FIELD_SOUND_SYSTEM_StartPushTask(w->x04, 6));
            *seq = 6;
        }
        break;
    case 6:
        if (FIELD_MSGBG_SysWinMain(w->x20) == 1) {
            if (SND_MIC_StartRecording(EVENT_PERAP_RECORD_OnRecorded, (u32)(&w->x54)) == 0) {
                *seq = 7;
            } else {
                a = func_02045EC0(w->x18, 3);
                func_0201EEF4(w->x28, 0, w->x14);
                func_0201F250(w->x28, w->x2C, a);
                STRBUF_Delete(a);
                FIELD_MSGBG_ClearSysWin(w->x20);
                FIELD_MSGBG_SysWinPrintStr(w->x20, 0, 0, (u32)w->x2C);
                SND_MIC_Exit();
                UI_ClearKeepAwakeFlagsGlobal(8);
                GAME_EVENT_CallEvent(proc, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(w->x04, 0, 30));
                *seq = 12;
            }
        }
        break;
    case 7:
        if (w->x54 == 1) {
            SND_MIC_StoreRecording(w->x00);
            SND_MIC_Exit();
            UI_ClearKeepAwakeFlagsGlobal(8);
            GAME_EVENT_CallEvent(proc, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(w->x04, 0, 30));
            *seq = 8;
        }
        break;
    case 8:
        if (EVENT_PERAP_RECORD_HopPokeIcon((u8 *)w) == 0) {
            a = func_02045EC0(w->x18, 2);
            func_0201EEF4(w->x28, 0, w->x14);
            func_0201F250(w->x28, w->x2C, a);
            STRBUF_Delete(a);
            FIELD_MSGBG_ClearSysWin(w->x20);
            FIELD_MSGBG_SysWinPrintStr(w->x20, 0, 0, (u32)w->x2C);
            *seq = 9;
        }
        break;
    case 9:
        if (FIELD_MSGBG_SysWinMain(w->x20) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        PM_VOICE_GetPerapVoiceSave((void **)(&buf));
        w->x50 = (void *)PM_VOICE_Play(0x1B9, 0, 64, 0, 0, 0, 0, (u32)(&buf));
        *seq = 11;
        break;
    case 11:
        if (PM_VOICE_IsActive((u32)w->x50) == 0) {
            *seq = 13;
        }
        break;
    case 12:
        if (FIELD_MSGBG_SysWinMain(w->x20) == 1) {
            *seq = 13;
        }
        break;
    case 13:
        EVENT_PERAP_RECORD_Cleanup(w);
        STRBUF_Delete(w->x2C);
        WORDSET_DeleteStrbufED04(w->x28);
        FIELD_MSGBG_DeleteSysWin((u32)w->x20);
        FIELD_MSGBG_DeleteMsgData(w->x18);
        *seq = 14;
        break;
    case 14:
        EVENT_PERAP_RECORD_ResumeMmdls((u32)w);
        return 1;
    }
    return 0;
}
