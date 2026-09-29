/*
 * function: func_021614BC
 * address:  0x021614BC
 * packet:   pkt_ov009_021614BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      finished_md5 (ssl.o)
 *
 * symbols:
 *   func_02163438  0x02163438  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_021634F0  0x021634F0  arm  ov009
 *   func_021633F0  0x021633F0  arm  ov009
 *   g_021A1D98     0x021A1D98  data
 *   g_021A1DA0     0x021A1DA0  data
 */

struct _CPSSslConnection {
    unsigned char master_secret[48];
    char pad0[0x3a4 - 0x30];
    unsigned char md5_hash[0x58];
    char pad1[0x454 - 0x3fc];
    unsigned char server;
};

extern void func_02163438(void *ctx, void *data0, int datalen);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_021634F0(void *ctx, unsigned char *digest);
extern void func_021633F0(void *ctx);
extern int g_021A1D98;
extern int g_021A1DA0;

void func_021614BC(struct _CPSSslConnection *con, unsigned char *d, int flag)
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
