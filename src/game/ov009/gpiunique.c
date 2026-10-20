/*
 * file:     gpiunique.c
 * unit:     yes
 * function: gpiProcessRegisterUniqueNick, gpiProcessRegisterCdKey
 * address:  0x0219305C
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
 *   gpiCheckForError  0x0219329c  arm   ov009
 *   strncmp  0x020949f4  arm
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189d78  arm   ov009
 *   gsimalloc  0x0217eab0  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiAddCallback  0x02189dfc  arm   ov009
 *   gpiRemoveOperation  0x0218e240  arm   ov009
 *   gGpiUniqueResponseN     0x021a56c8  data
 *   gGpiUniqueErrorUnexpectedData     0x021a56d0  data
 *   gGpiUniqueErrorOutOfMemory     0x021a5700  data
 *   gGpiUniqueResponseC     0x021a5710  data
 */
typedef struct {
    int result;
} GPRegisterUniqueNickResponseArg;

#include "../types.h"

#include "gpi_types.h"

typedef struct {
    int result;
} GPRegisterCdKeyResponseArg;

#include "gpiutility.h"
#include "../arm9/msl_string_str.h"
#include "gpicallback.h"
#include "gsmemory.h"
#include "gpioperation.h"
int gpiProcessRegisterUniqueNick(void **connection, GPIOperation *operation, char *input);
int gpiProcessRegisterCdKey(void **connection, GPIOperation *operation, char *input);
extern char gGpiUniqueResponseN[];
extern char gGpiUniqueErrorUnexpectedData[];
extern char gGpiUniqueErrorOutOfMemory[];
extern char gGpiUniqueResponseC[];

/*
 * sdk:      gpiProcessRegisterUniqueNick (libdwcgsgp.TWL.HYB.a gpiunique.o)
 */
int gpiProcessRegisterUniqueNick(void **connection, GPIOperation *operation, char *input)
{
    GPICallback callback;
    GPRegisterUniqueNickResponseArg *arg;
    int __result__;

    if (gpiCheckForError(connection, input, 1))
        return 4;
    if (strncmp(input, gGpiUniqueResponseN, 4) != 0) {
        gpiSetError(connection, 1, gGpiUniqueErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback((void **)connection, __result__, 1);
        return __result__;
    }
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPRegisterUniqueNickResponseArg *)gsimalloc(sizeof(GPRegisterUniqueNickResponseArg));
        if (arg == 0) {
            gpiSetErrorString(connection, gGpiUniqueErrorOutOfMemory);
            return 1;
        }
        arg->result = 0;
        __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    gpiRemoveOperation(connection, (struct GPIOperation *)operation);
    return 0;
}

/*
 * sdk:      gpiProcessRegisterCdKey (libdwcgsgp.TWL.HYB.a gpiunique.o)
 */
int gpiProcessRegisterCdKey(void **connection, GPIOperation *operation, char *input)
{
    GPICallback callback;
    GPRegisterCdKeyResponseArg *arg;
    int __result__;

    if (gpiCheckForError(connection, input, 1))
        return 4;
    if (strncmp(input, gGpiUniqueResponseC, 4) != 0) {
        gpiSetError(connection, 1, gGpiUniqueErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback((void **)connection, __result__, 1);
        return __result__;
    }
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPRegisterCdKeyResponseArg *)gsimalloc(sizeof(GPRegisterCdKeyResponseArg));
        if (arg == 0) {
            gpiSetErrorString(connection, gGpiUniqueErrorOutOfMemory);
            return 1;
        }
        arg->result = 0;
        __result__ = gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    gpiRemoveOperation(connection, (struct GPIOperation *)operation);
    return 0;
}
