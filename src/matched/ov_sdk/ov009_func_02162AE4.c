/*
 * function: try_fill_record
 * address:  0x02162AE4
 * packet:   pkt_ov009_02162AE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      try_fill_record (libssl.TWL.HYB.a ssl.o)
 *
 * symbols:
 *   CPSi_TcpReadRaw  0x0215AE18  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   CPSi_SocConsumeRaw  0x0215AF14  arm  ov009
 *   parse_record_in_buf  0x02161C80  arm  ov009
 *   CPSiAlloc     0x021A8280  data ov009
 *
 * Static SSL record reassembly: reads the socket receive buffer into an allocated record buffer, parses it when complete.
 */

typedef struct CPSSoc {
    unsigned char pad0[0xC];
    struct CPSSslConnection *con;
    unsigned char pad1[0x40];
    unsigned long rcvbufp;
} CPSSoc;

typedef struct CPSSslConnection {
    unsigned char pad0[0x455];
    unsigned char state;
    unsigned char inbuf_decrypted;
    unsigned char pad1[0x824 - 0x457];
    unsigned char *inbuf;
    long inbuf_len;
    long inbuf_pnt;
} CPSSslConnection;

extern unsigned char *(*CPSiAlloc)(unsigned long size);
struct _CPSSoc;
extern unsigned char *CPSi_TcpReadRaw(unsigned long *len, char *soc);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc);
extern void parse_record_in_buf(CPSSslConnection *con, unsigned char *buf);

void try_fill_record(CPSSoc *soc)
{
    int got_all;
    unsigned long len;
    unsigned char *s;
    CPSSslConnection *con = soc->con;

    if (con->inbuf == 0) {
        if (soc->rcvbufp < 5) return;
        s = CPSi_TcpReadRaw(&len, (char *)soc);
        len = (s[3] << 8) + s[4] + 5;
        if (len > 0x4805) {
            con->state = 9;
            return;
        }
        con->inbuf = CPSiAlloc(len);
        if (con->inbuf == 0) {
            con->state = 9;
            return;
        }
        con->inbuf_len = len;
        con->inbuf_pnt = 0;
        con->inbuf_decrypted = 0;
    } else if (soc->rcvbufp == 0) {
        return;
    }
    s = CPSi_TcpReadRaw(&len, (char *)soc);
    if (len >= (unsigned long)(con->inbuf_len - con->inbuf_pnt)) {
        len = con->inbuf_len - con->inbuf_pnt;
        got_all = 1;
    } else {
        got_all = 0;
    }
    MI_CpuCopy8(s, con->inbuf + con->inbuf_pnt, len);
    CPSi_SocConsumeRaw(len, (struct _CPSSoc *)soc);
    if (got_all) {
        parse_record_in_buf(con, con->inbuf);
        if (con->inbuf_decrypted == 0) con->inbuf = 0;
    } else {
        con->inbuf_pnt += len;
    }
}
