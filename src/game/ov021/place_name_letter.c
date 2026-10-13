/*
 * file:     place_name_letter.c
 * unit:     yes
 * function: func_021BD148, func_021BD184, func_021BD19C, func_021BD1CC, func_021BD1D4, func_021BD1DC, func_021BD1E4, func_021BD1EC, func_021BD1F4, func_021BD1FC, func_021BD204, func_021BD20C, func_021BD214, func_021BD22C, func_021BD234, func_021BD250, func_021BD264, func_021BD278, func_021BD2A4, func_021BD2B8, func_021BD2BC, func_021BD2C0, func_021BD2C4, func_021BD2C8, func_021BD2D0, func_021BD2D8, func_021BD2DC, func_021BD2E8, func_021BD2F4, func_021BD2FC, func_021BD304, func_021BD308, func_021BD30C, func_021BD340, func_021BD36C, func_021BD394, func_021BD3BC, func_021BD3EC, func_021BD430, func_021BD474, func_021BD47C, func_021BD484, func_021BD554, func_021BD57C, func_021BD588, func_021BD5D4, func_021BD5F8, func_021BD604
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
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_02045808  0x02045808  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021DE368     0x021DE368  data  a4
 *   func_020437AC  0x020437AC  arm
 *   func_0209C494  0x0209C494  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020257D0  0x020257D0  thumb
 *   func_02025774  0x02025774  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

#include "field_place_name_types.h"

typedef struct GfFont GfFont;
typedef struct Strbuf Strbuf;
typedef struct Bmp Bmp;
typedef struct BmpOamSys BmpOamSys;
typedef struct BmpOam BmpOam;

/* Same layout as struct BmpOamParam in arm9/bmp_oam.c. */
typedef struct BmpOamParam {
    const Bmp *bmp;                     /* 0x00 */
    s16 x;                              /* 0x04 */
    s16 y;                              /* 0x06 */
    u32 animResId;                      /* 0x08 */
    u32 palette;                        /* 0x0C */
    u8 drawPriority;                    /* 0x10 */
    u8 bgPriority;                      /* 0x11 */
    u16 space;                          /* 0x12 */
    u32 engine;                         /* 0x14 */
} BmpOamParam;

/* Bitmap size of one letter in 8x8 tiles. */
#define PLACE_NAME_LETTER_TILES_WIDE 2
#define PLACE_NAME_LETTER_TILES_HIGH 2
#define PLACE_NAME_LETTER_BMP_DEPTH 0x20
#define PLACE_NAME_LETTER_PRINT_COLOR 0x440

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short line);
extern u32 func_020307B0(void *p);
extern void func_02043B5C(Bmp *bmp, u8 value);
extern void func_02045808(Strbuf *strbuf);
extern void func_02082BCC(void *dst, int value, int size);
extern Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern u16 func_02045A98(void);
extern Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heapId);
extern void func_020437AC(Bmp *bmp);
extern BmpOam *func_020255A0(BmpOamSys *sys, const BmpOamParam *param);
extern void func_0202570C(BmpOam *bmpOam);
extern u32 func_0209C494(u32 value);
extern void func_02045994(Strbuf *strbuf, const u16 *chars, u32 count);
extern void func_0201C7D0(Bmp *bmp, s16 x, s16 y, Strbuf *strbuf, GfFont *font, u16 color);
extern void func_020257D0(BmpOam *bmpOam);
extern void func_0202590C(BmpOam *bmpOam, int x, int y);
extern void func_02025774(BmpOam *bmpOam, unsigned int visible);
extern u32 func_0201D304(Strbuf *strbuf, GfFont *font, u32 spacing);
extern u32 func_0201D42C(Strbuf *strbuf, GfFont *font);
PlaceNameLetter *func_021BD148(u32 heapId, BmpOamSys *bmpOamSys, u16 space, int paletteId);
void func_021BD184(PlaceNameLetter *letter);
void func_021BD19C(PlaceNameLetter *letter, const PlaceNameLetterParam *param);
void func_021BD1CC(PlaceNameLetter *letter);
void func_021BD1D4(PlaceNameLetter *letter);
Bmp *func_021BD1DC(PlaceNameLetter *letter);
void func_021BD1E4(PlaceNameLetter *letter, unsigned int visible);
int func_021BD1EC(PlaceNameLetter *letter);
int func_021BD1F4(PlaceNameLetter *letter);
u32 func_021BD1FC(PlaceNameLetter *letter);
u32 func_021BD204(PlaceNameLetter *letter);
unsigned int func_021BD20C(PlaceNameLetter *letter);
PlaceNameLetter *func_021BD214(u32 heapId);
u32 func_021BD22C(PlaceNameLetter *letter);
void func_021BD234(PlaceNameLetter *letter);
void func_021BD250(PlaceNameLetter *letter);
void func_021BD264(PlaceNameLetter *letter);
void func_021BD278(PlaceNameLetter *letter, BmpOamSys *bmpOamSys, u16 space, int paletteId);
void func_021BD2A4(PlaceNameLetter *letter);
u16 func_021BD2B8(PlaceNameLetter *letter);
void func_021BD2BC(PlaceNameLetter *letter, int heapId);
GfFont *func_021BD2C0(PlaceNameLetter *letter);
void func_021BD2C4(PlaceNameLetter *letter, GfFont *font);
u16 func_021BD2C8(PlaceNameLetter *letter);
void func_021BD2D0(PlaceNameLetter *letter, u16 ch);
u32 func_021BD2D8(PlaceNameLetter *letter);
u32 func_021BD2DC(PlaceNameLetter *letter);
u32 func_021BD2E8(PlaceNameLetter *letter);
u8 func_021BD2F4(PlaceNameLetter *letter);
u8 func_021BD2FC(PlaceNameLetter *letter);
PlaceNameLetterMotion *func_021BD304(PlaceNameLetter *letter);
Bmp *func_021BD308(PlaceNameLetter *letter);
void func_021BD30C(PlaceNameLetter *letter);
int func_021BD340(PlaceNameLetter *letter);
int func_021BD36C(PlaceNameLetter *letter);
int func_021BD394(PlaceNameLetter *letter);
void func_021BD3BC(PlaceNameLetter *letter);
void func_021BD3EC(PlaceNameLetter *letter);
void func_021BD430(PlaceNameLetter *letter);
void func_021BD474(PlaceNameLetter *letter);
void func_021BD47C(PlaceNameLetter *letter);
void func_021BD484(PlaceNameLetter *letter);
void func_021BD554(PlaceNameLetter *letter, const PlaceNameLetterParam *param);
void func_021BD57C(PlaceNameLetter *letter);
void func_021BD588(PlaceNameLetter *letter);
void func_021BD5D4(PlaceNameLetter *letter);
void func_021BD5F8(PlaceNameLetter *letter, unsigned int visible);
void func_021BD604(GfFont *font, u16 ch, u32 heapId, u8 *width, u8 *height);
extern u8 d_021DE368[20];

/* Creates a letter: work, bitmap, OAM actor. It starts hidden and inactive. */
PlaceNameLetter *func_021BD148(u32 heapId, BmpOamSys *bmpOamSys, u16 space, int paletteId)
{
    PlaceNameLetter *letter = func_021BD214(heapId);
    func_021BD234(letter);
    func_021BD2BC(letter, heapId);
    func_021BD250(letter);
    func_021BD278(letter, bmpOamSys, space, paletteId);
    func_021BD5F8(letter, 0);
    return letter;
}

void func_021BD184(PlaceNameLetter *letter)
{
    func_021BD2A4(letter);
    func_021BD264(letter);
    func_021BD22C(letter);
}

/* Gives the letter its character and motion, draws the glyph and sets the OAM position. */
void func_021BD19C(PlaceNameLetter *letter, const PlaceNameLetterParam *param)
{
    func_021BD2C4(letter, param->font);
    func_021BD2D0(letter, param->ch);
    func_021BD30C(letter);
    func_021BD57C(letter);
    func_021BD588(letter);
    func_021BD554(letter, param);
}

void func_021BD1CC(PlaceNameLetter *letter)
{
    func_021BD3BC(letter);
}

void func_021BD1D4(PlaceNameLetter *letter)
{
    func_021BD474(letter);
}

Bmp *func_021BD1DC(PlaceNameLetter *letter)
{
    return func_021BD308(letter);
}

void func_021BD1E4(PlaceNameLetter *letter, unsigned int visible)
{
    func_021BD5F8(letter, visible);
}

int func_021BD1EC(PlaceNameLetter *letter)
{
    return func_021BD2F4(letter);
}

int func_021BD1F4(PlaceNameLetter *letter)
{
    return func_021BD2FC(letter);
}

u32 func_021BD1FC(PlaceNameLetter *letter)
{
    return func_021BD2DC(letter);
}

u32 func_021BD204(PlaceNameLetter *letter)
{
    return func_021BD2E8(letter);
}

/* 1 while the letter moves. */
unsigned int func_021BD20C(PlaceNameLetter *letter)
{
    return func_021BD2D8(letter);
}

PlaceNameLetter *func_021BD214(u32 heapId)
{
    return func_02030734(heapId, 0x4C, 0, (const char *)&d_021DE368, 0x170);
}

u32 func_021BD22C(PlaceNameLetter *letter)
{
    return func_020307B0(letter);
}

void func_021BD234(PlaceNameLetter *letter)
{
    func_02082BCC(letter, 0, 0x4C);
    letter->active = 0;
    letter->ch = func_02045A98();
}

void func_021BD250(PlaceNameLetter *letter)
{
    letter->bmp = func_02043678(PLACE_NAME_LETTER_TILES_WIDE, PLACE_NAME_LETTER_TILES_HIGH, PLACE_NAME_LETTER_BMP_DEPTH, letter->heapId);
}

void func_021BD264(PlaceNameLetter *letter)
{
    Bmp *bmp = letter->bmp;
    if (bmp != 0) {
        func_020437AC(bmp);
        letter->bmp = 0;
    }
}

void func_021BD278(PlaceNameLetter *letter, BmpOamSys *bmpOamSys, u16 space, int paletteId)
{
    BmpOamParam param;
    param.bmp = letter->bmp;
    param.x = 0;
    param.y = 0;
    param.animResId = paletteId;
    param.palette = 0;
    param.drawPriority = 0;
    param.bgPriority = 0;
    param.space = space;
    param.engine = 0;
    letter->bmpOam = func_020255A0(bmpOamSys, &param);
}

void func_021BD2A4(PlaceNameLetter *letter)
{
    if (letter->bmpOam != 0) {
        func_0202570C(letter->bmpOam);
        letter->bmpOam = 0;
    }
}

u16 func_021BD2B8(PlaceNameLetter *letter)
{
    return letter->heapId;
}

void func_021BD2BC(PlaceNameLetter *letter, int heapId)
{
    letter->heapId = heapId;
}

GfFont *func_021BD2C0(PlaceNameLetter *letter)
{
    return letter->font;
}

void func_021BD2C4(PlaceNameLetter *letter, GfFont *font)
{
    letter->font = font;
}

u16 func_021BD2C8(PlaceNameLetter *letter)
{
    return letter->ch;
}

void func_021BD2D0(PlaceNameLetter *letter, u16 ch)
{
    letter->ch = ch;
}

u32 func_021BD2D8(PlaceNameLetter *letter)
{
    return letter->active;
}

/* Current x position as an integer (letter + 0x10 is the motion x). */
u32 func_021BD2DC(PlaceNameLetter *letter)
{
    return func_0209C494(*(u32 *)&letter->motion.x);
}

/* Current y position as an integer. */
u32 func_021BD2E8(PlaceNameLetter *letter)
{
    return func_0209C494(*(u32 *)&letter->motion.y);
}

u8 func_021BD2F4(PlaceNameLetter *letter)
{
    return letter->width;
}

u8 func_021BD2FC(PlaceNameLetter *letter)
{
    return letter->height;
}

PlaceNameLetterMotion *func_021BD304(PlaceNameLetter *letter)
{
    return &letter->motion;
}

Bmp *func_021BD308(PlaceNameLetter *letter)
{
    return letter->bmp;
}

/* Measures the glyph of the letter's character. */
void func_021BD30C(PlaceNameLetter *letter)
{
    GfFont *font;
    u16 ch;
    font = func_021BD2C0(letter);
    ch = func_021BD2C8(letter);
    func_021BD604(font, ch, func_021BD2B8(letter), &letter->width, &letter->height);
}

/* 1 when the letter is inactive or both axes finished. */
int func_021BD340(PlaceNameLetter *letter)
{
    if (func_021BD2D8(letter) == 0) {
        return 1;
    }
    if (func_021BD36C(letter) != 0) {
        if (func_021BD394(letter) != 0) {
            return 1;
        }
    }
    return 0;
}

/* 1 when the x axis needs no more steps. */
int func_021BD36C(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion = func_021BD304(letter);
    if (func_021BD2D8(letter) == 0) {
        return 1;
    }
    if (motion->framesX <= 0) {
        return 1;
    }
    return 0;
}

/* 1 when the y axis needs no more steps. */
int func_021BD394(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion = func_021BD304(letter);
    if (func_021BD2D8(letter) == 0) {
        return 1;
    }
    if (motion->framesY <= 0) {
        return 1;
    }
    return 0;
}

/* One frame of movement: both axes, the OAM position, and deactivation when done. */
void func_021BD3BC(PlaceNameLetter *letter)
{
    if (func_021BD2D8(letter)) {
        func_021BD3EC(letter);
        func_021BD430(letter);
        func_021BD5D4(letter);
        if (func_021BD340(letter) == 1) {
            func_021BD47C(letter);
        }
    }
}

/* One step on the x axis: x += vx + ax / 2, vx += ax; the last step snaps to the target. */
void func_021BD3EC(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion;
    if (func_021BD36C(letter) == 1) {
        return;
    }
    motion = &letter->motion;
    letter->motion.x = letter->motion.x + (motion->vx + motion->ax / 2.0f);
    motion->vx = motion->vx + motion->ax;
    motion->framesX = motion->framesX - 1;
    if (motion->framesX == 0) {
        motion->x = motion->targetX;
    }
}

/* One step on the y axis. */
void func_021BD430(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion;
    if (func_021BD394(letter) == 1) {
        return;
    }
    motion = &letter->motion;
    motion->y = motion->y + (motion->vy + motion->ay / 2.0f);
    motion->vy = motion->vy + motion->ay;
    motion->framesY = motion->framesY - 1;
    if (motion->framesY == 0) {
        motion->y = motion->targetY;
    }
}

void func_021BD474(PlaceNameLetter *letter)
{
    letter->active = 1;
}

void func_021BD47C(PlaceNameLetter *letter)
{
    letter->active = 0;
}

/*
 * Derives acceleration and frame count per axis from start and target:
 * a = (targetV^2 - v^2) / (2 * distance), frames = (targetV - v) / a.
 */
void func_021BD484(PlaceNameLetter *letter)
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
void func_021BD554(PlaceNameLetter *letter, const PlaceNameLetterParam *param)
{
    letter->motion.x = param->x;
    letter->motion.y = param->y;
    letter->motion.vx = param->vx;
    letter->motion.vy = param->vy;
    letter->motion.targetX = param->targetX;
    letter->motion.targetY = param->targetY;
    letter->motion.targetVx = param->targetVx;
    letter->motion.targetVy = param->targetVy;
    func_021BD484(letter);
}

/* Clears the letter bitmap. */
void func_021BD57C(PlaceNameLetter *letter)
{
    func_02043B5C(letter->bmp, 0);
}

/* Prints the character into the bitmap and uploads it to the OAM actor. */
void func_021BD588(PlaceNameLetter *letter)
{
    u16 chars[2];
    Strbuf *strbuf;
    chars[0] = func_021BD2C8(letter);
    chars[1] = func_02045A98();
    strbuf = func_020457B0(2, letter->heapId);
    func_02045994(strbuf, chars, 2);
    func_0201C7D0(letter->bmp, 0, 0, strbuf, letter->font, PLACE_NAME_LETTER_PRINT_COLOR);
    func_020257D0(letter->bmpOam);
    func_02045808(strbuf);
}

/* Moves the OAM actor to the letter's position. */
void func_021BD5D4(PlaceNameLetter *letter)
{
    PlaceNameLetterMotion *motion = func_021BD304(letter);
    int x = (int)motion->x;
    int y = (int)motion->y;
    func_0202590C(letter->bmpOam, x, y);
}

void func_021BD5F8(PlaceNameLetter *letter, unsigned int visible)
{
    func_02025774(letter->bmpOam, visible);
}

/* Pixel width and height of one character in the font. */
void func_021BD604(GfFont *font, u16 ch, u32 heapId, u8 *width, u8 *height)
{
    u16 chars[2];
    Strbuf *strbuf;
    chars[0] = ch;
    chars[1] = func_02045A98();
    strbuf = func_020457B0(2, heapId);
    func_02045994(strbuf, chars, 2);
    *width = func_0201D304(strbuf, font, 0);
    *height = func_0201D42C(strbuf, font);
    func_02045808(strbuf);
}
