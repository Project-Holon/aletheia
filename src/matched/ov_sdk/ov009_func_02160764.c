/*
 * function: validate_signature
 * address:  0x02160764
 * packet:   pkt_ov009_02160764
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      validate_signature (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02164CC4  0x02164CC4  arm  ov009
 *   enter_computebound  0x0216009C  arm  ov009
 *   CPSi_big_power  0x0216469C  arm  ov009
 *   exit_computebound  0x021600E4  arm  ov009
 *   func_02164D20  0x02164D20  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   CPSiAlloc     0x021A8280  data
 *   CPSiFree     0x021A82B0  data
 *
 * The DWARF declares CPSi_char_from_big(d, s, numbytes); the call site also
 * loads digits into r3, so the file passes it as a fourth argument.
 */

typedef struct SOCLCaInfo {
    char *dn;
    int modulo_len;
    unsigned char *modulo;
    int exponent_len;
    unsigned char *exponent;
} SOCLCaInfo;

typedef struct CPSSslConnection {
    unsigned char pad0[0x468];
    unsigned char hash[0x47c - 0x468];  /* +0x468 */
    int hash_len;                       /* +0x47c */
    unsigned char pad480[0x5a4 - 0x480];
    unsigned char *sig;                 /* +0x5a4 */
    int sig_len;                        /* +0x5a8 */
} CPSSslConnection;

extern unsigned short *(*CPSiAlloc)(unsigned long size);
extern void (*CPSiFree)(void *p);

extern void func_02164CC4(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern unsigned long enter_computebound(void);
extern void CPSi_big_power(unsigned short *c, unsigned short *a, unsigned short *b, int digits,
                          unsigned short *n);
extern void exit_computebound(unsigned long old_priority);
extern void func_02164D20(unsigned char *d, unsigned short *s, int numbytes, int digits);
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);

static int validate_signature(CPSSslConnection *con, SOCLCaInfo *ca)
{
    unsigned short *tmp_var;
    unsigned short *b;
    unsigned short *c;
    unsigned short *n;
    int digits;
    unsigned char *s;
    int result;
    int i;
    unsigned long old_priority;

    if (con->sig == 0 || con->sig_len == 0 || ca->exponent == 0 || ca->exponent_len == 0 ||
        ca->modulo == 0 || ca->modulo_len == 0)
        return 2;
    digits = ca->modulo_len * 2 / 2;
    tmp_var = CPSiAlloc(digits * 8);
    if (tmp_var == 0)
        return 2;
    b = tmp_var + digits;
    c = b + digits;
    n = c + digits;
    func_02164CC4(b, con->sig, con->sig_len, digits);
    func_02164CC4(c, ca->exponent, ca->exponent_len, digits);
    func_02164CC4(n, ca->modulo, ca->modulo_len, digits);
    old_priority = enter_computebound();
    CPSi_big_power(tmp_var, b, c, digits, n);
    exit_computebound(old_priority);
    s = (unsigned char *)b;
    func_02164D20(s, tmp_var, ca->modulo_len, digits);
    result = 0;
    if (s[0] != 0 || s[1] != 1) {
        result = 2;
    } else {
        for (i = 2; i < ca->modulo_len; i++) {
            if (s[i] != 0xff)
                break;
        }
        if (i + 1 >= ca->modulo_len || s[i] != 0 || s[i + 1] != 0x30 ||
            func_020923F0(con->hash, s + ca->modulo_len - con->hash_len, con->hash_len) != 0)
            result = 2;
    }
    CPSiFree(tmp_var);
    return result;
}
