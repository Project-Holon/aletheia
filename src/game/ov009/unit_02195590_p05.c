/*
 * file:     unit_02195590_p05.c
 * unit:     yes
 * function: func_021959D0, func_02195A30
 * address:  0x021959D0
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
 *   TableRemove  0x021847BC arm
 *   ArrayAppend  0x02184234 arm
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 */
struct GTI2Connection;
struct GTI2Socket;
struct HashImplementation;
struct DArrayImplementation;
struct GTI2Socket {
    char pad00[0xc];
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
};

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    struct GTI2Socket *socket;
    int state;
};

typedef struct Conn {
	unsigned char pad0[0x38];
	void *msg;
	unsigned char pad1[8];
	void *buf44;
	unsigned char pad3[8];
	void *buf50;
	unsigned char pad4[8];
	void *arr5c;
	void *arr60;
	unsigned char pad5[0x34];
	void *arr98;
	void *arr9c;
} Conn;

extern int TableRemove(struct HashImplementation *table, void *delElem);
extern void ArrayAppend(struct DArrayImplementation *array, void *newElem);
extern void func_0217EAE0(void *ptr);
extern void func_021841B0(void *array);
void gti2ConnectionClosed(struct GTI2Connection *connection);
void func_02195A30(Conn *c);


void gti2ConnectionClosed(struct GTI2Connection *connection)
{
    if (connection->state == 7)
        return;
    connection->state = 7;
    TableRemove(connection->socket->connections, &connection);
    ArrayAppend(connection->socket->closedConnections, &connection);
}


/*
 * sdk:      gti2ConnectionCleanup (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
void func_02195A30(Conn *c)
{
	if (c->msg)
		func_0217EAE0(c->msg);
	if (c->buf44)
		func_0217EAE0(c->buf44);
	if (c->buf50)
		func_0217EAE0(c->buf50);
	if (c->arr5c)
		func_021841B0(c->arr5c);
	if (c->arr60)
		func_021841B0(c->arr60);
	if (c->arr98)
		func_021841B0(c->arr98);
	if (c->arr9c)
		func_021841B0(c->arr9c);
	func_0217EAE0(c);
}
