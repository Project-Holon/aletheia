/*
 * file:     unit_02195B44.c
 * unit:     yes
 * function: func_02195B44, func_02195CC0, func_02195DC4, func_02195DD4, func_02195DE4, func_02195E00
 * address:  0x02195B44
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
 *   gt2StringToAddress          0x021986C4  arm  ov009
 *   gti2NewOutgoingConnection   0x02195590  arm  ov009
 *   gti2StartConnectionAttempt  0x021955F0  arm  ov009
 *   gti2FreeSocketConnection    0x02198264  arm  ov009
 *   gt2Think                    0x02195AF0  arm  ov009
 *   msleep                      0x0217F2BC  arm  ov009
 *   gti2MessageCheck        0x02198808 arm
 *   ArrayLength             0x02184200 arm
 *   gti2SendFilterCallback  0x02195278 arm
 *   gti2Send                0x02197CE0 arm
 *   func_02195980  0x02195980  arm  ov009
 *   DWC_IsSendableReliable       0x02195DC4  arm
 *   func_0218489C  0x0218489C  arm  ov009
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct GTI2Connection
{
    int pad0[3];
    int state;
    int pad1[2];
    int result;
    int pad2;
    int timeout;
    int freezeCount;
} GTI2Connection;

extern int gt2StringToAddress();
extern int gti2NewOutgoingConnection();
extern int gti2StartConnectionAttempt();
extern void gti2FreeSocketConnection();
extern void gt2Think();
extern void msleep();
extern void gti2MessageCheck(unsigned char **message, int *len);
extern int ArrayLength(void *array);
extern int gti2SendFilterCallback(void *connection, int filterID,
    unsigned char *message, int len, int reliable);
extern int gti2Send(void *connection, unsigned char *message, int len, int reliable);
extern void func_02195980(int a, int b);
extern void DWC_IsSendableReliable(void);
extern void func_0218489C(int a, char *p, int c);
int func_02195B44(void *socket, GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking);
int gt2Send(void *connection, unsigned char *message, int len, int reliable);
void func_02195DC4(int a);
asm void KeyValHashKey(void);
void func_02195DE4(int *p);
int func_02195E00(const int *p);


/*
 * sdk:      gt2Connect (libdwcgsgt2.TWL.HYB.a(gt2main.o))
 */
int func_02195B44(void *socket, GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking)
{
    GTI2Connection *connectionTemp;
    int result;
    int done;
    u32 ip;
    u16 port;

    if (!gt2StringToAddress(remoteAddress, &ip, &port) || !ip || !port)
        return 4;
    if (((((ip >> 24) & 0xFF) | ((ip >> 8) & 0xFF00) | ((ip << 8) & 0xFF0000) | ((ip << 24) & 0xFF000000)) & 0xE0000000) == 0xE0000000)
        return 4;
    result = gti2NewOutgoingConnection(socket, &connectionTemp, ip, port);
    if (result)
        return result;
    connectionTemp->timeout = timeout;
    result = gti2StartConnectionAttempt(connectionTemp, message, len, callbacks);
    if (result)
    {
        gti2FreeSocketConnection(connectionTemp);
        return result;
    }
    if (!blocking)
    {
        if (connection)
            *connection = connectionTemp;
        return 0;
    }
    connectionTemp->freezeCount++;
    do
    {
        gt2Think(socket);
        done = connectionTemp->state >= 5;
        if (!done)
            msleep(1);
    } while (!done);
    connectionTemp->freezeCount--;
    if (connectionTemp->state == 5)
        *connection = connectionTemp;
    return connectionTemp->result;
}


int gt2Send(void *connection, unsigned char *message, int len, int reliable)
{
    unsigned short vdpDataLength;

    if (*(int *)((char *)connection + 0xc) != 5)
        return 8;
    gti2MessageCheck(&message, &len);
    if (reliable) {
        char *p = *(char **)((char *)connection + 8);

        if (*(int *)(p + 0x40) == 2) {
            unsigned char *b = (unsigned char *)&vdpDataLength;

            b[0] = message[0];
            b[1] = message[1];
            if (len != vdpDataLength + *(int *)(p + 0x44))
                return 9;
        }
    }
    if (ArrayLength(*(void **)((char *)connection + 0x98)) != 0) {
        gti2SendFilterCallback(connection, 0, message, len, reliable);
        return 0;
    }
    return gti2Send(connection, message, len, reliable) ? 0 : 0xa;
}


/*
 * Tail call that supplies the second argument 1.
 */
void func_02195DC4(int a)
{
    func_02195980(a, 1);
}

asm void KeyValHashKey(void)
{
	ldr r0, [r0]
	ldr ip, =DWC_IsSendableReliable
	bx ip
}


/*
 * Tail call on the word at +0xc of the object.  The pool word at +0x14 is the
 * address of the ARM function KeyValHashKey (0x02195DD4, EXACT in
 * ov009_func_02195DD4.c), not data: seeded as a function 2026-09-28.
 */
void func_02195DE4(int *p)
{
    func_0218489C(p[3], (char *)KeyValHashKey, 0);
}

/*
 * Maps the word at +0xc onto 0..3.
 */
int func_02195E00(const int *p)
{
    int v = p[3];

    if (v < 5)
        return 0;
    if (v == 5)
        return 1;
    return v == 6 ? 2 : 3;
}
