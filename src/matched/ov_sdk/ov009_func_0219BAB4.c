/*
 * function: compute_challenge_response
 * address:  0x0219BAB4
 * packet:   pkt_ov009_0219BAB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      compute_challenge_response (qr2.o)
 *
 * symbols:
 *   gsiSafeStrcpyA  0x021803BC  arm  ov009
 *   strlen  0x0209477C  arm
 *   gs_encrypt  0x0219B918  arm  ov009
 *   gs_encode  0x0219B858  arm  ov009
 */

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

typedef struct qr2_implementation_s {
    unsigned char pad0[0x44];
    char secret_key[1];
} qr2_implementation_s;

extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern void gs_encrypt(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len);
extern void gs_encode(unsigned char *ins, int size, unsigned char *result);

void compute_challenge_response(qr2_implementation_s *qrec, struct qr2_buffer_s *buf, char *challenge, int challengelen)
{
    char encrypted_val[65];

    if (challengelen < 1 || challengelen > 65 || challenge[challengelen - 1] != 0)
        return;
    gsiSafeStrcpyA(encrypted_val, challenge, 65);
    gs_encrypt((unsigned char *)qrec->secret_key, strlen((const u8 *)qrec->secret_key), (unsigned char *)encrypted_val, challengelen - 1);
    gs_encode((unsigned char *)encrypted_val, challengelen - 1, (unsigned char *)&buf->buffer[buf->len]);
    buf->len += strlen((const u8 *)(&buf->buffer[buf->len])) + 1;
}
