/*
 * function: gpiSendTransferReply
 * address:  0x02192F24
 * packet:   pkt_ov009_02192F24
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendTransferReply (libdwcgsgp.TWL.HYB.a(gpitransfer.o))
 *
 * symbols:
 *   func_0218F4BC  0x0218F4BC  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_02189750  0x02189750  arm  ov009
 *   gpiPeerFinishTransferMessage  0x0218F51C  arm  ov009
 *   g_021A5698  0x021A5698  data
 *   g_021A569C  0x021A569C  data
 */

struct GPITransferID {
    int a;
    int b;
    int c;
};

extern int func_0218F4BC(void **connection, void *peer, int type, struct GPITransferID *transferID);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int func_02189750(void **connection, void *peer, char *string);
struct GPIPeer;
extern int gpiPeerFinishTransferMessage(void **connection, struct GPIPeer *peer, char *message, int len);
extern char g_021A5698[];
extern char g_021A569C[];

int gpiSendTransferReply(void **connection, struct GPITransferID *transferID, void *peer, int result, char *msg)
{
    char buffer[32];
    int r;

    if (msg == 0)
        msg = g_021A5698;
    r = func_0218F4BC(connection, peer, 0xc9, transferID);
    if (r != 0)
        return r;
    OS_SPrintf(buffer, g_021A569C, 1, result);
    r = func_02189750(connection, peer, buffer);
    if (r != 0)
        return r;
    r = gpiPeerFinishTransferMessage(connection, peer, msg, -1);
    if (r != 0)
        return r;
    return 0;
}
