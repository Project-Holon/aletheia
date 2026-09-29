/*
 * function: func_021622C0
 * address:  0x021622C0
 * packet:   pkt_ov009_021622C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_change_cipher_spec_and_finished (libssl.TWL.HYB.a ssl.o)
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021614BC  0x021614BC  arm  ov009
 *   func_02161598  0x02161598  arm  ov009
 *   func_02161C54  0x02161C54  arm  ov009
 *   func_021619CC  0x021619CC  arm  ov009
 *   func_0215B198  0x0215B198  arm  ov009
 *   g_021A8280     0x021A8280  data ov009
 *   g_021A82B0     0x021A82B0  data ov009
 *
 * Static SSL handshake tail: builds the ChangeCipherSpec and Finished records, hashes and encrypts them, sends them.
 */

typedef struct CPSSoc {
    unsigned char pad0[0xC];
    struct CPSSslConnection *con;
} CPSSoc;

typedef struct CPSSslConnection {
    unsigned char pad0[0x1CC];
    unsigned char send_seq[8];
    unsigned char pad1[0x2EC - 0x1D4];
    unsigned char sha1_hash[0x5C];
    unsigned char sha1_hash_tmp[0x5C];
    unsigned char md5_hash[0x58];
    unsigned char md5_hash_tmp[0x58];
    unsigned char pad2[0x455 - 0x454];
    unsigned char state;
} CPSSslConnection;

extern unsigned char *(*g_021A8280)(unsigned long size);
extern void (*g_021A82B0)(void *p);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void func_021614BC(CPSSslConnection *con, unsigned char *d, int flag);
extern void func_02161598(CPSSslConnection *con, unsigned char *d, int flag);
extern void func_02161C54(CPSSslConnection *con, unsigned char *s, unsigned long len);
extern int func_021619CC(CPSSslConnection *con, unsigned char *s);
extern unsigned long func_0215B198(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, CPSSoc *soc);

void func_021622C0(CPSSoc *soc)
{
    unsigned char *buf;
    CPSSslConnection *con = soc->con;

    buf = g_021A8280(131);
    if (buf == 0) {
        con->state = 9;
        return;
    }
    buf[0] = 20;
    buf[1] = 3;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 1;
    buf[5] = 1;
    MI_CpuFill8(con->send_seq, 0, 8);
    buf[6] = 22;
    buf[7] = 3;
    buf[8] = 0;
    buf[9] = 0;
    buf[10] = 40;
    buf[11] = 20;
    buf[12] = 0;
    buf[13] = 0;
    buf[14] = 36;
    MI_CpuCopy8(con->md5_hash, con->md5_hash_tmp, 0x58);
    func_021614BC(con, buf + 15, 0);
    MI_CpuCopy8(con->md5_hash_tmp, con->md5_hash, 0x58);
    MI_CpuCopy8(con->sha1_hash, con->sha1_hash_tmp, 0x5C);
    func_02161598(con, buf + 31, 0);
    MI_CpuCopy8(con->sha1_hash_tmp, con->sha1_hash, 0x5C);
    func_02161C54(con, buf + 11, 40);
    func_0215B198(buf, func_021619CC(con, buf + 6) + 6, 0, 0, soc);
    g_021A82B0(buf);
}
