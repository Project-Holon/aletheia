/*
 * function: decrypt_premaster_secret
 * address:  0x02160F80
 * packet:   pkt_ov009_02160F80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      decrypt_premaster_secret (libssl.TWL.HYB.a ssl.o)
 *
 * CPSPrivateKey is six (len,ptr) big-integer byte strings after a leading
 * size; the (len,ptr) loads prove the pairing.
 *
 * symbols:
 *   enter_computebound       0x0216009C arm ov009
 *   exit_computebound       0x021600E4 arm ov009
 *   CPSi_big_from_char  0x02164CC4 arm ov009
 *   CPSi_big_montpower  0x02164AA8 arm ov009
 *   CPSi_big_sub        0x021640B8 arm ov009
 *   CPSi_big_mult       0x02164230 arm ov009
 *   CPSi_big_add        0x02163F7C arm ov009
 *   CPSi_big_sign       0x02163F4C arm ov009
 *   CPSi_big_negate     0x02164078 arm ov009
 *   CPSi_big_div        0x021644D0 arm ov009
 *   CPSi_char_from_big  0x02164D20 arm ov009
 *   CPSiAlloc           0x021A8280 data
 *   CPSiFree            0x021A82B0 data
 */

typedef struct CPSPrivateKey {
    int size;
    unsigned char *p0;
    int l1;
    unsigned char *p1;
    int l2;
    unsigned char *p2;
    int l3;
    unsigned char *p3;
    int l4;
    unsigned char *p4;
    int l5;
    unsigned char *p5;
} CPSPrivateKey;

extern unsigned long enter_computebound(void);
extern void exit_computebound(unsigned long old_priority);
extern void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n);
extern void CPSi_big_sub(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_add(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern int CPSi_big_sign(unsigned short *a, int digits);
extern void CPSi_big_negate(unsigned short *a, int digits);
extern void CPSi_big_div(unsigned short *c, unsigned short *a, unsigned short *b, unsigned short *r, int digits, unsigned short *work);
extern void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes, int digits);
extern void *(*CPSiAlloc)(unsigned long size);
extern void (*CPSiFree)(void *ptr);

static void decrypt_premaster_secret(unsigned char *d, unsigned char *s, CPSPrivateKey *k)
{
    int digits;
    unsigned short *tmp_var;
    unsigned short *b;
    unsigned short *c;
    unsigned short *k1;
    unsigned short *k2;
    unsigned short *n;
    unsigned short *l;
    unsigned short *divwork;
    unsigned long old_priority;

    if (k == 0 || k->size == 0)
        return;

    digits = (k->size * 2) / 2 + 1;
    tmp_var = CPSiAlloc(digits * 20);
    if (tmp_var == 0)
        return;

    b = tmp_var + digits;
    c = b + digits;
    k1 = c + digits;
    k2 = k1 + digits;
    n = k2 + digits;
    l = n + digits;
    divwork = l + digits;

    CPSi_big_from_char(tmp_var, s, k->size, digits);
    CPSi_big_from_char(b, k->p3, k->l3, digits);
    CPSi_big_from_char(n, k->p1, k->l1, digits);
    old_priority = enter_computebound();
    CPSi_big_montpower(k1, tmp_var, b, digits, n);
    CPSi_big_from_char(b, k->p4, k->l4, digits);
    CPSi_big_from_char(n, k->p2, k->l2, digits);
    CPSi_big_montpower(k2, tmp_var, b, digits, n);
    exit_computebound(old_priority);
    CPSi_big_sub(tmp_var, k1, k2, digits);
    CPSi_big_from_char(b, k->p5, k->l5, digits);
    CPSi_big_mult(c, tmp_var, b, digits);
    CPSi_big_from_char(b, k->p2, k->l2, digits);
    CPSi_big_mult(tmp_var, c, b, digits);
    CPSi_big_add(c, tmp_var, k2, digits);
    CPSi_big_from_char(b, k->p0, k->size, digits);
    if (CPSi_big_sign(c, digits) < 0) {
        CPSi_big_negate(c, digits);
        CPSi_big_div(0, c, b, l, digits, divwork);
        CPSi_big_sub(l, b, l, digits);
    } else {
        CPSi_big_div(0, c, b, l, digits, divwork);
    }
    CPSi_char_from_big(d, l, 0x30, digits);
    CPSiFree(tmp_var);
}
