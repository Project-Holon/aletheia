/*
 * file:     unit_0215FDA4_p11.c
 * unit:     yes
 * function: func_02161480, func_021614BC, func_02161598
 * address:  0x02161480
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   decrypt_premaster_secret  0x02160F80  arm
 *   create_master_secret      0x02161264  arm
 *   cache_session             0x0215FEE0  arm
 *   create_key_block          0x021612C8  arm
 *   func_02163438  0x02163438  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_021634F0  0x021634F0  arm  ov009
 *   func_021633F0  0x021633F0  arm  ov009
 *   g_021A1D98     0x021A1D98  data
 *   g_021A1DA0     0x021A1DA0  data
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   func_02163DA8  0x02163DA8  arm  ov009
 *   func_02163C9C  0x02163C9C  arm  ov009
 */
struct _CPSSslConnection_02161480 {
    char pad0[0x455];
    unsigned char f455;
    char pad1[0x81c - 0x455 - 1];
    void *f81c;
};

struct _CPSSslConnection_021614BC {
    unsigned char master_secret[48];
    char pad0[0x3a4 - 0x30];
    unsigned char md5_hash[0x58];
    char pad1[0x454 - 0x3fc];
    unsigned char server;
};

struct _CPSSslConnection_02161598 {
    unsigned char master_secret[48];
    char pad0[0x2ec - 0x30];
    unsigned char sha1_hash[0x5c];
    char pad1[0x454 - 0x348];
    unsigned char server;
};

extern void decrypt_premaster_secret(unsigned char *d, unsigned char *s, void *k);
extern void create_master_secret(struct _CPSSslConnection_02161480 *con);
extern void cache_session(struct _CPSSslConnection_02161480 *con, unsigned long ip,
                          unsigned short port);
extern void create_key_block(struct _CPSSslConnection_02161480 *con);
extern void func_02163438(void *ctx, void *data0, int datalen);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_021634F0(void *ctx, unsigned char *digest);
extern void func_021633F0(void *ctx);
extern void func_02163CF0(void *ctx, void *data0, int datalen);
extern void func_02163DA8(void *ctx, unsigned char *digest);
extern void func_02163C9C(void *ctx);
void func_021614BC(struct _CPSSslConnection_021614BC *con, unsigned char *d, int flag);
void func_02161598(struct _CPSSslConnection_02161598 *con, unsigned char *d, int flag);
extern int g_021A1D98;
extern int g_021A1DA0;


static void rcv_client_key_exchange(struct _CPSSslConnection_02161480 *con, unsigned char *s)
{
    decrypt_premaster_secret((unsigned char *)con, s, con->f81c);
    create_master_secret(con);
    cache_session(con, 0, 0);
    create_key_block(con);
    con->f455 = 5;
}


/*
 * sdk:      finished_md5 (ssl.o)
 */
void func_021614BC(struct _CPSSslConnection_021614BC *con, unsigned char *d, int flag)
{
    unsigned char tmp[48];
    unsigned char *p = con->md5_hash;

    if ((con->server ^ flag) != 0)
        func_02163438(p, &g_021A1D98, 4);
    else
        func_02163438(p, &g_021A1DA0, 4);
    func_02163438(p, con->master_secret, 48);
    func_02082BCC(tmp, 0x36, 48);
    func_02163438(p, tmp, 48);
    func_021634F0(p, d);
    func_021633F0(p);
    func_02163438(p, con->master_secret, 48);
    func_02082BCC(tmp, 0x5c, 48);
    func_02163438(p, tmp, 48);
    func_02163438(p, d, 16);
    func_021634F0(p, d);
}


/*
 * sdk:      finished_sha1 (ssl.o)
 */
void func_02161598(struct _CPSSslConnection_02161598 *con, unsigned char *d, int flag)
{
    unsigned char tmp[40];
    unsigned char *p = con->sha1_hash;

    if ((con->server ^ flag) != 0)
        func_02163CF0(p, &g_021A1D98, 4);
    else
        func_02163CF0(p, &g_021A1DA0, 4);
    func_02163CF0(p, con->master_secret, 48);
    func_02082BCC(tmp, 0x36, 40);
    func_02163CF0(p, tmp, 40);
    func_02163DA8(p, d);
    func_02163C9C(p);
    func_02163CF0(p, con->master_secret, 48);
    func_02082BCC(tmp, 0x5c, 40);
    func_02163CF0(p, tmp, 40);
    func_02163CF0(p, d, 20);
    func_02163DA8(p, d);
}
