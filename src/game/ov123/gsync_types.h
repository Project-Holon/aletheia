/*
 * Named object layouts for the ov123 Game Sync state code (gsync_state.c).
 * Built from the per-function offset scan of the old f<offset> views.
 */
#ifndef GSYNC_TYPES_H
#define GSYNC_TYPES_H

/*
 * Work area of the Game Sync state proc (gsync_state.c), 0xB0 bytes.
 * GFL_HEAP_CreateChildHeap/PROCSYS_AllocProcWork allocate it in GSYNC_STATE_ProcInit.
 */
typedef struct GsyncStateWork {
    u16 heapId;                 /* 0x000, heap the child work is allocated from */
    u8 pad_002[6];
    int downloadWork;           /* 0x008, GSYNC_DOWNLOAD work pointer, cast when passed */
    void *receivedMon;          /* 0x00C, box mon record built by POKE_TOOL_CreateFromBoxParam */
    void *httpConnection;       /* 0x010, NHTTP_RAP connection handle */
    void *displayWork;          /* 0x014, GsyncDispWork pointer */
    void *messageWork;          /* 0x018, GsyncMessageWork pointer */
    void *confirmMenu;          /* 0x01C, TaskMenu pointer from GSYNC_MESSAGE_OpenYesNoMenu */
    void *connection;           /* 0x020, GsyncConn pointer, network connection record */
    void *boxSave;              /* 0x024, box save handle for func_020076D0/func_02007A18 */
    void *saveControl;          /* 0x028, save control returned by GAME_DATA_GetSaveControl */
    int saveData;               /* 0x02C, save data word passed to the save API */
    void *musicalSave;          /* 0x030, MusicalDist record built by MUSICAL_DIST_SAVE_CreateFromData */
    void *receivedMonCopy;      /* 0x034, buffer copied back by GSYNC_STATE_CommitReceivedMon */
    u8 *listBuffer;             /* 0x038, received-list buffer */
    void *extraSaveBuffer;      /* 0x03C, extra save block loaded by SAVE_CONTROL_LoadExtraSaveWithBuffer */
    void *iconBuffer;           /* 0x040, extra save icon buffer allocated by func_02030734 */
    void *auxBuffer;            /* 0x044, spare allocation freed on exit */
    int boxIndex;               /* 0x048, box passed to the box save helpers */
    int slotIndex;              /* 0x04C, slot passed to the box save helpers */
    unsigned int stateHandler;  /* 0x050, address of the next GSYNC_STATE_State* handler */
    u8 pad_054[12];
    int timer;                  /* 0x060, countdown timer used by the animation states */
    int blinkTimer;             /* 0x064, %110 drives the button beep */
    int progressStep;           /* 0x068, secondary progress counter, 0..100 */
    int messageArg;             /* 0x06C, argument of GSYNC_MESSAGE_SetMonName */
    int progressPercent;        /* 0x070, progress bar percent, 0..100 */
    int waitTicks;              /* 0x074, idle counter, prints a message at 360/720/1080 */
    int bgmWait;                /* 0x078, countdown before the ending bgm is played */
    int entryId;                /* 0x07C, id of the current received-list entry */
    int errorCode;              /* 0x080, error code shown by GSYNC_STATE_StateErrorMessage */
    u8 pad_084[32];
    u8 wantExtraSave;           /* 0x0A4, extra save block requested */
    u8 wantMusicalSave;         /* 0x0A5, musical save requested */
    u8 wantRecordSave;          /* 0x0A6, trainer record save requested */
    u8 downloadKind;            /* 0x0A7, 0 extra save, 1 musical save, 2 record save */
    u8 downloadFlags;           /* 0x0A8, bit0 musical, bit1 extra, bit2 record */
    u8 hasListEntry;            /* 0x0A9, GSYNC_STATE_GetListEntry result */
    u8 monStored;               /* 0x0AA, set by GSYNC_STATE_StateStoreReceivedMon */
    u8 saveInProgress;          /* 0x0AB, set while a save is running */
    u8 responsePending;         /* 0x0AC, response flag copied from func_020092EC */
    u8 saveActive;              /* 0x0AD, save must be cancelled on input */
    u8 netDone;                 /* 0x0AE, network step finished */
    u8 responseValid;           /* 0x0AF, last response was accepted */
} GsyncStateWork;

/*
 * Network connection record of the Game Sync state proc (also the init parameter
 * and the received-list header). Every view of this object shares this layout.
 */
typedef struct GsyncConn {
    int statusWord;             /* 0x000, response status read as a word */
    void *saveData;             /* 0x004, save data handle passed to the save API */
    u8 pad_008[4];
    u16 rapState;               /* 0x00C, NHTTP RAP state */
    u8 pad_00E[0x42];
    int rapFlags;               /* 0x050, NHTTP RAP flag word */
    u16 listFlags;              /* 0x054, received-list header flags */
    u8 pad_056[0x2A];
    u16 responseCode;           /* 0x080, response code of the received buffer */
    u8 pad_082[0x146];
    int state;                  /* 0x1C8, connection state 0..7 */
    u8 pad_1CC[4];
    u16 boxIndex;               /* 0x1D0, box of the request */
    u16 slotIndex;              /* 0x1D2, slot of the request */
} GsyncConn;

/* Response record of the NHTTP receive buffer. */
typedef struct GsyncHttpResponse {
    int resultCode;             /* 0x00 */
} GsyncHttpResponse;

/* Header of the received mon in GSYNC_STATE_StateSaveStart. */
typedef struct GsyncMonHeader {
    u16 unknown_00;             /* 0x00 */
    u16 species;                /* 0x02, species argument of GSYNC_STATE_BuildMonEntry */
    u16 arg;                    /* 0x04, second species argument */
} GsyncMonHeader;

/* One 8-byte entry of the received-list buffer. */
typedef struct GsyncListEntry {
    u16 unknown_00;             /* 0x00 */
    u16 unknown_02;             /* 0x02 */
    u16 species;                /* 0x04 */
    u16 arg;                    /* 0x06 */
    u8 form;                    /* 0x08 */
    u8 gender;                  /* 0x09 */
    u8 value;                   /* 0x0A */
    u8 unknown_0B;              /* 0x0B */
} GsyncListEntry;

/* Message id table indexed by the download kind. */
typedef struct GsyncMessageIdTable {
    int ids[8];                 /* 0x00 */
} GsyncMessageIdTable;

/* RTC date record used by GF_STANDARD_SetField00_F4E4 and GF_STANDARD_SetupRtc_F540. */
typedef struct GsyncRtcDate {
    u32 year;                   /* 0x00 */
    u32 month;                  /* 0x04 */
    u32 day;                    /* 0x08 */
    u32 week;                   /* 0x0C */
} GsyncRtcDate;

#endif
