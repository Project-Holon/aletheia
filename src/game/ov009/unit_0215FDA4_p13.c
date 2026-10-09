/*
 * file:     unit_0215FDA4_p13.c
 * unit:     yes
 * function: func_02162418, func_021625B8, func_0216286C
 * address:  0x02162418
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
 *   func_0216003C  0x0216003C  arm  ov009
 *   func_02162128  0x02162128  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0215FE3C  0x0215FE3C  arm  ov009
 *   func_0215B198  0x0215B198  arm  ov009
 *   func_02161C54  0x02161C54  arm  ov009
 *   g_021A8280     0x021A8280  data
 *   g_021A1D40     0x021A1D40  data
 *   g_021A82B0     0x021A82B0  data
 *   CPSi_TcpWrite2Raw   0x0215B198 arm ov009
 *   set_random          0x02162128 arm ov009
 *   CPSi_big_from_char  0x02164CC4 arm ov009
 *   enter_computebound  0x0216009C arm ov009
 *   CPSi_big_power      0x0216469C arm ov009
 *   exit_computebound   0x021600E4 arm ov009
 *   update_digest       0x02161C54 arm ov009
 *   alert_nocert        0x021A1980 data
 *   CPSiAlloc           0x021A8280 data
 *   CPSiFree            0x021A82B0 data
 *   parse_record  0x02161F98  arm
 */
#define NELEMS(a) (sizeof(a) / sizeof((a)[0]))
struct _CPSSoc;
typedef struct CPSSoc {
    unsigned char pad0[0xC];
    struct CPSSslConnection *con;
    unsigned char pad10[0x18 - 0x10];
    unsigned short remote_port;     /* +0x18 */
    unsigned long remote_ip;        /* +0x1c */
} CPSSoc;

typedef struct CPSSslConnection {
    unsigned char pad0[0x30];
    unsigned char session_id_len;   /* +0x30 */
    unsigned char pad31[3];
    unsigned char client_random[32];/* +0x34 */
    unsigned char pad54[0x74 - 0x54];
    unsigned char session_id[32];   /* +0x74 */
    unsigned char pad94[0x455 - 0x94];
    unsigned char state;            /* +0x455 */
} CPSSslConnection;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct _CPSSslConnection _CPSSslConnection;

typedef struct _CPSSoc {
    char pad0[0xc];
    _CPSSslConnection *con;
} _CPSSoc;

struct _CPSSslConnection {
    unsigned char premaster[0x30];
    unsigned char pad0[0x455 - 0x30];
    unsigned char error;
    unsigned char pad1[0x494 - 0x456];
    unsigned char modulus[0x100];
    int modlen;
    unsigned char pubexp[8];
    int pubexplen;
    unsigned char pad2[0x5ac - 0x5a4];
    unsigned char flag;
};

extern unsigned long func_0216003C(void);
extern void func_02162128(unsigned char *d, int len);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void func_0215FE3C(CPSSslConnection *con, unsigned long ip, unsigned short port);
extern u32 func_0215B198(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc);
extern void func_02161C54(CPSSslConnection *con, unsigned char *s, unsigned long len);
extern unsigned long CPSi_TcpWrite2Raw(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, _CPSSoc *soc);
extern void set_random(unsigned char *d, int len);
extern void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern unsigned long enter_computebound(void);
extern void CPSi_big_power(unsigned short *c, unsigned short *a, unsigned short *b, int digits, unsigned short *n);
extern void exit_computebound(unsigned long old_priority);
extern void update_digest(_CPSSslConnection *con, unsigned char *s, unsigned long len);
extern int parse_record(struct _CPSSoc *soc);
extern unsigned short g_021A1D40[2];
extern unsigned char alert_nocert[7];


extern unsigned char *(*g_021A8280)(unsigned long size);

extern void (*g_021A82B0)(void *p);


/*
 * sdk:      send_client_hello (libssl.TWL.HYB.a(ssl.o))
 */
static void func_02162418(CPSSoc *soc)
{
    CPSSslConnection *con = soc->con;
    unsigned long sec;
    unsigned char *buf;
    unsigned char *d;
    int i;

    buf = g_021A8280(0x98);
    if (buf == 0) {
        con->state = 9;
        return;
    }
    buf[9] = 3;
    buf[10] = 0;
    sec = func_0216003C();
    con->client_random[0] = sec >> 24;
    con->client_random[1] = sec >> 16;
    con->client_random[2] = sec >> 8;
    con->client_random[3] = sec;
    func_02162128(con->client_random + 4, 28);
    MI_CpuCopy8(con->client_random, buf + 11, 32);
    func_0215FE3C(con, soc->remote_ip, soc->remote_port);
    if (con->session_id_len == 0) {
        buf[43] = 0;
        d = buf + 44;
    } else {
        buf[43] = 32;
        MI_CpuCopy8(con->session_id, buf + 44, 32);
        d = buf + 76;
    }
    d[0] = 0;
    d[1] = 4;
    d += 2;
    for (i = 0; i < NELEMS(g_021A1D40); i++) {
        d[0] = g_021A1D40[i] >> 8;
        d[1] = g_021A1D40[i];
        d += 2;
    }
    d[0] = 1;
    d[1] = 0;
    d += 2;
    i = d - buf - 5;
    buf[0] = 22;
    buf[1] = 3;
    buf[2] = 0;
    buf[3] = i >> 8;
    buf[4] = i;
    buf[5] = 1;
    buf[6] = (i - 4) >> 16;
    buf[7] = (i - 4) >> 8;
    buf[8] = i - 4;
    func_0215B198(buf, i + 5, 0, 0, (struct _CPSSoc *)soc);
    func_02161C54(con, buf + 5, i);
    g_021A82B0(buf);
}

extern void *(*CPSiAlloc)(unsigned long size);

extern void (*CPSiFree)(void *ptr);


static void send_client_key_exchange(_CPSSoc *soc)
{
    _CPSSslConnection *con;
    unsigned short *a;
    unsigned short *n;
    int digits;
    unsigned char *buf;
    int modlen;
    unsigned short *b;
    unsigned short *tmp_var;
    unsigned long old_priority;
    int i;
    unsigned char *tmp;
    unsigned char *d;

    con = soc->con;
    if (con->flag != 0)
        CPSi_TcpWrite2Raw(alert_nocert, 7, 0, 0, soc);

    con->premaster[0] = 3;
    con->premaster[1] = 0;
    set_random(&con->premaster[2], 0x2e);

    modlen = con->modlen;
    digits = modlen * 2 / 2;
    buf = CPSiAlloc(modlen);
    if (buf == 0) {
        con->error = 9;
        return;
    }
    buf[0] = 0;
    buf[1] = 2;
    set_random(&buf[2], modlen - 0x33);
    buf[modlen - 0x31] = 0;
    MI_CpuCopy8(con, buf + modlen - 0x30, 0x30);

    a = CPSiAlloc(digits * 8);
    if (a == 0) {
        CPSiFree(buf);
        con->error = 9;
        return;
    }
    tmp_var = a + digits;
    b = tmp_var + digits;
    n = b + digits;
    CPSi_big_from_char(tmp_var, buf, modlen, digits);
    CPSi_big_from_char(b, con->pubexp, con->pubexplen, digits);
    CPSi_big_from_char(n, con->modulus, modlen, digits);
    old_priority = enter_computebound();
    CPSi_big_power(a, tmp_var, b, digits, n);
    exit_computebound(old_priority);

    tmp = CPSiAlloc(modlen + 0x49);
    if (tmp == 0) {
        CPSiFree(buf);
        CPSiFree(a);
        con->error = 9;
        return;
    }
    tmp[0] = 0x16;
    tmp[1] = 3;
    tmp[2] = 0;
    tmp[3] = (modlen + 4) >> 8;
    tmp[4] = modlen + 4;
    tmp[5] = 0x10;
    tmp[6] = modlen >> 16;
    tmp[7] = modlen >> 8;
    tmp[8] = modlen;
    d = &tmp[9];
    if (modlen & 1) {
        tmp[9] = a[modlen / 2];
        d = &tmp[10];
    }
    for (i = modlen / 2 - 1; i >= 0; i--) {
        *d++ = a[i] >> 8;
        *d++ = a[i];
    }
    CPSi_TcpWrite2Raw(tmp, modlen + 9, 0, 0, soc);
    update_digest(con, &tmp[5], modlen + 4);
    CPSiFree(tmp);
    CPSiFree(a);
    CPSiFree(buf);
}


static int mustget_change_cipher_spec_and_finished(struct _CPSSoc *soc)
{
    if (parse_record(soc) != 7)
        return 1;
    if (parse_record(soc) != 6)
        return 1;
    return 0;
}
