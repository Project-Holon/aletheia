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
 * blocker:  444 bytes vs 440 (U42).  SOLVED since the first draft: the size
 *           selection is a `switch (con->f32)` with `case 4` / `case 5` (a
 *           nested if emits a real branch for the ==5 arm, mwcc if-converts
 *           a switch arm into the predicated moveq/streq block at 0x21612E4).
 *           The loop is a `for` rotated by the compiler; `p` must NOT be live
 *           into the post-loop tail (spell `(unsigned char *)con + 0x74` out
 *           in the f454 block) or the len/p register pair swaps to
 *           p=sb(r9)/len=fp(r11) instead of the image's len=sb/p=fp.
 *           Residue now: the inner j-loop's address/constant hoists.  Image
 *           0x2161368 `add r5, sp, #8` (&c) and 0x216136C `mov r4, #1` sit
 *           BEFORE the sha1_init call; here they land after the
 *           `strb r0, [sp, #8]` (compiled 0x2161388).  Everything above
 *           0x2161368 is byte-identical.  A `do { } while` + explicit
 *           `if (0 < len)` entry guard (v16 in scratch/a2/laneU42/) is the
 *           closest form: 25 instructions identical, 278 concrete bytes.
 *           Size-exact alternative (440 bytes, 225 bytes out) is the same
 *           switch with `p` live into the tail - see v2.c/  v6.c in
 *           scratch/a2/laneU42/; that form's only residue is the len/p swap.
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

    switch (con->f32) {
    case 4:
        size1 = 0x10;
        size2 = 0x10;
        size3 = 0;
        break;
    case 5:
        size1 = 0x14;
        size2 = 0x10;
        size3 = 0;
        break;
    }
    len = (size1 + size2 + size3) * 2;
    i = 0;
    if (0 < len) {
        do {
        p = (unsigned char *)con + 0x74;
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
        i++;
        } while (i * 16 < len);
    }
    if (con->f454 != 0) {
        con->f1d4 = (unsigned char *)con + 0x74;
        con->f1d8 = (unsigned char *)con + 0x74 + size1 * 2;
        con->fbc = (unsigned char *)con + 0x74 + size1;
        con->fc0 = (unsigned char *)con + 0x74 + size1 * 2 + size2;
    } else {
        con->fbc = (unsigned char *)con + 0x74;
        con->fc0 = (unsigned char *)con + 0x74 + size1 * 2;
        con->f1d4 = (unsigned char *)con + 0x74 + size1;
        con->f1d8 = (unsigned char *)con + 0x74 + size1 * 2 + size2;
    }
    CPSi_rc4_init((char *)con + 0x1e0, (unsigned char *)con->f1d8, 0x10);
    CPSi_rc4_init((char *)con + 0xc8, (unsigned char *)con->fc0, 0x10);
}
