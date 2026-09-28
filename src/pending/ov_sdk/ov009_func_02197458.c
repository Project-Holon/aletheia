/*
 * function: gti2BeginReliableMessage
 * address:  0x02197458
 * packet:   pkt_ov009_02197458
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * blocker: boolean normalize/store order (compiled movne,strne,moveq vs orig moveq,movne,strne); 244 B size exact
 * status:   DIFF
 *
 * sdk:      gti2BeginReliableMessage (gt2message.o)
 *
 * symbols:
 *   gti2GetBufferFreeSpace           0x02194DD4 arm
 *   gti2ConnectionMemoryError        0x02195F70 arm
 *   gti2StoreOutgoingReliableMessageInfo 0x021973E4 arm
 *   gti2BufferWriteData              0x02194E2C arm
 *   gti2BufferWriteByte              0x02194DE4 arm
 *   gti2BufferWriteUShort            0x02194DFC arm
 *   d_021A5948                       0x021A5948 data
 */

struct GTI2Connection;
struct GTI2Socket;
struct GTI2Buffer;

extern int gti2GetBufferFreeSpace(struct GTI2Buffer *buffer);
extern int gti2ConnectionMemoryError(struct GTI2Connection *connection);
extern int gti2StoreOutgoingReliableMessageInfo(struct GTI2Connection *connection,
                                                unsigned short SN, int len);
extern void gti2BufferWriteData(struct GTI2Buffer *buffer,
                                unsigned char *data, int len);
extern void gti2BufferWriteByte(struct GTI2Buffer *buffer, unsigned char b);
extern void gti2BufferWriteUShort(struct GTI2Buffer *buffer, unsigned short s);
extern unsigned char d_021A5948[];

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

struct GTI2Connection {
    char pad00[8];
    struct GTI2Socket *socket;
    char pad0c[0x44];
    struct GTI2Buffer buffer;
    char pad5c[8];
    unsigned short field_64;
    unsigned short field_66;
};

static int gti2BeginReliableMessage(struct GTI2Connection *connection,
                                    int type, int len, int *overflow)
{
    unsigned short vdpDataLength;
    int freeSpace;

    vdpDataLength = (unsigned short)(len - connection->socket->field_44);
    freeSpace = gti2GetBufferFreeSpace(&connection->buffer);
    if (freeSpace < len)
        return (gti2ConnectionMemoryError(connection) != 0) ? (*overflow = 1) : 0;
    if (!gti2StoreOutgoingReliableMessageInfo(connection, connection->field_64,
                                              len))
        return (gti2ConnectionMemoryError(connection) != 0) ? (*overflow = 1) : 0;
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
