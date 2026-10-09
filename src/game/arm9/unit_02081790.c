/*
 * file:     unit_02081790.c
 * function: MATHi_CalcHMAC
 * address:  0x02081790
 * packet:   pkt_02081790
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmath dgt_hmac.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The
 * generic HMAC over a hash function table: a key longer than the block is
 * hashed first, then H(K ^ opad, H(K ^ ipad, message)).  The locals are
 * declared in the exact reverse of the DWARF listing, which puts opad_key at
 * the bottom of the frame and new_key at the top.
 */

typedef unsigned long u32;
typedef unsigned char u8;

#define MATH_HASH_BLOCK_SIZE_MAX 64

typedef struct MATHiHMACFuncs {
    u32 dlength;
    u32 blength;
    void *context;
    u8 *hash_buf;
    void (*HashReset)(void *context);
    void (*HashSetSource)(void *context, const void *input, u32 length);
    void (*HashGetDigest)(void *context, void *digest);
} MATHiHMACFuncs;

void MATHi_CalcHMAC(void *mac, const void *message, u32 message_length, const void *key, u32 key_length, MATHiHMACFuncs *funcs)
{
    int i;
    u8 new_key[MATH_HASH_BLOCK_SIZE_MAX];
    const u8 *use_key;
    u32 use_key_length;
    u8 ipad_key[MATH_HASH_BLOCK_SIZE_MAX];
    u8 opad_key[MATH_HASH_BLOCK_SIZE_MAX];

    if (mac == 0 || message == 0 || message_length == 0 || key == 0 || key_length == 0 || funcs == 0) {
        return;
    }

    if (key_length > funcs->blength) {
        funcs->HashReset(funcs->context);
        funcs->HashSetSource(funcs->context, key, key_length);
        funcs->HashGetDigest(funcs->context, new_key);
        use_key = new_key;
        use_key_length = funcs->dlength;
    } else {
        use_key = (const u8 *)key;
        use_key_length = key_length;
    }

    for (i = 0; i < use_key_length; i++) {
        ipad_key[i] = (u8)(use_key[i] ^ 0x36);
    }
    for (; i < funcs->blength; i++) {
        ipad_key[i] = 0x36;
    }
    funcs->HashReset(funcs->context);
    funcs->HashSetSource(funcs->context, ipad_key, funcs->blength);
    funcs->HashSetSource(funcs->context, message, message_length);
    funcs->HashGetDigest(funcs->context, funcs->hash_buf);

    for (i = 0; i < use_key_length; i++) {
        opad_key[i] = (u8)(use_key[i] ^ 0x5c);
    }
    for (; i < funcs->blength; i++) {
        opad_key[i] = 0x5c;
    }
    funcs->HashReset(funcs->context);
    funcs->HashSetSource(funcs->context, opad_key, funcs->blength);
    funcs->HashSetSource(funcs->context, funcs->hash_buf, funcs->dlength);
    funcs->HashGetDigest(funcs->context, mac);
}
