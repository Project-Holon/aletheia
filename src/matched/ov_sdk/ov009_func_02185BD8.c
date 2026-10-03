/*
 * function: func_02185BD8
 * address:  0x02185BD8
 * packet:   pkt_ov009_02185BD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpGetInfo (gp.o)
 *
 * symbols:
 *   func_02193734  0x02193734  arm   ov009
 *   func_0218D4A4  0x0218D4A4  arm   ov009
 *   g_021A4010     0x021A4010  data  ov009
 *   g_021A4024     0x021A4024  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad0[0x108];
    int f108;
    unsigned char pad1[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection;

typedef struct GPGetInfoResponseArg {
    unsigned int w[0x81];
} GPGetInfoResponseArg;

typedef void (*GPCallback)(void **, void *, void *);

extern void func_02193734(void **connection, char *errorString);
extern int func_0218D4A4(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
extern char g_021A4010[];
extern char g_021A4024[];

int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection *)*connection) == 0 || profile == 0)
        return 2;
    if (callback == 0) {
        func_02193734(connection, g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPGetInfoResponseArg arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    if (iconnection->f1F4 == 4) {
        func_02193734(connection, g_021A4024);
        return 2;
    }
    return func_0218D4A4(connection, profile, checkCache, blocking, callback, param);
}
