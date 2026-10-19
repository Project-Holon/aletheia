/*
 * file:     app_keycursor.c
 * unit:     yes
 * function: APP_KEYCURSOR_Create, APP_KEYCURSOR_Delete, APP_KEYCURSOR_DrawMark, APP_KEYCURSOR_Animate, APP_KEYCURSOR_Update, FIELD_SKILL_USE_FLAGS_SetSkill, FIELD_SKILL_USE_FLAGS_IsSkillUsable
 * address:  0x020285A4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from app_keycursor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   BMP_CreateFromBuffer      0x020436FC  arm
 *   app_keycursor_File 0x020A74F0  data
 *   BMP_Delete  0x020437AC  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   BMP_Blit  0x020439A0  arm
 *   PRINTSYS_PrintStreamGetState   0x0201CE30  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "app_keycursor_shared_types.h"

typedef signed short   s16;

typedef signed int     s32;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   depth;
    u16   kind;
};

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
struct FieldSkillUseFlags {
    u8  pad_00[0x14];
    u32 usableMask;
};

struct Descriptor;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);

extern void BMP_Delete(struct Bmp *bmp);

extern u16  BMP_GetWidth(const struct Bmp *bmp);

extern u16 BMP_GetHeight(const struct Bmp *bmp);

extern void BMP_FillRect(const struct Bmp *b, u32 x, u32 y, u32 w, u32 h, u32 value);

extern void BMP_Blit(struct Bmp *dst, const struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

extern u32   PRINTSYS_PrintStreamGetState(void *p);

extern u32   KEY_GetTrg(void);

extern int TOUCHPANEL_GetTrg(void);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u32 GFL_HEAP_Free(void *p);

struct KeyCursor *APP_KEYCURSOR_Create(u16 id, u32 live, u32 flip, u16 heap, void *pixels);

void APP_KEYCURSOR_Delete(struct KeyCursor *cursor);

void APP_KEYCURSOR_DrawMark(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color);

void APP_KEYCURSOR_Animate(struct KeyCursor *cursor, const struct Bmp *bmp, u32 color);

void APP_KEYCURSOR_Update(struct KeyCursor *cursor, void *printStream, void *win);

void FIELD_SKILL_USE_FLAGS_SetSkill(struct FieldSkillUseFlags *flags, int skillIndex, int usable);

u32 FIELD_SKILL_USE_FLAGS_IsSkillUsable(const struct FieldSkillUseFlags *flags, u32 skillIndex);

extern const char app_keycursor_File[];

/*
 * TU: app_keycursor.c (__FILE__ 0x020A74F0, line 149).
 */
struct KeyCursor *APP_KEYCURSOR_Create(u16 id, u32 live, u32 flip, u16 heap,
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

    BMP_FillRect(bmp, (s16)w, (s16)(h + cursor->phase), 0xa, 7, (u8)color);
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

    BMP_Blit(cursor->item, bmp, 0, 2, w, h + cursor->phase, 0xa, 7, 0);
}

void APP_KEYCURSOR_Update(struct KeyCursor *cursor, void *printStream, void *win)
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
