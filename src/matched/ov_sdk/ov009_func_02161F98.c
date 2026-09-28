/*
 * function: parse_record
 * address:  0x02161F98
 * packet:   pkt_ov009_02161F98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      parse_record (ssl.o)
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
*/

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

extern unsigned char *CPSi_TcpReadRaw(unsigned long *len, struct _CPSSoc *soc);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc);
extern int tcp_read_raw_nbytes(unsigned char *d, int len, struct _CPSSoc *soc);
extern void client_hello_v2(void *con, unsigned char *s);
extern void update_digest(void *con, unsigned char *s, unsigned long len);
extern void parse_record_in_buf(void *con, unsigned char *buf);
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
