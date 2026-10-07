/*
 * function: func_02176EB0
 * address:  0x02176EB0
 * packet:   pkt_ov009_02176EB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * symbols:
 *   func_02177770  0x02177770  arm  ov009
 *   func_02176DFC  0x02176DFC  arm  ov009
 *   func_021771B0  0x021771B0  arm  ov009
 *   func_021777C0  0x021777C0  arm  ov009
 *   func_02177E64  0x02177E64  arm  ov009
 *   g_021AB180  0x021AB180  data
 */

#include "../include/G_TransInfo.h"

typedef struct {
    int size;
    unsigned short type;
    char magicStrings[2];
} TransHeader;

typedef struct {
    unsigned char *sendBuffer;
    unsigned char *recvBuffer;
    int recvBufferSize;
    int sendingSize;
    int recvingSize;
    int requestSendSize;
    int requestRecvSize;
    unsigned char sendState;
    unsigned char recvState;
    unsigned char lastRecvState;
    unsigned char pads[3];
    unsigned short lastRecvType;
    unsigned long long previousRecvTick;
    unsigned long recvTimeoutTime;
    unsigned long long lastSomeDataRecvTick;
} TransConn;

typedef struct {
    TransConn connections[32];
    void (*sendCallback)(int, unsigned char, void *);
    void (*recvCallback)(unsigned char, unsigned char *, int, void *);
    void (*recvTimeoutCallback)(unsigned char, void *);
    void (*pingCallback)(int, unsigned char, void *);
    void *sendCallbackParam;
    void *recvCallbackParam;
    void *recvTimeoutCallbackParam;
    void *pingCallbackParam;
    unsigned short sendSplitMax;
    unsigned long connKeepAliveTime;
} TransInfo;

extern int func_02177770(int i);
extern int func_02176DFC(int aid, int type);
extern void func_021771B0(TransHeader *header, unsigned short type, int size);
extern void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable);
extern int func_02177E64(unsigned char aid);
extern struct TransInfo *g_021AB180;

int func_02176EB0(unsigned short type, unsigned char aid, void *buffer, int size)
{
    int freeSpace;
    int sendSize;
    TransHeader header;
    TransConn *transConnection;

    transConnection = (TransConn *)func_02177770(aid);
    if (!func_02176DFC((unsigned char)aid, (unsigned short)type))
        return 0;
    transConnection->sendState = 1;
    transConnection->sendBuffer = buffer;
    transConnection->sendingSize = 0;
    transConnection->requestSendSize = size;
    func_021771B0(&header, type, size);
    func_021777C0(aid, (unsigned char *)&header, 8, 1);
    sendSize = g_021AB180->sendSplitMax;
    if (size <= sendSize)
        sendSize = size;
    freeSpace = func_02177E64(aid);
    if (sendSize > freeSpace)
        return 1;
    func_021777C0(aid, buffer, sendSize, 1);
    transConnection->sendingSize += sendSize;
    freeSpace = transConnection->requestSendSize;
    if (transConnection->sendingSize == freeSpace) {
        transConnection->sendState = 0;
        transConnection->sendBuffer = 0;
        transConnection->sendingSize = 0;
        transConnection->requestSendSize = 0;
        if (g_021AB180->sendCallback && type == 1)
            g_021AB180->sendCallback(freeSpace, aid, g_021AB180->sendCallbackParam);
    }
    return 1;
}
