/*
 * file:     field_flash.c
 * unit:     yes
 * function: FIELD_FLASH_Create, FIELD_FLASH_Delete, FIELD_FLASH_Update, FIELD_FLASH_Apply, FIELD_FLASH_SetPendingCommand, FIELD_FLASH_GetState, FIELD_FLASH_InitTween, FIELD_FLASH_ClearTween, FIELD_FLASH_StartTween, FIELD_FLASH_StepTween, FIELD_FLASH_GetTweenSize, FIELD_FLASH_SetTweenSize, FIELD_FLASH_GetTweenAlpha, FIELD_FLASH_SetTweenAlpha, FIELD_FLASH_CmdInit, FIELD_FLASH_CmdExpand, FIELD_FLASH_ShowExpanded, FIELD_FLASH_HideMask
 * address:  0x021C7DAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_task_manager.c, field_flash.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   gFieldFlashFileName  0x021DE4FC  data  ov021  a4
 *   gFlashCommandTable  0x021DAAD0  data  ov021  a4
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0207C768  0x0207C768  arm
 *   FLD_WIPE_3DOBJ_Create 0x021C8018 thumb ov021
 *   FLD_WIPE_3DOBJ_Delete 0x021C8054 thumb ov021
 *   FLD_WIPE_3DOBJ_Draw 0x021C8078 thumb ov021
 */
#include "field_task_types.h"
#include "field_flash_shared_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

enum FlashState {
    FLASH_STATE_OFF = 0,
    FLASH_STATE_READY = 1,
    FLASH_STATE_EXPANDING = 2,
    FLASH_STATE_EXPANDED = 3
};

extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

extern void MI_CpuFill8(void *dst, int value, int size);

extern u32 func_0207C768(u32 a, u32 b);

extern char gFieldFlashFileName[];

extern void (*gFlashCommandTable[])(FieldFlash *flash);

FieldFlash *FIELD_FLASH_Create(u32 heapId);

void FIELD_FLASH_Delete(FieldFlash *flash);

void FIELD_FLASH_Update(FieldFlash *flash);

void FIELD_FLASH_Apply(FieldFlash *flash);

void FIELD_FLASH_SetPendingCommand(FieldFlash *flash, u16 command);

u16 FIELD_FLASH_GetState(FieldFlash *flash);

void FIELD_FLASH_InitTween(FlashTween *tween);

void FIELD_FLASH_ClearTween(FlashTween *tween);

FlashTween *FIELD_FLASH_StartTween(FlashTween *tween, fx32 sizeStart, fx32 sizeEnd, u32 alphaStart, u8 alphaEnd, u32 frames);

int FIELD_FLASH_StepTween(FlashTween *tween);

u32 FIELD_FLASH_GetTweenSize(FlashTween *tween);

void FIELD_FLASH_SetTweenSize(FlashTween *tween, fx32 size);

u8 FIELD_FLASH_GetTweenAlpha(FlashTween *tween);

FlashTween *FIELD_FLASH_SetTweenAlpha(FlashTween *tween, u8 alpha);

void FIELD_FLASH_CmdInit(FieldFlash *flash);

void FIELD_FLASH_CmdExpand(FieldFlash *flash);

void FIELD_FLASH_ShowExpanded(FieldFlash *flash);

void FIELD_FLASH_HideMask(FieldFlash *flash);

FldWipe3dObj *FLD_WIPE_3DOBJ_Create(u32 heapId);

int FLD_WIPE_3DOBJ_Delete(FldWipe3dObj *obj);

void FLD_WIPE_3DOBJ_Draw(FldWipe3dObj *obj, int size, int alpha);

FieldFlash *FIELD_FLASH_Create(u32 heapId)
{
    FieldFlash *flash = func_02030734(heapId, sizeof(FieldFlash), 1, gFieldFlashFileName, 0x7a);
    flash->model = FLD_WIPE_3DOBJ_Create(heapId);
    flash->state = FLASH_STATE_OFF;
    flash->pendingCommand = FLASH_CMD_NONE;
    FIELD_FLASH_InitTween(&flash->tween);
    return flash;
}

void FIELD_FLASH_Delete(FieldFlash *flash)
{
    if (flash != 0) {
        FIELD_FLASH_ClearTween(&flash->tween);
        FLD_WIPE_3DOBJ_Delete(flash->model);
        func_020307B0(flash);
    }
}

/* Runs a pending command, then steps the tween while it expands. */
void FIELD_FLASH_Update(FieldFlash *flash)
{
    if (flash != 0) {
        if (flash->pendingCommand != FLASH_CMD_NONE) {
            gFlashCommandTable[flash->pendingCommand](flash);
            flash->pendingCommand = FLASH_CMD_NONE;
        }
        if (flash->state == FLASH_STATE_EXPANDING && FIELD_FLASH_StepTween(&flash->tween))
            flash->state = FLASH_STATE_EXPANDED;
    }
}

/* Applies the tween size and alpha to the mask model. */
void FIELD_FLASH_Apply(FieldFlash *flash)
{
    u32 size;
    if (flash != 0) {
        size = FIELD_FLASH_GetTweenSize(&flash->tween);
        FLD_WIPE_3DOBJ_Draw(flash->model, size, FIELD_FLASH_GetTweenAlpha(&flash->tween));
    }
}

void FIELD_FLASH_SetPendingCommand(FieldFlash *flash, u16 command)
{
    flash->pendingCommand = command;
}

/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the u16 at +0x1C (FIELD_FLASH_SetPendingCommand sets +0x1E).
 * Sole blocker of ov010 MOVE_POKEMON_FlashEventMain's MATCH.
 */
u16 FIELD_FLASH_GetState(FieldFlash *flash)
{
    return flash->state;
}

/* Tail-call thunk: pins arguments 2 and 3 to 0 and 24. */
void FIELD_FLASH_InitTween(FlashTween *tween)
{
    MI_CpuFill8(tween, 0, 24);
}

void FIELD_FLASH_ClearTween(FlashTween *tween)
{
    MI_CpuFill8(tween, 0, 24);
}

/* Starts a tween of size sizeStart..sizeEnd and alpha alphaStart..alphaEnd over `frames`. */
FlashTween *FIELD_FLASH_StartTween(FlashTween *tween, fx32 sizeStart, fx32 sizeEnd, u32 alphaStart, u8 alphaEnd, u32 frames)
{
    tween->size = sizeStart;
    tween->sizeStart = sizeStart;
    tween->sizeDelta = (sizeEnd - sizeStart);
    tween->alpha = alphaStart;
    tween->alphaStart = alphaStart;
    tween->alphaDelta = (alphaEnd - alphaStart);
    tween->frame = 0;
    tween->frames = frames;
    return tween;
}

/* Returns 1 once the tween has run its frames. */
int FIELD_FLASH_StepTween(FlashTween *tween)
{
    if (tween->frame < tween->frames) {
        tween->frame = tween->frame + 1;
        tween->size = tween->sizeStart + func_0207C768((int)(((long long)tween->sizeDelta * (tween->frame << 12) + 0x800) >> 12), tween->frames << 12);
        tween->alpha = tween->alphaStart + tween->alphaDelta * tween->frame / tween->frames;
        return 0;
    }
    return 1;
}

u32 FIELD_FLASH_GetTweenSize(FlashTween *tween)
{
    return tween->size;
}

void FIELD_FLASH_SetTweenSize(FlashTween *tween, fx32 size)
{
    tween->size = size;
}

u8 FIELD_FLASH_GetTweenAlpha(FlashTween *tween)
{
    return tween->alpha;
}

FlashTween *FIELD_FLASH_SetTweenAlpha(FlashTween *tween, u8 alpha)
{
    tween->alpha = alpha;
    return tween;
}

/* Command 0: small lit area (size 3.0, full alpha). */
void FIELD_FLASH_CmdInit(FieldFlash *flash)
{
    flash->state = FLASH_STATE_READY;
    FIELD_FLASH_SetTweenSize(&flash->tween, (3 << 12));
    FIELD_FLASH_SetTweenAlpha(&flash->tween, 31);
}

/* Command 1: grow the lit area to size 10.6 in 15 frames (flash was just used). */
void FIELD_FLASH_CmdExpand(FieldFlash *flash)
{
    flash->state = FLASH_STATE_EXPANDING;
    FIELD_FLASH_StartTween(&flash->tween, 0x3000, 0xaa00, 0x1f, 0x1f, 0xf);
    GFL_USE_PlaySeDefaultVolume(0x767);
}

/* Command 2: show the expanded lit area at once (flash was already active). */
void FIELD_FLASH_ShowExpanded(FieldFlash *flash)
{
    flash->state = FLASH_STATE_EXPANDED;
    FIELD_FLASH_SetTweenSize(&flash->tween, 0xaa00);
    FIELD_FLASH_SetTweenAlpha(&flash->tween, 0x1f);
}

/* Command 3: hide the mask. */
void FIELD_FLASH_HideMask(FieldFlash *flash)
{
    flash->state = FLASH_STATE_OFF;
    FIELD_FLASH_SetTweenSize(&flash->tween, 0);
}
