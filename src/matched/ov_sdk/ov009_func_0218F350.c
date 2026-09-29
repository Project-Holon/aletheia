/*
 * function: func_0218F350
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

extern unsigned int func_0209477C(const char *s);
extern int func_0218946C(void **connection, GPIBuffer *outputBuffer, char *buffer);
extern int func_0218949C(void **connection, GPIBuffer *outputBuffer, int num);
extern int func_021893C8(void **connection, GPIBuffer *outputBuffer, char *buffer, int len);
extern int func_0218934C(void **connection, GPIBuffer *outputBuffer, char c);
extern void func_02184234(void *array, void *elem);
extern int func_02184098(int *timer);
extern char g_021A4FC4[];
extern char g_021A4FC8[];
extern char g_021A4FD0[];

int func_0218F350(void **connection, GPIPeer *peer, int type, char *message)
{
    int len;

    if (peer == 0)
        return 3;
    if (message == 0)
        return 3;
    len = func_0209477C(message);
    {
        GPIMessage gpiMessage = {0};
        gpiMessage.type = type;
        {
            int __result__ = func_0218946C(connection, &gpiMessage.buffer, g_021A4FC4);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C(connection, &gpiMessage.buffer, type);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C(connection, &gpiMessage.buffer, g_021A4FC8);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C(connection, &gpiMessage.buffer, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C(connection, &gpiMessage.buffer, g_021A4FD0);
            if (__result__ != 0)
                return __result__;
        }
        gpiMessage.start = gpiMessage.buffer.len;
        {
            int __result__ = func_021893C8(connection, &gpiMessage.buffer, message, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218934C(connection, &gpiMessage.buffer, 0);
            if (__result__ != 0)
                return __result__;
        }
        func_02184234(peer->messages, &gpiMessage);
        peer->timeout = func_02184098(0) + 10000;
        return 0;
    }
}
