/*
 * function: create_key_block
 * address:  0x021612C8
 * packet:   pkt_ov009_021612C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      create_key_block (ssl.o)
 *
 * blocker:  436 bytes vs 440.  Two residues: (1) the f32==4 / f32==5 size
 *           selection is laid out branch-first in the image (beq to the ==4
 *           block, predicated ver==5 block falls through) but this form emits
 *           the predicated block first then a branch; (2) register allocation:
 *           image len=sb(r9) p=fp(r11), compiled p=sb(r9) len=fp(r11).  The
 *           loop body, sha1/md5 chain and rc4_init tail otherwise line up.
 *
 * symbols:
 *   CPSi_sha1_init    0x02163C9C  arm
 *   CPSi_sha1_calc    0x02163CF0  arm
 *   CPSi_sha1_result  0x02163DA8  arm
 *   CPSi_md5_init     0x021633F0  arm
 *   CPSi_md5_calc     0x02163438  arm
 *   CPSi_md5_result   0x021634F0  arm
 *   CPSi_rc4_init     0x02163E40  arm
*/

struct _CPSSslConnection {
    char pad0[0x32];
    unsigned short f32;
    char pad1[0xbc - 0x34];
    void *fbc;
    void *fc0;
    char pad2[0x1d4 - 0xc4];
    void *f1d4;
    void *f1d8;
    char pad3[0x454 - 0x1dc];
    unsigned char f454;
    unsigned char f455;
};

extern void CPSi_sha1_init(void *ctx);
extern void CPSi_sha1_calc(void *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(void *ctx, unsigned char *digest);
extern void CPSi_md5_init(void *ctx);
extern void CPSi_md5_calc(void *ctx, void *data0, int datalen);
extern void CPSi_md5_result(void *ctx, unsigned char *digest);
extern void CPSi_rc4_init(void *ctx, unsigned char *key, int len);

static void create_key_block(struct _CPSSslConnection *con)
{
    int i, j;
    unsigned char c;
    unsigned char tmp[20];
    unsigned char *p;
    int size1, size2, size3;
    int len;

    if (con->f32 != 4) {
        if (con->f32 == 5) {
            size1 = 0x14;
            size2 = 0x10;
            size3 = 0;
        }
    } else {
        size1 = 0x10;
        size2 = 0x10;
        size3 = 0;
    }
    len = (size1 + size2 + size3) * 2;
    p = (unsigned char *)con + 0x74;
    for (i = 0; i * 16 < len; i++) {
        CPSi_sha1_init((char *)con + 0x348);
        c = 'A' + i;
        for (j = 0; j < i + 1; j++)
            CPSi_sha1_calc((char *)con + 0x348, &c, 1);
        CPSi_sha1_calc((char *)con + 0x348, con, 0x30);
        CPSi_sha1_calc((char *)con + 0x348, (char *)con + 0x54, 0x20);
        CPSi_sha1_calc((char *)con + 0x348, (char *)con + 0x34, 0x20);
        CPSi_sha1_result((char *)con + 0x348, tmp);
        CPSi_md5_init((char *)con + 0x3fc);
        CPSi_md5_calc((char *)con + 0x3fc, con, 0x30);
        CPSi_md5_calc((char *)con + 0x3fc, tmp, 0x14);
        CPSi_md5_result((char *)con + 0x3fc, p + i * 16);
    }
    if (con->f454 != 0) {
        con->f1d4 = p;
        con->f1d8 = p + size1 * 2;
        con->fbc = p + size1;
        con->fc0 = p + size1 * 2 + size2;
    } else {
        con->fbc = p;
        con->fc0 = p + size1 * 2;
        con->f1d4 = p + size1;
        con->f1d8 = p + size1 * 2 + size2;
    }
    CPSi_rc4_init((char *)con + 0x1e0, (unsigned char *)con->f1d8, 0x10);
    CPSi_rc4_init((char *)con + 0xc8, (unsigned char *)con->fc0, 0x10);
}
