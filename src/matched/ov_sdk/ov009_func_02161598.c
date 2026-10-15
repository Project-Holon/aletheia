/*
 * function: finished_sha1
 * address:  0x02161598
 * packet:   pkt_ov009_02161598
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      finished_sha1 (ssl.o)
 *
 * symbols:
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02163DA8  0x02163DA8  arm  ov009
 *   func_02163C9C  0x02163C9C  arm  ov009
 *   gCpsSslServerId     0x021A1D98  data
 *   gCpsSslClientId     0x021A1DA0  data
 */

struct _CPSSslConnection {
    unsigned char master_secret[48];
    char pad0[0x2ec - 0x30];
    unsigned char sha1_hash[0x5c];
    char pad1[0x454 - 0x348];
    unsigned char server;
};

extern void func_02163CF0(void *ctx, void *data0, int datalen);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void func_02163DA8(void *ctx, unsigned char *digest);
extern void func_02163C9C(void *ctx);
extern int gCpsSslServerId;
extern int gCpsSslClientId;

void finished_sha1(struct _CPSSslConnection *con, unsigned char *d, int flag)
{
    unsigned char tmp[40];
    unsigned char *p = con->sha1_hash;

    if ((con->server ^ flag) != 0)
        func_02163CF0(p, &gCpsSslServerId, 4);
    else
        func_02163CF0(p, &gCpsSslClientId, 4);
    func_02163CF0(p, con->master_secret, 48);
    MI_CpuFill8(tmp, 0x36, 40);
    func_02163CF0(p, tmp, 40);
    func_02163DA8(p, d);
    func_02163C9C(p);
    func_02163CF0(p, con->master_secret, 48);
    MI_CpuFill8(tmp, 0x5c, 40);
    func_02163CF0(p, tmp, 40);
    func_02163CF0(p, d, 20);
    func_02163DA8(p, d);
}
