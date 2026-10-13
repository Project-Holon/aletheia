/*
 * function: gpSetInfosA
 * address:  0x02185CB4
 * packet:   pkt_ov009_02185CB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpSetInfosA (gp.o)
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm
 *   gpiSetInfoi        0x0218CC48  arm
 *   g_021A4024         0x021A4024  data
 *
 * note: the object's DWARF names the callee gpiSetInfoi while the recovered SDK
 * catalog spells the same address gpiSetInfos (0x0218CC48).
 */

typedef struct GPIConnection GPIConnection;

extern char g_021A4024[];
extern void gpiSetErrorString(void **connection, char *errorString);
extern int gpiSetInfoi(void **connection, int info, int value);

int gpSetInfosA(void **connection, int info, int value)
{
    GPIConnection *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0)
        return 0;
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        gpiSetErrorString(connection, g_021A4024);
        return 2;
    }
    return gpiSetInfoi(connection, info, value);
}
