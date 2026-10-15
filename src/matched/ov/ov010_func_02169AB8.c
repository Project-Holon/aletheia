/*
 * function: REPORT_EVENT_Main
 * address:  0x02169AB8
 * packet:   pkt_ov010_02169AB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 21-state setup and teardown machine of the ov010 program. First
 * draft; the call at 0x021A153C reaches an ov021 Thumb thunk
 * (`ldr r0, [r0, #0x20]; ldr r3, =target; bx r3`), declared `thumb ov021`
 * (the ISA evidence honours the ovNNN hint since tooling_3).
 *
 * symbols:
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_IsReportReady  0x021A1518  thumb  ov021
 *   FIELD_SUBSCREEN_PrepareReportSave  0x021A1524  thumb  ov021
 *   FIELD_SUBSCREEN_CheckReportSaveCounter  0x021A1554  thumb  ov021
 *   FIELD_SUBSCREEN_StartReportSaveAnim  0x021A1530  thumb  ov021
 *   FIELD_SUBSCREEN_StopReportSaveAnim  0x021A1548  thumb  ov021
 *   FIELD_SUBSCREEN_IsReportSaveAnimDone  0x021A153C  thumb  ov021
 *   FIELD_SUBSCREEN_ResumeField  0x021A0FB4  thumb  ov021
 *   func_02028590  0x02028590  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_020071F0  0x020071F0  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   GFL_USE_IsSeqPlaying  0x02006254  thumb
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   TCBL_Create  0x0203101C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   REPORT_EVENT_Free  0x02169E0C  thumb  ov010
 *   REPORT_EVENT_CreateMessageWindow  0x02169E4C  thumb  ov010
 *   REPORT_EVENT_PrintMessage  0x02169EA4  thumb  ov010
 *   REPORT_EVENT_StartPrintStream  0x02169EBC  thumb  ov010
 *   REPORT_EVENT_UpdateMessage  0x02169FB8  thumb  ov010
 *   REPORT_EVENT_QueueMessage  0x02169FFC  thumb  ov010
 *   REPORT_EVENT_UpdateMessageQueue  0x0216A07C  thumb  ov010
 *   REPORT_EVENT_CreateMenuResources  0x0216A0BC  thumb  ov010
 *   REPORT_EVENT_OpenYesNoMenu  0x0216A148  thumb  ov010
 *   REPORT_EVENT_UpdateYesNoMenu  0x0216A184  thumb  ov010
 *   REPORT_EVENT_BeginAvatarAnim  0x0216A1C0  thumb  ov010
 *   REPORT_EVENT_EndAvatarAnim  0x0216A1F8  thumb  ov010
 *   REPORT_EVENT_IsAvatarRequestDone  0x0216A21C  thumb  ov010
 *   REPORT_EVENT_IsAvatarReady  0x0216A244  thumb  ov010
 *   REPORT_EVENT_StartSaveEffect  0x0216A264  thumb  ov010
 *   REPORT_EVENT_StopSaveEffect  0x0216A280  thumb  ov010
 *   d_02172A50     0x02172A50  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u8 pad20[0x44 - 0x20];
    u8 *f44;            /* 0x44 */
    u8 pad48[0x4C - 0x48];
    u32 f4C;            /* 0x4C */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

extern int REPORT_EVENT_Free(char *a0);
extern void REPORT_EVENT_CreateMessageWindow(int a0);
extern void REPORT_EVENT_PrintMessage(Work *w, u32 n);
extern void REPORT_EVENT_StartPrintStream(Work *w);
extern int REPORT_EVENT_UpdateMessage(int a0);
extern void REPORT_EVENT_QueueMessage(Work *w, u32 n);
extern int REPORT_EVENT_UpdateMessageQueue(Work *w);
extern void REPORT_EVENT_CreateMenuResources(Work *w);
extern void REPORT_EVENT_OpenYesNoMenu(Work *w);
extern int REPORT_EVENT_UpdateYesNoMenu(int a0);
extern int REPORT_EVENT_BeginAvatarAnim(int a0);
extern void REPORT_EVENT_EndAvatarAnim(int a0);
extern int REPORT_EVENT_IsAvatarRequestDone(int a0);
struct Ctx;
struct MsgBank;
struct Sub020071E4Ctrl;
struct Sub02008C20Obj;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern int REPORT_EVENT_IsAvatarReady(void *a0);
extern int REPORT_EVENT_StartSaveEffect(int a0);
extern int REPORT_EVENT_StopSaveEffect(int a0);

extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);
extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern int FIELD_SUBSCREEN_IsReportReady(u32 *p);
extern void FIELD_SUBSCREEN_PrepareReportSave(u32 *p);
extern int FIELD_SUBSCREEN_CheckReportSaveCounter(u32 *p);
extern void FIELD_SUBSCREEN_StartReportSaveAnim(u32 *p);
extern void FIELD_SUBSCREEN_StopReportSaveAnim(u32 *p);
extern int FIELD_SUBSCREEN_IsReportSaveAnimDone(u32 *p);
extern void FIELD_SUBSCREEN_ResumeField(u32 *p, u32 a);

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void BMP_MENUWORK_DrawWindowBorder(void *p, u32 kind);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern int GAME_DATA_SaveStart(int a0);
extern int GAME_DATA_SaveMain(u8 *p);
extern void TIME_ICON_Delete(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern u32 KEY_GetTrg(void);

extern const char d_02172A50[];

int REPORT_EVENT_Main(Work *w, u32 *state)
{
    void *ws;
    void *str;

    switch (*state) {
    case 0:
        FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(w->f08), 7);
        *state = 1;
        break;
    case 1:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(w->f08)) == 1
            && FIELD_SUBSCREEN_IsReportReady((u32 *)FIELDMAP_GetSubscreen(w->f08)) == 1) {
            w->f18 = func_02030734(w->f10, 0x50, 0, d_02172A50, 0x9F);
            w->f18->f04 = func_02045B38(0, 3, 0x9E, w->f10);
            w->f18->f18 = STRBUF_Create(0x200, w->f10);
            w->f18->f00 = TCBL_Create(w->f10, w->f10, 1, 4);
            w->f18->f1C = func_02028590(0xF, 1, 1, w->f10);
            w->f18->f14 = PRINTSYS_QUE_Create((void *)w->f10);
            w->f18->f4C = 0;
            REPORT_EVENT_CreateMessageWindow((int)w);
            REPORT_EVENT_CreateMenuResources(w);
            *state = 2;
        }
        break;
    case 2:
        REPORT_EVENT_PrintMessage(w, 2);
        *state = 3;
        break;
    case 3:
        if (REPORT_EVENT_UpdateMessage((int)w) == 0) {
            REPORT_EVENT_OpenYesNoMenu(w);
            *state = 4;
        }
        break;
    case 4:
        switch (REPORT_EVENT_UpdateYesNoMenu((int)w)) {
        case 0:
            if (func_020071F0(w->f00) == 1) {
                REPORT_EVENT_PrintMessage(w, 8);
                *state = 0xE;
            } else {
                BMP_MENUWORK_DrawWindowBorder(w->f18->f08, 1);
                *state = 5;
            }
            break;
        case 1:
            *state = 0x11;
            break;
        }
        break;
    case 5:
        func_02008DF0(GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData(w->f04)), 1);
        FIELD_SUBSCREEN_PrepareReportSave((u32 *)FIELDMAP_GetSubscreen(w->f08));
        if (FIELD_SUBSCREEN_CheckReportSaveCounter((u32 *)FIELDMAP_GetSubscreen(w->f08)) == 1)
            REPORT_EVENT_QueueMessage(w, 10);
        else
            REPORT_EVENT_QueueMessage(w, 4);
        *state = 6;
        break;
    case 6:
        if (REPORT_EVENT_UpdateMessageQueue(w) == 1) {
            REPORT_EVENT_BeginAvatarAnim((int)w);
            *state = 7;
        }
        break;
    case 7:
        if (REPORT_EVENT_IsAvatarRequestDone((int)w) == 1)
            *state = 8;
        break;
    case 8:
        if (REPORT_EVENT_IsAvatarReady(w) != 0) {
            w->f18->f44 = TIME_ICON_Create((void *)func_020056BC(), w->f18->f08, 0xF, 0x10, w->f10);
            FIELD_SUBSCREEN_StartReportSaveAnim((u32 *)FIELDMAP_GetSubscreen(w->f08));
            REPORT_EVENT_StartSaveEffect((int)w);
            GAME_DATA_SaveStart((int)GAMESYSTEM_GetGameData(w->f04));
            *state = 9;
        }
        break;
    case 9:
        switch (GAME_DATA_SaveMain(GAMESYSTEM_GetGameData(w->f04))) {
        case 0:
        case 1:
            break;
        case 2:
            *state = 10;
            break;
        case 3:
            FIELD_SUBSCREEN_StopReportSaveAnim((u32 *)FIELDMAP_GetSubscreen(w->f08));
            REPORT_EVENT_StopSaveEffect((int)w);
            REPORT_EVENT_EndAvatarAnim((int)w);
            REPORT_EVENT_PrintMessage(w, 7);
            TIME_ICON_Delete(w->f18->f44);
            *state = 0xD;
            break;
        }
        break;
    case 10:
        if (FIELD_SUBSCREEN_IsReportSaveAnimDone((u32 *)FIELDMAP_GetSubscreen(w->f08)) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x558);
            REPORT_EVENT_StopSaveEffect((int)w);
            REPORT_EVENT_EndAvatarAnim((int)w);
            ws = GF_FONT_Create_EC64(w->f10);
            str = func_02045EC0(w->f18->f04, 5);
            WORDSET_SetSlotMyStatus(ws, 0, GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(w->f04)));
            WORDSET_CopyTaggedText(ws, w->f18->f18, str);
            STRBUF_Delete(str);
            WORDSET_DeleteStrbufED04(ws);
            REPORT_EVENT_StartPrintStream(w);
            TIME_ICON_Delete(w->f18->f44);
            *state = 0xB;
        }
        break;
    case 11:
        if (REPORT_EVENT_IsAvatarRequestDone((int)w) == 1 && REPORT_EVENT_IsAvatarReady(w) != 0 && REPORT_EVENT_UpdateMessage((int)w) == 0)
            *state = 0xC;
        break;
    case 12:
        if (GFL_USE_IsSeqPlaying(0x558) == 0)
            *state = 0x10;
        break;
    case 13:
        if (REPORT_EVENT_IsAvatarRequestDone((int)w) != 1 || REPORT_EVENT_IsAvatarReady(w) == 0)
            break;
        *state = 0xE;
    case 14:
        if (REPORT_EVENT_UpdateMessage((int)w) == 0)
            *state = 0xF;
        break;
    case 15:
        if (KEY_GetTrg() & 3)
            *state = 0x13;
        break;
    case 16:
        if (KEY_GetTrg() & 3)
            *state = 0x13;
        if (w->f18->f4C >= 150)
            *state = 0x13;
        else
            w->f18->f4C++;
        break;
    case 17:
        REPORT_EVENT_Free((char *)w);
        FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(w->f08), 1);
        *state = 0x12;
        break;
    case 18:
        return 1;
    case 19:
        REPORT_EVENT_Free((char *)w);
        FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(w->f08), 0);
        *state = 0x14;
        break;
    case 20:
        FIELD_SUBSCREEN_ResumeField((u32 *)FIELDMAP_GetSubscreen(w->f08), w->f10);
        return 0;
    }
    return 2;
}
