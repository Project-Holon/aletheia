/*
 * function: func_0217CF5C
 * address:  0x0217CF5C
 * packet:   pkt_ov009_0217CF5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  allocator tie, 4 B excess (560 vs 556).  The stack parameter
 *           `sigLen` is rematerialised: the front end loads it into r1 for the
 *           `sigLen != publicKey->modulus.mLength*4` compare (+007C) and reloads
 *           it into r2 at the func_02092344 length argument (+00A8); the image
 *           keeps ONE web in r2 from that compare, through the hashLen guard, to
 *           the call (ldr r2,[sp,#0x140] at 0x0217CFD8, never reloaded).
 *           The post-loop `k = i + 1` (source `i++;`) is now in r1 as in the
 *           image, so the remaining 4 B is exactly the sigLen reload; the two
 *           allocations are coupled (if sigLen takes r2, r1 is free for k).
 *           Tried this lane: `const` on publicKey/hash/sig (upstream spelling),
 *           upstream `int i=0` + `i++` + `sizeof(header)`, a named `u32 len =
 *           sigLen` used for compare/`/4`/argument, mLength assignment hoisted
 *           above the hashLen guard (378 concrete, worse), `>> 2`, swapped
 *           operand order.  All 560/358 or flat, none 556.
 *           Separate, unavoidable-in-overlay blocker: the two compiler
 *           initialiser template literals (@18/@20 here; vendor @13305/@13307)
 *           have no overlay attestation class, so only 8/10 relocs resolve and
 *           MATCH* is the ceiling even if the size ties.
 * notes:    body is the exact upstream GameSpy gsCrypt.c spelling
 *           (scratch/U2/gs/src/GameSpy/common/gsCrypt.c:438).
 *
 * sdk:      gsCryptRSAVerifySignedHash (libdwcgscommon.TWL.HYB.a(gscrypt.o))
 *
 * symbols:
 *   func_02092344  0x02092344  arm
 *   func_0217E934  0x0217E934  arm  ov009
 *   func_0217E078  0x0217E078  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   @13305  0x021A19E8  data
 *   @13307  0x021A19D8  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct gsLargeInt_s {
    u32 mLength;
    u32 mData[64];
} gsLargeInt_t;

typedef struct {
    gsLargeInt_t modulus;
    gsLargeInt_t exponent;
} gsCryptRSAKey;

extern void *func_02092344(const void *, const void *, u32);
extern int func_0217E934(gsLargeInt_t *lint);
extern int func_0217E078(gsLargeInt_t *b, gsLargeInt_t *p, gsLargeInt_t *m, gsLargeInt_t *dest);
extern int func_020923F0(const void *, const void *, u32);

int func_0217CF5C(const gsCryptRSAKey *publicKey, const u8 *hash, u32 hashLen, const u8 *sig, u32 sigLen)
{
    gsLargeInt_t lintRSASignature;
    u8 *packet = (u8 *)lintRSASignature.mData;
    int i = 0;
    u8 md5Header[18] = {
        0x30, 0x20, 0x30, 0x0C, 0x06, 0x08, 0x2A, 0x86, 0x48,
        0x86, 0xF7, 0x0D, 0x02, 0x05, 0x05, 0x00, 0x04, 0x10
    };
    u8 sha1Header[15] = {
        0x30, 0x21, 0x30, 0x09, 0x06, 0x05, 0x2B, 0x0E,
        0x03, 0x02, 0x1A, 0x05, 0x00, 0x04, 0x14
    };

    if (hash == 0 || sig == 0)
        return -1;
    if (sigLen != publicKey->modulus.mLength * 4)
        return -1;
    if (hashLen != 16 && hashLen != 20)
        return -1;
    lintRSASignature.mLength = sigLen / 4;
    func_02092344(lintRSASignature.mData, sig, sigLen);
    func_0217E934(&lintRSASignature);
    func_0217E078(&lintRSASignature, (gsLargeInt_t *)&publicKey->exponent, (gsLargeInt_t *)&publicKey->modulus, &lintRSASignature);
    func_0217E934(&lintRSASignature);
    if (packet[0] != 0 || packet[1] != 1)
        return -2;
    for (i = 2; i < 128; i++) {
        if (packet[i] == 0)
            break;
        if (packet[i] != 0xFF)
            return -3;
    }
    i++;
    if ((i + sizeof(md5Header) + 16) == lintRSASignature.mLength * 4) {
        if (func_020923F0(md5Header, &packet[i], sizeof(md5Header)) != 0)
            return -4;
        i += sizeof(md5Header);
        if (hashLen != 16)
            return -5;
        if (func_020923F0(&packet[i], hash, 16) != 0)
            return -5;
    } else if ((i + sizeof(sha1Header) + 20) == lintRSASignature.mLength * 4) {
        if (func_020923F0(sha1Header, &packet[i], sizeof(sha1Header)) != 0)
            return -4;
        i += sizeof(sha1Header);
        if (hashLen != 20)
            return -5;
        if (func_020923F0(&packet[i], hash, 20) != 0)
            return -5;
    } else {
        return -4;
    }
    return 0;
}
