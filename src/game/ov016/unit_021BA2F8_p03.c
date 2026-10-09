/*
 * file:     unit_021BA2F8_p03.c
 * unit:     yes
 * function: AutoConfigThread, func_021BAC20, func_021BADD8, func_021BAF90, func_021BAFD8, func_021BB290, func_021BB420, rijndaelDecrypt
 * address:  0x021BABE8
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   atermset_data       0x021DAB58  data
 *   atermset_bss        0x021DCFD0  data
 *   AutoConfigThreadEx  0x021BA804  thumb
 *   DisconnectAP        0x021B99C8  thumb
 *   SendNotify          0x021BC804  thumb
 *   func_021BAFD8  0x021BAFD8  thumb  ov016
 *   memcpy  0x02092344  arm
 *   _ull_mul  0x0209C054  arm
 *   func_021BB420  0x021BB420  thumb  ov016
 *   func_021BAF90  0x021BAF90  thumb  ov016
 *   func_021BB290  0x021BB290  thumb  ov016
 *   func_021BB7DC  0x021BB7DC  thumb  ov016
 *   memcmp  0x020923F0  arm
 *   rcon  0x021D77D0  data
 *   Te4   0x021D93F8  data
 *   Td0   0x021D97F8  data
 *   Td1   0x021D9BF8  data
 *   Td2   0x021D77F8  data
 *   Td3   0x021D7BF8  data
 *   Te0   0x021D83F8  data
 *   Te1   0x021D87F8  data
 *   Te2   0x021D8BF8  data
 *   Te3   0x021D8FF8  data
 *   Td4   0x021D7FF8  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/arm9_sdk/libc/memcmp/string.h"

#define KW_BSWAP64(x) \
    ((((x) & 0x00000000000000ffULL) << 56) | \
     (((x) & 0x000000000000ff00ULL) << 40) | \
     (((x) & 0x0000000000ff0000ULL) << 24) | \
     (((x) & 0x00000000ff000000ULL) << 8)  | \
     (((x) & 0x000000ff00000000ULL) >> 8)  | \
     (((x) & 0x0000ff0000000000ULL) >> 24) | \
     (((x) & 0x00ff000000000000ULL) >> 40) | \
     (((x) & 0xff00000000000000ULL) >> 56))
#define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
#define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
/*
 * atermset.o's .bss scalars from 0x021DCFD0 (btAutoResult): the vendor object addresses
 * every word here through btAutoResult's pool word plus an offset, so they are declared as
 * one object in the object's own order; member names are the vendor symbols. The arrays
 * and the pointer and aggregates of the same section (apci_user_callback, event_buf, AllocLock, gAtermThread,
 * gAtermApConfigParam, AutoProfile) are pooled by their own symbols and declared apart.
 */
struct WCMConfig;
struct WMBssDesc;
struct _ATERMApConfigState;
typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;          /* enum PHASE */
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;         /* enum */
    unsigned long long       *gThreadStack;
    int                       cbElementData;
    int                       gAtermApState;
    unsigned char            *apci_IWBuffer;
    unsigned char            *apc_work;
    unsigned char            *apci_bssid_ptr;
    unsigned char            *apci_essid_ptr;
    struct WMBssDesc         *apci_wmbssdesc;
    int                       bDualCfg;
    unsigned char            *atermapc_work;
    unsigned long             apci_connect_option;
    struct WMBssDesc         *ap_list;
    unsigned long             apci_search_option;
    int                       gAtermThreadId;
    int                       event_set_ptr;
    int                       event_get_ptr;
    int                       gMaxApList;
    int                       bInitAtermApNetwork;
    int                       gAtermApResult;
    void                    (*gAtermNotify)(struct _ATERMApConfigState *state);
} ATERMSET_BSS;

/*
 * atermset.o's .data words from 0x021DAB58 (lpElementData), addressed through
 * lpElementData's pool word plus an offset; member names are the vendor symbols.
 */
typedef struct {
    unsigned char *lpElementData;
    int            bDebug;
    unsigned long  gThreadStackSize;
    unsigned long  gAtermApTimeout;
    int            gMaxBssIdList;
} ATERMSET_DATA;

typedef unsigned long u32;

typedef unsigned char u8;

extern int AutoConfigThreadEx(void);
extern void DisconnectAP(void);
extern void SendNotify(void);
extern int func_021BAFD8(unsigned long *rk, unsigned char *cipherKey, int keyBits);
extern void func_021BB420(unsigned long *rk, int Nr, unsigned char *pt, unsigned char *ct);
extern void func_021BAF90(unsigned char *srcA, unsigned char *srcB, unsigned char *dst);
extern int func_021BB290(unsigned long *rk, unsigned char *cipherKey, int keyBits);
extern void func_021BB7DC(unsigned long *rk, int Nr, unsigned char *ct, unsigned char *pt);
void AutoConfigThread(void *arg);
void aeskw_xor64(unsigned char *srcA, unsigned char *srcB, unsigned char *dst);
int rijndaelKeySetupEnc(u32 *rk, u8 *cipherKey, int keyBits);
int rijndaelKeySetupDec(u32 *rk, u8 *cipherKey, int keyBits);
void rijndaelEncrypt(u32 *rk, int Nr, u8 *pt, u8 *ct);
void rijndaelDecrypt(u32 *rk, int Nr, u8 *ct, u8 *pt);
extern ATERMSET_BSS atermset_bss;
extern ATERMSET_DATA atermset_data;
extern u32 rcon[10];
extern u32 Te4[256];
extern u32 Td0[256];
extern u32 Td1[256];
extern u32 Td2[256];
extern u32 Td3[256];
extern u32 Te0[256];
extern u32 Te1[256];
extern u32 Te2[256];
extern u32 Te3[256];
extern u32 Td4[256];





void AutoConfigThread(void *arg)
{
    int ret;

    ret = AutoConfigThreadEx();
    atermset_bss.gAtermApResult = ret;
    DisconnectAP();
    if (ret == 1)
        atermset_bss.gAtermApState = 6;
    else
        atermset_bss.gAtermApState = 7;
    atermset_data.gAtermApTimeout = -1;
    SendNotify();
}





/*
 * sdk:      keywrap_encrypt (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * RFC 3394 AES key wrap. The block offset is written i * sizeof(iv): the unsigned
 * product keeps i in r4 and recomputes the offset, where i * 8 is strength-reduced
 * into a second induction register. The byte swap's terms are listed low byte
 * first, which gives the object's evaluation order.
 */
static int func_021BAC20(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen)
{
    unsigned long long xort;
    unsigned long long iv;
    unsigned char aes_data[16];
    int i;
    int j;
    int n;
    int rounds;
    unsigned long aes_rk[80];

    iv = 0xa6a6a6a6a6a6a6a6ULL;
    if ((buflen & 7) || (keylen & 7))
        return 0;
    n = buflen >> 3;
    if (n < 2)
        return 0;
    rounds = func_021BAFD8(aes_rk, (unsigned char *)keyptr, keylen * 8);
    memcpy(dest + 8, src, buflen);
    memcpy(aes_data, &iv, 8);
    for (j = 0; j < 6; j++) {
        for (i = 1; i <= n; i++) {
            memcpy(aes_data + 8, dest + i * sizeof(iv), 8);
            func_021BB420(aes_rk, rounds, aes_data, aes_data);
            xort = KW_BSWAP64((unsigned long long)n * j + i);
            func_021BAF90(aes_data, (unsigned char *)&xort, aes_data);
            memcpy(dest + i * sizeof(iv), aes_data + 8, 8);
        }
    }
    memcpy(dest, aes_data, 8);
    return 1;
}




/*
 * sdk:      keywrap_decrypt (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * RFC 3394 AES key unwrap, the mirror of keywrap_encrypt (ov016_func_021BAC20.c).
 * The object computes n as (buflen - 1) >> 3 and copies buflen - 1 bytes; both are
 * kept as the object has them.
 */
static int func_021BADD8(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen)
{
    unsigned long long xort;
    unsigned char aes_data[16];
    int i;
    int j;
    int n;
    int rounds;
    unsigned long aes_rk[80];
    int status;
    unsigned long long iv;

    status = 1;
    iv = 0xa6a6a6a6a6a6a6a6ULL;
    if ((buflen & 7) || (keylen & 7))
        return 0;
    n = (buflen - 1) >> 3;
    if (n < 2)
        return 0;
    rounds = func_021BB290(aes_rk, (unsigned char *)keyptr, keylen * 8);
    memcpy(aes_data, src, 8);
    src += 8;
    memcpy(dest, src, buflen - 1);
    for (j = 5; j >= 0; j--) {
        for (i = n; i > 0; i--) {
            xort = KW_BSWAP64((unsigned long long)n * j + i);
            func_021BAF90(aes_data, (unsigned char *)&xort, aes_data);
            memcpy(aes_data + 8, dest + (i - 1) * sizeof(iv), 8);
            func_021BB7DC(aes_rk, rounds, aes_data, aes_data);
            memcpy(dest + (i - 1) * sizeof(iv), aes_data + 8, 8);
        }
    }
    if (memcmp(&iv, aes_data, 8))
        status = 0;
    return status;
}



void aeskw_xor64(unsigned char *srcA, unsigned char *srcB, unsigned char *dst)
{
    dst[0] = srcA[0] ^ srcB[0];
    dst[1] = srcA[1] ^ srcB[1];
    dst[2] = srcA[2] ^ srcB[2];
    dst[3] = srcA[3] ^ srcB[3];
    dst[4] = srcA[4] ^ srcB[4];
    dst[5] = srcA[5] ^ srcB[5];
    dst[6] = srcA[6] ^ srcB[6];
    dst[7] = srcA[7] ^ srcB[7];
}




int rijndaelKeySetupEnc(u32 *rk, u8 *cipherKey, int keyBits)
{
	int i = 0;
	u32 temp;

	rk[0] = GETU32(cipherKey     );
	rk[1] = GETU32(cipherKey +  4);
	rk[2] = GETU32(cipherKey +  8);
	rk[3] = GETU32(cipherKey + 12);
	if (keyBits == 128) {
		for (;;) {
			temp  = rk[3];
			rk[4] = rk[0] ^
				(Te4[(temp >> 16) & 0xff] & 0xff000000) ^
				(Te4[(temp >>  8) & 0xff] & 0x00ff0000) ^
				(Te4[(temp      ) & 0xff] & 0x0000ff00) ^
				(Te4[(temp >> 24)       ] & 0x000000ff) ^
				rcon[i];
			rk[5] = rk[1] ^ rk[4];
			rk[6] = rk[2] ^ rk[5];
			rk[7] = rk[3] ^ rk[6];
			if (++i == 10) {
				return 10;
			}
			rk += 4;
		}
	}
	rk[4] = GETU32(cipherKey + 16);
	rk[5] = GETU32(cipherKey + 20);
	if (keyBits == 192) {
		for (;;) {
			temp = rk[ 5];
			rk[ 6] = rk[ 0] ^
				(Te4[(temp >> 16) & 0xff] & 0xff000000) ^
				(Te4[(temp >>  8) & 0xff] & 0x00ff0000) ^
				(Te4[(temp      ) & 0xff] & 0x0000ff00) ^
				(Te4[(temp >> 24)       ] & 0x000000ff) ^
				rcon[i];
			rk[ 7] = rk[ 1] ^ rk[ 6];
			rk[ 8] = rk[ 2] ^ rk[ 7];
			rk[ 9] = rk[ 3] ^ rk[ 8];
			if (++i == 8) {
				return 12;
			}
			rk[10] = rk[ 4] ^ rk[ 9];
			rk[11] = rk[ 5] ^ rk[10];
			rk += 6;
		}
	}
	rk[6] = GETU32(cipherKey + 24);
	rk[7] = GETU32(cipherKey + 28);
	if (keyBits == 256) {
		for (;;) {
			temp = rk[ 7];
			rk[ 8] = rk[ 0] ^
				(Te4[(temp >> 16) & 0xff] & 0xff000000) ^
				(Te4[(temp >>  8) & 0xff] & 0x00ff0000) ^
				(Te4[(temp      ) & 0xff] & 0x0000ff00) ^
				(Te4[(temp >> 24)       ] & 0x000000ff) ^
				rcon[i];
			rk[ 9] = rk[ 1] ^ rk[ 8];
			rk[10] = rk[ 2] ^ rk[ 9];
			rk[11] = rk[ 3] ^ rk[10];
			if (++i == 7) {
				return 14;
			}
			temp = rk[11];
			rk[12] = rk[ 4] ^
				(Te4[(temp >> 24)       ] & 0xff000000) ^
				(Te4[(temp >> 16) & 0xff] & 0x00ff0000) ^
				(Te4[(temp >>  8) & 0xff] & 0x0000ff00) ^
				(Te4[(temp      ) & 0xff] & 0x000000ff);
			rk[13] = rk[ 5] ^ rk[12];
			rk[14] = rk[ 6] ^ rk[13];
			rk[15] = rk[ 7] ^ rk[14];

			rk += 8;
		}
	}
	return 0;
}




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




void rijndaelEncrypt(u32 *rk, int Nr, u8 *pt, u8 *ct)
{
	u32 s0, s1, s2, s3, t0, t1, t2, t3;
	int r;

	s0 = GETU32(pt     ) ^ rk[0];
	s1 = GETU32(pt +  4) ^ rk[1];
	s2 = GETU32(pt +  8) ^ rk[2];
	s3 = GETU32(pt + 12) ^ rk[3];
	r = Nr >> 1;
	for (;;) {
		t0 =
			Te0[(s0 >> 24)       ] ^
			Te1[(s1 >> 16) & 0xff] ^
			Te2[(s2 >>  8) & 0xff] ^
			Te3[(s3      ) & 0xff] ^
			rk[4];
		t1 =
			Te0[(s1 >> 24)       ] ^
			Te1[(s2 >> 16) & 0xff] ^
			Te2[(s3 >>  8) & 0xff] ^
			Te3[(s0      ) & 0xff] ^
			rk[5];
		t2 =
			Te0[(s2 >> 24)       ] ^
			Te1[(s3 >> 16) & 0xff] ^
			Te2[(s0 >>  8) & 0xff] ^
			Te3[(s1      ) & 0xff] ^
			rk[6];
		t3 =
			Te0[(s3 >> 24)       ] ^
			Te1[(s0 >> 16) & 0xff] ^
			Te2[(s1 >>  8) & 0xff] ^
			Te3[(s2      ) & 0xff] ^
			rk[7];

		rk += 8;
		if (--r == 0) {
			break;
		}

		s0 =
			Te0[(t0 >> 24)       ] ^
			Te1[(t1 >> 16) & 0xff] ^
			Te2[(t2 >>  8) & 0xff] ^
			Te3[(t3      ) & 0xff] ^
			rk[0];
		s1 =
			Te0[(t1 >> 24)       ] ^
			Te1[(t2 >> 16) & 0xff] ^
			Te2[(t3 >>  8) & 0xff] ^
			Te3[(t0      ) & 0xff] ^
			rk[1];
		s2 =
			Te0[(t2 >> 24)       ] ^
			Te1[(t3 >> 16) & 0xff] ^
			Te2[(t0 >>  8) & 0xff] ^
			Te3[(t1      ) & 0xff] ^
			rk[2];
		s3 =
			Te0[(t3 >> 24)       ] ^
			Te1[(t0 >> 16) & 0xff] ^
			Te2[(t1 >>  8) & 0xff] ^
			Te3[(t2      ) & 0xff] ^
			rk[3];
	}
	s0 =
		(Te4[(t0 >> 24)       ] & 0xff000000) ^
		(Te4[(t1 >> 16) & 0xff] & 0x00ff0000) ^
		(Te4[(t2 >>  8) & 0xff] & 0x0000ff00) ^
		(Te4[(t3      ) & 0xff] & 0x000000ff) ^
		rk[0];
	PUTU32(ct     , s0);
	s1 =
		(Te4[(t1 >> 24)       ] & 0xff000000) ^
		(Te4[(t2 >> 16) & 0xff] & 0x00ff0000) ^
		(Te4[(t3 >>  8) & 0xff] & 0x0000ff00) ^
		(Te4[(t0      ) & 0xff] & 0x000000ff) ^
		rk[1];
	PUTU32(ct +  4, s1);
	s2 =
		(Te4[(t2 >> 24)       ] & 0xff000000) ^
		(Te4[(t3 >> 16) & 0xff] & 0x00ff0000) ^
		(Te4[(t0 >>  8) & 0xff] & 0x0000ff00) ^
		(Te4[(t1      ) & 0xff] & 0x000000ff) ^
		rk[2];
	PUTU32(ct +  8, s2);
	s3 =
		(Te4[(t3 >> 24)       ] & 0xff000000) ^
		(Te4[(t0 >> 16) & 0xff] & 0x00ff0000) ^
		(Te4[(t1 >>  8) & 0xff] & 0x0000ff00) ^
		(Te4[(t2      ) & 0xff] & 0x000000ff) ^
		rk[3];
	PUTU32(ct + 12, s3);
}


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
