/*
 * file:     gpitransfer.c
 * unit:     yes
 * function: gpiSendTransferReply, gpiHandleTransferMessage
 * address:  0x02192F24
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
 *   gpiPeerStartTransferMessage  0x0218F4BC  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   gpiSendOrBufferString  0x02189750  arm  ov009
 *   gpiPeerFinishTransferMessage  0x0218F51C  arm  ov009
 *   gGpiTransferEmptyMsg  0x021A5698  data
 *   gGpiTransferResultFmt  0x021A569C  data
 *   gpiValueForKey  0x02193418  arm  ov009
 *   STD_TSScanf  0x0208CF34  arm
 *   gGpiTransferKeyXfer  0x021A56B4  data
 *   gGpiTransferIdFmt  0x021A56BC  data
 */
struct GPIPeer;
struct GPITransferID {
    int a;
    int b;
    int c;
};

extern int gpiPeerStartTransferMessage(void **connection, void *peer, int type, struct GPITransferID *transferID);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int gpiSendOrBufferString(void **connection, void *peer, char *string);
extern int gpiPeerFinishTransferMessage(void **connection, struct GPIPeer *peer, char *message, int len);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int STD_TSScanf(char *src, char *fmt, ...);
int gpiSendTransferReply(void **connection, struct GPITransferID *transferID, void *peer, int result, char *msg);
void gpiHandleTransferMessage(void **connection, void *peer, int unused, char *headers, char *buffer, int len);
extern char gGpiTransferEmptyMsg[];
extern char gGpiTransferResultFmt[];
extern char gGpiTransferKeyXfer[];
extern char gGpiTransferIdFmt[];


/*
 * sdk:      gpiSendTransferReply (libdwcgsgp.TWL.HYB.a(gpitransfer.o))
 */
int gpiSendTransferReply(void **connection, struct GPITransferID *transferID, void *peer, int result, char *msg)
{
    char buffer[32];
    int r;

    if (msg == 0)
        msg = gGpiTransferEmptyMsg;
    r = gpiPeerStartTransferMessage(connection, peer, 0xc9, transferID);
    if (r != 0)
        return r;
    OS_SPrintf(buffer, gGpiTransferResultFmt, 1, result);
    r = gpiSendOrBufferString(connection, peer, buffer);
    if (r != 0)
        return r;
    r = gpiPeerFinishTransferMessage(connection, peer, msg, -1);
    if (r != 0)
        return r;
    return 0;
}


/*
 * sdk:      gpiHandleTransferMessage (libdwcgsgp.TWL.HYB.a(gpitransfer.o))
 */
void gpiHandleTransferMessage(void **connection, void *peer, int unused, char *headers, char *buffer, int len)
{
    char value[64];
    struct GPITransferID transferID;

    if (gpiValueForKey(headers, gGpiTransferKeyXfer, value, 64) == 0)
        return;
    if (STD_TSScanf(value, gGpiTransferIdFmt, &transferID.a, &transferID.b, &transferID.c) != 3)
        return;
    gpiSendTransferReply(connection, &transferID, peer, 2, 0);
}
