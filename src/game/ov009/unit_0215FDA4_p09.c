/*
 * file:     unit_0215FDA4_p09.c
 * unit:     yes
 * function: func_02161480, func_021614BC, func_02161598, func_02161678, func_02161748, func_0216176C, func_02161784
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
 *   func_02082D44  0x02082D44  arm
 *   func_020923F0  0x020923F0  arm
 *   func_02163EB8  0x02163EB8  arm  ov009
 *   decrypt                         0x0216176C  arm  ov009
 *   CPSi_md5_init                   0x021633F0  arm  ov009
 *   CPSi_md5_calc                   0x02163438  arm  ov009
 *   MI_CpuFill8                     0x02082BCC  arm
 *   CPSi_md5_result                 0x021634F0  arm  ov009
 *   CPSi_sha1_init                  0x02163C9C  arm  ov009
 *   CPSi_sha1_calc                  0x02163CF0  arm  ov009
 *   CPSi_sha1_result                0x02163DA8  arm  ov009
 *   memcmp                          0x020923F0  arm
 */
struct _CPSSslConnection;
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

typedef struct CPSSslConnection_02161678 {
    unsigned char pad0[0x2ec];
    unsigned char sha1[0x5c];           /* +0x2ec */
    unsigned char sha1_save[0x5c];      /* +0x348 */
    unsigned char md5[0x58];            /* +0x3a4 */
    unsigned char md5_save[0x58];       /* +0x3fc */
    unsigned char pad454[0x455 - 0x454];
    unsigned char state;                /* +0x455 */
} CPSSslConnection_02161678;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct CPSSslConnection_02161784 {
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
} CPSSslConnection_02161784;

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
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern int decrypt(CPSSslConnection_02161784 *con, u8 *s, int len);
extern void CPSi_md5_init(void *ctx);
extern void CPSi_md5_calc(void *ctx, void *data0, int datalen);
extern void CPSi_md5_result(void *ctx, u8 *digest);
extern void CPSi_sha1_init(void *ctx);
extern void CPSi_sha1_calc(void *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(void *ctx, u8 *digest);
extern int memcmp(const void *a, const void *b, unsigned int n);
void func_021614BC(struct _CPSSslConnection_021614BC *con, unsigned char *d, int flag);
void func_02161598(struct _CPSSslConnection_02161598 *con, unsigned char *d, int flag);
void *func_0216176C(char *p, void *a, void *b);
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



/*
 * sdk:      rcv_finished (libssl.TWL.HYB.a(ssl.o))
 */
static void func_02161678(CPSSslConnection_02161678 *con, unsigned char *s)
{
    unsigned char tmp[20];

    func_02082D44(con->md5, con->md5_save, 0x58);
    func_021614BC((struct _CPSSslConnection_021614BC *)((struct _CPSSslConnection *)con), tmp, 1);
    func_02082D44(con->md5_save, con->md5, 0x58);
    if (func_020923F0(s, tmp, 0x10) != 0) {
        con->state = 9;
        return;
    }
    func_02082D44(con->sha1, con->sha1_save, 0x5c);
    func_02161598((struct _CPSSslConnection_02161598 *)((struct _CPSSslConnection *)con), tmp, 1);
    func_02082D44(con->sha1_save, con->sha1, 0x5c);
    if (func_020923F0(s + 0x10, tmp, 0x14) != 0)
        con->state = 9;
    else
        con->state = 6;
}



static void add1_be8(u8 *d)
{
    int i;
    u8 tmp;

    for (i = 8; i != 0; i--) {
        tmp = *--d + 1;
        *d = tmp;
        if (tmp != 0)
            return;
    }
}



/*
 * Forwards (p + 0x1e0) to func_02163EB8 and returns the third argument.
 */
void *func_0216176C(char *p, void *a, void *b)
{
    void func_02163EB8(void *, void *, void *);
    func_02163EB8(p + 0x1e0, a, b);
    return b;
}



static int make_plaintext(CPSSslConnection_02161784 *con, u8 *s)
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
