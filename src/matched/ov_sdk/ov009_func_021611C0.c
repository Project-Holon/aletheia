/*
 * function: create_ms_sub
 * address:  0x021611C0
 * packet:   pkt_ov009_021611C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      create_ms_sub (ssl.o)
 *
 * symbols:
 *   CPSi_sha1_init    0x02163C9C  arm
 *   CPSi_sha1_calc    0x02163CF0  arm
 *   CPSi_sha1_result  0x02163DA8  arm
 *   CPSi_md5_init     0x021633F0  arm
 *   CPSi_md5_calc     0x02163438  arm
 *   CPSi_md5_result   0x021634F0  arm
 *   strlen            0x0209477C  arm
*/

struct _CPSSslConnection;

extern void CPSi_sha1_init(void *ctx);
extern void CPSi_sha1_calc(void *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(void *ctx, unsigned char *digest);
extern void CPSi_md5_init(void *ctx);
extern void CPSi_md5_calc(void *ctx, void *data0, int datalen);
extern void CPSi_md5_result(void *ctx, unsigned char *digest);
extern int strlen(const char *s);

static void create_ms_sub(unsigned char *d, char *salt,
                          struct _CPSSslConnection *con)
{
    unsigned char tmp[20];

    CPSi_sha1_init((char *)con + 0x348);
    CPSi_sha1_calc((char *)con + 0x348, salt, strlen(salt));
    CPSi_sha1_calc((char *)con + 0x348, con, 0x30);
    CPSi_sha1_calc((char *)con + 0x348, (char *)con + 0x34, 0x40);
    CPSi_sha1_result((char *)con + 0x348, tmp);
    CPSi_md5_init((char *)con + 0x3fc);
    CPSi_md5_calc((char *)con + 0x3fc, con, 0x30);
    CPSi_md5_calc((char *)con + 0x3fc, tmp, 0x14);
    CPSi_md5_result((char *)con + 0x3fc, d);
}
