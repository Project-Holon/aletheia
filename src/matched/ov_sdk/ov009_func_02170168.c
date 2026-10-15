/*
 * function: DWCi_SendSBMsgCommand
 * address:  0x02170168
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sends a match command to a host through the server browser.
 *
 * symbols:
 *   DWCi_EncodeBinaryMsgCommand  0x021700C8  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   gt2AddressToString  0x02198620  arm  ov009
 *   ServerBrowserSendMessageToServerA  0x0219EF08  arm  ov009
 */

typedef struct {
    char id[5];
} MatchId;

typedef struct {
    MatchId id;
    unsigned char pad[3];
    unsigned char command;
    unsigned char len;
    unsigned short port;
    int ip;
    int pid;
    unsigned int data[32];
} MatchCtrl;

struct DWCstBinaryMessage;
struct ServerBrowser;
extern void DWCi_EncodeBinaryMsgCommand(struct DWCstBinaryMessage *message, unsigned char command, unsigned long *data, int len);
extern int func_02175F3C(void);
extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
extern int ServerBrowserSendMessageToServerA(struct ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);

int DWCi_SendSBMsgCommand(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    int i;
    int res;

    DWCi_EncodeBinaryMsgCommand((struct DWCstBinaryMessage *)(&ctrl), command, (long unsigned int *)data, len);
    for (i = 0; i < 1; i++) {
        res = ServerBrowserSendMessageToServerA(*(void **)(func_02175F3C() + 0x5e0), gt2AddressToString(ip, 0, 0), port, (char *)(&ctrl), ctrl.len + 0x14);
        if (res == 0) {
            return res;
        }
        if (res != 2) {
            return res;
        }
    }
    return res;
}
