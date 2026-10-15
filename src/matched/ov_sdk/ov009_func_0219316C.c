/*
 * function: gpiProcessRegisterCdKey
 * address:  0x0219316C
 * packet:   pkt_ov009_0219316C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessRegisterCdKey (libdwcgsgp.TWL.HYB.a gpiunique.o)
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
 *   gGpiUniqueResponseC     0x021a5710  data
 *   gGpiUniqueErrorUnexpectedData     0x021a56d0  data
 *   gGpiUniqueErrorOutOfMemory     0x021a5700  data
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
} GPIOperation;

typedef struct {
    int result;
} GPRegisterCdKeyResponseArg;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct GPIOperation;
extern int gpiCheckForError(int *connection, const char *input, int fatal);
extern int strncmp(const u8 *s1, const u8 *s2, u32 n);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(int *p, int b);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void gpiRemoveOperation(void **connection, struct GPIOperation *operation);
extern char gGpiUniqueResponseC[];
extern char gGpiUniqueErrorUnexpectedData[];
extern char gGpiUniqueErrorOutOfMemory[];

int gpiProcessRegisterCdKey(void **connection, GPIOperation *operation, char *input)
{
    GPICallback callback;
    GPRegisterCdKeyResponseArg *arg;
    int __result__;

    if (gpiCheckForError((int *)connection, input, 1))
        return 4;
    if (strncmp((const u8 *)input, (const u8 *)gGpiUniqueResponseC, 4) != 0) {
        gpiSetError((int *)connection, 1, (int)gGpiUniqueErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback((int *)connection, __result__, 1);
        return __result__;
    }
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPRegisterCdKeyResponseArg *)gsimalloc(sizeof(GPRegisterCdKeyResponseArg));
        if (arg == 0) {
            gpiSetErrorString((int *)connection, (int)gGpiUniqueErrorOutOfMemory);
            return 1;
        }
        arg->result = 0;
        __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    gpiRemoveOperation(connection, (struct GPIOperation *)operation);
    return 0;
}
