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
 * blocker: partial rewrite.  The state->pos == -1 gate, the data->type branch
 *          (0 / 3 / else), the four-byte-aligned gsiSafeStrcpyA append, the
 *          encryptor-vs-ghiTrySendThenBuffer send split and the final
 *          per-post-type dispatch are all transcribed from the listing.  The
 *          exact GHIPostData field roles and the multipart header byte values
 *          are approximate; this body does not reproduce the vendor bytes.
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
 *   g_021CEE80                       0x021CEE80 data
 *   g_021CEE88                       0x021CEE88 data
 *   g_021CEEC8                       0x021CEEC8 data
 *   g_021CEECC                       0x021CEECC data
 *   g_021CEED4                       0x021CEED4 data
 *   g_021CEEFC                       0x021CEEFC data
 *   g_021CEF28                       0x021CEF28 data
 *   g_021CEF58                       0x021CEF58 data
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

struct GHIPostData {
    u32 type;                      /* 0x00 */
    u32 field4;                    /* 0x04 */
    void *field8;                  /* 0x08 */
    char *fieldC;                  /* 0x0C */
    char *field10;                 /* 0x10 */
    char *field14;                 /* 0x14 */
};

struct GHIBuffer {
    void *data;                    /* 0x00 */
    int len;                       /* 0x04 */
    int size;                      /* 0x08 */
    int fieldC;                    /* 0x0C */
    int field10;                   /* 0x10 */
};

struct GHIEncryptor {
    u8 pad0[4];
    int field4;                    /* 0x04 */
    int field8;                    /* 0x08 */
    u8 padC[0x14];
};

struct GHIConnection {
    u8 pad0[0x58];
    struct GHIBuffer sendBuffer;   /* 0x58 */
    u8 pad1[0x164 - 0x7C];
    struct GHIPostData *post;      /* 0x164 */
    u8 pad2[0x194 - 0x168];
    struct GHIEncryptor encryptor; /* 0x194 */
};

struct GHIPostState {
    struct GHIPostData *data;      /* 0x00 */
    int pos;                       /* 0x04 */
    u8 state[8];                   /* 0x08 */
};

extern int func_0209477C(const char *s);
extern int func_02181E20(void *stream);
extern unsigned long func_021803BC(char *dst, char *src, unsigned long size);
extern int func_02084F40(char *dst, char *fmt, ...);
extern int func_021BFDEC(struct GHIBuffer *buffer, char *data, int dataLen);
extern int func_021C011C(struct GHIConnection *connection);
extern int func_021C07B8(struct GHIConnection *connection, char *buffer, int len);
extern void func_021C00FC(struct GHIBuffer *buffer);
extern int func_021C2C28(struct GHIPostState *state, struct GHIConnection *connection);
extern int func_021C2DB0(struct GHIPostState *state, struct GHIConnection *connection);
extern int func_021C2F10(struct GHIPostState *state, struct GHIConnection *connection);
extern int func_021C304C(struct GHIPostState *state, struct GHIConnection *connection);

extern char g_021CEE80[];
extern char g_021CEE88[];
extern char g_021CEEC8[];
extern char g_021CEECC[];
extern char g_021CEED4[];
extern char g_021CEEFC[];
extern char g_021CEF28[];
extern char g_021CEF58[];

/* Append `str` at buffer[writePos], NUL included, padded to a four-byte
 * boundary; *writePos is advanced past the padding. */
static void ghiPostAppendString(char *buffer, int *writePos, char *str)
{
    int written;
    int pad;

    written = func_021803BC(buffer + *writePos, str, 0x800 - *writePos);
    pad = 4 - (written & 3);
    *writePos += written;
    if (pad == 4)
        return;
    for (pad--; pad > 0; pad--)
        buffer[(*writePos)++] = 0;
}

static int ghiPostStateDoPosting(struct GHIPostState *state,
                                 struct GHIConnection *connection,
                                 int first, int last)
{
    char buffer[2048];
    struct GSIDimeHeader header;
    struct GHIPostData *data;
    int writePos;
    int result;
    u32 *src;
    u32 *dst;
    int i;

    if (state->pos == -1) {
        state->pos = 0;
        data = state->data;
        if (connection->post->fieldC == 0 && connection->post->field10 == 0) {
            if (first)
                func_02084F40(buffer, g_021CEE80, connection->post->field4);
            else
                func_02084F40(buffer, g_021CEE88, connection->post->field4);
            writePos = func_0209477C(buffer);
        } else if (data->type == 0) {
            if (first)
                func_02084F40(buffer, g_021CEE80, data->field4);
            else
                func_02084F40(buffer, g_021CEE88, data->field4);
            writePos = func_0209477C(buffer);
        } else if (data->type == 3) {
            header.mVersionAndFlags = 8;
            header.mTypeT = (first ? 8 : 8) | 4 | 2;
            header.mOptionsLength = 0;
            header.mIdLength = 0x20;
            header.mTypeLength = 0;
            header.mDataLength = 0;
            src = (u32 *)&header;
            dst = (u32 *)buffer;
            for (i = 0; i < 3; i++)
                dst[i] = src[i];
            writePos = 0xc;
            ghiPostAppendString(buffer, &writePos, connection->post->fieldC);
            ghiPostAppendString(buffer, &writePos, connection->post->field14);
        } else {
            writePos = func_0209477C(buffer);
        }

        if (connection->encryptor.field4 != 0 &&
            connection->encryptor.field8 == 1) {
            if (writePos == 0)
                writePos = func_0209477C(buffer);
            result = func_021BFDEC(&connection->sendBuffer, buffer, writePos);
            if (result == 0)
                return 0;
            if (func_021C011C(connection) == 0)
                return 0;
            if (connection->sendBuffer.field10 < connection->sendBuffer.fieldC)
                return 2;
        } else {
            if (writePos == 0)
                writePos = func_0209477C(buffer);
            result = func_021C07B8(connection, buffer, writePos);
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
