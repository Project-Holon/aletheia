/*
 * function: func_02160A7C
 * address:  0x02160A7C
 * packet:   pkt_ov009_02160A7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      rcv_certificate (libssl.TWL.HYB.a(ssl.o))
 *
 * note:     EXACT (2026-10-01). Closed by the vendor listing's branch targets: the
 *           result0==1 skip lands past validate_signature, so the bic/orr runs
 *           inside that if, as `result = (result & ~0xff) | validate_signature()`;
 *           and `con->f804 = s;` is written before `con->f808 = this_certlen;`
 *           (the reverse order let the f808 store hoist and stole r6 from
 *           parse_mode).
 *
 * symbols:
 *   RTC_GetDate        0x02088864  arm
 *   cert_item          0x021602B8  arm  ov009
 *   auth_cert          0x0216090C  arm  ov009
 *   compare_fqdn       0x02160A10  arm  ov009
 *   validate_signature 0x02160764  arm  ov009
 */

typedef struct RTCDate {
    int year;
    int month;
    int day;
    int week;
} RTCDate;

typedef struct SOCLCaInfo SOCLCaInfo;

typedef struct CPSSslConnection {
    unsigned char pad0[0x348];
    unsigned char sha1[0x3fc - 0x348];      /* +0x348 */
    unsigned char t1[0x455 - 0x3fc];
    unsigned char state;                    /* +0x455 */
    unsigned char t2[0x458 - 0x456];
    int hash_type;                          /* +0x458 */
    int f45c;                               /* +0x45c */
    unsigned char *cert_start;              /* +0x460 */
    unsigned char *cert_end;                /* +0x464 */
    unsigned char hash[0x47c - 0x468];      /* +0x468 */
    int hash_len;                           /* +0x47c */
    unsigned char t3[0x594 - 0x480];
    int f594;                               /* +0x594 */
    unsigned char t4[0x5a0 - 0x598];
    int f5a0;                               /* +0x5a0 */
    unsigned char t5[0x5ac - 0x5a4];
    unsigned char f5ac;                     /* +0x5ac */
    unsigned char f5ad;                     /* +0x5ad */
    unsigned char t6[0x5af - 0x5ae];
    unsigned char f5af;                     /* +0x5af */
    unsigned char dn[0x6b0 - 0x5b0];        /* +0x5b0 */
    unsigned char f6b0;                     /* +0x6b0 */
    unsigned char t7[0x7b0 - 0x6b1];
    unsigned char f7b0;                     /* +0x7b0 */
    unsigned char t8[0x800 - 0x7b1];
    char *f800;                             /* +0x800 */
    unsigned char *f804;                    /* +0x804 */
    int f808;                               /* +0x808 */
    int f80c;                               /* +0x80c */
    int (*f810)(int result, struct CPSSslConnection *con, int level);  /* +0x810 */
} CPSSslConnection;

extern int RTC_GetDate(RTCDate *date);
extern int cert_item(CPSSslConnection *con, unsigned char **ps, int level,
                     int seq, int mode);
extern int auth_cert(CPSSslConnection *con);
extern int compare_fqdn(char *name, char *pat);
extern int validate_signature(CPSSslConnection *con, SOCLCaInfo *ca);

static void func_02160A7C(CPSSslConnection *con, unsigned char *s)
{
    RTCDate date;
    int result0;
    int result;
    int remaining_certlen;
    int this_certlen;
    unsigned char *s2;
    int parse_mode;
    int level;

    remaining_certlen = (((s[0] << 8) + s[1]) << 8) + s[2];
    s += 3;
    con->f45c = -1;
    RTC_GetDate(&date);
    parse_mode = 0;
    level = 0;
    con->f80c = ((date.year + 2000) << 16) + (date.month << 8) + date.day;
    con->f6b0 = 0;
    con->f5a0 = 0;
    con->f594 = 0;
    for (;;) {
        this_certlen = (((s[0] << 8) + s[1]) << 8) + s[2];
        s += 3;
        remaining_certlen -= this_certlen + 3;
        con->hash_type = -1;
        con->f5ad = 0;
        con->f5ac = 0;
        con->f5af = 0;
        con->f6b0 = 0;
        con->dn[0] = 0;
        con->f7b0 = 0;
        con->f804 = s;
        con->f808 = this_certlen;

        if (cert_item(con, &s, 0, 0, parse_mode) != 0 || (unsigned int)con->f594 < 0x33 ||
            con->f5a0 == 0) {
            con->state = 9;
            return;
        }
        result = auth_cert(con);
        if (level == 0 && con->f800 != 0) {
            if (compare_fqdn(con->f800, (char *)&con->f7b0) != 0)
                result |= 0x4000;
        }
        result0 = result & 0xff;
        if (result0 == 1 && remaining_certlen != 0) {
            s2 = s + 3;
            con->f5ad = 0;
            if (cert_item(con, &s2, 0, 0, 2) != 0) {
                con->state = 9;
                return;
            }
            result = (result & ~0xff) | validate_signature(con, (SOCLCaInfo *)((char *)con + 0x480));
        }
        if (con->f810 != 0)
            result = con->f810(result, con, level);
        level++;
        if (result0 == 0 || result != 0 || remaining_certlen == 0)
            break;
        parse_mode = 1;
    }
    if (result == 0)
        con->state = 3;
    else
        con->state = 9;
}
