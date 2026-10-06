/*
 * function: func_021C2C28
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
 *   1. `g_021CE0B4` is a 4-byte object, not `char[]`.  Declaring it
 *      `extern Hex4 g_021CE0B4;` and writing `hex = g_021CE0B4;` makes the
 *      copy the pair-at-a-time struct copy the image has (2 ldrb, 2 strb,
 *      2 ldrb, 2 strb, with the independent `add sb,#0x58` / `mov r6,#0`
 *      scheduled into the gaps).  The `*(Hex4 *)g_021CE0B4` cast form made
 *      MWCC emit four loads then four stores in one solid block (48 concrete
 *      bytes, 20 of them this copy).
 *   2. The two pool globals were swapped: the image's hex table is
 *      `g_021CEEB4` and the character-set string handed to func_02094A28 is
 *      `g_021CED88` (image pool +0x180 = 0x021CEEB4 feeding r4, the table
 *      indexed at +0x0E4/+0x0E8; +0x184 = 0x021CED88 feeding r5, the
 *      func_02094A28 argument).  The parked draft had them the other way
 *      round, which is the last 4 concrete bytes.
 *
 * symbols:
 *   func_02094A28  0x02094A28  arm
 *   func_021C0004  0x021C0004  arm   ov114
 *   func_021BFCEC  0x021BFCEC  arm   ov114
 *   func_021C07B8  0x021C07B8  arm   ov114
 *   func_021C011C  0x021C011C  arm   ov114
 *   func_021C00FC  0x021C00FC  arm   ov114
 *   g_021CE0B4     0x021CE0B4  data
 *   g_021CEEB4     0x021CEEB4  data
 *   g_021CED88     0x021CED88  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021C2C28.c \
 *       --func func_021C2C28 --addr 0x021C2C28 --region ov114 --arm \
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

extern char *func_02094A28(const char *, int);
struct Ctx;
extern int func_021C0004(struct Ctx *ctx, int ch);
extern int func_021BFCEC(GHIBuffer *, char *, int);
extern GRes func_021C07B8(GHIConnection *, char *, int);
extern int func_021C011C(GHIConnection *);
extern void func_021C00FC(GHIBuffer *);
extern Hex4 g_021CE0B4;
extern char g_021CEEB4[];
extern char g_021CED88[];

GRes func_021C2C28(GHIPostState *state, GHIConnection *connection)
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
        hex = g_021CE0B4;
        i = 0;
        if (connection->encrypted != 0)
            writeBuffer = &connection->sendBuffer;
        for (c = string[0]; c != 0; c = string[++i]) {
            if (func_02094A28(g_021CED88, c) != 0) {
                result = func_021C0004((struct Ctx *)writeBuffer, c);
            } else if (c == ' ') {
                result = func_021C0004((struct Ctx *)writeBuffer, '+');
            } else {
                hex.c[1] = g_021CEEB4[c / 16];
                hex.c[2] = g_021CEEB4[c % 16];
                result = func_021BFCEC(writeBuffer, hex.c, 3);
            }
        }
    } else {
        result = func_021C07B8(connection, state->data->string, state->data->length);
        if (result == GERR)
            return GERR;
        return GOK;
    }
    if (connection->encrypted == 0) {
        if (func_021C011C(connection) == 0)
            return 0;
        if (connection->encoded.pos == connection->encoded.size)
            func_021C00FC(&connection->encoded);
        return 1;
    }
    return 1;
}
