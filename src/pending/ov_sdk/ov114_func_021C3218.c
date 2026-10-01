/*
 * function: ghiPostStateDoPosting
 * address:  0x021C3218
 * packet:   pkt_ov114_021C3218
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: wave8 reconstruction from the ov114 listing (asm/overlays/ov114.s
 *          14690-15190).  Corrected the previous transcription's biggest
 *          errors: the original inlines the append+pad loop at all four
 *          sites (no ghiPostAppendString call), the private strings are
 *          literal addresses not `char *` variables, the DIME fields are
 *          built with an htons/htonl macro whose argument is used twice
 *          (two strlen calls; gsXmlWriterGetDataLength called four times),
 *          and GHIEncryptor.mEncryptOnBuffer sits at 0x1A8 with
 *          GHIBuffer.len/pos at 0x64/0x68 and GHIPostState.state.fileDisk.len
 *          at 0x0C.  Result improved 1344 -> 1416 bytes (orig 1564) and
 *          23 -> 27 of 35 relocs, but still DIFF: (1) the compiler allocates
 *          state/connection/buffer to sl/sb/r5 + fp while the original uses
 *          r8/r7/r4 and no fp, so register rotation differs from byte 8; the
 *          extra fp is register pressure from the DIME htonl call chain.
 *          (2) the 12-byte header copy should be six ldrb/strb pairs (original
 *          0x340C/0x3604); the pointer loop here unrolls differently.  (3) the
 *          eight private literals
 *          (g_soapId/g_soapType and six format/boundary strings at
 *          0x021CEE80..0x021CEF58) are still wildcarded ABS32 sites with no
 *          attestation.  This was not pushed to EXACT.
 *
 * sdk:      ghiPostStateDoPosting (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * symbols:
 *   func_0209477C                    0x0209477C arm
 *   func_02181E20                    0x02181E20 arm
 *   func_021803BC                    0x021803BC arm
 *   func_02084F40                    0x02084F40 arm
 *   func_021BFDEC                    0x021BFDEC arm  ov114
 *   func_021C011C                    0x021C011C arm  ov114
 *   func_021C07B8                    0x021C07B8 arm  ov114
 *   func_021C00FC                    0x021C00FC arm  ov114
 *   func_021C2C28                    0x021C2C28 arm  ov114
 *   func_021C2DB0                    0x021C2DB0 arm  ov114
 *   func_021C2F10                    0x021C2F10 arm  ov114
 *   func_021C304C                    0x021C304C arm  ov114
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GSIDimeHeader {
    u8 mVersionAndFlags;           /* 0x00 */
    u8 mTypeT;                     /* 0x01 */
    u16 mOptionsLength;            /* 0x02 */
    u16 mIdLength;                 /* 0x04 */
    u16 mTypeLength;               /* 0x06 */
    u32 mDataLength;               /* 0x08 */
};

extern void *memcpy(void *dst, const void *src, unsigned long n);

#define GHI_DIME_VERSION         (0x1 << 3)
#define GHI_DIMEFLAG_FIRSTRECORD (1 << 2)
#define GHI_DIMEFLAG_LASTRECORD  (1 << 1)
#define GHI_DIMETYPE_T_MEDIA     (0x1 << 4)
#define GHI_DIMETYPE_T_URI       (0x2 << 4)

#define GHI_MULTIPART_BOUNDARY        "Qr4G823s23d---<<><><<<>--7d118e0536"
#define GHI_MULTIPART_BOUNDARY_BASE   "--" GHI_MULTIPART_BOUNDARY
#define GHI_MULTIPART_BOUNDARY_FIRST  GHI_MULTIPART_BOUNDARY_BASE "\r\n"
#define GHI_MULTIPART_BOUNDARY_NORMAL "\r\n" GHI_MULTIPART_BOUNDARY_BASE "\r\n"

#define GHI_DIME_SOAPID   "cid:id0"
#define GHI_DIME_SOAPTYPE "http://schemas.xmlsoap.org/soap/envelope/"

#define htons(x) ((u16)((((x) & 0xff) << 8) | (((x) >> 8) & 0xff)))
#define htonl(x) ((u32)((((x) & 0xff) << 24) | (((x) & 0xff00) << 8) | \
                        (((x) & 0xff0000) >> 8) | (((x) >> 24) & 0xff)))

typedef struct GHIPostStringData {
    char *string;
    int len;
    int invalidChars;
    int extendedChars;
} GHIPostStringData;

typedef struct GHIPostFileDiskData {
    char *filename;
    char *reportFilename;
    char *contentType;
} GHIPostFileDiskData;

typedef struct GHIPostFileMemoryData {
    const char *buffer;
    int len;
    char *reportFilename;
    char *contentType;
} GHIPostFileMemoryData;

typedef struct GHIPostXmlData {
    void *xml;
} GHIPostXmlData;

typedef struct GHIPostData {
    int type;
    char *name;
    union {
        GHIPostStringData string;
        GHIPostFileDiskData fileDisk;
        GHIPostFileMemoryData fileMemory;
        GHIPostXmlData xml;
    } data;
} GHIPostData;

typedef struct GHIPostFileDiskState {
    void *file;
    long len;
} GHIPostFileDiskState;

typedef struct GHIPostState {
    GHIPostData *data;
    int pos;
    union {
        GHIPostFileDiskState fileDisk;
    } state;
} GHIPostState;

typedef struct GHIPost {
    void *data;                    /* 0x00 */
    void *callback;                /* 0x04 */
    void *param;                   /* 0x08 */
    int hasFiles;                  /* 0x0C */
    int hasSoap;                   /* 0x10 */
    int useDIME;                   /* 0x14 */
} GHIPost;

typedef struct GHIBuffer {
    char *data;                    /* 0x58 */
    int field0;                    /* 0x5C */
    int field1;                    /* 0x60 */
    int len;                       /* 0x64 */
    int pos;                       /* 0x68 */
} GHIBuffer;

typedef struct GHIEncryptor {
    int pad0;                      /* 0x194 */
    int mEngine;                   /* 0x198 */
    int pad1;                      /* 0x19C */
    int pad2;                      /* 0x1A0 */
    int pad3;                      /* 0x1A4 */
    int mEncryptOnBuffer;          /* 0x1A8 */
} GHIEncryptor;

typedef struct GHIConnection {
    u8 pad0[0x58];
    GHIBuffer sendBuffer;          /* 0x58 */
    u8 pad1[0x164 - 0x6C];
    GHIPost *post;                 /* 0x164 */
    u8 pad2[0x194 - 0x168];
    GHIEncryptor encryptor;        /* 0x194 */
} GHIConnection;

extern int func_0209477C(char *s);
extern int func_02181E20(void *stream);
extern unsigned long func_021803BC(char *dst, char *src, unsigned long size);
extern void func_02084F40(char *dst, char *fmt, ...);
extern int func_021BFDEC(GHIBuffer *buffer, char *data, int dataLen);
extern int func_021C011C(GHIConnection *connection);
extern int func_021C07B8(GHIConnection *connection, char *buffer, int len);
extern void func_021C00FC(GHIBuffer *buffer);
extern int func_021C2C28(GHIPostState *state, GHIConnection *connection);
extern int func_021C2DB0(GHIPostState *state, GHIConnection *connection);
extern int func_021C2F10(GHIPostState *state, GHIConnection *connection);
extern int func_021C304C(GHIPostState *state, GHIConnection *connection);

#define APPEND_STRING(str)                                              \
    do {                                                                \
        int written_ = (int)func_021803BC(buffer + len, (str),          \
                                          0x800 - len);                 \
        int pad_ = 4 - (written_ & 3);                                  \
        len += written_;                                                \
        if (pad_ != 4) {                                                \
            pad_--;                                                     \
            if (pad_ > 0) {                                             \
                do {                                                    \
                    buffer[len++] = 0;                                  \
                    pad_--;                                             \
                } while (pad_ > 0);                                     \
            }                                                           \
        }                                                               \
    } while (0)

static int ghiPostStateDoPosting(GHIPostState *state, GHIConnection *connection,
                                 int first, int last)
{
    int len = 0;
    int result;

    if (state->pos == -1) {
        char buffer[2048];
        state->pos = 0;

        if (connection->post->hasFiles == 0 && connection->post->hasSoap == 0) {
            if (first)
                func_02084F40(buffer, "%s=", state->data->name);
            else
                func_02084F40(buffer, "&%s=", state->data->name);
        } else if (state->data->type == 0) {
            if (first)
                func_02084F40(buffer,
                    "%sContent-Disposition: form-data; name=\"%s\"\r\n\r\n",
                    GHI_MULTIPART_BOUNDARY_FIRST, state->data->name);
            else
                func_02084F40(buffer,
                    "%sContent-Disposition: form-data; name=\"%s\"\r\n\r\n",
                    GHI_MULTIPART_BOUNDARY_NORMAL, state->data->name);
        } else if (state->data->type == 3) {
            if (connection->post->useDIME != 0) {
                int writePos = 0;
                int i;
                struct GSIDimeHeader header;

                header.mVersionAndFlags = GHI_DIME_VERSION;
                if (first)
                    header.mVersionAndFlags |= GHI_DIMEFLAG_FIRSTRECORD;
                if (last)
                    header.mVersionAndFlags |= GHI_DIMEFLAG_LASTRECORD;
                header.mTypeT = GHI_DIMETYPE_T_URI;
                header.mOptionsLength = 0;
                header.mIdLength = htons((short)func_0209477C(GHI_DIME_SOAPID));
                header.mTypeLength = htons((short)func_0209477C(GHI_DIME_SOAPTYPE));
                header.mDataLength = htonl(func_02181E20(state->data->data.xml.xml));

                {
                    char *src_ = (char *)&header;
                    char *dst_ = buffer + writePos;
                    for (i = 0; i < (int)sizeof(header); i++)
                        *dst_++ = *src_++;
                }
                writePos += sizeof(header);

                len = writePos;
                APPEND_STRING(GHI_DIME_SOAPID);
                APPEND_STRING(GHI_DIME_SOAPTYPE);
            } else {
                buffer[0] = 0;
            }
        } else {
            char *filename;
            char *contentType;
            int filelen;

            if (state->data->type == 1) {
                filelen = state->state.fileDisk.len;
                filename = state->data->data.fileDisk.reportFilename;
                contentType = state->data->data.fileDisk.contentType;
            } else {
                filelen = state->data->data.fileMemory.len;
                filename = state->data->data.fileMemory.reportFilename;
                contentType = state->data->data.fileMemory.contentType;
            }

            if (connection->post->useDIME != 0) {
                int writePos = 0;
                int i;
                struct GSIDimeHeader header;

                header.mVersionAndFlags = GHI_DIME_VERSION;
                if (first)
                    header.mVersionAndFlags |= GHI_DIMEFLAG_FIRSTRECORD;
                if (last)
                    header.mVersionAndFlags |= GHI_DIMEFLAG_LASTRECORD;
                header.mTypeT = GHI_DIMETYPE_T_MEDIA;
                header.mOptionsLength = 0;
                header.mIdLength = htons((short)func_0209477C(state->data->name));
                header.mTypeLength = htons((short)func_0209477C(contentType));
                header.mDataLength = htonl(filelen);

                {
                    char *src_ = (char *)&header;
                    char *dst_ = buffer + writePos;
                    for (i = 0; i < (int)sizeof(header); i++)
                        *dst_++ = *src_++;
                }
                writePos += sizeof(header);

                len = writePos;
                APPEND_STRING(state->data->name);
                APPEND_STRING(contentType);
            } else {
                if (first)
                    func_02084F40(buffer,
                        "%sContent-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\nContent-Type: %s\r\n\r\n",
                        GHI_MULTIPART_BOUNDARY_FIRST, state->data->name,
                        filename, contentType);
                else
                    func_02084F40(buffer,
                        "%sContent-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\nContent-Type: %s\r\n\r\n",
                        GHI_MULTIPART_BOUNDARY_NORMAL, state->data->name,
                        filename, contentType);
            }
        }

        if (connection->encryptor.mEngine != 0 &&
            connection->encryptor.mEncryptOnBuffer == 1) {
            if (len == 0)
                len = func_0209477C(buffer);
            result = func_021BFDEC(&connection->sendBuffer, buffer, len);
            if (result == 0)
                return 0;
            if (func_021C011C(connection) == 0)
                return 0;
            if (connection->sendBuffer.pos < connection->sendBuffer.len)
                return 2;
        } else {
            if (len == 0)
                len = func_0209477C(buffer);
            result = func_021C07B8(connection, buffer, len);
            if (result == 0)
                return 0;
            if (result == 2)
                return 2;
        }
        func_021C00FC(&connection->sendBuffer);
    }

    if (state->data->type == 0)
        return func_021C2C28(state, connection);
    if (state->data->type == 3)
        return func_021C2DB0(state, connection);
    if (state->data->type == 1)
        return func_021C2F10(state, connection);
    return func_021C304C(state, connection);
}
