#ifndef ALETHEIA_OV121_MYSTERY_ALBUM_TYPES_H
#define ALETHEIA_OV121_MYSTERY_ALBUM_TYPES_H

#include "../types.h"
#include "../arm9/nns_g2d_res_types.h"

/* Mystery Gift album screen work (types shared with mystery_util.c, which allocates it). */

typedef struct MysteryAlbumPathPoint {
    int x, y;
} MysteryAlbumPathPoint;

/* Cursor path animation: walks a sprite through a table of waypoints (44 bytes). */
typedef struct MysteryAlbumPathAnim {
    unsigned short frameId;
    unsigned short prevFrameId;
    unsigned short nextFrameId;
    signed char direction;
    unsigned char phase;
    unsigned short waypointIndex;
    unsigned short waypointCount;
    unsigned int frame;
    unsigned int durationFrames;
    int startX, startY;
    MysteryAlbumPathPoint target, current;
} MysteryAlbumPathAnim;

/* Which layers and palette slot one album background uses. */
typedef struct MysteryAlbumBgSetup {
    unsigned int bgLayer;
    unsigned int overlayLayer;
    unsigned int paletteNumber;
} MysteryAlbumBgSetup;

/* Screen resources held by the album (at least 0xB4 bytes). */
typedef struct MysteryAlbumUi {
    void *albumData;
    unsigned char pad04[4];
    int bgHandleA;
    unsigned char pad0C[4];
    unsigned int paletteHandle;
    int bgHandleB;
    unsigned char pad18[4];
    void *iconActor;
    void *cursorActor;
    unsigned short palFade[16];
    unsigned short palBlack[16];
    unsigned short palImage[16];
    int isMainScreen;
    unsigned int paletteBank;
    unsigned int idleAnimId;
    unsigned int introAnimId;
    unsigned short frontPlane;
    unsigned short backPlane;
    unsigned int screenId;
    unsigned char pad9C[4];
    MysteryAlbumBgSetup bgSetup;
    unsigned char padAC[4];
    unsigned int iconPaletteNumber;
} MysteryAlbumUi;

typedef struct MysteryAlbum {
    unsigned char padStart[0xDC];
    unsigned short introPhase;
    unsigned short introTick;
    int skipSound;
    unsigned short soundId;
    unsigned short soundPlayerId;
    unsigned int soundHandle;
    MysteryAlbumPathAnim pathAnim;
    unsigned short heapId;
    unsigned char pad11A[2];
    MysteryAlbumUi *ui;
    unsigned char pad120[8];
    void *setupTask;
    int isSetupDone;
    int setupMode;
    void *bgDataBuffer;
    NNSG2dCharacterData *bgDataRes;
    void *paletteBuffer;
    NNSG2dPaletteData *paletteRes;
    void *cardView;
} MysteryAlbum;

struct MysteryData;
struct MsgBank;
struct GfFont;
struct PrintQueue;
struct WordSet;
struct GameData;

/* Input of MYSTERY_ALBUM_CreateSlotWork, copied into the slot work (48 bytes on the DS). */
typedef struct MysteryAlbumDesc {
    unsigned int frontPlane;       /* 0x00 */
    unsigned int backPlane;        /* 0x04 */
    unsigned int reserved08;       /* 0x08 written by the callers, read by nobody */
    unsigned int windowPalette;    /* 0x0C palette of the window list */
    unsigned int charPalette;      /* 0x10 CLACT palette slot, shifted left by 5 */
    unsigned int paletteBank;      /* 0x14 */
    void *clactUnit;               /* 0x18 */
    struct MysteryData *cardList;  /* 0x1C */
    struct MsgBank *msgBank;       /* 0x20 */
    struct GfFont *font;           /* 0x24 */
    struct PrintQueue *printQueue; /* 0x28 */
    struct WordSet *wordSet;       /* 0x2C */
} MysteryAlbumDesc;

/* Album select create input (MYSTERY_ALBUM_Create), copied to the head of the album work. */
typedef struct MysteryAlbumCreateInput {
    unsigned int mode;             /* 0x00 nonzero: single-card handler */
    unsigned int reserved04;       /* 0x04 */
    void *clactUnit;               /* 0x08 */
    struct MysteryData *cardList;  /* 0x0C */
    struct GfFont *font;           /* 0x10 */
    struct PrintQueue *printQueue; /* 0x14 */
    struct WordSet *wordSet;       /* 0x18 */
    struct MsgBank *msgBank;       /* 0x1C */
    struct GameData *gameData;     /* 0x20 */
} MysteryAlbumCreateInput;

#endif
