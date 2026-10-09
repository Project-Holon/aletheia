/*
 * file:     unit_02196C34_p05.c
 * unit:     yes
 * function: gti2SendAppReliable, func_021975FC, func_02197678
 * address:  0x02197594
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
 *   gti2BufferWriteData       0x02194e2c arm
 *   gti2EndReliableMessage    0x0219754c arm
 *   func_02197458  0x02197458  arm  ov009
 *   func_02194E2C  0x02194E2C  arm  ov009
 *   func_0219754C  0x0219754C  arm  ov009
 */
struct GTI2Connection {
    unsigned char pad0[8];
    struct GTI2Peer * peer;
};

struct GTI2Peer {
    unsigned char pad0[0x44];
    int field_44;
};

typedef struct Sock {
	unsigned char pad0[0x44];
	int overhead;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
	unsigned char pad1[0x44];
	unsigned char buffer[0x38];
	int a88;
	int a8c;
} Conn;

extern int gti2BeginReliableMessage(struct GTI2Connection * connection, int type, int len, int * overflow);
extern void gti2BufferWriteData(void * buffer, unsigned char * data, int len);
extern int gti2EndReliableMessage(struct GTI2Connection * connection);
extern int func_02197458(Conn *c, int type, int len, int *overflow);
extern void func_02194E2C(void *buffer, unsigned char *data, int len);
extern int func_0219754C(Conn *c);
int gti2SendAppReliable(struct GTI2Connection * connection, unsigned char * message, int len);
int gti2SendClientChallenge(struct GTI2Connection * connection, char * challenge);
/* * sdk: gti2SendServerChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o)) */ int func_02197678(Conn *c, char *response, char *challenge);


int gti2SendAppReliable(struct GTI2Connection * connection, unsigned char * message, int len)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 0, len + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData((char *)connection + 0x50, message, len);
    return gti2EndReliableMessage(connection) != 0;
}



int gti2SendClientChallenge(struct GTI2Connection * connection, char * challenge)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 1, connection->peer->field_44 + 0x27, &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData((char *)connection + 0x50, (unsigned char *)challenge, 0x20);
    return gti2EndReliableMessage(connection) != 0;
}



/*
 * sdk:      gti2SendServerChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02197678(Conn *c, char *response, char *challenge)
{
	int overflow;

	if (!func_02197458(c, 2, c->sock->overhead + 0x47, &overflow))
		return 0;
	if (overflow)
		return 1;
	func_02194E2C(c->buffer, (unsigned char *)response, 0x20);
	func_02194E2C(c->buffer, (unsigned char *)challenge, 0x20);
	if (!func_0219754C(c))
		return 0;
	c->a8c = c->a88;
	return 1;
}
