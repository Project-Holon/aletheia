/*
 * function: ghiPostStringStateDoPosting
 * address:  0x021C2C28
 * packet:   pkt_ov114_021C2C28
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostStringStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * Two spellings were wrong, both invisible to the C semantics:
 *   1. `sGhttpUrlEscapeTemplate` is a 4-byte object, not `char[]`.  Declaring it
 *      `extern Hex4 sGhttpUrlEscapeTemplate;` and writing `hex = sGhttpUrlEscapeTemplate;` makes the
 *      copy the pair-at-a-time struct copy the image has (2 ldrb, 2 strb,
 *      2 ldrb, 2 strb, with the independent `add sb,#0x58` / `mov r6,#0`
 *      scheduled into the gaps).  The `*(Hex4 *)sGhttpUrlEscapeTemplate` cast form made
 *      MWCC emit four loads then four stores in one solid block (48 concrete
 *      bytes, 20 of them this copy).
 *   2. The two pool globals were swapped: the image's hex table is
 *      `sGhttpHexDigits` and the character-set string handed to strchr is
 *      `sGhttpUrlSafeChars` (image pool +0x180 = 0x021CEEB4 feeding r4, the table
 *      indexed at +0x0E4/+0x0E8; +0x184 = 0x021CED88 feeding r5, the
 *      strchr argument).  The parked draft had them the other way
 *      round, which is the last 4 concrete bytes.
 *
 * symbols:
 *   strchr  0x02094A28  arm
 *   ghiAppendCharToBuffer  0x021C0004  arm   ov114
 *   ghiAppendDataToBuffer  0x021BFCEC  arm   ov114
 *   ghiTrySendThenBuffer  0x021C07B8  arm   ov114
 *   ghiSendBufferedData  0x021C011C  arm   ov114
 *   ghiResetBuffer  0x021C00FC  arm   ov114
 *   sGhttpUrlEscapeTemplate     0x021CE0B4  data
 *   sGhttpHexDigits     0x021CEEB4  data
 *   sGhttpUrlSafeChars     0x021CED88  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021C2C28.c \
 *       --func ghiPostStringStateDoPosting --addr 0x021C2C28 --region ov114 --arm \
 *       --cc 1.1p1 --lang c99 --diff
 */


typedef struct GHIBuffer {
    int f0;
    char *data;
    int f8;
    int size;
    int pos;
    int f14;
    int f18;
    int f1C;
    int f20;
} GHIBuffer;

typedef struct GHIPostString {
    int f0;
    int f4;
    char *string;
    int length;
    int encode;
} GHIPostString;

typedef struct GHIPostState {
    GHIPostString *data;
} GHIPostState;

typedef struct GHIPostData {
    char pad[0xc];
    int flagC;
    int flag10;
} GHIPostData;

typedef struct GHIConnection {
    char pad0[0x58];
    GHIBuffer encoded;
    GHIBuffer sendBuffer;
    char pad_a0[0x164 - 0xa0];
    GHIPostData *postData;
    char pad_168[0x198 - 0x168];
    int encrypted;
} GHIConnection;

typedef enum { GERR, GOK, GBUF } GRes;

typedef struct Hex4 {
    char c[4];
} Hex4;

typedef unsigned char  u8;
extern u8 *strchr(const u8 *s, int c);
struct Ctx;
extern int ghiAppendCharToBuffer(struct Ctx *ctx, int ch);
extern int ghiAppendDataToBuffer(GHIBuffer *, char *, int);
extern GRes ghiTrySendThenBuffer(GHIConnection *, char *, int);
extern int ghiSendBufferedData(GHIConnection *);
extern void ghiResetBuffer(GHIBuffer *);
extern Hex4 sGhttpUrlEscapeTemplate;
extern char sGhttpHexDigits[];
extern char sGhttpUrlSafeChars[];

GRes ghiPostStringStateDoPosting(GHIPostState *state, GHIConnection *connection)
{
    int i;
    int c;
    char *string;
    Hex4 hex;
    GHIBuffer *writeBuffer;
    GRes result;

    if (state->data->length == 0)
        return 1;
    if (connection->postData->flagC == 0 && connection->postData->flag10 == 0 && state->data->encode != 0) {
        string = state->data->string;
        writeBuffer = &connection->encoded;
        hex = sGhttpUrlEscapeTemplate;
        i = 0;
        if (connection->encrypted != 0)
            writeBuffer = &connection->sendBuffer;
        for (c = string[0]; c != 0; c = string[++i]) {
            if (strchr((const u8 *)sGhttpUrlSafeChars, c) != 0) {
                result = ghiAppendCharToBuffer((struct Ctx *)writeBuffer, c);
            } else if (c == ' ') {
                result = ghiAppendCharToBuffer((struct Ctx *)writeBuffer, '+');
            } else {
                hex.c[1] = sGhttpHexDigits[c / 16];
                hex.c[2] = sGhttpHexDigits[c % 16];
                result = ghiAppendDataToBuffer(writeBuffer, hex.c, 3);
            }
        }
    } else {
        result = ghiTrySendThenBuffer(connection, state->data->string, state->data->length);
        if (result == GERR)
            return GERR;
        return GOK;
    }
    if (connection->encrypted == 0) {
        if (ghiSendBufferedData(connection) == 0)
            return 0;
        if (connection->encoded.pos == connection->encoded.size)
            ghiResetBuffer(&connection->encoded);
        return 1;
    }
    return 1;
}
