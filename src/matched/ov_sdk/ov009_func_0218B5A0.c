/*
 * function: gpiCheckConnect
 * address:  0x0218B5A0
 * packet:   pkt_ov009_0218B5A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiCheckConnect (gpiconnect.o)
 *
 * symbols:
 *   gpiCheckSocketConnect  0x02193488  arm   ov009
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   g_021A4A58     0x021A4A58  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad[0x1F0];
    int socket;
    int state;
} GPIConnection;

extern int gpiCheckSocketConnect(int *connection, int sock, int *state);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern char g_021A4A58[];

int gpiCheckConnect(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int state;
    int result;

    if ((result = gpiCheckSocketConnect((int *)connection, iconnection->socket, &state)) != 0)
        return result;
    if (state == 4) {
        gpiSetError((int *)connection, 0x107, (int)g_021A4A58);
        gpiCallErrorCallback((int *)connection, 4, 1);
        return 4;
    }
    if (state == 0)
        return 0;
    iconnection->state = 2;
    return 0;
}
