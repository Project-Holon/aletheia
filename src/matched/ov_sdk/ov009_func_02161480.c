/*
 * function: rcv_client_key_exchange
 * address:  0x02161480
 * packet:   pkt_ov009_02161480
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      rcv_client_key_exchange (ssl.o)
 *
 * symbols:
 *   decrypt_premaster_secret  0x02160F80  arm
 *   create_master_secret      0x02161264  arm
 *   cache_session             0x0215FEE0  arm
 *   create_key_block          0x021612C8  arm
*/

struct _CPSSslConnection {
    char pad0[0x455];
    unsigned char f455;
    char pad1[0x81c - 0x455 - 1];
    void *f81c;
};

extern void decrypt_premaster_secret(unsigned char *d, unsigned char *s, void *k);
extern void create_master_secret(struct _CPSSslConnection *con);
extern void cache_session(struct _CPSSslConnection *con, unsigned long ip,
                          unsigned short port);
extern void create_key_block(struct _CPSSslConnection *con);

static void rcv_client_key_exchange(struct _CPSSslConnection *con, unsigned char *s)
{
    decrypt_premaster_secret((unsigned char *)con, s, con->f81c);
    create_master_secret(con);
    cache_session(con, 0, 0);
    create_key_block(con);
    con->f455 = 5;
}
