/*
 * function: DWCi_SendReliable
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
 *   DWCs_GetTransConnection  0x02177770  arm  ov009
 *   func_02176DFC  0x02176DFC  arm  ov009
 *   DWCs_EncodeHeader  0x021771B0  arm  ov009
 *   DWCs_Send  0x021777C0  arm  ov009
 *   DWCs_GetOutgoingBufferFreeSize  0x02177E64  arm  ov009
 *   gDwcTransInfo  0x021AB180  data
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

extern int DWCs_GetTransConnection(int i);
extern int func_02176DFC(int aid, int type);
extern void DWCs_EncodeHeader(TransHeader *header, unsigned short type, int size);
extern void DWCs_Send(unsigned char aid, unsigned char *buffer, int size, int reliable);
extern int DWCs_GetOutgoingBufferFreeSize(unsigned char aid);
extern struct TransInfo *gDwcTransInfo;

int DWCi_SendReliable(unsigned short type, unsigned char aid, void *buffer, int size)
{
    int freeSpace;
    int sendSize;
    TransHeader header;
    TransConn *transConnection;

    transConnection = (TransConn *)DWCs_GetTransConnection(aid);
    if (!func_02176DFC((unsigned char)aid, (unsigned short)type))
        return 0;
    transConnection->sendState = 1;
    transConnection->sendBuffer = buffer;
    transConnection->sendingSize = 0;
    transConnection->requestSendSize = size;
    DWCs_EncodeHeader(&header, type, size);
    DWCs_Send(aid, (unsigned char *)&header, 8, 1);
    sendSize = gDwcTransInfo->sendSplitMax;
    if (size <= sendSize)
        sendSize = size;
    freeSpace = DWCs_GetOutgoingBufferFreeSize(aid);
    if (sendSize > freeSpace)
        return 1;
    DWCs_Send(aid, buffer, sendSize, 1);
    transConnection->sendingSize += sendSize;
    freeSpace = transConnection->requestSendSize;
    if (transConnection->sendingSize == freeSpace) {
        transConnection->sendState = 0;
        transConnection->sendBuffer = 0;
        transConnection->sendingSize = 0;
        transConnection->requestSendSize = 0;
        if (gDwcTransInfo->sendCallback && type == 1)
            gDwcTransInfo->sendCallback(freeSpace, aid, gDwcTransInfo->sendCallbackParam);
    }
    return 1;
}
