/*
 * function: func_0216090C
 * address:  0x0216090C
 * packet:   pkt_ov009_0216090C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      auth_cert (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_021633F0  0x021633F0  arm  ov009
 *   func_02163438  0x02163438  arm  ov009
 *   func_021634F0  0x021634F0  arm  ov009
 *   func_02163C9C  0x02163C9C  arm  ov009
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   func_02163DA8  0x02163DA8  arm  ov009
 *   func_02160130  0x02160130  arm  ov009
 *   func_02160764  0x02160764  arm  ov009
 */

typedef struct SOCLCaInfo SOCLCaInfo;

typedef struct CPSSslConnection {
    unsigned char pad0[0x348];
    unsigned char sha1[0x3fc - 0x348];  /* +0x348 */
    unsigned char md5[0x458 - 0x3fc];   /* +0x3fc */
    int hash_type;                      /* +0x458 */
    int f45c;                           /* +0x45c */
    unsigned char *cert_start;          /* +0x460 */
    unsigned char *cert_end;            /* +0x464 */
    unsigned char hash[0x47c - 0x468];  /* +0x468 */
    int hash_len;                       /* +0x47c */
    unsigned char pad480[0x5af - 0x480];
    unsigned char f5af;                 /* +0x5af */
    char dn[1];                         /* +0x5b0 */
} CPSSslConnection;

extern void func_021633F0(void *ctx);
extern void func_02163438(void *ctx, void *data0, int datalen);
extern void func_021634F0(void *ctx, unsigned char *digest);
extern void func_02163C9C(void *ctx);
extern void func_02163CF0(void *ctx, void *data0, int datalen);
extern void func_02163DA8(void *ctx, unsigned char *digest);
extern SOCLCaInfo *func_02160130(CPSSslConnection *con, char *dn);
extern int func_02160764(struct CPSSslConnection *con, struct SOCLCaInfo *ca);

static int func_0216090C(CPSSslConnection *con)
{
    int result;
    SOCLCaInfo *p;

    result = 0;
    if (con->f5af == 0)
        result = 0x8000;
    if (con->f45c == -1)
        return result | 4;
    switch (con->hash_type) {
    case 3:
        func_021633F0(con->md5);
        func_02163438(con->md5, con->cert_start, con->cert_end - con->cert_start);
        func_021634F0(con->md5, con->hash);
        con->hash_len = 0x10;
        break;
    case 4:
        func_02163C9C(con->sha1);
        func_02163CF0(con->sha1, con->cert_start, con->cert_end - con->cert_start);
        func_02163DA8(con->sha1, con->hash);
        con->hash_len = 0x14;
        break;
    default:
        return result | 3;
    }
    p = func_02160130(con, con->dn);
    if (p == 0)
        return result | 1;
    return result | func_02160764(con, p);
}
