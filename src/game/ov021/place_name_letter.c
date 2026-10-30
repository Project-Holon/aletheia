/*
 * file:     place_name_letter.c
 * unit:     yes
 * function: PLACE_NAME_LETTER_Create, PLACE_NAME_LETTER_Delete, PLACE_NAME_LETTER_Setup, PLACE_NAME_LETTER_Update, PLACE_NAME_LETTER_Start, PLACE_NAME_LETTER_GetBmp, PLACE_NAME_LETTER_SetVisible, PLACE_NAME_LETTER_GetWidth, PLACE_NAME_LETTER_GetHeight, PLACE_NAME_LETTER_GetX, PLACE_NAME_LETTER_GetY, PLACE_NAME_LETTER_IsActive, PLACE_NAME_LETTER_AllocWork, PLACE_NAME_LETTER_FreeWork, PLACE_NAME_LETTER_InitWork, PLACE_NAME_LETTER_CreateBmp, PLACE_NAME_LETTER_DeleteBmp, PLACE_NAME_LETTER_CreateBmpOam, PLACE_NAME_LETTER_DeleteBmpOam, PLACE_NAME_LETTER_GetHeapId, PLACE_NAME_LETTER_SetHeapId, PLACE_NAME_LETTER_GetFont, PLACE_NAME_LETTER_SetFont, PLACE_NAME_LETTER_GetChar, PLACE_NAME_LETTER_SetChar, PLACE_NAME_LETTER_GetActive, PLACE_NAME_LETTER_GetIntX, PLACE_NAME_LETTER_GetIntY, PLACE_NAME_LETTER_GetWidthRaw, PLACE_NAME_LETTER_GetHeightRaw, PLACE_NAME_LETTER_GetMotion, PLACE_NAME_LETTER_GetBmpRaw, PLACE_NAME_LETTER_MeasureGlyph, PLACE_NAME_LETTER_IsFinished, PLACE_NAME_LETTER_IsXDone, PLACE_NAME_LETTER_IsYDone, PLACE_NAME_LETTER_UpdateActive, PLACE_NAME_LETTER_StepX, PLACE_NAME_LETTER_StepY, PLACE_NAME_LETTER_Activate, PLACE_NAME_LETTER_Deactivate, PLACE_NAME_LETTER_ComputeAcceleration, PLACE_NAME_LETTER_SetMotion, PLACE_NAME_LETTER_ClearBmp, PLACE_NAME_LETTER_PrintChar, PLACE_NAME_LETTER_UpdateOamPos, PLACE_NAME_LETTER_SetVisibleRaw, PLACE_NAME_LETTER_MeasureChar
 * address:  0x021BD148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BD148 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   gPlaceNameLetterFileName     0x021DE368  data  a4
 *   BMP_Delete  0x020437AC  arm
 *   _ffix  0x0209C494  arm
 *   BMP_Clear  0x02043B5C  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   PRINTSYS_CountLines  0x0201D42C  thumb
 *   BMP_OAM_Create  0x020255A0  thumb  arm9
 *   BMP_OAM_Delete  0x0202570C  thumb  arm9
 *   BMP_OAM_SetPos  0x0202590C  thumb  arm9
 *   BMP_Create  0x02043678  arm  arm9
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _fmul                        0x0209C77C  arm
 *   _fneq                        0x0209BCD0  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "../types.h"
/* Original DS prototype: this file passes the coordinates as ints; the header and the definition take s16. */
#ifdef __MWERKS__
#define BMP_OAM_SetPos BMP_OAM_SetPos_header
#endif
#include "../arm9/bmp_oam.h"
#ifdef __MWERKS__
#undef BMP_OAM_SetPos
extern void BMP_OAM_SetPos(struct BmpOam *bmpOam, int x, int y);
#endif

#include "field_place_name_types.h"

typedef struct GfFont GfFont;
typedef struct Bmp Bmp;
typedef struct BmpOamSys BmpOamSys;
typedef struct BmpOam BmpOam;

/* Bitmap size of one letter in 8x8 tiles. */
#define PLACE_NAME_LETTER_TILES_WIDE 2
#define PLACE_NAME_LETTER_TILES_HIGH 2
#define PLACE_NAME_LETTER_BMP_DEPTH 0x20
#define PLACE_NAME_LETTER_PRINT_COLOR 0x440

#include "../arm9/gfl_heap_wrap.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/strbuf.h"
#include "../arm9/mi_memory.h"
#include "../arm9/printsys.h"
PlaceNameLetter *PLACE_NAME_LETTER_Create(u32 heapId, BmpOamSys *bmpOamSys, u16 space, int paletteId);
void PLACE_NAME_LETTER_Delete(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Setup(PlaceNameLetter *letter, const PlaceNameLetterParam *param);
void PLACE_NAME_LETTER_Update(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Start(PlaceNameLetter *letter);
Bmp *PLACE_NAME_LETTER_GetBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetVisible(PlaceNameLetter *letter, unsigned int visible);
int PLACE_NAME_LETTER_GetWidth(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_GetHeight(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetX(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetY(PlaceNameLetter *letter);
unsigned int PLACE_NAME_LETTER_IsActive(PlaceNameLetter *letter);
PlaceNameLetter *PLACE_NAME_LETTER_AllocWork(u32 heapId);
u32 PLACE_NAME_LETTER_FreeWork(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_InitWork(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_CreateBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_DeleteBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_CreateBmpOam(PlaceNameLetter *letter, BmpOamSys *bmpOamSys, u16 space, int paletteId);
void PLACE_NAME_LETTER_DeleteBmpOam(PlaceNameLetter *letter);
u16 PLACE_NAME_LETTER_GetHeapId(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetHeapId(PlaceNameLetter *letter, int heapId);
GfFont *PLACE_NAME_LETTER_GetFont(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetFont(PlaceNameLetter *letter, GfFont *font);
u16 PLACE_NAME_LETTER_GetChar(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetChar(PlaceNameLetter *letter, u16 ch);
u32 PLACE_NAME_LETTER_GetActive(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetIntX(PlaceNameLetter *letter);
u32 PLACE_NAME_LETTER_GetIntY(PlaceNameLetter *letter);
u8 PLACE_NAME_LETTER_GetWidthRaw(PlaceNameLetter *letter);
u8 PLACE_NAME_LETTER_GetHeightRaw(PlaceNameLetter *letter);
PlaceNameLetterMotion *PLACE_NAME_LETTER_GetMotion(PlaceNameLetter *letter);
Bmp *PLACE_NAME_LETTER_GetBmpRaw(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_MeasureGlyph(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_IsFinished(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_IsXDone(PlaceNameLetter *letter);
int PLACE_NAME_LETTER_IsYDone(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_UpdateActive(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_StepX(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_StepY(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Activate(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_Deactivate(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_ComputeAcceleration(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetMotion(PlaceNameLetter *letter, const PlaceNameLetterParam *param);
void PLACE_NAME_LETTER_ClearBmp(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_PrintChar(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_UpdateOamPos(PlaceNameLetter *letter);
void PLACE_NAME_LETTER_SetVisibleRaw(PlaceNameLetter *letter, unsigned int visible);
void PLACE_NAME_LETTER_MeasureChar(GfFont *font, u16 ch, u32 heapId, u8 *width, u8 *height);
extern u8 gPlaceNameLetterFileName[20];

/* Creates a letter: work, bitmap, OAM actor. It starts hidden and inactive. */
PlaceNameLetter *PLACE_NAME_LETTER_Create(u32 heapId, BmpOamSys *bmpOamSys, u16 space, int paletteId)
{
    PlaceNameLetter *letter = PLACE_NAME_LETTER_AllocWork(heapId);
    PLACE_NAME_LETTER_InitWork(letter);
    PLACE_NAME_LETTER_SetHeapId(letter, heapId);
    PLACE_NAME_LETTER_CreateBmp(letter);
    PLACE_NAME_LETTER_CreateBmpOam(letter, bmpOamSys, space, paletteId);
    PLACE_NAME_LETTER_SetVisibleRaw(letter, 0);
    return letter;
}

void PLACE_NAME_LETTER_Delete(PlaceNameLetter *letter)
{
    PLACE_NAME_LETTER_DeleteBmpOam(letter);
    PLACE_NAME_LETTER_DeleteBmp(letter);
    PLACE_NAME_LETTER_FreeWork(letter);
}

/* Gives the letter its character and motion, draws the glyph and sets the OAM position. */
void PLACE_NAME_LETTER_Setup(PlaceNameLetter *letter, const PlaceNameLetterParam *param)
{
    PLACE_NAME_LETTER_SetFont(letter, param->font);
    PLACE_NAME_LETTER_SetChar(letter, param->ch);
    PLACE_NAME_LETTER_MeasureGlyph(letter);
    PLACE_NAME_LETTER_ClearBmp(letter);
    PLACE_NAME_LETTER_PrintChar(letter);
    PLACE_NAME_LETTER_SetMotion(letter, param);
}

void PLACE_NAME_LETTER_Update(PlaceNameLetter *letter)
{
    PLACE_NAME_LETTER_UpdateActive(letter);
}

void PLACE_NAME_LETTER_Start(PlaceNameLetter *letter)
{
    PLACE_NAME_LETTER_Activate(letter);
}

Bmp *PLACE_NAME_LETTER_GetBmp(PlaceNameLetter *letter)
{
    return PLACE_NAME_LETTER_GetBmpRaw(letter);
}

void PLACE_NAME_LETTER_SetVisible(PlaceNameLetter *letter, unsigned int visible)
{
    PLACE_NAME_LETTER_SetVisibleRaw(letter, visible);
}

int PLACE_NAME_LETTER_GetWidth(PlaceNameLetter *letter)
{
    return PLACE_NAME_LETTER_GetWidthRaw(letter);
}

int PLACE_NAME_LETTER_GetHeight(PlaceNameLetter *letter)
{
    return PLACE_NAME_LETTER_GetHeightRaw(letter);
}

u32 PLACE_NAME_LETTER_GetX(PlaceNameLetter *letter)
{
    return PLACE_NAME_LETTER_GetIntX(letter);
}

u32 PLACE_NAME_LETTER_GetY(PlaceNameLetter *letter)
{
    return PLACE_NAME_LETTER_GetIntY(letter);
}

/* 1 while the letter moves. */
unsigned int PLACE_NAME_LETTER_IsActive(PlaceNameLetter *letter)
{
    return PLACE_NAME_LETTER_GetActive(letter);
}

PlaceNameLetter *PLACE_NAME_LETTER_AllocWork(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 0x4C, 0, (const char *)&gPlaceNameLetterFileName, 0x170);
}

u32 PLACE_NAME_LETTER_FreeWork(PlaceNameLetter *letter)
{
    return GFL_HEAP_Free(letter);
}

void PLACE_NAME_LETTER_InitWork(PlaceNameLetter *letter)
{
    MI_CpuFill8(letter, 0, sizeof(*letter));
    letter->active = 0;
    letter->ch = STRBUF_GetEosChar();
}

void PLACE_NAME_LETTER_CreateBmp(PlaceNameLetter *letter)
{
    letter->bmp = BMP_Create(PLACE_NAME_LETTER_TILES_WIDE, PLACE_NAME_LETTER_TILES_HIGH, PLACE_NAME_LETTER_BMP_DEPTH, letter->heapId);
}

void PLACE_NAME_LETTER_DeleteBmp(PlaceNameLetter *letter)
{
    Bmp *bmp = letter->bmp;
    if (bmp != 0) {
        BMP_Delete(bmp);
        letter->bmp = 0;
    }
}

void PLACE_NAME_LETTER_CreateBmpOam(PlaceNameLetter *letter, BmpOamSys *bmpOamSys, u16 space, int paletteId)
{
    struct BmpOamParam param;
    param.bmp = letter->bmp;
    param.x = 0;
    param.y = 0;
    param.animResId = paletteId;
    param.palette = 0;
    param.drawPriority = 0;
    param.bgPriority = 0;
    param.space = space;
    param.engine = 0;
    letter->bmpOam = BMP_OAM_Create(bmpOamSys, &param);
}

void PLACE_NAME_LETTER_DeleteBmpOam(PlaceNameLetter *letter)
{
    if (letter->bmpOam != 0) {
        BMP_OAM_Delete(letter->bmpOam);
        letter->bmpOam = 0;
    }
}

u16 PLACE_NAME_LETTER_GetHeapId(PlaceNameLetter *letter)
{
    return letter->heapId;
}

void PLACE_NAME_LETTER_SetHeapId(PlaceNameLetter *letter, int heapId)
{
    letter->heapId = heapId;
}

GfFont *PLACE_NAME_LETTER_GetFont(PlaceNameLetter *letter)
{
    return letter->font;
}

void PLACE_NAME_LETTER_SetFont(PlaceNameLetter *letter, GfFont *font)
{
    letter->font = font;
}

u16 PLACE_NAME_LETTER_GetChar(PlaceNameLetter *letter)
{
    return letter->ch;
}

void PLACE_NAME_LETTER_SetChar(PlaceNameLetter *letter, u16 ch)
{
    letter->ch = ch;
}

u32 PLACE_NAME_LETTER_GetActive(PlaceNameLetter *letter)
{
    return letter->active;
}

/* Current x position as an integer (letter + 0x10 is the motion x). */
u32 PLACE_NAME_LETTER_GetIntX(PlaceNameLetter *letter)
{
    return (int)letter->motion.x;
}

/* Current y position as an integer. */
u32 PLACE_NAME_LETTER_GetIntY(PlaceNameLetter *letter)
{
    return (int)letter->motion.y;
}

u8 PLACE_NAME_LETTER_GetWidthRaw(PlaceNameLetter *letter)
{
    return letter->width;
}

u8 PLACE_NAME_LETTER_GetHeightRaw(PlaceNameLetter *letter)
{
    return letter->height;
}

PlaceNameLetterMotion *PLACE_NAME_LETTER_GetMotion(PlaceNameLetter *letter)
{
    return &letter->motion;
}

Bmp *PLACE_NAME_LETTER_GetBmpRaw(PlaceNameLetter *letter)
{
    return letter->bmp;
}

/* Measures the glyph of the letter's character. */
void PLACE_NAME_LETTER_MeasureGlyph(PlaceNameLetter *letter)
{
    GfFont *font;
    u16 ch;
    font = PLACE_NAME_LETTER_GetFont(letter);
    ch = PLACE_NAME_LETTER_GetChar(letter);
    PLACE_NAME_LETTER_MeasureChar(font, ch, PLACE_NAME_LETTER_GetHeapId(letter), &letter->width, &letter->height);
}

/* 1 when the letter is inactive or both axes finished. */
int PLACE_NAME_LETTER_IsFinished(PlaceNameLetter *letter)
{
    if (PLACE_NAME_LETTER_GetActive(letter) == 0) {
        return 1;
    }
    if (PLACE_NAME_LETTER_IsXDone(letter) != 0) {
        if (PLACE_NAME_LETTER_IsYDone(letter) != 0) {
            return 1;
        }
    }
    return 0;
}

/* 1 when the x axis needs no more steps. */
int PLACE_NAME_LETTER_IsXDone(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion = PLACE_NAME_LETTER_GetMotion(letter);
    if (PLACE_NAME_LETTER_GetActive(letter) == 0) {
        return 1;
    }
    if (motion->framesX <= 0) {
        return 1;
    }
    return 0;
}

/* 1 when the y axis needs no more steps. */
int PLACE_NAME_LETTER_IsYDone(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion = PLACE_NAME_LETTER_GetMotion(letter);
    if (PLACE_NAME_LETTER_GetActive(letter) == 0) {
        return 1;
    }
    if (motion->framesY <= 0) {
        return 1;
    }
    return 0;
}

/* One frame of movement: both axes, the OAM position, and deactivation when done. */
void PLACE_NAME_LETTER_UpdateActive(PlaceNameLetter *letter)
{
    if (PLACE_NAME_LETTER_GetActive(letter)) {
        PLACE_NAME_LETTER_StepX(letter);
        PLACE_NAME_LETTER_StepY(letter);
        PLACE_NAME_LETTER_UpdateOamPos(letter);
        if (PLACE_NAME_LETTER_IsFinished(letter) == 1) {
            PLACE_NAME_LETTER_Deactivate(letter);
        }
    }
}

/* One step on the x axis: x += vx + ax / 2, vx += ax; the last step snaps to the target. */
void PLACE_NAME_LETTER_StepX(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion;
    if (PLACE_NAME_LETTER_IsXDone(letter) == 1) {
        return;
    }
    motion = &letter->motion;
#if LANGUAGE == LANGUAGE_JAPANESE
    letter->motion.x = letter->motion.x + motion->vx;
    motion->vx = motion->vx + motion->ax;
    motion->framesX = motion->framesX - 1;
#else
    letter->motion.x = letter->motion.x + (motion->vx + motion->ax / 2.0f);
    motion->vx = motion->vx + motion->ax;
    motion->framesX = motion->framesX - 1;
    if (motion->framesX == 0) {
        motion->x = motion->targetX;
    }
#endif
}

/* One step on the y axis. */
void PLACE_NAME_LETTER_StepY(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion;
    if (PLACE_NAME_LETTER_IsYDone(letter) == 1) {
        return;
    }
    motion = &letter->motion;
#if LANGUAGE == LANGUAGE_JAPANESE
    motion->y = motion->y + motion->vy;
    motion->vy = motion->vy + motion->ay;
    motion->framesY = motion->framesY - 1;
#else
    motion->y = motion->y + (motion->vy + motion->ay / 2.0f);
    motion->vy = motion->vy + motion->ay;
    motion->framesY = motion->framesY - 1;
    if (motion->framesY == 0) {
        motion->y = motion->targetY;
    }
#endif
}

void PLACE_NAME_LETTER_Activate(PlaceNameLetter *letter)
{
    letter->active = 1;
}

void PLACE_NAME_LETTER_Deactivate(PlaceNameLetter *letter)
{
    letter->active = 0;
}

/*
 * Derives acceleration and frame count per axis from start and target:
 * a = (targetV^2 - v^2) / (2 * distance), frames = (targetV - v) / a.
 */
void PLACE_NAME_LETTER_ComputeAcceleration(PlaceNameLetter *letter)
{
    float dx;
    float dy;
    PlaceNameLetterMotion *motion;
    motion = &letter->motion;
    dx = motion->targetX - letter->motion.x;
    dy = motion->targetY - motion->y;
    if (dx != 0.0f) {
        motion->ax = (motion->targetVx * motion->targetVx - motion->vx * motion->vx) / (2.0f * dx);
    }
    if (dy != 0.0f) {
        motion->ay = (motion->targetVy * motion->targetVy - motion->vy * motion->vy) / (2.0f * dy);
    }
    if (motion->ax != 0.0f) {
        motion->framesX = (motion->targetVx - motion->vx) / motion->ax;
    }
    if (motion->ay != 0.0f) {
        motion->framesY = (motion->targetVy - motion->vy) / motion->ay;
    }
}

/* Copies the start and target values into the motion, then derives acceleration and frames. */
void PLACE_NAME_LETTER_SetMotion(PlaceNameLetter *letter, const PlaceNameLetterParam *param)
{
    letter->motion.x = param->x;
    letter->motion.y = param->y;
    letter->motion.vx = param->vx;
    letter->motion.vy = param->vy;
    letter->motion.targetX = param->targetX;
    letter->motion.targetY = param->targetY;
    letter->motion.targetVx = param->targetVx;
    letter->motion.targetVy = param->targetVy;
    PLACE_NAME_LETTER_ComputeAcceleration(letter);
}

/* Clears the letter bitmap. */
void PLACE_NAME_LETTER_ClearBmp(PlaceNameLetter *letter)
{
    BMP_Clear(letter->bmp, 0);
}

/* Prints the character into the bitmap and uploads it to the OAM actor. */
void PLACE_NAME_LETTER_PrintChar(PlaceNameLetter *letter)
{
    u16 chars[2];
    Strbuf *strbuf;
    chars[0] = PLACE_NAME_LETTER_GetChar(letter);
    chars[1] = STRBUF_GetEosChar();
    strbuf = STRBUF_Create(2, letter->heapId);
    STRBUF_SetStringN(strbuf, chars, 2);
    PRINTSYS_PrintColor(letter->bmp, 0, 0, strbuf, letter->font, PLACE_NAME_LETTER_PRINT_COLOR);
    BMP_OAM_UploadChars(letter->bmpOam);
    STRBUF_Delete(strbuf);
}

/* Moves the OAM actor to the letter's position. */
void PLACE_NAME_LETTER_UpdateOamPos(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion = PLACE_NAME_LETTER_GetMotion(letter);
    int x = (int)motion->x;
    int y = (int)motion->y;
    BMP_OAM_SetPos(letter->bmpOam, x, y);
}

void PLACE_NAME_LETTER_SetVisibleRaw(PlaceNameLetter *letter, unsigned int visible)
{
    BMP_OAM_SetEnabled(letter->bmpOam, visible);
}

/* Pixel width and height of one character in the font. */
void PLACE_NAME_LETTER_MeasureChar(GfFont *font, u16 ch, u32 heapId, u8 *width, u8 *height)
{
    u16 chars[2];
    Strbuf *strbuf;
    chars[0] = ch;
    chars[1] = STRBUF_GetEosChar();
    strbuf = STRBUF_Create(2, heapId);
    STRBUF_SetStringN(strbuf, chars, 2);
    *width = PRINTSYS_MeasureWidestLine(strbuf, font, 0);
    *height = PRINTSYS_CountLines(strbuf, font);
    STRBUF_Delete(strbuf);
}
