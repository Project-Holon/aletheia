/*
 * function: func_02162CA0
 * address:  0x02162CA0
 * packet:   pkt_ov009_02162CA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SslWrite2 (libssl.TWL.HYB.a ssl.o)
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021619CC  0x021619CC  arm  ov009
 *   CPSi_TcpWrite2Raw  0x0215B198  arm  ov009
 *   g_021A8280     0x021A8280  data ov009
 *   g_021A82B0     0x021A82B0  data ov009
 *
 * Writes a two-part buffer as SSL application-data records of at most 2895 bytes; returns the bytes sent.
 */

typedef struct CPSSoc {
    unsigned char pad[0xC];
    void *con;
} CPSSoc;

extern void *(*g_021A8280)(unsigned long size);
extern void (*g_021A82B0)(void *p);
extern int func_021619CC(void *con, unsigned char *s);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct _CPSSoc;
extern u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);

unsigned long func_02162CA0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, CPSSoc *soc)
{
    CPSSoc *con = (CPSSoc *)soc->con;
    unsigned char *tmp;
    long total_len;
    long part1_len;
    long this_len;
    long part2_len;
    long total_sent_len;
    long this_sent_len;
    total_sent_len = 0;
    total_len = len + len2;
    do {
        this_len = (total_len > 2895) ? 2895 : total_len;
        tmp = (unsigned char *)g_021A8280(this_len + 25);
        if (!tmp) break;
        part1_len = (len >= (unsigned long)this_len) ? this_len : len;
        part2_len = this_len - part1_len;
        MI_CpuCopy8(buf, tmp + 5, part1_len);
        buf += part1_len;
        len -= part1_len;
        MI_CpuCopy8(buf2, tmp + 5 + part1_len, part2_len);
        tmp[0] = 23;
        tmp[1] = 3;
        tmp[2] = 0;
        tmp[3] = this_len >> 8;
        buf2 += part2_len;
        tmp[4] = this_len;
        this_sent_len = func_021619CC(con, tmp);
        if (CPSi_TcpWrite2Raw(tmp, this_sent_len, 0, 0, (struct _CPSSoc *)soc) < (unsigned long)this_sent_len) this_len = 0;
        g_021A82B0(tmp);
        total_sent_len += this_len;
        total_len -= this_len;
        if (total_len == 0) break;
    } while (this_len != 0);
    return total_sent_len;
}
