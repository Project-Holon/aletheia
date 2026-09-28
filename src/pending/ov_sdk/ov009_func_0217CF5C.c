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
 * notes:    draft; residue: the image loads sigLen once into r2 (this spelling reloads it for memcpy) and keeps i+1 as its own value for the length compares ((i+1)+0x22, (i+1)+0x23) where this spelling folds to i+0x23. The md5Header/sha1Header initializer templates (vendor @13305, @13307) have no overlay attestation class, so MATCH* is the ceiling in an overlay.
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

extern void *func_02092344();
extern int func_0217E934(gsLargeInt_t *lint);
extern int func_0217E078(gsLargeInt_t *b, gsLargeInt_t *p, gsLargeInt_t *m, gsLargeInt_t *dest);
extern int func_020923F0();

int func_0217CF5C(gsCryptRSAKey *publicKey, u8 *hash, unsigned int hashLen, u8 *sig, unsigned int sigLen)
{
    gsLargeInt_t lintRSASignature;
    u8 *packet = (u8 *)lintRSASignature.mData;
    int i;
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
    func_0217E078(&lintRSASignature, &publicKey->exponent, &publicKey->modulus, &lintRSASignature);
    func_0217E934(&lintRSASignature);
    if (packet[0] != 0 || packet[1] != 1)
        return -2;
    for (i = 2; i < 128; i++) {
        if (packet[i] == 0)
            break;
        if (packet[i] != 0xFF)
            return -3;
    }
    if (i + 1 + 18 + 16 == lintRSASignature.mLength * 4) {
        if (func_020923F0(md5Header, &packet[i + 1], 18) != 0)
            return -4;
        if (hashLen != 16)
            return -5;
        if (func_020923F0(&packet[i + 1 + 18], hash, 16) != 0)
            return -5;
    } else if (i + 1 + 15 + 20 == lintRSASignature.mLength * 4) {
        if (func_020923F0(sha1Header, &packet[i + 1], 15) != 0)
            return -4;
        if (hashLen != 20)
            return -5;
        if (func_020923F0(&packet[i + 1 + 15], hash, 20) != 0)
            return -5;
    } else {
        return -4;
    }
    return 0;
}
