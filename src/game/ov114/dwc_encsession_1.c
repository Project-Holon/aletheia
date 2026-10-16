/*
 * file:     dwc_encsession_1.c
 * unit:     yes
 * function: b64size, my_randinit, my_rand, DWCi_EncValidateKey, DWCi_EncSessionValidateResponse, DWCi_EncSessionProgressCallback
 * address:  0x021C9858
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from dwc_encsession.c by tools/splitfile.py.
 *
 * symbols:
 *   gDwcEncSession     0x021CF7AC  data
 *   gDwcEncRandState     0x021D4228  data
 *   strlen  0x0209477C  arm
 *   strncpy  0x02094860  arm
 *   DWC_Alloc  0x0205A16C  arm
 *   DWC_Free  0x0205A1B0  arm
 *   func_020816B8  0x020816B8  arm
 *   strncmp  0x020949F4  arm
 *   B64Encode  0x0217FA90  arm  ov009
 *   @16077  0x021CE1B8  data
 *   @16117  0x021CE1CC  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "dwc_encsession_types.h"
#include "dwc_ghttp_types.h"

extern int strncmp(const char *a, const char *b, unsigned long n);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern void *DWC_Alloc(int name, u32 size);
extern void DWC_Free(int name, void *ptr, u32 size);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);
extern void func_020816B8(void *digest, void *data, u32 len);

unsigned long b64size(unsigned long len);
void my_randinit(u32 seed);
unsigned char my_rand(void);
int DWCi_EncValidateKey(char *gameName, const char *secretKey, unsigned long multiplier, unsigned long increment, unsigned long modulus, unsigned long checksumMask);
int DWCi_EncSessionValidateResponse(char *response, int responseLen);
void DWCi_EncSessionProgressCallback(int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);

/*
 * Length of the base64 encoding of `len` bytes (with padding).
 */
unsigned long b64size(unsigned long len)
{
    return (len / 3 + (len % 3 != 0 ? 1 : 0)) * 4;
}

/*
 * Seeds the request cipher PRNG: the 16-bit seed is duplicated across both halves of the state word.
 */
void my_randinit(u32 seed)
{
    gDwcEncRandState = seed | ((u32)seed << 16);
}

/*
 * Linear congruential generator over the session constants; returns the high 16 sCryptoBnNumBitsWordBits of the state
 * truncated to a byte.
 */
unsigned char my_rand(void)
{
    gDwcEncRandState = (gDwcEncSession.randMultiplier * gDwcEncRandState + gDwcEncSession.randIncrement) % gDwcEncSession.randModulus;
    return gDwcEncRandState >> 16;
}

/*
 * Checks the game name, secret key and cipher constants and stores them in the session.
 * The 20-byte key copy is the compiler's 2x unrolled byte loop.  The r0/r1
 * assignment of the two byte temporaries is fixed by declaring the parameter
 * const (the compiler then keeps the loaded pair in r0=hi, r1=lo, matching
 * the image) and by interleaving the source-store advance (`s += 2`)
 * between the two destination stores.
 */
int DWCi_EncValidateKey(char *gameName, const char *secretKey, unsigned long multiplier, unsigned long increment, unsigned long modulus, unsigned long checksumMask)
{
    int bitCount = 0;
    int i;
    unsigned int n;

    gDwcEncSession.isKeyValid = 0;
    if ((unsigned long)strlen(gameName) >= 0x20) {
        return 0;
    }
    if ((unsigned long)strlen(secretKey) != 0x14) {
        return 0;
    }
    if ((multiplier - 5) & 7) {
        return 0;
    }
    if ((increment & 1) == 0) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        if (((modulus >> i) & 1) == 1) {
            bitCount++;
        }
    }
    if (bitCount != 1) {
        return 0;
    }
    strncpy(gDwcEncSession.gameName, gameName, 0x20);
    {
        unsigned char *d = (unsigned char *)gDwcEncSession.secretKey;
        unsigned char *s = (unsigned char *)secretKey;
        for (n = 10; n != 0; n--) {
            unsigned char x0;
            unsigned char x1;
            x1 = s[1];
            x0 = s[0];
            d[1] = x1;
            s += 2;
            d[0] = x0;
            d += 2;
        }
    }
    gDwcEncSession.randMultiplier = multiplier;
    gDwcEncSession.randIncrement = increment;
    gDwcEncSession.randModulus = modulus;
    gDwcEncSession.checksumMask = checksumMask;
    gDwcEncSession.isKeyValid = 1;
    return 1;
}

/*
 * Checks the 40-character hex digest at the end of a response against the SHA-1 of
 * secretKey + base64(body) + secretKey; on success stores the body length and pointer.
 * The pool word at +0x184 is the hextbl initializer template.  The block-scoped `d`
 * destination pointer is the spelling that gives the image register order for the second key copy.
 */
int DWCi_EncSessionValidateResponse(char *response, int responseLen)
{
    int i;
    u8 *scratch;
    char hashHex[41];
    u8 hash[20];
    char hexDigits[17] = "0123456789abcdef";

    if (responseLen <= 40)
        return 0;
    scratch = DWC_Alloc(8, b64size(responseLen - 40u) + 41);
    if (scratch == 0)
        return 0;
    memcpy(scratch, gDwcEncSession.secretKey, 20);
    B64Encode(response, (char *)(scratch + 20), responseLen - 40u, 2);
    {
        u8 *d = scratch + 20 + b64size(responseLen - 40u);
        memcpy(d, gDwcEncSession.secretKey, 20);
    }
    func_020816B8(hash, scratch, b64size(responseLen - 40u) + 40);
    DWC_Free(8, scratch, 0);
    for (i = 0; i < 20; i++) {
        hashHex[i * 2] = hexDigits[hash[i] >> 4];
        hashHex[i * 2 + 1] = hexDigits[hash[i] & 15];
    }
    hashHex[40] = '\0';
    if (strncmp(&response[responseLen - 40], hashHex, 40) != 0)
        return 0;
    gDwcEncSession.decodedBuffer = response;
    gDwcEncSession.decodedBufferLen = responseLen - 40u;
    return 1;
}

/*
 * Progress callback of the session requests; nothing to do.
 */
void DWCi_EncSessionProgressCallback(int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param)
{
}
