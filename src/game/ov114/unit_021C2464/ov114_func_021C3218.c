/*
 * function: ghiPostStateDoPosting
 * address:  0x021C3218
 * packet:   pkt_ov114_021C3218
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostStateDoPosting (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * 2026-10-01: full rewrite from the vendor listing and DWARF closed it.
 * strlen and memcpy come from the house string.h (strlen writes no memory,
 * so state->data->name stays cached; memcpy of the 12-byte header expands
 * inline to the six ldrb/strb pairs).  The DWARF locals (writePos, padBytes,
 * writen, header per DIME block; filename/contentType/filelen) replace the
 * old stand-ins; the boundary choice is a ternary feeding one OS_SPrintf;
 * htons/htonl are the SOC byte-swap macros with the argument evaluated per
 * use; the pad loop is while (padBytes-- > 0); ghiResetBuffer is called
 * at the end of each send branch (tail-merged), which gives the
 * conditional return 2 in the encrypt branch.
 *
 * symbols:
 *   strlen                           0x0209477C arm
 *   func_02181E20                    0x02181E20 arm  ov009
 *   func_021803BC                    0x021803BC arm  ov009
 *   OS_SPrintf                       0x02084F40 arm
 *   func_021BFDEC                    0x021BFDEC arm  ov114
 *   func_021C011C                    0x021C011C arm  ov114
 *   func_021C07B8                    0x021C07B8 arm  ov114
 *   func_021C00FC                    0x021C00FC arm  ov114
 *   func_021C2C28                    0x021C2C28 arm  ov114
 *   func_021C2DB0                    0x021C2DB0 arm  ov114
 *   func_021C2F10                    0x021C2F10 arm  ov114
 *   func_021C304C                    0x021C304C arm  ov114
 *   g_021CEEC8                       0x021CEEC8 data
 *   g_021CEECC                       0x021CEECC data
 *   g_021CEED4                       0x021CEED4 data
 *   g_021CEEFC                       0x021CEEFC data
 *   g_021CEF28                       0x021CEF28 data
 *   g_021CEE80                       0x021CEE80 data
 *   g_021CEE88                       0x021CEE88 data
 *   g_021CEF58                       0x021CEF58 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#include "../../../matched/arm9_sdk/libc/string.h"

typedef enum { GHTTPFalse, GHTTPTrue } GHTTPBool;
typedef enum { GHIPostingError, GHIPostingDone, GHIPostingWaitForContinue } GHIPostingResult;
typedef enum { GHITrySendError, GHITrySendSent, GHITrySendBuffered } GHITrySendResult;

typedef struct GSIDimeHeader {
    u8 mVersionAndFlags;
    u8 mTypeT;
    u16 mOptionsLength;
    u16 mIdLength;
    u16 mTypeLength;
    u32 mDataLength;
} GSIDimeHeader;

#define GHI_DIME_VERSION         (0x1 << 3)
#define GHI_DIMEFLAG_FIRSTRECORD (1 << 2)
#define GHI_DIMEFLAG_LASTRECORD  (1 << 1)
#define GHI_DIMETYPE_T_MEDIA     (0x1 << 4)
#define GHI_DIMETYPE_T_URI       (0x2 << 4)

#define htons(s) ((u16)((((u16)(s) >> 8) & 0x00ff) | (((u16)(s) << 8) & 0xff00)))
#define htonl(l) ((u32)((((u32)(l) >> 24) & 0x000000ff) | (((u32)(l) >> 8) & 0x0000ff00) | \
                        (((u32)(l) << 8) & 0x00ff0000) | (((u32)(l) << 24) & 0xff000000)))

typedef struct GHIPostData {
    int type;
    char *name;
    union {
        struct { char *string; int len; } string;
        struct { char *filename; char *reportFilename; char *contentType; } fileDisk;
        struct { const char *buffer; int len; char *reportFilename; char *contentType; } fileMemory;
        struct { void *xml; } xml;
    } data;
} GHIPostData;

typedef struct GHIPostState {
    GHIPostData *data;
    int pos;
    union {
        struct { void *file; long len; } fileDisk;
    } state;
} GHIPostState;

typedef struct GHIPost {
    void *data;
    void *callback;
    void *param;
    GHTTPBool hasFiles;
    GHTTPBool hasSoap;
    GHTTPBool useDIME;
} GHIPost;

typedef struct GHIBuffer {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
} GHIBuffer;

typedef struct GHIEncryptor {
    int mInitialized;
    int mEngine;
    int pad[3];
    GHTTPBool mEncryptOnBuffer;
} GHIEncryptor;

typedef struct GHIConnection {
    u8 pad0[0x58];
    GHIBuffer sendBuffer;          /* 0x58 */
    u8 pad1[0x164 - 0x6C];
    GHIPost *post;                 /* 0x164 */
    u8 pad2[0x194 - 0x168];
    GHIEncryptor encryptor;        /* 0x194 */
} GHIConnection;

extern int func_02181E20(void *stream);
extern unsigned long func_021803BC(char *dst, char *src, unsigned long size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern GHTTPBool func_021BFDEC(GHIBuffer *buffer, char *data, int dataLen);
extern GHTTPBool func_021C011C(GHIConnection *connection);
extern GHITrySendResult func_021C07B8(GHIConnection *connection, char *buffer, int len);
extern void func_021C00FC(GHIBuffer *buffer);
extern GHIPostingResult func_021C2C28(GHIPostState *state, GHIConnection *connection);
extern GHIPostingResult func_021C2DB0(GHIPostState *state, GHIConnection *connection);
extern GHIPostingResult func_021C2F10(GHIPostState *state, GHIConnection *connection);
extern GHIPostingResult func_021C304C(GHIPostState *state, GHIConnection *connection);

extern char g_021CEEC8[];
extern char g_021CEECC[];
extern char g_021CEED4[];
extern char g_021CEEFC[];
extern char g_021CEF28[];
extern char g_021CEE80[];
extern char g_021CEE88[];
extern char g_021CEF58[];

static GHIPostingResult ghiPostStateDoPosting(GHIPostState *state, GHIConnection *connection,
                                       GHTTPBool first, GHTTPBool last)
{
    int len = 0;
    GHITrySendResult result;

    if (state->pos == -1)
    {
        char buffer[2048];

        state->pos = 0;

        if (!connection->post->hasFiles && !connection->post->hasSoap)
        {
            if (first)
                OS_SPrintf(buffer, g_021CEEC8, state->data->name);
            else
                OS_SPrintf(buffer, g_021CEECC, state->data->name);
        }
        else
        {
            if (state->data->type == 0)
            {
                OS_SPrintf(buffer, g_021CEF28,
                           first ? g_021CEED4 : g_021CEEFC,
                           state->data->name);
            }
            else if (state->data->type == 3)
            {
                if (connection->post->useDIME)
                {
                    int writePos = 0;
                    int padBytes;
                    unsigned long writen;
                    GSIDimeHeader header;

                    header.mVersionAndFlags = GHI_DIME_VERSION;
                    if (first)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_FIRSTRECORD;
                    if (last)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_LASTRECORD;
                    header.mTypeT = GHI_DIMETYPE_T_URI;
                    header.mOptionsLength = 0;
                    header.mIdLength = htons((short)strlen(g_021CEE80));
                    header.mTypeLength = htons((short)strlen(g_021CEE88));
                    header.mDataLength = htonl(func_02181E20(state->data->data.xml.xml));
                    memcpy(&buffer[writePos], &header, sizeof(GSIDimeHeader));
                    writePos += sizeof(GSIDimeHeader);

                    writen = func_021803BC(&buffer[writePos], g_021CEE80, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    writen = func_021803BC(&buffer[writePos], g_021CEE88, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    len = writePos;
                }
                else
                {
                    buffer[0] = '\0';
                }
            }
            else if (state->data->type == 1 || state->data->type == 2)
            {
                char *filename;
                char *contentType;
                int filelen;

                if (state->data->type == 1)
                {
                    filelen = (int)state->state.fileDisk.len;
                    filename = state->data->data.fileDisk.reportFilename;
                    contentType = state->data->data.fileDisk.contentType;
                }
                else
                {
                    filelen = state->data->data.fileMemory.len;
                    filename = state->data->data.fileMemory.reportFilename;
                    contentType = state->data->data.fileMemory.contentType;
                }

                if (connection->post->useDIME)
                {
                    int writePos = 0;
                    int padBytes;
                    unsigned long writen;
                    GSIDimeHeader header;

                    header.mVersionAndFlags = GHI_DIME_VERSION;
                    if (first)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_FIRSTRECORD;
                    if (last)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_LASTRECORD;
                    header.mTypeT = GHI_DIMETYPE_T_MEDIA;
                    header.mOptionsLength = 0;
                    header.mIdLength = htons((short)strlen(state->data->name));
                    header.mTypeLength = htons((short)strlen(contentType));
                    header.mDataLength = htonl(filelen);
                    memcpy(&buffer[writePos], &header, sizeof(GSIDimeHeader));
                    writePos += sizeof(GSIDimeHeader);

                    writen = func_021803BC(&buffer[writePos], state->data->name, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    writen = func_021803BC(&buffer[writePos], contentType, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    len = writePos;
                }
                else
                {
                    OS_SPrintf(buffer, g_021CEF58,
                               first ? g_021CEED4 : g_021CEEFC,
                               state->data->name, filename, contentType);
                }
            }
        }

        if (connection->encryptor.mEngine != 0 &&
            connection->encryptor.mEncryptOnBuffer == GHTTPTrue)
        {
            if (len == 0)
                len = (int)strlen(buffer);
            if (!func_021BFDEC(&connection->sendBuffer, buffer, len))
                return GHIPostingError;
            if (!func_021C011C(connection))
                return GHIPostingError;
            if (connection->sendBuffer.pos < connection->sendBuffer.len)
                return GHIPostingWaitForContinue;
            func_021C00FC(&connection->sendBuffer);
        }
        else
        {
            if (len == 0)
                len = (int)strlen(buffer);
            result = func_021C07B8(connection, buffer, len);
            if (result == GHITrySendError)
                return GHIPostingError;
            if (result == GHITrySendBuffered)
                return GHIPostingWaitForContinue;
            func_021C00FC(&connection->sendBuffer);
        }
    }

    if (state->data->type == 0)
        return func_021C2C28(state, connection);
    if (state->data->type == 3)
        return func_021C2DB0(state, connection);
    if (state->data->type == 1)
        return func_021C2F10(state, connection);
    return func_021C304C(state, connection);
}
