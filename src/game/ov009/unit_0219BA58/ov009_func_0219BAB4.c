/*
 * function: func_0219BAB4
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
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0219B918  0x0219B918  arm  ov009
 *   func_0219B858  0x0219B858  arm  ov009
 */

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

typedef struct qr2_implementation_s {
    unsigned char pad0[0x44];
    char secret_key[1];
} qr2_implementation_s;

extern int func_021803BC(char *dst, const char *src, unsigned int n);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern void func_0219B918(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len);
extern void func_0219B858(unsigned char *ins, int size, unsigned char *result);

void func_0219BAB4(qr2_implementation_s *qrec, struct qr2_buffer_s *buf, char *challenge, int challengelen)
{
    char encrypted_val[65];

    if (challengelen < 1 || challengelen > 65 || challenge[challengelen - 1] != 0)
        return;
    func_021803BC(encrypted_val, challenge, 65);
    func_0219B918((unsigned char *)qrec->secret_key, func_0209477C((const u8 *)qrec->secret_key), (unsigned char *)encrypted_val, challengelen - 1);
    func_0219B858((unsigned char *)encrypted_val, challengelen - 1, (unsigned char *)&buf->buffer[buf->len]);
    buf->len += func_0209477C((const u8 *)(&buf->buffer[buf->len])) + 1;
}
