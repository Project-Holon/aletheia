/*
 * file:     unit_0215FDA4_p13.c
 * unit:     yes
 * function: func_021619CC, func_02161BE8, func_02161C54, func_02161C80
 * address:  0x021619CC
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
 *   CPSi_md5_init    0x021633F0  arm  ov009
 *   CPSi_md5_calc    0x02163438  arm  ov009
 *   MI_CpuFill8      0x02082BCC  arm
 *   CPSi_md5_result  0x021634F0  arm  ov009
 *   CPSi_sha1_init   0x02163C9C  arm  ov009
 *   CPSi_sha1_calc   0x02163CF0  arm  ov009
 *   CPSi_sha1_result 0x02163DA8  arm  ov009
 *   CPSi_rc4_crypt   0x02163EB8  arm  ov009
 *   add1_be8         0x02161748  arm  ov009
 *   func_0215AE18  0x0215AE18  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_0215AF14  0x0215AF14  arm  ov009
 *   make_plaintext           0x02161784  arm  ov009
 *   client_hello             0x02160EE0  arm  ov009
 *   rcv_client_key_exchange  0x02161480  arm  ov009
 *   rcv_server_hello         0x02160C9C  arm  ov009
 *   rcv_certificate          0x02160A7C  arm  ov009
 *   rcv_finished             0x02161678  arm  ov009
 *   CPSiFree                 0x021A82B0  data
 */
struct _CPSSslConnection;
struct CPSSoc;
struct _CPSSoc;
typedef struct CPSMd5Ctx CPSMd5Ctx;

typedef struct CPSSha1Ctx CPSSha1Ctx;

typedef struct CPSRc4Ctx CPSRc4Ctx;

struct _CPSSslConnection {
    unsigned char pad0[0x1d4];
    unsigned int f1d4;
    unsigned char pad1[0x2e4 - 0x1d4 - 4];
    unsigned char f2e4[8];
    unsigned char pad2[0x454 - 0x2e4 - 8];
    unsigned char f454;
    unsigned char state;
    unsigned char f456;
    unsigned char pad3[0x5ac - 0x457];
    unsigned char f5ac;
    unsigned char pad4[0x824 - 0x5ad];
    unsigned long f824;
    unsigned long f828;
    unsigned long f82c;
};

extern void CPSi_md5_init(CPSMd5Ctx *ctx);
extern void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPSi_md5_result(CPSMd5Ctx *ctx, unsigned char *digest);
extern void CPSi_sha1_init(CPSSha1Ctx *ctx);
extern void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest);
extern void CPSi_rc4_crypt(CPSRc4Ctx *ctx, unsigned char *data, int len);
extern void add1_be8(unsigned char *d);
extern unsigned char *func_0215AE18(unsigned long *len, char *soc);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_0215AF14(unsigned long len, struct _CPSSoc *soc);
extern int make_plaintext(struct _CPSSslConnection *con, unsigned char *s);
extern void client_hello(struct _CPSSslConnection *con, unsigned char *s);
extern void rcv_client_key_exchange(struct _CPSSslConnection *con,
                                    unsigned char *s);
extern void rcv_server_hello(struct _CPSSslConnection *con, unsigned char *s);
extern void rcv_certificate(struct _CPSSslConnection *con, unsigned char *s);
extern void rcv_finished(struct _CPSSslConnection *con, unsigned char *s);
int make_ciphertext(struct _CPSSslConnection *con, unsigned char *s);


int make_ciphertext(struct _CPSSslConnection *con, unsigned char *s)
{
    void *p;
    int len;
    unsigned char tmp[48];
    unsigned char *mac;
    char *c = (char *)con;

    len = (s[3] << 8) + s[4];
    p = s + 5;
    switch (*(unsigned short *)(c + 0x32)) {
    case 4: {
        CPSMd5Ctx *ctx = (CPSMd5Ctx *)(c + 0x3fc);
        CPSi_md5_init(ctx);
        CPSi_md5_calc(ctx, *(void **)(c + 0xbc), 16);
        MI_CpuFill8(tmp, 0x36, 48);
        CPSi_md5_calc(ctx, tmp, 48);
        CPSi_md5_calc(ctx, c + 0x1cc, 8);
        CPSi_md5_calc(ctx, s, 1);
        CPSi_md5_calc(ctx, s + 3, len + 2);
        mac = (unsigned char *)p + len;
        CPSi_md5_result(ctx, mac);
        CPSi_md5_init(ctx);
        CPSi_md5_calc(ctx, *(void **)(c + 0xbc), 16);
        MI_CpuFill8(tmp, 0x5c, 48);
        CPSi_md5_calc(ctx, tmp, 48);
        CPSi_md5_calc(ctx, mac, 16);
        CPSi_md5_result(ctx, mac);
        len += 16;
        break;
    }
    case 5: {
        CPSSha1Ctx *ctx = (CPSSha1Ctx *)(c + 0x348);
        CPSi_sha1_init(ctx);
        CPSi_sha1_calc(ctx, *(void **)(c + 0xbc), 20);
        MI_CpuFill8(tmp, 0x36, 40);
        CPSi_sha1_calc(ctx, tmp, 40);
        CPSi_sha1_calc(ctx, c + 0x1cc, 8);
        CPSi_sha1_calc(ctx, s, 1);
        CPSi_sha1_calc(ctx, s + 3, len + 2);
        mac = (unsigned char *)p + len;
        CPSi_sha1_result(ctx, mac);
        CPSi_sha1_init(ctx);
        CPSi_sha1_calc(ctx, *(void **)(c + 0xbc), 20);
        MI_CpuFill8(tmp, 0x5c, 40);
        CPSi_sha1_calc(ctx, tmp, 40);
        CPSi_sha1_calc(ctx, mac, 20);
        CPSi_sha1_result(ctx, mac);
        len += 20;
        break;
    }
    }
    s[3] = len >> 8;
    s[4] = len;
    CPSi_rc4_crypt((CPSRc4Ctx *)(c + 0xc8), s + 5, len);
    add1_be8((unsigned char *)(c + 0x1d4));
    return len + 5;
}


/*
 * sdk:      tcp_read_raw_nbytes (libssl.TWL.HYB.a(ssl.o))
 */
static int func_02161BE8(unsigned char *d, int len, struct CPSSoc *soc)
{
    unsigned long thislen;
    unsigned char *s;

    do {
        s = func_0215AE18(&thislen, (char *)soc);
        if (thislen == 0)
            return -1;
        if (thislen > len)
            thislen = len;
        func_02082D44(s, d, thislen);
        func_0215AF14(thislen, (struct _CPSSoc *)soc);
        len -= thislen;
        d += thislen;
    } while (len > 0);
    return 0;
}


static void update_digest(struct _CPSSslConnection *con, unsigned char *s,
                          unsigned long len)
{
    CPSi_sha1_calc((CPSSha1Ctx *)((char *)con + 0x2ec), s, len);
    CPSi_md5_calc((CPSMd5Ctx *)((char *)con + 0x3a4), s, len);
}

extern void (*CPSiFree)(void *ptr);


static void parse_record_in_buf(struct _CPSSslConnection *con, unsigned char *buf)
{
    unsigned char *s;
    unsigned char type;
    unsigned long len;
    int sub;

    if (con->state == 9) {
        CPSiFree(buf);
        return;
    }

    type = buf[0];
    len = (buf[3] << 8) + buf[4] + 5;
    if (con->f1d4 != 0 &&
        (((con->state == 7 || con->state == 8) && type != 0x15) ||
         (type == 0x15 && len > 7))) {
        len = make_plaintext(con, buf);
        if (con->state == 9) {
            CPSiFree(buf);
            return;
        }
    }

    s = buf + 5;
    len -= 5;

    switch (type) {
    case 0x14:
        if (con->f1d4 == 0) {
            con->state = 9;
        } else {
            MI_CpuFill8(con->f2e4, 0, 8);
            con->state = 7;
        }
        break;
    case 0x15:
        if (len != 2 || s[0] == 2)
            con->state = 9;
        break;
    case 0x16:
        if (len < 4) {
            con->state = 9;
            break;
        }
        do {
            type = s[0];
            sub = (s[1] << 16) + (s[2] << 8) + s[3];
            if ((s[1] << 16) + (s[2] << 8) + s[3] > len) {
                con->state = 9;
                break;
            }
            s += 4;
            switch (type) {
            case 1:
                if (con->f454 != 0 && con->state == 0)
                    client_hello(con, s);
                else
                    con->state = 9;
                break;
            case 0x10:
                if (con->f454 == 0)
                    con->state = 9;
                else
                    rcv_client_key_exchange(con, s);
                break;
            case 2:
                if (sub >= 0x26 && con->f454 == 0)
                    rcv_server_hello(con, s);
                else
                    con->state = 9;
                break;
            case 0xb:
                if (con->state == 2 && con->f454 == 0) {
                    rcv_certificate(con, s);
                    con->f5ac = 0;
                } else {
                    con->state = 9;
                }
                break;
            case 0xd:
                if (con->state == 3 && con->f454 == 0)
                    con->f5ac = 1;
                else
                    con->state = 9;
                break;
            case 0xe:
                if (con->f454 == 0 && con->state == 3)
                    con->state = 4;
                else
                    con->state = 9;
                break;
            case 0x14:
                rcv_finished(con, s);
                break;
            default:
                con->state = 9;
                break;
            }
            if (con->state != 9) {
                update_digest(con, s - 4, sub + 4);
                s += sub;
                len -= sub + 4;
            }
        } while (len != 0 && con->state != 9);
        break;
    case 0x17:
        if (con->state != 8) {
            con->state = 9;
        } else {
            con->f824 = (unsigned long)buf;
            con->f82c = 5;
            con->f828 = len + 5;
            con->f456 = 1;
            return;
        }
        break;
    default:
        con->state = 9;
        break;
    }
    CPSiFree(buf);
}
