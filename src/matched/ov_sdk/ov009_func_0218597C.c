/*
 * function: gpSetCallback
 * address:  0x0218597C
 * packet:   pkt_ov009_0218597C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpSetCallback (gp.o)
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm
 *   g_021A4000         0x021A4000  data
 */

typedef struct GPIConnection GPIConnection;

extern char g_021A4000[];
extern void gpiSetErrorString(void **connection, char *errorString);

int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param)
{
    GPIConnection *iconnection;

    if (!connection || !*connection)
        return 2;
    iconnection = (GPIConnection *)*connection;
    if ((unsigned int)func < 9) {
        *(void **)((char *)iconnection + func * 8 + 0x1a8) = (void *)callback;
        *(void **)((char *)iconnection + func * 8 + 0x1ac) = param;
        return 0;
    }
    gpiSetErrorString(connection, g_021A4000);
    return 2;
}
