/*
 * function: func_021C2DB0
 * address:  0x021C2DB0
 * packet:   pkt_ov114_021C2DB0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  bytes MATCH (352 B, 13 relocations); the callees func_02181E18 / func_02181E20 (ov009 gsxml
 *           getters) have no catalog row and no verified shard, so the 5 relocations to them
 *           cannot be attested; needs those two ov009 leaves matched first.
 *
 * sdk:      ghiPostXmlStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * symbols:
 *   func_02181E20  0x02181E20  arm   ov009
 *   func_02181E18  0x02181E18  arm   ov009
 *   func_021BFCEC  0x021BFCEC  arm   ov114
 *   func_021BFDEC  0x021BFDEC  arm   ov114
 *   func_021C00FC  0x021C00FC  arm   ov114
 *   func_021C011C  0x021C011C  arm   ov114
 *   func_021C07B8  0x021C07B8  arm   ov114
 */

typedef enum { GERR, GOK, GBUF } GRes;

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

typedef struct GHIPostXml {
    int f0;
    int f4;
    void *xml;
} GHIPostXml;

typedef struct GHIPostState {
    GHIPostXml *data;
} GHIPostState;

typedef struct GHIPostData {
    char pad[0x14];
    int flag14;
} GHIPostData;

typedef struct GHIConnection {
    char pad0[0x58];
    GHIBuffer encoded;
    GHIBuffer sendBuffer;
    char pad_a0[0x164 - 0xa0];
    GHIPostData *postData;
    char pad_168[0x198 - 0x168];
    int encrypted;
    char pad_19c[0x1a8 - 0x19c];
    int encryptState;
} GHIConnection;

extern int func_02181E20(void *);
extern char *func_02181E18(void *);
extern int func_021BFCEC(GHIBuffer *, char *, int);
extern int func_021BFDEC(struct GHIBuffer *buffer, const char *data, int dataLen);
extern void func_021C00FC(GHIBuffer *);
extern int func_021C011C(GHIConnection *);
extern GRes func_021C07B8(GHIConnection *, char *, int);

GRes func_021C2DB0(GHIPostState *state, GHIConnection *connection)
{
    void *xml = state->data->xml;
    char pad[3] = {0, 0, 0};
    int padlen = 0;
    GRes result;

    if (connection->postData->flag14 != 0) {
        padlen = 4 - (func_02181E20(xml) % 4);
        if (padlen == 4)
            padlen = 0;
    }
    if (connection->encrypted != 0 && connection->encryptState == 1) {
        if (func_021BFCEC(&connection->sendBuffer, func_02181E18(xml), func_02181E20(xml)) == 0 ||
            func_021BFCEC(&connection->sendBuffer, pad, padlen) == 0 ||
            func_021BFDEC(&connection->encoded, connection->sendBuffer.data, connection->sendBuffer.size) == 0)
            return 0;
        func_021C00FC(&connection->sendBuffer);
        if (func_021C011C(connection) == 0)
            return 0;
        if (connection->encoded.pos == connection->encoded.size)
            func_021C00FC(&connection->encoded);
        return 1;
    }
    if (func_021C07B8(connection, func_02181E18(xml), func_02181E20(xml)) == 0)
        return 0;
    result = func_021C07B8(connection, pad, padlen);
    if (result == 0)
        return 0;
    return 1;
}
