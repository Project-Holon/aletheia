/*
 * function: gpiHandleTransferMessage
 * address:  0x02192FD0
 * packet:   pkt_ov009_02192FD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiHandleTransferMessage (libdwcgsgp.TWL.HYB.a(gpitransfer.o))
 *
 * symbols:
 *   gpiValueForKey  0x02193418  arm  ov009
 *   func_0208CF34  0x0208CF34  arm
 *   gpiSendTransferReply  0x02192F24  arm  ov009
 *   g_021A56B4  0x021A56B4  data
 *   g_021A56BC  0x021A56BC  data
 */

struct GPITransferID {
    int a;
    int b;
    int c;
};

extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int func_0208CF34(char *src, char *fmt, ...);
extern int gpiSendTransferReply(void **connection, struct GPITransferID *transferID, void *peer, int result, char *msg);
extern char g_021A56B4[];
extern char g_021A56BC[];

void gpiHandleTransferMessage(void **connection, void *peer, int unused, char *headers, char *buffer, int len)
{
    char value[64];
    struct GPITransferID transferID;

    if (gpiValueForKey(headers, g_021A56B4, value, 64) == 0)
        return;
    if (func_0208CF34(value, g_021A56BC, &transferID.a, &transferID.b, &transferID.c) != 3)
        return;
    gpiSendTransferReply(connection, &transferID, peer, 2, 0);
}
