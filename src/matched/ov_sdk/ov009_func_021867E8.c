/*
 * function: func_021867E8
 * address:  0x021867E8
 * packet:   pkt_ov009_021867E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiReset (libdwcgsgp.TWL.HYB.a gpi.o)
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_0218D840  0x0218D840  arm  ov009
 *   func_0218D7F4  0x0218D7F4  arm  ov009
 *   func_02186788  0x02186788  arm  ov009
 *   func_0218E240  0x0218E240  arm  ov009
 *   func_0218FFFC  0x0218FFFC  arm  ov009
 *   func_021867C0  0x021867C0  arm  ov009
 */

typedef struct GPIConnection {
    char pad000[0x110];
    char errorString;              /* 0x110 */
    char pad111[0x1E];
    char f12F;                     /* 0x12F */
    char pad130[0x14];
    char f144;                     /* 0x144 */
    char pad145[0x53];
    int f198;                      /* 0x198 */
    int f19C;                      /* 0x19C */
    int f1A0;                      /* 0x1A0 */
    char pad1A4[0x4C];
    int cmSocket;                  /* 0x1F0 */
    int connectState;              /* 0x1F4 */
    char *buf1F8;                  /* 0x1F8 */
    int size1FC;                   /* 0x1FC */
    int len200;                    /* 0x200 */
    int pos204;                    /* 0x204 */
    char *buf208;                  /* 0x208 */
    int len20C;                    /* 0x20C */
    char *buf210;                  /* 0x210 */
    int size214;                   /* 0x214 */
    int len218;                    /* 0x218 */
    int pos21C;                    /* 0x21C */
    char pad220[0x14];
    int f234;                      /* 0x234 */
    int f238;                      /* 0x238 */
    int f23C;                      /* 0x23C */
    char pad240[0x178];
    char f3B8;                     /* 0x3B8 */
    char pad3B9[0xFF];
    char f4B8;                     /* 0x4B8 */
    char pad4B9[0x103];
    int f5BC;                      /* 0x5BC */
    char pad5C0[0x4];
    void *operationList;           /* 0x5C4 */
    char pad5C8[0x8];
    int f5D0;                      /* 0x5D0 */
    int f5D4;                      /* 0x5D4 */
    int f5D8;                      /* 0x5D8 */
    char pad5DC[0x8];
    char *buf5E4;                  /* 0x5E4 */
    int size5E8;                   /* 0x5E8 */
    int len5EC;                    /* 0x5EC */
    int pos5F0;                    /* 0x5F0 */
    char *buf5F4;                  /* 0x5F4 */
    int size5F8;                   /* 0x5F8 */
    int len5FC;                    /* 0x5FC */
    int pos600;                    /* 0x600 */
    char pad604[0x30];
    int f634;                      /* 0x634 */
} GPIConnection;

typedef void *GPConnection;
typedef struct GPIProfile GPIProfile;

extern void func_0217EAE0(void *ptr);
extern void func_0218D840(GPConnection *connection);
extern int func_0218D7F4(GPConnection *connection);
extern void func_02186788(GPConnection *connection);
extern void func_0218E240(GPConnection *connection, void *operation);
extern int func_0218FFFC(GPConnection *connection, int (*func)(GPConnection *, GPIProfile *, void *), void *data);
extern int func_021867C0(GPConnection *connection, GPIProfile *profile, void *data);

int func_021867E8(GPConnection *connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int result;

    iconnection->errorString = '\0';
    iconnection->f12F = '\0';
    iconnection->f144 = '\0';
    iconnection->cmSocket = -1;
    iconnection->connectState = 0;
    iconnection->len200 = 0;
    iconnection->pos204 = 0;
    iconnection->size1FC = 0;
    func_0217EAE0(iconnection->buf1F8);
    iconnection->buf1F8 = 0;
    iconnection->buf1F8 = 0;
    iconnection->len20C = 0;
    func_0217EAE0(iconnection->buf208);
    iconnection->buf208 = 0;
    iconnection->buf208 = 0;
    iconnection->len218 = 0;
    iconnection->pos21C = 0;
    iconnection->size214 = 0;
    func_0217EAE0(iconnection->buf210);
    iconnection->buf210 = 0;
    iconnection->buf210 = 0;
    iconnection->len5EC = 0;
    iconnection->pos5F0 = 0;
    iconnection->size5E8 = 0;
    func_0217EAE0(iconnection->buf5E4);
    iconnection->buf5E4 = 0;
    iconnection->buf5E4 = 0;
    iconnection->len5FC = 0;
    iconnection->pos600 = 0;
    iconnection->size5F8 = 0;
    func_0217EAE0(iconnection->buf5F4);
    iconnection->buf5F4 = 0;
    iconnection->buf5F4 = 0;

    func_0218D840(connection);
    result = func_0218D7F4((GPConnection *)&iconnection);
    if (result != 0)
    {
        func_02186788((GPConnection *)&iconnection);
        return result;
    }

    iconnection->f234 = 2;
    while (iconnection->operationList != 0)
        func_0218E240(connection, iconnection->operationList);
    iconnection->operationList = 0;
    iconnection->f5D0 = 0;
    iconnection->f5D4 = 0;
    func_0218FFFC(connection, (int (*)(GPConnection *, GPIProfile *, void *))func_021867C0, 0);
    iconnection->f19C = 0;
    iconnection->f1A0 = 0;
    iconnection->f198 = 0;
    iconnection->f238 = 0;
    iconnection->f5BC = 0;
    iconnection->f5D8 = 0;
    iconnection->f23C = -1;
    iconnection->f3B8 = '\0';
    iconnection->f4B8 = '\0';
    iconnection->f634 = 0;
    return 0;
}
