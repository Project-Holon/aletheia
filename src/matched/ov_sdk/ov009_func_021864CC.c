/*
 * function: func_021864CC
 * address:  0x021864CC
 * packet:   pkt_ov009_021864CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpSendBuddyMessageA (gp.o)
 *
 * symbols:
 *   func_02193734  0x02193734  arm   ov009
 *   func_021889A0  0x021889A0  arm   ov009
 *   g_021A4024     0x021A4024  data  ov009
 *   g_021A4118     0x021A4118  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad0[0x108];
    int f108;
    unsigned char pad1[0x1F4 - 0x10C];
    int f1F4;
} GPIConnection;

extern void func_02193734(int *p, int b);
extern int func_021889A0(void **connection, int profileid, int type, char *message,
                         int sendOption, void *peerOp);
extern char g_021A4024[];
extern char g_021A4118[];

int func_021864CC(void **connection, int profile, char *message)
{
    GPIConnection *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection *)*connection) == 0)
        return 2;
    if (iconnection->f108 != 0)
        return 0;
    if (iconnection->f1F4 == 4) {
        func_02193734((int *)connection, (int)g_021A4024);
        return 2;
    }
    if (message == 0) {
        func_02193734((int *)connection, (int)g_021A4118);
        return 2;
    }
    return func_021889A0(connection, profile, 1, message, 0, 0);
}
