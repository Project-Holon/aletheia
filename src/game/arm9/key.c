/*
 * file:     key.c
 * unit:     yes
 * function: KEY_Create, KEY_MainSys, KEY_Main, KEY_ApplyControlMode, KEY_SetRepeatSpeedSys, KEY_SetRepeatSpeed, KEY_SetControlModeTableSys, KEY_SetControlModeTable, KEY_GetTrgSys, KEY_GetTrg, KEY_GetContSys, KEY_GetCont, KEY_GetRepeatSys, KEY_GetRepeat, KEY_GetRepeatSpeedSys, KEY_GetRepeatSpeed, KEY_ClearFrameRateWork, KEY_SetTrg, KEY_SetCont, KEY_SetRepeat
 * address:  0x02035EE8
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
 *   UI_GetPointerValue                     0x0203521C  arm
 *   GFL_HEAP_Alloc                    0x02030734  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   _pTouchPanelWork                 0x021469C4  data
 *   key_File                         0x020A799C  data
 */
#include "touchpanel_shared_types.h"
#include "../sdk_ioreg.h"

#include "../types.h"

#define REG_KEYINPUT        REG_KEYINPUT_ADDR

#define PAD_ALL_MASK        0x2FFF

#define KEY_CONV_END    0

#define KEY_CONV_COPY   1

#define KEY_CONV_SWAP   2

#define KEY_CONV_MASK   3

#include "ui.h"


#include "gfl_heap_wrap.h"

#include "mi_memory.h"

/* key.c */
KeyWork *KEY_Create(u32 heapId);

void KEY_MainSys(UiCtx *ui);

void KEY_Main(void);

void KEY_ApplyControlMode(KeyWork *key);

void KEY_SetRepeatSpeedSys(UiCtx *ui, int speed, int wait);

void KEY_SetRepeatSpeed(int speed, int wait);

void KEY_SetControlModeTableSys(UiCtx *ui, const KeyConvEntry *table);

void KEY_SetControlModeTable(const KeyConvEntry *table);

u32 KEY_GetTrgSys(UiCtx *ui);

u32 KEY_GetTrg(void);

u32 KEY_GetContSys(UiCtx *ui);

u32 KEY_GetCont(void);

u32 KEY_GetRepeatSys(UiCtx *ui);

u32 KEY_GetRepeat(void);

void KEY_GetRepeatSpeedSys(UiCtx *ui, u32 *speed, u32 *wait);

void KEY_GetRepeatSpeed(u32 *speed, u32 *wait);

void KEY_ClearFrameRateWork(UiCtx *ui);

void KEY_SetTrg(UiCtx *ui, int trg, int trg30);

void KEY_SetCont(UiCtx *ui, int cont, int cont30);

void KEY_SetRepeat(UiCtx *ui, int repeat, int repeat30);

extern const char key_File[];

/* ==================================================================
 * key.c
 * ================================================================== */

/* Allocates and clears the work; key repeat starts after 15 frames, then
 * every 8 frames. */
KeyWork *KEY_Create(u32 heapId)
{
    KeyWork *key = GFL_HEAP_Alloc(heapId, sizeof(KeyWork), 0, key_File, 0x44);

    MI_CpuFill8(key, 0, sizeof(KeyWork));
    key->repeatSpeed = 8;
    key->repeatWait = 0xf;
    return key;
}

static inline s32 KEY_PadDetectFold(void)
{
    return (s32)((*(vu16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15);
}

static inline u16 KEY_PadRead(void)
{
    return (u16)(((*(vu16 *)REG_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF) ^ PAD_ALL_MASK) & PAD_ALL_MASK);
}

/*
 * The per-frame pad update: with the lid closed the converted and 30 fps
 * words are cleared; otherwise the pad is read (opposite directions
 * pressed together cancel), trigger and repeat are derived, the control
 * mode table is applied, and every second frame the 30 fps values take
 * what was collected over the pair.
 */
void KEY_MainSys(UiCtx *ui)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);
    u16 pad;

    if (KEY_PadDetectFold()) {
        key->trg = 0;
        key->cont = 0;
        key->repeat = 0;
        key->trg30 = 0;
        key->cont30 = 0;
        key->repeat30 = 0;
        return;
    }
    pad = KEY_PadRead();
    pad = pad & ~((pad & 0x40) << 1) & ~((pad & 0x20) >> 1);
    key->rawTrg = pad & (pad ^ key->rawCont);
    key->rawRepeat = pad & (pad ^ key->rawCont);
    if (pad != 0 && key->rawCont == pad) {
        if (--key->repeatCounter == 0) {
            key->rawRepeat = pad;
            key->repeatCounter = key->repeatSpeed;
        }
    } else {
        key->repeatCounter = key->repeatWait;
    }
    key->rawCont = pad;
    key->trg = key->rawTrg;
    key->cont = pad;
    key->repeat = key->rawRepeat;
    KEY_ApplyControlMode(key);
    key->pendTrg |= key->trg;
    key->pendCont |= key->cont;
    key->pendRepeat |= key->repeat;
    if (ui->frameCounter % 2 != 0) {
        return;
    }
    key->trg30 = key->pendTrg;
    key->cont30 = key->pendCont;
    key->repeat30 = key->pendRepeat;
    key->pendTrg = 0;
    key->pendCont = 0;
    key->pendRepeat = 0;
}

void KEY_Main(void)
{
    KEY_MainSys(UI_GetContext());
}

/* KEY_CONV_SWAP: the two keys trade places. */
static inline void KEY_ConvSwap(u32 *keys, const KeyConvEntry *conv)
{
    u32 swapped = 0;

    if (*keys & conv->srcKey)
        swapped |= conv->dstKey;
    if (*keys & conv->dstKey)
        swapped |= conv->srcKey;
    *keys &= (conv->srcKey | conv->dstKey) ^ 0xffff;
    *keys |= swapped;
}

/* KEY_CONV_COPY: the source key also presses the destination key. */
static inline void KEY_ConvCopy(u32 *keys, const KeyConvEntry *conv)
{
    if (*keys & conv->srcKey)
        *keys |= conv->dstKey;
}

/* KEY_CONV_MASK: the source key is dropped. */
static inline void KEY_ConvMask(u32 *keys, const KeyConvEntry *conv)
{
    *keys &= conv->srcKey ^ 0xffff;
}

/* Applies the entries of the current control mode to the converted words. */
void KEY_ApplyControlMode(KeyWork *key)
{
    const KeyConvEntry *conv;

    if (key->controlModeTable == 0)
        return;
    conv = key->controlModeTable + key->controlMode;
    for (;;) {
        switch (conv->kind) {
        case KEY_CONV_END:
            return;
        case KEY_CONV_COPY:
            KEY_ConvCopy(&key->trg, conv);
            KEY_ConvCopy(&key->cont, conv);
            KEY_ConvCopy(&key->repeat, conv);
            break;
        case KEY_CONV_SWAP:
            KEY_ConvSwap(&key->trg, conv);
            KEY_ConvSwap(&key->cont, conv);
            KEY_ConvSwap(&key->repeat, conv);
            break;
        case KEY_CONV_MASK:
            KEY_ConvMask(&key->trg, conv);
            KEY_ConvMask(&key->cont, conv);
            KEY_ConvMask(&key->repeat, conv);
            break;
        }
        conv++;
    }
}

void KEY_SetRepeatSpeedSys(UiCtx *ui, int speed, int wait)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    key->repeatSpeed = speed;
    key->repeatWait = wait;
}

void KEY_SetRepeatSpeed(int speed, int wait)
{
    KEY_SetRepeatSpeedSys(UI_GetContext(), speed, wait);
}

void KEY_SetControlModeTableSys(UiCtx *ui, const KeyConvEntry *table)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    key->controlModeTable = table;
}

void KEY_SetControlModeTable(const KeyConvEntry *table)
{
    KEY_SetControlModeTableSys(UI_GetContext(), table);
}

u32 KEY_GetTrgSys(UiCtx *ui)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->trg30;
    }
    return key->trg;
}

u32 KEY_GetTrg(void)
{
    return KEY_GetTrgSys(UI_GetContext());
}

u32 KEY_GetContSys(UiCtx *ui)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->cont30;
    }
    return key->cont;
}

u32 KEY_GetCont(void)
{
    return KEY_GetContSys(UI_GetContext());
}

u32 KEY_GetRepeatSys(UiCtx *ui)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->repeat30;
    }
    return key->repeat;
}

u32 KEY_GetRepeat(void)
{
    return KEY_GetRepeatSys(UI_GetContext());
}

void KEY_GetRepeatSpeedSys(UiCtx *ui, u32 *speed, u32 *wait)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    *speed = key->repeatSpeed;
    *wait = key->repeatWait;
}

void KEY_GetRepeatSpeed(u32 *speed, u32 *wait)
{
    KEY_GetRepeatSpeedSys(UI_GetContext(), speed, wait);
}

void KEY_ClearFrameRateWork(UiCtx *ui)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    key->cont30 = 0;
    key->trg30 = 0;
    key->repeat30 = 0;
    key->pendCont = 0;
    key->pendTrg = 0;
    key->pendRepeat = 0;
}

void KEY_SetTrg(UiCtx *ui, int trg, int trg30)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    key->trg30 = trg30;
    key->trg = trg;
}

void KEY_SetCont(UiCtx *ui, int cont, int cont30)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    key->cont30 = cont30;
    key->cont = cont;
}

void KEY_SetRepeat(UiCtx *ui, int repeat, int repeat30)
{
    KeyWork *key = (KeyWork *)UI_GetPointerValue((void **)ui);

    key->repeat30 = repeat30;
    key->repeat = repeat;
}
