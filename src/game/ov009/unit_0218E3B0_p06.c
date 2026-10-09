/*
 * file:     unit_0218E3B0_p06.c
 * unit:     yes
 * function: gpiPeerLeftCallback, func_0218F65C
 * address:  0x0218F5F4
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
 *   gpiGetPeerByAddr  0x0218F0E8  arm
 *   SOC_InetNtoA      0x0215FA9C  arm
 *   gsDebugFormat     0x0217D254  arm
 *   g_021A5000        0x021A5000  data
 *   func_0218F0E8  0x0218f0e8  arm   ov009
 *   func_0218F150  0x0218f150  arm   ov009
 *   func_0215FA9C  0x0215fa9c  arm   ov009
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_0217EAC8  0x0217eac8  arm   ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_02189D78  0x02189d78  arm   ov009
 *   memcpy         0x02092344  arm
 *   g_021A5028     0x021a5028  data
 *   g_021A5070     0x021a5070  data
 *   g_021A4F1C     0x021a4f1c  data
 */
struct GPIPeer;
struct SOCInAddr_0218F5F4 {
    unsigned long addr;  /* +0x00 */
};

struct GPIPeer_s {
    int state;       /* +0x00 */
    char pad04[0x10 - 0x04];
    int profile;     /* +0x10 */
};

struct SOCInAddr_0218F65C {
    unsigned int addr;
};

typedef struct {
    int state;
    int initiated;
    unsigned int ip;
    unsigned short port;
    char pad[0xc];
    unsigned char *buff;
    int size;
    int writePos;
} GPIPeer;

extern struct GPIPeer_s *gpiGetPeerByAddr(void **connection, unsigned int ip,
                                          unsigned short port);
extern char *SOC_InetNtoA(struct SOCInAddr_0218F5F4 in);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern GPIPeer *func_0218F0E8(void **connection, unsigned int ip, unsigned short port);
extern struct GPIPeer *func_0218F150(void **connection, int profileid, int initiate);
extern char *func_0215FA9C(struct SOCInAddr_0218F65C in);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void *func_0217EAC8(void *ptr, unsigned int size);
extern void func_0217EAE0(void *ptr);
extern void func_02193734(int *p, int b);
extern int func_02189D78(int *connection, int a1, int a2);
extern void *memcpy(void *, const void *, unsigned int);
void gpiPeerLeftCallback(unsigned int ip, unsigned short port, void *unused, void **connection);
void func_0218F65C(unsigned int ip, unsigned short port, unsigned char *message, int messageLength, int unused, void *userData);
extern char g_021A5000[];
extern char g_021A5028[];
extern char g_021A5070[];
extern char g_021A4F1C[];


void gpiPeerLeftCallback(unsigned int ip, unsigned short port, void *unused,
                         void **connection)
{
    struct SOCInAddr_0218F5F4 anAddr;
    struct GPIPeer_s *aPeer;

    anAddr.addr = ip;
    aPeer = gpiGetPeerByAddr(connection, ip, port);
    if (aPeer == 0)
        return;
    gsDebugFormat(1, 0, 8, g_021A5000, SOC_InetNtoA(anAddr), port,
                  aPeer->profile);
    aPeer->state = 0x6a;
}


/*
 * sdk:      gpiPeerMessageCallback (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
void func_0218F65C(unsigned int ip, unsigned short port, unsigned char *message,
                   int messageLength, int unused, void *userData)
{
    void **connection;
    GPIPeer *aPeer;
    unsigned char *buff;
    int writePos;
    int size;
    struct SOCInAddr_0218F65C anAddr;
    unsigned char *reallocedBuff;

    connection = (void **)userData;
    anAddr.addr = ip;
    aPeer = func_0218F0E8(connection, ip, port);
    if (aPeer == 0) {
        aPeer = (GPIPeer *)func_0218F150(connection, -1, 0);
        if (aPeer != 0) {
            aPeer->state = 0x68;
            aPeer->ip = ip;
            aPeer->port = port;
        } else {
            func_0217D254(1, (char *)2, 1, g_021A5028, func_0215FA9C(anAddr), port);
            return;
        }
    }
    writePos = aPeer->writePos;
    size = aPeer->size;
    buff = aPeer->buff;
    if (messageLength > size - writePos) {
        size = writePos + (messageLength < 0x4000 ? 0x4000 : messageLength);
        reallocedBuff = func_0217EAC8(buff, size + 1);
        if (reallocedBuff == 0) {
            func_0217D254(1, (char *)2, 1, g_021A5070, func_0215FA9C(anAddr), port);
            func_0217EAE0(buff);
            func_02193734((int *)connection, (int)g_021A4F1C);
            func_02189D78((int *)connection, 1, 0);
            return;
        }
        buff = reallocedBuff;
    }
    memcpy(buff + writePos, message, messageLength);
    aPeer->buff = buff;
    aPeer->writePos += messageLength;
    aPeer->size = size;
    buff[aPeer->writePos] = 0;
}
