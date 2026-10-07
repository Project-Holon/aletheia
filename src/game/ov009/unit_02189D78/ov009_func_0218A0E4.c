/*
 * function: func_0218A0E4
 * address:  0x0218A0E4
 * packet:   pkt_ov009_0218A0E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessCallbacks (gpicallback.o)
 *
 * symbols:
 *   func_02189EA0  0x02189EA0  arm   ov009
 */

typedef struct GPICallbackData {
    unsigned char pad0[0xC];
    int fC;
    int operationID;
    struct GPICallbackData *pnext;
} GPICallbackData;

typedef struct GPIConnection {
    unsigned char pad0[0x5DC];
    GPICallbackData *callbackList;
    GPICallbackData *lastCallback;
} GPIConnection;

extern void func_02189EA0(void **connection, GPICallbackData *data);

int func_0218A0E4(void **connection, int blockingOperationID)
{
    GPIConnection *iconnection;
    GPICallbackData *list;
    GPICallbackData *last;
    GPICallbackData *pcurr;
    GPICallbackData *pprev;
    GPICallbackData *pnext;

    iconnection = (GPIConnection *)*connection;
    if (blockingOperationID) {
        list = iconnection->callbackList;
        last = iconnection->lastCallback;
        iconnection->callbackList = 0;
        iconnection->lastCallback = 0;
        pprev = 0;
        for (pcurr = list; pcurr; pcurr = pnext) {
            pnext = pcurr->pnext;
            if (pcurr->operationID == blockingOperationID || pcurr->fC == 1) {
                if (pprev)
                    pprev->pnext = pnext;
                else
                    list = pnext;
                if (last == pcurr)
                    last = pprev;
                func_02189EA0(connection, pcurr);
            } else {
                pprev = pcurr;
            }
        }
        if (iconnection->callbackList)
            iconnection->lastCallback->pnext = list;
        else
            iconnection->callbackList = list;
        iconnection->lastCallback = last;
        return 0;
    } else {
        while (iconnection->callbackList) {
            list = iconnection->callbackList;
            iconnection->callbackList = 0;
            iconnection->lastCallback = 0;
            while (list) {
                pnext = list->pnext;
                func_02189EA0(connection, list);
                list = pnext;
            }
        }
    }
    return 0;
}
