/*
 * function: ghiPostXmlStateDoPosting
 * address:  0x021C2DB0
 * packet:   pkt_ov114_021C2DB0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  bytes MATCH (352 B, 13 relocations); the callees gsXmlWriterGetData / gsXmlWriterGetDataLength (ov009 gsxml
 *           getters) have no catalog row and no verified shard, so the 5 relocations to them
 *           cannot be attested; needs those two ov009 leaves matched first.
 *
 * sdk:      ghiPostXmlStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * symbols:
 *   gsXmlWriterGetDataLength  0x02181E20  arm   ov009
 *   gsXmlWriterGetData  0x02181E18  arm   ov009
 *   ghiAppendDataToBuffer  0x021BFCEC  arm   ov114
 *   ghiEncryptDataToBuffer  0x021BFDEC  arm   ov114
 *   ghiResetBuffer  0x021C00FC  arm   ov114
 *   ghiSendBufferedData  0x021C011C  arm   ov114
 *   ghiTrySendThenBuffer  0x021C07B8  arm   ov114
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

extern int gsXmlWriterGetDataLength(void *);
extern char *gsXmlWriterGetData(void *);
extern int ghiAppendDataToBuffer(GHIBuffer *, char *, int);
extern int ghiEncryptDataToBuffer(struct GHIBuffer *buffer, const char *data, int dataLen);
extern void ghiResetBuffer(GHIBuffer *);
extern int ghiSendBufferedData(GHIConnection *);
extern GRes ghiTrySendThenBuffer(GHIConnection *, char *, int);

GRes ghiPostXmlStateDoPosting(GHIPostState *state, GHIConnection *connection)
{
    void *xml = state->data->xml;
    char pad[3] = {0, 0, 0};
    int padlen = 0;
    GRes result;

    if (connection->postData->flag14 != 0) {
        padlen = 4 - (gsXmlWriterGetDataLength(xml) % 4);
        if (padlen == 4)
            padlen = 0;
    }
    if (connection->encrypted != 0 && connection->encryptState == 1) {
        if (ghiAppendDataToBuffer(&connection->sendBuffer, gsXmlWriterGetData(xml), gsXmlWriterGetDataLength(xml)) == 0 ||
            ghiAppendDataToBuffer(&connection->sendBuffer, pad, padlen) == 0 ||
            ghiEncryptDataToBuffer(&connection->encoded, connection->sendBuffer.data, connection->sendBuffer.size) == 0)
            return 0;
        ghiResetBuffer(&connection->sendBuffer);
        if (ghiSendBufferedData(connection) == 0)
            return 0;
        if (connection->encoded.pos == connection->encoded.size)
            ghiResetBuffer(&connection->encoded);
        return 1;
    }
    if (ghiTrySendThenBuffer(connection, gsXmlWriterGetData(xml), gsXmlWriterGetDataLength(xml)) == 0)
        return 0;
    result = ghiTrySendThenBuffer(connection, pad, padlen);
    if (result == 0)
        return 0;
    return 1;
}
