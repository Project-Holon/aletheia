/*
 * file:     gpitransfer.c
 * unit:     yes
 * function: func_02192F24, func_02192FD0
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
 *   func_0218F4BC  0x0218F4BC  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_02189750  0x02189750  arm  ov009
 *   gpiPeerFinishTransferMessage  0x0218F51C  arm  ov009
 *   g_021A5698  0x021A5698  data
 *   g_021A569C  0x021A569C  data
 *   func_02193418  0x02193418  arm  ov009
 *   func_0208CF34  0x0208CF34  arm
 *   g_021A56B4  0x021A56B4  data
 *   g_021A56BC  0x021A56BC  data
 */
struct GPIPeer;
struct GPITransferID {
    int a;
    int b;
    int c;
};

extern int func_0218F4BC(void **connection, void *peer, int type, struct GPITransferID *transferID);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int func_02189750(void **connection, void *peer, char *string);
extern int gpiPeerFinishTransferMessage(void **connection, struct GPIPeer *peer, char *message, int len);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int func_0208CF34(char *src, char *fmt, ...);
int func_02192F24(void **connection, struct GPITransferID *transferID, void *peer, int result, char *msg);
void func_02192FD0(void **connection, void *peer, int unused, char *headers, char *buffer, int len);
extern char g_021A5698[];
extern char g_021A569C[];
extern char g_021A56B4[];
extern char g_021A56BC[];


/*
 * sdk:      gpiSendTransferReply (libdwcgsgp.TWL.HYB.a(gpitransfer.o))
 */
int func_02192F24(void **connection, struct GPITransferID *transferID, void *peer, int result, char *msg)
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


/*
 * sdk:      gpiHandleTransferMessage (libdwcgsgp.TWL.HYB.a(gpitransfer.o))
 */
void func_02192FD0(void **connection, void *peer, int unused, char *headers, char *buffer, int len)
{
    char value[64];
    struct GPITransferID transferID;

    if (func_02193418(headers, g_021A56B4, value, 64) == 0)
        return;
    if (func_0208CF34(value, g_021A56BC, &transferID.a, &transferID.b, &transferID.c) != 3)
        return;
    func_02192F24(connection, &transferID, peer, 2, 0);
}
