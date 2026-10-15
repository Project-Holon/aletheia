/*
 * function: gpiProcessNewProfile
 * address:  0x0218FB68
 * packet:   pkt_ov009_0218FB68
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessNewProfile (libdwcgsgp.TWL.HYB.a gpiprofile.o)
 *
 * symbols:
 *   gpiCheckForError  0x0219329c  arm   ov009
 *   strncmp  0x020949f4  arm
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189d78  arm   ov009
 *   gpiValueForKey  0x02193418  arm   ov009
 *   atoi  0x020964e0  arm
 *   gsimalloc  0x0217eab0  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiAddCallback  0x02189dfc  arm   ov009
 *   gpiRemoveOperation  0x0218e240  arm   ov009
 *   gGpiProfileResponsePr     0x021a51d0  data
 *   gGpiProfileErrorUnexpectedData     0x021a51d8  data
 *   gGpiProfileKeyProfileId     0x021a5208  data
 *   gGpiProfileErrorOutOfMemory     0x021a5214  data
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
    int profile;
} GPNewProfileResponseArg;

struct GPIOperation;
extern int gpiCheckForError(int *connection, const char *input, int fatal);
typedef unsigned char  u8;
extern int strncmp(const u8 *s1, const u8 *s2, unsigned int n);
typedef unsigned int   u32;
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int atoi(u32 a0);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(int *p, int b);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void gpiRemoveOperation(void **connection, struct GPIOperation *operation);
extern char gGpiProfileResponsePr[];
extern char gGpiProfileErrorUnexpectedData[];
extern char gGpiProfileKeyProfileId[];
extern char gGpiProfileErrorOutOfMemory[];

int gpiProcessNewProfile(void **connection, GPIOperation *operation, char *input)
{
    char buffer[16];
    int pid;
    GPICallback callback;
    GPNewProfileResponseArg *arg;
    int __result__;

    if (gpiCheckForError((int *)connection, input, 1))
        return 4;
    if (strncmp((const u8 *)input, (const u8 *)gGpiProfileResponsePr, 5) != 0) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback((int *)connection, __result__, 1);
        return __result__;
    }
    if (!gpiValueForKey(input, gGpiProfileKeyProfileId, buffer, 16)) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback((int *)connection, __result__, 1);
        return __result__;
    }
    pid = atoi((u32)buffer);
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPNewProfileResponseArg *)gsimalloc(sizeof(GPNewProfileResponseArg));
        if (arg == 0) {
            gpiSetErrorString((int *)connection, (int)gGpiProfileErrorOutOfMemory);
            return 1;
        }
        arg->profile = pid;
        arg->result = 0;
        __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    gpiRemoveOperation(connection, (struct GPIOperation *)operation);
    return 0;
}
