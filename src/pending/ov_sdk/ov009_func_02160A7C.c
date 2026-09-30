/*
 * function: func_02160A7C
 * address:  0x02160A7C
 * packet:   pkt_ov009_02160A7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      rcv_certificate (libssl.TWL.HYB.a(ssl.o))
 *
 * blocker:  first divergence +0004: image `push {r3, r4, r5, r6, r7, r8, sb, sl,
 *           fp, lr}` | ours `push {r4, r5, r6, r7, r8, sb, sl, fp, lr}`; then
 *           +000C image `ldr r4, [sp, #0x44]` | ours `ldr r1, [sp, #0x44]`.
 *           Compiled 592 bytes against the image's 544.  The vendor object is
 *           byte identical to the image (0 concrete mismatches of 526 bytes),
 *           so this is a body-shape problem, not a boundary problem: the
 *           image keeps `s` in r4 and `con` in sl from the first instruction,
 *           and the leading `push {r0, r1, r2, r3}` (already reproduced) is
 *           the argument home its prologue needs.  See
 *           docs/notes/ov009_rcv_certificate.md for the full field map,
 *           DWARF register assignment and callee addresses.
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
    unsigned char *s2;
    int level;
    int parse_mode;
    int result;
    int result0;
    int this_certlen;
    int remaining_certlen;

    remaining_certlen = (s[2] << 16) + (s[1] << 8) + s[0];
    s += 3;
    level = 0;
    parse_mode = 0;
    con->f45c = -1;
    RTC_GetDate(&date);
    con->f80c = ((date.year + 0x7d0) << 16) + (date.month << 8) + date.day;
    con->f6b0 = 0;
    con->f5a0 = 0;
    con->f594 = 0;
    s2 = 0;
    result = 0;
    for (;;) {
        this_certlen = (s[2] << 16) + (s[1] << 8) + s[0];
        s += 3;
        remaining_certlen -= this_certlen + 3;
        con->hash_type = -1;
        con->f5ad = 0;
        con->f5ac = 0;
        con->f5af = 0;
        con->f6b0 = 0;
        con->dn[0] = 0;
        con->f7b0 = 0;
        con->f808 = this_certlen;
        con->f804 = s;
        if (cert_item(con, &s, 0, 0, parse_mode) != 0) {
            con->state = 9;
            return;
        }
        if (con->f594 < 0x33) {
            con->state = 9;
            return;
        }
        if (con->f5a0 != 0) {
            result = auth_cert(con);
            if (level == 0 && con->f800 != 0) {
                if (compare_fqdn(con->f800, (char *)(con + 1) + 0x7af) != 0)
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
            }
            result = (result & ~0xff) |
                     validate_signature(con, (SOCLCaInfo *)((char *)con + 0x480));
            if (con->f810 != 0)
                result = con->f810(result, con, level);
        }
        level++;
        if (result0 == 0)
            break;
        if (result != 0)
            break;
        if (remaining_certlen == 0)
            break;
        parse_mode = 1;
    }
    con->state = (result == 0) ? 3 : 9;
}
