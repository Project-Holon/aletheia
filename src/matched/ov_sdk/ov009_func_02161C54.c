/*
 * function: update_digest
 * address:  0x02161C54
 * packet:   pkt_ov009_02161C54
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      update_digest (ssl.o)
 *
 * symbols:
 *   CPSi_sha1_calc  0x02163CF0  arm
 *   CPSi_md5_calc   0x02163438  arm
*/

struct _CPSSslConnection;

typedef struct CPSSha1Ctx CPSSha1Ctx;
typedef struct CPSMd5Ctx CPSMd5Ctx;

extern void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen);

static void update_digest(struct _CPSSslConnection *con, unsigned char *s,
                          unsigned long len)
{
    CPSi_sha1_calc((CPSSha1Ctx *)((char *)con + 0x2ec), s, len);
    CPSi_md5_calc((CPSMd5Ctx *)((char *)con + 0x3a4), s, len);
}
