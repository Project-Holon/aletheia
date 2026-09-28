/*
 * function: rijndaelKeySetupDec
 * address:  0x021BB290
 * packet:   pkt_ov016_021BADD8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   rijndaelKeySetupDec  0x021BB290  thumb
 *   rijndaelKeySetupEnc  0x021BAFD8  thumb
 *   Te4   0x021D93F8  data
 *   Td0   0x021D97F8  data
 *   Td1   0x021D9BF8  data
 *   Td2   0x021D77F8  data
 *   Td3   0x021D7BF8  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), static rijndaelKeySetupDec:
 * the rijndael-alg-fst.c v3.0 reference decryption key schedule.
 * atermset.o's .comment stamp is "Metrowerks C/C++ for ARM 3.0.0.126", the
 * ../2.0/sp1p2 front end (see ov016_func_021BBC8C_md5.c for the dsi/1.1p1 contrast).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BB290.c \
 *       --func rijndaelKeySetupDec --addr 0x021BB290 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */
typedef unsigned long u32;
typedef unsigned char u8;

#define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
#define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
extern u32 Te4[256];
extern u32 Td0[256];
extern u32 Td1[256];
extern u32 Td2[256];
extern u32 Td3[256];
extern int rijndaelKeySetupEnc(u32 *rk, u8 *cipherKey, int keyBits);

int rijndaelKeySetupDec(u32 *rk, u8 *cipherKey, int keyBits)
{
	int Nr, i, j;
	u32 temp;

	/* expand the cipher key: */
	Nr = rijndaelKeySetupEnc(rk, cipherKey, keyBits);
	/* invert the order of the round keys: */
	for (i = 0, j = 4*Nr; i < j; i += 4, j -= 4) {
		temp = rk[i    ]; rk[i    ] = rk[j    ]; rk[j    ] = temp;
		temp = rk[i + 1]; rk[i + 1] = rk[j + 1]; rk[j + 1] = temp;
		temp = rk[i + 2]; rk[i + 2] = rk[j + 2]; rk[j + 2] = temp;
		temp = rk[i + 3]; rk[i + 3] = rk[j + 3]; rk[j + 3] = temp;
	}
	/* apply the inverse MixColumn transform to all round keys but the first and the last: */
	for (i = 1; i < Nr; i++) {
		rk += 4;
		rk[0] =
			Td0[Te4[(rk[0] >> 24)       ] & 0xff] ^
			Td1[Te4[(rk[0] >> 16) & 0xff] & 0xff] ^
			Td2[Te4[(rk[0] >>  8) & 0xff] & 0xff] ^
			Td3[Te4[(rk[0]      ) & 0xff] & 0xff];
		rk[1] =
			Td0[Te4[(rk[1] >> 24)       ] & 0xff] ^
			Td1[Te4[(rk[1] >> 16) & 0xff] & 0xff] ^
			Td2[Te4[(rk[1] >>  8) & 0xff] & 0xff] ^
			Td3[Te4[(rk[1]      ) & 0xff] & 0xff];
		rk[2] =
			Td0[Te4[(rk[2] >> 24)       ] & 0xff] ^
			Td1[Te4[(rk[2] >> 16) & 0xff] & 0xff] ^
			Td2[Te4[(rk[2] >>  8) & 0xff] & 0xff] ^
			Td3[Te4[(rk[2]      ) & 0xff] & 0xff];
		rk[3] =
			Td0[Te4[(rk[3] >> 24)       ] & 0xff] ^
			Td1[Te4[(rk[3] >> 16) & 0xff] & 0xff] ^
			Td2[Te4[(rk[3] >>  8) & 0xff] & 0xff] ^
			Td3[Te4[(rk[3]      ) & 0xff] & 0xff];
	}
	return Nr;
}
