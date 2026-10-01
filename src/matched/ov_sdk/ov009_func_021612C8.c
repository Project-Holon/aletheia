/*
 * function: create_key_block
 * address:  0x021612C8
 * packet:   pkt_ov009_021612C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * lane18 (2026-10-01): EXACT. Three source errors: (1) DWARF `void *p` is the hash
 *   context pointer, set to &con->sha1_hash_tmp then &con->md5_hash_tmp in the loop body
 *   (that alone hoists &c and 1 to the outer preheader); (2) real struct layout from DWARF
 *   with a plain `for (i = 0; i * 16 < len; i++)`; (3) the second key pointer is built from
 *   the stored MAC field (`con->send_mac + size1 + size2`), giving `add r1, r2, r0`.
 *
 * symbols:
 *   CPSi_sha1_init    0x02163C9C  arm
 *   CPSi_sha1_calc    0x02163CF0  arm
 *   CPSi_sha1_result  0x02163DA8  arm
 *   CPSi_md5_init     0x021633F0  arm
 *   CPSi_md5_calc     0x02163438  arm
 *   CPSi_md5_result   0x021634F0  arm
 *   CPSi_rc4_init     0x02163E40  arm
*/

typedef struct { unsigned char b[0x5C]; } CPSSha1Ctx;
typedef struct { unsigned char b[0x58]; } CPSMd5Ctx;
typedef struct { unsigned char b[0x104]; } CPSCipherCtx;

typedef struct _CPSSslConnection {
    unsigned char master_secret[48];      /* 0x000 */
    unsigned char session_cached;         /* 0x030 */
    unsigned char reuse_session;          /* 0x031 */
    unsigned short method;                /* 0x032 */
    unsigned char client_random[32];      /* 0x034 */
    unsigned char server_random[32];      /* 0x054 */
    union {
        unsigned char key_block[72];
    } common1;                            /* 0x074 */
    unsigned char *send_mac;              /* 0x0bc */
    unsigned char *send_key;              /* 0x0c0 */
    unsigned char *send_iv;               /* 0x0c4 */
    CPSCipherCtx send_cipher;             /* 0x0c8 */
    unsigned char send_seq[8];            /* 0x1cc */
    unsigned char *rcv_mac;               /* 0x1d4 */
    unsigned char *rcv_key;               /* 0x1d8 */
    unsigned char *rcv_iv;                /* 0x1dc */
    CPSCipherCtx rcv_cipher;              /* 0x1e0 */
    unsigned char rcv_seq[8];             /* 0x2e4 */
    CPSSha1Ctx sha1_hash;                 /* 0x2ec */
    CPSSha1Ctx sha1_hash_tmp;             /* 0x348 */
    CPSMd5Ctx md5_hash;                   /* 0x3a4 */
    CPSMd5Ctx md5_hash_tmp;               /* 0x3fc */
    unsigned char server;                 /* 0x454 */
    unsigned char state;                  /* 0x455 */
} CPSSslConnection;

extern void CPSi_sha1_init(CPSSha1Ctx *ctx);
extern void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest);
extern void CPSi_md5_init(CPSMd5Ctx *ctx);
extern void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen);
extern void CPSi_md5_result(CPSMd5Ctx *ctx, unsigned char *digest);
extern void CPSi_rc4_init(CPSCipherCtx *ctx, unsigned char *key, int len);

static void create_key_block(struct _CPSSslConnection *con)
{
    int i, j;
    unsigned char c;
    unsigned char tmp[20];
    void *p;
    int size1, size2, size3;
    int len;

    switch (con->method) {
    case 4:
        size1 = 16;
        size2 = 16;
        size3 = 0;
        break;
    case 5:
        size1 = 20;
        size2 = 16;
        size3 = 0;
        break;
    }
    len = (size1 + size2 + size3) * 2;
    for (i = 0; i * 16 < len; i++) {
        p = &con->sha1_hash_tmp;
        CPSi_sha1_init(p);
        c = 'A' + i;
        for (j = 0; j < i + 1; j++)
            CPSi_sha1_calc(p, &c, 1);
        CPSi_sha1_calc(p, con->master_secret, 48);
        CPSi_sha1_calc(p, con->server_random, 32);
        CPSi_sha1_calc(p, con->client_random, 32);
        CPSi_sha1_result(p, tmp);
        p = &con->md5_hash_tmp;
        CPSi_md5_init(p);
        CPSi_md5_calc(p, con->master_secret, 48);
        CPSi_md5_calc(p, tmp, 20);
        CPSi_md5_result(p, con->common1.key_block + i * 16);
    }
    if (con->server) {
        con->rcv_mac = con->common1.key_block;
        con->rcv_key = con->common1.key_block + size1 * 2;
        con->send_mac = con->common1.key_block + size1;
        con->send_key = con->send_mac + size1 + size2;
    } else {
        con->send_mac = con->common1.key_block;
        con->send_key = con->common1.key_block + size1 * 2;
        con->rcv_mac = con->common1.key_block + size1;
        con->rcv_key = con->rcv_mac + size1 + size2;
    }
    CPSi_rc4_init(&con->rcv_cipher, con->rcv_key, 16);
    CPSi_rc4_init(&con->send_cipher, con->send_key, 16);
}
