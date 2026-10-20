/*
 * file:     gpioperation.c
 * unit:     yes
 * function: gpiFailedOpCallback, gpiAddOperation, gpiDestroyOperation, gpiRemoveOperation, gpiFindOperationByID, gpiOperationsAreBlocking, gpiProcessOperation
 * address:  0x0218DD88
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
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   gpiAddCallback  0x02189DFC  arm  ov009
 *   gGpiOperationErrorOutOfMemory     0x021A4DF8  data
 *   gsimalloc          0x0217EAB0  arm
 *   gpiSetErrorString  0x02193734  arm
 *   shutdown  0x0217EB9C  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   gpiProcessConnect  0x0218AE9C  arm  ov009
 *   gpiProcessNewProfile  0x0218FB68  arm  ov009
 *   gpiProcessDeleteProfle  0x0218FDD8  arm  ov009
 *   gpiProcessGetInfo  0x0218BDB8  arm  ov009
 *   gpiProcessRegisterUniqueNick  0x0219305C  arm  ov009
 *   gpiProcessRegisterCdKey  0x0219316C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gGpiOperationDebugInvalidTypeFmt  0x021A4E08  data
 */
extern void *__builtin__clear(void *dest, unsigned long size);
typedef struct GPRegisterUniqueNickResponseArg {
    int result;
} GPRegisterUniqueNickResponseArg;

typedef struct GPRegisterCdKeyResponseArg {
    int result;
} GPRegisterCdKeyResponseArg;

#define GAME_TYPES_U32_LONG
#include "../types.h"

#include "gpi_types.h"

#include "gsmemory.h"
#include "gpiutility.h"
typedef unsigned int size_t;
#include "../arm9/msl_string_mem.h"
#include "gpicallback.h"
#include "gsplatformsocket.h"
#include "gpiconnect.h"
#include "gpiprofile.h"
typedef int _GPResult;
#include "gpiinfo.h"
#include "gpiunique.h"
#include "gsdebug.h"
int gpiFailedOpCallback(void **connection, const GPIOperation *operation);
int gpiAddOperation(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
/*
 * sdk: gpiDestroyOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void gpiDestroyOperation(void **connection, GPIOperation *operation);
/*
 * sdk: gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void gpiRemoveOperation(void **connection, GPIOperation *operation);
/*
 * sdk: gpiFindOperationByID (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int gpiFindOperationByID(void **connection, GPIOperation **operation, int id);
/*
 * Walks the +0x5c4 list; true as soon as a node has a non-zero +8 word and * a first word other than 3.
 */
int gpiOperationsAreBlocking(char *p);
/*
 * sdk: gpiProcessOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int gpiProcessOperation(void **connection, GPIOperation *operation, char *input);
extern char gGpiOperationErrorOutOfMemory[];
extern char gGpiOperationDebugInvalidTypeFmt[];

/*
 * sdk:      gpiFailedOpCallback (libdwcgsgp.TWL.HYB.a gpioperation.o)
 *
 * Dispatches a completed GSI GP operation: allocates the response struct for
 * the operation type, zeroes it, copies operation->result into it and calls
 * gpiAddCallback to hand it to the application callback.
 *
 * The 60-byte residue in cases 1/4/5/6 was the load of `operation->result`
 * trading places with the tail of the inline zeroing store run. Declaring the
 * `operation` parameter (and the matching parameter of gpiAddCallback)
 * `const GPIOperation *` lets the scheduler hoist the load through the
 * otherwise-aliasing stores. Same idiom as
 * docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/gpiFailedOpCallback.c  *     --func gpiFailedOpCallback --addr 0x0218DD88 --region ov009 --arm --lang c99 --diff
 */
int gpiFailedOpCallback(void **connection, const GPIOperation *operation)
{
    GPICallback callback;
    GPIConnection *iconnection;

    iconnection = (GPIConnection *)*connection;
    callback = operation->callback;
    if (callback.callback) {
        switch (operation->type) {
        case 0: {
            GPConnectResponseArg *arg;
            arg = (GPConnectResponseArg *)gsimalloc(sizeof(GPConnectResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            MSL_C_LIB_MemsetPtr(arg, 0, sizeof(GPConnectResponseArg));
            arg->result = operation->result;
            if (iconnection->errorCode == 0x201) {
                arg->profile = iconnection->profileid;
                iconnection->profileid = 0;
            }
            {
                int __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 1: {
            GPNewProfileResponseArg *arg;
            arg = (GPNewProfileResponseArg *)gsimalloc(sizeof(GPNewProfileResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPNewProfileResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 5: {
            GPDeleteProfileResponseArg *arg;
            arg = (GPDeleteProfileResponseArg *)gsimalloc(sizeof(GPDeleteProfileResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPDeleteProfileResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 2: {
            GPGetInfoResponseArg *arg;
            arg = (GPGetInfoResponseArg *)gsimalloc(sizeof(GPGetInfoResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            MSL_C_LIB_MemsetPtr(arg, 0, sizeof(GPGetInfoResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 3: {
            GPProfileSearchResponseArg *arg;
            arg = (GPProfileSearchResponseArg *)gsimalloc(sizeof(GPProfileSearchResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPProfileSearchResponseArg));
            arg->result = operation->result;
            arg->matches = 0;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 4: {
            GPRegisterUniqueNickResponseArg *arg;
            arg = (GPRegisterUniqueNickResponseArg *)gsimalloc(sizeof(GPRegisterUniqueNickResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPRegisterUniqueNickResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }

        case 6: {
            GPRegisterCdKeyResponseArg *arg;
            arg = (GPRegisterCdKeyResponseArg *)gsimalloc(sizeof(GPRegisterCdKeyResponseArg));
            if (arg == 0) {
                gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
                return 1;
            }
            __builtin__clear(arg, sizeof(GPRegisterCdKeyResponseArg));
            arg->result = operation->result;
            {
                int __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
                if (__result__ != 0)
                    return __result__;
            }
            break;
        }
        }
    }

    return 0;
}

int gpiAddOperation(void **connection, int type, void *data,
                    GPIOperation **op, int blocking,
                    void (*callback)(void **, void *, void *), void *param)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIOperation *operation;

    operation = (GPIOperation *)gsimalloc(0x24);
    if (operation == 0) {
        gpiSetErrorString(connection, gGpiOperationErrorOutOfMemory);
        return 1;
    }
    operation->type = type;
    operation->data = data;
    operation->blocking = blocking;
    operation->state = 0;
    if (type == 0) {
        operation->id = 1;
    } else {
        operation->id = iconnection->nextOperationID++;
        if (iconnection->nextOperationID < 2)
            iconnection->nextOperationID = 2;
    }
    operation->result = 0;
    operation->callback.callback = callback;
    operation->callback.param = param;
    operation->pnext = iconnection->operationList;
    iconnection->operationList = operation;
    *op = operation;
    return 0;
}

/*
 * sdk:      gpiDestroyOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void gpiDestroyOperation(void **connection, GPIOperation *operation)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    if (operation->type == 3) {
        struct GPISearchData *data = (struct GPISearchData *)operation->data;

        iconnection->numSearches--;
        shutdown(data->sock, 2);
        closesocket(data->sock);
        gsifree(data->outputBuffer.buffer);
        data->outputBuffer.buffer = 0;
        gsifree(data->inputBuffer.buffer);
        data->inputBuffer.buffer = 0;
    }
    gsifree(operation->data);
    operation->data = 0;
    gsifree(operation);
}

/*
 * sdk:      gpiRemoveOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
void gpiRemoveOperation(void **connection, GPIOperation *operation)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIOperation *pcurr;
    GPIOperation *pprev = 0;

    for (pcurr = iconnection->operationList; pcurr != 0; pcurr = pcurr->pnext) {
        if (pcurr == operation) {
            if (pprev == 0)
                iconnection->operationList = pcurr->pnext;
            else
                pprev->pnext = operation->pnext;
            gpiDestroyOperation(connection, operation);
            return;
        }
        pprev = pcurr;
    }
}

/*
 * sdk:      gpiFindOperationByID (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int gpiFindOperationByID(void **connection, GPIOperation **operation, int id)
{
    GPIOperation *op;

    for (op = ((GPIConnection *)*connection)->operationList; op != 0; op = op->pnext) {
        if (op->id == id) {
            if (operation != 0)
                *operation = op;
            return 1;
        }
    }
    if (operation != 0)
        *operation = 0;
    return 0;
}

/*
 * Walks the +0x5c4 list; true as soon as a node has a non-zero +8 word and
 * a first word other than 3.
 */
int gpiOperationsAreBlocking(char *p)
{
    char *q = *(char **)(*(char **)p + 0x5c4);

    while (q != 0) {
        if (*(int *)(q + 8) != 0 && *(int *)q != 3) return 1;
        q = *(char **)(q + 0x20);
    }
    return 0;
}

/*
 * sdk:      gpiProcessOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int gpiProcessOperation(void **connection, GPIOperation *operation, char *input)
{
    int result = 0;

    switch (operation->type) {
    case 0:
        result = gpiProcessConnect(connection, (GPIOperation *)operation, input);
        break;
    case 1:
        result = gpiProcessNewProfile(connection, (GPIOperation *)operation, input);
        break;
    case 5:
        result = gpiProcessDeleteProfle(connection, (GPIOperation *)operation, input);
        break;
    case 2:
        result = gpiProcessGetInfo(connection, (GPIOperation *)operation, input);
        break;
    case 4:
        result = gpiProcessRegisterUniqueNick(connection, (GPIOperation *)operation, input);
        break;
    case 6:
        result = gpiProcessRegisterCdKey(connection, (GPIOperation *)operation, input);
        break;
    default:
        gsDebugFormat((int)1, (int)4, 1, gGpiOperationDebugInvalidTypeFmt, operation->type);
        break;
    }
    if (result != 0)
        operation->result = result;
    return result;
}
