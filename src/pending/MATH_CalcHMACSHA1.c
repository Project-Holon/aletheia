/*
 * function: MATH_CalcHMACSHA1
 * address:  0x020816FC
 * packet:   pkt_020816FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * TwlSDK libmath dgt_sha1.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * HMAC-SHA1 through MATHi_CalcHMAC with a stack SHA-1 context; the
 * function table is an initialised local, copied from the compiler's
 * template @12151 and then patched with the run-time members.
 *
 * MATCH: byte-correct; the one wildcarded relocation is the ABS32 to the
 * aggregate initialiser's template (0x020A5CB8, vendor @12151, @30 here).
 * The symbols: block does not accept an `@N` name, so it cannot be
 * attested; a spelling with a named extern template would not be the
 * original source.  Needs a tooling rule for compiler template symbols.
 *
 * symbols:
 *   MATHi_CalcHMAC    0x02081790  arm
 *   MATH_SHA1Init     0x020813D8  arm
 *   MATH_SHA1Update   0x0208142C  arm
 *   MATH_SHA1GetHash  0x020814C0  arm
 */

typedef unsigned long u32;
typedef unsigned char u8;

#define MATH_SHA1_BLOCK_SIZE 64

typedef struct MATHSHA1Context {
    u32 h[5];
    u8 block[MATH_SHA1_BLOCK_SIZE];
    u32 pool;
    u32 blocks_low;
    u32 blocks_high;
} MATHSHA1Context;


#define MATH_SHA1_DIGEST_SIZE 20

typedef struct MATHiHMACFuncs {
    u32 dlength;
    u32 blength;
    void *context;
    u8 *hash_buf;
    void (*HashReset)(void *context);
    void (*HashSetSource)(void *context, const void *input, u32 length);
    void (*HashGetDigest)(void *context, void *digest);
} MATHiHMACFuncs;

extern void MATH_SHA1Init(MATHSHA1Context *context);
extern void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length);
extern void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest);
extern void MATHi_CalcHMAC(void *mac, const void *message, u32 message_length, const void *key, u32 key_length, MATHiHMACFuncs *funcs);

void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len)
{
    MATHSHA1Context context;
    u8 hash_buf[MATH_SHA1_DIGEST_SIZE];
    MATHiHMACFuncs hash2funcs = {
        MATH_SHA1_DIGEST_SIZE,
        MATH_SHA1_BLOCK_SIZE,
    };

    hash2funcs.context = &context;
    hash2funcs.hash_buf = hash_buf;
    hash2funcs.HashReset = (void (*)(void *))MATH_SHA1Init;
    hash2funcs.HashSetSource = (void (*)(void *, const void *, u32))MATH_SHA1Update;
    hash2funcs.HashGetDigest = (void (*)(void *, void *))MATH_SHA1GetHash;

    MATHi_CalcHMAC(digest, bin_ptr, bin_len, key_ptr, key_len, &hash2funcs);
}
