/*
 * function: gpiProcessDeleteProfle
 * address:  0x0218FDD8
 * packet:   pkt_ov009_0218FDD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessDeleteProfle (libdwcgsgp.TWL.HYB.a gpiprofile.o)
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
 *   g_021A5224     0x021a5224  data
 *   g_021A51D8     0x021a51d8  data
 *   g_021A5214     0x021a5214  data
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
} GPDeleteProfileResponseArg;

typedef struct {
    char pad[0x1a0];
    int profileid;
} GPIConnection;

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
extern char g_021A5224[];
extern char g_021A51D8[];
extern char g_021A5214[];

int gpiProcessDeleteProfle(void **connection, GPIOperation *operation, char *input)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPICallback callback;
    GPDeleteProfileResponseArg *arg;
    int __result__;

    if (gpiCheckForError((int *)connection, input, 1))
        return 4;
    if (strncmp((const u8 *)input, (const u8 *)g_021A5224, 5) != 0) {
        gpiSetError((int *)connection, 1, (int)g_021A51D8);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    callback = operation->callback;
    if (operation->callback.callback != 0) {
        arg = (GPDeleteProfileResponseArg *)gsimalloc(sizeof(GPDeleteProfileResponseArg));
        if (arg == 0) {
            gpiSetErrorString((int *)connection, (int)g_021A5214);
            return 1;
        }
        arg->profile = iconnection->profileid;
        arg->result = 0;
        __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    gpiRemoveOperation(connection, (struct GPIOperation *)operation);
    return 0;
}
