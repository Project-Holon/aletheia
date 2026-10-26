/*
 * file:     gscrypt.c
 * function: gsCryptRSAVerifySignedHash
 * address:  0x0217CF5C
 * packet:   pkt_ov009_0217CF5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * closed:   2026-10-01 (wave 2 lane 20).  mwcc CSEs the stack parameter
 *           sigLen across blocks only as one conversion expression: with
 *           unsigned int params/mLength (DWARF), memcpy from libc string.h
 *           (size_t = unsigned long) and every scale spelled sizeof(u32),
 *           the compare, the division and the memcpy length are all
 *           (unsigned long)sigLen, so one ldr r2 feeds all three.  The @N
 *           initialiser templates then resolve too.
 * notes:    body is the exact upstream GameSpy gsCrypt.c spelling
 *           (scratch/U2/gs/src/GameSpy/common/gsCrypt.c:438).
 *
 * sdk:      gsCryptRSAVerifySignedHash (libdwcgscommon.TWL.HYB.a(gscrypt.o))
 *
 * symbols:
 *   memcpy  0x02092344  arm
 *   gsLargeIntReverseBytes  0x0217E934  arm  ov009
 *   gsLargeIntPowerMod  0x0217E078  arm  ov009
 *   memcmp  0x020923F0  arm
 *   @13305  0x021A19E8  data
 *   @13307  0x021A19D8  data
 */

#include "../libc/string.h"
#include "../types.h"

#include "../ov175/auth_types.h"

#include "gslargeint.h"
#include "../arm9/msl_string_mem.h"

int gsCryptRSAVerifySignedHash(const gsCryptRSAKey *publicKey, const u8 *hash, u32 hashLen, const u8 *sig, u32 sigLen)
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
    if (sigLen != publicKey->modulus.mLength * sizeof(u32))
        return -1;
    if (hashLen != 16 && hashLen != 20)
        return -1;
    lintRSASignature.mLength = sigLen / sizeof(u32);
    memcpy(lintRSASignature.mData, sig, sigLen);
    gsLargeIntReverseBytes((char *)(&lintRSASignature));
    gsLargeIntPowerMod(&lintRSASignature, (gsLargeInt_t *)&publicKey->exponent, (gsLargeInt_t *)&publicKey->modulus, &lintRSASignature);
    gsLargeIntReverseBytes((char *)(&lintRSASignature));
    if (packet[0] != 0 || packet[1] != 1)
        return -2;
    for (i = 2; i < 128; i++) {
        if (packet[i] == 0)
            break;
        if (packet[i] != 0xFF)
            return -3;
    }
    i++;
    if ((i + sizeof(md5Header) + 16) == lintRSASignature.mLength * sizeof(u32)) {
        if (memcmp(md5Header, &packet[i], sizeof(md5Header)) != 0)
            return -4;
        i += sizeof(md5Header);
        if (hashLen != 16)
            return -5;
        if (memcmp((unsigned char *)(&packet[i]), (unsigned char *)hash, 16) != 0)
            return -5;
    } else if ((i + sizeof(sha1Header) + 20) == lintRSASignature.mLength * sizeof(u32)) {
        if (memcmp(sha1Header, &packet[i], sizeof(sha1Header)) != 0)
            return -4;
        i += sizeof(sha1Header);
        if (hashLen != 20)
            return -5;
        if (memcmp((unsigned char *)(&packet[i]), (unsigned char *)hash, 20) != 0)
            return -5;
    } else {
        return -4;
    }
    return 0;
}
