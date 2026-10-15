/*
 * function: MATH_CalcHMACSHA1
 * address:  0x020816FC
 * packet:   pkt_020816FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    byte-correct; the pool word for the hash2funcs initializer template is named `@12151` (the vendor member's local) in the symbols: block and resolves under the `template` class (image 0x020A5CB8 holds the member's 28 template bytes, uniquely).
 *
 * sdk:      MATH_CalcHMACSHA1 (dgt_sha1.o)
 *
 * symbols:
 *   MATHi_CalcHMAC    0x02081790  arm
 *   MATH_SHA1Init     0x020813D8  arm
 *   MATH_SHA1Update   0x0208142C  arm
 *   MATH_SHA1GetHash  0x020814C0  arm
 *   @12151            0x020A5CB8  data
 */

typedef unsigned long u32;
typedef unsigned char u8;

typedef struct MATHSHA1Context {
    u32 h[5];
    u32 block[16];
    u32 pool;
    unsigned long long length;
} MATHSHA1Context;

typedef struct MATHiHMACFuncs {
    u32 dlength;
    u32 blength;
    void *context;
    u8 *hash_buf;
    void (*HashReset)(void *context);
    void (*HashSetSource)(void *context, const void *input, u32 length);
    void (*HashGetDigest)(void *context, void *digest);
} MATHiHMACFuncs;

extern void MATHi_CalcHMAC(void *mac, const void *message, u32 message_length, const void *key, u32 key_length, MATHiHMACFuncs *funcs);
extern void MATH_SHA1Init(MATHSHA1Context *context);
extern void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length);
extern void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest);

void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len)
{
    MATHSHA1Context context;
    u8 hash_buf[20];
    MATHiHMACFuncs hash2funcs = {
        20,
        64,
    };

    hash2funcs.context = &context;
    hash2funcs.hash_buf = hash_buf;
    hash2funcs.HashReset = (void (*)(void *))MATH_SHA1Init;
    hash2funcs.HashSetSource = (void (*)(void *, const void *, u32))MATH_SHA1Update;
    hash2funcs.HashGetDigest = (void (*)(void *, void *))MATH_SHA1GetHash;

    MATHi_CalcHMAC(digest, bin_ptr, bin_len, key_ptr, key_len, &hash2funcs);
}
