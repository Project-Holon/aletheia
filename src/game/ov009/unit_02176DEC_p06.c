/*
 * file:     unit_02176DEC_p06.c
 * unit:     yes
 * function: func_021777C0, func_02177848, func_0217793C, func_02177A4C
 * address:  0x021777C0
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
 *   func_0216BAF4  0x0216BAF4  arm  ov009
 *   func_02176C00  0x02176C00  arm  ov009
 *   gt2Send        0x02195CC0  arm  ov009
 *   func_02176CF8  0x02176CF8  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 *   DWCi_GetGT2Connection                  0x0216BAF4 arm
 *   DWC_IsServerMyself                     0x0216BA08 arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C arm
 *   DWC_Alloc                              0x0205A16C arm
 *   strncpy                                0x02094860 arm
 *   MI_CpuCopy8                            0x02082D44 arm
 *   DWC_Free                               0x0205A1B0 arm
 *   g_021A2348                             0x021A2348 data
 *   DWCi_GetConnectionAID   0x0216BB54 arm
 *   DWCs_GetRecvState       0x021777A4 arm
 *   DWCs_DecodeHeader       0x021771E0 arm
 *   DWCs_RecvDataHeader     0x02177C1C arm
 *   DWCs_RecvDataBody       0x02177CE4 arm
 *   DWCs_RecvSystemDataBody 0x02177DCC arm
 *   g_021AB180              0x021AB180 data
 *   strncmp                                     0x020949F4 arm
 *   DWCi_HandleGT2UnreliableMatchCommandMessage 0x02174E10 arm
 *   memcmp                                      0x020923F0 arm
 *   DWC_GetMyAID                                0x0216B838 arm
 *   OS_GetTick                                  0x020870D0 arm
 *   g_021A234C                                  0x021A234C data
 */
#define sTransInfo (*(char **)g_021AB180)
extern int func_0216BAF4(int aid);
extern int func_02176C00(void);
extern int gt2Send(void *connection, unsigned char *buffer, int size, int reliable);
extern int func_02176CF8(void *connection, unsigned char *buffer, int size);
extern void DWCi_SetError(int kind, int code);
extern void *DWCi_GetGT2Connection(unsigned char aid);
extern int DWC_IsServerMyself(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void *DWC_Alloc(int name, unsigned long size);
extern void strncpy(char *dst, const char *src, int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void DWC_Free(int name, void *ptr, int flag);
extern unsigned char DWCi_GetConnectionAID(void *connection);
extern int DWCs_GetRecvState(unsigned char aid);
extern unsigned short DWCs_DecodeHeader(void *message);
extern void DWCs_RecvDataHeader(unsigned char aid, void *message, int size);
extern void DWCs_RecvDataBody(unsigned char aid, void *message, int size);
extern void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size);
extern int strncmp(const char *a, const char *b, unsigned int n);
extern void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
extern int memcmp(const void *a, const void *b, unsigned int n);
extern unsigned char DWC_GetMyAID(void);
extern unsigned long long OS_GetTick(void);
void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable);
void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer, int size, int fromDWC_SendUnreliable);
void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size);
void DWCs_HandleUnreliableMessage(void *connection, void *message, int size);
extern char g_021A2348[];
extern char g_021AB180[];
extern char g_021A234C[];


/*
 * sdk:      DWCs_Send (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable)
{
    void *connection;
    int res;

    connection = (void *)func_0216BAF4(aid);
    if (reliable != 0) {
        if (func_02176C00() != 0) {
            res = gt2Send(connection, buffer, size, reliable);
            if (res == 0)
                return;
        }
        if (func_02176CF8(connection, buffer, size) != 0)
            return;
        DWCi_SetError(6, -0x17D5E);
        return;
    }
    gt2Send(connection, buffer, size, reliable);
}


void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer,
    int size, int fromDWC_SendUnreliable)
{
    void *connection;
    int bNeedFoward = 0;
    unsigned char *sendBuf;

    connection = DWCi_GetGT2Connection(aidTo);
    if (connection == 0) {
        if (DWC_IsServerMyself())
            return;
        connection = DWCi_GetGT2Connection(
            *(unsigned char *)(DWCi_NodeInfoList_GetNodeInfoForIndex(0) + 0x16));
        if (connection == 0)
            return;
        bNeedFoward = 1;
    }
    if (fromDWC_SendUnreliable == 1 && bNeedFoward == 1) {
        sendBuf = DWC_Alloc(4, size + 8);
        if (sendBuf == 0)
            return;
        strncpy((char *)sendBuf, g_021A2348, 3);
        sendBuf[3] = aidFrom;
        *(unsigned long *)(sendBuf + 4) = 1 << aidTo;
        MI_CpuCopy8(buffer, sendBuf + 8, size);
        gt2Send(connection, sendBuf, size + 8, 0);
        if (sendBuf == 0)
            return;
        DWC_Free(4, sendBuf, 0);
    } else {
        gt2Send(connection, buffer, size, 0);
    }
}


void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size)
{
    unsigned short type;
    unsigned char aid;

    aid = DWCi_GetConnectionAID(connection);
    if (aid == 0xff) {
        DWCi_SetError(6, 0xfffe8298);
        return;
    }
    switch (DWCs_GetRecvState(aid)) {
    case 0:
        type = DWCs_DecodeHeader(message);
        if (type < 2 || type >= 5)
            return;
        DWCs_RecvDataHeader(aid, message, size);
        return;
    case 1:
        DWCs_RecvDataHeader(aid, message, size);
        return;
    case 2:
        DWCs_RecvDataBody(aid, message, size);
        return;
    case 3:
        DWCs_RecvSystemDataBody(aid, message, size);
        return;
    case 4:
        *(char *)(sTransInfo + aid * 0x38 + 0x1d) = 1;
        *(int *)(sTransInfo + aid * 0x38 + 0x10) = 0;
        *(int *)(sTransInfo + aid * 0x38 + 0x18) = 0;
        return;
    default:
        DWCi_SetError(6, 0xfffe82b6);
        return;
    }
}


void DWCs_HandleUnreliableMessage(void *connection, void *message, int size)
{
    unsigned char aidFrom;
    unsigned char aid;
    int toMeAvailable;
    unsigned char tempAid;
    int headerAvailable;
    unsigned long aidToBitmap;
    char *transConnection;

    aidFrom = DWCi_GetConnectionAID(connection);
    headerAvailable = 0;
    toMeAvailable = 0;
    if (aidFrom == 0xff) {
        DWCi_SetError(6, 0xfffe8298);
        return;
    }
    if (size >= 0x14u && strncmp(message, g_021A234C, 4) == 0) {
        DWCi_HandleGT2UnreliableMatchCommandMessage(message, size);
        return;
    }
    if (size >= 8 && memcmp(message, g_021A2348, 3) == 0)
        headerAvailable = 1;
    if (headerAvailable == 1) {
        aidFrom = ((unsigned char *)message)[3];
        MI_CpuCopy8((char *)message + 4, &aidToBitmap, 4);
        if (!DWC_IsServerMyself()) {
            aid = DWC_GetMyAID();
            toMeAvailable = 1;
            if (!(aidToBitmap & (1 << aid)))
                return;
        } else {
            for (tempAid = 0; tempAid < 32; tempAid++) {
                if (aidToBitmap & (1 << tempAid)) {
                    if (tempAid == DWC_GetMyAID())
                        toMeAvailable = 1;
                    else
                        DWCi_SendUnreliable(aidFrom, tempAid, message, size, 0);
                }
            }
        }
        if (toMeAvailable == 0)
            return;
    }
    if (headerAvailable == 1) {
        message = (char *)message + 8;
        size -= 8;
    }
    transConnection = sTransInfo + aidFrom * 0x38;
    if (*(int *)(transConnection + 4) == 0)
        return;
    if (*(int *)(transConnection + 8) < size)
        return;
    if (*(void **)(sTransInfo + 0x704) != 0) {
        ((void (*)(unsigned char, void *, int, int))*(void **)(sTransInfo + 0x704))(
            aidFrom, message, size, *(int *)(sTransInfo + 0x714));
    }
    if (*(int *)(sTransInfo + 0x708) != 0 && *(int *)(transConnection + 0x2c) != 0) {
        unsigned long long tick = OS_GetTick();
        *(unsigned long long *)(transConnection + 0x24) = tick;
    }
}
