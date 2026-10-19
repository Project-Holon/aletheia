/*
 * function: ssl_connect_try
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
 *   parse_record  0x02161F98  arm  ov009
 *   create_key_block  0x021612C8  arm  ov009
 *   mustget_change_cipher_spec_and_finished  0x0216286C  arm  ov009
 *   send_change_cipher_spec_and_finished  0x021622C0  arm  ov009
 *   send_client_key_exchange  0x021625B8  arm  ov009
 *   create_master_secret  0x02161264  arm  ov009
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
extern int parse_record(CPSSoc *soc);
extern void create_key_block(CPSSslConnection *con);
extern int mustget_change_cipher_spec_and_finished(CPSSoc *soc);
extern void send_change_cipher_spec_and_finished(CPSSoc *soc);
extern void send_client_key_exchange(CPSSoc *soc);
extern void create_master_secret(CPSSslConnection *con);
extern void func_0215FEE0(CPSSslConnection *con, unsigned long ip, unsigned short port);

static int ssl_connect_try(CPSSoc *soc)
{
    CPSSslConnection *con;
    int state;

    con = soc->con;
    func_02162418(soc);
    for (;;) {
        state = parse_record(soc);
        if (state == 9)
            return 1;
        if (state == 4)
            break;
        if (con->resumed != 0)
            break;
    }
    if (con->resumed != 0) {
        create_key_block(con);
        if (mustget_change_cipher_spec_and_finished(soc) != 0)
            return 1;
        send_change_cipher_spec_and_finished(soc);
    } else {
        send_client_key_exchange(soc);
        create_master_secret(con);
        if (con->cache != 0)
            func_0215FEE0(con, soc->ip, soc->port);
        create_key_block(con);
        send_change_cipher_spec_and_finished(soc);
        if (mustget_change_cipher_spec_and_finished(soc) != 0)
            return 1;
    }
    con->state = 8;
    return 0;
}
