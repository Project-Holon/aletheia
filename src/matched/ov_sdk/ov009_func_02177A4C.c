/*
 * function: DWCs_HandleUnreliableMessage
 * address:  0x02177A4C
 * packet:   pkt_ov009_02177A4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_HandleUnreliableMessage (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCi_GetConnectionAID                       0x0216BB54 arm
 *   DWCi_SetError                               0x02059F54 arm
 *   strncmp                                     0x020949F4 arm
 *   DWCi_HandleGT2UnreliableMatchCommandMessage 0x02174E10 arm
 *   memcmp                                      0x020923F0 arm
 *   MI_CpuCopy8                                 0x02082D44 arm
 *   DWC_IsServerMyself                          0x0216BA08 arm
 *   DWC_GetMyAID                                0x0216B838 arm
 *   DWCi_SendUnreliable                         0x02177848 arm
 *   OS_GetTick                                  0x020870D0 arm
 *   gDwcTransMatchMagic                                  0x021A234C data
 *   gDwcTransForwardMagic                                  0x021A2348 data
 *   gDwcTransInfo                                  0x021AB180 data
 */

extern unsigned char DWCi_GetConnectionAID(void *connection);
extern void DWCi_SetError(int error, int errorCode);
extern int strncmp(const char *a, const char *b, unsigned int n);
extern void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
extern int memcmp(const void *a, const void *b, unsigned int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int DWC_IsServerMyself(void);
extern unsigned char DWC_GetMyAID(void);
extern void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo,
    unsigned char *buffer, int size, int fromDWC_SendUnreliable);
extern unsigned long long OS_GetTick(void);
extern char gDwcTransMatchMagic[];
extern char gDwcTransForwardMagic[];
extern char gDwcTransInfo[];

#define sTransInfo (*(char **)gDwcTransInfo)

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
    if (size >= 0x14u && strncmp(message, gDwcTransMatchMagic, 4) == 0) {
        DWCi_HandleGT2UnreliableMatchCommandMessage(message, size);
        return;
    }
    if (size >= 8 && memcmp(message, gDwcTransForwardMagic, 3) == 0)
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
