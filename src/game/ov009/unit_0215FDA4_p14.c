/*
 * file:     unit_0215FDA4_p14.c
 * unit:     yes
 * function: func_02161F98, func_02162128, func_02162248, func_021622C0
 * address:  0x02161F98
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
 *   CPSi_TcpReadRaw       0x0215AE18  arm
 *   CPSi_SocConsumeRaw    0x0215AF14  arm
 *   tcp_read_raw_nbytes   0x02161BE8  arm
 *   client_hello_v2       0x02160E1C  arm
 *   update_digest         0x02161C54  arm
 *   parse_record_in_buf   0x02161C80  arm
 *   CPSiAlloc             0x021A8280  data
 *   CPSiFree              0x021A82B0  data
 *   func_02162248  0x02162248  arm  ov009
 *   func_02163C9C  0x02163C9C  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   func_02163E10  0x02163E10  arm  ov009
 *   func_0208799C  0x0208799C  arm
 *   g_021AA648  0x021AA648  data
 *   g_021A82E4  0x021A82E4  data
 *   g_021AA650  0x021AA650  data
 *   CPSi_sha1_init         0x02163c9c  arm
 *   OS_DisableInterrupts   0x02087988  arm
 *   CPSi_sha1_calc         0x02163cf0  arm
 *   CPSi_sha1_result       0x02163da8  arm
 *   OS_RestoreInterrupts   0x0208799c  arm
 *   pool                   0x021aa650  data  a4
 *   pool_initialized       0x021aa648  data
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021614BC  0x021614BC  arm  ov009
 *   func_02161598  0x02161598  arm  ov009
 *   func_02161C54  0x02161C54  arm  ov009
 *   func_021619CC  0x021619CC  arm  ov009
 *   func_0215B198  0x0215B198  arm  ov009
 *   g_021A8280     0x021A8280  data ov009
 *   g_021A82B0     0x021A82B0  data ov009
 */
struct _CPSSoc;
struct _CPSSslConnection;
struct _CPSSslConnection {
    char pad0[0x454];
    unsigned char f454;
    unsigned char f455;
};

struct _CPSSoc {
    char pad0[8];
    unsigned char field_8;
    char pad1[0xc - 9];
    struct _CPSSslConnection *con;
};

typedef unsigned long long u64;

typedef struct {
    unsigned long state[5];
    unsigned long count[2];
    unsigned char buffer[64];
} CPSSha1Ctx;

typedef struct {
    u64 x;
    u64 a;
    u64 c;
} Rand32Ctx;

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

typedef unsigned int   u32;

typedef unsigned char  u8;

extern unsigned char *CPSi_TcpReadRaw(unsigned long *len, struct _CPSSoc *soc);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc);
extern int tcp_read_raw_nbytes(unsigned char *d, int len, struct _CPSSoc *soc);
extern void client_hello_v2(void *con, unsigned char *s);
extern void update_digest(void *con, unsigned char *s, unsigned long len);
extern void parse_record_in_buf(void *con, unsigned char *buf);
extern void func_02162248(void *random_seed, unsigned long len);
extern void func_02163C9C(CPSSha1Ctx *ctx);
extern unsigned long func_02087988(void);
extern void func_02163CF0(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void func_02163E10(void *ctx, unsigned char *digest);
extern unsigned long func_0208799C(unsigned long state);
extern void CPSi_sha1_init(CPSSha1Ctx *ctx);
extern unsigned long OS_DisableInterrupts(void);
extern void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void func_021614BC(struct _CPSSslConnection *con, unsigned char *d, int flag);
extern void func_02161598(struct _CPSSslConnection *con, unsigned char *d, int flag);
extern void func_02161C54(CPSSslConnection *con, unsigned char *s, unsigned long len);
extern int func_021619CC(CPSSslConnection *con, unsigned char *s);
extern u32 func_0215B198(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc);
void CPS_SslAddRandomSeed(void *random_seed, unsigned long len);
void func_021622C0(CPSSoc *soc);
extern unsigned char g_021AA648;
extern Rand32Ctx g_021A82E4;
extern unsigned char g_021AA650[20];
extern unsigned char pool[20];
extern unsigned char pool_initialized;

extern unsigned char *(*CPSiAlloc)(unsigned long size);

extern void (*CPSiFree)(void *ptr);


static int parse_record(struct _CPSSoc *soc)
{
    unsigned char *buf;
    unsigned long len;
    unsigned char *s;
    struct _CPSSslConnection *con = soc->con;

    for (;;) {
        buf = CPSi_TcpReadRaw(&len, soc);
        if (len >= 5)
            break;
        if (len == 0 || soc->field_8 == 0) {
            con->f455 = 9;
            return 9;
        }
    }

    if (buf[0] == 0x80) {
        if (con->f454 != 0 && con->f455 == 0) {
            len = buf[1];
            CPSi_SocConsumeRaw(2, soc);
            s = CPSiAlloc(len);
            if (s == 0) {
                con->f455 = 9;
                return 9;
            }
            if (tcp_read_raw_nbytes(s, len, soc) != 0 || s[0] != 1)
                con->f455 = 9;
            else
                client_hello_v2(con, s + 1);
            update_digest(con, s, len);
            CPSiFree(s);
        } else {
            con->f455 = 9;
        }
    } else {
        len = (buf[3] << 8) + buf[4] + 5;
        if (len > 0x4805) {
            con->f455 = 9;
            return 9;
        }
        s = CPSiAlloc(len);
        if (s == 0) {
            con->f455 = 9;
            return 9;
        }
        if (tcp_read_raw_nbytes(s, len, soc) != 0) {
            CPSiFree(s);
            con->f455 = 9;
            return 9;
        }
        parse_record_in_buf(con, s);
    }
    return con->f455;
}


/*
 * sdk:      set_random (libssl.TWL.HYB.a(ssl.o))
 */
static void func_02162128(unsigned char *d, int len)
{
    unsigned long enabled;
    CPSSha1Ctx ctx;
    unsigned char x[20];
    int i;
    int j;
    int r;
    unsigned int carry;
    unsigned long tmp;

    if (g_021AA648 == 0) {
        g_021A82E4.x = g_021A82E4.a * g_021A82E4.x + g_021A82E4.c;
        tmp = (unsigned long)(g_021A82E4.x >> 32);
        func_02162248(&tmp, 4);
    }
    r = 20;
    for (i = 0; i < len;) {
        if (r == 20) {
            func_02163C9C(&ctx);
            enabled = func_02087988();
            func_02163CF0(&ctx, g_021AA650, 20);
            func_02163E10(&ctx, x);
            carry = 1;
            for (j = 19; j >= 0; j--) {
                tmp = g_021AA650[j] + x[j] + carry;
                g_021AA650[j] = (unsigned char)tmp;
                carry = tmp >> 8;
            }
            func_0208799C(enabled);
            r = 0;
        }
        {
            unsigned char b = x[r++];
            if (b != 0)
                d[i++] = b;
        }
    }
}


void CPS_SslAddRandomSeed(void *random_seed, unsigned long len)
{
    CPSSha1Ctx ctx;
    unsigned long enabled;

    CPSi_sha1_init(&ctx);
    enabled = OS_DisableInterrupts();
    CPSi_sha1_calc(&ctx, pool, 0x14);
    CPSi_sha1_calc(&ctx, random_seed, len);
    CPSi_sha1_result(&ctx, pool);
    OS_RestoreInterrupts(enabled);
    pool_initialized = 1;
}


extern unsigned char *(*g_021A8280)(unsigned long size);

extern void (*g_021A82B0)(void *p);


/*
 * sdk:      send_change_cipher_spec_and_finished (libssl.TWL.HYB.a ssl.o)
 *
 * Static SSL handshake tail: builds the ChangeCipherSpec and Finished records, hashes and encrypts them, sends them.
 */
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
    func_021614BC((struct _CPSSslConnection *)con, buf + 15, 0);
    MI_CpuCopy8(con->md5_hash_tmp, con->md5_hash, 0x58);
    MI_CpuCopy8(con->sha1_hash, con->sha1_hash_tmp, 0x5C);
    func_02161598((struct _CPSSslConnection *)con, buf + 31, 0);
    MI_CpuCopy8(con->sha1_hash_tmp, con->sha1_hash, 0x5C);
    func_02161C54(con, buf + 11, 40);
    func_0215B198(buf, func_021619CC(con, buf + 6) + 6, 0, 0, (struct _CPSSoc *)soc);
    g_021A82B0(buf);
}
