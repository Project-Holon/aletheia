/*
 * file:     unit_02196C34_p06.c
 * unit:     yes
 * function: func_02197700, gti2SendAccept
 * address:  0x02197700
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
 *   func_02197458  0x02197458  arm  ov009
 *   func_02194E2C  0x02194E2C  arm  ov009
 *   func_0219754C  0x0219754C  arm  ov009
 *   gti2BeginReliableMessage  0x02197458 arm
 *   gti2EndReliableMessage    0x0219754C arm
 */
struct GTI2Connection;
struct GTI2Socket;
typedef struct Sock {
	unsigned char pad0[0x44];
	int overhead;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
	unsigned char pad1[0x44];
	unsigned char buffer[1];
} Conn;

struct GTI2Socket {
    char pad00[0x44];
    int field_44;
};

struct GTI2Connection {
    char pad00[8];
    struct GTI2Socket *socket;
};

extern int func_02197458(Conn *c, int type, int len, int *overflow);
extern void func_02194E2C(void *buffer, unsigned char *data, int len);
extern int func_0219754C(Conn *c);
extern int gti2BeginReliableMessage(struct GTI2Connection *connection, int type,
                                    int len, int *overflow);
extern int gti2EndReliableMessage(struct GTI2Connection *connection);
int func_02197700(Conn *c, char *response, char *message, int len);
int gti2SendAccept(struct GTI2Connection *connection);


int func_02197700(Conn *c, char *response, char *message, int len)
{
	int overflow;

	if (!func_02197458(c, 3, len + 0x27 + c->sock->overhead, &overflow))
		return 0;
	if (overflow)
		return 1;
	func_02194E2C(c->buffer, (unsigned char *)response, 0x20);
	func_02194E2C(c->buffer, (unsigned char *)message, len);
	return func_0219754C(c) ? 1 : 0;
}


int gti2SendAccept(struct GTI2Connection *connection)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 4,
                                  connection->socket->field_44 + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    return gti2EndReliableMessage(connection) != 0;
}
