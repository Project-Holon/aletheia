/*
 * file:     unit_0215FDA4_p10.c
 * unit:     yes
 * function: func_02161678, func_02161748, func_0216176C, func_02161784
 * address:  0x02161678
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
 *   func_02082D44  0x02082D44  arm
 *   func_021614BC  0x021614BC  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   func_02161598  0x02161598  arm  ov009
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

extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_021614BC(struct _CPSSslConnection *con, unsigned char *d, int flag);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void func_02161598(struct _CPSSslConnection *con, unsigned char *d, int flag);
extern int decrypt(CPSSslConnection_02161784 *con, u8 *s, int len);
extern void CPSi_md5_init(void *ctx);
extern void CPSi_md5_calc(void *ctx, void *data0, int datalen);
extern void CPSi_md5_result(void *ctx, u8 *digest);
extern void CPSi_sha1_init(void *ctx);
extern void CPSi_sha1_calc(void *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(void *ctx, u8 *digest);
extern int memcmp(const void *a, const void *b, unsigned int n);
void *func_0216176C(char *p, void *a, void *b);


/*
 * sdk:      rcv_finished (libssl.TWL.HYB.a(ssl.o))
 */
static void func_02161678(CPSSslConnection_02161678 *con, unsigned char *s)
{
    unsigned char tmp[20];

    func_02082D44(con->md5, con->md5_save, 0x58);
    func_021614BC((struct _CPSSslConnection *)con, tmp, 1);
    func_02082D44(con->md5_save, con->md5, 0x58);
    if (func_020923F0(s, tmp, 0x10) != 0) {
        con->state = 9;
        return;
    }
    func_02082D44(con->sha1, con->sha1_save, 0x5c);
    func_02161598((struct _CPSSslConnection *)con, tmp, 1);
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
