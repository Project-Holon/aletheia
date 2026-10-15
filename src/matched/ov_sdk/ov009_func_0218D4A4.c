/*
 * function: gpiGetInfo
 * address:  0x0218D4A4
 * packet:   pkt_ov009_0218D4A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiGetInfo (gpiinfo.o)
 *
 * symbols:
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiInfoCacheToArg  0x0218BBDC  arm   ov009
 *   func_0218E114  0x0218E114  arm   ov009
 *   gpiAddCallback  0x02189DFC  arm   ov009
 *   gpiRemoveOperation  0x0218E240  arm   ov009
 *   func_0218D40C  0x0218D40C  arm   ov009
 *   func_02186E9C  0x02186E9C  arm   ov009
 *   gGpiInfoErrorOutOfMemory     0x021A4BE4  data
 */

typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    GPICallback callback;
    int state;
    int id;
    int result;
    struct GPIOperation_s *pnext;
} GPIOperation;

typedef struct GPIProfile {
    int profileId;
    int userId;
    void *buddyStatus;
    void *buddyStatusInfo;
    void *cache;
} GPIProfile;

typedef struct GPGetInfoResponseArg {
    int result;
    int profile;
    char rest[0x204 - 8];
} GPGetInfoResponseArg;

typedef struct GPIConnection {
    char pad0[0x100];
    int infoCaching;
} GPIConnection;

extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(int *p, int b);
struct GPIInfoCache;
extern void gpiInfoCacheToArg(struct GPIInfoCache *cache, struct GPGetInfoResponseArg *arg);
extern int func_0218E114(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
struct GPIOperation;
extern void gpiRemoveOperation(void **connection, struct GPIOperation *operation);
extern int func_0218D40C(void **connection, int profileid, int operationid);
extern int func_02186E9C(void **connection, int blockingOperationID);
extern char gGpiInfoErrorOutOfMemory[];

int gpiGetInfo(void **connection, int profile, int checkCache, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIProfile *pProfile;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIOperation *operation = 0;
    int useCache;
    int result;
    int id;

    useCache = (checkCache == 1) ? 1 : 0;
    if (!iconnection->infoCaching)
        useCache = 0;

    if (callback && useCache) {
        if (func_0218FD9C(connection, profile, &pProfile) && pProfile->cache) {
            GPICallback gpiCallback;
            GPGetInfoResponseArg *arg;

            arg = (GPGetInfoResponseArg *)gsimalloc(sizeof(GPGetInfoResponseArg));
            if (arg == 0) {
                gpiSetErrorString((int *)connection, (int)gGpiInfoErrorOutOfMemory);
                return 1;
            }
            gpiInfoCacheToArg(pProfile->cache, arg);
            arg->result = 0;
            arg->profile = profile;
            gpiCallback.callback = callback;
            gpiCallback.param = param;
            { int __result__ = func_0218E114(connection, 2, 0, &operation, 1, callback, param);
              if (__result__ != 0) return __result__; }
            id = operation->id;
            { int __result__ = gpiAddCallback(connection, gpiCallback, arg, operation, 0);
              if (__result__ != 0) return __result__; }
            gpiRemoveOperation(connection, (struct GPIOperation *)operation);
            goto done;
        }
    }
    { int __result__ = func_0218E114(connection, 2, 0, &operation, blocking, callback, param);
      if (__result__ != 0) return __result__; }
    id = operation->id;
    { int __result__ = func_0218D40C(connection, profile, id);
      if (__result__ != 0) return __result__; }
done:
    if (blocking) {
        int __result__ = func_02186E9C(connection, id);
        if (__result__ != 0) return __result__;
    }
    return 0;
}
