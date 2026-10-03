/*
 * function: func_02186564
 * address:  0x02186564
 * packet:   pkt_ov009_02186564
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpGetReversBuddiesList (gp.o)
 *
 * symbols:
 *   func_02193734  0x02193734  arm   ov009
 *   func_021908B0  0x021908B0  arm   ov009
 *   g_021A4010     0x021A4010  data  ov009
 *   g_021A4024     0x021A4024  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad0[0x108];
    int f108;
    unsigned char pad1[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection;

typedef struct GPGetReverseBuddiesListResponseArg {
    int a;
    int b;
    int c;
} GPGetReverseBuddiesListResponseArg;

typedef void (*GPCallback)(void **, void *, void *);

extern void func_02193734(void **connection, char *errorString);
extern int func_021908B0(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param);
extern char g_021A4010[];
extern char g_021A4024[];

int func_02186564(void **connection, int *targets, int numOfTargets, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection *iconnection;

    if (connection == 0 || *connection == 0)
        return 2;
    if (callback == 0) {
        func_02193734(connection, g_021A4010);
        return 2;
    }
    iconnection = (GPIConnection *)*connection;
    if (iconnection->f1F4 == 4) {
        func_02193734(connection, g_021A4024);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPGetReverseBuddiesListResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    return func_021908B0(connection, targets, numOfTargets, blocking, callback, param);
}
