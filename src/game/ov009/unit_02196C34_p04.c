/*
 * file:     unit_02196C34_p04.c
 * unit:     yes
 * function: gti2BeginReliableMessage, gti2EndReliableMessage
 * address:  0x02197458
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gti2GetBufferFreeSpace              0x02194DD4  arm  ov009
 *   gti2ConnectionMemoryError           0x02195F70  arm  ov009
 *   gti2StoreOutgoingReliableMessageInfo 0x021973E4 arm  ov009
 *   gti2BufferWriteData                 0x02194E2C  arm  ov009
 *   gti2BufferWriteByte                 0x02194DE4  arm  ov009
 *   gti2BufferWriteUShort               0x02194DFC  arm  ov009
 *   d_021A5948                          0x021A5948  data ov009
 *   ArrayLength            0x02184200 arm
 *   ArrayNth               0x02184208 arm
 *   gti2ConnectionSendData 0x02195750 arm
 */
struct GTI2Connection_02197458;
struct GTI2Socket;
struct GTI2Buffer;
struct GTI2OutgoingBufferMessage;
struct DArrayImplementation;
struct GTI2Socket {
    char pad00[0x40];
    int field_40;
    int field_44;
};

struct GTI2Buffer {
    unsigned char *data;
    int size;
    int position;
};

struct GTI2Connection_02197458 {
    char pad00[8];
    struct GTI2Socket *socket;
    char pad0c[0x44];
    struct GTI2Buffer buffer;
    char pad5c[8];
    unsigned short field_64;
    unsigned short field_66;
};

struct GTI2OutgoingBufferMessage {
    unsigned int offset;
    int len;
};

struct GTI2Connection_0219754C {
    char pad00[0x50];
    unsigned char *buffer;
    char pad54[0xc];
    struct DArrayImplementation *outgoingBuffers;
    char pad64[0x2c];
    int pendingAck;
};

extern int gti2GetBufferFreeSpace(struct GTI2Buffer *buffer);
extern int gti2ConnectionMemoryError(struct GTI2Connection_02197458 *connection);
extern int gti2StoreOutgoingReliableMessageInfo(struct GTI2Connection_02197458 *connection,
                                                unsigned short SN, int len);
extern void gti2BufferWriteData(struct GTI2Buffer *buffer,
                                unsigned char *data, int len);
extern void gti2BufferWriteByte(struct GTI2Buffer *buffer, unsigned char b);
extern void gti2BufferWriteUShort(struct GTI2Buffer *buffer, unsigned short s);
extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int gti2ConnectionSendData(struct GTI2Connection_0219754C *connection,
                                  unsigned char *message, int len);
extern unsigned char d_021A5948[];


static int gti2BeginReliableMessage(struct GTI2Connection_02197458 *connection,
                                    int type, int len, int *overflow)
{
    unsigned short vdpDataLength;
    int freeSpace;

    vdpDataLength = (unsigned short)(len - connection->socket->field_44);
    freeSpace = gti2GetBufferFreeSpace(&connection->buffer);
    if (freeSpace < len)
        return (gti2ConnectionMemoryError(connection) == 0) ? 0 : (*overflow = 1);
    if (!gti2StoreOutgoingReliableMessageInfo(connection, connection->field_64,
                                              len))
        return (gti2ConnectionMemoryError(connection) == 0) ? 0 : (*overflow = 1);
    if (connection->socket->field_40 == 2)
        gti2BufferWriteData(&connection->buffer,
                            (unsigned char *)&vdpDataLength,
                            connection->socket->field_44);
    gti2BufferWriteData(&connection->buffer, d_021A5948, 2);
    gti2BufferWriteByte(&connection->buffer, (unsigned char)type);
    gti2BufferWriteUShort(&connection->buffer, connection->field_64++);
    gti2BufferWriteUShort(&connection->buffer, connection->field_66);
    *overflow = 0;
    return 1;
}


static int gti2EndReliableMessage(struct GTI2Connection_0219754C *connection)
{
    struct GTI2OutgoingBufferMessage *message;
    int len;

    len = ArrayLength(connection->outgoingBuffers);
    message = ArrayNth(connection->outgoingBuffers, len - 1);
    if (gti2ConnectionSendData(connection, connection->buffer + message->offset,
                               message->len))
    {
        connection->pendingAck = 0;
        return 1;
    }
    return 0;
}
