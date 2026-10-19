#ifndef OV114_NHTTP_RAP_TYPES_H
#define OV114_NHTTP_RAP_TYPES_H
/*
 * Types of the game-side HTTP wrapper in nhttp_rap.c. One definition per
 * type; every part that uses one of these includes this header.
 */

#include "../types.h"

/* Wrapper session (size 0x5a8): one HTTP connection, its receive buffer,
 * the URL text and the post data buffer. */
typedef struct _NHTTPRapSession {
    char *postBuf_p;                    /* 0x00 */
    int postLen;                        /* 0x04: post data length or write cursor */
    char *source_p;                     /* 0x08: profile data, the name string is at +0x45 */
    struct _NHTTPConnection *connection_p; /* 0x0c: NHTTP connection handle, 0 when none */
    char recvBuf[0x400];                /* 0x10 */
    char url[0x190];                    /* 0x410 */
    u8 pad_5a0[4];
    u32 gameCode;                       /* 0x5a4: first argument of the URL format */
} NHTTPRapSession;

/* One row of the request table at sNHTTPRapRequestTable. */
typedef struct _NHTTPRapRequestEntry {
    const char *urlFormat;              /* 0x00 */
    u32 method;                         /* 0x04 */
} NHTTPRapRequestEntry;

/* One 4 byte big endian record. */
typedef struct _NHTTPRapRecord {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} NHTTPRapRecord;

/* Record list: a count byte, then the records directly after it. */
typedef struct _NHTTPRapRecordList {
    u8 count;                           /* 0x00 */
    NHTTPRapRecord records[1];          /* 0x01 */
} NHTTPRapRecordList;

/* Trainer info block sent to the server (size 0x64). */
typedef struct _NHTTPRapTrainerInfo {
    u8 packetType;                      /* 0x00: 0x15 */
    u8 version;                         /* 0x01: 2 */
    u8 language;                        /* 0x02 */
    u8 romVersion;                      /* 0x03 */
    u32 trainerId;                      /* 0x04 */
    u16 name[8];                        /* 0x08 */
    u32 reserved18;                     /* 0x18 */
    u8 pad_1c[8];
    u8 reserved24;                      /* 0x24 */
    u8 pad_25[0x37];
    u32 reserved5c;                     /* 0x5c */
    u8 pad_60[4];
} NHTTPRapTrainerInfo;

#endif
