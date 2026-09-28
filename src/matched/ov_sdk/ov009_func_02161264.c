/*
 * function: create_master_secret
 * address:  0x02161264
 * packet:   pkt_ov009_02161264
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      create_master_secret (ssl.o)
 *
 * symbols:
 *   create_ms_sub  0x021611C0  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_021A1D8C     0x021A1D8C  data
 *   d_021A1D90     0x021A1D90  data
 *   d_021A1D94     0x021A1D94  data
*/

struct _CPSSslConnection;

extern void create_ms_sub(unsigned char *d, char *salt,
                          struct _CPSSslConnection *con);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern char d_021A1D8C[];
extern char d_021A1D90[];
extern char d_021A1D94[];

static void create_master_secret(struct _CPSSslConnection *con)
{
    unsigned char tmp[48];

    create_ms_sub(tmp, d_021A1D8C, con);
    create_ms_sub(tmp + 0x10, d_021A1D90, con);
    create_ms_sub(tmp + 0x20, d_021A1D94, con);
    MI_CpuCopy8(tmp, con, 0x30);
}
