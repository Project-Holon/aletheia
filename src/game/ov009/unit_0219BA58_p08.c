/*
 * file:     unit_0219BA58_p08.c
 * unit:     yes
 * function: func_0219C3A4
 * address:  0x0219C3A4
 * packet:   pkt_ov009_0219C3A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * CLOSED 2026-10-01 (user-approved rule extension): the template rule's prong (b)
 *   now also counts a copy owned by a named global. The twin of @13818 at 0x021A5A7C
 *   is NNMagicData, named by eight located natneg.o/dwc_match.o slots, so 0x021A1B64
 *   is the only copy @13818 can be. A dry run over all 479 non-unique template sites
 *   changed only this verdict. The history below is kept for the record.
 *
 * former blocker:  +0198 ABS32 @13818 -> 0x021A1B64, the vendor object's six-byte
 *           initializer template of natNegBytes.  Exactly one word in the
 *           whole image names 0x021A1B64 and it is this function's own pool
 *           word at +0198 (0x0219C53C), inside the compared range
 *           0219C3A4..0219C554, so `literal` discards its only witness and
 *           every other address-based class refuses too: no label, no
 *           string, no data table, no EXACT entry, and the ov009 listing
 *           attests no object start at 0x021A1B64 (`starts` from
 *           asm/overlays/ov009.s holds it neither as a d_/g_/tbl_/pool_ label
 *           nor as the first datum of a run; layout/data_objects.txt has no
 *           row).  The vendor-object `template` class is the only rule that
 *           could witness it from outside the range, and it refuses on both
 *           prongs -- see below.
 *
 * sdk:      qr_process_client_message (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_02199DFC  0x02199DFC  arm  ov009
 *   func_0219BA58  0x0219BA58  arm  ov009
 *   func_0219BA54  0x0219BA54  arm  ov009
 *   @13818         0x021A1B64  data
 *   g_021A7858     0x021A7858  data
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021ACEFC     0x021ACEFC  data
 *
 * MATCH: all 399 concrete bytes equal, one relocation without a witness.
 * Eight of the nine sites resolve; only @13818 does not.
 *
 * Why `template` refuses @13818 (qr2.o, the local @N of the ABS32 at +0198,
 * six bytes FD FC 1E 66 6A B2, section alignment 1):
 *   (a) uniqueness fails.  The image holds those six bytes at two 1-aligned
 *       addresses of ov009: 0x021A1B64, our own template, and 0x021A5A7C,
 *       which is the head of the named global NNMagicData (the same six
 *       bytes, then "NNFreeNegotiateL...").  `_template_hits()` returns
 *       ['021A1B64', '021A5A7C'], so the pattern is not unique in ov009.
 *   (b) elimination finds no claim.  `_template_claims()` scans every row of
 *       libdwcgsqr2.TWL.HYB.a in ov009, located with 0 mismatches, for a
 *       slot outside 0219C3A4..0219C554 that relocates a local `@K` of six
 *       equal bytes onto the other occurrence; it returns [].  The nine pool
 *       words that name 0x021A5A7C are 0x0216E5AC (libdwcmatch.TWL.HYB.a),
 *       seven in libdwcgsnatneg.TWL.HYB.a (natify.o/natneg.o: 0x02198E58,
 *       0x021992A4, 0x021994D4, 0x02199718, 0x02199A64, 0x02199BDC,
 *       0x0219A618) and 0x0219CD84 -- the last is in our own archive, but
 *       qr2_parse_queryA relocates that slot against the UNDEFINED global
 *       NNMagicData, not against a local template, so it is no claim.
 * So the constant has a named twin in the same overlay and the class that
 * was built for exactly this object declines.  Not a version-stamp residue:
 * the vendor object is Metrowerks 4.0.0.1025 and no tools/mwccarm build
 * writes that stamp, yet sdkobj locate() reports 0 concrete mismatches of
 * 399 concrete bytes and all 399 reproduce here.
 *
 * The one spelling that would move the verdict is naming the object instead
 * of initialising the local from it (`memcpy(natNegBytes, g_..., 6)` against
 * an extern declared 0x021A1B64).  That routes the site to attest() instead
 * of the vendor rule, where it resolves only as `sole-ref/self` -- the ROM
 * word at the site agreeing with itself, the weakest class -- and it is not
 * byte-identical: the memcpy form diffs in 75 concrete bytes (qrec moves to
 * r8, the six stores land in source order instead of around the
 * gsDebugFormat argument setup).  Not pursued: it would trade a strong
 * refused class for a weak one and mean rewriting the body.
 *
 * lane U41 (2026-09-30).  Re-measured MATCH: 432/432, 399 concrete bytes equal,
 * 8 of 9 relocations resolved, only +0198/@13818 unresolved.  Re-tested the two
 * candidate re-spellings that would move the site onto a named extern so the
 * template rule is bypassed: six explicit `natNegBytes[k] = g_021A1B64[k];`
 * assignments compile 432 bytes with 45 concrete diffs (the loop base stays in
 * r2 and the id arrive in r8 in the image), and `memcpy(natNegBytes,
 * g_021A1B64, 6)` gives 75.  Both are far from the initialiser form's 0, so the
 * template rule is the only route and its uniqueness prong is defeated by the
 * NNMagicData twin at 0x021A5A7C, which no libdwcgsqr2 slot outside this range
 * claims.  Residue named; no shard written.
 *
 * How the other data absolutes stand, for the record:
 *   - g_021A7858 (the vendor's @14807) resolves as `sole-ref/self`.
 *   - g_021ACEF8 and g_021ACEFC (__GSIACResult and __GSIACGamename, i.e. the
 *     start and start+4 of one global, as the catalog suggests) resolve as
 *     `sole-ref/data`: the ov009 listing attests an object start at both, so
 *     they are the strongest of the three.
 */

#include "../../matched/arm9_sdk/libc/string.h" /* "../arm9_sdk/libc/string.h" once under src/matched */

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct qr2_implementation_s {
    int hbsock;                                              /* 0x000 */
    char gamename[64];                                       /* 0x004 */
    char pad044[0xA0 - 0x44];
    void (*nn_callback)(int cookie, void *userdata);         /* 0x0A0 */
    void (*cm_callback)(char *data, int len, void *userdata); /* 0x0A4 */
    void *pa_callback;                                       /* 0x0A8 */
    void *cc_callback;                                       /* 0x0AC */
    char pad0b0[0x114 - 0xB0];
    void *udata;                                             /* 0x114 */
} *qr2_t;

extern void func_0217D254(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern unsigned long func_021803BC(char *dst, const char *src, unsigned long size);
extern int func_02199DFC(int gamesocket, int cookie, int clientindex,
                         void (*progresscallback)(int, void *),
                         void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
extern void func_0219BA58(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata);
extern void func_0219BA54(int state, void *userdata);

extern char g_021A7858[];
extern int g_021ACEF8;
extern char g_021ACEFC[];

/*
 * CLOSED 2026-10-01 (user-approved rule extension): the template rule's prong (b)
 *   now also counts a copy owned by a named global. The twin of @13818 at 0x021A5A7C
 *   is NNMagicData, named by eight located natneg.o/dwc_match.o slots, so 0x021A1B64
 *   is the only copy @13818 can be. A dry run over all 479 non-unique template sites
 *   changed only this verdict. The history below is kept for the record.
 *
 * former blocker:  +0198 ABS32 @13818 -> 0x021A1B64, the vendor object's six-byte
 *           initializer template of natNegBytes.  Exactly one word in the
 *           whole image names 0x021A1B64 and it is this function's own pool
 *           word at +0198 (0x0219C53C), inside the compared range
 *           0219C3A4..0219C554, so `literal` discards its only witness and
 *           every other address-based class refuses too: no label, no
 *           string, no data table, no EXACT entry, and the ov009 listing
 *           attests no object start at 0x021A1B64 (`starts` from
 *           asm/overlays/ov009.s holds it neither as a d_/g_/tbl_/pool_ label
 *           nor as the first datum of a run; layout/data_objects.txt has no
 *           row).  The vendor-object `template` class is the only rule that
 *           could witness it from outside the range, and it refuses on both
 *           prongs -- see below.
 *
 * sdk:      qr_process_client_message (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * MATCH: all 399 concrete bytes equal, one relocation without a witness.
 * Eight of the nine sites resolve; only @13818 does not.
 *
 * Why `template` refuses @13818 (qr2.o, the local @N of the ABS32 at +0198,
 * six bytes FD FC 1E 66 6A B2, section alignment 1):
 *   (a) uniqueness fails.  The image holds those six bytes at two 1-aligned
 *       addresses of ov009: 0x021A1B64, our own template, and 0x021A5A7C,
 *       which is the head of the named global NNMagicData (the same six
 *       bytes, then "NNFreeNegotiateL...").  `_template_hits()` returns
 *       ['021A1B64', '021A5A7C'], so the pattern is not unique in ov009.
 *   (b) elimination finds no claim.  `_template_claims()` scans every row of
 *       libdwcgsqr2.TWL.HYB.a in ov009, located with 0 mismatches, for a
 *       slot outside 0219C3A4..0219C554 that relocates a local `@K` of six
 *       equal bytes onto the other occurrence; it returns [].  The nine pool
 *       words that name 0x021A5A7C are 0x0216E5AC (libdwcmatch.TWL.HYB.a),
 *       seven in libdwcgsnatneg.TWL.HYB.a (natify.o/natneg.o: 0x02198E58,
 *       0x021992A4, 0x021994D4, 0x02199718, 0x02199A64, 0x02199BDC,
 *       0x0219A618) and 0x0219CD84 -- the last is in our own archive, but
 *       qr2_parse_queryA relocates that slot against the UNDEFINED global
 *       NNMagicData, not against a local template, so it is no claim.
 * So the constant has a named twin in the same overlay and the class that
 * was built for exactly this object declines.  Not a version-stamp residue:
 * the vendor object is Metrowerks 4.0.0.1025 and no tools/mwccarm build
 * writes that stamp, yet sdkobj locate() reports 0 concrete mismatches of
 * 399 concrete bytes and all 399 reproduce here.
 *
 * The one spelling that would move the verdict is naming the object instead
 * of initialising the local from it (`memcpy(natNegBytes, g_..., 6)` against
 * an extern declared 0x021A1B64).  That routes the site to attest() instead
 * of the vendor rule, where it resolves only as `sole-ref/self` -- the ROM
 * word at the site agreeing with itself, the weakest class -- and it is not
 * byte-identical: the memcpy form diffs in 75 concrete bytes (qrec moves to
 * r8, the six stores land in source order instead of around the
 * gsDebugFormat argument setup).  Not pursued: it would trade a strong
 * refused class for a weak one and mean rewriting the body.
 *
 * lane U41 (2026-09-30).  Re-measured MATCH: 432/432, 399 concrete bytes equal,
 * 8 of 9 relocations resolved, only +0198/@13818 unresolved.  Re-tested the two
 * candidate re-spellings that would move the site onto a named extern so the
 * template rule is bypassed: six explicit `natNegBytes[k] = g_021A1B64[k];`
 * assignments compile 432 bytes with 45 concrete diffs (the loop base stays in
 * r2 and the id arrive in r8 in the image), and `memcpy(natNegBytes,
 * g_021A1B64, 6)` gives 75.  Both are far from the initialiser form's 0, so the
 * template rule is the only route and its uniqueness prong is defeated by the
 * NNMagicData twin at 0x021A5A7C, which no libdwcgsqr2 slot outside this range
 * claims.  Residue named; no shard written.
 *
 * How the other data absolutes stand, for the record:
 *   - g_021A7858 (the vendor's @14807) resolves as `sole-ref/self`.
 *   - g_021ACEF8 and g_021ACEFC (__GSIACResult and __GSIACGamename, i.e. the
 *     start and start+4 of one global, as the catalog suggests) resolve as
 *     `sole-ref/data`: the ov009 listing attests an object start at both, so
 *     they are the strongest of the three.
 */
void func_0219C3A4(qr2_t qrec, char *buf, int len)
{
    unsigned char natNegBytes[6] = {0xFD, 0xFC, 0x1E, 0x66, 0x6A, 0xB2};
    int i;
    int isnatneg = 1;
    int cookie;

    func_0217D254(3, 4, 8, g_021A7858);

    if (len >= 10) {
        for (i = 0; i < 6; i++) {
            if ((unsigned char)buf[i] != natNegBytes[i]) {
                isnatneg = 0;
                break;
            }
        }
    } else
        isnatneg = 0;

    if (isnatneg) {
        memcpy(&cookie, buf + 6, 4);
        cookie = (int)((((unsigned int)cookie >> 24) & 0xFF) | (((unsigned int)cookie >> 8) & 0xFF00)
                       | (((unsigned int)cookie << 8) & 0xFF0000) | (((unsigned int)cookie << 24) & 0xFF000000));
        if (qrec->cc_callback) {
            if (g_021ACEF8 != 1) {
                g_021ACEF8 = 1;
                func_021803BC(g_021ACEFC, qrec->gamename, 64);
            }
            func_02199DFC(qrec->hbsock, cookie, 1, func_0219BA54, func_0219BA58, qrec);
        } else if (qrec->nn_callback)
            qrec->nn_callback(cookie, qrec->udata);
    } else if (qrec->cm_callback)
        qrec->cm_callback(buf, len, qrec->udata);
}
