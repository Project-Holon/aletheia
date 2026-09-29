/*
 * function: make_ciphertext
 * address:  0x021619CC
 * packet:   pkt_ov009_021619CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      make_ciphertext (ssl.o)
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
 */

typedef struct CPSMd5Ctx CPSMd5Ctx;
typedef struct CPSSha1Ctx CPSSha1Ctx;
typedef struct CPSRc4Ctx CPSRc4Ctx;
struct _CPSSslConnection;

extern void CPSi_md5_init(CPSMd5Ctx *ctx);
extern void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPSi_md5_result(CPSMd5Ctx *ctx, unsigned char *digest);
extern void CPSi_sha1_init(CPSSha1Ctx *ctx);
extern void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest);
extern void CPSi_rc4_crypt(CPSRc4Ctx *ctx, unsigned char *data, int len);
extern void add1_be8(unsigned char *d);

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
