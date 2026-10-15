/*
 * function: gpiPeerAddMessage
 * address:  0x0218F350
 * packet:   pkt_ov009_0218F350
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerAddMessage (libdwcgsgp.TWL.HYB.a gpipeer.o)
 *
 * symbols:
 *   strlen  0x0209477c  arm
 *   gpiAppendStringToBuffer  0x0218946c  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949c  arm   ov009
 *   gpiAppendStringToBufferLen  0x021893c8  arm   ov009
 *   gpiAppendCharToBuffer  0x0218934c  arm   ov009
 *   ArrayAppend  0x02184234  arm   ov009
 *   gsiTimeNitro  0x02184098  arm   ov009
 *   gGpiPeerKeyM     0x021a4fc4  data
 *   gGpiPeerKeyLen     0x021a4fc8  data
 *   gGpiPeerKeyMsgCont     0x021a4fd0  data
 */

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
extern int strlen(const u8 *s);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern int gpiAppendStringToBufferLen(int *connection, int *buffer, int src, int n);
extern int gpiAppendCharToBuffer(int *connection, int *buffer, int c);
extern void ArrayAppend(void *array, void *elem);
extern int gsiTimeNitro(int *timer);
extern char gGpiPeerKeyM[];
extern char gGpiPeerKeyLen[];
extern char gGpiPeerKeyMsgCont[];

int gpiPeerAddMessage(void **connection, GPIPeer *peer, int type, char *message)
{
    int len;

    if (peer == 0)
        return 3;
    if (message == 0)
        return 3;
    len = strlen((const u8 *)message);
    {
        GPIMessage gpiMessage = {0};
        gpiMessage.type = type;
        {
            int __result__ = gpiAppendStringToBuffer((int *)connection, (int *)(&gpiMessage.buffer), gGpiPeerKeyM);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendIntToBuffer((int *)connection, (int *)(&gpiMessage.buffer), type);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendStringToBuffer((int *)connection, (int *)(&gpiMessage.buffer), gGpiPeerKeyLen);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendIntToBuffer((int *)connection, (int *)(&gpiMessage.buffer), len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendStringToBuffer((int *)connection, (int *)(&gpiMessage.buffer), gGpiPeerKeyMsgCont);
            if (__result__ != 0)
                return __result__;
        }
        gpiMessage.start = gpiMessage.buffer.len;
        {
            int __result__ = gpiAppendStringToBufferLen((int *)connection, (int *)(&gpiMessage.buffer), (int)message, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendCharToBuffer((int *)connection, (int *)(&gpiMessage.buffer), 0);
            if (__result__ != 0)
                return __result__;
        }
        ArrayAppend(peer->messages, &gpiMessage);
        peer->timeout = gsiTimeNitro(0) + 10000;
        return 0;
    }
}
