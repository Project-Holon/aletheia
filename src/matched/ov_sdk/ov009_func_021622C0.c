/*
 * function: send_change_cipher_spec_and_finished
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
 *   finished_md5  0x021614BC  arm  ov009
 *   finished_sha1  0x02161598  arm  ov009
 *   update_digest  0x02161C54  arm  ov009
 *   make_ciphertext  0x021619CC  arm  ov009
 *   CPSi_TcpWrite2Raw  0x0215B198  arm  ov009
 *   CPSiAlloc     0x021A8280  data ov009
 *   CPSiFree     0x021A82B0  data ov009
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

extern unsigned char *(*CPSiAlloc)(unsigned long size);
extern void (*CPSiFree)(void *p);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct _CPSSoc;
struct _CPSSslConnection;
extern void finished_md5(struct _CPSSslConnection *con, unsigned char *d, int flag);
extern void finished_sha1(struct _CPSSslConnection *con, unsigned char *d, int flag);
extern void update_digest(CPSSslConnection *con, unsigned char *s, unsigned long len);
extern int make_ciphertext(CPSSslConnection *con, unsigned char *s);
extern u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc);

void send_change_cipher_spec_and_finished(CPSSoc *soc)
{
    unsigned char *buf;
    CPSSslConnection *con = soc->con;

    buf = CPSiAlloc(131);
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
    finished_md5((struct _CPSSslConnection *)con, buf + 15, 0);
    MI_CpuCopy8(con->md5_hash_tmp, con->md5_hash, 0x58);
    MI_CpuCopy8(con->sha1_hash, con->sha1_hash_tmp, 0x5C);
    finished_sha1((struct _CPSSslConnection *)con, buf + 31, 0);
    MI_CpuCopy8(con->sha1_hash_tmp, con->sha1_hash, 0x5C);
    update_digest(con, buf + 11, 40);
    CPSi_TcpWrite2Raw(buf, make_ciphertext(con, buf + 6) + 6, 0, 0, (struct _CPSSoc *)soc);
    CPSiFree(buf);
}
