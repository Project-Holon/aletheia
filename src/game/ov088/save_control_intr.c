/*
 * file:     save_control_intr.c
 * unit:     yes
 * function: SAVE_CONTROL_INTR_Create, SAVE_CONTROL_INTR_Delete, SAVE_CONTROL_INTR_Start, SAVE_CONTROL_INTR_Update, SAVE_CONTROL_INTR_Pause, SAVE_CONTROL_INTR_Resume, SAVE_CONTROL_INTR_IsPausedOrFinished, SAVE_CONTROL_INTR_NoOp, SAVE_CONTROL_INTR_IsFinished, SAVE_CONTROL_INTR_Cancel
 * address:  0x021BD25C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02007210  0x02007210  thumb
 *   func_02030734  0x02030734  arm
 *   func_020071EC  0x020071EC  thumb
 *   func_020351F8  0x020351F8  arm
 *   SAVE_CONTROL_StartSave  0x02007150  thumb
 *   func_02008764  0x02008764  thumb
 *   func_02007218  0x02007218  thumb
 *   func_02007214  0x02007214  thumb
 *   func_0200721C  0x0200721C  thumb
 *   BACKUP_SYSTEM_IsFlashBusy  0x02031E70  arm
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   SAVE_CONTROL_CancelSave  0x020071A8  thumb
 */

struct Sub020071E4Ctrl;
struct Sub02007168;
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
extern u8 func_02007210(const struct Sub020071E4Ctrl *ctrl);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern unsigned char func_020071EC(const struct Sub020071E4Ctrl *);
extern void func_020351F8(u32 a, u32 b);
int SAVE_CONTROL_StartSave(int a0);
void func_02008764(void *);
u8 func_02007218(const struct Sub020071E4Ctrl *ctrl);
void func_02007214(void *, u32);
void func_0200721C(void *, u32);
extern int BACKUP_SYSTEM_IsFlashBusy(void);
extern u32 SAVE_CONTROL_MainSave(struct Sub02007168 *p);

/* Save progress object: drives a save that can be paused or cancelled. */
typedef struct SaveControlIntr {
    void *saveControl;
    u8 state; /* 0 idle, 1 saving, 2 paused, 3 finished */
    u8 stateBeforePause;
    u8 pauseRequested;
    u8 cancelled; /* 1: nothing to save, or the save was cancelled */
    u32 outsideSaveLoaded;
    u32 outsideSaveBroken;
} SaveControlIntr;






/*
 * func_020351F8 (arm) resolves through the matched entry
 * src/matched/arm9/UI_SetIntrDataGlobal.c.
 */
void *SAVE_CONTROL_INTR_Create(int heapId, int saveControl)
{
    SaveControlIntr *intr = (SaveControlIntr *)func_02030734(heapId, 0x10, 1, (const char *)0x021BDA0C, 0x45);
    intr->saveControl = (void *)saveControl;
    if (func_020071EC((const struct Sub020071E4Ctrl *)saveControl) == 1) {
        intr->cancelled = 1;
    } else {
        func_020351F8(0x021BD3B9, (int)intr);
    }
    return intr;
}

void SAVE_CONTROL_INTR_Delete(void *p)
{
    func_020351F8(0, 0);
    func_020307B0(p);
}



void SAVE_CONTROL_INTR_Start(SaveControlIntr *intr)
{
    if (intr->cancelled != 1) {
        SAVE_CONTROL_StartSave((int)intr->saveControl);
        if (intr->cancelled == 0) {
            func_02008764(intr->saveControl);
            intr->outsideSaveLoaded = func_02007210(intr->saveControl);
            intr->outsideSaveBroken = func_02007218(intr->saveControl);
            func_02007214(intr->saveControl, (u32)0);
            func_0200721C(intr->saveControl, (u32)0);
        }
        intr->state = 1;
    }
}

u32 SAVE_CONTROL_INTR_Update(SaveControlIntr *intr)
{
    u32 status;

    if (intr->cancelled == 1)
        return 2;
    switch (intr->state) {
    case 1:
        if (intr->pauseRequested == 1 && BACKUP_SYSTEM_IsFlashBusy() == 0) {
            intr->stateBeforePause = intr->state;
            intr->state = 2;
            return 0;
        }
        status = SAVE_CONTROL_MainSave(intr->saveControl);
        if (status - 2 <= 1) {
            intr->state = 3;
            func_02007214(intr->saveControl, intr->outsideSaveLoaded);
            func_0200721C(intr->saveControl, intr->outsideSaveBroken);
        }
        return status;
    case 2:
        if (intr->pauseRequested == 0)
            intr->state = intr->stateBeforePause;
        return 0;
    case 3:
        return 2;
    }
    return 0;
}

void SAVE_CONTROL_INTR_Pause(SaveControlIntr *intr){if(intr->state!=3)intr->pauseRequested=1;}
/*
 * Unlabelled Thumb leaf in a .word run at ov088:021BD374.  The caller
 * func_021BE6E8 lives in ov204 (0x021BDA40..), which does not overlap ov088
 * (0x021B95A0..0x021BDA20), the only overlay in the window that its own
 * window does not overlap, so ov088 is the resident copy.
 */
void SAVE_CONTROL_INTR_Resume(SaveControlIntr *intr)
{
    if (intr->state != 3)
        intr->pauseRequested = 0;
}



int SAVE_CONTROL_INTR_IsPausedOrFinished(SaveControlIntr *intr){if(intr->cancelled==1||intr->state==3)return 1;if(intr->state==2)return 1;return 0;}



/*
 * Unlabelled Thumb leaf in a .word run at ov088:021BD39C: `bx lr` (2 bytes),
 * an empty function called as a no-op by INTRO_CMD_CmdSaveNoOp.  ov088 is the only
 * overlay in the window not overlapping the caller's ov204.
 */
void SAVE_CONTROL_INTR_NoOp(int a0)
{
}



/*
 * Unlabelled 24-byte predicate. Parent cleared this sole blocker of
 * ov204:021BE708 after SDK/ownership/unit/shard audit. Same object at p+a4
 * is passed by matched ov204:021BE6E8/021BE6F8 to ov088:021BD374/021BD39C;
 * ov204:021BEF20 initializes it from input d+c. Matched ov088:021BD3B8
 * reads the same byte fields (7 and 4), confirming the region inference.
 */
int SAVE_CONTROL_INTR_IsFinished(SaveControlIntr *intr)
{
    if (intr->cancelled == 1)
        return 1;
    if (intr->state == 3)
        return 1;
    return 0;
}


void SAVE_CONTROL_INTR_Cancel(SaveControlIntr *intr)
{
    if (intr->cancelled == 0 && intr->state != 3) {
        SAVE_CONTROL_CancelSave(intr->saveControl);
        intr->cancelled = 1;
    }
}
