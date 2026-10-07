/*
 * file:     unit_0218E3B0_p03.c
 * unit:     yes
 * function: func_0218F350, func_0218F4BC, func_0218F51C
 * address:  0x0218F350
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
 *   func_0209477C  0x0209477c  arm
 *   func_0218946C  0x0218946c  arm   ov009
 *   func_0218949C  0x0218949c  arm   ov009
 *   func_021893C8  0x021893c8  arm   ov009
 *   func_0218934C  0x0218934c  arm   ov009
 *   func_02184234  0x02184234  arm   ov009
 *   func_02184098  0x02184098  arm   ov009
 *   g_021A4FC4     0x021a4fc4  data
 *   g_021A4FC8     0x021a4fc8  data
 *   g_021A4FD0     0x021a4fd0  data
 *   OS_SPrintf             0x02084F40  arm
 *   gpiSendOrBufferString  0x02189750  arm
 *   g_021A4FD8             0x021A4FD8  data
 *   func_02084F40  0x02084F40  arm
 *   func_02189750  0x02189750  arm  ov009
 *   func_0218964C  0x0218964C  arm  ov009
 *   func_02189644  0x02189644  arm  ov009
 *   g_021A4FEC  0x021A4FEC  data
 *   g_021A4FF0  0x021A4FF0  data
 */
struct GPIPeer_s;
typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct {
    GPIBuffer buffer;
    int type;
    int start;
} GPIMessage;

typedef struct {
    char pad[0x14];
    int timeout;
    char pad2[0x24];
    void *messages;
} GPIPeer;

typedef unsigned char  u8;

struct GPITransferID_s {
    int          profileid;  /* +0x00 */
    unsigned int count;      /* +0x04 */
    unsigned int time;       /* +0x08 */
};

struct GPIPeer {
    char pad0[0x14];
    int timeout;
};

extern int func_0209477C(const u8 *s);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern int func_021893C8(int *connection, int *buffer, int src, int n);
extern int func_0218934C(int *connection, int *buffer, int c);
extern void func_02184234(void *array, void *elem);
extern int func_02184098(int *timer);
extern int  OS_SPrintf(char *dst, char *fmt, ...);
extern int  gpiSendOrBufferString(void **connection, struct GPIPeer_s *peer,
                                  char *string);
extern int func_02084F40(char *dst, char *fmt, ...);
extern int func_02189750(void **connection, struct GPIPeer *peer, char *string);
extern int func_0218964C(void **connection, struct GPIPeer *peer, char *string, int stringLen);
extern int func_02189644();
int func_0218F350(void **connection, GPIPeer *peer, int type, char *message);
int gpiPeerStartTransferMessage(void **connection, struct GPIPeer_s *peer, int type, struct GPITransferID_s *transferID);
int func_0218F51C(void **connection, struct GPIPeer *peer, char *message, int len);
extern char g_021A4FC4[];
extern char g_021A4FC8[];
extern char g_021A4FD0[];
extern char g_021A4FD8[];
extern char g_021A4FEC[];   /* "" -- the default when message is 0 */
extern char g_021A4FF0[];   /* "\len\%d\msg\\\n" -- OS_SPrintf's format */


/*
 * sdk:      gpiPeerAddMessage (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
int func_0218F350(void **connection, GPIPeer *peer, int type, char *message)
{
    int len;

    if (peer == 0)
        return 3;
    if (message == 0)
        return 3;
    len = func_0209477C((const u8 *)message);
    {
        GPIMessage gpiMessage = {0};
        gpiMessage.type = type;
        {
            int __result__ = func_0218946C((int *)connection, (int *)(&gpiMessage.buffer), g_021A4FC4);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C((int *)connection, (int *)(&gpiMessage.buffer), type);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C((int *)connection, (int *)(&gpiMessage.buffer), g_021A4FC8);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C((int *)connection, (int *)(&gpiMessage.buffer), len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C((int *)connection, (int *)(&gpiMessage.buffer), g_021A4FD0);
            if (__result__ != 0)
                return __result__;
        }
        gpiMessage.start = gpiMessage.buffer.len;
        {
            int __result__ = func_021893C8((int *)connection, (int *)(&gpiMessage.buffer), (int)message, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218934C((int *)connection, (int *)(&gpiMessage.buffer), 0);
            if (__result__ != 0)
                return __result__;
        }
        func_02184234(peer->messages, &gpiMessage);
        peer->timeout = func_02184098(0) + 10000;
        return 0;
    }
}


int gpiPeerStartTransferMessage(void **connection, struct GPIPeer_s *peer,
                                int type, struct GPITransferID_s *transferID)
{
    char buffer[64];
    int profileid;
    unsigned int count;
    unsigned int time;

    profileid = transferID->profileid;
    count = transferID->count;
    time = transferID->time;
    if (transferID == 0)
        return 3;
    OS_SPrintf(buffer, g_021A4FD8, type, profileid, count, time);
    return gpiSendOrBufferString(connection, peer, buffer);
}


/*
 * Byte-correct (216/216), 8 of 8 relocation sites resolved.
 *
 * The two pool words at the end are in the order the code first names them:
 * the `ldreq` at +0028 (the `message == 0` default) addresses +00D0, which the
 * image fills with 0x021A4FEC -- the compiler's 1-byte empty string @15025 --
 * and the `ldr` at +0044 (OS_SPrintf's format) addresses +00D4 = 0x021A4FF0,
 * "\len\%d\msg\\\n", @15026.  Spelling them the other way round still
 * reproduces every instruction, because the pool slots are the same either
 * way, but the two words come out exchanged and `sole-ref/self`, which
 * compares the word it is about to write with the ROM word at the site,
 * refuses both.  Both literals are attested by the overlay's own image
 * (ov009 window, the only two candidate windows holding them are ov009 and
 * ov021 and only ov009's bytes are read, the function under test living there).
 *
 * The DWARF carries three separate `enum _GPResult __result__` locals, all in
 * r0, one per if-chain, so the original almost certainly declared a result in
 * each of three sibling blocks rather than reusing one.  The single `result`
 * below colours identically -- r0 in all three, r4 never live across a call --
 * and reproduces all 216 bytes, so the extra scopes buy nothing here.
 *
 * sdk:      gpiPeerFinishTransferMessage (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
int func_0218F51C(void **connection, struct GPIPeer *peer, char *message, int len)
{
    char buffer[32];
    int result;

    if (peer == 0)
        return 3;
    if (message == 0)
        message = g_021A4FEC;
    if (len == -1)
        len = func_0209477C((const u8 *)message);
    func_02084F40(buffer, g_021A4FF0, len);
    result = func_02189750(connection, peer, buffer);
    if (result != 0)
        return result;
    result = func_0218964C(connection, peer, message, len);
    if (result != 0)
        return result;
    result = func_02189644(connection, peer, 0);
    if (result != 0)
        return result;
    peer->timeout = func_02184098(0) + 10000;
    return 0;
}
