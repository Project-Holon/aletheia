/*
 * file:     unit_02176DEC_p01.c
 * unit:     yes
 * function: func_02176DEC, func_02176DFC, func_02176E90, func_02176EB0, func_02176FD4, func_02177044
 * address:  0x02176DEC
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
 *   func_02059F38          0x02059F38  arm
 *   DWC_IsValidAID         0x0216B94C  arm  ov009
 *   DWCi_IsValidAID        0x0216BC3C  arm  ov009
 *   func_02177788          0x02177788  arm  ov009
 *   DWCs_GetOutgoingBufferFreeSize  0x02177E64  arm  ov009
 *   DWCs_GetRequiredHeaderSize      0x0217721C  arm  ov009
 *   func_02176BE4          0x02176BE4  arm  ov009
 *   func_02177770  0x02177770  arm  ov009
 *   func_021771B0  0x021771B0  arm  ov009
 *   func_021777C0  0x021777C0  arm  ov009
 *   func_02177E64  0x02177E64  arm  ov009
 *   g_021AB180  0x021AB180  data
 *   DWC_GetMyAID                   0x0216B838  arm ov009
 *   func_0216B838   0x0216B838  arm ov009
 *   DWCi_SendUnreliable  0x02177848  arm  ov009
 */

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

typedef struct TransInfo {
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

extern int func_02059F38(void);
extern int DWC_IsValidAID(int aid);
extern int DWCi_IsValidAID(int aid);
extern unsigned char func_02177788(int i);
extern int DWCs_GetOutgoingBufferFreeSize(int aid);
extern int DWCs_GetRequiredHeaderSize(int type);
extern int func_02176BE4(void);
extern int func_02177770(int i);
extern void func_021771B0(TransHeader *header, unsigned short type, int size);
extern void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable);
extern int func_02177E64(unsigned char aid);
extern unsigned char DWC_GetMyAID(void);
extern unsigned char func_0216B838(void);
extern void DWCi_SendUnreliable(int myaid, int aid, void *buffer, int size, int flag);
extern TransInfo *g_021AB180;
int func_02176DEC(int a);
int func_02176DFC(int aid, int type);
int func_02176E90(unsigned char aid, void *buffer, int size);
int func_02176EB0(unsigned short type, unsigned char aid, void *buffer, int size);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
int func_02177044(unsigned char aid, void *buffer, int size);


/*
 * Tail call that supplies the second argument 1.
 */
int func_02176DEC(int a)
{
    return func_02176DFC(a, 1);
}



/*
 * sdk:      DWCi_IsSendableReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int func_02176DFC(int aid, int type)
{
    long freeSpace;

    if (func_02059F38() != 0 || (type == 1 && DWC_IsValidAID(aid) == 0))
        return 0;
    if (DWCi_IsValidAID(aid) == 0)
        return 0;
    if (func_02177788(aid) == 1)
        return 0;
    freeSpace = DWCs_GetOutgoingBufferFreeSize(aid);
    if (freeSpace < DWCs_GetRequiredHeaderSize(type))
        return 0;
    return func_02176BE4() != 0;
}


/*
 * sdk:      DWC_SendReliable
 */
int func_02176E90(unsigned char aid, void *buffer, int size)
{
    return func_02176EB0(1, aid, buffer, size);
}


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


/*
 * sdk:      DWC_SendReliableBitmap (dwc_transport.o)
 *
 * Closed (w5_nm): the bit is the conditional expression
 * `(aid != 0) ? (1 << aid) : 1`, which keeps the two constant 1s in separate
 * registers (r7 for the zero case, r8 for the shift); the statement form with
 * a later `if (aid == 0) aidbit = 1;` shared one register.
 */
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size)
{
    unsigned long aidbit;
    unsigned char aid;

    for (aid = 0; aid < 32; aid++) {
        aidbit = (aid != 0) ? (1 << aid) : 1;
        if ((bitmap & aidbit) == 0)
            continue;
        if (aid == DWC_GetMyAID())
            continue;
        if (func_02176E90(aid, buffer, size) == 0)
            bitmap &= ~aidbit;
    }
    return bitmap;
}


/*
 * sdk:      DWC_SendUnreliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int func_02177044(unsigned char aid, void *buffer, int size)
{
    if (func_02059F38() != 0)
        return 0;
    if (DWC_IsValidAID(aid) == 0)
        return 0;
    if (size > 0x5B6)
        return 0;
    DWCi_SendUnreliable(func_0216B838(), aid, buffer, size, 1);
    if (g_021AB180->sendCallback != 0)
        g_021AB180->sendCallback(size, aid, g_021AB180->sendCallbackParam);
    return 1;
}
