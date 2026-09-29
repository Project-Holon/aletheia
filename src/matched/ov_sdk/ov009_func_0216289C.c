/*
 * function: func_0216289C
 * address:  0x0216289C
 * packet:   pkt_ov009_0216289C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ssl_connect_try (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02162418  0x02162418  arm  ov009
 *   func_02161F98  0x02161F98  arm  ov009
 *   func_021612C8  0x021612C8  arm  ov009
 *   func_0216286C  0x0216286C  arm  ov009
 *   func_021622C0  0x021622C0  arm  ov009
 *   func_021625B8  0x021625B8  arm  ov009
 *   func_02161264  0x02161264  arm  ov009
 *   func_0215FEE0  0x0215FEE0  arm  ov009
 */


typedef struct CPSSslConnection {
    unsigned char pad0[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char resumed;              /* +0x31 */
    unsigned char pad32[0x455 - 0x32];
    unsigned char state;                /* +0x455 */
} CPSSslConnection;

typedef struct CPSSoc {
    unsigned char pad0[0xc];
    CPSSslConnection *con;              /* +0xc */
    unsigned char pad10[0x18 - 0x10];
    unsigned short port;                /* +0x18 */
    unsigned char pad1a[2];
    unsigned long ip;                   /* +0x1c */
} CPSSoc;

extern void func_02162418(CPSSoc *soc);
extern int func_02161F98(CPSSoc *soc);
extern void func_021612C8(CPSSslConnection *con);
extern int func_0216286C(CPSSoc *soc);
extern void func_021622C0(CPSSoc *soc);
extern void func_021625B8(CPSSoc *soc);
extern void func_02161264(CPSSslConnection *con);
extern void func_0215FEE0(CPSSslConnection *con, unsigned long ip, unsigned short port);

static int func_0216289C(CPSSoc *soc)
{
    CPSSslConnection *con;
    int state;

    con = soc->con;
    func_02162418(soc);
    for (;;) {
        state = func_02161F98(soc);
        if (state == 9)
            return 1;
        if (state == 4)
            break;
        if (con->resumed != 0)
            break;
    }
    if (con->resumed != 0) {
        func_021612C8(con);
        if (func_0216286C(soc) != 0)
            return 1;
        func_021622C0(soc);
    } else {
        func_021625B8(soc);
        func_02161264(con);
        if (con->cache != 0)
            func_0215FEE0(con, soc->ip, soc->port);
        func_021612C8(con);
        func_021622C0(soc);
        if (func_0216286C(soc) != 0)
            return 1;
    }
    con->state = 8;
    return 0;
}
