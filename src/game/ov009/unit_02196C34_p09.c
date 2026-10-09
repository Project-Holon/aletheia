/*
 * file:     unit_02196C34_p09.c
 * unit:     yes
 * function: gti2SendAck, func_02197AD8, gti2SendPong, func_02197BB8, func_02197BD4
 * address:  0x02197A30
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gti2UShortToBuffer      0x02195EA0 arm
 *   gti2ConnectionSendData  0x02195750 arm
 *   d_021A5948              0x021A5948 data
 *   func_02195EA0  0x02195EA0  arm  ov009
 *   func_02195750  0x02195750  arm  ov009
 *   g_021A5948  0x021A5948  data
 *   func_02198328  0x02198328  arm  ov009
 *   @14988         0x021A5948  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

struct GTI2Connection;
struct GTI2Socket;
struct Sock;
struct GTI2Socket {
    char pad00[0x40];
    int field_40;
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
    char pad68[0x28];
    int pendingAck;
};

typedef struct Sock {
	unsigned char pad0[0x40];
	int type;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
} Conn;

extern void gti2UShortToBuffer(unsigned char *buffer, int pos, unsigned short s);
extern int gti2ConnectionSendData(struct GTI2Connection *connection,
                                  unsigned char *message, int len);
extern void func_02195EA0(unsigned char *buffer, int pos, unsigned short s);
extern int func_02195750(Conn *c, unsigned char *message, int len);
extern int func_02198328(Sock *sock, unsigned int ip, unsigned short port, unsigned char *message, int len);
int gti2SendAck(struct GTI2Connection *connection);
int func_02197AD8(Conn *connection, unsigned short SNMin, unsigned short SNMax);
asm void gti2SendPong(void);
int func_02197BB8(int *p);
int func_02197BD4(Sock *sock, unsigned int ip, unsigned short port);
extern unsigned char d_021A5948[];
extern unsigned char g_021A5948[];





int gti2SendAck(struct GTI2Connection *connection)
{
    short dataLength;
    int pos;
    char buffer[7];

    pos = 0;
    if (connection->socket->field_40 == 2)
    {
        unsigned char *s;
        unsigned char *d;
        dataLength = 5;
        s = (unsigned char *)&dataLength;
        d = (unsigned char *)buffer + pos;
        d[0] = s[0];
        d[1] = s[1];
        pos += 2;
    }
    {
        unsigned char *s = d_021A5948;
        unsigned char *d = (unsigned char *)buffer + pos;
        d[0] = s[0];
        d[1] = s[1];
        pos += 2;
    }
    buffer[pos] = 100;
    pos += 1;
    gti2UShortToBuffer((unsigned char *)buffer, pos, connection->field_66);
    pos += 2;
    if (gti2ConnectionSendData(connection, (unsigned char *)buffer, pos))
    {
        connection->pendingAck = 0;
        return 1;
    }
    return 0;
}





/*
 * sdk:      gti2SendNack (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02197AD8(Conn *connection, unsigned short SNMin, unsigned short SNMax)
{
	char buffer[9];
	int pos = 0;
	short dataLength;

	if (connection->sock->type == 2) {
		dataLength = 7;
		memcpy(buffer + pos, &dataLength, 2);
		pos += 2;
	}
	memcpy(buffer + pos, g_021A5948, 2);
	pos += 2;
	buffer[pos] = 0x65;
	pos++;
	func_02195EA0((unsigned char *)buffer, pos, SNMin);
	pos += 2;
	if (SNMin != SNMax) {
		func_02195EA0((unsigned char *)buffer, pos, SNMax);
		pos += 2;
	}
	if (!func_02195750(connection, (unsigned char *)buffer, pos))
		return 0;
	return 1;
}




asm void gti2SendPong(void)
{
	ldr ip, =gti2ConnectionSendData
	mov r3, #0x67
	strb r3, [r1, #2]
	bx ip
}



/*
 * Tail call on three fields of the object.
 */
int func_02197BB8(int *p)
{
    return func_02197BD4((struct Sock *)p[2], p[0], *(unsigned short *)((char *)p + 4));
}


/*
 * sdk:      gti2SendClosedOnSocket (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * w4_nm: both two-byte copies are memcpy through string.h (inlined as the
 * ldrb/strb pairs with the object's register roles); the magic source is the
 * string literal "\xFE\xFE", the vendor template @14988 at 0x021A5948.
 */
int func_02197BD4(Sock *sock, unsigned int ip, unsigned short port)
{
	char buffer[5];
	int pos = 0;
	short dataLength;

	if (sock->type == 2) {
		dataLength = 3;
		memcpy(buffer + pos, &dataLength, 2);
		pos += 2;
	}
	memcpy(buffer + pos, "\xFE\xFE", 2);
	pos += 2;
	buffer[pos] = 0x68;
	pos++;
	if (!func_02198328(sock, ip, port, (unsigned char *)buffer, pos))
		return 0;
	return 1;
}
