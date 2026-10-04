/*
 * function: func_0218B5A0
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
 *   func_02193488  0x02193488  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   g_021A4A58     0x021A4A58  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad[0x1F0];
    int socket;
    int state;
} GPIConnection;

extern int func_02193488(void **connection, int sock, int *state);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern char g_021A4A58[];

int func_0218B5A0(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int state;
    int result;

    if ((result = func_02193488(connection, iconnection->socket, &state)) != 0)
        return result;
    if (state == 4) {
        func_02193710((int *)connection, 0x107, (int)g_021A4A58);
        func_02189D78((int *)connection, 4, 1);
        return 4;
    }
    if (state == 0)
        return 0;
    iconnection->state = 2;
    return 0;
}
