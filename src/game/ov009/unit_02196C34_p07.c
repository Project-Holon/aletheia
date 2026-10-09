/*
 * file:     unit_02196C34_p07.c
 * unit:     yes
 * function: gti2SendReject, gti2SendClose, gti2SendKeepAlive
 * address:  0x021977E8
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
 *   gti2BeginReliableMessage  0x02197458 arm
 *   gti2BufferWriteData       0x02194E2C arm
 *   gti2EndReliableMessage    0x0219754C arm
 */
struct GTI2Connection_02196C34;
struct GTI2Socket;
struct GTI2Buffer;
struct GTI2Socket {
    char pad00[0x44];
    int field_44;
};

struct GTI2Buffer {
    unsigned char *data;
    int size;
    int position;
};

struct GTI2Connection_02196C34 {
    char pad00[8];
    struct GTI2Socket *socket;
    char pad0c[0x44];
    struct GTI2Buffer buffer;
};

extern int gti2BeginReliableMessage(struct GTI2Connection_02196C34 *connection, int type,
                                    int len, int *overflow);
extern void gti2BufferWriteData(struct GTI2Buffer *buffer,
                                unsigned char *data, int len);
extern int gti2EndReliableMessage(struct GTI2Connection_02196C34 *connection);
int gti2SendReject(struct GTI2Connection_02196C34 *connection, unsigned char *message, int len);
int gti2SendClose(struct GTI2Connection_02196C34 *connection);
int gti2SendKeepAlive(struct GTI2Connection_02196C34 *connection);


int gti2SendReject(struct GTI2Connection_02196C34 *connection, unsigned char *message,
                   int len)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 5,
                                  (len + 7) + connection->socket->field_44,
                                  &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData(&connection->buffer, message, len);
    return gti2EndReliableMessage(connection) != 0;
}



int gti2SendClose(struct GTI2Connection_02196C34 *connection)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 6,
                                  connection->socket->field_44 + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    return gti2EndReliableMessage(connection) != 0;
}



int gti2SendKeepAlive(struct GTI2Connection_02196C34 *connection)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 7,
                                  connection->socket->field_44 + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    return gti2EndReliableMessage(connection) != 0;
}
