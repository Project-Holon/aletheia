/*
 * file:     unit_021CAB34_p05.c
 * unit:     yes
 * function: func_021CAF24, func_021CB010, func_021CB078
 * address:  0x021CAF24
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CACE4  0x021CACE4  arm  ov114
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CAC8C  0x021CAC8C  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 */
typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM_021CAF24;

typedef struct
{
    unsigned int *d;
    int top;
} BIGNUM_021CB010;

typedef unsigned char  u8;

typedef struct
{
    unsigned int *d;
    int top;
} BIGNUM_021CB078;

extern void *func_021CACE4(void);
extern BIGNUM_021CAF24 *func_021CADAC(BIGNUM_021CAF24 *a, int words);
extern void func_021CAC8C(BIGNUM_021CAF24 *a);
extern char *func_021CAB94(u8 *p);
BIGNUM_021CAF24 *func_021CAF24(unsigned char *s, unsigned int len, BIGNUM_021CAF24 *ret);
int func_021CB010(BIGNUM_021CB010 *a, unsigned char *to);
int func_021CB078(BIGNUM_021CB078 *a, BIGNUM_021CB078 *b);


/*
 * sdk:      CRYPTOi__BN_bin2bn (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
BIGNUM_021CAF24 *func_021CAF24(unsigned char *s, unsigned int len, BIGNUM_021CAF24 *ret)
{
	unsigned int i, m;
	unsigned long l;

	if (ret == 0)
		ret = func_021CACE4();
	if (ret == 0)
		return 0;
	l = 0;
	if (len == 0) {
		ret->top = 0;
		return ret;
	}
	if ((((((int)len + 2) * 8 + 31) / 32 <= ret->dmax) ? ret : func_021CADAC(ret, (((int)len + 2) * 8) / 32 + 1)) == 0)
		return 0;
	i = ((len - 1) / 4) + 1;
	m = ((len - 1) % 4);
	ret->top = i;
	while (len--) {
		l = (l << 8) | *(s++);
		if (m-- == 0) {
			ret->d[--i] = l;
			l = 0;
			m = 3;
		}
	}
	func_021CAC8C(ret);
	return ret;
}


/*
 * sdk:      CRYPTOi__BN_bn2bin (crypto_bobj1.o)
 *
 * Big-endian byte serialisation; returns the byte count.
 */
int func_021CB010(BIGNUM_021CB010 *a, unsigned char *to)
{
    int n = (int)func_021CAB94((u8 *)a);
    int i = (n + 7) / 8;
    int j = i - 1;
    if (i <= 0)
        return i;
    do {
        unsigned int l = a->d[j / 4];
        *to++ = (unsigned char)(l >> (8 * (j % 4)));
    } while (j-- > 0);
    return i;
}


/*
 * sdk:      CRYPTOi__BN_ucmp (crypto_bobj1.o)
 *
 * Unsigned magnitude compare.  The early return yields the signed word
 * difference; the pointer locals are declared before the loop index so the
 * allocator keeps the two data cursors in r2/r3 and the index in ip.
 */
int func_021CB078(BIGNUM_021CB078 *a, BIGNUM_021CB078 *b)
{
    unsigned int *ap, *bp;
    int i;
    if (a->top - b->top)
        return a->top - b->top;
    ap = a->d;
    bp = b->d;
    for (i = a->top - 1; i >= 0; i--) {
        unsigned int t1 = ap[i];
        unsigned int t2 = bp[i];
        if (t1 != t2)
            return (t1 > t2) ? 1 : -1;
    }
    return 0;
}
