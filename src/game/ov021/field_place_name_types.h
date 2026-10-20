#ifndef ALETHEIA_OV021_FIELD_PLACE_NAME_TYPES_H
#define ALETHEIA_OV021_FIELD_PLACE_NAME_TYPES_H

/*
 * Place name banner shown when the player enters a new area (field_place_name.c)
 * and the flying letters it is built from (place_name_letter.c).
 */

struct GameSystem;
struct GameData;
struct WordSet;
struct ArcFile;
struct MsgBank;
struct GfFont;
struct Strbuf;
struct BmpWin;
struct Bmp;
struct BmpOamSys;
struct BmpOam;
struct Unit;
struct ClactRenderer;
struct NitroFileHeader;
struct PlaceNameLetter;

/* Palette block unpacked from the NCLR file; colors is the raw palette data. */
typedef struct PlaceNamePaletteBlock {
    unsigned int header[3];             /* 0x00 */
    void *colors;                       /* 0x0C */
} PlaceNamePaletteBlock;

/* Display states of the banner (FieldPlaceName.state). */
enum {
    FIELD_PLACE_NAME_STATE_IDLE,            /* hidden, waits for a request */
    FIELD_PLACE_NAME_STATE_PREPARE,         /* builds the message and the letters */
    FIELD_PLACE_NAME_STATE_FADE_IN,         /* plate blends in over 10 frames */
    FIELD_PLACE_NAME_STATE_FADE_IN_WAIT,    /* plate shown, 10 frames */
    FIELD_PLACE_NAME_STATE_LETTERS_LAUNCH,  /* one letter starts flying every 3 frames */
    FIELD_PLACE_NAME_STATE_LETTERS_LAND,    /* letters land, get blitted into the window, hold */
    FIELD_PLACE_NAME_STATE_FADE_OUT         /* plate blends out over 20 frames */
};

#define FIELD_PLACE_NAME_MAX_LETTERS 30
#define FIELD_PLACE_NAME_NO_CHAR_OFFSET (-1)

/* The banner work (0x154 bytes). Created by FIELDMAP, stored at FieldMap+0x30. */
typedef struct FieldPlaceName {
    struct GameSystem *gameSystem;                                  /* 0x00 */
    struct GameData *gameData;                                      /* 0x04 */
    struct WordSet *wordSet;                                        /* 0x08 */
    unsigned short heapId;                                          /* 0x0C */
    struct ArcFile *arcHandle;                                      /* 0x10 */
    struct MsgBank *msgData;                                        /* 0x14: arc 2, file 0x59 */
    struct GfFont *font;                                            /* 0x18 */
    struct Strbuf *message;                                         /* 0x1C */
    unsigned char messageLength;                                    /* 0x20 */
    struct BmpWin *bmpWin;                                          /* 0x24 */
    int bgCharOffset;                                               /* 0x28: BG3 char area, -1 if none */
    int clactPaletteId;                                             /* 0x2C */
    struct BmpOamSys *bmpOamSys;                                    /* 0x30 */
    struct Unit *clactUnit[1];                                 /* 0x34 */
    struct ClactRenderer *clactRenderer;                            /* 0x38 */
    int state;                                                      /* 0x3C */
    unsigned char step;                                             /* 0x40: step inside the state */
    unsigned short frame;                                           /* 0x42: frames since the last state change */
    unsigned short prevZoneId;                                      /* 0x44 */
    unsigned short zoneId;                                          /* 0x46 */
    unsigned int zoneChangeRequested;                               /* 0x48 */
    unsigned int forceShowRequested;                                /* 0x4C */
    struct PlaceNameLetter *letters[FIELD_PLACE_NAME_MAX_LETTERS];  /* 0x50: letter pool */
    struct PlaceNameLetter *shownLetters[32];                       /* 0xC8: letter per message character */
    unsigned char spawnedCount;                                     /* 0x148 */
    unsigned char launchedCount;                                    /* 0x149 */
    unsigned char blittedCount;                                     /* 0x14A */
    unsigned char skippedSpaceCount;                                /* 0x14B */
    struct NitroFileHeader *paletteFile;                            /* 0x14C */
    PlaceNamePaletteBlock *paletteBlock;                            /* 0x150 */
} FieldPlaceName;

/* Start values of one letter; also the layout of the default table gPlaceNameLetterDefaultParam. */
typedef struct PlaceNameLetterParam {
    float x;                            /* 0x00 */
    float y;                            /* 0x04 */
    float vx;                           /* 0x08 */
    float vy;                           /* 0x0C */
    float targetX;                      /* 0x10 */
    float targetY;                      /* 0x14 */
    float targetVx;                     /* 0x18 */
    float targetVy;                     /* 0x1C */
    struct GfFont *font;                /* 0x20 */
    unsigned short ch;                  /* 0x24 */
    unsigned short pad;                 /* 0x26 */
} PlaceNameLetterParam;

/*
 * Constant acceleration per axis: the letter starts at (x, y) with speed
 * (vx, vy) and reaches (targetX, targetY) with speed (targetVx, targetVy).
 */
typedef struct PlaceNameLetterMotion {
    float x;                            /* 0x00 */
    float y;                            /* 0x04 */
    float vx;                           /* 0x08 */
    float vy;                           /* 0x0C */
    float ax;                           /* 0x10 */
    float ay;                           /* 0x14 */
    float targetX;                      /* 0x18 */
    float targetY;                      /* 0x1C */
    float targetVx;                     /* 0x20 */
    float targetVy;                     /* 0x24 */
    int framesX;                        /* 0x28: frames left on the x axis */
    int framesY;                        /* 0x2C */
} PlaceNameLetterMotion;

/* One flying letter (0x4C bytes): a 2x2 tile bitmap shown through a BmpOam. */
typedef struct PlaceNameLetter {
    unsigned short heapId;              /* 0x00 */
    struct GfFont *font;                /* 0x04 */
    struct Bmp *bmp;                    /* 0x08 */
    struct BmpOam *bmpOam;              /* 0x0C */
    PlaceNameLetterMotion motion;       /* 0x10 */
    unsigned char width;                /* 0x40: glyph width in pixels */
    unsigned char height;               /* 0x41 */
    unsigned int active;                /* 0x44: 1 while it moves */
    unsigned short ch;                  /* 0x48 */
} PlaceNameLetter;

#endif
