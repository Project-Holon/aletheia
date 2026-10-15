/*
 * function: gpiStatusInfoKeysDestroy
 * address:  0x0218D840
 * packet:   pkt_ov009_0218D840
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStatusInfoKeysDestroy (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 *
 * symbols:
 *   func_021841B0  0x021841B0  arm  ov009
 */

struct GPIConnection {
    char pad[0x3b4];
    void *statusInfoKeys;
};

extern void func_021841B0(void *array);

void gpiStatusInfoKeysDestroy(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (iconnection->statusInfoKeys == 0)
        return;
    func_021841B0(iconnection->statusInfoKeys);
    iconnection->statusInfoKeys = 0;
}
