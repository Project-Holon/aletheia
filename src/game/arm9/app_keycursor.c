/*
 * file:     app_keycursor.c
 * unit:     yes
 * function: PRINTSYS_CTRL_Init, PRINTSYS_CTRL_Update, PRINTSYS_CTRL_IsInputTrg, PRINTSYS_CTRL_IsInputCont, PRINTSYS_CTRL_IsInputIdle, APP_KEYCURSOR_CreateDefault, APP_KEYCURSOR_Create, APP_KEYCURSOR_Delete, APP_KEYCURSOR_DrawMark, APP_KEYCURSOR_Animate, APP_KEYCURSOR_Update, FIELD_SKILL_USE_FLAGS_SetSkill, FIELD_SKILL_USE_FLAGS_IsSkillUsable
 * address:  0x02028470
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from app_keycursor_head.c, app_keycursor.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   _KeyCursorDefaultPixels  0x0209FD10  data
 *   APP_KEYCURSOR_Create  0x020285A4  thumb
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   KEY_GetCont  0x0203630C  arm
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   BMP_CreateFromBuffer      0x020436FC  arm
 *   app_keycursor_File 0x020A74F0  data
 *   BMP_Delete  0x020437AC  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "beacon_status_shared_types.h"

#include "../types.h"

struct TextPrinter;     /* message print stream (printsys.c) */

struct KeyCursor;       /* key cursor mark (app_keycursor.c) */

/* ------------------------------------------------------------------ */
/* print stream key/touch control                                      */
/* ------------------------------------------------------------------ */

/* 8 bytes, cleared by PRINTSYS_CTRL_Init. */
typedef struct PrintStreamCtrl {
    u8 isKeyReleased;           /* +0x00 keys were released once since the stream started */
    u8 pad_01[3];
    u32 inputType;              /* +0x04 bit 1 keys, bit 2 touch, bit 10 no fast-forward */
} PrintStreamCtrl;

#include "mi_memory.h"

#include "key.h"

#include "gfl_use.h"

#include "printsys.h"



#include "touchpanel.h"



struct KeyCursor *APP_KEYCURSOR_Create(u32 id, u32 live, u32 flip, u16 heap, void *pixels);

void PRINTSYS_CTRL_Init(PrintStreamCtrl *ctrl, u32 inputType);

int PRINTSYS_CTRL_Update(PrintStreamCtrl *ctrl, struct TextPrinter *stream);

u32 PRINTSYS_CTRL_IsInputTrg(u32 inputType);

u32 PRINTSYS_CTRL_IsInputCont(u32 inputType);

u32 PRINTSYS_CTRL_IsInputIdle(u32 inputType);

struct KeyCursor *APP_KEYCURSOR_CreateDefault(u32 id, u32 isLive, u32 isFlip, u16 heapId);

extern const u8 _KeyCursorDefaultPixels[];

/* ================================================================== */
/* print stream key/touch control                                      */
/* ================================================================== */
void PRINTSYS_CTRL_Init(PrintStreamCtrl *ctrl, u32 inputType)
{
    MI_CpuFill8(ctrl, 0, sizeof(PrintStreamCtrl));
    ctrl->inputType = inputType;
}

/*
 * Per-frame control of a print stream. Paused (1): a key or touch
 * releases it with SE 0x547. Running (0): unless bit 10 is set, once the
 * keys were released, holding a key prints the rest at once. Returns 1
 * when the stream is finished (2) or absent.
 */
int PRINTSYS_CTRL_Update(PrintStreamCtrl *ctrl, struct TextPrinter *stream)
{
    u32 mask;

    if (stream != 0) {
        switch (PRINTSYS_PrintStreamGetState(stream)) {
        case 2:
            return 1;
        case 1:
            if (PRINTSYS_CTRL_IsInputTrg(ctrl->inputType) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(stream);
            }
            break;
        case 0:
            mask = 1 << 10;
            if ((mask & ctrl->inputType) == 0) {
                if (ctrl->isKeyReleased == 0) {
                    if (PRINTSYS_CTRL_IsInputIdle(ctrl->inputType) != 0) {
                        ctrl->isKeyReleased = 1;
                    }
                } else {
                    if (PRINTSYS_CTRL_IsInputCont(ctrl->inputType) != 0) {
                        PRINTSYS_PrintStreamShortWait(stream, 0);
                    }
                }
            }
            break;
        }
        return 0;
    }
    return 1;
}

/* A or B pressed, or the panel touched, as inputType allows. */
u32 PRINTSYS_CTRL_IsInputTrg(u32 inputType)
{
    u32 result = 0;
    if (inputType == 0) {
        result = 1;
    }
    if (inputType & 2) {
        if (KEY_GetTrg() & 3) {
            result = 1;
        }
    }
    if (inputType & 4) {
        if (TOUCHPANEL_GetTrg() != 0) {
            result = 1;
        }
    }
    return result;
}

/* A or B held, or the panel held, as inputType allows. */
u32 PRINTSYS_CTRL_IsInputCont(u32 inputType)
{
    u32 result = 0;
    if (inputType == 0) {
        result = 1;
    }
    if (inputType & 2) {
        if (KEY_GetCont() & 3) {
            result = 1;
        }
    }
    if (inputType & 4) {
        if (TOUCHPANEL_GetCont() != 0) {
            result = 1;
        }
    }
    return result;
}

/* No key held, or the panel not held, as inputType allows. */
u32 PRINTSYS_CTRL_IsInputIdle(u32 inputType)
{
    u32 result = 0;
    if (inputType == 0) {
        result = 1;
    }
    if (inputType & 2) {
        if (KEY_GetCont() == 0) {
            result = 1;
        }
    }
    if (inputType & 4) {
        if (TOUCHPANEL_GetCont() == 0) {
            result = 1;
        }
    }
    return result;
}

/* Key cursor with the default mark pixels. */
struct KeyCursor *APP_KEYCURSOR_CreateDefault(u32 id, u32 isLive, u32 isFlip, u16 heapId)
{
    return APP_KEYCURSOR_Create(id, isLive, isFlip, heapId, (void *)_KeyCursorDefaultPixels);
}

#include "bmp_shared_types.h"

/* Cursor work: one 2x2-tile bitmap and the blink state of one text cursor. */
struct KeyCursor {
    struct Bmp *item;  /* 0x00 */
    u8   phase;        /* 0x04 */
    u8   tick;         /* 0x05 */
    u8   held;         /* 0x06 */
    u8   live : 1;     /* 0x07 bit 0 */
    u8   flip : 1;     /* 0x07 bit 1 */
    u16  id;           /* 0x08 */
};

/* Field skill availability flags (0x18 bytes, filled by FIELD_SKILL_CHECK_FillUseFlags): bit i of
 * usableMask is set when field skill i can be used.  Only the mask is touched here. */
#include "app_keycursor_types.h"

struct Descriptor;

struct TextPrinter;

#include "gfl_heap_wrap.h"

typedef short s16_p07;
#include "bmp.h"





struct BmpWin;

#include "bmp_win.h"



void APP_KEYCURSOR_Delete(struct KeyCursor *cursor);

void APP_KEYCURSOR_DrawMark(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color);

void APP_KEYCURSOR_Animate(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color);

void APP_KEYCURSOR_Update(struct KeyCursor *cursor, struct TextPrinter *printStream, void *win);

void FIELD_SKILL_USE_FLAGS_SetSkill(struct FieldSkillUseFlags *flags, int skillIndex, int usable);

u32 FIELD_SKILL_USE_FLAGS_IsSkillUsable(const struct FieldSkillUseFlags *flags, u32 skillIndex);

extern const char app_keycursor_File[];

/*
 * TU: app_keycursor.c (__FILE__ 0x020A74F0, line 149).
 */
struct KeyCursor *APP_KEYCURSOR_Create(u32 id, u32 live, u32 flip, u16 heap,
                                void *pixels)
{
    struct KeyCursor *cursor;

    cursor = GFL_HEAP_Alloc(heap, sizeof(struct KeyCursor), 1, app_keycursor_File,
                      149);

    cursor->id = id;
    cursor->live = live;
    cursor->flip = flip;
    cursor->item = BMP_CreateFromBuffer(pixels, 2, 2, 0x20, heap);

    return cursor;
}

void APP_KEYCURSOR_Delete(struct KeyCursor *cursor)
{
    BMP_Delete(cursor->item);
    GFL_HEAP_Free(cursor);
}

void APP_KEYCURSOR_DrawMark(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color)
{
    u16 w = BMP_GetWidth(bmp) - 11;
    u16 h = BMP_GetHeight(bmp) - 9;

    BMP_FillRect((struct Bmp *)bmp, (s16)w, (s16)(h + cursor->phase), 0xa, 7, (u8)color);
}

void APP_KEYCURSOR_Animate(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color)
{
    u16 w;
    u16 h;

    APP_KEYCURSOR_DrawMark(cursor, bmp, color);

    cursor->tick = cursor->tick + 1;
    if (cursor->tick >= 8) {
        cursor->tick = 0;
        cursor->phase = cursor->phase + 1;
        cursor->phase = (s32)cursor->phase % 3;
    }

    w = BMP_GetWidth(bmp) - 11;
    h = BMP_GetHeight(bmp) - 9;

    BMP_Blit((struct Bmp *)cursor->item, (struct Bmp *)bmp, 0, 2, w, h + cursor->phase, 0xa, 7, 0);
}

void APP_KEYCURSOR_Update(struct KeyCursor *cursor, struct TextPrinter *printStream, void *win)
{
    u32 mode = PRINTSYS_PrintStreamGetState(printStream);

    switch (mode) {
    case 2:
        cursor->held = 0;
        return;
    case 1:
    {
        u32 input = 0;

        if (cursor->live) {
            input = KEY_GetTrg() & 3;
        }
        if (input == 0) {
            if (cursor->flip) {
                input = TOUCHPANEL_GetTrg();
            }
        }
        if (input != 0) {
            cursor->held = 1;
            APP_KEYCURSOR_DrawMark(cursor, BMP_WIN_GetBmp(win), cursor->id);
            BMP_WIN_TransferChars(win);
            return;
        }
        if (cursor->held != 0) {
            return;
        }
        APP_KEYCURSOR_Animate(cursor, BMP_WIN_GetBmp(win), cursor->id);
        BMP_WIN_TransferChars(win);
        return;
    }
    case 0:
        cursor->held = 0;
        return;
    }
}

/*
 * Accessors of the field skill availability mask (word at +0x14): set the bit of
 * a skill from a 0/1 value, and test it.  Neither calls anything.  They sit in this
 * file but belong to the field skill check code, not to the key cursor.
 */
void FIELD_SKILL_USE_FLAGS_SetSkill(struct FieldSkillUseFlags *flags, int skillIndex, int usable)
{
    flags->usableMask = flags->usableMask | (usable << skillIndex);
}

u32 FIELD_SKILL_USE_FLAGS_IsSkillUsable(const struct FieldSkillUseFlags *flags, u32 skillIndex)
{
    return (flags->usableMask >> skillIndex) & 1;
}
