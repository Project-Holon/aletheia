/*
 * function: send_client_key_exchange
 * address:  0x021625B8
 * packet:   pkt_ov009_021625B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_client_key_exchange (libssl.TWL.HYB.a ssl.o)
 *
 * con->premaster is 48 bytes (version + 46 random), copied into the RSA
 * block's tail by MI_CpuCopy8.  digits is spelled modlen*2/2 (mwcc keeps
 * the multiply then signed-divides).
 *
 * blocker:  near miss.  All 15 relocations resolve and the body is
 *           structurally right; the spill of tmp_var lands and the frame is
 *           present, but mwcc CSEs the 2*digits offset into one register and
 *           schedules the from_char arg setup differently, so ~30 concrete
 *           bytes stay out (696 vs 692).  Needs a declaration/CSE nudge.
 *
 * symbols:
 *   CPSi_TcpWrite2Raw   0x0215B198 arm ov009
 *   set_random          0x02162128 arm ov009
 *   MI_CpuCopy8         0x02082D44 arm
 *   CPSi_big_from_char  0x02164CC4 arm ov009
 *   enter_computebound  0x0216009C arm ov009
 *   CPSi_big_power      0x0216469C arm ov009
 *   exit_computebound   0x021600E4 arm ov009
 *   update_digest       0x02161C54 arm ov009
 *   alert_nocert        0x021A1980 data
 *   CPSiAlloc           0x021A8280 data
 *   CPSiFree            0x021A82B0 data
 */

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

extern unsigned long CPSi_TcpWrite2Raw(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, _CPSSoc *soc);
extern void set_random(unsigned char *d, int len);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern unsigned long enter_computebound(void);
extern void CPSi_big_power(unsigned short *c, unsigned short *a, unsigned short *b, int digits, unsigned short *n);
extern void exit_computebound(unsigned long old_priority);
extern void update_digest(_CPSSslConnection *con, unsigned char *s, unsigned long len);
extern unsigned char alert_nocert[7];
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
