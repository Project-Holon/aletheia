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
 * blocker: wave8 structural transcription, not EXACT.  Compiled 1344 B vs the
 *          original 1564 B (220 B short), 1129 concrete bytes differ; 23 of 34
 *          relocations resolve, the rest are the five private string literals
 *          and the two static format strings (g_firstFmt/g_normalFmt, the
 *          GHI_MULTIPART_BOUNDARY_FIRST/NORMAL prefixes) plus the two static
 *          DIME names, which have no attestation yet.  The overall body is now
 *          right: prologue push {r4-r8,sb,sl,lr} + sub sp,#0x820, the
 *          state->pos == -1 gate, the simple-post / type==0 / type==3 / file
 *          branch tree, the four-byte ghiPostAppendString padding loop, the
 *          encryptor-vs-ghiTrySendThenBuffer split with the shared
 *          ghiResetBuffer tail, and the per-type tail dispatch are all laid
 *          out in the original order and use the original call set.
 *
 *          The residual is the DIME header construction (both the
 *          GHIXmlData/type==3 arm and the file arm).  The original builds the
 *          12-byte GSIDimeHeader from a local, byte-swapping mIdLength /
 *          mTypeLength / mDataLength with inline lsl/asr/and/orr sequences and
 *          four gsXmlWriterGetDataLength (func_02181E20) results packed into
 *          mDataLength, then copies the struct to buffer a byte at a time.  The
 *          transcription reproduces the shape but the exact field/source roles
 *          (which union member feeds each DIME field, and the htonl pack order)
 *          are approximate, so the arm is short.  A near-correct but unverified
 *          guess for the file arm's filelen select is in place; it is the
 *          clearest remaining 100+ byte discrepancy.  Next lane: build the
 *          header straight from the upstream ghiPostStateDoPosting DIME block
 *          and verify each of the four func_02181E20 calls' positions.
 *
 *          (Previous wave7 claim that the 4.0.0.1025 vendor stamp blocks this
 *          is withdrawn: the body is plain 1.1p1-reachable C.)
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

typedef struct GHIPostState {
    GHIPostData *data;
    int pos;
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
    char *data;
    int len;
    int size;
    int pos;
    int field10;
} GHIBuffer;

typedef struct GHIEncryptor {
    int pad0;
    int mEngine;
    int mEncryptOnBuffer;
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

static char *g_soapId;
static char *g_soapType;
static char *g_firstFmt;
static char *g_normalFmt;

static void ghiPostAppendString(char *buffer, int *len, char *str)
{
    int pad;
    int written;

    written = (int)func_021803BC(buffer + *len, str, 0x800 - *len);
    pad = 4 - (written & 3);
    *len += written;
    if (pad == 4)
        return;
    pad--;
    if (pad <= 0)
        return;
    do {
        buffer[(*len)++] = 0;
        pad--;
    } while (pad > 0);
}

static int ghiPostStateDoPosting(GHIPostState *state, GHIConnection *connection,
                                 int first, int last)
{
    char buffer[2048];
    struct GSIDimeHeader header;
    int len = 0;
    int result;

    if (state->pos == -1) {
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
                    g_firstFmt, state->data->name);
            else
                func_02084F40(buffer,
                    "%sContent-Disposition: form-data; name=\"%s\"\r\n\r\n",
                    g_normalFmt, state->data->name);
        } else if (state->data->type == 3) {
            if (connection->post->useDIME != 0) {
                header.mVersionAndFlags = 8;
                if (first)
                    header.mVersionAndFlags |= 4;
                if (last)
                    header.mVersionAndFlags |= 2;
                header.mTypeT = 0x20;
                header.mOptionsLength = 0;
                header.mIdLength = (u16)((((func_0209477C(g_soapId) & 0xff) << 8) | ((func_0209477C(g_soapId) & 0xff00) >> 8)) & 0xffff);
                header.mTypeLength = (u16)((((func_0209477C(g_soapType) & 0xff) << 8) | ((func_0209477C(g_soapType) & 0xff00) >> 8)) & 0xffff);
                header.mDataLength = (u32)(((func_02181E20(state->data->data.xml.xml) & 0xff) << 24) |
                                           ((func_02181E20(state->data->data.xml.xml) & 0xff00) << 8) |
                                           ((func_02181E20(state->data->data.xml.xml) & 0xff0000) >> 8) |
                                           ((func_02181E20(state->data->data.xml.xml) & 0xff000000) >> 24));
                buffer[0] = *(char *)&header;
                buffer[1] = *((char *)&header + 1);
                buffer[2] = *((char *)&header + 2);
                buffer[3] = *((char *)&header + 3);
                buffer[4] = *((char *)&header + 4);
                buffer[5] = *((char *)&header + 5);
                buffer[6] = *((char *)&header + 6);
                buffer[7] = *((char *)&header + 7);
                buffer[8] = *((char *)&header + 8);
                buffer[9] = *((char *)&header + 9);
                buffer[10] = *((char *)&header + 10);
                buffer[11] = *((char *)&header + 11);
                len = 0xc;
                ghiPostAppendString(buffer, &len, g_soapId);
                ghiPostAppendString(buffer, &len, g_soapType);
            } else {
                buffer[0] = 0;
            }
        } else {
            GHIPostData *data2 = state->data;
            char *filename;
            char *contentType;
            int filelen;

            if (data2->type == 1) {
                filelen = data2->data.fileDisk.contentType[0];
                filename = data2->data.fileDisk.reportFilename;
                contentType = data2->data.fileDisk.contentType;
            } else {
                filelen = data2->data.fileMemory.len;
                filename = data2->data.fileMemory.contentType;
                contentType = data2->data.fileMemory.contentType;
            }

            if (connection->post->useDIME != 0) {
                header.mVersionAndFlags = 8;
                if (first)
                    header.mVersionAndFlags |= 4;
                if (last)
                    header.mVersionAndFlags |= 2;
                header.mTypeT = 0x10;
                header.mOptionsLength = 0;
                header.mIdLength = (u16)((((func_0209477C(state->data->name) & 0xff) << 8) | ((func_0209477C(state->data->name) & 0xff00) >> 8)) & 0xffff);
                header.mTypeLength = (u16)((((func_0209477C(contentType) & 0xff) << 8) | ((func_0209477C(contentType) & 0xff00) >> 8)) & 0xffff);
                header.mDataLength = (u32)filelen;
                buffer[8] = *(char *)&header;
                buffer[9] = *((char *)&header + 1);
                buffer[10] = *((char *)&header + 2);
                buffer[11] = *((char *)&header + 3);
                buffer[12] = *((char *)&header + 4);
                buffer[13] = *((char *)&header + 5);
                buffer[14] = *((char *)&header + 6);
                buffer[15] = *((char *)&header + 7);
                buffer[16] = *((char *)&header + 8);
                buffer[17] = *((char *)&header + 9);
                buffer[18] = *((char *)&header + 10);
                buffer[19] = *((char *)&header + 11);
                len = 0xc;
                ghiPostAppendString(buffer, &len, state->data->name);
                ghiPostAppendString(buffer, &len, filename);
            } else {
                if (first)
                    func_02084F40(buffer,
                        "%sContent-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\nContent-Type: %s\r\n\r\n",
                        g_firstFmt, state->data->name, filename, contentType);
                else
                    func_02084F40(buffer,
                        "%sContent-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\nContent-Type: %s\r\n\r\n",
                        g_normalFmt, state->data->name, filename, contentType);
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
            if (connection->sendBuffer.len < connection->sendBuffer.pos)
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

    switch (state->data->type) {
    case 0:
        return func_021C2C28(state, connection);
    case 3:
        return func_021C2DB0(state, connection);
    case 1:
        return func_021C2F10(state, connection);
    default:
        return func_021C304C(state, connection);
    }
}
