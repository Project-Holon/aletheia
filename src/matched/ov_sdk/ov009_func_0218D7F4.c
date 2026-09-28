/*
 * function: func_0218D7F4
 * address:  0x0218D7F4
 * packet:   pkt_ov009_0218D7F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStatusInfoKeysInit (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 *
 * symbols:
 *   func_02184144  0x02184144  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_0218D7CC  0x0218D7CC  arm  ov009
 *   g_021A4D80  0x021A4D80  data
 */

struct GPIConnection {
    char pad[0x3b4];
    void *statusInfoKeys;
};

extern void *func_02184144(int elemSize, int numElems, void (*freeFn)(void *));
extern void func_02193734(void **connection, char *errorString);
extern void func_0218D7CC(void *element);
extern char g_021A4D80[];

int func_0218D7F4(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    int result = 1;

    iconnection->statusInfoKeys = func_02184144(8, result, func_0218D7CC);
    if (iconnection->statusInfoKeys != 0)
        return 0;
    func_02193734(connection, g_021A4D80);
    return result;
}
