/*
 * function: rijndaelDecrypt
 * address:  0x021BB7DC
 * packet:   pkt_ov016_021BADD8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   rijndaelDecrypt      0x021BB7DC  thumb
 *   Td0   0x021D97F8  data
 *   Td1   0x021D9BF8  data
 *   Td2   0x021D77F8  data
 *   Td3   0x021D7BF8  data
 *   Td4   0x021D7FF8  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), static rijndaelDecrypt:
 * the rijndael-alg-fst.c v3.0 reference inverse cipher, the non-FULL_UNROLL loop.
 * atermset.o's .comment stamp is "Metrowerks C/C++ for ARM 3.0.0.126", the
 * ../2.0/sp1p2 front end (see ov016_func_021BBC8C_md5.c for the dsi/1.1p1 contrast).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BB7DC.c \
 *       --func rijndaelDecrypt --addr 0x021BB7DC --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */
typedef unsigned long u32;
typedef unsigned char u8;

#define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
#define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
extern u32 Td0[256];
extern u32 Td1[256];
extern u32 Td2[256];
extern u32 Td3[256];
extern u32 Td4[256];

void rijndaelDecrypt(u32 *rk, int Nr, u8 *ct, u8 *pt)
{
	u32 s0, s1, s2, s3, t0, t1, t2, t3;
	int r;

	s0 = GETU32(ct     ) ^ rk[0];
	s1 = GETU32(ct +  4) ^ rk[1];
	s2 = GETU32(ct +  8) ^ rk[2];
	s3 = GETU32(ct + 12) ^ rk[3];
	r = Nr >> 1;
	for (;;) {
		t0 =
			Td0[(s0 >> 24)       ] ^
			Td1[(s3 >> 16) & 0xff] ^
			Td2[(s2 >>  8) & 0xff] ^
			Td3[(s1      ) & 0xff] ^
			rk[4];
		t1 =
			Td0[(s1 >> 24)       ] ^
			Td1[(s0 >> 16) & 0xff] ^
			Td2[(s3 >>  8) & 0xff] ^
			Td3[(s2      ) & 0xff] ^
			rk[5];
		t2 =
			Td0[(s2 >> 24)       ] ^
			Td1[(s1 >> 16) & 0xff] ^
			Td2[(s0 >>  8) & 0xff] ^
			Td3[(s3      ) & 0xff] ^
			rk[6];
		t3 =
			Td0[(s3 >> 24)       ] ^
			Td1[(s2 >> 16) & 0xff] ^
			Td2[(s1 >>  8) & 0xff] ^
			Td3[(s0      ) & 0xff] ^
			rk[7];

		rk += 8;
		if (--r == 0) {
			break;
		}

		s0 =
			Td0[(t0 >> 24)       ] ^
			Td1[(t3 >> 16) & 0xff] ^
			Td2[(t2 >>  8) & 0xff] ^
			Td3[(t1      ) & 0xff] ^
			rk[0];
		s1 =
			Td0[(t1 >> 24)       ] ^
			Td1[(t0 >> 16) & 0xff] ^
			Td2[(t3 >>  8) & 0xff] ^
			Td3[(t2      ) & 0xff] ^
			rk[1];
		s2 =
			Td0[(t2 >> 24)       ] ^
			Td1[(t1 >> 16) & 0xff] ^
			Td2[(t0 >>  8) & 0xff] ^
			Td3[(t3      ) & 0xff] ^
			rk[2];
		s3 =
			Td0[(t3 >> 24)       ] ^
			Td1[(t2 >> 16) & 0xff] ^
			Td2[(t1 >>  8) & 0xff] ^
			Td3[(t0      ) & 0xff] ^
			rk[3];
	}
	s0 =
		(Td4[(t0 >> 24)       ] & 0xff000000) ^
		(Td4[(t3 >> 16) & 0xff] & 0x00ff0000) ^
		(Td4[(t2 >>  8) & 0xff] & 0x0000ff00) ^
		(Td4[(t1      ) & 0xff] & 0x000000ff) ^
		rk[0];
	PUTU32(pt     , s0);
	s1 =
		(Td4[(t1 >> 24)       ] & 0xff000000) ^
		(Td4[(t0 >> 16) & 0xff] & 0x00ff0000) ^
		(Td4[(t3 >>  8) & 0xff] & 0x0000ff00) ^
		(Td4[(t2      ) & 0xff] & 0x000000ff) ^
		rk[1];
	PUTU32(pt +  4, s1);
	s2 =
		(Td4[(t2 >> 24)       ] & 0xff000000) ^
		(Td4[(t1 >> 16) & 0xff] & 0x00ff0000) ^
		(Td4[(t0 >>  8) & 0xff] & 0x0000ff00) ^
		(Td4[(t3      ) & 0xff] & 0x000000ff) ^
		rk[2];
	PUTU32(pt +  8, s2);
	s3 =
		(Td4[(t3 >> 24)       ] & 0xff000000) ^
		(Td4[(t2 >> 16) & 0xff] & 0x00ff0000) ^
		(Td4[(t1 >>  8) & 0xff] & 0x0000ff00) ^
		(Td4[(t0      ) & 0xff] & 0x000000ff) ^
		rk[3];
	PUTU32(pt + 12, s3);
}
