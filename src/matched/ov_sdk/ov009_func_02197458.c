/*
 * function: gti2BeginReliableMessage
 * address:  0x02197458
 * packet:   pkt_ov009_02197458
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2BeginReliableMessage (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   gti2GetBufferFreeSpace              0x02194DD4  arm  ov009
 *   gti2ConnectionMemoryError           0x02195F70  arm  ov009
 *   gti2StoreOutgoingReliableMessageInfo 0x021973E4 arm  ov009
 *   gti2BufferWriteData                 0x02194E2C  arm  ov009
 *   gti2BufferWriteByte                 0x02194DE4  arm  ov009
 *   gti2BufferWriteUShort               0x02194DFC  arm  ov009
 *   d_021A5948                          0x021A5948  data ov009
 *
 * Opens a reliable GT2 message: sizes the VDP length word, reserves outgoing
 * sequence space and appends the header (2-byte token, type byte, sequence
 * number) to the connection's send buffer.  Writes 1 to *overflow and returns
 * the connection's memory-error flag when a step fails.
 *
 * Both `freeSpace < len` and the store-info failure exit through the same
 * `return cond ? (side effect) : 0`.  The parked form spelled the test as
 * `err != 0 ? (*overflow = 1) : 0`, which 1.1p1 lowers as the taken arm first
 * (`movne r0,#1; strne r0,[r5]; moveq r0,#0`, 14 bytes out at two sites).
 * Inverting the test and swapping the arms --
 *
 *     return (gti2ConnectionMemoryError(connection) == 0) ? 0 : (*overflow = 1);
 *
 * -- makes the compiler emit the else-constant first and then the predicated
 * taken arm, which is the image's `moveq r0,#0; movne r0,#1; strne r0,[r5]`.
 * Same three instructions, same predicate, only the emission order changes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02197458.c \
 *     --func gti2BeginReliableMessage --addr 0x02197458 --region ov009 \
 *     --arm --cc 1.1p1 --lang c99 --diff
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
