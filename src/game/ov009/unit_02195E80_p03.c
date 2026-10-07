/*
 * file:     unit_02195E80_p03.c
 * unit:     yes
 * function: func_02196268, func_02196348
 * address:  0x02196268
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
 *   func_02195F5C  0x02195F5C  arm  ov009
 *   func_02194D74  0x02194D74  arm  ov009
 *   func_02194C6C  0x02194C6C  arm  ov009
 *   func_02197700  0x02197700  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   gti2ConnectionCommunicationError  0x02195F5C  arm  ov009
 *   gti2CheckResponse                 0x02194D74  arm  ov009
 *   gti2SendClosed                    0x02197BB8  arm  ov009
 *   gti2ConnectionClosed              0x021959D0  arm  ov009
 *   current_time                      0x0217F264  arm  ov009
 *   gti2ConnectAttemptCallback        0x02194F2C  arm  ov009
 */
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

extern int func_02195F5C(Conn *c);
extern int func_02194D74(unsigned char *response1, unsigned char *response2);
extern unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge);
extern int func_02197700(struct Conn *c, char *response, char *message, int len);
extern void func_0217EAE0(void *ptr);
extern int gti2ConnectionCommunicationError();
extern int gti2CheckResponse();
extern int gti2SendClosed();
extern void gti2ConnectionClosed();
extern u32 current_time(void);
extern int gti2ConnectAttemptCallback();
int func_02196268(Conn *connection, unsigned char *message, int len);
int func_02196348(GTI2Connection *connection, u8 *message, int len);


/*
 * sdk:      gti2HandleServerChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196268(Conn *connection, unsigned char *message, int len)
{
	char response[32];

	if (connection->state != 0) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	if (len < 0x40) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	if (!func_02194D74(message, connection->response)) {
		if (func_02195F5C(connection))
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
