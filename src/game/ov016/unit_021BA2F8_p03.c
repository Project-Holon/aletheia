/*
 * file:     unit_021BA2F8_p03.c
 * unit:     yes
 * function: AutoConfigThread, func_021BAC20, func_021BADD8, func_021BAF90, func_021BAFD8, func_021BB290, func_021BB420, rijndaelDecrypt, func_021BBB98, func_021BBBC0, func_021BBC38, func_021BBC8C, func_021BC4D4, func_021BC500, MD5_memcpy, func_021BC544, func_021BC55C, GetTickCount, func_021BC5A0, func_021BC5C4, PutHex, func_021BC608, func_021BC63C, ATERMi_ApConfigEnd, ATERMi_ApConfigGetState, func_021BC7F0, SendNotify
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
 *   PADDING       0x021DABD8  data
 *   Decode        0x021BC500  thumb
 *   MY_MD5Init    0x021BBB98  thumb
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv    0x0209C00C  arm
 *   func_021DCFD0   0x021DCFD0  data
 *   func_021B97A8  0x021b97a8  thumb  ov016
 *   func_020853B0  0x020853b0  arm
 *   func_020853C0  0x020853c0  arm
 *   func_021BC584  0x021bc584  thumb  ov016
 *   func_021BC804  0x021bc804  thumb  ov016
 *   func_02085868  0x02085868  arm
 *   g_021DCFD0  0x021dcfd0  data
 *   g_021DAB58  0x021dab58  data
 *   g_021DD07C  0x021dd07c  data
 *   func_021BABE8  0x021babe8  thumb  ov016
 *   g_021DD13C  0x021dd13c  data
 *   OS_Sleep               0x02085A38  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_JoinThread          0x02085710  arm
 *   FreeAtermApcNetwork    0x021B984C  thumb
 *   gAtermThread           0x021DD07C  data
 *   func_021DD13C   0x021DD13C  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/arm9_sdk/libc/memcmp/string.h"
#include "../../matched/include/G__ATERMApConfigParam.h"

#define KW_BSWAP64(x) \
    ((((x) & 0x00000000000000ffULL) << 56) | \
     (((x) & 0x000000000000ff00ULL) << 40) | \
     (((x) & 0x0000000000ff0000ULL) << 24) | \
     (((x) & 0x00000000ff000000ULL) << 8)  | \
     (((x) & 0x000000ff00000000ULL) >> 8)  | \
     (((x) & 0x0000ff0000000000ULL) >> 24) | \
     (((x) & 0x00ff000000000000ULL) >> 40) | \
     (((x) & 0xff00000000000000ULL) >> 56))
#define GETU32(pt) (((u32_021BABE8)(pt)[0] << 24) ^ ((u32_021BABE8)(pt)[1] << 16) ^ ((u32_021BABE8)(pt)[2] <<  8) ^ ((u32_021BABE8)(pt)[3]))
#define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
#define FF(a, b, c, d, x, s, ac) { \
 (a) += F ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define GG(a, b, c, d, x, s, ac) { \
 (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define HH(a, b, c, d, x, s, ac) { \
 (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define II(a, b, c, d, x, s, ac) { \
 (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define BSS atermset_bss
#define DAT atermset_data
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
struct _OSThread;
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
    void                    (*apci_user_callback)(int event, void *arg);
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

typedef unsigned long u32_021BABE8;

typedef unsigned char u8;

typedef unsigned long UINT4;

typedef unsigned char *POINTER;

typedef struct {
    UINT4         state[4];
    UINT4         count[2];
    unsigned char buffer[64];
} MY_MD5_CTX;

typedef unsigned short u16;

typedef unsigned int u32_021BC500;

typedef unsigned int   u32;

typedef struct _OSThread OSThread;

typedef struct _ATERMApConfigState {
    int state;
    int timeout;
    int result;
} ATERMApConfigState;

extern int AutoConfigThreadEx(void);
extern void DisconnectAP(void);
extern int func_021BAFD8(unsigned long *rk, unsigned char *cipherKey, int keyBits);
extern void func_021BB420(unsigned long *rk, int Nr, unsigned char *pt, unsigned char *ct);
extern void func_021BAF90(unsigned char *srcA, unsigned char *srcB, unsigned char *dst);
extern int func_021BB290(unsigned long *rk, unsigned char *cipherKey, int keyBits);
extern void func_021BB7DC(unsigned long *rk, int Nr, unsigned char *ct, unsigned char *pt);
extern void Decode(UINT4 *output, unsigned char *input, unsigned int len);
extern void MY_MD5Init(MY_MD5_CTX *context);
extern unsigned long long OS_GetTick(void);
extern void *func_020923B0(void *p, int c, u32 n);
extern int func_021B97A8(int maxap);
extern int func_020853B0(void);
extern void func_020853C0(struct _OSThread *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern unsigned long func_021BC584(void);
extern void func_021BC804(void);
extern void func_02085868(struct _OSThread *thread);
extern void func_021BABE8(void *arg);
extern void OS_Sleep(unsigned long msec);
extern int OS_IsThreadTerminated(OSThread *thread);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void OS_JoinThread(OSThread *thread);
extern int FreeAtermApcNetwork(void);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
void AutoConfigThread(void *arg);
void aeskw_xor64(unsigned char *srcA, unsigned char *srcB, unsigned char *dst);
int rijndaelKeySetupEnc(u32_021BABE8 *rk, u8 *cipherKey, int keyBits);
int rijndaelKeySetupDec(u32_021BABE8 *rk, u8 *cipherKey, int keyBits);
void rijndaelEncrypt(u32_021BABE8 *rk, int Nr, u8 *pt, u8 *ct);
void rijndaelDecrypt(u32_021BABE8 *rk, int Nr, u8 *ct, u8 *pt);
void func_021BBB98(unsigned int *p);
void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen);
void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context);
void MD5Transform(UINT4 state[4], unsigned char block[64]);
void Encode(unsigned char *output, UINT4 *input, unsigned int len);
void func_021BC500(u32_021BC500 *dst, const u8 *src, u32_021BC500 count);
void MD5_memcpy(unsigned char *output, unsigned char *input, unsigned int len);
void MD5_memset(unsigned char *output, int value, unsigned int len);
unsigned long GetTickCount(void);
void *func_021BC5A0(int a, int b);
void func_021BC5C4(int a);
int PutHex(char *lpwrite, char ch);
int PutMac(char *lpwrite, char *lps);
int func_021BC63C(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize);
int ATERMi_ApConfigEnd(void);
int ATERMi_ApConfigGetState(ATERMApConfigState *state);
int func_021BC7F0(int a);
void SendNotify(void);
extern ATERMSET_BSS atermset_bss;
extern ATERMSET_DATA atermset_data;
extern u32_021BABE8 rcon[10];
extern u32_021BABE8 Te4[256];
extern u32_021BABE8 Td0[256];
extern u32_021BABE8 Td1[256];
extern u32_021BABE8 Td2[256];
extern u32_021BABE8 Td3[256];
extern u32_021BABE8 Te0[256];
extern u32_021BABE8 Te1[256];
extern u32_021BABE8 Te2[256];
extern u32_021BABE8 Te3[256];
extern u32_021BABE8 Td4[256];
extern unsigned char PADDING[64];
extern struct _OSThread g_021DD07C;
extern struct _ATERMApConfigParam g_021DD13C;
extern OSThread gAtermThread;
extern char func_021DD13C[];











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










int rijndaelKeySetupEnc(u32_021BABE8 *rk, u8 *cipherKey, int keyBits)
{
	int i = 0;
	u32_021BABE8 temp;

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










int rijndaelKeySetupDec(u32_021BABE8 *rk, u8 *cipherKey, int keyBits)
{
	int Nr, i, j;
	u32_021BABE8 temp;

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










void rijndaelEncrypt(u32_021BABE8 *rk, int Nr, u8 *pt, u8 *ct)
{
	u32_021BABE8 s0, s1, s2, s3, t0, t1, t2, t3;
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








void rijndaelDecrypt(u32_021BABE8 *rk, int Nr, u8 *ct, u8 *pt)
{
	u32_021BABE8 s0, s1, s2, s3, t0, t1, t2, t3;
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






void func_021BBB98(unsigned int *p)
{
    p[5] = 0;
    p[4] = 0;
    p[0] = 0x67452301;
    p[1] = 0xefcdab89;
    p[2] = 0x98badcfe;
    p[3] = 0x10325476;
}








void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen)
{
    unsigned int i, index, partLen;

    index = (unsigned int)((context->count[0] >> 3) & 0x3F);
    if ((context->count[0] += ((UINT4)inputLen << 3)) < ((UINT4)inputLen << 3))
        context->count[1]++;
    context->count[1] += ((UINT4)inputLen >> 29);
    partLen = 64 - index;
    if (inputLen >= partLen) {
        MD5_memcpy((POINTER)&context->buffer[index], (POINTER)input, partLen);
        MD5Transform(context->state, context->buffer);
        for (i = partLen; i + 63 < inputLen; i += 64)
            MD5Transform(context->state, &input[i]);
        index = 0;
    } else {
        i = 0;
    }
    MD5_memcpy((POINTER)&context->buffer[index], (POINTER)&input[i], inputLen - i);
}








void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context)
{
    unsigned char bits[8];
    unsigned int index;

    Encode(bits, context->count, 8);
    index = (unsigned int)((context->count[0] >> 3) & 0x3f);
    MY_MD5Update(context, PADDING, (index < 56) ? (56 - index) : (120 - index));
    MY_MD5Update(context, bits, 8);
    Encode(digest, context->state, 16);
    MD5_memset((POINTER)context, 0, sizeof(*context));
}








void MD5Transform(UINT4 state[4], unsigned char block[64])
{
  UINT4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];

  Decode (x, block, 64);

  /* Round 1 */
  FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
  FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
  FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
  FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
  FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
  FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
  FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
  FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
  FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
  FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
  FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
  FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
  FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
  FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
  FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
  FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

 /* Round 2 */
  GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
  GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
  GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
  GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
  GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
  GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
  GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
  GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
  GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
  GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
  GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
  GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
  GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
  GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
  GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
  GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

  /* Round 3 */
  HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
  HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
  HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
  HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
  HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
  HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
  HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
  HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
  HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
  HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
  HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
  HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
  HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
  HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
  HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
  HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

  /* Round 4 */
  II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
  II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
  II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
  II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
  II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
  II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
  II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
  II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
  II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
  II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
  II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
  II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
  II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
  II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
  II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
  II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;

  /* Zeroize sensitive information. */
  MD5_memset ((POINTER)x, 0, sizeof (x));
}








void Encode(unsigned char *output, UINT4 *input, unsigned int len)
{
    unsigned int i, j;

    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = (unsigned char)(input[i] & 0xff);
        output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
        output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
        output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
    }
}





void func_021BC500(u32_021BC500 *dst, const u8 *src, u32_021BC500 count)
{
    u32_021BC500 i = 0;
    while (i < count) {
        u32_021BC500 b0 = src[i];
        u32_021BC500 b1 = src[i + 1];
        u32_021BC500 b2 = src[i + 2];
        u32_021BC500 b3 = src[i + 3];
        *dst++ = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
        i += 4;
    }
}





void MD5_memcpy(unsigned char *output, unsigned char *input, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++)
        output[i] = input[i];
}






void MD5_memset(unsigned char *output, int value, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++)
        ((char *)output)[i] = (char)value;
}







static void MD5Encode(unsigned char *digest, unsigned char *psrc, int srclen)
{
    MY_MD5_CTX context;

    MY_MD5Init(&context);
    MY_MD5Update(&context, psrc, srclen);
    MY_MD5Final(digest, &context);
}





unsigned long GetTickCount(void)
{
    return (unsigned long)((OS_GetTick() * 64) / 0x82EA);
}



extern void *(*func_021DCFD0[])(int);




void *func_021BC5A0(int a, int b)
{
    int n = a * b;
    void *p = func_021DCFD0[1](n);

    if (p)
        func_020923B0(p, 0, n);
    return p;
}



extern void *(*func_021DCFD0[])(int);




void func_021BC5C4(int a)
{
    func_021DCFD0[3](a);
}






int PutHex(char *lpwrite, char ch)
{
    char *lpw;
    int i;
    int val;

    lpw = lpwrite;
    val = ((unsigned char)ch & 0xF0) >> 4;
    for (i = 0; i < 2; i++) {
        if (val <= 9)
            val += '0';
        else
            val += 'A' - 10;
        *lpw++ = val;
        val = (unsigned char)ch & 0x0F;
    }
    *lpw = 0;
    return lpw - lpwrite;
}








int PutMac(char *lpwrite, char *lps)
{
    char *lpw;
    int i;

    lpw = lpwrite;
    for (i = 0; i < 6; i++) {
        lpw += PutHex(lpw, *lps++);
        if (i < 5)
            *lpw++ = ':';
    }
    *lpw = 0;
    return lpw - lpwrite;
}








int func_021BC63C(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize)
{
    int ret;

    if (BSS.gAtermApState >= 1 && BSS.gAtermApState <= 5)
        return -10;
    *(volatile int *)&DAT.gMaxBssIdList = maxap;
    *(volatile int *)&BSS.gAtermApState = 7;
    *(volatile void **)&BSS.gAtermNotify = (void *)notify;
    *(volatile void **)&BSS.gAtermAlloc = (void *)alloc;
    *(volatile void **)&BSS.gAtermFree = (void *)free;
    *(volatile unsigned long *)&DAT.gThreadStackSize = stackSize;
    ret = func_021B97A8(maxap);
    BSS.bInitAtermApNetwork = 1;
    if (ret < 0) {
        BSS.gAtermApResult = ret;
        return ret;
    }
    BSS.gThreadStack = (unsigned long long *)BSS.gAtermAlloc(DAT.gThreadStackSize);
    if (BSS.gThreadStack == 0) {
        BSS.gAtermApResult = -1;
        return -1;
    }
    if (func_020853B0() != 1) {
        BSS.gAtermApResult = -9;
        return -9;
    }
    func_020853C0(&g_021DD07C, func_021BABE8, 0, (unsigned char *)BSS.gThreadStack + (DAT.gThreadStackSize & ~7), DAT.gThreadStackSize, prio);
    BSS.gAtermApState = 1;
    DAT.gAtermApTimeout = func_021BC584() + 60000;
    BSS.bAtermApCanceled = 0;
    memset(&g_021DD13C, 0, 232);
    func_021BC804();
    func_02085868(&g_021DD07C);
    BSS.gAtermThreadId = 1;
    return 1;
}






int ATERMi_ApConfigEnd(void)
{
    int retv;
    int laststate;

    if (atermset_bss.gAtermThreadId) {
        laststate = atermset_bss.gAtermApState;
        atermset_bss.bAtermApCanceled = 1;
        while (atermset_bss.gAtermApState >= 1 && atermset_bss.gAtermApState <= 5)
            OS_Sleep(100);
        OS_Sleep(500);
        while (!OS_IsThreadTerminated(&gAtermThread)) {
            OS_WakeupThreadDirect(&gAtermThread);
            OS_JoinThread(&gAtermThread);
        }
        if (atermset_bss.gThreadStack) {
            atermset_bss.gAtermFree(atermset_bss.gThreadStack);
            atermset_bss.gThreadStack = 0;
        }
        atermset_bss.gAtermThreadId = 0;
        if (laststate != atermset_bss.gAtermApState)
            SendNotify();
    }
    if (atermset_bss.bInitAtermApNetwork > 0) {
        retv = FreeAtermApcNetwork();
        atermset_bss.bInitAtermApNetwork = 0;
        return retv;
    }
    return -10;
}





int ATERMi_ApConfigGetState(ATERMApConfigState *state)
{
    state->state = atermset_bss.gAtermApState;
    if (atermset_data.gAtermApTimeout == -1)
        state->timeout = -1;
    else
        state->timeout = atermset_data.gAtermApTimeout - GetTickCount();
    state->result = atermset_bss.gAtermApResult;
    return 1;
}




int func_021BC7F0(int a)
{
    func_02092344((void *)a, func_021DD13C, 0xe8);
    return 1;
}



void SendNotify(void)
{
    ATERMApConfigState state;

    ATERMi_ApConfigGetState(&state);
    atermset_bss.gAtermNotify(&state);
}
