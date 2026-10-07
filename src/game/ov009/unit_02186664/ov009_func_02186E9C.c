/*
 * function: gpiProcess
 * address:  0x02186E9C
 * packet:   pkt_ov009_02186E9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcess (gpi.o)
 *
 * symbols:
 *   msleep                        0x0217F2BC  arm
 *   gpiCheckConnect               0x0218B5A0  arm
 *   gpiFindOperationByID          0x0218E290  arm
 *   gpiProcessConnectionManager   0x02186A0C  arm
 *   gpiProcessPeers               0x0218EFEC  arm
 *   gpiProcessSearches            0x02192E10  arm
 *   gpiFailedOpCallback           0x0218DD88  arm
 *   gpiRemoveOperation            0x0218E240  arm
 *   gpiProcessCallbacks           0x0218A0E4  arm
 *   gpiDisconnect                 0x0218B760  arm
 *   gpiReset                      0x021867E8  arm
 */

typedef struct GPIConnection GPIConnection;
typedef struct GPIOperation_s GPIOperation_s;

struct GPIOperation_s {
    char pad[0x1c];
    int field1c;
    struct GPIOperation_s *field20;
};

extern void msleep(int ms);
extern int gpiCheckConnect(void **connection);
extern int gpiFindOperationByID(void **connection, GPIOperation_s **operation, int id);
extern int gpiProcessConnectionManager(void **connection);
extern int gpiProcessPeers(void **connection);
extern int gpiProcessSearches(void **connection);
extern int gpiFailedOpCallback(void **connection, GPIOperation_s *operation);
extern void gpiRemoveOperation(void **connection, GPIOperation_s *operation);
extern int gpiProcessCallbacks(void **connection, int blockingOperationID);
extern void gpiDisconnect(void **connection, int tellServer);
extern int gpiReset(void **connection);

int gpiProcess(void **connection, int blockingOperationID)
{
    GPIConnection *iconnection;
    GPIOperation_s *operation;
    int result;
    int loop;
    int __result__;

    iconnection = (GPIConnection *)*connection;
    result = 0;

    if (*(int *)((char *)iconnection + 0x1f4) == 1) {
        do {
            result = gpiCheckConnect(connection);
            if (result == 0 && blockingOperationID != 0
                && *(int *)((char *)iconnection + 0x1f4) == 1)
                loop = 1;
            else
                loop = 0;
            if (loop)
                msleep(10);
        } while (loop);

        if (result != 0) {
            if (gpiFindOperationByID(connection, &operation, 1))
                operation->field1c = 4;
        }
    }

    if (*(int *)((char *)iconnection + 0x1f4) == 3
        || *(int *)((char *)iconnection + 0x1f4) == 2
        || *(int *)((char *)iconnection + 0x1f4) == 5) {
        if (result == 0)
            result = gpiProcessConnectionManager(connection);
        if (result == 0)
            result = gpiProcessPeers(connection);
    }
    if (result == 0)
        result = gpiProcessSearches(connection);

    operation = *(GPIOperation_s **)((char *)iconnection + 0x5c4);
    while (operation != 0) {
        if (operation->field1c == 0) {
            operation = operation->field20;
        } else {
            GPIOperation_s *op;
            gpiFailedOpCallback(connection, operation);
            op = operation;
            operation = op->field20;
            gpiRemoveOperation(connection, op);
        }
    }

    __result__ = gpiProcessCallbacks(connection, blockingOperationID);
    if (__result__ != 0)
        return __result__;
    if (*(int *)((char *)iconnection + 0x5bc) != 0) {
        gpiDisconnect(connection, 0);
        gpiReset(connection);
    }
    return result;
}
