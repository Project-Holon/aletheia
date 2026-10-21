#ifndef ALETHEIA_OV121_MYSTERY_ALBUM_TYPES_H
#define ALETHEIA_OV121_MYSTERY_ALBUM_TYPES_H

#include "../types.h"

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
    void *bgDataRes;
    void *paletteBuffer;
    void *paletteRes;
    void *cardView;
} MysteryAlbum;

/* Input of MYSTERY_ALBUM_CreateSlotWork, copied into the album work. */
typedef struct MysteryAlbumDesc {
    u32 w[12];
} MysteryAlbumDesc;

/* Album select create input (MYSTERY_ALBUM_Create). */
typedef struct MysteryAlbumCreateInput {u32 w[9];} MysteryAlbumCreateInput;

#endif
