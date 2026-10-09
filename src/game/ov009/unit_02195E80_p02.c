/*
 * file:     unit_02195E80_p02.c
 * unit:     yes
 * function: func_02195F9C, func_02196098, func_02196118, func_021961C8, func_02196268, func_02196348
 * address:  0x02195F9C
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
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02195EB4  0x02195EB4  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_02194E80  0x02194E80  arm  ov009
 *   func_02195340  0x02195340  arm  ov009
 *   func_021950B4  0x021950B4  arm  ov009
 *   func_02195F5C  0x02195F5C  arm  ov009
 *   func_02194C6C  0x02194C6C  arm  ov009
 *   func_02194B74  0x02194B74  arm  ov009
 *   func_02197678  0x02197678  arm  ov009
 *   func_02194D74  0x02194D74  arm  ov009
 *   func_02197700  0x02197700  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   gti2ConnectionCommunicationError  0x02195F5C  arm  ov009
 *   gti2CheckResponse                 0x02194D74  arm  ov009
 *   gti2SendClosed                    0x02197BB8  arm  ov009
 *   gti2ConnectionClosed              0x021959D0  arm  ov009
 *   current_time                      0x0217F264  arm  ov009
 *   gti2ConnectAttemptCallback        0x02194F2C  arm  ov009
 */
typedef struct Msg {
	int offset;
	unsigned char pad0[4];
	unsigned short SN;
} Msg;

typedef struct Conn_02195F9C {
	unsigned char pad0[0x50];
	unsigned char buffer[8];
	int a58;
	unsigned char pad1[4];
	void *outgoing;
} Conn_02195F9C;

typedef struct Conn_02195E80 {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x8c];
	void *filters;
} Conn_02195E80;

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x28];
	void *challenge;
	int challengeLen;
	unsigned char pad2[0x28];
	unsigned char response[1];
} Conn;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct GTI2Socket
{
    char pad0[0x20];
    int flag;
} GTI2Socket;

typedef struct GTI2Connection
{
    u32 ip;
    u16 port;
    GTI2Socket *socket;
    int state;
    char pad0[0x58];
    u8 response[0x24];
    u32 startTime;
} GTI2Connection;

extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_02195EB4(unsigned short SN1, unsigned short SN2);
extern void func_0218437C(int a, int b);
extern void func_02194E80(void *buffer, int start, int shortenBy);
extern int func_02195340(Conn_02195E80 *c, int filterID, unsigned char *msg, int len, int reliable);
extern int func_021950B4(Conn_02195E80 *c, unsigned char *msg, int len, int reliable);
extern int func_02195F5C(Conn_02195E80 *c);
extern unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge);
extern unsigned char *func_02194B74(unsigned char *buffer);
extern int func_02197678(Conn *c, char *response, char *challenge);
extern int func_02194D74(unsigned char *response1, unsigned char *response2);
extern int func_02197700(struct Conn *c, char *response, char *message, int len);
extern void func_0217EAE0(void *ptr);
extern int gti2ConnectionCommunicationError();
extern int gti2CheckResponse();
extern int gti2SendClosed();
extern void gti2ConnectionClosed();
extern u32 current_time(void);
extern int gti2ConnectAttemptCallback();
int func_02195F9C(Conn_02195F9C *connection, unsigned short ESN);
int func_02196098(Conn_02195E80 *c, unsigned char *msg, int len);
int func_02196118(Conn_02195E80 *c, unsigned char *message, int len);
int func_021961C8(Conn *c, unsigned char *message, int len);
int func_02196268(Conn *connection, unsigned char *message, int len);
int func_02196348(GTI2Connection *connection, u8 *message, int len);



/*
 * sdk:      gti2HandleESN (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02195F9C(Conn_02195F9C *connection, unsigned short ESN)
{
	int len;
	int i;
	Msg *message;
	int shortenBy;

	len = func_02184200(connection->outgoing);
	if (len == 0)
		return 1;
	for (i = 0; i < len; i++) {
		message = func_02184208(connection->outgoing, i);
		if (func_02195EB4(message->SN, ESN) >= 0)
			break;
	}
	if (i == 0)
		return 1;
	while (i-- != 0)
		func_0218437C((int)connection->outgoing, i);
	len = func_02184200(connection->outgoing);
	if (len == 0) {
		connection->a58 = 0;
		return 1;
	}
	message = func_02184208(connection->outgoing, 0);
	shortenBy = message->offset;
	for (i = 0; i < len; i++) {
		message = func_02184208(connection->outgoing, i);
		message->offset -= shortenBy;
	}
	func_02194E80(connection->buffer, 0, shortenBy);
	return 1;
}




/*
 * sdk:      gti2HandleAppUnreliable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196098(Conn_02195E80 *c, unsigned char *msg, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6)
		return 1;
	if (func_02184200(c->filters)) {
		ret = 0;
		if (func_02195340(c, 0, msg, len, 0))
			ret = 1;
		return ret;
	}
	ret = 0;
	if (func_021950B4(c, msg, len, 0))
		ret = 1;
	return ret;
}




/*
 * sdk:      gti2HandleAppReliable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196118(Conn_02195E80 *c, unsigned char *message, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6) {
		if (!func_02195F5C(c))
			return 0;
	} else if (func_02184200(c->filters)) {
		ret = 1;
		if (!func_02195340(c, 0, message, len, 1))
			ret = 0;
		return ret;
	} else {
		if (!func_021950B4(c, message, len, 1))
			return 0;
	}
	return 1;
}



/*
 * sdk:      gti2HandleClientChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021961C8(Conn *c, unsigned char *message, int len)
{
	char response[32];
	char challenge[32];

	if (c->state != 2) {
		if (func_02195F5C((Conn_02195E80 *)c))
			return 1;
		return 0;
	}
	if (len < 0x20) {
		if (func_02195F5C((Conn_02195E80 *)c))
			return 1;
		return 0;
	}
	func_02194C6C((unsigned char *)response, message);
	func_02194B74((unsigned char *)challenge);
	func_02194C6C(c->response, (unsigned char *)challenge);
	if (!func_02197678(c, response, challenge))
		return 0;
	c->state = 3;
	return 1;
}




/*
 * sdk:      gti2HandleServerChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196268(Conn *connection, unsigned char *message, int len)
{
	char response[32];

	if (connection->state != 0) {
		if (func_02195F5C((Conn_02195E80 *)connection))
			return 1;
		return 0;
	}
	if (len < 0x40) {
		if (func_02195F5C((Conn_02195E80 *)connection))
			return 1;
		return 0;
	}
	if (!func_02194D74(message, connection->response)) {
		if (func_02195F5C((Conn_02195E80 *)connection))
			return 1;
		return 0;
	}
	func_02194C6C((unsigned char *)response, message + 0x20);
	if (!func_02197700(connection, response, connection->challenge, connection->challengeLen))
		return 0;
	if (connection->challenge != 0) {
		func_0217EAE0(connection->challenge);
		connection->challenge = 0;
	}
	connection->state = 1;
	return 1;
}




/*
 * sdk:      gti2HandleClientResponse (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196348(GTI2Connection *connection, u8 *message, int len)
{
    int latency;

    if (connection->state != 3)
        return gti2ConnectionCommunicationError(connection) != 0;
    if (len < 32)
        return gti2ConnectionCommunicationError(connection) != 0;
    if (!gti2CheckResponse(message, connection->response))
        return gti2ConnectionCommunicationError(connection) != 0;
    if (connection->socket->flag == 0)
    {
        if (!gti2SendClosed(connection))
            return 0;
        gti2ConnectionClosed(connection);
        return 1;
    }
    connection->state = 4;
    latency = current_time() - connection->startTime;
    return gti2ConnectAttemptCallback(connection->socket, connection, connection->ip, connection->port, latency, message + 32, len - 32) != 0;
}
