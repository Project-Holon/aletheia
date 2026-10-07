/*
 * file:     unit_0215FDA4_p10.c
 * unit:     yes
 * function: func_02160F80, func_021611C0, func_02161264, func_021612C8
 * address:  0x02160F80
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
 *   func_0216009C       0x0216009C arm ov009
 *   func_021600E4       0x021600E4 arm ov009
 *   CPSi_big_from_char  0x02164CC4 arm ov009
 *   CPSi_big_montpower  0x02164AA8 arm ov009
 *   CPSi_big_sub        0x021640B8 arm ov009
 *   CPSi_big_mult       0x02164230 arm ov009
 *   CPSi_big_add        0x02163F7C arm ov009
 *   CPSi_big_sign       0x02163F4C arm ov009
 *   CPSi_big_negate     0x02164078 arm ov009
 *   CPSi_big_div        0x021644D0 arm ov009
 *   CPSi_char_from_big  0x02164D20 arm ov009
 *   CPSiAlloc           0x021A8280 data
 *   CPSiFree            0x021A82B0 data
 *   CPSi_sha1_init    0x02163C9C  arm
 *   CPSi_sha1_calc    0x02163CF0  arm
 *   CPSi_sha1_result  0x02163DA8  arm
 *   CPSi_md5_init     0x021633F0  arm
 *   CPSi_md5_calc     0x02163438  arm
 *   CPSi_md5_result   0x021634F0  arm
 *   strlen            0x0209477C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_021A1D8C     0x021A1D8C  data
 *   d_021A1D90     0x021A1D90  data
 *   d_021A1D94     0x021A1D94  data
 *   CPSi_rc4_init     0x02163E40  arm
 */
struct _CPSSslConnection;
typedef struct CPSPrivateKey {
    int size;
    unsigned char *p0;
    int l1;
    unsigned char *p1;
    int l2;
    unsigned char *p2;
    int l3;
    unsigned char *p3;
    int l4;
    unsigned char *p4;
    int l5;
    unsigned char *p5;
} CPSPrivateKey;

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

extern unsigned long func_0216009C(void);
extern void func_021600E4(unsigned long old_priority);
extern void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n);
extern void CPSi_big_sub(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_add(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern int CPSi_big_sign(unsigned short *a, int digits);
extern void CPSi_big_negate(unsigned short *a, int digits);
extern void CPSi_big_div(unsigned short *c, unsigned short *a, unsigned short *b, unsigned short *r, int digits, unsigned short *work);
extern void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes, int digits);
extern void CPSi_sha1_init(void *ctx);
extern void CPSi_sha1_calc(void *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(void *ctx, unsigned char *digest);
extern void CPSi_md5_init(void *ctx);
extern void CPSi_md5_calc(void *ctx, void *data0, int datalen);
extern void CPSi_md5_result(void *ctx, unsigned char *digest);
extern int strlen(const char *s);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_rc4_init(CPSCipherCtx *ctx, unsigned char *key, int len);
extern char d_021A1D8C[];
extern char d_021A1D90[];
extern char d_021A1D94[];

extern void *(*CPSiAlloc)(unsigned long size);

extern void (*CPSiFree)(void *ptr);


static void decrypt_premaster_secret(unsigned char *d, unsigned char *s, CPSPrivateKey *k)
{
    int digits;
    unsigned short *tmp_var;
    unsigned short *b;
    unsigned short *c;
    unsigned short *k1;
    unsigned short *k2;
    unsigned short *n;
    unsigned short *l;
    unsigned short *divwork;
    unsigned long old_priority;

    if (k == 0 || k->size == 0)
        return;

    digits = (k->size * 2) / 2 + 1;
    tmp_var = CPSiAlloc(digits * 20);
    if (tmp_var == 0)
        return;

    b = tmp_var + digits;
    c = b + digits;
    k1 = c + digits;
    k2 = k1 + digits;
    n = k2 + digits;
    l = n + digits;
    divwork = l + digits;

    CPSi_big_from_char(tmp_var, s, k->size, digits);
    CPSi_big_from_char(b, k->p3, k->l3, digits);
    CPSi_big_from_char(n, k->p1, k->l1, digits);
    old_priority = func_0216009C();
    CPSi_big_montpower(k1, tmp_var, b, digits, n);
    CPSi_big_from_char(b, k->p4, k->l4, digits);
    CPSi_big_from_char(n, k->p2, k->l2, digits);
    CPSi_big_montpower(k2, tmp_var, b, digits, n);
    func_021600E4(old_priority);
    CPSi_big_sub(tmp_var, k1, k2, digits);
    CPSi_big_from_char(b, k->p5, k->l5, digits);
    CPSi_big_mult(c, tmp_var, b, digits);
    CPSi_big_from_char(b, k->p2, k->l2, digits);
    CPSi_big_mult(tmp_var, c, b, digits);
    CPSi_big_add(c, tmp_var, k2, digits);
    CPSi_big_from_char(b, k->p0, k->size, digits);
    if (CPSi_big_sign(c, digits) < 0) {
        CPSi_big_negate(c, digits);
        CPSi_big_div(0, c, b, l, digits, divwork);
        CPSi_big_sub(l, b, l, digits);
    } else {
        CPSi_big_div(0, c, b, l, digits, divwork);
    }
    CPSi_char_from_big(d, l, 0x30, digits);
    CPSiFree(tmp_var);
}


static void create_ms_sub(unsigned char *d, char *salt,
                          struct _CPSSslConnection *con)
{
    unsigned char tmp[20];

    CPSi_sha1_init((char *)con + 0x348);
    CPSi_sha1_calc((char *)con + 0x348, salt, strlen(salt));
    CPSi_sha1_calc((char *)con + 0x348, con, 0x30);
    CPSi_sha1_calc((char *)con + 0x348, (char *)con + 0x34, 0x40);
    CPSi_sha1_result((char *)con + 0x348, tmp);
    CPSi_md5_init((char *)con + 0x3fc);
    CPSi_md5_calc((char *)con + 0x3fc, con, 0x30);
    CPSi_md5_calc((char *)con + 0x3fc, tmp, 0x14);
    CPSi_md5_result((char *)con + 0x3fc, d);
}


static void create_master_secret(struct _CPSSslConnection *con)
{
    unsigned char tmp[48];

    create_ms_sub(tmp, d_021A1D8C, con);
    create_ms_sub(tmp + 0x10, d_021A1D90, con);
    create_ms_sub(tmp + 0x20, d_021A1D94, con);
    MI_CpuCopy8(tmp, con, 0x30);
}


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
