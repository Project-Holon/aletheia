/*
 * function: BTLV_INPUT_ChangeScreen
 * address:  0x0220270C
 * packet:   pkt_ov094_0220270C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BTLV_INPUT_ClearButtonState  0x022056B4  thumb  ov094
 *   BTLV_INPUT_StartBgScrollTask  0x022043C0  thumb  ov094
 *   BTLV_INPUT_StartBgScrollOffsetTask  0x02204960  thumb  ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 *   func_02030734  0x02030734  arm
 *   BTLV_EFFECT_StartIntroEffect  0x021F8A78  thumb  ov094
 *   BTLV_INPUT_DeleteWazaCursorActors  0x02205E30  thumb  ov094
 *   BTLV_INPUT_DeleteActionButtonActors  0x02205AB8  thumb  ov094
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_INPUT_RegisterTask  0x0220684C  thumb  ov094
 *   PALANM_RequestFadeOverwrite  0x02021848  thumb
 *   CLACT_GetUnitDrawEnable  0x0204B248  arm
 *   CLACT_SetUnitDrawEnable  0x0204B22C  arm
 *   BTLV_INPUT_PrepareCommandSelect  0x022067E8  thumb  ov094
 *   BTLV_EFFECT_SetIntroState  0x021F8A40  thumb  ov094
 *   BTLV_INPUT_ClearSlotEvents  0x0220680C  thumb  ov094
 *   BTLV_EFFECT_IsRecordAllowed  0x021F8914  thumb  ov094
 *   BTLV_INPUT_CreateActionButtons  0x022057CC  thumb  ov094
 *   BTLV_INPUT_CreateStatusIcons  0x02205B90  thumb  ov094
 *   BTLV_INPUT_GetMessageBoxMode  0x02206A7C  thumb  ov094
 *   BTLV_INPUT_DrawRunButtonText  0x02206728  thumb  ov094
 *   BTLV_INPUT_SetActionUnitVisible  0x02205B80  thumb  ov094
 *   BTLV_INPUT_CreateWazaCursorActors  0x02205D58  thumb  ov094
 *   BTLV_INPUT_DrawWazaButtons  0x02204CC0  thumb  ov094
 *   BTLV_EFFECT_ResetIntroState  0x021F8AC0  thumb  ov094
 *   BTLV_EFFECT_StartEffect  0x021F7998  thumb  ov094
 *   BTLV_INPUT_DrawTargetButtons  0x022050F0  thumb  ov094
 *   BTLV_INPUT_DrawMessageText  0x02205340  thumb  ov094
 *   BTLV_INPUT_InitButtonState  0x022053DC  thumb  ov094
 *   BTLV_INPUT_DrawSelectScreenText  0x0220558C  thumb  ov094
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BTLV_INPUT_TaskEndClearBusyBit  0x022043AC  thumb  ov094
 *   BTLV_INPUT_WaitScreenOpenTask  0x02203BC0  thumb  ov094
 *   BTLV_INPUT_WaitScreenOpenInstantTask  0x02203C2C  thumb  ov094
 *   BTLV_INPUT_ActionScreenOpenInstantTask  0x02203978  thumb  ov094
 *   BTLV_INPUT_ActionScreenOpenTask  0x022035C0  thumb  ov094
 *   BTLV_INPUT_WazaScreenCloseTask  0x02203B08  thumb  ov094
 *   BTLV_INPUT_WazaScreenOpenTask  0x022036C4  thumb  ov094
 *   BTLV_INPUT_WazaScreenOpenInstantTask  0x02203880  thumb  ov094
 *   BTLV_INPUT_TargetScreenOpenTask  0x02203A78  thumb  ov094
 *   BTLV_INPUT_MessageScreenOpenTask  0x02203D40  thumb  ov094
 *   BTLV_INPUT_ListScreenOpenTask  0x02203E30  thumb  ov094
 *   BTLV_INPUT_ListScreenOpenInstantTask  0x022041E0  thumb  ov094
 *   BTLV_INPUT_SelectScreenOpenTask  0x02203FDC  thumb  ov094
 *   BTLV_INPUT_ConfirmScreenOpenTask  0x022040FC  thumb  ov094
 *   d_0220AEB0     0x0220AEB0  data
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct F68 {
    u32 b0 : 1;
    u32 b1 : 3;
    u32 b4 : 1;
    u32 b5 : 4;
    u32 b9 : 4;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 mode : 2;
    u32 b17 : 2;
    u32 b19 : 2;
    u32 b21 : 2;
    u32 b23 : 4;
    u32 b27 : 5;
} F68;

typedef struct F6C {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 x : 8;
    u32 rest : 22;
} F6C;

typedef struct T12 {
    int v[3];
} T12;

typedef struct Task {
    char *s;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    void *f1c;
    int f20;
} Task;

typedef struct Arg1 {
    T12 a[6];
    T12 b[6];
    int f90;
    int f94;
    u8 pad98[0xbc - 0x98];
    int fbc;
    u8 padc0[5];
    u8 bc5;
} Arg1;

typedef struct Arg2 {
    u16 h[4];
    int f8;
    int fc;
    int f10;
    int f14;
} Arg2;

typedef struct Arg5 {
    int a[3];
    int b[3][4];
} Arg5;

typedef struct S5 {
    u8 pad[0x2a4];
    int a[3];
    int b[3][4];
} S5;

#define S_INT(o) (*(int *)(s + (o)))
#define S_PTR(o) (*(void **)(s + (o)))
#define F68_(s) (*(F68 *)((s) + 0x68))
#define F6C_(s) (*(F6C *)((s) + 0x6c))
#define HEAP(s) ((u16)((*(u16 *)((s) + 0x240) & 0x7fff) | 0x8000))

struct Bank;
struct Cfg;
struct Ctx;
struct Info;
struct Main;
struct MsgBank;
struct Out;
struct Slots;
struct U16Vec;
struct Work;
extern void BTLV_INPUT_ClearButtonState(struct Main *m);
extern void BTLV_INPUT_StartBgScrollTask(struct Main *m, int a1, int a2, int a3, int a4);
extern void BTLV_INPUT_StartBgScrollOffsetTask(struct Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern int PALANM_RequestFade(void *, u16, u16, s16, u8, u8, u16, void *);
extern int PALANM_RequestFadeOverwrite(void *, u16, u16, s16, u8, u8, u16, void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
struct Ctx;
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);
extern void BTLV_EFFECT_StartIntroEffect(void);
extern void BTLV_INPUT_DeleteWazaCursorActors(char *);
extern void BTLV_INPUT_DeleteActionButtonActors(char *);
extern u32 CLACT_GetUnitDrawEnable(struct Bank *bank);
extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);
extern void BTLV_INPUT_PrepareCommandSelect(char *);
extern void BTLV_EFFECT_SetIntroState(int);
extern void BTLV_INPUT_ClearSlotEvents(char *);
extern int BTLV_EFFECT_IsRecordAllowed(void);
extern void BTLV_INPUT_CreateActionButtons(struct Main *m, struct Info *q);
extern void BTLV_INPUT_CreateStatusIcons(char *, int);
extern int BTLV_INPUT_GetMessageBoxMode(char *);
extern void BTLV_INPUT_DrawRunButtonText(char *s, char *b);
extern void BTLV_INPUT_SetActionUnitVisible(char *, int);
extern void BTLV_INPUT_CreateWazaCursorActors(char *, int);
extern void BTLV_INPUT_DrawWazaButtons(struct Work *p, const struct Slots *q);
extern void BTLV_EFFECT_ResetIntroState(int);
extern void BTLV_EFFECT_StartEffect(u32);
extern void BTLV_INPUT_DrawTargetButtons(char *s, struct Out *out, const struct Info *p);
extern void BTLV_INPUT_DrawMessageText(struct Main *m, const int *c);
extern void BTLV_INPUT_InitButtonState(char *);
extern void BTLV_INPUT_DrawSelectScreenText(char *s, const int *b);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BG_SYS_PushTile(u32 index);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void BTLV_INPUT_TaskEndClearBusyBit(void *);
extern void BTLV_INPUT_WaitScreenOpenTask(int a0, struct Ctx *c);
extern void BTLV_INPUT_WaitScreenOpenInstantTask(void *task, struct Ctx *c);
extern void BTLV_INPUT_ActionScreenOpenInstantTask(void *task, struct Ctx *c);
extern void BTLV_INPUT_ActionScreenOpenTask(void *task, struct Ctx *c);
extern void BTLV_INPUT_WazaScreenCloseTask(int a0, struct Ctx *c);
extern void BTLV_INPUT_WazaScreenOpenTask(void *task, struct Ctx *c);
extern void BTLV_INPUT_WazaScreenOpenInstantTask(void *task, struct Ctx *c);
extern void BTLV_INPUT_TargetScreenOpenTask(int a0, struct Ctx *c);
extern void BTLV_INPUT_MessageScreenOpenTask(void *, void *);
extern void BTLV_INPUT_ListScreenOpenTask(void *, void *);
extern void BTLV_INPUT_ListScreenOpenInstantTask(void *, void *);
extern void BTLV_INPUT_SelectScreenOpenTask(void *, void *);
extern void BTLV_INPUT_ConfirmScreenOpenTask(void *, void *);

extern const char d_0220AEB0[];

void BTLV_INPUT_ChangeScreen(char *s, int mode, void *arg)
{
    Task *t;
    void *w;
    int i;
    int j;

    BTLV_INPUT_ClearButtonState((struct Main *)s);
    F68_(s).b23 = 0;
    F6C_(s).b0 = 1;
    switch (mode) {
    case 0:
        S_INT(0x70) = -1;
        if (S_INT(0x58) == 0) {
            BTLV_INPUT_StartBgScrollTask((struct Main *)s, 0x3000, 0x3000, 0, 0x98);
            BTLV_INPUT_StartBgScrollOffsetTask((struct Main *)s, -1, 0, 0, 0, 0, 2, 1);
            PALANM_RequestFade(S_PTR(0x64), 2, 3, 1, 12, 12, 0x842, S_PTR(0));
        } else {
            t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x549);
            F68_(s).b0 = 1;
            t->s = s;
            if (S_INT(0x23c) == 1)
                BTLV_EFFECT_StartIntroEffect();
            BTLV_INPUT_DeleteWazaCursorActors(s);
            BTLV_INPUT_DeleteActionButtonActors(s);
            if (S_INT(0x58) == 1 || S_INT(0x58) == 4) {
                BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_WaitScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
            } else {
                t->f20 = S_INT(0x58);
                BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_WaitScreenOpenInstantTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
            }
            PALANM_RequestFadeOverwrite(S_PTR(0x64), 2, 3, 1, 0, 12, 0x842, S_PTR(0));
            if (CLACT_GetUnitDrawEnable(S_PTR(0x17c)) != 0) {
                F68_(s).b5 = 0;
                F68_(s).b9 = 15;
                F68_(s).b13 = 1;
                CLACT_SetUnitDrawEnable(S_PTR(0x17c), 0);
            }
        }
        break;
    case 1: {
        Arg1 *a = arg;
        Task *t1;
        t1 = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x570);
        S_INT(0x278) = a->fbc;
        BTLV_INPUT_PrepareCommandSelect(s);
        BTLV_EFFECT_SetIntroState(2);
        if (a->fbc >= 2)
            a->fbc = (a->fbc - 2) / 2;
        F68_(s).b0 = 1;
        F68_(s).b4 = a->f90;
        t1->s = s;
        t1->f8 = a->fbc;
        S_INT(0x27c) = a->fbc;
        if (S_INT(0x58) == 0)
            BTLV_INPUT_ClearSlotEvents(s);
        for (i = 0; i < 6; i++) {
            ((T12 *)(s + 0x74))[i] = a->a[i];
            ((T12 *)(s + 0xbc))[i] = a->b[i];
        }
        for (j = 0; j < 4; j++)
            s[0x25a + j] = 1;
        s[0x25b] = BTLV_EFFECT_IsRecordAllowed();
        BTLV_INPUT_DeleteActionButtonActors(s);
        BTLV_INPUT_CreateActionButtons((struct Main *)s, (struct Info *)a);
        BTLV_INPUT_CreateStatusIcons(s, a->bc5);
        t1->fc = BTLV_INPUT_GetMessageBoxMode(s);
        BTLV_INPUT_DrawRunButtonText(s, (char *)a);
        if (S_INT(0x58) == 2 || S_INT(0x58) == 5) {
            BTLV_INPUT_SetActionUnitVisible(s, 0);
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_ActionScreenOpenInstantTask, t1, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_CreateWazaCursorActors(s, 0);
            if (a->f94 != 0)
                BTLV_INPUT_CreateWazaCursorActors(s, 1);
            F68_(s).b14 = a->f94;
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_ActionScreenOpenTask, t1, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 2: {
        Arg2 *a = arg;
        Task *t2;
        t2 = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5bd);
        BTLV_INPUT_DrawWazaButtons((struct Work *)s, (const struct Slots *)a);
        F68_(s).b0 = 1;
        t2->s = s;
        t2->f8 = a->f10;
        S_INT(0x280) = a->f14;
        t2->fc = BTLV_INPUT_GetMessageBoxMode(s);
        for (j = 0; j < 4; j++)
            ((u16 *)(s + 0x26c))[j] = a->h[j];
        if (S_INT(0x23c) == 1 && (S_INT(0x50) == 1 || S_INT(0x50) == 2)) {
            BTLV_EFFECT_ResetIntroState(2);
            BTLV_EFFECT_StartEffect(0x244);
        }
        if (S_INT(0x58) == 3) {
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_WazaScreenCloseTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else if (S_INT(0x58) == 0) {
            BTLV_INPUT_CreateWazaCursorActors(s, 0);
            if (F68_(s).b14)
                BTLV_INPUT_CreateWazaCursorActors(s, 1);
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_WazaScreenOpenTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_DeleteActionButtonActors(s);
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_WazaScreenOpenInstantTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 3:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5ec);
        BTLV_INPUT_DrawTargetButtons(s, (struct Out *)t, arg);
        F68_(s).b0 = 1;
        t->s = s;
        t->f8 = ((u8 *)arg)[0x48];
        BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))BTLV_INPUT_TargetScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        break;
    case 4:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5f8);
        BTLV_INPUT_DrawMessageText((struct Main *)s, arg);
        F68_(s).b0 = 1;
        t->s = s;
        F6C_(s).b0 = ((int *)arg)[2];
        BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), BTLV_INPUT_MessageScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        break;
    case 5: {
        Arg5 *a = arg;
        int k;
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x605);
        if (S_INT(0x58) != 0) {
            F68_(s).b17 = 0;
            F68_(s).b19 = 0;
        }
        for (i = 0; i < 3; i++) {
            ((S5 *)s)->a[i] = a->a[i];
            for (k = 0; k < 4; k++)
                ((S5 *)s)->b[i][k] = a->b[i][k];
        }
        BTLV_INPUT_InitButtonState(s);
        F68_(s).b0 = 1;
        t->s = s;
        if (S_INT(0x58) == 0) {
            BTLV_INPUT_CreateWazaCursorActors(s, 0);
            if (F68_(s).b14)
                BTLV_INPUT_CreateWazaCursorActors(s, 1);
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), BTLV_INPUT_ListScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), BTLV_INPUT_ListScreenOpenInstantTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 6: {
        Arg2 *a = arg;
        w = 0;
        for (j = 0; j < 3; j++)
            s[0x25a + j] = 1;
        BTLV_INPUT_DrawSelectScreenText(s, (const int *)a);
        switch (a->fc) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            GF_FONT_SetTextColor(1, 2, 0);
            w = func_02045EC0(S_PTR(0x5c), a->fc + 8);
            break;
        }
        if (S_INT(0x58) == 0) {
            t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x65f);
            F68_(s).b0 = 1;
            t->s = s;
            if (a->fc == 0) {
                t->f10 = 0;
                t->f14 = 0x100;
            } else {
                t->f10 = 0x100;
                t->f14 = 0;
            }
            t->f1c = w;
            BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), BTLV_INPUT_SelectScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            if (a->fc == 0)
                BTLV_INPUT_StartBgScrollOffsetTask((struct Main *)s, 4, 0, 0x100, 2, 2, 2, 2);
            else
                BTLV_INPUT_StartBgScrollOffsetTask((struct Main *)s, 4, 0x100, 0, 2, 2, 2, 2);
            if (w != 0) {
                PRINTSYS_Print((void *)S_INT(0x22c), 0x18, 0x38, w, (void *)S_INT(0x224));
                STRBUF_Delete(w);
            }
            BMP_WIN_MakeScreen(S_PTR(0x228));
            BG_SYS_PushTile(6);
            BMP_WIN_TransferChars(S_PTR(0x228));
        }
        break;
    }
    case 7:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x68c);
        F68_(s).b0 = 1;
        t->s = s;
        BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(S_PTR(0), BTLV_INPUT_ConfirmScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        s[0x25a] = 1;
        s[0x25b] = 1;
        break;
    }
    S_INT(0x58) = mode;
}
