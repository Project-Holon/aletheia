/*
 * file:     unit_021CA494.c
 * unit:     yes
 * function: func_021CA494, func_021CA5E4, func_021CA69C, func_021CA734, func_021CA8EC, func_021CA9F8, func_021CAA70
 * address:  0x021CA494
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
 *   func_021CAD1C  0x021CAD1C  arm  ov114
 *   func_021CACD0  0x021CACD0  arm  ov114
 *   func_021CAF24  0x021CAF24  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CC124  0x021CC124  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 *   func_021CB010  0x021CB010  arm  ov114
 *   func_021CABDC  0x021CABDC  arm  ov114
 *   func_021CAD6C  0x021CAD6C  arm  ov114
 *   func_020816B8  0x020816B8  arm
 */
typedef struct bignum_st
{
    unsigned int *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef struct bignum_ctx BN_CTX;

typedef unsigned char  u8;

extern void *func_021CAD1C(void);
extern void func_021CACD0(int a);
extern BIGNUM *func_021CAF24(const unsigned char *, int, BIGNUM *);
extern int func_021CAEC8(u8 *a, unsigned long w);
extern int func_021CC124(BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int func_021CAB94(const BIGNUM *);
extern int func_021CB010(const BIGNUM *, unsigned char *);
extern void func_021CABDC(u8 *p);
extern void func_021CAD6C(u8 *ctx);
extern void func_020816B8(void *digest, void *data, unsigned long dataLength);
int func_021CA494(void *dst_ptr, int dst_len, void *src_ptr, int src_len, void *mod_ptr, int mod_len, unsigned long exp_num);
int func_021CA5E4(unsigned char **datap, unsigned int *dlenp, unsigned char type, unsigned int *lenp);
int func_021CA69C(unsigned char *psrc_adrs, unsigned int nsrc_size, unsigned char **ppsign_adrs, unsigned int *psign_size);
int func_021CA734(unsigned char *data, unsigned int dlen, unsigned char **ppdgst_adrs, unsigned int *pdgst_size, unsigned char **pphash_adrs, unsigned int *phash_size);
int func_021CA8EC(void *decoded_hash_ptr, unsigned long decoded_hash_len, void *sign_ptr, unsigned long sign_len, void *mod_ptr, unsigned long mod_len, unsigned long exp_num);
int func_021CA9F8(void *hash_ptr, void *sign_ptr, void *mod_ptr);
int func_021CAA70(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr);


/*
 * sdk:      CRYPTOi_RSA (sign.o)
 */
int func_021CA494(void *dst_ptr, int dst_len, void *src_ptr, int src_len, void *mod_ptr, int mod_len, unsigned long exp_num)
{
    BN_CTX *ctx;
    BIGNUM src;
    BIGNUM dst;
    BIGNUM exp;
    BIGNUM mod;
    int ret;

    if (dst_ptr == 0 || src_ptr == 0 || mod_ptr == 0)
        return -3;

    ctx = func_021CAD1C();
    func_021CACD0((int)(&src));
    func_021CACD0((int)(&dst));
    func_021CACD0((int)(&exp));
    func_021CACD0((int)(&mod));

    if (ctx == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CAF24((unsigned char *)src_ptr, src_len, &src) == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CAEC8((u8 *)(&exp), exp_num) == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CAF24((unsigned char *)mod_ptr, mod_len, &mod) == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CC124(&dst, &src, &exp, &mod, ctx) == 0)
    {
        ret = -2;
        goto end;
    }
    if (dst_len < (func_021CAB94(&dst) + 7) / 8)
    {
        ret = -1;
        goto end;
    }
    ret = func_021CB010(&dst, (unsigned char *)dst_ptr);

end:
    func_021CABDC((u8 *)(&src));
    func_021CABDC((u8 *)(&dst));
    func_021CABDC((u8 *)(&exp));
    func_021CABDC((u8 *)(&mod));
    if (ctx != 0)
        func_021CAD6C((u8 *)ctx);
    return ret;
}

/*
 * note:     Lane wave7 (2026-09-30): EXACT from the object listing.  The DWARF
 *          local list is l(r6), len(r12), dlen(r5), data(r4) (reverse source
 *          order), and the vendor's long-form parse hoists `data++` out of the
 *          do/while: `data++; do { len = (*data & 0x7f) + (len << 7); } while
 *          (--l);`.  With the increment inside the loop this front end keeps
 *          the reload in the loop (180 B, 80 concrete bytes); hoisted, the load
 *          is loop-invariant and CSE'd into `lr`, giving the image's 4
 *          instruction loop and 184/184.
 *
 * sdk:      ASN1Skip (libcrypto.TWL.HYB.a(sign.o))
 */
int func_021CA5E4(unsigned char **datap, unsigned int *dlenp, unsigned char type, unsigned int *lenp)
{
	unsigned int dlen;
	unsigned int len;
	unsigned char *data;
	unsigned char l;

	data = *datap;
	dlen = *dlenp;
	len = 0;
	if (*data++ != type)
		return 0;
	if (dlen < 1)
		return 0;
	dlen--;
	l = *data;
	if (l & 0x80) {
		l &= 0x7f;
		if (dlen < (unsigned int)l + 1)
			return 0;
		dlen -= l;
		if (lenp != 0) {
			data++;
			do {
				len = (*data & 0x7f) + (len << 7);
			} while (--l);
		} else {
			data += l;
		}
	} else {
		data++;
		len = l;
		if (dlen < 1)
			return 0;
		dlen--;
	}
	*datap = data;
	*dlenp = dlen;
	if (lenp != 0)
		*lenp = len;
	return 1;
}

/*
 * sdk:      SkipPadding (libcrypto.TWL.HYB.a(sign.o))
 */
int func_021CA69C(unsigned char *psrc_adrs, unsigned int nsrc_size, unsigned char **ppsign_adrs, unsigned int *psign_size)
{
	unsigned char *p;
	unsigned char *pe;
	int i;

	if (nsrc_size < 10)
		return 0;
	p = psrc_adrs;
	pe = psrc_adrs + nsrc_size;
	if (*p != 1)
		return 0;
	p++;
	for (i = 0; i < 8; i++) {
		if (*p++ != 0xff)
			return 0;
	}
	for (; p != pe; p++) {
		if (*p != 0xff)
			break;
	}
	if (p == pe)
		return 0;
	if (*p != 0)
		return 0;
	p++;
	*psign_size = pe - p;
	*ppsign_adrs = p;
	return 1;
}


/*
 * sdk:      ParseSignHash (sign.o)
 */
int func_021CA734(unsigned char *data, unsigned int dlen, unsigned char **ppdgst_adrs, unsigned int *pdgst_size, unsigned char **pphash_adrs, unsigned int *phash_size)
{
    unsigned int len;

    if (!func_021CA5E4(&data, &dlen, 0x30, 0))
        return 0;
    if (!func_021CA5E4(&data, &dlen, 0x30, 0))
        return 0;
    if (!func_021CA5E4(&data, &dlen, 0x06, &len))
        return 0;
    if (ppdgst_adrs)
        *ppdgst_adrs = data;
    if (pdgst_size)
        *pdgst_size = len;
    data += len;
    if (dlen < len)
        return 0;
    dlen -= len;
    if (!func_021CA5E4(&data, &dlen, 0x05, &len))
        return 0;
    data += len;
    if (dlen < len)
        return 0;
    dlen -= len;
    if (!func_021CA5E4(&data, &dlen, 0x04, &len))
        return 0;
    if (dlen != len)
        return 0;
    if (pphash_adrs)
        *pphash_adrs = data;
    if (phash_size)
        *phash_size = len;
    return 1;
}


/*
 * sdk:      CRYPTOi_GetDecodedHash (sign.o)
 */
int func_021CA8EC(void *decoded_hash_ptr, unsigned long decoded_hash_len, void *sign_ptr, unsigned long sign_len, void *mod_ptr, unsigned long mod_len, unsigned long exp_num)
{
    unsigned long decode[64];
    int decode_len;
    int i = 0;
    unsigned char *decoded_sign;
    unsigned int decoded_sign_len = 0;
    unsigned char *tmp_decoded_hash;
    unsigned int tmp_decoded_hash_len = 0;
    unsigned char *p_decoded_hash = (unsigned char *)decoded_hash_ptr;

    decode_len = func_021CA494(decode, sizeof(decode), sign_ptr, (int)sign_len, mod_ptr, (int)mod_len, exp_num);
    if (decode_len < 0)
        return -1;
    if (!func_021CA69C((unsigned char *)decode, (unsigned int)decode_len, &decoded_sign, &decoded_sign_len))
        return -1;
    if (!func_021CA734(decoded_sign, decoded_sign_len, 0, 0, &tmp_decoded_hash, &tmp_decoded_hash_len))
        return -1;
    if (tmp_decoded_hash_len > decoded_hash_len)
        return -1;
    for (i = 0; i < tmp_decoded_hash_len; i++)
        *p_decoded_hash++ = tmp_decoded_hash[i];
    for (; i < decoded_hash_len; i++)
        *p_decoded_hash++ = 0;
    return (int)tmp_decoded_hash_len;
}


/*
 * sdk:      CRYPTO_VerifySignatureWithHash (libcrypto.TWL.HYB.a(sign.o))
 */
int func_021CA9F8(void *hash_ptr, void *sign_ptr, void *mod_ptr)
{
	unsigned char decoded_hash[20];
	int decoded_hash_len;
	int i;

	decoded_hash_len = func_021CA8EC(decoded_hash, 20, sign_ptr, 128, mod_ptr, 128, 0x10001);
	if (decoded_hash_len != 20)
		return 0;
	for (i = 0; i < 20; i++) {
		if (decoded_hash[i] != ((unsigned char *)hash_ptr)[i])
			return 0;
	}
	return 1;
}


/*
 * sdk:      CRYPTO_VerifySignature (libcrypto.TWL.HYB.a(sign.o))
 */
int func_021CAA70(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr)
{
	unsigned char hash[20];

	func_020816B8(hash, data_ptr, data_len);
	return func_021CA9F8(hash, sign_ptr, mod_ptr);
}
