/*
 * file:     atermset.c
 * unit:     yes
 * function: APCi_Notify, APCi_MoveIdleState, CopyApList, APC_SearchStart, APC_Disconnect, APC_End, APC_Connect, APC_Init, APC_GetState, soAlloc, soFree, AtermApc_InitEventBuf, AtermApc_GetEvent, AtermApc_callback, alarmCallback, InitAtermApcNetwork, FreeAtermApcNetwork, ConnectAP, DisconnectAP, CheckAccessPoint, ScanAP, SendFrameViaInterface, SendBroadcast, SendFrame, GetFrameData, GetElementData, GetFirstElement, SetFrameData, SetElementData, SetSingleElement, IsSearchCommand, GetCommandElement, SetSearchRes, GetOwnMacAddress, GetMacEncKey, GetWLanSetElement, AsciiToHex, StoreNetParam, AutoConfigThreadEx, AutoConfigThread, keywrap_encrypt, keywrap_decrypt, aeskw_xor64, rijndaelKeySetupEnc, rijndaelKeySetupDec, rijndaelEncrypt, rijndaelDecrypt, MY_MD5Init, MY_MD5Update, MY_MD5Final, MD5Transform, Encode, Decode, MD5_memcpy, MD5_memset, MD5Encode, GetTickCount, Calloc, Free, PutHex, PutMac, DWCi_RakurakuATERMi_ApConfigStart, ATERMi_ApConfigEnd, ATERMi_ApConfigGetState, DWCi_RakurakuATERMi_ApConfigGetResult, SendNotify
 * address:  0x021B9038
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p -ipa file
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * sdk:      TwlDWC libdwcutil.TWL.HYB.a atermset.o
 *
 * One vendor object (layout/symbols_sdk.json, 0x021B9038..0x021BC820). Its .comment is
 * Metrowerks C/C++ for ARM 3.0.0.126, the 2.0/sp1p2 front end, for every function
 * (APC_GetAPList and GetAdapterMac, earlier tagged 1.1p1, build the same bytes under it).
 * The object is built with -ipa file: a static function nobody in the file calls is
 * dropped, so the parts of the earlier split each lost callees. Every function is static,
 * as the vendor object binds it, except the four ATERMi_ApConfig* entry points (global in
 * the object, called from rakuraku.c) and soAlloc / soFree, which the vendor object
 * reaches through its own AtermSOConfig initializer; that data is defined outside this
 * file here, so they stay global or -ipa file drops them.
 * GetMacEncKey is defined K&R style: DWARF gives it one parameter, and its caller
 * (AutoConfigThreadEx) passes a second argument, which a prototyped definition would reject.
 * AtermApc_callback takes the APC_Init callback signature (event, arg); the arg is unused.
 *
 * symbols:
 *   OS_GetMacAddress               0x02087C6C  arm  arm9
 *   GetMacEncKey                   0x021BA2F8  thumb  ov016
 *   atermset_bss           0x021DCFD0  data
 *   sAtermsetApciUserCallback     0x021DD050  data
 *   WCM_SearchAsync        0x02165144  arm
 *   WCM_ConnectAsync       0x021652A4  arm
 *   WCM_CleanupAsync       0x02165088  arm
 *   WCM_Finish             0x02164EE0  arm
 *   WCM_DisconnectAsync    0x02165478  arm
 *   WCM_StartupAsync       0x02164F98  arm
 *   WCM_LockApList         0x02165C28  arm
 *   WCM_CountApList        0x02165BD0  arm
 *   WCM_PointApList        0x02165CA0  arm
 *   MIi_CpuCopy32          0x02082A90  arm
 *   OS_DisableInterrupts   0x02087988  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   WCM_Bssid_Any          0x021A1988  data
 *   WCM_Essid_Any          0x021A1990  data
 *   MI_CpuFill8            0x02082BCC  arm
 *   apci_bssid_buf         0x021DD488  data
 *   apci_essid_buf         0x021DD4C0  data
 *   MI_CpuCopy8            0x02082D44  arm
 *   WCM_Init               0x02164D64  arm
 *   OS_LockMutex           0x02086028  arm
 *   OS_UnlockMutex         0x02086078  arm
 *   AllocLock              0x021DD064  data
 *   event_buf              0x021DD054  data
 *   OS_Sleep               0x02085A38  arm
 *   atermset_data          0x021DAB58  data
 *   OS_CreateAlarm         0x02087254  arm
 *   OS_SetAlarm            0x0208738C  arm
 *   OS_CancelAlarm         0x020873F8  arm
 *   SOC_Startup            0x0215F8FC  arm
 *   AtermSOConfig          0x021DAB6C  data
 *   SOC_Cleanup            0x0215FA90  arm
 *   memcpy                 0x02092344  arm
 *   strlen                 0x0209477C  arm
 *   memcmp                 0x020923F0  arm
 *   sAtermsetTable1             0x021DABC4  data
 *   strcpy                 0x02094798  arm
 *   sAtermsetBtAutoResult           0x021DCFD0  data
 *   sAtermsetLpElementData          0x021DAB58  data
 *   gAPSSID                0x021DD4E0  data
 *   gAPMac                 0x021DD480  data
 *   SOC_SendTo             0x0215F5B4  arm
 *   SOCL_GetHostID         0x0215EF48  arm
 *   SOC_U32to4U8           0x0215FBAC  arm
 *   memset                 0x020923B0  arm
 *   atermset_rodata        0x021D77C8  data
 *   btAdapterMAC           0x021DD478  data
 *   ElementData            0x021DD504  data
 *   sAtermsetTable2             0x021DAC18  data
 *   gAtermsetBlock4             0x021DD224  data
 *   gAtermsetBlock6             0x021DD350  data
 *   gAtermsetBlock2             0x021DD13C  data
 *   gAtermsetBlock3             0x021DD150  data
 *   SOC_Socket             0x0215F428  arm
 *   SOC_Bind               0x0215F454  arm
 *   SOC_Close              0x0215F644  arm
 *   SOC_RecvFrom           0x0215F500  arm
 *   GetWLanSetElement      0x021BA3F4  thumb
 *   StoreNetParam          0x021BA67C  thumb
 *   gAtermsetBlock7             0x021DD490  data
 *   gAtermsetBlock10             0x021DDD04  data
 *   gAtermsetBlock1             0x021DD020  data
 *   gAtermsetBlock8             0x021DD4A0  data
 *   gAtermsetBlock9             0x021DD4A8  data
 *   gAtermsetBlock5             0x021DD310  data
 *   rcon                   0x021D77D0  data
 *   Te4                    0x021D93F8  data
 *   Td0                    0x021D97F8  data
 *   Td1                    0x021D9BF8  data
 *   Td2                    0x021D77F8  data
 *   Td3                    0x021D7BF8  data
 *   Te0                    0x021D83F8  data
 *   Te1                    0x021D87F8  data
 *   Te2                    0x021D8BF8  data
 *   Te3                    0x021D8FF8  data
 *   Td4                    0x021D7FF8  data
 *   PADDING                0x021DABD8  data
 *   OS_GetTick             0x020870D0  arm
 *   OS_IsThreadAvailable          0x020853B0  arm
 *   OS_CreateThread          0x020853C0  arm
 *   OS_WakeupThreadDirect          0x02085868  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_JoinThread          0x02085710  arm
 *   gAtermThread           0x021DD07C  data
 *   _ll_udiv                     0x0209C00C  arm
 *   _ull_mul                     0x0209C054  arm
 */
#define GAME_TYPES_U32_LONG
#include "../libc/memcmp/string.h"
#include "../ov009/wcm_system.h"
#include "../ov009/wcm_aplist.h"
#include "../ov009/soc.h"
struct _ATERMApConfigParam {
    char ssid[32];
    int auth_mode;
    int wepkeyid;
    char wepkey[4][32];
    char wpakey[64];
};
struct ATERMSET_DATA {
    unsigned char *lpElementData;
    int bDebug;
    unsigned long gThreadStackSize;
    unsigned long gAtermApTimeout;
    int gMaxBssIdList;
};
struct WCMConfig;
struct WMBssDesc;
struct _ATERMApConfigState;
struct ATERMSET_BSS {
    unsigned char btAutoResult;
    unsigned char pad_1[0x3];
    void * (*gAtermAlloc)(unsigned long);
    struct WCMConfig *apci_IWConfig;
    void (*gAtermFree)(void *);
    int bAtermApCanceled;
    int cbFrameData;
    int gAPId;
    int AutoPhase;
    int bApConnect;
    int bSO_Startup;
    unsigned char *apci_Wep;
    int apci_state;
    unsigned long long *gThreadStack;
    int cbElementData;
    int gAtermApState;
    unsigned char *apci_IWBuffer;
    unsigned char *apc_work;
    unsigned char *apci_bssid_ptr;
    unsigned char *apci_essid_ptr;
    struct WMBssDesc *apci_wmbssdesc;
    int bDualCfg;
    unsigned char *atermapc_work;
    unsigned long apci_connect_option;
    struct WMBssDesc *ap_list;
    unsigned long apci_search_option;
    int gAtermThreadId;
    int event_set_ptr;
    int event_get_ptr;
    int gMaxApList;
    int bInitAtermApNetwork;
    int gAtermApResult;
    void (*gAtermNotify)(struct _ATERMApConfigState *);
    void (*apci_user_callback)();
};
extern void *__builtin__clear(void *dest, unsigned long size);

#define APCI_CALLBACK(event)                                  \
    if (sAtermsetApciUserCallback != 0)                      \
        sAtermsetApciUserCallback((event), 0)
#define APC_WORK_SIZE(n) ((n) * 0xd0 + 0x2490)
#define ROUNDUP32(x) (((x) + 31LL) & ~31LL)
#define WMBSSDESC_SIZE 0xC0
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
#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))

#include "../types.h"

/*
 * atermset.o's .bss scalars from 0x021DCFD0 (sAtermsetBtAutoResult): the vendor object addresses
 * every word here through sAtermsetBtAutoResult's pool word plus an offset, so they are declared as
 * one object in the object's own order; member names are the vendor symbols. The arrays
 * and aggregates of the same section (event_buf, AllocLock, gAtermThread,
 * gAtermApConfigParam, AutoProfile) are pooled by their own symbols and declared apart.
 */
typedef struct ATERMSET_BSS ATERMSET_BSS;
/*
 * atermset.o's .data words from 0x021DAB58 (sAtermsetLpElementData), addressed through
 * sAtermsetLpElementData's pool word plus an offset; member names are the vendor symbols.
 */
typedef struct ATERMSET_DATA ATERMSET_DATA;

#include "../sdk_wm.h"

#include "../sdk_os.h"

#include "../sdk_soc.h"

typedef struct _NDIS_802_11_SSID {
    unsigned long SsidLength;
    unsigned char Ssid[32];
    unsigned char pad[4];
} NDIS_802_11_SSID;

typedef struct _WLAN_BSSID {
    NDIS_802_11_SSID Ssid;          /* +0x00 */
    unsigned char MacAddress[6];    /* +0x28 */
    unsigned short Privacy;         /* +0x2e */
} WLAN_BSSID;

typedef struct _BSSID_LIST {
    unsigned long NumberOfItems;
    WLAN_BSSID Bssid[1];
} BSSID_LIST;

typedef struct _FRAMEHEADER {
    unsigned short FrameID;
    unsigned short DataLength;
    unsigned short Reserved;
} FRAMEHEADER;

typedef struct _ELEMENTINFO {
    unsigned short ElementID;
    unsigned short ElementLength;
} ELEMENTINFO;

typedef struct _ELEMENTHEADER {
    unsigned short FullLength;
    unsigned short Reserved[3];
} ELEMENTHEADER;

typedef struct {
    unsigned char b[7];
} SUPPORTENC;

typedef struct {
    int keyType;
    int keyLen;
    char key[32];
} WepEntry;

typedef struct {
    int type;
    int defkey;
    char pad[0x28];
    WepEntry wep[4];
    char wpakey[72];
} WS11G_ENCRYPT_DATA;

typedef struct {
    char ConfigName[256];
    char Ssid[32];
    u32 NetworkType;
    u32 Channel;
    u32 PowerManagement;
    WS11G_ENCRYPT_DATA EncryptData;
    u32 AdHocBand;
    u32 AdHocChannel;
    u32 scanMode;
    u32 tpc;
} WS11G_PROFILE_DATA;

typedef unsigned long UINT4;

typedef unsigned char *POINTER;

typedef struct {
    UINT4         state[4];
    UINT4         count[2];
    unsigned char buffer[64];
} MY_MD5_CTX;

typedef struct _ATERMApConfigState {
    int state;
    int timeout;
    int result;
} ATERMApConfigState;

#include "../arm9/os_system.h"
#include "../arm9/mi_memory.h"
#include "../arm9/os_mutex.h"
#include "../arm9/os_thread.h"
#include "../arm9/os_alarm.h"
#include "../ov009/socl_resolve.h"
#include "../arm9/os_ownerinfo.h"
#include "../arm9/os_tick.h"

void *soAlloc(unsigned long name, long size);
void soFree(unsigned long name, void *ptr, long size);
static void AtermApc_callback(int event, void *arg);
static int GetMacEncKey();
int DWCi_RakurakuATERMi_ApConfigStart(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize);
int ATERMi_ApConfigEnd(void);
int ATERMi_ApConfigGetState(ATERMApConfigState *state);
int DWCi_RakurakuATERMi_ApConfigGetResult(void *a);

extern ATERMSET_BSS atermset_bss;
extern unsigned char sAtermsetBtAutoResult;
extern void (*sAtermsetApciUserCallback)(int event, void *arg);
extern unsigned char apci_bssid_buf[6];
extern unsigned char apci_essid_buf[32];
extern unsigned char WCM_Bssid_Any[];
extern unsigned char WCM_Essid_Any[];
extern OSMutex AllocLock;
extern int event_buf[4];
extern ATERMSET_DATA atermset_data;
extern SOCConfig AtermSOConfig;
extern char sAtermsetTable1[7];
extern u8 gAPSSID[34];
extern u8 gAPMac[6];
extern const SUPPORTENC atermset_rodata;
extern unsigned char btAdapterMAC[6];
extern unsigned char ElementData[2048];
extern const unsigned char sAtermsetTable2[];
extern WS11G_PROFILE_DATA gAtermsetBlock4;
/*
 * gAtermsetBlock6 is gAtermsetBlock4.EncryptData and gAtermsetBlock3 lies inside gAtermsetBlock2 (auth_mode at
 * +0x0C is gAtermsetBlock2.auth_mode). StoreNetParam and GetWLanSetElement load these two
 * addresses from their own pool words; written through the outer objects they get one pool
 * word fewer (DIFF), so the inner addresses keep their own declarations.
 */
extern WS11G_ENCRYPT_DATA gAtermsetBlock6;
extern struct _ATERMApConfigParam gAtermsetBlock2;
extern struct {
    int pad[3];
    int auth_mode;
    int wepkeyid;
} gAtermsetBlock3;
extern u8 gAtermsetBlock7[16];
extern u8 gAtermsetBlock10[2048];
extern int gAtermsetBlock1;
extern u8 gAtermsetBlock8[8];
extern u8 gAtermsetBlock9[16]; /* the MD5 digest written by MD5Encode */
extern signed char gAtermsetBlock5[];
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
extern unsigned char PADDING[64];
extern OSThread gAtermThread;

static void APCi_Notify(WCMNotice *notice);
static int APCi_MoveIdleState(void);
static int CopyApList(WMBssDesc *buf, int max);
static int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option);
static int APC_Disconnect(void);
static int APC_End(void);
static int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option);
static int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
static int APC_GetState(void);
static void AtermApc_InitEventBuf(void);
static int AtermApc_GetEvent(void);
static void alarmCallback(void *event);
static int InitAtermApcNetwork(int maxap);
static int FreeAtermApcNetwork(void);
static int ConnectAP(void);
static void DisconnectAP(void);
static int CheckAccessPoint(BSSID_LIST *pNewList, BSSID_LIST *pOldList, unsigned long *ApNo);
static int ScanAP(void);
static int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata);
static int SendBroadcast(int sock, unsigned char *lpb, int size);
static int SendFrame(int sock, void *target, unsigned char *lpb, int size);
static unsigned char *GetFrameData(unsigned char *lpframe, int *pid, int *psize);
static unsigned char *GetElementData(unsigned char **lplpb, unsigned char *lplimit, int *pid, int *psize);
static unsigned char *GetFirstElement(unsigned char *lpelement, int *pid, int *psize);
static int SetFrameData(unsigned char *lpframe, int id, unsigned char *pbody, register int size, const unsigned char *lpkey);
static unsigned char *SetElementData(unsigned char *lpb, int eid, unsigned char *pele, int esize);
static int SetSingleElement(unsigned char *lpbuff, int eid, unsigned char *pele, int esize);
static int IsSearchCommand(unsigned char *lpframe, int *pdual);
static int GetCommandElement(unsigned char *lpframe, int cmdid, unsigned char *lpelement, unsigned char *lpkey);
static int SetSearchRes(unsigned char *lpframe);
static int GetOwnMacAddress(unsigned char *mac);
static int GetWLanSetElement(u8 *lpelement);
static int AsciiToHex(unsigned char *byDest, char *szStr, int nLen);
static int StoreNetParam(void);
static int AutoConfigThreadEx(void);
static void AutoConfigThread(void *arg);
static int keywrap_encrypt(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen);
static int keywrap_decrypt(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen);
static void aeskw_xor64(unsigned char *srcA, unsigned char *srcB, unsigned char *dst);
static int rijndaelKeySetupEnc(u32 *rk, u8 *cipherKey, int keyBits);
static int rijndaelKeySetupDec(u32 *rk, u8 *cipherKey, int keyBits);
static void rijndaelEncrypt(u32 *rk, int Nr, u8 *pt, u8 *ct);
static void rijndaelDecrypt(u32 *rk, int Nr, u8 *ct, u8 *pt);
static void MY_MD5Init(MY_MD5_CTX *context);
static void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen);
static void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context);
static void MD5Transform(UINT4 state[4], unsigned char block[64]);
static void Encode(unsigned char *output, UINT4 *input, unsigned int len);
static void Decode(UINT4 *dst, unsigned char *src, unsigned int count);
static void MD5_memcpy(unsigned char *output, unsigned char *input, unsigned int len);
static void MD5_memset(unsigned char *output, int value, unsigned int len);
static void MD5Encode(unsigned char *digest, unsigned char *psrc, int srclen);
static unsigned long GetTickCount(void);
static void *Calloc(unsigned long a, unsigned long b);
static void Free(void *ptr);
static int PutHex(char *lpwrite, char ch);
static int PutMac(char *lpwrite, char *lps);
static void SendNotify(void);

static void APCi_Notify(WCMNotice *notice)
{
    if (notice == 0)
        return;
    switch (notice->notify) {
    case 1:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 4) {
                atermset_bss.apci_state = 3;
                APCI_CALLBACK(6);
            } else if (atermset_bss.apci_state == 6) {
                if (WCM_SearchAsync(atermset_bss.apci_bssid_ptr, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 8) {
                if (WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            }
        } else {
            atermset_bss.apci_state = 1;
            APCI_CALLBACK(2);
        }
        break;
    case 3:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 6) {
                atermset_bss.apci_state = 5;
                APCI_CALLBACK(8);
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(9);
        }
        break;
    case 5:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 8) {
                atermset_bss.apci_state = 7;
                APCI_CALLBACK(12);
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(13);
        }
        break;
    case 4:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 4) {
                atermset_bss.apci_state = 3;
                APCI_CALLBACK(10);
            } else if (atermset_bss.apci_state == 6) {
                if (WCM_SearchAsync(atermset_bss.apci_bssid_ptr, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 2) {
                if (WCM_CleanupAsync() != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 8) {
                if (WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(11);
        }
        break;
    case 6:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 4) {
                atermset_bss.apci_state = 3;
                APCI_CALLBACK(14);
            } else if (atermset_bss.apci_state == 6) {
                if (WCM_SearchAsync(atermset_bss.apci_bssid_ptr, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 2) {
                if (WCM_CleanupAsync() != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 8) {
                if (WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 7) {
                atermset_bss.apci_state = 3;
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(15);
        }
        break;
    case 2:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 2) {
                WCM_Finish();
                atermset_bss.apci_state = 0;
                APCI_CALLBACK(20);
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(2);
        }
        break;
    case 7:
        if (atermset_bss.apci_state == 5) {
            APCI_CALLBACK(5);
        }
        break;
    case 8:
        APCI_CALLBACK(4);
        break;
    case 9:
        atermset_bss.apci_state = 0;
        APCI_CALLBACK(3);
        break;
    case 0:
    default:
        APCI_CALLBACK(1);
        break;
    }
}

static int APCi_MoveIdleState(void)
{
    switch (atermset_bss.apci_state) {
    case 5:
        if (WCM_SearchAsync(0, 0, 0) != 3)
            return 0;
        break;
    case 7:
        if (WCM_DisconnectAsync() != 3)
            return 0;
        break;
    case 1:
        if (WCM_StartupAsync(atermset_bss.apci_IWConfig, APCi_Notify) != 3)
            return 0;
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
    default:
        return 0;
    }
    return 1;
}

static int CopyApList(WMBssDesc *buf, int max)
{
    int n;
    int i;

    WCM_LockApList(1);
    n = WCM_CountApList();
    if (n > 0) {
        for (i = 0; i < n; i++) {
            if (i >= max)
                break;
            MIi_CpuCopy32(WCM_PointApList(i), buf, 0xc0);
            buf++;
        }
    }
    WCM_LockApList(0);
    return n;
}

static int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option)
{
    unsigned long enabled;
    int i;

    enabled = OS_DisableInterrupts();
    atermset_bss.apci_search_option = option;
    atermset_bss.apci_bssid_ptr = apci_bssid_buf;
    if (bssid != 0) {
        for (i = 0; i < 6; i++)
            apci_bssid_buf[i] = *bssid++;
    } else {
        MI_CpuFill8(apci_bssid_buf, 0xFF, 6);
        atermset_bss.apci_bssid_ptr = WCM_Bssid_Any;
    }
    atermset_bss.apci_essid_ptr = apci_essid_buf;
    if (essid != 0 && essid_len > 0 && essid_len < 32) {
        for (i = 0; i < essid_len; i++)
            apci_essid_buf[i] = *essid++;
        for (; i < 32; i++)
            apci_essid_buf[i] = 0;
    } else {
        MI_CpuFill8(apci_essid_buf, 0xFF, 32);
        atermset_bss.apci_essid_ptr = WCM_Essid_Any;
    }
    if (atermset_bss.apci_state == 3) {
        if (WCM_SearchAsync(apci_bssid_buf, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) == 3) {
            atermset_bss.apci_state = 6;
            OS_RestoreInterrupts(enabled);
            return 1;
        }
    } else if (APCi_MoveIdleState() == 1) {
        atermset_bss.apci_state = 6;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

static int APC_Disconnect(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (atermset_bss.apci_state == 7 && WCM_DisconnectAsync() == 3) {
        atermset_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

static int APC_End(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (atermset_bss.apci_state == 3) {
        if (WCM_CleanupAsync() != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        atermset_bss.apci_state = 2;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (APCi_MoveIdleState() == 1) {
        atermset_bss.apci_state = 2;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

static int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    atermset_bss.apci_connect_option = option;
    if (wep_buf != 0)
        MI_CpuCopy8(wep_buf, atermset_bss.apci_Wep, 0x60);
    else
        MI_CpuFill8(atermset_bss.apci_Wep, 0, 0x60);
    MIi_CpuCopy32(wmbssdesc, atermset_bss.apci_wmbssdesc, sizeof(struct WMBssDesc));
    if (APCi_MoveIdleState() == 1) {
        atermset_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (atermset_bss.apci_state == 3 &&
        WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) == 3) {
        atermset_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

static int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    atermset_bss.apci_Wep = workbuffer;
    atermset_bss.apci_IWConfig = (struct WCMConfig *)(((uptr)workbuffer + 0x60 + 3) & ~3);
    atermset_bss.apci_IWBuffer = (void *)(((uptr)atermset_bss.apci_IWConfig + sizeof(struct WCMConfig) + 0x1F) & ~0x1F);
    atermset_bss.apci_wmbssdesc = (void *)(((uptr)atermset_bss.apci_IWBuffer + 0x2300 + 0x1F) & ~0x1F);
    atermset_bss.apci_IWConfig->pbdbuffer = (void *)(((uptr)atermset_bss.apci_wmbssdesc + 0xC0 + 0x1F) & ~0x1F);
    atermset_bss.apci_IWConfig->nbdbuffer = ((uptr)workbuffer + work_size) - (uptr)atermset_bss.apci_IWConfig->pbdbuffer;
    atermset_bss.apci_IWConfig->nbdmode = 0;
    atermset_bss.apci_IWConfig->dmano = 3;
    sAtermsetApciUserCallback = user_callback;
    if (atermset_bss.apci_state == 0) {
        if (WCM_Init(atermset_bss.apci_IWBuffer, 0x2300) != 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        atermset_bss.apci_state = 1;
    }
    if (atermset_bss.apci_state == 1) {
        if (WCM_StartupAsync(atermset_bss.apci_IWConfig, APCi_Notify) != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        atermset_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

static int APC_GetState(void)
{
    return atermset_bss.apci_state;
}

void *soAlloc(unsigned long name, long size)
{
    void *ptr;

    if (size > 0) {
        OS_LockMutex(&AllocLock);
        ptr = atermset_bss.gAtermAlloc(size);
        OS_UnlockMutex(&AllocLock);
        return ptr;
    }
    return 0;
}

void soFree(unsigned long name, void *ptr, long size)
{
    if (ptr != 0 && size > 0) {
        OS_LockMutex(&AllocLock);
        atermset_bss.gAtermFree(ptr);
        OS_UnlockMutex(&AllocLock);
    }
}

static void AtermApc_InitEventBuf(void)
{
    int i;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    atermset_bss.event_set_ptr = 0;
    atermset_bss.event_get_ptr = 0;
    for (i = 0; i < 4; i++)
        event_buf[i] = 0;
    OS_RestoreInterrupts(enabled);
}

static int AtermApc_GetEvent(void)
{
    unsigned long enabled;
    int event;

    enabled = OS_DisableInterrupts();
    if (atermset_bss.event_set_ptr == atermset_bss.event_get_ptr) {
        event = 0;
    } else {
        event = event_buf[atermset_bss.event_get_ptr];
        atermset_bss.event_get_ptr++;
        if (atermset_bss.event_get_ptr >= 4)
            atermset_bss.event_get_ptr = 0;
    }
    OS_RestoreInterrupts(enabled);
    return event;
}

static void AtermApc_callback(int event, void *arg)
{
    if (atermset_bss.event_set_ptr + 1 == atermset_bss.event_get_ptr)
        return;
    if (atermset_bss.event_set_ptr == atermset_bss.event_get_ptr + 3)
        return;
    event_buf[atermset_bss.event_set_ptr] = event;
    atermset_bss.event_set_ptr++;
    if (atermset_bss.event_set_ptr >= 4)
        atermset_bss.event_set_ptr = 0;
}

static void alarmCallback(void *event)
{
    AtermApc_callback((int)(uptr)event, 0);
}

static int InitAtermApcNetwork(int maxap)
{
    int loop_flag;
    int retv;

    loop_flag = 1;
    atermset_bss.gMaxApList = maxap;
    AtermApc_InitEventBuf();
    atermset_bss.atermapc_work = atermset_bss.gAtermAlloc(APC_WORK_SIZE(maxap) + 64 + maxap * sizeof(struct WMBssDesc));
    if (atermset_bss.atermapc_work == 0)
        return -1;
    atermset_bss.apc_work = (u8 *)ROUNDUP32((uptr)atermset_bss.atermapc_work);
    atermset_bss.ap_list = (struct WMBssDesc *)ROUNDUP32((uptr)atermset_bss.apc_work + APC_WORK_SIZE(maxap));
    if (APC_Init(AtermApc_callback, atermset_bss.apc_work, APC_WORK_SIZE(maxap)) == 0)
        return -2;
    do {
        int event;

        OS_Sleep(10);
        while ((event = AtermApc_GetEvent()) != 0) {
            switch (event) {
            case 4:
            case 5:
                break;
            case 6:
                loop_flag = 0;
                retv = 1;
                break;
            default:
                loop_flag = 0;
                retv = -2;
                break;
            }
        }
    } while (loop_flag);
    return retv;
}

static int FreeAtermApcNetwork(void)
{
    int loop_flag;

    loop_flag = 1;
    if (APC_End()) {
        while (loop_flag) {
            int event;

            OS_Sleep(10);
            while ((event = AtermApc_GetEvent()) != 0) {
                switch (event) {
                case 4:
                case 5:
                    break;
                case 20:
                    loop_flag = 0;
                    break;
                default:
                    loop_flag = 0;
                    break;
                }
            }
        }
    }
    if (atermset_bss.atermapc_work) {
        atermset_bss.gAtermFree(atermset_bss.atermapc_work);
        atermset_bss.atermapc_work = 0;
    }
    return 1;
}

static int ConnectAP(void)
{
    int loop_flag;
    struct WMBssDesc *wmbssdesc;
    int ret;
    int retv;
    OSAlarm alarm;

    loop_flag = 1;
    retv = -2;
    wmbssdesc = (struct WMBssDesc *)((unsigned char *)atermset_bss.ap_list + atermset_bss.gAPId * WMBSSDESC_SIZE);
    if (wmbssdesc == 0)
        return 0;
    if (APC_Connect(wmbssdesc, 0, 0x30000) == 0)
        return -2;
    OS_CreateAlarm(&alarm);
    OS_SetAlarm(&alarm, 0x3FEC42, alarmCallback, (void *)0x12);
    while (loop_flag) {
        if (GetTickCount() >= atermset_data.gAtermApTimeout) {
            retv = -3;
            break;
        }
        if (atermset_bss.bAtermApCanceled) {
            retv = -8;
            break;
        }
        OS_Sleep(10);
        while ((ret = AtermApc_GetEvent()) != 0) {
            switch (ret) {
            case 4:
            case 5:
            case 18:
            case 19:
                break;
            case 12:
                loop_flag = 0;
                retv = 1;
                break;
            case 13:
                if (atermset_bss.bAtermApCanceled) {
                    loop_flag = 0;
                    retv = -8;
                } else if (APC_Connect(wmbssdesc, 0, 0x30000) == 0) {
                    return retv;
                }
                break;
            default:
                loop_flag = 0;
                break;
            }
        }
    }
    OS_CancelAlarm(&alarm);
    while (AtermApc_GetEvent() != 0)
        ;
    if (retv > 0) {
        atermset_bss.bApConnect = 1;
        if (SOC_Startup(&AtermSOConfig) < 0)
            retv = -2;
        else
            atermset_bss.bSO_Startup = 1;
    }
    return retv;
}

static void DisconnectAP(void)
{
    int loop_flag;

    loop_flag = 1;
    if (atermset_bss.bApConnect) {
        if (APC_Disconnect()) {
            while (loop_flag) {
                int event;

                OS_Sleep(10);
                while ((event = AtermApc_GetEvent()) != 0) {
                    switch (event) {
                    case 4:
                    case 5:
                        break;
                    case 14:
                        loop_flag = 0;
                        break;
                    default:
                        loop_flag = 0;
                        break;
                    }
                }
            }
        }
        atermset_bss.bApConnect = 0;
    }
    if (atermset_bss.bSO_Startup) {
        atermset_bss.bSO_Startup = 0;
        SOC_Cleanup();
    }
}

/*
 * sdk:      CheckAccessPoint (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * atermset.o carries the 3.0.0.126 stamp (the 2.0/sp1p2 front end), as the other
 * atermset.o files do. memcmp must come from a header named string.h so the
 * inner loop keeps pOldList->NumberOfItems and SsidLength across the calls;
 * the libc/memcmp/string.h variant declares it. The DWARF places i in r6 (the
 * stealth scan over the old list); the other ranges of i share one stack slot.
 */
static int CheckAccessPoint(BSSID_LIST *pNewList, BSSID_LIST *pOldList, unsigned long *ApNo)
{
    int flagDetect;
    int Result;
    int flagNew;
    int flagOld;
    WLAN_BSSID *pNewBss;
    WLAN_BSSID *pOldBss;
    unsigned long j;
    unsigned long i;

    flagDetect = 0;
    Result = 0;
    pNewBss = pNewList->Bssid;
    pOldBss = pOldList->Bssid;
    for (i = 0; i < pNewList->NumberOfItems; i++) {
        char newSSID[34] = {0};

        memcpy(newSSID, pNewBss->Ssid.Ssid, 32);
        newSSID[pNewBss->Ssid.SsidLength] = 0;
        for (j = 0; j < pOldList->NumberOfItems; j++) {
            if (pNewBss->Ssid.SsidLength == 0 || pNewBss->Ssid.SsidLength > 32)
                break;
            if (pNewBss->Ssid.SsidLength == 1 &&
                (pNewBss->Ssid.Ssid[0] == 0 || pNewBss->Ssid.Ssid[0] == ' '))
                break;
            if (memcmp(newSSID, pOldBss->Ssid.Ssid, strlen(newSSID)) == 0 &&
                memcmp(pNewBss->MacAddress, pOldBss->MacAddress, 6) == 0 &&
                pNewBss->Privacy != pOldBss->Privacy && pNewBss->Privacy == 0) {
                flagDetect = 1;
                break;
            }
            pOldBss++;
        }
        if (flagDetect)
            break;
        pNewBss++;
        pOldBss = pOldList->Bssid;
    }

    if (!flagDetect) {
        char newSSID[34] = {0};

        flagNew = 0;
        flagOld = 0;
        pNewBss = pNewList->Bssid;
        pOldBss = pOldList->Bssid;
        for (i = 0; i < pOldList->NumberOfItems; i++) {
            memcpy(newSSID, pOldBss->Ssid.Ssid, 32);
            newSSID[pOldBss->Ssid.SsidLength] = 0;
            if (memcmp(newSSID, sAtermsetTable1, strlen(sAtermsetTable1)) == 0 && pOldBss->Privacy == 0) {
                flagOld = 1;
                break;
            }
            pOldBss++;
        }
        for (i = 0; i < pNewList->NumberOfItems; i++) {
            memcpy(newSSID, pNewBss->Ssid.Ssid, 32);
            newSSID[pNewBss->Ssid.SsidLength] = 0;
            if (strlen(newSSID) == strlen(sAtermsetTable1) &&
                memcmp(newSSID, sAtermsetTable1, strlen(sAtermsetTable1)) == 0 && pNewBss->Privacy == 0) {
                flagNew = 1;
                break;
            }
            pNewBss++;
        }
        if (flagNew && !flagOld)
            flagDetect = 1;
    }
    if (flagDetect) {
        *ApNo = i;
        Result = 1;
    }
    return Result;
}

static int ScanAP(void)
{
    int retv;
    int retry;
    int i, n;
    unsigned long ApNo;
    unsigned long BssListSize;
    BSSID_LIST *pBssList;
    BSSID_LIST *pOldList;
    WLAN_BSSID *pBssid;
    char apBSSID[32];
    int loop_flag;
    OSAlarm alarm;
    int ap_count;
    int nfound;
    WMBssDesc *wmbssdesc;

    retv = -1;
    pOldList = 0;
    ApNo = 0;
    BssListSize = sizeof(BSSID_LIST) + atermset_bss.gMaxApList * sizeof(WLAN_BSSID);
    pBssList = Calloc(1, BssListSize);
    if (pBssList == 0)
        goto end;
    pOldList = Calloc(1, BssListSize);
    if (pOldList == 0)
        goto end;
    for (retry = 0; retry < 30 && !atermset_bss.bAtermApCanceled; retry++) {
        if (GetTickCount() >= atermset_data.gAtermApTimeout)
            break;
        if (APC_SearchStart(0, 0, 0, 0x30BFFE) == 0) {
            retv = -2;
            goto end;
        }
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0xFFB10, alarmCallback, (void *)0x13);
        loop_flag = 1;
        ap_count = 0;
        while (loop_flag) {
            OS_Sleep(10);
            if (GetTickCount() >= atermset_data.gAtermApTimeout)
                break;
            if (atermset_bss.bAtermApCanceled)
                break;
            while ((nfound = AtermApc_GetEvent()) != 0) {
                switch (nfound) {
                case 4:
                case 8:
                case 18:
                    break;
                case 19:
                    loop_flag = 0;
                    break;
                case 5:
                    nfound = CopyApList(atermset_bss.ap_list, atermset_bss.gMaxApList);
                    if (nfound > ap_count) {
                        ap_count = nfound;
                        OS_CancelAlarm(&alarm);
                        OS_SetAlarm(&alarm, 0xFFB10, alarmCallback, (void *)0x13);
                    }
                    break;
                case 10:
                    loop_flag = 0;
                    break;
                case 1:
                case 2:
                case 3:
                case 6:
                case 7:
                case 9:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                default:
                    loop_flag = 0;
                    break;
                }
            }
        }
        OS_CancelAlarm(&alarm);
        while (AtermApc_GetEvent() != 0)
            ;
        if (atermset_bss.bAtermApCanceled)
            break;
        n = 0;
        if (ap_count >= atermset_bss.gMaxApList) {
            retv = -6;
            goto end;
        }
        for (i = 0, wmbssdesc = atermset_bss.ap_list; i < ap_count; i++, wmbssdesc++) {
            memcpy(pBssList->Bssid[n].Ssid.Ssid, wmbssdesc->ssid, 32);
            pBssList->Bssid[n].Ssid.SsidLength = wmbssdesc->ssidLength;
            pBssList->Bssid[n].Ssid.Ssid[wmbssdesc->ssidLength] = 0;
            pBssList->Bssid[n].Privacy = (wmbssdesc->capaInfo & 0x10) ? 1 : 0;
            memcpy(pBssList->Bssid[n].MacAddress, wmbssdesc->bssid, 6);
            n++;
        }
        pBssList->NumberOfItems = ap_count;
        if (atermset_bss.gAtermApState != 1 && CheckAccessPoint(pBssList, pOldList, &ApNo)) {
            pBssid = &pBssList->Bssid[ApNo];
            atermset_bss.gAPId = ApNo;
            strcpy((char *)gAPSSID, (char *)pBssid->Ssid.Ssid);
            memcpy(gAPMac, pBssid->MacAddress, 6);
            PutMac(apBSSID, (char *)gAPMac);
            break;
        }
        memcpy(pOldList, pBssList, BssListSize);
        atermset_bss.gAtermApState = 2;
        SendNotify();
    }
    if (retry >= 30 || GetTickCount() > atermset_data.gAtermApTimeout)
        retv = -3;
    else if (atermset_bss.bAtermApCanceled)
        retv = -8;
    else
        retv = 1;
end:
    if (pBssList)
        Free(pBssList);
    if (pOldList)
        Free(pOldList);
    return retv;
}

static int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata)
{
    int ret;

    ret = SOC_SendTo(sock, lpdata, cbdata, 0, target);
    if (ret < 0)
        return -4;
    return ret;
}

static int SendBroadcast(int sock, unsigned char *lpb, int size)
{
    int retv;
    SOCSockAddrIn target;
    unsigned char ipaddr[4];

    target.len = sizeof(target);
    target.family = 2;
    target.addr = 0xFFFFFFFF;
    target.port = 0x1E6;
    SOC_U32to4U8(SOCL_GetHostID(), ipaddr);
    retv = SendFrameViaInterface(sock, &target, ipaddr, lpb, size);
    return retv;
}

static int SendFrame(int sock, void *target, unsigned char *lpb, int size)
{
    return SendBroadcast(sock, lpb, size);
}

static unsigned char *GetFrameData(unsigned char *lpframe, int *pid, int *psize)
{
    FRAMEHEADER *pfh;
    unsigned short *psum;
    unsigned long dwsum;
    unsigned char *lps;

    pfh = (FRAMEHEADER *)lpframe;
    dwsum = 0;
    *pid = SWAP16(pfh->FrameID);
    *psize = SWAP16(pfh->DataLength);
    psum = (unsigned short *)(lpframe + sizeof(FRAMEHEADER) + *psize);
    for (lps = lpframe; lps < (unsigned char *)psum; lps++)
        dwsum += *lps;
    if ((unsigned short)dwsum != SWAP16(*psum))
        return 0;
    return lpframe + sizeof(FRAMEHEADER);
}

static unsigned char *GetElementData(unsigned char **lplpb, unsigned char *lplimit, int *pid, int *psize)
{
    unsigned char *lpb;
    ELEMENTINFO *pele;

    lpb = *lplpb;
    if (lpb >= lplimit)
        return 0;
    pele = (ELEMENTINFO *)lpb;
    *pid = SWAP16(pele->ElementID);
    *psize = SWAP16(pele->ElementLength);
    lpb += sizeof(ELEMENTINFO);
    *lplpb = lpb + (((*psize + 11) & ~7) - 4);
    return lpb;
}

static unsigned char *GetFirstElement(unsigned char *lpelement, int *pid, int *psize)
{
    unsigned char *lpb;

    lpb = lpelement + 8;
    return GetElementData(&lpb, lpb + SWAP16(((ELEMENTHEADER *)lpelement)->FullLength), pid, psize);
}

/*
 * sdk:      SetFrameData (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * 2026-10-01 (w4 restart): EXACT. Closed from the Debug/Release libdwcutil
 * atermset.o (-O0): its DWARF homes size and lpb in registers (`register`)
 * and shows the real statements: lpb = lpframe at its declaration,
 * `lpb += sizeof(FRAMEHEADER); lpb += size; psum = (u16 *)lpb;` after the
 * header stores, and the return as `lpb += 2; return lpb - lpframe;`.
 * Earlier lanes computed psum from lpb + size directly and lost the copy.
 */
static int SetFrameData(unsigned char *lpframe, int id, unsigned char *pbody, register int size, const unsigned char *lpkey)
{
    FRAMEHEADER *pfh = (FRAMEHEADER *)lpframe;
    ELEMENTHEADER *peh = (ELEMENTHEADER *)pbody;
    register unsigned char *lpb = lpframe;
    unsigned char *lps;
    unsigned short *psum;
    unsigned long dwsum = 0;

    memset(peh, 0, sizeof(ELEMENTHEADER));
    peh->FullLength = SWAP16((unsigned short)(size - sizeof(ELEMENTHEADER)));
    if (lpkey) {
        keywrap_encrypt((char *)(lpframe + sizeof(FRAMEHEADER)), (char *)pbody, size, (char *)lpkey, 16);
        size += 8;
    } else {
        memcpy(lpframe + sizeof(FRAMEHEADER), pbody, size);
    }
    memset(pfh, 0, sizeof(FRAMEHEADER));
    pfh->FrameID = SWAP16((unsigned short)id);
    pfh->DataLength = SWAP16((unsigned short)size);
    lpb += sizeof(FRAMEHEADER);
    lpb += size;
    psum = (unsigned short *)lpb;
    for (lps = lpframe; lps < (unsigned char *)psum; lps++)
        dwsum += *lps;
    *psum = SWAP16((unsigned short)dwsum);
    lpb += sizeof(unsigned short);
    return lpb - lpframe;
}

static unsigned char *SetElementData(unsigned char *lpb, int eid, unsigned char *pele, int esize)
{
    ELEMENTINFO *pei;
    int size;

    pei = (ELEMENTINFO *)lpb;
    lpb[0] = 0;
    lpb[1] = 0;
    lpb[2] = 0;
    lpb[3] = 0;
    pei->ElementID = SWAP16((unsigned short)eid);
    size = ((esize + 11) & ~7) - 4;
    pei->ElementLength = SWAP16((unsigned short)esize);
    lpb = (unsigned char *)(pei + 1);
    memset(lpb, 0, size);
    memcpy(lpb, pele, esize);
    return lpb + size;
}

static int SetSingleElement(unsigned char *lpbuff, int eid, unsigned char *pele, int esize)
{
    ELEMENTHEADER *peh;
    unsigned char *lpb;

    peh = (ELEMENTHEADER *)lpbuff;
    lpbuff[0] = 0;
    lpbuff[1] = 0;
    lpbuff[2] = 0;
    lpbuff[3] = 0;
    lpbuff[4] = 0;
    lpbuff[5] = 0;
    lpbuff[6] = 0;
    lpbuff[7] = 0;
    lpb = SetElementData(lpbuff + 8, eid, pele, esize);
    peh->FullLength = (lpb - lpbuff) - 8;
    return lpb - lpbuff;
}

static int IsSearchCommand(unsigned char *lpframe, int *pdual)
{
    int id;
    int size;
    int eid;
    int esize;
    unsigned char *lpb;
    unsigned char *lplimit;
    int iMajor;
    int iMinor;
    int iSP;

    lpb = GetFrameData(lpframe, &id, &size);
    iMajor = 0;
    iMinor = 0;
    iSP = 0;
    if (lpb == 0)
        return 0;
    if (id != 1)
        return 0;
    lplimit = lpb + size;
    lpb += 8;
    while ((lpframe = GetElementData(&lpb, lplimit, &eid, &esize)) != 0) {
        switch (eid) {
        case 1:
            iMajor = SWAP16(*(unsigned short *)lpframe);
            break;
        case 2:
            iMinor = SWAP16(*(unsigned short *)lpframe);
            break;
        case 5:
            iSP = SWAP16(*(unsigned short *)lpframe);
            break;
        }
    }
    if (iMajor != 1 || iMinor != 1)
        return 0;
    if (iSP >= 1)
        *pdual = 1;
    else
        *pdual = 0;
    return 1;
}

static int GetCommandElement(unsigned char *lpframe, int cmdid, unsigned char *lpelement, unsigned char *lpkey)
{
    int id;
    int size;
    unsigned char *lpb;

    lpb = GetFrameData(lpframe, &id, &size);
    if (lpb == 0)
        return 0;
    if (id != cmdid)
        return 0;
    if (lpkey != 0) {
        keywrap_decrypt((char *)lpelement, (char *)lpb, size, (char *)lpkey, 16);
        size -= 8;
    } else {
        memcpy(lpelement, lpb, size);
    }
    return size;
}

static int SetSearchRes(unsigned char *lpframe)
{
    unsigned char *lpb;
    unsigned short wd;
    SUPPORTENC SupportEnc;

    wd = 0x100;
    SupportEnc = atermset_rodata;
    lpb = SetElementData(atermset_data.lpElementData, 1, (unsigned char *)&wd, 2);
    lpb = SetElementData(lpb, 2, (unsigned char *)&wd, 2);
    if (atermset_bss.bDualCfg)
        lpb = SetElementData(lpb, 5, (unsigned char *)&wd, 2);
    lpb = SetElementData(lpb, 3, SupportEnc.b, 7);
    if (atermset_bss.bDualCfg)
        lpb = SetElementData(lpb, 4, btAdapterMAC, 6);
    return SetFrameData(lpframe, 2, ElementData, (lpb - atermset_data.lpElementData) + 8, 0);
}

static int GetOwnMacAddress(unsigned char *mac)
{
    OS_GetMacAddress(mac);
    return 1;
}

/*
 * sdk:      GetMacEncKey (libdwcutil.TWL.HYB.a(atermset.o))
 */
static int GetMacEncKey(lpkey)
    unsigned char *lpkey;
{
    char strmac[32];
    char strap[32];
    unsigned char ap_mac[6];
    unsigned char sta_mac[6];
    int ret;

    memcpy(lpkey + 12, sAtermsetTable2, 4);
    memcpy(ap_mac, gAPMac, 6);
    ap_mac[0] &= 0xfd;
    GetOwnMacAddress(sta_mac);
    memcpy(btAdapterMAC, sta_mac, 6);
    ret = memcmp(ap_mac, sta_mac, 6);
    if (ret <= 0) {
        memcpy(lpkey, sta_mac, 6);
        memcpy(lpkey + 6, ap_mac, 6);
    } else {
        memcpy(lpkey, ap_mac, 6);
        memcpy(lpkey + 6, sta_mac, 6);
    }
    if (atermset_data.bDebug) {
        PutMac(strmac, (char *)sta_mac);
        PutMac(strap, (char *)ap_mac);
    }
    return 1;
}

static int GetWLanSetElement(u8 *lpelement)
{
    int retv;
    u8 *lpb;
    u8 *lpw;
    int eid;
    int esize;
    int i;
    u16 len;
    u8 *lpe;
    char *wp;

    lpe = lpelement;
    lpe += 8;
    lpb = lpe;
    retv = 0;
    len = SWAP16(*(u16 *)lpelement);
    while ((lpw = GetElementData(&lpb, lpe + len, &eid, &esize)) != 0) {
        switch (eid) {
        case 0x201:
            __builtin__clear(gAtermsetBlock4.Ssid, 32);
            memcpy(gAtermsetBlock4.Ssid, lpw, esize);
            retv = 1;
            break;
        case 0x202:
            gAtermsetBlock6.type = SWAP16(*(u16 *)lpw);
            break;
        case 0x203:
            {
                u16 v = SWAP16(*(u16 *)lpw);
                for (i = 0; i < 4; i++)
                    gAtermsetBlock4.EncryptData.wep[i].keyType = v;
            }
            break;
        case 0x204:
            {
                u16 v = SWAP16(*(u16 *)lpw);
                for (i = 0; i < 4; i++)
                    gAtermsetBlock4.EncryptData.wep[i].keyLen = v;
            }
            break;
        case 0x205:
            gAtermsetBlock6.defkey = SWAP16(*(u16 *)lpw);
            break;
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x209:
            memset(gAtermsetBlock4.EncryptData.wep[eid - 0x206].key, 0, 32);
            if (gAtermsetBlock6.wep[0].keyType == 1) {
                wp = gAtermsetBlock4.EncryptData.wep[eid - 0x206].key;
                for (i = 0; i < esize; i++)
                    wp += PutHex(wp, *(char *)lpw++);
            } else {
                memcpy(gAtermsetBlock4.EncryptData.wep[eid - 0x206].key, lpw, esize);
            }
            break;
        case 0x20a:
            __builtin__clear(gAtermsetBlock4.EncryptData.wpakey, 72);
            memcpy(gAtermsetBlock4.EncryptData.wpakey, lpw, esize);
            break;
        }
    }
    return retv;
}

static int AsciiToHex(unsigned char *byDest, char *szStr, int nLen)
{
    int ch;
    int b;
    int i;

    b = 0;
    for (i = 0; i < nLen; i++) {
        ch = szStr[i];
        switch (ch) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            b += ch - '0';
            break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            b += ch - 'a' + 10;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            b += ch - 'A' + 10;
            break;
        default:
            return 0;
        }
        if (i % 2 == 0) {
            b <<= 4;
        } else {
            byDest[i / 2] = b;
            b = 0;
        }
    }
    return 1;
}

static int StoreNetParam(void)
{
    char szwep[36];
    int i;
    int defkey;
    char *lpwep;
    int ret;

    ret = 1;
    strcpy(gAtermsetBlock2.ssid, gAtermsetBlock4.Ssid);
    switch (gAtermsetBlock6.type) {
    case 0:
        gAtermsetBlock3.auth_mode = 0;
        break;
    case 1:
        defkey = gAtermsetBlock6.defkey;
        if (defkey == 0) {
            ret = -7;
            break;
        }
        gAtermsetBlock3.wepkeyid = defkey;
        for (i = 0; i < 4; i++) {
            lpwep = szwep;
            memcpy(szwep, gAtermsetBlock4.EncryptData.wep[i].key, 32);
            szwep[32] = 0;
            switch (strlen(szwep)) {
            case 0:
                break;
            case 5:
                gAtermsetBlock3.auth_mode = 1;
                memcpy(gAtermsetBlock2.wepkey[i], lpwep, 5);
                break;
            case 10:
                gAtermsetBlock3.auth_mode = 1;
                AsciiToHex((unsigned char *)gAtermsetBlock2.wepkey[i], lpwep, 10);
                break;
            case 13:
                gAtermsetBlock3.auth_mode = 2;
                memcpy(gAtermsetBlock2.wepkey[i], lpwep, 13);
                break;
            case 26:
                gAtermsetBlock3.auth_mode = 2;
                AsciiToHex((unsigned char *)gAtermsetBlock2.wepkey[i], lpwep, 26);
                break;
            case 16:
                gAtermsetBlock3.auth_mode = 3;
                memcpy(gAtermsetBlock2.wepkey[i], lpwep, 16);
                break;
            case 32:
                gAtermsetBlock3.auth_mode = 3;
                AsciiToHex((unsigned char *)gAtermsetBlock2.wepkey[i], lpwep, 32);
                break;
            default:
                ret = -7;
                break;
            }
        }
        break;
    case 2:
        gAtermsetBlock3.auth_mode = 4;
        memcpy(gAtermsetBlock2.wpakey, gAtermsetBlock4.EncryptData.wpakey, 64);
        break;
    case 3:
        gAtermsetBlock3.auth_mode = 5;
        memcpy(gAtermsetBlock2.wpakey, gAtermsetBlock4.EncryptData.wpakey, 64);
        break;
    default:
        ret = -7;
        break;
    }
    return ret;
}

/* OS_Printf compiles to nothing in the Rom (FINALROM) build. */
#define OS_Printf(fmt, arg) ((void)0)

static int AutoConfigThreadEx(void)
{
    int sock = 0;
    int ret;
    struct SOCSockAddrIn server;
    struct SOCSockAddrIn target;
    int n;
    unsigned long dwSendTick;
    u8 *lpe;
    int eid;
    int esize;
    int iretry;
    int bfinish;
    unsigned long dw;
    int state;

    ret = -5;
    dwSendTick = 0;
    iretry = 0;
    bfinish = 0;
    atermset_bss.AutoPhase = 1;

    while (!bfinish && atermset_bss.bAtermApCanceled == 0) {
        OS_Sleep(500);
        switch (atermset_bss.AutoPhase) {
        case 1:
            ret = ScanAP();
            if (ret != 1) {
                bfinish = 1;
                break;
            }
            atermset_bss.gAtermApState = 3;
            SendNotify();
            atermset_bss.AutoPhase = 2;
            break;
        case 2:
            ret = ConnectAP();
            if (ret != 1) {
                bfinish = 1;
                break;
            }
            atermset_bss.AutoPhase = 3;
            break;
        case 3:
            sock = SOC_Socket(2, 2, 0);
            if (sock < 0) {
                ret = -2;
                bfinish = 1;
                break;
            }
            __builtin__clear(&server, sizeof(server));
            server.len = sizeof(server);
            server.family = 2;
            server.port = 486;
            server.addr = 0;
            ret = SOC_Bind(sock, &server);
            if (ret < 0) {
                ret = -2;
                bfinish = 1;
                break;
            }
            atermset_bss.AutoPhase = 4;
            break;
        case 4:
            if (GetTickCount() >= atermset_data.gAtermApTimeout) {
                SOC_Close(sock);
                ret = -3;
                bfinish = 1;
                break;
            }
            target.len = sizeof(target);
            GetMacEncKey(gAtermsetBlock7, &target);
            n = SOC_RecvFrom((int)sock, gAtermsetBlock10, 0x800, 4, (unsigned char *)(&target));
            if (n > 0) {
                if (IsSearchCommand(gAtermsetBlock10, &gAtermsetBlock1)) {
                    atermset_data.gAtermApTimeout = GetTickCount() + 30000;
                    atermset_bss.AutoPhase = 5;
                    atermset_bss.gAtermApState = 4;
                    SendNotify();
                    break;
                }
            }
            break;
        case 5:
            atermset_bss.cbFrameData = SetSearchRes(gAtermsetBlock10);
            SendFrame(sock, &target, gAtermsetBlock10, atermset_bss.cbFrameData);
            dwSendTick = GetTickCount();
            atermset_bss.AutoPhase = 6;
            break;
        case 6:
            if (GetTickCount() >= atermset_data.gAtermApTimeout) {
                SOC_Close(sock);
                ret = -4;
                bfinish = 1;
                break;
            }
            n = SOC_RecvFrom((int)sock, gAtermsetBlock10, 0x800, 4, (unsigned char *)(&target));
            if (n > 0) {
                if (GetCommandElement(gAtermsetBlock10, 3, ElementData, gAtermsetBlock7)) {
                    lpe = GetFirstElement(ElementData, &eid, &esize);
                    if (eid == 257) {
                        dw = GetTickCount();
                        memcpy(gAtermsetBlock8, lpe, 8);
                        MD5Encode(gAtermsetBlock9, (u8 *)&dw, 4);
                        iretry = 0;
                        atermset_bss.AutoPhase = 7;
                        atermset_bss.gAtermApState = 5;
                        atermset_data.gAtermApTimeout = -1;
                        SendNotify();
                    } else {
                        if (atermset_data.bDebug)
                            OS_Printf("eid %d\n", eid);
                    }
                    break;
                }
            }
            if (GetTickCount() >= dwSendTick + 1000) {
                atermset_bss.AutoPhase = 5;
            }
            break;
        case 7:
            atermset_bss.cbElementData = SetSingleElement(ElementData, 258, gAtermsetBlock9, 8);
            atermset_bss.cbFrameData = SetFrameData(gAtermsetBlock10, 4, ElementData, atermset_bss.cbElementData, gAtermsetBlock7);
            SendFrame(sock, &target, gAtermsetBlock10, atermset_bss.cbFrameData);
            dwSendTick = GetTickCount();
            __builtin__clear(&gAtermsetBlock4, sizeof(gAtermsetBlock4));
            atermset_bss.AutoPhase = 8;
            break;
        case 8:
            if (SOC_RecvFrom((int)sock, gAtermsetBlock10, 0x800, 4, (unsigned char *)(&target)) > 0
                && (atermset_bss.cbElementData = GetCommandElement(gAtermsetBlock10, 5, ElementData, gAtermsetBlock8)) != 0
                && GetWLanSetElement(ElementData)) {
                if (gAtermsetBlock5[0x14] != 0)
                    atermset_bss.btAutoResult = 1;
                else
                    atermset_bss.btAutoResult = 0;
                iretry = 0;
                atermset_bss.AutoPhase = 9;
                break;
            }
            if (GetTickCount() < dwSendTick + 1000)
                break;
            if (++iretry >= 10) {
                SOC_Close(sock);
                ret = -2;
                bfinish = 1;
                break;
            }
            atermset_bss.AutoPhase = 7;
            break;
        case 9:
            atermset_bss.cbElementData = SetSingleElement(ElementData, 769, &sAtermsetBtAutoResult, 1);
            atermset_bss.cbFrameData = SetFrameData(gAtermsetBlock10, 6, ElementData, atermset_bss.cbElementData, gAtermsetBlock8);
            state = APC_GetState();
            if (state != 7) {
                dwSendTick = GetTickCount() + 1000;
                iretry = 10;
                atermset_bss.AutoPhase = 10;
                break;
            }
            SendFrame(sock, &target, gAtermsetBlock10, atermset_bss.cbFrameData);
            dwSendTick = GetTickCount();
            atermset_bss.AutoPhase = 10;
            break;
        case 10:
            if (GetTickCount() < dwSendTick + 1000)
                break;
            if (++iretry >= 10) {
                bfinish = 1;
                ret = StoreNetParam();
                break;
            }
            atermset_bss.AutoPhase = 9;
            break;
        }
    }
    if (sock != 0)
        SOC_Close(sock);
    if (atermset_bss.bAtermApCanceled != 0)
        ret = -8;
    return ret;
}

static void AutoConfigThread(void *arg)
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
static int keywrap_encrypt(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen)
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
    rounds = rijndaelKeySetupEnc(aes_rk, (unsigned char *)keyptr, keylen * 8);
    memcpy(dest + 8, src, buflen);
    memcpy(aes_data, &iv, 8);
    for (j = 0; j < 6; j++) {
        for (i = 1; i <= n; i++) {
            memcpy(aes_data + 8, dest + i * sizeof(iv), 8);
            rijndaelEncrypt(aes_rk, rounds, aes_data, aes_data);
            xort = KW_BSWAP64((unsigned long long)n * j + i);
            aeskw_xor64(aes_data, (unsigned char *)&xort, aes_data);
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
static int keywrap_decrypt(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen)
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
    rounds = rijndaelKeySetupDec(aes_rk, (unsigned char *)keyptr, keylen * 8);
    memcpy(aes_data, src, 8);
    src += 8;
    memcpy(dest, src, buflen - 1);
    for (j = 5; j >= 0; j--) {
        for (i = n; i > 0; i--) {
            xort = KW_BSWAP64((unsigned long long)n * j + i);
            aeskw_xor64(aes_data, (unsigned char *)&xort, aes_data);
            memcpy(aes_data + 8, dest + (i - 1) * sizeof(iv), 8);
            rijndaelDecrypt(aes_rk, rounds, aes_data, aes_data);
            memcpy(dest + (i - 1) * sizeof(iv), aes_data + 8, 8);
        }
    }
    if (memcmp(&iv, aes_data, 8))
        status = 0;
    return status;
}

static void aeskw_xor64(unsigned char *srcA, unsigned char *srcB, unsigned char *dst)
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

static int rijndaelKeySetupEnc(u32 *rk, u8 *cipherKey, int keyBits)
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

static int rijndaelKeySetupDec(u32 *rk, u8 *cipherKey, int keyBits)
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

static void rijndaelEncrypt(u32 *rk, int Nr, u8 *pt, u8 *ct)
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

static void rijndaelDecrypt(u32 *rk, int Nr, u8 *ct, u8 *pt)
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

static void MY_MD5Init(MY_MD5_CTX *context)
{
    context->count[0] = context->count[1] = 0;
    context->state[0] = 0x67452301;
    context->state[1] = 0xefcdab89;
    context->state[2] = 0x98badcfe;
    context->state[3] = 0x10325476;
}

static void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen)
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

static void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context)
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

static void MD5Transform(UINT4 state[4], unsigned char block[64])
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

static void Encode(unsigned char *output, UINT4 *input, unsigned int len)
{
    unsigned int i, j;

    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = (unsigned char)(input[i] & 0xff);
        output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
        output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
        output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
    }
}

static void Decode(UINT4 *dst, unsigned char *src, unsigned int count)
{
    unsigned int i = 0;
    while (i < count) {
        unsigned int b0 = src[i];
        unsigned int b1 = src[i + 1];
        unsigned int b2 = src[i + 2];
        unsigned int b3 = src[i + 3];
        *dst++ = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
        i += 4;
    }
}

static void MD5_memcpy(unsigned char *output, unsigned char *input, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++)
        output[i] = input[i];
}

static void MD5_memset(unsigned char *output, int value, unsigned int len)
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

static unsigned long GetTickCount(void)
{
    return (unsigned long)((OS_GetTick() * 64) / 0x82EA);
}

static void *Calloc(unsigned long a, unsigned long b)
{
    unsigned long n = a * b;
    void *p = atermset_bss.gAtermAlloc(n);

    if (p)
        memset(p, 0, n);
    return p;
}

static void Free(void *ptr)
{
    atermset_bss.gAtermFree(ptr);
}

static int PutHex(char *lpwrite, char ch)
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

static int PutMac(char *lpwrite, char *lps)
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

int DWCi_RakurakuATERMi_ApConfigStart(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize)
{
    int ret;

    if (atermset_bss.gAtermApState >= 1 && atermset_bss.gAtermApState <= 5)
        return -10;
    *(volatile int *)&atermset_data.gMaxBssIdList = maxap;
    *(volatile int *)&atermset_bss.gAtermApState = 7;
    *(volatile void **)&atermset_bss.gAtermNotify = (void *)notify;
    *(volatile void **)&atermset_bss.gAtermAlloc = (void *)alloc;
    *(volatile void **)&atermset_bss.gAtermFree = (void *)free;
    *(volatile unsigned long *)&atermset_data.gThreadStackSize = stackSize;
    ret = InitAtermApcNetwork(maxap);
    atermset_bss.bInitAtermApNetwork = 1;
    if (ret < 0) {
        atermset_bss.gAtermApResult = ret;
        return ret;
    }
    atermset_bss.gThreadStack = (unsigned long long *)atermset_bss.gAtermAlloc(atermset_data.gThreadStackSize);
    if (atermset_bss.gThreadStack == 0) {
        atermset_bss.gAtermApResult = -1;
        return -1;
    }
    if (OS_IsThreadAvailable() != 1) {
        atermset_bss.gAtermApResult = -9;
        return -9;
    }
    OS_CreateThread(&gAtermThread, AutoConfigThread, 0, (unsigned char *)atermset_bss.gThreadStack + (atermset_data.gThreadStackSize & ~7), atermset_data.gThreadStackSize, prio);
    atermset_bss.gAtermApState = 1;
    atermset_data.gAtermApTimeout = GetTickCount() + 60000;
    atermset_bss.bAtermApCanceled = 0;
    memset(&gAtermsetBlock2, 0, 232);
    SendNotify();
    OS_WakeupThreadDirect(&gAtermThread);
    atermset_bss.gAtermThreadId = 1;
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

int DWCi_RakurakuATERMi_ApConfigGetResult(void *a)
{
    memcpy(a, &gAtermsetBlock2, 0xe8);
    return 1;
}

static void SendNotify(void)
{
    ATERMApConfigState state;

    ATERMi_ApConfigGetState(&state);
    atermset_bss.gAtermNotify(&state);
}
