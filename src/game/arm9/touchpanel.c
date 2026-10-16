/*
 * file:     touchpanel.c
 * unit:     yes
 * function: TOUCHPANEL_GetWork, TOUCHPANEL_ReadPointX, TOUCHPANEL_ReadPointY, TOUCHPANEL_ReadCont, TOUCHPANEL_ReadTrg, TOUCHPANEL_Create, TOUCHPANEL_MainSys, TOUCHPANEL_Main, TOUCHPANEL_HitCircle, TOUCHPANEL_HitRect, TOUCHPANEL_SearchHitTable, TOUCHPANEL_HitContSys, TOUCHPANEL_HitCont, TOUCHPANEL_HitTrgSys, TOUCHPANEL_HitTrg, TOUCHPANEL_GetContSys, TOUCHPANEL_GetCont, TOUCHPANEL_GetTrgSys, TOUCHPANEL_GetTrg, TOUCHPANEL_GetPointContSys, TOUCHPANEL_GetPointCont, TOUCHPANEL_GetPointTrgSys, TOUCHPANEL_GetPointTrg, TOUCHPANEL_HitPoint, TOUCHPANEL_RequestAutoSamplingStop, TOUCHPANEL_AutoSamplingRestartSys, TOUCHPANEL_AutoSamplingRestart, TOUCHPANEL_AutoSamplingStopSys, TOUCHPANEL_AutoSamplingStop, TOUCHPANEL_RequestAutoSamplingStart, TOUCHPANEL_ClearFrameRateWork, TOUCHPANEL_SetPoint, TOUCHPANEL_SetTrg, TOUCHPANEL_SetCont
 * address:  0x02035750
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from touchpanel.c by tools/splitfile.py.
 *
 * symbols:
 *   UI_GetContext                     0x02035224  arm
 *   GFL_HEAP_Alloc                    0x02030734  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   TP_Init                          0x0208A924  arm
 *   TP_GetUserInfo                   0x0208A998  arm
 *   TP_SetCalibrateParam             0x0208AA2C  arm
 *   TP_RequestSamplingAsync          0x0208AB1C  arm
 *   TP_WaitRawResult                 0x0208ABB8  arm
 *   TP_RequestAutoSamplingStartAsync 0x0208AC0C  arm
 *   TP_RequestAutoSamplingStopAsync  0x0208AD14  arm
 *   TP_GetLatestRawPointInAuto       0x0208ADB4  arm
 *   TP_GetCalibratedPoint            0x0208B104  arm
 *   TP_WaitBusy                      0x0208B220  arm
 *   TP_CheckError                    0x0208B238  arm
 *   _pTouchPanelWork                 0x021469C4  data
 *   touchpanel_File                  0x020A798C  data
 */
#include "touchpanel_shared_types.h"

/* SDK TPData validity values */
#define TP_VALIDITY_VALID       0

#define TP_VALIDITY_INVALID_X   1

#define TP_VALIDITY_INVALID_Y   2

#define TP_VALIDITY_INVALID_XY  3

/* touch hit table codes (first byte of an entry) */
#define TOUCHPANEL_HIT_END      0xff

#define TOUCHPANEL_HIT_CIRCLE   0xfe

#define TOUCHPANEL_HIT_SKIP     0xfd

/* One entry of a touch hit table: a rectangle, or a circle when the first
 * byte is TOUCHPANEL_HIT_CIRCLE.  TOUCHPANEL_HIT_END ends the table. */
typedef union {
    struct {
        u8 top;
        u8 bottom;
        u8 left;
        u8 right;
    } rect;
    struct {
        u8 code;
        u8 x;
        u8 y;
        u8 r;
    } circle;
} TouchHitTable;

extern UiCtx *UI_GetContext(void);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern void MI_CpuFill8(void *dst, u8 val, u32 size);

extern void TP_Init(void);

extern int  TP_GetUserInfo(u16 *info);

extern void TP_SetCalibrateParam(u16 *info);

extern void TP_RequestSamplingAsync(void);

extern u32  TP_WaitRawResult(TPData *result);

extern void TP_RequestAutoSamplingStartAsync(u32 vcount, u32 freq, TPData *buf, u32 size);

extern void TP_RequestAutoSamplingStopAsync(void);

extern void TP_GetLatestRawPointInAuto(TPData *result);

extern void TP_GetCalibratedPoint(TPData *disp, const TPData *raw);

extern void TP_WaitBusy(u32 command);

extern u32  TP_CheckError(u32 command);

/* touchpanel.c */
TouchPanelWork *TOUCHPANEL_GetWork(void);

u16 TOUCHPANEL_ReadPointX(UiCtx *ui);

u16 TOUCHPANEL_ReadPointY(UiCtx *ui);

int TOUCHPANEL_ReadCont(UiCtx *ui);

u16 TOUCHPANEL_ReadTrg(UiCtx *ui);

TouchPanelWork *TOUCHPANEL_Create(u32 heapId);

void TOUCHPANEL_MainSys(UiCtx *ui);

void TOUCHPANEL_Main(void);

u32 TOUCHPANEL_HitCircle(const TouchHitTable *hit, s32 x, s32 y);

u32 TOUCHPANEL_HitRect(const TouchHitTable *hit, u32 x, u32 y);

int TOUCHPANEL_SearchHitTable(const TouchHitTable *tbl, u32 x, u32 y);

int TOUCHPANEL_HitContSys(UiCtx *ui, const TouchHitTable *tbl);

int TOUCHPANEL_HitCont(const TouchHitTable *tbl);

int TOUCHPANEL_HitTrgSys(UiCtx *ui, const TouchHitTable *tbl);

int TOUCHPANEL_HitTrg(const TouchHitTable *tbl);

int TOUCHPANEL_GetContSys(UiCtx *ui);

int TOUCHPANEL_GetCont(void);

u16 TOUCHPANEL_GetTrgSys(UiCtx *ui);

int TOUCHPANEL_GetTrg(void);

u32 TOUCHPANEL_GetPointContSys(UiCtx *ui, u32 *x, u32 *y);

u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y);

u32 TOUCHPANEL_GetPointTrgSys(UiCtx *ui, u32 *x, u32 *y);

u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);

u32 TOUCHPANEL_HitPoint(const TouchHitTable *tbl, u32 x, u32 y);

u32 TOUCHPANEL_RequestAutoSamplingStop(TouchPanelWork *tp);

void TOUCHPANEL_AutoSamplingRestartSys(UiCtx *ui);

void TOUCHPANEL_AutoSamplingRestart(void);

void TOUCHPANEL_AutoSamplingStopSys(UiCtx *ui);

void TOUCHPANEL_AutoSamplingStop(void);

u32 TOUCHPANEL_RequestAutoSamplingStart(TouchPanelWork *tp);

void TOUCHPANEL_ClearFrameRateWork(UiCtx *ui);

void TOUCHPANEL_SetPoint(UiCtx *ui, u16 x, u16 y, u16 x30, u16 y30);

void TOUCHPANEL_SetTrg(UiCtx *ui, int trg, int trg30);

void TOUCHPANEL_SetCont(UiCtx *ui, int cont, int cont30);

extern TouchPanelWork *_pTouchPanelWork;

extern const char touchpanel_File[];

/* ==================================================================
 * touchpanel.c
 * ================================================================== */
TouchPanelWork *TOUCHPANEL_GetWork(void)
{
    return _pTouchPanelWork;
}

/*
 * Point and button accessors: with the UI at 30 fps the values collected
 * over the frame pair are reported, otherwise the ones of this frame.
 * The work comes from TOUCHPANEL_GetWork and the frame rate from the argument,
 * which is why the argument is kept in r4 across the call.
 */
u16 TOUCHPANEL_ReadPointX(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->x30;
    return tp->x;
}

u16 TOUCHPANEL_ReadPointY(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->y30;
    return tp->y;
}

int TOUCHPANEL_ReadCont(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->cont30;
    return tp->cont;
}

u16 TOUCHPANEL_ReadTrg(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->trg30;
    return tp->trg;
}

/*
 * Allocates and clears the work, brings the touch panel up with the user
 * calibration (or a default one when none is stored).
 */
TouchPanelWork *TOUCHPANEL_Create(u32 heapId)
{
    u16 info[4];
    TouchPanelWork *tp = GFL_HEAP_Alloc(heapId, sizeof(TouchPanelWork), 0, touchpanel_File, 0x83);

    MI_CpuFill8(tp, 0, sizeof(TouchPanelWork));
    tp->autoSampleMode = 0;
    tp->autoSampleStopped = 0;
    TP_Init();
    if (TP_GetUserInfo(info) == 1) {
        TP_SetCalibrateParam(info);
    } else {
        info[0] = 0x2ae;
        info[1] = 0x58c;
        info[2] = 0xe25;
        info[3] = 0x1208;
        TP_SetCalibrateParam(info);
    }
    tp->autoSampleFreq = 4;
    tp->autoSampleIndex = 0;
    _pTouchPanelWork = tp;
    return tp;
}

/*
 * The per-frame sampling pass.  With the lid closed (bit 15 of the button
 * word at HW_BUTTON_XY_BUF) the work is cleared.  Otherwise the panel is
 * sampled (manual sampling retries up to 32 times), calibrated, and the
 * point and button state latched; every second frame the 30 fps values
 * take what was collected over the pair.
 *
 * Declaration facts that carry the register allocation: `raw` is declared
 * before `cal` (the converter's output `cal` is the sp+0 object), and the
 * work pointer is first bound to `tpTmp`, declared last, then copied into
 * `tp`; that copy keeps the loop counter in r4.
 */
void TOUCHPANEL_MainSys(UiCtx *ui)
{
    TPData raw;
    TPData cal;
    TouchPanelWork *tp;
    u32 done = 0;
    u32 n;
    TouchPanelWork *tpTmp = TOUCHPANEL_GetWork();

    tp = tpTmp;
    if (tp == 0) {
        return;
    }
    if ((s32)(*(u16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15 != 0) {
        MI_CpuFill8(tp, 0, sizeof(TouchPanelWork));
        return;
    }
    if (tp->autoSampleActive == 0) {
        n = 0;
        TP_RequestSamplingAsync();
        if (TP_WaitRawResult(&raw) != 0) {
            do {
                n = (n + 1) & 0xff;
                if (n >= 0x20) {
                    cal.validity = TP_VALIDITY_INVALID_XY;
                    done = 1;
                    break;
                }
                TP_RequestSamplingAsync();
            } while (TP_WaitRawResult(&raw) != 0);
        }
    } else {
        TP_GetLatestRawPointInAuto(&raw);
    }
    if (done == 0) {
        TP_GetCalibratedPoint(&cal, &raw);
    }
    if (cal.validity == TP_VALIDITY_VALID) {
        tp->x = cal.x;
        tp->y = cal.y;
    } else if (tp->cont != 0) {
        if (cal.validity != TP_VALIDITY_INVALID_X) {
            if (cal.validity == TP_VALIDITY_INVALID_Y) {
                tp->x = cal.x;
            }
        } else {
            tp->y = cal.y;
        }
    } else {
        cal.touch = 0;
    }
    tp->trg = cal.touch & (cal.touch ^ tp->cont);
    tp->cont = cal.touch;
    tp->pendTrg = tp->pendTrg | tp->trg;
    tp->pendCont = tp->pendCont | tp->cont;
    if (tp->y != 0) {
        tp->pendY = tp->y;
    }
    if (tp->x != 0) {
        tp->pendX = tp->x;
    }
    if (ui->frameCounter % 2 == 0) {
        tp->x30 = tp->pendX;
        tp->y30 = tp->pendY;
        tp->trg30 = tp->pendTrg;
        tp->cont30 = tp->pendCont;
        tp->pendX = 0;
        tp->pendY = 0;
        tp->pendTrg = 0;
        tp->pendCont = 0;
    }
}

void TOUCHPANEL_Main(void)
{
    TOUCHPANEL_MainSys(UI_GetContext());
}

/* Inside a circle entry: strictly closer than the radius. */
u32 TOUCHPANEL_HitCircle(const TouchHitTable *hit, s32 x, s32 y)
{
    s32 dx = hit->circle.x - x;
    s32 dy = hit->circle.y - y;
    u32 r = hit->circle.r;

    return (u32)(dx * dx + dy * dy) < r * r;
}

/* Inside a rectangle entry (unsigned range tests). */
u32 TOUCHPANEL_HitRect(const TouchHitTable *hit, u32 x, u32 y)
{
    if (x - hit->rect.left <= (u32)(hit->rect.right - hit->rect.left)
        && y - hit->rect.top <= (u32)(hit->rect.bottom - hit->rect.top))
        return 1;
    return 0;
}

/* Index of the first table entry the point falls inside, or -1. */
int TOUCHPANEL_SearchHitTable(const TouchHitTable *tbl, u32 x, u32 y)
{
    int i = 0;

    while (tbl[i].circle.code != TOUCHPANEL_HIT_END) {
        if (tbl[i].circle.code != TOUCHPANEL_HIT_SKIP) {
            if (tbl[i].circle.code == TOUCHPANEL_HIT_CIRCLE) {
                if (TOUCHPANEL_HitCircle(&tbl[i], x, y) != 0) {
                    return i;
                }
            } else {
                if (TOUCHPANEL_HitRect(&tbl[i], x, y) != 0) {
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}

int TOUCHPANEL_HitContSys(UiCtx *ui, const TouchHitTable *tbl)
{
    u32 x;
    u32 y;

    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadCont(ui) == 0) {
        return -1;
    }
    x = TOUCHPANEL_ReadPointX(ui);
    y = TOUCHPANEL_ReadPointY(ui);
    return TOUCHPANEL_SearchHitTable(tbl, x, y);
}

int TOUCHPANEL_HitCont(const TouchHitTable *tbl)
{
    return TOUCHPANEL_HitContSys(UI_GetContext(), tbl);
}

int TOUCHPANEL_HitTrgSys(UiCtx *ui, const TouchHitTable *tbl)
{
    u32 x;
    u32 y;

    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadTrg(ui) == 0) {
        return -1;
    }
    x = TOUCHPANEL_ReadPointX(ui);
    y = TOUCHPANEL_ReadPointY(ui);
    return TOUCHPANEL_SearchHitTable(tbl, x, y);
}

int TOUCHPANEL_HitTrg(const TouchHitTable *tbl)
{
    return TOUCHPANEL_HitTrgSys(UI_GetContext(), tbl);
}

int TOUCHPANEL_GetContSys(UiCtx *ui)
{
    TOUCHPANEL_GetWork();
    return TOUCHPANEL_ReadCont(ui);
}

int TOUCHPANEL_GetCont(void)
{
    return TOUCHPANEL_GetContSys(UI_GetContext());
}

u16 TOUCHPANEL_GetTrgSys(UiCtx *ui)
{
    TOUCHPANEL_GetWork();
    return TOUCHPANEL_ReadTrg(ui);
}

int TOUCHPANEL_GetTrg(void)
{
    return TOUCHPANEL_GetTrgSys(UI_GetContext());
}

u32 TOUCHPANEL_GetPointContSys(UiCtx *ui, u32 *x, u32 *y)
{
    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadCont(ui) == 0) {
        return 0;
    }
    *x = TOUCHPANEL_ReadPointX(ui);
    *y = TOUCHPANEL_ReadPointY(ui);
    return 1;
}

u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y)
{
    return TOUCHPANEL_GetPointContSys(UI_GetContext(), x, y);
}

u32 TOUCHPANEL_GetPointTrgSys(UiCtx *ui, u32 *x, u32 *y)
{
    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadTrg(ui) == 0) {
        return 0;
    }
    *x = TOUCHPANEL_ReadPointX(ui);
    *y = TOUCHPANEL_ReadPointY(ui);
    return 1;
}

u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y)
{
    return TOUCHPANEL_GetPointTrgSys(UI_GetContext(), x, y);
}

u32 TOUCHPANEL_HitPoint(const TouchHitTable *tbl, u32 x, u32 y)
{
    return (u32)TOUCHPANEL_SearchHitTable(tbl, (u16)x, (u16)y);
}

/* Stops auto sampling when it is used; 2 on a TP error, else 1. */
u32 TOUCHPANEL_RequestAutoSamplingStop(TouchPanelWork *tp)
{
    if (tp->autoSampleMode == 0) {
        return 1;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    if (TP_CheckError(4) != 0) {
        return 2;
    }
    return 1;
}

void TOUCHPANEL_AutoSamplingRestartSys(UiCtx *ui)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    if (tp != 0 && tp->autoSampleStopped != 0 && tp->autoSampleMode != 0) {
        TOUCHPANEL_RequestAutoSamplingStart(tp);
        tp->autoSampleStopped = 0;
    }
}

void TOUCHPANEL_AutoSamplingRestart(void)
{
    TOUCHPANEL_AutoSamplingRestartSys(UI_GetContext());
}

void TOUCHPANEL_AutoSamplingStopSys(UiCtx *ui)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    if (tp != 0 && tp->autoSampleStopped != 1 && tp->autoSampleMode != 0) {
        TOUCHPANEL_RequestAutoSamplingStop(tp);
        tp->autoSampleStopped = 1;
    }
}

void TOUCHPANEL_AutoSamplingStop(void)
{
    TOUCHPANEL_AutoSamplingStopSys(UI_GetContext());
}

/* Starts auto sampling into the work buffer; 1 when it started, else 2. */
u32 TOUCHPANEL_RequestAutoSamplingStart(TouchPanelWork *tp)
{
    u32 ret;

    TP_RequestAutoSamplingStartAsync(0, tp->autoSampleFreq, tp->autoSampleBuf, 9);
    ret = 2;
    TP_WaitBusy(2);
    if (TP_CheckError(2) == 0) {
        ret = 1;
    }
    return ret;
}

void TOUCHPANEL_ClearFrameRateWork(UiCtx *ui)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    tp->x30 = 0;
    tp->y30 = 0;
    tp->trg30 = 0;
    tp->cont30 = 0;
    tp->pendX = 0;
    tp->pendY = 0;
    tp->pendTrg = 0;
    tp->pendCont = 0;
}

void TOUCHPANEL_SetPoint(UiCtx *ui, u16 x, u16 y, u16 x30, u16 y30)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    tp->x30 = x30;
    tp->y30 = y30;
    tp->x = x;
    tp->y = y;
}

void TOUCHPANEL_SetTrg(UiCtx *ui, int trg, int trg30)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    tp->trg30 = (u16)trg30;
    tp->trg = (u16)trg;
}

void TOUCHPANEL_SetCont(UiCtx *ui, int cont, int cont30)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    tp->cont30 = (u16)cont30;
    tp->cont = (u16)cont;
}
