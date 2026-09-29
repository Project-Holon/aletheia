/*
 * function: make_plaintext
 * address:  0x02161784
 * packet:   pkt_ov009_02161784
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      make_plaintext (libssl.TWL.HYB.a ssl.o)
 *
 * symbols:
 *   decrypt                         0x0216176C  arm  ov009
 *   CPSi_md5_init                   0x021633F0  arm  ov009
 *   CPSi_md5_calc                   0x02163438  arm  ov009
 *   MI_CpuFill8                     0x02082BCC  arm
 *   CPSi_md5_result                 0x021634F0  arm  ov009
 *   CPSi_sha1_init                  0x02163C9C  arm  ov009
 *   CPSi_sha1_calc                  0x02163CF0  arm  ov009
 *   CPSi_sha1_result                0x02163DA8  arm  ov009
 *   memcmp                          0x020923F0  arm
 *   add1_be8                        0x02161748  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct CPSSslConnection {
    u8  pad00[0x32];
    u16 hash_type;          /* +0x32 */
    u8  pad34[0x1d4 - 0x34];
    u8  *f1d4;              /* +0x1d4 */
    u8  pad1d8[0x2e4 - 0x1d8];
    u8  f2e4[8];            /* +0x2e4 */
    u8  f2ec[0x348 - 0x2ec];
    u8  sha1[0x3fc - 0x348];
    u8  md5[0x455 - 0x3fc];
    u8  f455;               /* +0x455 */
} CPSSslConnection;

extern int decrypt(CPSSslConnection *con, u8 *s, int len);
extern void CPSi_md5_init(void *ctx);
extern void CPSi_md5_calc(void *ctx, void *data0, int datalen);
extern void CPSi_md5_result(void *ctx, u8 *digest);
extern void CPSi_sha1_init(void *ctx);
extern void CPSi_sha1_calc(void *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(void *ctx, u8 *digest);
extern int memcmp(const void *a, const void *b, unsigned int n);
extern void add1_be8(u8 *d);

static int make_plaintext(CPSSslConnection *con, u8 *s)
{
    int len;
    int hash_len;
    u8 tmp[20];
    u8 pad[48];

    len = decrypt(con, s + 5, (s[3] << 8) + s[4]);
    switch (con->hash_type) {
    case 4:
        len -= 0x10;
        s[3] = len >> 8;
        s[4] = len;
        CPSi_md5_init(con->md5);
        hash_len = 0x10;
        CPSi_md5_calc(con->md5, con->f1d4, hash_len);
        MI_CpuFill8(pad, 0x36, 0x30);
        CPSi_md5_calc(con->md5, pad, 0x30);
        CPSi_md5_calc(con->md5, con->f2e4, 8);
        CPSi_md5_calc(con->md5, s, 1);
        CPSi_md5_calc(con->md5, s + 3, len + 2);
        CPSi_md5_result(con->md5, tmp);
        CPSi_md5_init(con->md5);
        CPSi_md5_calc(con->md5, con->f1d4, hash_len);
        MI_CpuFill8(pad, 0x5c, 0x30);
        CPSi_md5_calc(con->md5, pad, 0x30);
        CPSi_md5_calc(con->md5, tmp, hash_len);
        CPSi_md5_result(con->md5, tmp);
        break;
    case 5:
        len -= 0x14;
        s[3] = len >> 8;
        s[4] = len;
        CPSi_sha1_init(con->sha1);
        hash_len = 0x14;
        CPSi_sha1_calc(con->sha1, con->f1d4, hash_len);
        MI_CpuFill8(pad, 0x36, 0x28);
        CPSi_sha1_calc(con->sha1, pad, 0x28);
        CPSi_sha1_calc(con->sha1, con->f2e4, 8);
        CPSi_sha1_calc(con->sha1, s, 1);
        CPSi_sha1_calc(con->sha1, s + 3, len + 2);
        CPSi_sha1_result(con->sha1, tmp);
        CPSi_sha1_init(con->sha1);
        CPSi_sha1_calc(con->sha1, con->f1d4, hash_len);
        MI_CpuFill8(pad, 0x5c, 0x28);
        CPSi_sha1_calc(con->sha1, pad, 0x28);
        CPSi_sha1_calc(con->sha1, tmp, hash_len);
        CPSi_sha1_result(con->sha1, tmp);
        break;
    }
    if (memcmp(s + 5 + len, tmp, hash_len) != 0)
        con->f455 = 9;
    add1_be8(con->f2ec);
    return len + 5;
}
