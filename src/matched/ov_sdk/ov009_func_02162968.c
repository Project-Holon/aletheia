/*
 * function: func_02162968
 * address:  0x02162968
 * packet:   pkt_ov009_02162968
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SslConnect (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   CPSi_TcpConnectRaw  0x0215ABB0  arm  ov009
 *   func_02163C9C  0x02163C9C  arm  ov009
 *   func_021633F0  0x021633F0  arm  ov009
 *   func_0216289C  0x0216289C  arm  ov009
 */


typedef struct CPSSslConnection {
    unsigned char pad0[0x1d4];
    int f1d4;                           /* +0x1d4 */
    unsigned char pad1d8[0x2ec - 0x1d8];
    unsigned char sha1[0x3a4 - 0x2ec];  /* +0x2ec */
    unsigned char md5[0x454 - 0x3a4];   /* +0x3a4 */
    unsigned char f454;                 /* +0x454 */
    unsigned char f455;                 /* +0x455 */
} CPSSslConnection;

typedef struct CPSSoc {
    unsigned char pad0[8];
    unsigned char state;                /* +0x8 */
    unsigned char pad9[3];
    CPSSslConnection *con;              /* +0xc */
} CPSSoc;

struct Soc;
extern unsigned long CPSi_TcpConnectRaw(struct Soc *soc);
extern void func_02163C9C(void *ctx);
extern void func_021633F0(void *ctx);
extern int func_0216289C(CPSSoc *soc);

unsigned long func_02162968(CPSSoc *soc)
{
    int result;
    CPSSslConnection *con;

    con = soc->con;
    if (soc->state != 4) {
        if (CPSi_TcpConnectRaw((struct Soc *)soc) != 0)
            return 1;
    }
    con->f455 = 0;
    con->f1d4 = 0;
    con->f454 = 0;
    func_02163C9C(con->sha1);
    func_021633F0(con->md5);
    return func_0216289C(soc);
}
