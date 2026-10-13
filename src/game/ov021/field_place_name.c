/*
 * file:     field_place_name.c
 * unit:     yes
 * function: func_021BC388, func_021BC424, func_021BC484, func_021BC4F0, func_021BC550, func_021BC578, func_021BC5A0, func_021BC5BC, func_021BC5D4, func_021BC5E4, func_021BC63C, func_021BC654, func_021BC664, func_021BC6B4, func_021BC6D0, func_021BC6E8, func_021BC704, func_021BC720, func_021BC730, func_021BC748, func_021BC75C, func_021BC788, func_021BC794, func_021BC7B0, func_021BC7BC, func_021BC7D4, func_021BC7F8, func_021BC810, func_021BC824, func_021BC838, func_021BC848, func_021BC910, func_021BC92C, func_021BC948, func_021BC970, func_021BC998, func_021BC9AC, func_021BC9C0, func_021BC9CC, func_021BCA48, func_021BCA64, func_021BCA6C, func_021BCA74, func_021BCA78, func_021BCA80, func_021BCA88, func_021BCA8C, func_021BCAB0, func_021BCB48, func_021BCB9C, func_021BCBC8, func_021BCC3C, func_021BCC80, func_021BCD34, func_021BCD70, func_021BCD84, func_021BCDD8, func_021BCE88, func_021BCEAC, func_021BCEB0, func_021BCEB4, func_021BCF18, func_021BCF1C, func_021BCF20, func_021BCF24, func_021BCF88, func_021BCFA4, func_021BCFD8, func_021BCFE0, func_021BCFF0, func_021BD008, func_021BD01C, func_021BD040, func_021BD054, func_021BD068, func_021BD07C, func_021BD090, func_021BD094, func_021BD098, func_021BD09C, func_021BD0A0, func_021BD0A4, func_021BD0A8, func_021BD0B0, func_021BD0C0, func_021BD0C8, func_021BD0D0, func_021BD0E0, func_021BD0FC, func_021BD118, func_021BD120, func_021BD134, func_021BD138, func_021BD140
 * address:  0x021BC388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BC388 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_020493D4  0x020493D4  arm
 *   func_02030734  0x02030734  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 *   d_021D9B78     0x021D9B78  data  a4
 *   func_0204B084  0x0204B084  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02049238  0x02049238  arm
 *   func_02045A38  0x02045A38  arm
 *   sub_0201DC6C   0x0201DC6C  thumb
 *   d_021D9B88     0x021D9B88  data  a4
 *   func_02045770  0x02045770  arm
 *   func_020439A0  0x020439A0  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb
 *   func_0215841C  0x0215841C  thumb
 *   func_021583EC  0x021583EC  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_020458F8  0x020458F8  arm
 *   func_02012B38  0x02012B38  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_020414C4  0x020414C4  arm
 *   func_020414EC  0x020414EC  arm
 *   d_021DE354     0x021DE354  data  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02008998  0x02008998  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_020089A0  0x020089A0  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_021BD148 0x021BD148 thumb ov021
 *   func_021BD184 0x021BD184 thumb ov021
 *   func_021BD19C 0x021BD19C thumb ov021
 *   func_021BD1CC 0x021BD1CC thumb ov021
 *   func_021BD1D4 0x021BD1D4 thumb ov021
 *   func_021BD1DC 0x021BD1DC thumb ov021
 *   func_021BD1E4 0x021BD1E4 thumb ov021
 *   func_021BD1EC 0x021BD1EC thumb ov021
 *   func_021BD1F4 0x021BD1F4 thumb ov021
 *   func_021BD1FC 0x021BD1FC thumb ov021
 *   func_021BD204 0x021BD204 thumb ov021
 *   func_021BD20C 0x021BD20C thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#include "field_place_name_types.h"

typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct WordSet WordSet;
typedef struct ArcFile ArcFile;
typedef struct MsgData MsgData;
typedef struct GfFont GfFont;
typedef struct Strbuf Strbuf;
typedef struct BmpWin BmpWin;
typedef struct Bmp Bmp;
typedef struct BmpOamSys BmpOamSys;
typedef struct ClactUnit ClactUnit;
typedef struct ClactRenderer ClactRenderer;
typedef struct NitroFileHeader NitroFileHeader;
struct BgTemplate;
struct FieldMsgContext;

#define REG_BLDCNT_ADDR 0x04000050
/* Address of the BG3 template table in the overlay data (a symbol here changes the literal pool relocation). */
#define FIELD_PLACE_NAME_BG_TEMPLATE_ADDR 0x021DE334

#define FIELD_PLACE_NAME_BG_LAYER 3
#define FIELD_PLACE_NAME_MAX_MESSAGE_CHARS 32
#define FIELD_PLACE_NAME_PLACE_COUNT 0x75
#define FIELD_PLACE_NAME_FADE_IN_FRAMES 10
#define FIELD_PLACE_NAME_FADE_OUT_FRAMES 20
#define FIELD_PLACE_NAME_LETTER_INTERVAL 3
#define FIELD_PLACE_NAME_HOLD_FRAMES 30

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short line);
extern u32 func_020307B0(void *p);
extern GfFont *func_021904AC(struct FieldMsgContext *msgContext);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020403F4(u32 bgId);
extern void func_02045334(BmpWin *bmpWin);
extern void func_02045374(BmpWin *bmpWin);
extern unsigned char func_02045730(BmpWin *bmpWin);
extern void func_020409B4(unsigned int bgLayer);
extern void func_0204047C(int bgId, unsigned short priority);
extern void func_02040588(unsigned char bgId, unsigned char enable);
extern void func_0207D63C(int regAddr, int plane1, int plane2, int evA, int evB);
extern void func_020414AC(int bgId);
extern u32 func_020493D4(ArcFile *arc, u32 member);
extern void func_0204932C(ArcFile *arc, u32 member, void *dst);
extern s32 func_02062A98(NitroFileHeader *file, void **out);
extern void func_02040E78(u32 bgId, void *src, u32 size, u32 offset);
extern u32 func_0203FA08(u32 bgId, u32 size, u32 top);
extern void func_0203FB44(u32 bgId, u32 offset, u32 size);
extern Bmp *func_02045770(BmpWin *bmpWin);
extern void func_02043B5C(Bmp *bmp, u8 value);
extern ClactRenderer *func_0204B034(const u8 *initParam, u32 count, u32 heapId);
extern void func_0204B084(ClactRenderer *renderer);
extern s32 func_0204AC18(ArcFile *arc, u32 type, u32 index, u32 size, u16 plane, u16 compress, u16 heapId);
extern void func_0204ADA4(u32 paletteId);
extern ClactUnit *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(ClactUnit *unit, u32 mode);
extern u32 func_0204B1CC(ClactUnit *unit);
extern void func_0204B258(ClactUnit *unit, ClactRenderer *renderer);
extern ArcFile *func_020490F4(u32 arcId, u32 heapId);
extern void func_02049238(ArcFile *arc);
extern void func_02045A38(Strbuf *strbuf, u16 *out, u32 count);
extern u32 sub_0201DC6C(GfFont *font, u16 ch);
extern BmpOamSys *func_02025538(unsigned int heapId, ClactUnit *unit);
extern void func_02025588(BmpOamSys *sys);
extern void func_020439A0(Bmp *dst, Bmp *src, u32 x, u32 y, int srcX, int srcY, u32 w, u32 h, u32 key);
extern u32 func_02013E4C(u32 zoneId);
extern unsigned int func_02012138(const GameSystem *gameSystem);
extern int func_02158344(int gameComm);
extern int func_0215841C(GameData *gameData);
extern int func_021583EC(GameData *gameData, int netId);
extern Strbuf *func_02045EC0(MsgData *msgData, u32 index);
extern void func_02045CAC(MsgData *msgData, u32 index, Strbuf *dst);
extern void func_0201F02C(WordSet *wordSet, u32 index, void *myStatus);
extern void func_0201F158(WordSet *wordSet, u32 index, u32 value);
extern void func_0201F250(WordSet *wordSet, Strbuf *dst, Strbuf *src);
extern void func_02045808(Strbuf *strbuf);
extern u16 func_020458F8(Strbuf *strbuf);
extern void *func_02012B38(const GameData *gameData);
extern u8 func_02012B58(const GameData *gameData);
extern unsigned int func_0201444C(void *fieldStatus);
extern u32 func_02013D5C(u32 zoneId);
extern void func_020414C4(u32 bgId);
extern void func_020414EC(u32 bgId);
extern void func_02082BCC(void *dst, int value, int size);
extern void *func_020120F4(const GameSystem *gameSystem);
extern WordSet *func_0201EC64(u32 heapId);
extern MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern BmpWin *func_020450F0(u32 bgId, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_0201ED04(WordSet *wordSet);
extern u32 func_02045C04(MsgData *msgData);
extern u32 func_020452E8(BmpWin *bmpWin);
extern void *func_02012EBC(GameData *gameData);
extern void *func_02008854(void *saveControl);
extern u16 func_02008998(const void *location);
extern u32 func_020089A0(u32 location, u32 zoneId);
extern u32 func_02013E6C(u32 zoneId);
extern const u8 d_021D9B78[16];
extern const PlaceNameLetterParam d_021D9B88;
extern u8 d_021DE354[20];

FieldPlaceName *func_021BC388(GameSystem *gameSystem, u32 heapId, struct FieldMsgContext *msgContext);
void func_021BC424(FieldPlaceName *placeName);
void func_021BC484(FieldPlaceName *placeName);
void func_021BC4F0(FieldPlaceName *placeName);
void func_021BC550(FieldPlaceName *placeName, int zoneId);
void func_021BC578(FieldPlaceName *placeName, int zoneId);
void func_021BC5A0(FieldPlaceName *placeName, int zoneId);
int func_021BC5BC(FieldPlaceName *placeName);
void func_021BC5D4(FieldPlaceName *placeName);
void func_021BC5E4(FieldPlaceName *placeName);
void func_021BC63C(FieldPlaceName *placeName);
void func_021BC654(FieldPlaceName *placeName);
void func_021BC664(FieldPlaceName *placeName);
void func_021BC6B4(FieldPlaceName *placeName);
void func_021BC6D0(FieldPlaceName *placeName);
void func_021BC6E8(FieldPlaceName *placeName);
void func_021BC704(FieldPlaceName *placeName);
void func_021BC720(FieldPlaceName *placeName);
void func_021BC730(FieldPlaceName *placeName);
void func_021BC748(FieldPlaceName *placeName);
void func_021BC75C(FieldPlaceName *placeName);
void func_021BC788(FieldPlaceName *placeName);
void func_021BC794(FieldPlaceName *placeName);
void func_021BC7B0(FieldPlaceName *placeName);
void func_021BC7BC(FieldPlaceName *placeName, int unitIndex);
void func_021BC7D4(FieldPlaceName *placeName);
void func_021BC7F8(FieldPlaceName *placeName);
void func_021BC810(FieldPlaceName *placeName);
void func_021BC824(FieldPlaceName *placeName);
void func_021BC838(FieldPlaceName *placeName);
void func_021BC848(FieldPlaceName *placeName);
int func_021BC910(FieldPlaceName *placeName);
void func_021BC92C(FieldPlaceName *placeName);
void func_021BC948(FieldPlaceName *placeName);
void func_021BC970(FieldPlaceName *placeName);
void func_021BC998(FieldPlaceName *placeName);
void func_021BC9AC(FieldPlaceName *placeName);
void func_021BC9C0(FieldPlaceName *placeName);
void func_021BC9CC(FieldPlaceName *placeName);
int func_021BCA48(FieldPlaceName *placeName);
void func_021BCA64(FieldPlaceName *placeName);
FieldPlaceName *func_021BCA6C(FieldPlaceName *placeName);
u32 func_021BCA74(FieldPlaceName *placeName);
void func_021BCA78(FieldPlaceName *placeName);
void func_021BCA80(FieldPlaceName *placeName);
u32 func_021BCA88(FieldPlaceName *placeName);
int func_021BCA8C(FieldPlaceName *placeName);
void func_021BCAB0(FieldPlaceName *placeName);
int func_021BCB48(FieldPlaceName *placeName, int zoneId);
void func_021BCB9C(FieldPlaceName *placeName, int newState);
void func_021BCBC8(FieldPlaceName *placeName);
void func_021BCC3C(FieldPlaceName *placeName);
void func_021BCC80(FieldPlaceName *placeName);
void func_021BCD34(FieldPlaceName *placeName);
void func_021BCD70(FieldPlaceName *placeName);
void func_021BCD84(FieldPlaceName *placeName);
void func_021BCDD8(FieldPlaceName *placeName);
void func_021BCE88(FieldPlaceName *placeName);
void func_021BCEAC(FieldPlaceName *placeName);
void func_021BCEB0(FieldPlaceName *placeName);
void func_021BCEB4(FieldPlaceName *placeName);
void func_021BCF18(FieldPlaceName *placeName);
void func_021BCF1C(FieldPlaceName *placeName);
void func_021BCF20(FieldPlaceName *placeName);
void func_021BCF24(FieldPlaceName *placeName);
FieldPlaceName *func_021BCF88(u32 heapId);
void func_021BCFA4(FieldPlaceName *placeName, GameSystem *gameSystem);
void func_021BCFD8(FieldPlaceName *placeName);
void func_021BCFE0(FieldPlaceName *placeName);
void func_021BCFF0(FieldPlaceName *placeName);
void func_021BD008(FieldPlaceName *placeName);
void func_021BD01C(FieldPlaceName *placeName);
void func_021BD040(FieldPlaceName *placeName);
void func_021BD054(FieldPlaceName *placeName);
void func_021BD068(FieldPlaceName *placeName);
void func_021BD07C(FieldPlaceName *placeName);
u16 func_021BD090(FieldPlaceName *placeName);
ArcFile *func_021BD094(FieldPlaceName *placeName);
void func_021BD098(FieldPlaceName *placeName, int heapId);
void func_021BD09C(FieldPlaceName *placeName, GfFont *font);
void func_021BD0A0(FieldPlaceName *placeName, int state);
u32 func_021BD0A4(FieldPlaceName *placeName);
void func_021BD0A8(FieldPlaceName *placeName);
void func_021BD0B0(FieldPlaceName *placeName);
u8 func_021BD0C0(FieldPlaceName *placeName);
void func_021BD0C8(FieldPlaceName *placeName);
void func_021BD0D0(FieldPlaceName *placeName);
void func_021BD0E0(FieldPlaceName *placeName);
int func_021BD0FC(FieldPlaceName *placeName);
u16 func_021BD118(FieldPlaceName *placeName);
void func_021BD120(FieldPlaceName *placeName, u16 zoneId);
Strbuf *func_021BD134(FieldPlaceName *placeName);
u8 func_021BD138(FieldPlaceName *placeName);
u32 func_021BD140(u32 zoneId);
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

/* Creates the banner work and every part of it; msgContext supplies the font. */
FieldPlaceName *func_021BC388(GameSystem *gameSystem, u32 heapId, struct FieldMsgContext *msgContext)
{
    FieldPlaceName *placeName;

    placeName = func_021BCF88(heapId);
    func_021BCFA4(placeName, gameSystem);
    func_021BD0E0(placeName);
    func_021BC810(placeName);
    func_021BCFE0(placeName);
    func_021BCFF0(placeName);
    func_021BD008(placeName);
    func_021BD098(placeName, heapId);
    func_021BD09C(placeName, func_021904AC(msgContext));
    func_021BC730(placeName);
    func_021BC75C(placeName);
    func_021BC794(placeName);
    func_021BC7BC(placeName, 0);
    func_021BC998(placeName);
    func_021BC7D4(placeName);
    func_0203FCA0(FIELD_PLACE_NAME_BG_LAYER, (const struct BgTemplate *)FIELD_PLACE_NAME_BG_TEMPLATE_ADDR, 0);
    func_021BC664(placeName);
    func_021BC6E8(placeName);
    func_021BD01C(placeName);
    func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_IDLE);
    return placeName;
}

void func_021BC424(FieldPlaceName *placeName)
{
    func_021BD0FC(placeName);
    func_021BC6B4(placeName);
    func_021BC7F8(placeName);
    func_021BD068(placeName);
    func_021BC9AC(placeName);
    func_021BC7B0(placeName);
    func_021BC788(placeName);
    func_021BC748(placeName);
    func_021BD040(placeName);
    func_021BD054(placeName);
    func_021BD07C(placeName);
    func_021BC704(placeName);
    func_021BC824(placeName);
    func_020403F4(FIELD_PLACE_NAME_BG_LAYER);
    func_021BCFD8(placeName);
}

/* Per-frame update: advances the frame counter, runs the state handler, then moves the letters. */
void func_021BC484(FieldPlaceName *placeName)
{
    func_021BD0B0(placeName);
    switch (func_021BD0A4(placeName)) {
    case FIELD_PLACE_NAME_STATE_IDLE:
        func_021BCC3C(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_PREPARE:
        func_021BCC80(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN:
        func_021BCD34(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN_WAIT:
        func_021BCD70(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH:
        func_021BCD84(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAND:
        func_021BCDD8(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_OUT:
        func_021BCE88(placeName);
        break;
    }
    func_021BC970(placeName);
}

/* Per-frame draw: the hardware blend of the plate follows the state. */
void func_021BC4F0(FieldPlaceName *placeName)
{
    switch (func_021BD0A4(placeName)) {
    case FIELD_PLACE_NAME_STATE_IDLE:
        func_021BCEAC(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_PREPARE:
        func_021BCEB0(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN:
        func_021BCEB4(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN_WAIT:
        func_021BCF18(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH:
        func_021BCF1C(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_LETTERS_LAND:
        func_021BCF20(placeName);
        break;
    case FIELD_PLACE_NAME_STATE_FADE_OUT:
        func_021BCF24(placeName);
        break;
    }
}

/* Zone change: shows the banner when the new zone has a place name window and its place name differs. */
void func_021BC550(FieldPlaceName *placeName, int zoneId)
{
    func_021BD120(placeName, (u16)zoneId);
    if (func_021BD140((u16)zoneId)) {
        func_021BCBC8(placeName);
        func_021BCA78(placeName);
    }
}

/* Zone change: shows the banner whenever the new zone has a place name window. */
void func_021BC578(FieldPlaceName *placeName, int zoneId)
{
    func_021BD120(placeName, (u16)zoneId);
    if (func_021BD140((u16)zoneId)) {
        func_021BCBC8(placeName);
        func_021BCA64(placeName);
    }
}

/* Zone change: shows the banner in every case. */
void func_021BC5A0(FieldPlaceName *placeName, int zoneId)
{
    func_021BD120(placeName, (u16)zoneId);
    func_021BCBC8(placeName);
    func_021BCA64(placeName);
}

/* Stops the banner now and drops pending show requests. */
int func_021BC5BC(FieldPlaceName *placeName)
{
    func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_IDLE);
    func_021BCA80(placeName);
    return (int)func_021BCA6C(placeName);
}

/* Rebuilds the BG window (used after another screen took the BG layer). */
void func_021BC5D4(FieldPlaceName *placeName)
{
    func_021BC654(placeName);
    func_021BC720(placeName);
}

/* Sets up the BG window: palette, char area, window bitmap, blend registers. */
void func_021BC5E4(FieldPlaceName *placeName)
{
    BmpWin *bmpWin;

    func_021BC6D0(placeName);
    func_021BC6E8(placeName);
    func_021BD01C(placeName);
    bmpWin = placeName->bmpWin;
    func_02045334(bmpWin);
    func_02045374(bmpWin);
    func_020409B4(func_02045730(bmpWin));
    func_0204047C(FIELD_PLACE_NAME_BG_LAYER, 1);
    func_02040588(FIELD_PLACE_NAME_BG_LAYER, 0);
    func_0207D63C(REG_BLDCNT_ADDR, 8, 0x11, 0x10, 4);
}

/* Releases the BG window resources. */
void func_021BC63C(FieldPlaceName *placeName)
{
    func_020414AC(FIELD_PLACE_NAME_BG_LAYER);
    func_021BC704(placeName);
    func_021BD07C(placeName);
}

void func_021BC654(FieldPlaceName *placeName)
{
    func_021BC63C(placeName);
    func_021BC5E4(placeName);
}

/* Loads the palette file (archive member 1) and unpacks it. */
void func_021BC664(FieldPlaceName *placeName)
{
    int heapId;
    ArcFile *arcHandle;
    NitroFileHeader *file;

    heapId = func_021BD090(placeName);
    arcHandle = func_021BD094(placeName);
    file = (NitroFileHeader *)func_02030734(heapId, func_020493D4(arcHandle, 1), 0, (const char *)d_021DE354, 0x2c8);
    placeName->paletteFile = file;
    func_0204932C(arcHandle, 1, file);
    func_02062A98(placeName->paletteFile, (void **)&placeName->paletteBlock);
}

void func_021BC6B4(FieldPlaceName *placeName)
{
    if (placeName->paletteFile != 0) {
        func_020307B0(placeName->paletteFile);
        placeName->paletteFile = 0;
        placeName->paletteBlock = 0;
    }
}

/* Transfers the plate palette to the BG layer. */
void func_021BC6D0(FieldPlaceName *placeName)
{
    func_02040E78(FIELD_PLACE_NAME_BG_LAYER, placeName->paletteBlock->colors, 0x20, 0);
}

void func_021BC6E8(FieldPlaceName *placeName)
{
    if (placeName->bgCharOffset == FIELD_PLACE_NAME_NO_CHAR_OFFSET) {
        placeName->bgCharOffset = func_0203FA08(FIELD_PLACE_NAME_BG_LAYER, 0x20, 0);
    }
}

void func_021BC704(FieldPlaceName *placeName)
{
    if (placeName->bgCharOffset != FIELD_PLACE_NAME_NO_CHAR_OFFSET) {
        func_0203FB44(FIELD_PLACE_NAME_BG_LAYER, placeName->bgCharOffset, 0x20);
        placeName->bgCharOffset = FIELD_PLACE_NAME_NO_CHAR_OFFSET;
    }
}

/* Clears the window bitmap. */
void func_021BC720(FieldPlaceName *placeName)
{
    func_02043B5C(func_02045770(placeName->bmpWin), 3);
}

void func_021BC730(FieldPlaceName *placeName)
{
    placeName->clactRenderer = func_0204B034(d_021D9B78, 1, placeName->heapId);
}

void func_021BC748(FieldPlaceName *placeName)
{
    ClactRenderer *renderer = placeName->clactRenderer;
    if (renderer != 0) {
        func_0204B084(renderer);
        placeName->clactRenderer = 0;
    }
}

void func_021BC75C(FieldPlaceName *placeName)
{
    u16 heapId = func_021BD090(placeName);
    ArcFile *arcHandle = func_021BD094(placeName);
    placeName->clactPaletteId = func_0204AC18(arcHandle, 3, 0, 0x20, 0, 1, heapId);
}

void func_021BC788(FieldPlaceName *placeName)
{
    func_0204ADA4(placeName->clactPaletteId);
}

void func_021BC794(FieldPlaceName *placeName)
{
    placeName->clactUnit[0] = func_0204B100(FIELD_PLACE_NAME_MAX_LETTERS, 1, func_021BD090(placeName));
    func_0204B22C(placeName->clactUnit[0], 1);
}

void func_021BC7B0(FieldPlaceName *placeName)
{
    func_0204B1CC(placeName->clactUnit[0]);
}

void func_021BC7BC(FieldPlaceName *placeName, int unitIndex)
{
    if (placeName->clactRenderer != 0) {
        func_0204B258(placeName->clactUnit[unitIndex], placeName->clactRenderer);
    }
}

void func_021BC7D4(FieldPlaceName *placeName)
{
    int i;
    for (i = 0; i < FIELD_PLACE_NAME_MAX_LETTERS; i++) {
        placeName->letters[i] = func_021BD148(placeName->heapId, placeName->bmpOamSys, 0, placeName->clactPaletteId);
    }
}

void func_021BC7F8(FieldPlaceName *placeName)
{
    int i;
    for (i = 0; i < FIELD_PLACE_NAME_MAX_LETTERS; i++) {
        func_021BD184(placeName->letters[i]);
    }
}

void func_021BC810(FieldPlaceName *placeName)
{
    placeName->arcHandle = func_020490F4(0x54, func_021BD090(placeName));
}

void func_021BC824(FieldPlaceName *placeName)
{
    ArcFile *arcHandle = placeName->arcHandle;
    if (arcHandle != 0) {
        func_02049238(arcHandle);
        placeName->arcHandle = 0;
    }
}

/* Clears the spawned and skipped letter counters. */
void func_021BC838(FieldPlaceName *placeName)
{
    placeName->spawnedCount = 0;
    placeName->skippedSpaceCount = 0;
}

/*
 * Starts the next letter of the message. Its target x is the sum of the
 * widths of the letters before it (plus one pixel each); a space takes no
 * letter and counts as skipped.
 * The x accumulation is a compound add inside each if/else arm (the two arms
 * cross-jump into one shared `ldr x; _fadd; str x` tail), then `+= 1.0f`
 * after the join, which is why the original re-loads x it has just stored:
 * a single `x += w` after the if/else forwards the value instead.
 * The call argument is the assignment itself: `f(p->shownLetters[n] = v, &param)`
 * gives the `str r0, [r2, r1]` with the shownLetters base hoisted.
 */
void func_021BC848(FieldPlaceName *placeName)
{
    int letterIndex;
    int i;
    u16 chars[FIELD_PLACE_NAME_MAX_MESSAGE_CHARS];
    PlaceNameLetterParam param;

    letterIndex = placeName->spawnedCount;
    func_02045A38(func_021BD134(placeName), chars, FIELD_PLACE_NAME_MAX_MESSAGE_CHARS);
    param = d_021D9B88;
    param.font = placeName->font;
    param.ch = chars[letterIndex];
    for (i = 0; i < letterIndex; i++) {
        if (placeName->shownLetters[i] == 0) {
            param.targetX += sub_0201DC6C(placeName->font, 0x20);
        } else {
            param.targetX += func_021BD1EC(placeName->shownLetters[i]);
        }
        param.targetX += 1.0f;
    }
    if (param.ch == 0x20) {
        placeName->shownLetters[letterIndex] = 0;
        placeName->skippedSpaceCount++;
    } else {
        func_021BD19C(placeName->shownLetters[letterIndex] = placeName->letters[letterIndex - placeName->skippedSpaceCount], &param);
    }
    placeName->spawnedCount++;
}

/* 1 when every character of the message has been started. */
int func_021BC910(FieldPlaceName *placeName)
{
    if (func_021BD138(placeName) <= placeName->spawnedCount) {
        return 1;
    }
    return 0;
}

void func_021BC92C(FieldPlaceName *placeName)
{
    int i;
    for (i = 0; i < FIELD_PLACE_NAME_MAX_LETTERS; i++) {
        func_021BD1E4(placeName->letters[i], 0);
    }
}

/* Starts the next shown letter flying and makes it visible. */
void func_021BC948(FieldPlaceName *placeName)
{
    u8 i = placeName->launchedCount++;
    if (placeName->shownLetters[i] != 0) {
        func_021BD1D4(placeName->shownLetters[i]);
        func_021BD1E4(placeName->shownLetters[i], 1);
    }
}

/* Moves every started letter. */
void func_021BC970(FieldPlaceName *placeName)
{
    int count = func_021BD138(placeName);
    int i;
    for (i = 0; i < count; i++) {
        if (placeName->shownLetters[i] != 0) {
            func_021BD1CC(placeName->shownLetters[i]);
        }
    }
}

void func_021BC998(FieldPlaceName *placeName)
{
    placeName->bmpOamSys = func_02025538(func_021BD090(placeName), placeName->clactUnit[0]);
}

void func_021BC9AC(FieldPlaceName *placeName)
{
    if (placeName->bmpOamSys != 0) {
        func_02025588(placeName->bmpOamSys);
        placeName->bmpOamSys = 0;
    }
}

void func_021BC9C0(FieldPlaceName *placeName)
{
    placeName->blittedCount = 0;
}

/* Copies the next shown letter's bitmap into the window bitmap at its final position. */
void func_021BC9CC(FieldPlaceName *placeName)
{
    PlaceNameLetter *letter;
    Bmp *letterBmp;
    Bmp *windowBmp;
    u16 srcX, srcY, width, height;

    letter = placeName->shownLetters[placeName->blittedCount];
    if (letter != 0) {
        letterBmp = func_021BD1DC(letter);
        windowBmp = func_02045770(placeName->bmpWin);
        srcX = func_021BD1FC(letter);
        srcY = func_021BD204(letter) - 8;
        width = func_021BD1EC(letter);
        height = func_021BD1F4(letter);
        func_020439A0(letterBmp, windowBmp, 0, 0, srcX, srcY, width, height, 0);
    }
    (placeName->blittedCount)++;
}

/* 1 when every letter of the message has been blitted. */
int func_021BCA48(FieldPlaceName *placeName)
{
    if ((int)func_021BD138(placeName) <= placeName->blittedCount) {
        return 1;
    }
    return 0;
}

void func_021BCA64(FieldPlaceName *placeName)
{
    placeName->forceShowRequested = 1;
}

FieldPlaceName *func_021BCA6C(FieldPlaceName *placeName)
{
    placeName->forceShowRequested = 0;
    return placeName;
}

u32 func_021BCA74(FieldPlaceName *placeName)
{
    return placeName->zoneChangeRequested;
}

void func_021BCA78(FieldPlaceName *placeName)
{
    placeName->zoneChangeRequested = 1;
}

void func_021BCA80(FieldPlaceName *placeName)
{
    placeName->zoneChangeRequested = 0;
}

u32 func_021BCA88(FieldPlaceName *placeName)
{
    return placeName->forceShowRequested;
}

/* 1 when the previous and the current zone have different place names. */
int func_021BCA8C(FieldPlaceName *placeName)
{
    int prevPlaceNameId = func_02013E4C(placeName->prevZoneId);
    if (prevPlaceNameId != func_02013E4C(placeName->zoneId)) {
        return 1;
    }
    return 0;
}

/*
 * Reads the message for the current zone's place name into the message buffer.
 * With a visitor in the Palace the message is a template that also names the
 * player. A zone without a place name cancels the banner.
 */
void func_021BCAB0(FieldPlaceName *placeName)
{
    int zoneId;
    int myStatus;
    unsigned int placeNameId;
    Strbuf *template;

    zoneId = func_021BD118(placeName);
    placeNameId = func_02013E4C((unsigned int)zoneId);
    if (placeNameId >= FIELD_PLACE_NAME_PLACE_COUNT) {
        placeNameId = 0;
    }
    if (placeNameId == 0) {
        func_021BC5BC(placeName);
        return;
    }
    if (func_021BCB48(placeName, zoneId) != 0) {
        func_02158344((int)func_02012138(placeName->gameSystem));
        myStatus = func_021583EC(placeName->gameData, func_0215841C(placeName->gameData));
        template = func_02045EC0(placeName->msgData, 3);
        func_02045CAC(placeName->msgData, placeNameId, placeName->message);
        func_0201F02C(placeName->wordSet, 0, (void *)myStatus);
        func_0201F158(placeName->wordSet, 1, placeNameId);
        func_0201F250(placeName->wordSet, placeName->message, template);
        func_02045808(template);
    } else {
        func_02045CAC(placeName->msgData, placeNameId, placeName->message);
    }
    placeName->messageLength = func_020458F8(placeName->message);
}

/*
 * 1 when the banner must use the Palace template: a Palace connection is
 * running and either the map mode is 1 or the zone is zone 117 while the
 * player stands in another player's Palace.
 */
int func_021BCB48(FieldPlaceName *placeName, int zoneId)
{
    int intrudeId;
    void *fieldStatus;
    int ownNetId;

    intrudeId = func_02158344((int)func_02012138(placeName->gameSystem));
    fieldStatus = func_02012B38(placeName->gameData);
    ownNetId = func_02012B58(placeName->gameData);
    if (intrudeId != 0) {
        intrudeId = func_0215841C(placeName->gameData);
        if (func_0201444C(fieldStatus) == 1) {
            return 1;
        }
        if (func_02013D5C(zoneId) != 0 && ownNetId != intrudeId) {
            return 1;
        }
    }
    return 0;
}

/* Enters a new state: resets step and frame; going idle also hides the plate and the letters. */
void func_021BCB9C(FieldPlaceName *placeName, int newState)
{
    func_021BD0A0(placeName, newState);
    func_021BD0A8(placeName);
    func_021BD0C8(placeName);
    if (newState == FIELD_PLACE_NAME_STATE_IDLE) {
        func_02040588(FIELD_PLACE_NAME_BG_LAYER, 0);
        func_021BC92C(placeName);
    }
}

/*
 * A new request arrives while a banner is up: jumps to the matching point of
 * the fade out. States idle, letters launch and fade out ignore it.
 */
void func_021BCBC8(FieldPlaceName *placeName)
{
    int newState;
    int newFrame;
    switch (placeName->state) {
    case FIELD_PLACE_NAME_STATE_IDLE:
    case FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH:
    case FIELD_PLACE_NAME_STATE_FADE_OUT:
        return;
    case FIELD_PLACE_NAME_STATE_FADE_IN_WAIT:
    case FIELD_PLACE_NAME_STATE_LETTERS_LAND:
        newState = FIELD_PLACE_NAME_STATE_LETTERS_LAND;
        newFrame = FIELD_PLACE_NAME_HOLD_FRAMES;
        break;
    case FIELD_PLACE_NAME_STATE_FADE_IN:
        newState = FIELD_PLACE_NAME_STATE_FADE_OUT;
        newFrame = (int)(20.0f * (1.0f - (float)(u32)placeName->frame / 10.0f));
        break;
    case FIELD_PLACE_NAME_STATE_PREPARE:
        newState = FIELD_PLACE_NAME_STATE_IDLE;
        newFrame = 0;
        break;
    }
    func_021BCB9C(placeName, newState);
    placeName->frame = newFrame;
}

/* Idle state: starts the banner when a request is pending. */
void func_021BCC3C(FieldPlaceName *placeName)
{
    int show = 0;
    if (func_021BCA88(placeName)) {
        show = 1;
        func_021BCA6C(placeName);
    } else if (func_021BCA74(placeName)) {
        if (func_021BCA8C(placeName)) {
            show = 1;
        }
        func_021BCA80(placeName);
    }
    if (show) {
        func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_PREPARE);
    }
}

/* Prepare state: reads the message, resets the BG, then starts one letter per frame. */
void func_021BCC80(FieldPlaceName *placeName)
{
    BmpWin *bmpWin;
    switch (func_021BD0C0(placeName)) {
    case 0:
        func_021BCAB0(placeName);
        func_021BD0D0(placeName);
        break;
    case 1:
        func_020414C4(FIELD_PLACE_NAME_BG_LAYER);
        func_020414EC(FIELD_PLACE_NAME_BG_LAYER);
        func_021BC6D0(placeName);
        func_021BD0D0(placeName);
        break;
    case 2:
        func_021BC720(placeName);
        bmpWin = placeName->bmpWin;
        func_02045334(bmpWin);
        func_02045374(bmpWin);
        func_020409B4(func_02045730(bmpWin));
        func_0204047C(FIELD_PLACE_NAME_BG_LAYER, 1);
        func_02040588(FIELD_PLACE_NAME_BG_LAYER, 0);
        func_0207D63C(REG_BLDCNT_ADDR, 8, 0x11, 0x10, 4);
        func_021BC838(placeName);
        func_021BD0D0(placeName);
        break;
    case 3:
        func_021BC848(placeName);
        if (func_021BC910(placeName)) {
            func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_FADE_IN);
        }
        break;
    }
}

/* Fade in state: shows the plate, then waits out the blend. */
void func_021BCD34(FieldPlaceName *placeName)
{
    switch (func_021BD0C0(placeName)) {
    case 0:
        func_021BCEB4(placeName);
        func_02040588(FIELD_PLACE_NAME_BG_LAYER, 1);
        func_021BD0D0(placeName);
        break;
    case 1:
        if (placeName->frame > FIELD_PLACE_NAME_FADE_IN_FRAMES) {
            func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_FADE_IN_WAIT);
        }
        break;
    }
}

void func_021BCD70(FieldPlaceName *placeName)
{
    if (placeName->frame > FIELD_PLACE_NAME_FADE_IN_FRAMES) {
        func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH);
    }
}

/* Letters launch state: one letter every 3 frames. */
void func_021BCD84(FieldPlaceName *placeName)
{
    switch (func_021BD0C0(placeName)) {
    case 0:
        placeName->launchedCount = 0;
        func_021BD0D0(placeName);
        break;
    case 1:
        if (placeName->frame % FIELD_PLACE_NAME_LETTER_INTERVAL == 0) {
            func_021BC948(placeName);
            if (placeName->messageLength <= placeName->launchedCount) {
                func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_LETTERS_LAND);
            }
        }
        break;
    }
}

/*
 * Letters land state: waits until no letter moves, blits the letters into
 * the window one per frame, transfers the window, hides the letters and
 * holds the plate for 30 frames.
 */
void func_021BCDD8(FieldPlaceName *placeName)
{
    int allLanded = 1;
    int i;
    switch (func_021BD0C0(placeName)) {
    case 0:
        for (i = 0; i < placeName->messageLength; i++) {
            PlaceNameLetter *letter = placeName->shownLetters[i];
            if (letter != 0 && func_021BD20C(letter) != 0) {
                allLanded = 0;
                break;
            }
        }
        if (allLanded != 0) {
            func_021BC9C0(placeName);
            func_021BD0D0(placeName);
        }
        break;
    case 1:
        func_021BC9CC(placeName);
        if (func_021BCA48(placeName) != 0) {
            func_021BD0D0(placeName);
        }
        break;
    case 2:
        func_02045334(placeName->bmpWin);
        func_021BD0D0(placeName);
        break;
    case 3:
        func_021BC92C(placeName);
        func_021BD0D0(placeName);
        break;
    case 4:
        if (placeName->frame > FIELD_PLACE_NAME_HOLD_FRAMES) {
            func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_FADE_OUT);
        }
        break;
    }
}

/* Fade out state: after 20 frames the banner is gone. */
void func_021BCE88(FieldPlaceName *placeName)
{
    if (placeName->frame > FIELD_PLACE_NAME_FADE_OUT_FRAMES) {
        func_021BCB9C(placeName, FIELD_PLACE_NAME_STATE_IDLE);
        func_02040588(FIELD_PLACE_NAME_BG_LAYER, 0);
        func_021BC92C(placeName);
    }
}

/* Draw handler of the idle state: nothing to draw. */
void func_021BCEAC(FieldPlaceName *placeName)
{
}

/* Draw handler of the prepare state: nothing to draw. */
void func_021BCEB0(FieldPlaceName *placeName)
{
}

/* Draw handler of the fade in state: blend weights move from (0, 16) to (16, 4). */
void func_021BCEB4(FieldPlaceName *placeName)
{
    float progress;
    int evA;
    progress = (float)(u32)placeName->frame / 10.0f;
    evA = (int)(16.0f * progress);
    func_0207D63C(REG_BLDCNT_ADDR, 8, 0x11, evA, (int)(4.0f + 12.0f * (1.0f - progress)));
}

/* Draw handler of the fade in wait state: nothing to draw. */
void func_021BCF18(FieldPlaceName *placeName)
{
}

/* Draw handler of the letters launch state: nothing to draw. */
void func_021BCF1C(FieldPlaceName *placeName)
{
}

/* Draw handler of the letters land state: nothing to draw. */
void func_021BCF20(FieldPlaceName *placeName)
{
}

/* Draw handler of the fade out state: blend weights move back from (16, 4). */
void func_021BCF24(FieldPlaceName *placeName)
{
    float progress;
    int evA;
    progress = (float)(u32)placeName->frame / 20.0f;
    evA = (int)(16.0f * (1.0f - progress));
    func_0207D63C(REG_BLDCNT_ADDR, 8, 0x11, evA, (int)(4.0f + 12.0f * progress));
}

FieldPlaceName *func_021BCF88(u32 heapId)
{
    return func_02030734(heapId, 0x154, 1, (const char *)&d_021DE354, 0x73C);
}

void func_021BCFA4(FieldPlaceName *placeName, GameSystem *gameSystem)
{
    func_02082BCC(placeName, 0, 0x154);
    placeName->gameSystem = gameSystem;
    placeName->gameData = func_020120F4(gameSystem);
    placeName->bgCharOffset = -1;
    placeName->forceShowRequested = 0;
    placeName->zoneChangeRequested = 0;
    placeName->prevZoneId = 0x1AB;
    placeName->zoneId = 0x1AB;
}

void func_021BCFD8(FieldPlaceName *placeName)
{
    func_020307B0(placeName);
}

void func_021BCFE0(FieldPlaceName *placeName)
{
    placeName->wordSet = func_0201EC64(func_021BD090(placeName));
}

void func_021BCFF0(FieldPlaceName *placeName)
{
    placeName->msgData = func_02045B38(0, 2, 0x59, func_021BD090(placeName));
}

void func_021BD008(FieldPlaceName *placeName)
{
    placeName->message = func_020457B0(0x21, func_021BD090(placeName));
}

void func_021BD01C(FieldPlaceName *placeName)
{
    func_021BD090(placeName);
    placeName->bmpWin = func_020450F0(FIELD_PLACE_NAME_BG_LAYER, 0, 1, 0x20, 2, 0, 0);
}

void func_021BD040(FieldPlaceName *placeName)
{
    if (placeName->wordSet != 0) {
        func_0201ED04(placeName->wordSet);
        placeName->wordSet = 0;
    }
}

void func_021BD054(FieldPlaceName *placeName)
{
    MsgData *msgData = placeName->msgData;
    if (msgData != 0) {
        func_02045C04(msgData);
        placeName->msgData = 0;
    }
}

void func_021BD068(FieldPlaceName *placeName)
{
    Strbuf *message = placeName->message;
    if (message != 0) {
        func_02045808(message);
        placeName->message = 0;
    }
}

void func_021BD07C(FieldPlaceName *placeName)
{
    if (placeName->bmpWin != 0) {
        func_020452E8(placeName->bmpWin);
        placeName->bmpWin = 0;
    }
}

u16 func_021BD090(FieldPlaceName *placeName)
{
    return placeName->heapId;
}

ArcFile *func_021BD094(FieldPlaceName *placeName)
{
    return placeName->arcHandle;
}

void func_021BD098(FieldPlaceName *placeName, int heapId)
{
    placeName->heapId = heapId;
}

void func_021BD09C(FieldPlaceName *placeName, GfFont *font)
{
    placeName->font = font;
}

void func_021BD0A0(FieldPlaceName *placeName, int state)
{
    placeName->state = state;
}

u32 func_021BD0A4(FieldPlaceName *placeName)
{
    return placeName->state;
}

void func_021BD0A8(FieldPlaceName *placeName)
{
    placeName->frame = 0;
}

void func_021BD0B0(FieldPlaceName *placeName)
{
    placeName->frame++;
}

u8 func_021BD0C0(FieldPlaceName *placeName)
{
    return placeName->step;
}

void func_021BD0C8(FieldPlaceName *placeName)
{
    placeName->step = 0;
}

void func_021BD0D0(FieldPlaceName *placeName)
{
    placeName->step++;
}

/* Reads the player's current zone from the save data. */
void func_021BD0E0(FieldPlaceName *placeName)
{
    placeName->zoneId = func_02008998(func_02008854(func_02012EBC(func_020120F4(placeName->gameSystem))));
}

/* Writes the banner's current zone back to the save data. */
int func_021BD0FC(FieldPlaceName *placeName)
{
    return func_020089A0((u32)func_02008854(func_02012EBC(func_020120F4(placeName->gameSystem))), placeName->zoneId);
}

u16 func_021BD118(FieldPlaceName *placeName)
{
    return placeName->zoneId;
}

void func_021BD120(FieldPlaceName *placeName, u16 zoneId)
{
    placeName->prevZoneId = placeName->zoneId;
    placeName->zoneId = zoneId;
}

Strbuf *func_021BD134(FieldPlaceName *placeName)
{
    return placeName->message;
}

u8 func_021BD138(FieldPlaceName *placeName)
{
    return placeName->messageLength;
}

/* Whether the zone has a place name window. */
u32 func_021BD140(u32 zoneId)
{
    return func_02013E6C(zoneId);
}
