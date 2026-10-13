/*
 * file:     aoss.c
 * unit:     yes
 * function: AOSS_MALLOC, AOSS_FREE, AOSSi_Init, AOSS_Init_old, DWCi_AossAoss_IP_sta, aoss_release, aoss_data_init, func_021B6D74, func_021B6D80, AOSS_seq_data_copy, DWCi_AossAoss_check_str, DWCi_AossCheckAP, AOSS_set_APInfo, DWCi_AossMakeSendSeqID, AOSS_StatusExclusion, DWCi_AossRecvMessage, DWCi_AossAstsSetInitRes, DWCi_AossAstsSetSecureRes, DWCi_AossAstsRestartRes, DWCi_AossDecodePacket, DWCi_AossCheckSeqID, DWCi_AossCheckRecvSeqID, DWCi_AossGetProductInfo, DWCi_AossAoss_get_bin, DWCi_AossGetWEPData, DWCi_AossGetWPAData, GetBssidData, GetSecurityData, GetSecurityType, DWCi_AossSendMessage, DWCi_AossAstsSetInitReq, DWCi_AossAstsSetSecureReq, DWCi_AossAstsRestartReq, DWCi_AossSetStaData, DWCi_AossPacketDataSet, DWCi_AossSetPacketHeader, DWCi_AossSendPacketUDP, DWCi_AossEncodeRC4, DWCi_AossDecodeRC4, DWCi_AossRC4init, DWCi_AossRC4encrypt, DWCi_AossArcfour_byte, DWCi_AossCrc, DWCi_AossUpdate_crc, DWCi_AossMake_crc_table, DWCi_AossCryptSeqNo, DWCi_AossMakeKey, DWCi_AossAddKey, DWCi_AossRotate, Alloc, Free, AOSS_SetIPAddr, AOSS_Disconnect, AOSS_Memcmp, AOSS_Memcpy, AOSS_Memset, AOSS_Recvfrom, AOSS_Select, AOSS_Sendto, AOSS_Setsockopt, AOSS_Socket, AOSS_Bind, AOSS_Close, AOSS_Htonl, AOSS_Htons, AOSS_Ntohl, AOSS_Ntohs, AOSS_Strlen, AOSS_Rand, AOSS_FD_ZERO, AOSS_FD_SET
 * address:  0x021B61B0
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_Memset (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8240.c \
 *       --func AOSS_Memset --addr 0x021B8240 --region ov016 --cc ../2.0/sp1p2 --thumb
 *
 * symbols:
 *   aoss_bss              0x021DC040  data
 *   aoss_data             0x021DAAB4  data
 *   AOSSi_Alloc           0x021DCE20  data
 *   AOSSi_Free            0x021DCE2C  data
 *   AOSS_MALLOC           0x021B61B0  thumb
 *   AOSS_FREE             0x021B61C0  thumb
 *   AOSSi_Sleep           0x021B89C0  thumb
 *   AOSSi_WLANConnect     0x021B87F0  thumb
 *   AOSSi_WLANGetBSSList  0x021B8678  thumb
 *   _s32_div_f            0x0209C0A4  arm
 *   aoss_rodata           0x021D77C4  data
 *   gSeqID       0x021DCDA0  data
 *   SecurityInfo    0x021DC700  data
 *   AOSS_Memcpy     0x021B8230  thumb
 *   AOSS_Strlen     0x021B8364  thumb
 *   aoss_str_10367  0x021DAB14  data
 *   aoss_str_10375  0x021DAB20  data
 *   AOSSi_Status  0x021B89C8  thumb
 *   GetSecurityType  0x021B796C  thumb
 *   AttrNo        0x021DAAB0  data
 *   AOSS_Sendto  0x021B82B4  thumb
 *   TANE         0x021DCDA8  data
 *   _u32_div_f  0x0209C2B0  arm
 *   CPSMyIp      0x021A82BC  data
 *   SOC_Startup  0x0215F8FC  arm
 *   OS_Sleep     0x02085A38  arm
 *   SOC_Cleanup       0x0215FA90  arm
 *   AOSSi_Disconnect  0x021B8640  thumb
 *   MI_CpuCopy8   0x02082D44  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm
 *   _ull_mul  0x0209C054  arm
 *   SOC_Poll  0x0215FBCC  arm
 *   SOC_Close  0x0215F644  arm  ov009
 *   RTC_GetTime  0x0208890C  arm
 */
#define NULL ((void *)0)
#define FAIL(code)                      \
    do {                                \
        aossInfo->aossResult = (code);  \
        aoss_release();                 \
        return -1;                      \
    } while (0)
extern void *(*AOSSi_Alloc)(unsigned long size);
extern void (*AOSSi_Free)(void *ptr);

/*
 * aoss.o's main .bss section (3424 bytes at 0x021DC040). The vendor object
 * addresses these statics section-relative (one pool word for the section
 * base plus a field offset), so they are declared here as one object laid
 * out in the object's own order; member names are the vendor statics.
 */
typedef struct {
    unsigned char *p_name;
    unsigned int   p_name_len;
    unsigned int   sLevel;
    unsigned int   aLevel;
    unsigned int   apAddr;
    unsigned int   apMask;
    char           ip_chg;
    char           p_type;
} _AOSS_INFO;

typedef struct {
    unsigned long x;
    unsigned long mul;
    unsigned long add;
} MATHRandContext16;

typedef struct AOSS_BSS {
    int            SecurityType;    /* +0x000 */
    struct wlla_bss_list *bssList;  /* +0x004 */
    int            initflg;         /* +0x008 */
    struct wlla_link_stat *linkInfo; /* +0x00C */
    unsigned int   gError;          /* +0x010 */
    void          *s_buf;           /* +0x014 */
    MATHRandContext16 randContext;  /* +0x018 */
    _AOSS_INFO     gData;           /* +0x024 */
    unsigned char  ProductInfo[0x280];   /* +0x040 PRODUCT_INFO_AOSS */
    unsigned long  crc_table[256];       /* +0x2C0 */
    unsigned char  SecurityInfo[0x6A0];  /* +0x6C0 ASTS_DATA_INFO[2] */
} AOSS_BSS;

typedef struct {
    unsigned char  pad00[0x10];
    unsigned long  addr;       /* +0x10 */
    unsigned long  netmask;    /* +0x14 */
    unsigned long  router;     /* +0x18 */
    unsigned char  pad1C[0x58 - 0x1C];
} SOCConfig;

typedef struct {
    int       s_sFd;
    int       before;
    SOCConfig soconfig;
} AOSS_DATA_SECTION;

typedef struct product_info {
    unsigned char  dataType;
    unsigned short dataLen;
    unsigned char  productName[256];
} PRODUCT_INFO;

typedef struct aoss_secure_info {
    unsigned char WEP40Key1[6];
    unsigned char WEP40Key2[6];
    unsigned char WEP40Key3[6];
    unsigned char WEP40Key4[6];
    unsigned char WEP40_SSID[33];
    unsigned char WEP104Key1[14];
    unsigned char WEP104Key2[14];
    unsigned char WEP104Key3[14];
    unsigned char WEP104Key4[14];
    unsigned char WEP104_SSID[33];
    unsigned char WPA_PSK_TKIP[64];
    unsigned char WPA_PSK_TKIP_SSID[33];
    unsigned char WPA_PSK_AES[64];
    unsigned char WPA_PSK_AES_SSID[33];
} AOSS_SECURE_INFO;

typedef struct aoss_info {
    unsigned short   supportSecurity;
    PRODUCT_INFO     productInfo;
    short            retryCount_Scan;
    short            retryInterval_Scan;
    short            retryCount_Comu;
    short            retryInterval_Comu;
    short            selectInterval;
    char             macAddress[6];
    unsigned char    aossResult;
    AOSS_SECURE_INFO secureInfo;
} AOSS_INFO;

typedef struct {
    char SendSeqID[8];
} SEQID_INFO;

typedef struct {
    unsigned short PktVersion;
    unsigned short PktID;
    unsigned short PktSubID;
    unsigned short cmd;
    unsigned short type;
    unsigned short size;
    unsigned short CryptType;
    unsigned char  crc8;
    unsigned char  Fragment;
    unsigned char  SeqID[8];
} tagASTSpktHeader;

typedef struct {
    unsigned char  SubAttrNo;
    unsigned char  SubAttrVer;
    unsigned short length;
} tagASTSsubAttrHeader;

struct UdpIpMsg {
    unsigned char udpipmsg[1500];
};

typedef struct recv_info {
    int            sockfd;
    int            recvlen;
    unsigned long  cli_ip;
    unsigned char  packet[1500];
    unsigned short port;
    unsigned char  IfHwAddress[8];
    unsigned long  MyIp_addr;
} RECV_INFO;

typedef struct {
    tagASTSsubAttrHeader hdr;
    unsigned long        Result;
} tagASTSpktResult;

typedef struct SEND_INFO {
    unsigned long  cli_ip;
    unsigned short port;
    unsigned char  IfHwAddress[8];
    unsigned long  MyIp_addr;
} SEND_INFO;

typedef struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
} WLLA_SSID;

typedef struct wlla_key {
    unsigned long Len;
    unsigned char Key[13];
} WLLA_KEY;

typedef struct wlla_connect_param {
    WLLA_SSID     Ssid;
    unsigned long AuthAlgo;
    WLLA_KEY      Key;
} WLLA_CONNECT_PARAM;

typedef struct wlla_rateset {
    unsigned long Num;
    unsigned char Rates[14];
} WLLA_RATESET;

typedef struct wlla_bss_info {
    WLLA_SSID     Ssid;
    unsigned long Channel;
    unsigned long Noise;
    unsigned long Signal;
    unsigned char Bssid[6];
    WLLA_RATESET  SupportRates;
    unsigned long BeaconPeriod;
    unsigned long Capability;
} WLLA_BSS_INFO;

typedef struct wlla_bss_list {
    unsigned long Num;
    WLLA_BSS_INFO BssInfo[1];
} WLLA_BSS_LIST;

typedef struct wlla_link_stat {
    unsigned long LinkStat;
    WLLA_BSS_INFO BssInfo;
} WLLA_LINK_STAT;

typedef struct {
    unsigned long addr;
} SOCInAddr;

typedef struct {
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    SOCInAddr      addr;
} SOCSockAddrIn;

typedef struct {
    int   fd;
    short events;
    short revents;
} SOCPollFD;

struct timeval {
    int tv_sec;
    int tv_usec;
};

struct _retry {
    short count;
    short time;
};

typedef struct {
    int  Enable;
    int  KeyLen;
    char SSID[40];
    char Data[4][64];
} ASTS_DATA_WEP;

typedef struct {
    int  Enable;
    int  KeyLen;
    char SSID[40];
    char Data[64];
} ASTS_DATA_TKIP;

typedef struct {
    int            ReNew;
    unsigned long  EncryptLevel;
    ASTS_DATA_WEP  WepData_40;
    ASTS_DATA_WEP  WepData_104;
    ASTS_DATA_TKIP TkipData;
    ASTS_DATA_TKIP AesData;
    char           BSSID[6];
} ASTS_DATA_INFO;

typedef struct {
    char ProductInfo[5][128];
} PRODUCT_INFO_AOSS;

typedef struct {
    tagASTSsubAttrHeader hdr;
    unsigned char        ProductData[1];
} tagASTSpktInitRes;

typedef struct {
    unsigned short size;
    unsigned char  iv[2];
    unsigned char  Data[1];
} tagASTSpktCryptData;

typedef struct {
    unsigned char  DataID;
    unsigned char  DataType;
    unsigned short length;
    unsigned short offset;
    unsigned char  Data[256];
} VariableData;

typedef struct {
    unsigned short size;
    unsigned char  WEP[1];
} tagWepData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagWepData           WEP;
} tagASTSpktWEP40;

typedef struct {
    unsigned short size;
    unsigned char  WpaPsk[1];
} tagWpaPskData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagWpaPskData        WpaPsk;
} tagASTSpktTKIP;

typedef struct {
    unsigned short size;
    unsigned char  Bssid[1];
} tagBssidData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagBssidData         Bssid;
} tagASTSpktBssid;

typedef struct {
    tagASTSsubAttrHeader info;
    unsigned char        StaData[1];
} tagASTSpktRequest;

typedef struct {
    tagASTSsubAttrHeader info;
    unsigned long        EncryptLevel;
} tagASTSpktCapability;

typedef struct {
    unsigned int   x;
    unsigned int   y;
    unsigned char *state;
    unsigned int   SizeOfState;
} ArcfourContext;

typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    unsigned long hour;
    unsigned long minute;
    unsigned long second;
} RTCTime;

void *AOSS_MALLOC(int size);
void AOSS_FREE(void *mem);
extern int AOSSi_WLANGetBSSList(WLLA_BSS_LIST **bssList);
extern void AOSSi_Sleep(int msec);
extern int AOSSi_WLANConnect(WLLA_CONNECT_PARAM *conParam, WLLA_LINK_STAT *linkStat);
void *AOSS_Memcpy(void *dest, void *src, int n);
int AOSS_Strlen(char *s);
extern int AOSSi_Status(int stat);
int AOSS_Sendto(int s, void *msg, int len, int flags, void *to, int tolen);
extern int SOC_Startup(SOCConfig *config);
extern void OS_Sleep(unsigned long msec);
extern int SOC_Cleanup(void);
extern int AOSSi_Disconnect(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int SOC_RecvFrom(int, void *, int, int, void *);
extern int SOC_Poll(SOCPollFD *fds, unsigned int nfds, unsigned long long timeout);
extern int SOC_SendTo(int, void *, int, int, void *);
extern int SOC_Socket(int domain, int type, int protocol);
extern int SOC_Bind(int s, void *addr, int addrlen);
extern int SOC_Close(int fd);
extern int RTC_GetTime(RTCTime *time);
int AOSSi_Init(struct aoss_info *aossInfo);
int AOSS_Init_old(struct aoss_info *aossInfo);
unsigned long aoss_IP_sta(unsigned long ipAp, unsigned long nMask);
void aoss_release(void);
void aoss_data_init(AOSS_INFO *aossInfo);
void aoss_set_error(unsigned int type);
unsigned int aoss_get_error(void);
int AOSS_seq_data_copy(struct aoss_info *aossInfo);
int aoss_check_str(char *ptr, int count);
int checkAP(WLLA_BSS_LIST *list);
int AOSS_set_APInfo(WLLA_CONNECT_PARAM *ap);
void MakeSendSeqID(int Cnt, SEQID_INFO *SeqID, char *Mymacaddr);
int AOSS_StatusExclusion(int stat);
int RecvMessage(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *SendSeqID, int sFd);
int AstsSetInitRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
int AstsSetSecureRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
int AstsRestartRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID);
int DecodePacket(unsigned char *tpkt);
int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID);
int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID);
int GetProductInfo(char *ProductData, PRODUCT_INFO_AOSS *ProductInfo);
unsigned long aoss_get_bin(void *ptr, int num);
int GetWEPData(tagASTSpktWEP40 *pWEP, ASTS_DATA_WEP *Info);
int GetWPAData(tagASTSpktTKIP *pWPA, ASTS_DATA_TKIP *Info);
int GetBssidData(tagASTSpktBssid *pBssid, char *BSSID);
int GetSecurityData(int Mode, unsigned char *pData, int Length, ASTS_DATA_INFO *SecurityInfo, PRODUCT_INFO_AOSS *Info);
int SendMessage(int SendReq, SEND_INFO *send_info, SEQID_INFO *SendSeqID, int sFd);
int AstsSetInitReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd);
int AstsSetSecureReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd);
int AstsRestartReq(void *send_info, SEQID_INFO *pSeqID, int sFd);
short SetStaData(char *StaData);
void PacketDataSet(int Type, unsigned char *pData, unsigned char *pPlaneData, short *packet_size, short *CryptType, unsigned char *crc8);
void SetPacketHeader(tagASTSpktHeader *Hdr, short cmd, short size, short CryptType, char crc8, char Fragment, unsigned char *SeqID);
int SendPacketUDP(unsigned char *packet, int size, unsigned char Mac, int port);
int EncodeRC4(unsigned char *srcData, unsigned char *EncodeData, int SizeOfData, unsigned char *CRC, unsigned char *iv, unsigned char *key, int keylen);
int DecodeRC4(unsigned char *srcData, unsigned char *DecodeData, int SizeOfData, unsigned char CRC, unsigned char *iv, unsigned char *key, int keylen);
void RC4init(ArcfourContext *ctx, unsigned char *key, unsigned int key_len, unsigned int size);
void RC4encrypt(ArcfourContext *ctx, unsigned char *dest, unsigned char *src, unsigned int len);
unsigned int arcfour_byte(ArcfourContext *ctx);
unsigned char crc(unsigned char *buf, int len);
unsigned long update_crc(unsigned long crc, unsigned char *buf, int len, int crc_table_computed, unsigned long *crc_table);
void make_crc_table(int crc_table_computed, unsigned long *crc_table);
int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
void MakeKey(int ID, char *Key, int maclen, char *Wep, int weplen);
void AddKey(char *Key, unsigned char *mac, int maclen);
void Rotate(unsigned char *mac, int maclen, char *wBuff);
int AOSS_SetIPAddr(unsigned long ip, unsigned long sm, unsigned long gw);
int AOSS_Disconnect(void);
int AOSS_Memcmp(void *s1, void *s2, int n);
void *AOSS_Memset(void *s, int c, int n);
int AOSS_Recvfrom(int s, void *buf, int len, int flags, void *from, int *fromlen);
int AOSS_Select(int nfds, SOCPollFD *readfds, void *writefds, void *exceptfds, struct timeval *timeout);
int AOSS_Setsockopt(int s, int level, int optname, void *optval, int optlen);
int AOSS_Socket(int domain, int type, int protocol);
int AOSS_Bind(int s, void *addr, int addrlen);
int AOSS_Close(int fd);
unsigned long AOSS_Htonl(unsigned long hostlong);
unsigned short AOSS_Htons(unsigned short hostshort);
unsigned long AOSS_Ntohl(unsigned long netlong);
unsigned short AOSS_Ntohs(unsigned short netshort);
int AOSS_Rand(void);
void AOSS_FD_ZERO(SOCPollFD *pollFd);
int AOSS_FD_SET(int fd, SOCPollFD *pollFd);
extern AOSS_BSS aoss_bss;
extern AOSS_DATA_SECTION aoss_data;
extern unsigned char gSeqID[8];
extern const struct _retry aoss_rodata;   /* aoss.o .rodata: the compiler's @8259, retry1's initialiser { -1, -1 } */
extern ASTS_DATA_INFO SecurityInfo[2];
extern char aoss_str_10367[];
extern char aoss_str_10375[];
extern unsigned char AttrNo[];
extern unsigned char TANE[100];
extern unsigned long CPSMyIp;


/*
 * FILED EXACT with NO region token on the data symbol.  The `ov016` hint is
 * contested at this address (another overlay mapped over the same window
 * starts an object there).  A contested hint is refused outright by the
 * overlay `sole-ref/data` sub-kind, and for `sole-ref/self` by
 * self_hint_accepted() unless the function itself loads ov016 through an
 * `overlay_id` site -- which this one does not.  Dropping the token leaves
 * the choice to _overlay_pool()'s site_region arm, the region this function
 * is compiled in: it returns the same single overlay, ov016, without taking
 * the refused hint path.  The site then attests `sole-ref/self` -- the ROM
 * word at the pool site already names 0x021DCE20, and 0x021DCE20 is data in exactly one
 * overlay of the pool.  See scratch/ov_ov016/o27/report.md.
 *
 * Forward the argument a to the handler in the global function pointer at 0x021DCE20.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_MALLOC.c \
 *       --func AOSS_MALLOC --addr 0x021B61B0 --region ov016 --cc dsi/1.1p1 --thumb
 */

static int GetSecurityType(unsigned int v);
static int Alloc(int a, int b);
static void Free(int a, int b);

void *AOSS_MALLOC(int size)
{
    return AOSSi_Alloc(size);
}


/*
 * Forward to the handler in the global function pointer at 0x021DCE2C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_FREE.c \
 *       --func AOSS_FREE --addr 0x021B61C0 --region ov016 --cc dsi/1.1p1 --thumb
 */
void AOSS_FREE(void *mem)
{
    AOSSi_Free(mem);
}


int AOSSi_Init(struct aoss_info *aossInfo)
{
    int ret;

    if (aossInfo->retryCount_Scan == 0 || aossInfo->retryCount_Scan < -1 ||
        aossInfo->retryInterval_Scan < -1 ||
        aossInfo->retryCount_Comu == 0 || aossInfo->retryCount_Comu < -1 ||
        aossInfo->retryInterval_Comu < -1 || aossInfo->selectInterval < -1 ||
        aossInfo->productInfo.dataLen == 0 || aossInfo->productInfo.dataLen > 256 ||
        aossInfo->productInfo.productName[aossInfo->productInfo.dataLen - 1] != 0)
        ret = -1;
    else
        ret = 0;
    if (AOSSi_Alloc == 0 || AOSSi_Free == 0)
        ret = -1;
    if (ret == -1) {
        aossInfo->aossResult = 0xF;
        aoss_release();
        return -1;
    }
    aoss_bss.s_buf = AOSS_MALLOC(0x5F8);
    if (aoss_bss.s_buf == 0) {
        aossInfo->aossResult = 0xF;
        aoss_release();
        return -1;
    }
    AOSS_StatusExclusion(-1);
    ret = AOSS_Init_old(aossInfo);
    AOSS_FREE(aoss_bss.s_buf);
    aoss_release();
    if (aoss_data.s_sFd != -1)
        AOSS_Close(aoss_data.s_sFd);
    return ret;
}


int AOSS_Init_old(struct aoss_info *aossInfo)
{
    struct _retry retry1 = aoss_rodata;
    struct _retry retry2 = { 0, 0 };
    short selectTime;
    int ret;
    int optV = 1;
    int Retry1;
    int SendReq = 0;
    int RetSendReq;
    int eRet;
    SOCSockAddrIn clientAddr;
    int sockAddrSize;
    SOCPollFD sockFd;
    struct timeval wait;
    short retry_counter;
    SEQID_INFO SendSeqID[3];
    int apList;
    WLLA_CONNECT_PARAM comAP;
    SOCSockAddrIn aoss_src_addr;
    unsigned long newIP;
    SEND_INFO send_info;
    RECV_INFO *recv_info;
    int ret_value;

    Retry1 = SendReq;
    newIP = SendReq;
    AOSS_Memset(SendSeqID, SendReq, sizeof(SendSeqID));

    retry1.count = aossInfo->retryCount_Scan;
    if (retry1.count == -1)
        retry1.count = 10;
    retry2.count = aossInfo->retryCount_Comu;
    if (retry2.count == -1)
        retry2.count = 10;
    retry1.time = aossInfo->retryInterval_Scan;
    if (retry1.time == -1)
        retry1.time = 100;
    retry2.time = aossInfo->retryInterval_Comu;
    if (retry2.time == -1)
        retry2.time = 100;
    selectTime = aossInfo->selectInterval;
    if (selectTime == -1)
        selectTime = 2000;

    aoss_data_init(aossInfo);
    if ((aoss_bss.gData.sLevel & 1) != 1) {
        aoss_set_error(0x13);
        FAIL(0xF);
    }

    retry_counter = 0;
    AOSS_StatusExclusion(0);
    while (1) {
        if (aoss_bss.bssList != NULL) {
            AOSS_FREE(aoss_bss.bssList);
            aoss_bss.bssList = NULL;
        }
        if (AOSSi_WLANGetBSSList(&aoss_bss.bssList) == -1)
            FAIL(0xF);
        ret = checkAP(aoss_bss.bssList);
        if (ret == 4)
            FAIL(2);
        if (ret == 0)
            break;
        if (retry_counter >= retry1.count)
            FAIL(1);
        AOSSi_Sleep(retry1.time);
        retry_counter++;
    }

    AOSS_StatusExclusion(1);
    AOSS_Memset(&comAP, 0, sizeof(comAP));
    if (AOSS_set_APInfo(&comAP) != 0)
        FAIL(0xF);
    aoss_bss.linkInfo = AOSS_MALLOC(sizeof(WLLA_LINK_STAT));
    if (aoss_bss.linkInfo == NULL)
        FAIL(0xF);
    AOSS_Memset(aoss_bss.linkInfo, 0, sizeof(WLLA_LINK_STAT));
    for (retry_counter = 0; retry_counter < retry1.count; retry_counter++) {
        ret = AOSSi_WLANConnect(&comAP, aoss_bss.linkInfo);
        if (ret == -1)
            FAIL(0xF);
        if (ret == 0) {
            if (ret != 0 || aoss_bss.linkInfo->LinkStat == 1)
                break;
        }
        AOSSi_Sleep(retry1.time);
    }
    if (retry_counter == retry1.count)
        FAIL(0xF);

    if (AOSS_SetIPAddr(0xC0A80B65, 0xFFFFFF00, 0xC0A80B65) != 0) {
        aoss_set_error(0xC);
        FAIL(0xF);
    }
    aoss_release();
    MakeSendSeqID(3, SendSeqID, aossInfo->macAddress);

    aoss_data.s_sFd = AOSS_Socket(2, 2, 0);
    if (aoss_data.s_sFd < 0)
        FAIL(0xF);
    if (AOSS_Setsockopt(aoss_data.s_sFd, 0xFFFF, 1, &optV, sizeof(optV)) < 0) {
        aoss_set_error(0xB);
        FAIL(0xF);
    }
    AOSS_Memset(&aoss_src_addr, 0, sizeof(aoss_src_addr));
    aoss_src_addr.family = 2;
    aoss_src_addr.addr.addr = AOSS_Htonl(0xC0A80B65);
    aoss_src_addr.port = AOSS_Htons(0x5790);
    if (AOSS_Bind(aoss_data.s_sFd, &aoss_src_addr, sizeof(aoss_src_addr)) < 0)
        FAIL(0xF);

    while (1) {
        recv_info = aoss_bss.s_buf;
        AOSS_Memset(&send_info, 0, sizeof(send_info));
        send_info.MyIp_addr = 0xC0A80B65;
        send_info.cli_ip = 0xC0A80B01;
        while (1) {
            if (SendReq == 1 && aoss_bss.gData.ip_chg != 1) {
                if (aoss_data.s_sFd != -1)
                    AOSS_Close(aoss_data.s_sFd);
                aoss_data.s_sFd = -1;
                if (AOSS_Disconnect() != 0)
                    FAIL(0xF);
                aoss_bss.bssList = AOSS_MALLOC(sizeof(WLLA_BSS_LIST));
                if (aoss_bss.bssList == NULL)
                    FAIL(0xF);
                while (1) {
                    if (aoss_bss.bssList != NULL) {
                        AOSS_FREE(aoss_bss.bssList);
                        aoss_bss.bssList = NULL;
                    }
                    apList = AOSSi_WLANGetBSSList(&aoss_bss.bssList);
                    if (apList == -1)
                        FAIL(0xF);
                    ret = checkAP(aoss_bss.bssList);
                    if (ret == 4)
                        FAIL(2);
                    if (ret == 0)
                        break;
                    if (retry_counter >= retry1.count)
                        FAIL(1);
                    AOSSi_Sleep(retry1.time);
                    retry_counter++;
                }
                if (apList == -1)
                    FAIL(0xF);
                aoss_bss.linkInfo = AOSS_MALLOC(sizeof(WLLA_LINK_STAT));
                if (aoss_bss.linkInfo == NULL)
                    FAIL(0xF);
                AOSS_Memset(aoss_bss.linkInfo, 0, sizeof(WLLA_LINK_STAT));
                for (retry_counter = 0; retry_counter < retry1.count; retry_counter++) {
                    ret = AOSSi_WLANConnect(&comAP, aoss_bss.linkInfo);
                    if (ret == -1)
                        FAIL(0xF);
                    if (ret == 0) {
                        if (ret != 0 || aoss_bss.linkInfo->LinkStat == 1)
                            break;
                    }
                    AOSSi_Sleep(retry1.time);
                }
                if (retry_counter == retry1.count)
                    FAIL(0xF);
                newIP = aoss_IP_sta(aoss_bss.gData.apAddr, aoss_bss.gData.apMask);
                if (AOSS_SetIPAddr(newIP, aoss_bss.gData.apMask, newIP) != 0) {
                    aoss_set_error(0xC);
                    FAIL(0xF);
                }
                aoss_bss.gData.ip_chg = 1;
                aoss_release();
                aoss_data.s_sFd = AOSS_Socket(2, 2, 0);
                if (aoss_data.s_sFd < 0)
                    FAIL(0xF);
                if (AOSS_Setsockopt(aoss_data.s_sFd, 0xFFFF, 1, &optV, sizeof(optV)) < 0) {
                    aoss_set_error(0xB);
                    FAIL(0xF);
                }
                AOSS_Memset(&aoss_src_addr, 0, sizeof(aoss_src_addr));
                aoss_src_addr.family = 2;
                aoss_src_addr.addr.addr = AOSS_Htonl(newIP);
                aoss_src_addr.port = AOSS_Htons(0x5790);
                if (AOSS_Bind(aoss_data.s_sFd, &aoss_src_addr, sizeof(aoss_src_addr)) < 0)
                    FAIL(0xF);
            }

            if (SendMessage(SendReq, &send_info, SendSeqID, aoss_data.s_sFd) == -1) {
                aoss_set_error(SendReq + 0x1000);
                FAIL(0xF);
            }
            AOSS_Memset(recv_info, 0, sizeof(RECV_INFO));
            AOSS_FD_ZERO(&sockFd);
            AOSS_FD_SET(aoss_data.s_sFd, &sockFd);
            wait.tv_sec = selectTime / 1000;
            wait.tv_usec = (selectTime % 1000) * 1000;
            if (AOSS_Select(aoss_data.s_sFd + 1, &sockFd, NULL, NULL, &wait) > 0)
                break;
            Retry1++;
            if (Retry1 > retry2.count) {
                if (SendReq == 0)
                    aoss_set_error(0xF);
                else if (SendReq == 1)
                    aoss_set_error(0x10);
                else
                    aoss_set_error(0x11);
                eRet = -1;
                goto end;
            }
            AOSSi_Sleep(retry2.time);
        }
        sockAddrSize = sizeof(clientAddr);
        ret = AOSS_Recvfrom(aoss_data.s_sFd, recv_info->packet, 1500, 0, &clientAddr, &sockAddrSize);
        recv_info->sockfd = aoss_data.s_sFd;
        recv_info->recvlen = AOSS_Ntohs(ret);
        RetSendReq = RecvMessage(SendReq, recv_info, &Retry1, SendSeqID, aoss_data.s_sFd);
        if (RetSendReq == 100) {
            eRet = 0;
            break;
        }
        if (RetSendReq == -1) {
            eRet = -1;
            break;
        }
        if (SendReq != RetSendReq) {
            if (RetSendReq == 2) {
                if (aoss_data.s_sFd != -1)
                    AOSS_Close(aoss_data.s_sFd);
                aoss_data.s_sFd = -1;
                if (AOSS_Disconnect() != 0)
                    FAIL(0xF);
                retry_counter = 0;
                AOSS_StatusExclusion(4);
                while (1) {
                    if (aoss_bss.bssList != NULL) {
                        AOSS_FREE(aoss_bss.bssList);
                        aoss_bss.bssList = NULL;
                    }
                    if (AOSSi_WLANGetBSSList(&aoss_bss.bssList) == -1)
                        FAIL(0xF);
                    ret = checkAP(aoss_bss.bssList);
                    if (ret == 4)
                        FAIL(2);
                    if (ret == 0)
                        break;
                    if (retry_counter >= retry1.count)
                        FAIL(1);
                    AOSSi_Sleep(retry1.time);
                    retry_counter++;
                }
                aoss_bss.linkInfo = AOSS_MALLOC(sizeof(WLLA_LINK_STAT));
                if (aoss_bss.linkInfo == NULL)
                    FAIL(0xF);
                AOSS_Memset(aoss_bss.linkInfo, 0, sizeof(WLLA_LINK_STAT));
                for (retry_counter = 0; retry_counter < retry1.count; retry_counter++) {
                    ret = AOSSi_WLANConnect(&comAP, aoss_bss.linkInfo);
                    if (ret == -1)
                        FAIL(0xF);
                    if (ret == 0) {
                        if (ret != 0 || aoss_bss.linkInfo->LinkStat == 1)
                            break;
                    }
                    AOSSi_Sleep(retry1.time);
                }
                if (retry_counter == retry1.count)
                    FAIL(0xF);
                if (AOSS_SetIPAddr(newIP, aoss_bss.gData.apMask, newIP) != 0) {
                    aoss_set_error(0xC);
                    FAIL(0xF);
                }
                aoss_release();
                aoss_data.s_sFd = AOSS_Socket(2, 2, 0);
                if (aoss_data.s_sFd < 0)
                    FAIL(0xF);
                if (AOSS_Setsockopt(aoss_data.s_sFd, 0xFFFF, 1, &optV, sizeof(optV)) < 0) {
                    aoss_set_error(0xB);
                    FAIL(0xF);
                }
                AOSS_Memset(&aoss_src_addr, 0, sizeof(aoss_src_addr));
                aoss_src_addr.family = 2;
                aoss_src_addr.addr.addr = AOSS_Htonl(newIP);
                aoss_src_addr.port = AOSS_Htons(0x5790);
                if (AOSS_Bind(aoss_data.s_sFd, &aoss_src_addr, sizeof(aoss_src_addr)) < 0)
                    FAIL(0xF);
            }
            SendReq = RetSendReq;
            continue;
        }
        SendReq = RetSendReq;
        if (Retry1 > retry2.count) {
            if (SendReq == 0)
                aoss_set_error(0xF);
            else if (SendReq == 1)
                aoss_set_error(0x10);
            else
                aoss_set_error(0x11);
            eRet = -1;
            break;
        }
        AOSSi_Sleep(retry2.time);
    }

end:
    if (aoss_data.s_sFd != -1)
        AOSS_Close(aoss_data.s_sFd);
    aoss_data.s_sFd = -1;
    if (AOSS_Disconnect() != 0)
        FAIL(0xF);
    if (eRet != 0) {
        switch (aoss_get_error()) {
        case 0xF:
            ret_value = 3;
            break;
        case 0x10:
            ret_value = 4;
            break;
        case 0x11:
            ret_value = 5;
            break;
        case 0x14:
            ret_value = 7;
            break;
        case 0x15:
            ret_value = 8;
            break;
        default:
            ret_value = 0xF;
            break;
        }
        FAIL(ret_value);
    }
    if (AOSS_seq_data_copy(aossInfo) != 0)
        FAIL(6);
    return 0;
}


unsigned long aoss_IP_sta(unsigned long ipAp, unsigned long nMask)
{
    unsigned long network = ipAp & nMask;
    unsigned long newIP = (ipAp & ~nMask) + 1;

    newIP |= network;
    if (newIP >= (~nMask | network))
        newIP = network | 1;
    return newIP;
}


void aoss_release(void)
{
    if (aoss_bss.linkInfo != 0) {
        AOSS_FREE(aoss_bss.linkInfo);
        aoss_bss.linkInfo = 0;
    }
    if (aoss_bss.bssList != 0) {
        AOSS_FREE(aoss_bss.bssList);
        aoss_bss.bssList = 0;
    }
}


void aoss_data_init(AOSS_INFO *aossInfo)
{
    AOSS_Memset(gSeqID, 0, 8);
    aoss_bss.gError = 1;
    AOSS_Memset(&aoss_bss.gData, 0, sizeof(_AOSS_INFO));
    aoss_bss.gData.p_name = aossInfo->productInfo.productName;
    aoss_bss.gData.p_name_len = aossInfo->productInfo.dataLen;
    aoss_bss.gData.sLevel = aossInfo->supportSecurity & 0xf;
    aoss_bss.gData.p_type = aossInfo->productInfo.dataType;
    aoss_bss.gData.aLevel = 0;
    aoss_bss.gData.apAddr = 0xc0a80b01;
    aoss_bss.gData.ip_chg = 0;
}


void aoss_set_error(unsigned int type)
{
    aoss_bss.gError = type;
}


unsigned int aoss_get_error(void)
{
    return aoss_bss.gError;
}


int AOSS_seq_data_copy(struct aoss_info *aossInfo)
{
    struct aoss_secure_info *ptr;
    ASTS_DATA_WEP *wep40;
    ASTS_DATA_WEP *wep104;
    ASTS_DATA_TKIP *tkip;
    ASTS_DATA_TKIP *aes;

    ptr = &aossInfo->secureInfo;
    wep40 = &SecurityInfo[0].WepData_40;
    wep104 = &SecurityInfo[0].WepData_104;
    tkip = &SecurityInfo[0].TkipData;
    aes = &SecurityInfo[0].AesData;
    if (ptr == 0)
        return -1;
    aossInfo->supportSecurity = aoss_bss.gData.sLevel & aoss_bss.gData.aLevel;
    AOSS_Memset(ptr, 0, sizeof(struct aoss_secure_info));
    if (aossInfo->supportSecurity & 1) {
        AOSS_Memcpy(ptr->WEP40Key1, wep40->Data[0], wep40->KeyLen);
        AOSS_Memcpy(ptr->WEP40Key2, wep40->Data[1], wep40->KeyLen);
        AOSS_Memcpy(ptr->WEP40Key3, wep40->Data[2], wep40->KeyLen);
        AOSS_Memcpy(ptr->WEP40Key4, wep40->Data[3], wep40->KeyLen);
        if (aoss_check_str(wep40->SSID, AOSS_Strlen(wep40->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WEP40_SSID, wep40->SSID, AOSS_Strlen(wep40->SSID));
    }
    if (aossInfo->supportSecurity & 2) {
        AOSS_Memcpy(ptr->WEP104Key1, wep104->Data[0], wep104->KeyLen);
        AOSS_Memcpy(ptr->WEP104Key2, wep104->Data[1], wep104->KeyLen);
        AOSS_Memcpy(ptr->WEP104Key3, wep104->Data[2], wep104->KeyLen);
        AOSS_Memcpy(ptr->WEP104Key4, wep104->Data[3], wep104->KeyLen);
        if (aoss_check_str(wep104->SSID, AOSS_Strlen(wep104->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WEP104_SSID, wep104->SSID, AOSS_Strlen(wep104->SSID));
    }
    if (aossInfo->supportSecurity & 4) {
        if (aoss_check_str(tkip->Data, tkip->KeyLen - 1) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_TKIP, tkip->Data, tkip->KeyLen);
        if (aoss_check_str(tkip->SSID, AOSS_Strlen(tkip->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_TKIP_SSID, tkip->SSID, AOSS_Strlen(tkip->SSID));
    }
    if (aossInfo->supportSecurity & 8) {
        if (aoss_check_str(aes->Data, aes->KeyLen - 1) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_AES, aes->Data, aes->KeyLen);
        if (aoss_check_str(aes->SSID, AOSS_Strlen(aes->SSID)) != 0)
            goto error;
        AOSS_Memcpy(ptr->WPA_PSK_AES_SSID, aes->SSID, AOSS_Strlen(aes->SSID));
    }
    aossInfo->aossResult = 0;
    return 0;

error:
    AOSS_Memset(ptr, 0, sizeof(struct aoss_secure_info));
    return -1;
}


int aoss_check_str(char *ptr, int count)
{
    int i;
    unsigned char str;

    for (i = 0; i < count; i++) {
        str = *ptr++;
        if (str < 0x20 || str > 0x7f)
            return -1;
    }
    return 0;
}


int checkAP(WLLA_BSS_LIST *list)
{
    int count, ret, num;
    int find;

    ret = 0;
    find = 0;
    num = list->Num;
    if (num == 0)
        return 5;
    if (list->Num > 64)
        num = 64;
    for (count = 0; count < num; count++) {
        if (list->BssInfo[count].Capability & 1) {
            if (list->BssInfo[count].Ssid.Len == AOSS_Strlen(aoss_str_10367) &&
                AOSS_Memcmp(list->BssInfo[count].Ssid.Ssid, aoss_str_10367, AOSS_Strlen(aoss_str_10367)) == 0)
                find++;
        }
    }
    if (find > 1)
        ret = 4;
    if (find == 0)
        ret = 5;
    return ret;
}


int AOSS_set_APInfo(WLLA_CONNECT_PARAM *ap)
{
    ap->Ssid.Len = AOSS_Strlen(aoss_str_10367);
    AOSS_Memcpy(ap->Ssid.Ssid, aoss_str_10367, ap->Ssid.Len);
    ap->AuthAlgo = 1;
    ap->Key.Len = AOSS_Strlen(aoss_str_10375);
    if (ap->Key.Len > 13)
        return -1;
    AOSS_Memcpy(ap->Key.Key, aoss_str_10375, ap->Key.Len);
    return 0;
}


void MakeSendSeqID(int Cnt, SEQID_INFO *SeqID, char *Mymacaddr)
{
    short *Num;
    int i;

    for (i = 0; i < Cnt; i++) {
        AOSS_Memcpy(SeqID->SendSeqID, Mymacaddr, 6);
        Num = (short *)&SeqID->SendSeqID[6];
        *Num = AOSS_Rand();
        *Num = AOSS_Htons(*Num);
        SeqID++;
    }
}


int AOSS_StatusExclusion(int stat)
{
    if (stat == -1) {
        aoss_data.before = stat;
        return 0;
    }
    if (aoss_data.before != stat) {
        aoss_data.before = stat;
        return AOSSi_Status(stat);
    }
    return 0;
}


int RecvMessage(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *SendSeqID, int sFd)
{
    int ret;
    tagASTSpktHeader *hdr;

    hdr = (tagASTSpktHeader *)recv_info->packet;
    if (AOSS_Ntohs(hdr->PktVersion) < 1) {
        (*Retry)++;
        return Mode;
    }
    if (hdr->Fragment != 0x11) {
        (*Retry)++;
        return Mode;
    }
    ret = DecodePacket(recv_info->packet);
    if (ret > 0) {
        (*Retry)++;
        return Mode;
    }
    switch (AOSS_Ntohs(hdr->cmd)) {
    case 0x1010:
        Mode = AstsSetInitRes(Mode, recv_info, Retry, SendSeqID);
        break;
    case 0x2010:
        Mode = AstsSetSecureRes(Mode, recv_info, Retry, SendSeqID);
        break;
    case 0x3010:
        Mode = AstsRestartRes(Mode, recv_info, Retry, SendSeqID);
        break;
    }
    return Mode;
}


int AstsSetInitRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID)
{
    unsigned long *Ret;
    tagASTSpktInitRes *plv;
    tagASTSpktHeader *ptr;
    int ret;

    if (Mode != 0) {
        (*Retry)++;
        return Mode;
    }
    ptr = (tagASTSpktHeader *)recv_info->packet;
    plv = (tagASTSpktInitRes *)(recv_info->packet + sizeof(tagASTSpktHeader));
    if (CheckRecvSeqID(pSeqID->SendSeqID, ptr->SeqID) < 0) {
        (*Retry)++;
        return Mode;
    }
    if (AOSS_Ntohs(plv->hdr.length) == 0) {
        (*Retry)++;
        return Mode;
    }
    if (plv->hdr.SubAttrNo == 7) {
        Ret = (unsigned long *)plv->ProductData;
        if (AOSS_Ntohl(*Ret) == -2)
            aoss_set_error(0x14);
        else if (AOSS_Ntohl(*Ret) == -3)
            aoss_set_error(0x15);
        else
            aoss_set_error(0x18);
        return -1;
    }
    if (plv->hdr.SubAttrNo != 1) {
        (*Retry)++;
        return Mode;
    }
    ret = GetProductInfo((char *)plv->ProductData, (PRODUCT_INFO_AOSS *)aoss_bss.ProductInfo);
    if (ret < 0) {
        if (ret == -2) {
            aoss_set_error(0x16);
            return -1;
        }
        (*Retry)++;
        return Mode;
    }
    aoss_bss.SecurityType = GetSecurityType(AOSS_Ntohs(ptr->CryptType));
    *Retry = 0;
    return 1;
}


int AstsSetSecureRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID)
{
    tagASTSpktResult *temp;
    unsigned char *pData;
    tagASTSpktHeader *ptr;

    if (Mode != 1) {
        (*Retry)++;
        return Mode;
    }
    ptr = (tagASTSpktHeader *)recv_info->packet;
    pData = recv_info->packet + sizeof(tagASTSpktHeader);
    if (CheckRecvSeqID(pSeqID[1].SendSeqID, ptr->SeqID) < 0) {
        (*Retry)++;
        return Mode;
    }
    temp = (tagASTSpktResult *)pData;
    if (AOSS_Ntohs(temp->hdr.length) == 0) {
        (*Retry)++;
        return Mode;
    }
    if (temp->hdr.SubAttrNo == 7) {
        if (AOSS_Ntohl(temp->Result) == -2)
            aoss_set_error(0x14);
        else if (AOSS_Ntohl(temp->Result) == -3)
            aoss_set_error(0x15);
        else
            aoss_set_error(0x18);
        return -1;
    }
    AOSS_Memset(aoss_bss.SecurityInfo, 0, sizeof(aoss_bss.SecurityInfo));
    if (GetSecurityData(0, pData, AOSS_Ntohs(ptr->size), (ASTS_DATA_INFO *)aoss_bss.SecurityInfo,
                        (PRODUCT_INFO_AOSS *)aoss_bss.ProductInfo) < 0) {
        (*Retry)++;
        return Mode;
    }
    if ((aoss_bss.gData.aLevel & aoss_bss.gData.sLevel) == 0)
        return Mode;
    *Retry = 0;
    return 2;
}


int AstsRestartRes(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *pSeqID)
{
    tagASTSpktResult *rslt;

    if (Mode != 2) {
        (*Retry)++;
        return Mode;
    }
    rslt = (tagASTSpktResult *)(recv_info->packet + sizeof(tagASTSpktHeader));
    if (CheckRecvSeqID(pSeqID[2].SendSeqID, ((tagASTSpktHeader *)recv_info->packet)->SeqID) < 0) {
        (*Retry)++;
        return Mode;
    }
    if (rslt->hdr.SubAttrNo != 7) {
        (*Retry)++;
        return Mode;
    }
    if (AOSS_Ntohs(rslt->hdr.length) == 0) {
        (*Retry)++;
        return Mode;
    }
    if (AOSS_Ntohl(rslt->Result) == 0)
        return 100;
    if (AOSS_Ntohl(rslt->Result) == -2) {
        aoss_set_error(0x14);
        return -1;
    }
    if (AOSS_Ntohl(rslt->Result) == -3) {
        aoss_set_error(0x15);
        return -1;
    }
    aoss_set_error(0x18);
    return -1;
}


int DecodePacket(unsigned char *tpkt)
{
    int size;
    unsigned char wrkSeqID[8];
    unsigned char *DecodeData;
    tagASTSpktCryptData *pRc4;
    tagASTSpktHeader *hdr;

    hdr = (tagASTSpktHeader *)tpkt;
    pRc4 = (tagASTSpktCryptData *)(tpkt + sizeof(tagASTSpktHeader));
    AOSS_Memcpy(wrkSeqID, hdr->SeqID, 8);
    if (CryptSeqNo(wrkSeqID, 8, aoss_str_10375, AOSS_Strlen(aoss_str_10375)) == -1) {
        aoss_set_error(2);
        return -100;
    }
    size = CheckSeqID(AOSS_Ntohs(hdr->cmd), wrkSeqID);
    if (size != 0)
        return size;
    if (AOSS_Ntohs(hdr->cmd) == 0x1000)
        AOSS_Memcpy(gSeqID, wrkSeqID, 8);
    if ((AOSS_Ntohs(hdr->CryptType) & 0xF) == 0)
        return 0;
    size = AOSS_Ntohs(pRc4->size);
    DecodeData = AOSS_MALLOC(size);
    if (DecodeData == 0) {
        aoss_set_error(2);
        return 100;
    }
    if (DecodeRC4(pRc4->Data, DecodeData, size, hdr->crc8, pRc4->iv, gSeqID, 8) < 0) {
        AOSS_FREE(DecodeData);
        if (aoss_get_error() == 2)
            return 100;
        return 200;
    }
    AOSS_Memcpy(pRc4, DecodeData, size);
    hdr->size = AOSS_Htons(size);
    AOSS_FREE(DecodeData);
    return 0;
}


int CheckSeqID(unsigned short CMD, unsigned char *RecvSeqID)
{
    int i, flag, ret;

    ret = 0;
    flag = 0;
    for (i = 0; i < 6; i++) {
        if (gSeqID[i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        if (AOSS_Memcmp(gSeqID, RecvSeqID, 6) != 0)
            ret = 1;
    } else if (CMD != 0x1000) {
        ret = 2;
    }
    return ret;
}


int CheckRecvSeqID(char *SendSeqID, unsigned char *RecvSeqID)
{
    int ret = 0;

    CryptSeqNo(RecvSeqID, 8, aoss_str_10375, AOSS_Strlen(aoss_str_10375));
    if (AOSS_Memcmp(SendSeqID, RecvSeqID, 6) != 0) {
        ret -= 1;
    } else if (AOSS_Ntohs(*(unsigned short *)(SendSeqID + 6)) + 1 != AOSS_Ntohs(*(unsigned short *)(RecvSeqID + 6))) {
        ret -= 2;
    }
    return ret;
}


int GetProductInfo(char *ProductData, PRODUCT_INFO_AOSS *ProductInfo)
{
    int Num;
    int length;
    VariableData *Data;

    AOSS_Memset(ProductInfo, 0, 0x104);
    Data = (VariableData *)ProductData;
    for (;;) {
        length = AOSS_Ntohs(Data->length);
        if (length <= 0)
            return -1;
        switch (Data->DataID) {
        case 0:
            AOSS_Memcpy(ProductInfo->ProductInfo[0], Data->Data, length);
            break;
        case 1:
            AOSS_Memcpy(ProductInfo->ProductInfo[1], Data->Data, length);
            break;
        case 2:
            AOSS_Memcpy(ProductInfo->ProductInfo[2], Data->Data, length);
            break;
        case 3:
        case 4:
            Num = AOSS_Ntohs(Data->Data[0]);
            if (Num <= 0)
                return -2;
            break;
        case 5:
            aoss_bss.gData.apAddr = AOSS_Ntohl(aoss_get_bin(Data->Data, length));
            break;
        case 6:
            aoss_bss.gData.apMask = AOSS_Ntohl(aoss_get_bin(Data->Data, length));
            break;
        default:
            return -1;
        }
        if (Data->offset == 0)
            break;
        Data = (VariableData *)(ProductData + AOSS_Ntohs(Data->offset));
    }
    return 0;
}


unsigned long aoss_get_bin(void *ptr, int num)
{
    unsigned long ret = 0;
    int i;
    unsigned char *p = (unsigned char *)ptr + (num - 1);

    for (i = 0; i < num; i++) {
        ret = (ret << 8) + *p--;
    }
    return ret;
}


int GetWEPData(tagASTSpktWEP40 *pWEP, ASTS_DATA_WEP *Info)
{
    VariableData *Data;
    unsigned int length;

    Data = (VariableData *)pWEP->WEP.WEP;
    for (;;) {
        length = AOSS_Ntohs(Data->length);
        switch (Data->DataID) {
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            if (length > 5)
                return -1;
            break;
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
            if (length > 0xD)
                return -1;
            break;
        case 0x15:
        case 0x25:
            if (length > 0x21)
                return -1;
            break;
        }
        switch (Data->DataID) {
        case 0x10:
        case 0x20:
            AOSS_Memcpy(Info->Data[0], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x11:
        case 0x21:
            AOSS_Memcpy(Info->Data[1], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x12:
        case 0x22:
            AOSS_Memcpy(Info->Data[2], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x13:
        case 0x23:
            AOSS_Memcpy(Info->Data[3], Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x15:
        case 0x25:
            if (length != 0 && Data->Data[length - 1] != 0)
                return -1;
            AOSS_Memcpy(Info->SSID, Data->Data, length);
            break;
        default:
            return -1;
        }
        if (Data->offset == 0)
            break;
        Data = (VariableData *)(pWEP->WEP.WEP + AOSS_Ntohs(Data->offset));
    }
    return 0;
}


int GetWPAData(tagASTSpktTKIP *pWPA, ASTS_DATA_TKIP *Info)
{
    VariableData *Data;
    unsigned int length;

    Data = (VariableData *)pWPA->WpaPsk.WpaPsk;
    for (;;) {
        length = AOSS_Ntohs(Data->length);
        switch (Data->DataID) {
        case 0x30:
        case 0x40:
            if (length > 0x40)
                return -1;
            break;
        case 0x35:
        case 0x45:
            if (length > 0x21)
                return -1;
            break;
        }
        switch (Data->DataID) {
        case 0x30:
        case 0x40:
            AOSS_Memcpy(Info->Data, Data->Data, length);
            Info->KeyLen = length;
            break;
        case 0x35:
        case 0x45:
            if (length != 0 && Data->Data[length - 1] != 0)
                return -1;
            AOSS_Memcpy(Info->SSID, Data->Data, length);
            break;
        default:
            return -1;
        }
        if (Data->offset == 0)
            break;
        Data = (VariableData *)(pWPA->WpaPsk.WpaPsk + AOSS_Ntohs(Data->offset));
    }
    return 0;
}


int GetBssidData(tagASTSpktBssid *pBssid, char *BSSID)
{
    VariableData *Data;
    int length;

    Data = (VariableData *)pBssid->Bssid.Bssid;
    length = AOSS_Ntohs(Data->length);
    if (length <= 0)
        return -1;
    if (Data->DataID != 0x70)
        return -1;
    AOSS_Memcpy(BSSID, Data->Data, length);
    return 0;
}


int GetSecurityData(int Mode, unsigned char *pData, int Length, ASTS_DATA_INFO *SecurityInfo,
                    PRODUCT_INFO_AOSS *Info)
{
    tagASTSsubAttrHeader *pSec;
    int size;
    int wLen;
    int ret;
    int Level;
    int Len;

    Level = 0;
    if (Length <= 0)
        return -2;
    for (;;) {
        pSec = (tagASTSsubAttrHeader *)pData;
        if (pSec->SubAttrNo == AttrNo[Mode])
            break;
        size = AOSS_Ntohs(pSec->length) + 4;
        Length -= size;
        pData += size;
        if (Length <= 0)
            return -4;
    }
    pData += 4;
    Len = AOSS_Ntohs(pSec->length);
    do {
        switch (*pData) {
        case 3:
            ret = GetWEPData((tagASTSpktWEP40 *)pData, &SecurityInfo[Mode].WepData_40);
            Level |= 1;
            break;
        case 4:
            ret = GetWEPData((tagASTSpktWEP40 *)pData, &SecurityInfo[Mode].WepData_104);
            Level |= 2;
            break;
        case 5:
            ret = GetWPAData((tagASTSpktTKIP *)pData, &SecurityInfo[Mode].TkipData);
            Level |= 4;
            break;
        case 6:
            ret = GetWPAData((tagASTSpktTKIP *)pData, &SecurityInfo[Mode].AesData);
            Level |= 8;
            break;
        case 10:
            ret = GetBssidData((tagASTSpktBssid *)pData, Info->ProductInfo[Mode + 3]);
            break;
        default:
            ret = -3;
            break;
        }
        if (ret != 0)
            return ret;
        wLen = AOSS_Ntohs(((tagASTSsubAttrHeader *)pData)->length) + 4;
        Len -= wLen;
        pData += wLen;
    } while (Len > 0);
    aoss_bss.gData.aLevel |= Level;
    return 0;
}


static int GetSecurityType(unsigned int type)
{
    int r = 0;
    if (type & 0x10)
        r = 1;
    return r;
}


int SendMessage(int SendReq, SEND_INFO *send_info, SEQID_INFO *SendSeqID, int sFd)
{
    int ret;

    switch (SendReq) {
    case 0:
        AOSS_StatusExclusion(2);
        ret = AstsSetInitReq(send_info, SendSeqID, sFd);
        break;
    case 1:
        AOSS_StatusExclusion(3);
        ret = AstsSetSecureReq(send_info, SendSeqID, sFd);
        break;
    case 2:
        AOSS_StatusExclusion(5);
        ret = AstsRestartReq(send_info, SendSeqID, sFd);
        break;
    default:
        ret = -1;
        break;
    }
    return ret;
}


int AstsSetInitReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd)
{
    struct UdpIpMsg *send_msg;
    short packet_size;
    short CryptType;
    tagASTSpktRequest *PlaneData;
    unsigned char wrkSeqID[8];
    unsigned char crc8;
    unsigned char *pData;

    crc8 = 0;
    packet_size = 0;
    CryptType = 0;
    send_msg = aoss_bss.s_buf;
    AOSS_Memset(send_msg, 0, sizeof(struct UdpIpMsg));
    PlaneData = AOSS_MALLOC(0x210);
    if (PlaneData == 0) {
        aoss_set_error(2);
        return -1;
    }
    AOSS_Memset(PlaneData, 0, 0x210);
    pData = send_msg->udpipmsg + sizeof(tagASTSpktHeader);
    AOSS_Memcpy(gSeqID, pSeqID->SendSeqID, 8);
    AOSS_Memcpy(wrkSeqID, gSeqID, 8);
    packet_size = SetStaData((char *)PlaneData->StaData);
    if (packet_size < 0) {
        aoss_set_error(3);
        if (PlaneData != 0)
            AOSS_FREE(PlaneData);
        return -1;
    }
    PlaneData->info.SubAttrNo = 0;
    PlaneData->info.length = AOSS_Htons(packet_size);
    packet_size += 4;
    PacketDataSet(0, pData, (unsigned char *)PlaneData, &packet_size, &CryptType, &crc8);
    CryptType |= 0x10;
    if (CryptSeqNo(wrkSeqID, 8, aoss_str_10375, 6) != 0) {
        aoss_set_error(2);
        if (PlaneData != 0)
            AOSS_FREE(PlaneData);
        return -1;
    }
    SetPacketHeader((tagASTSpktHeader *)send_msg, 0x1000, packet_size, CryptType, crc8, 0x11, wrkSeqID);
    packet_size += sizeof(tagASTSpktHeader);
    SendPacketUDP(send_msg->udpipmsg, packet_size, 0xFF, sFd);
    if (PlaneData != 0)
        AOSS_FREE(PlaneData);
    return 0;
}


int AstsSetSecureReq(SEND_INFO *send_info, SEQID_INFO *pSeqID, int sFd)
{
    struct UdpIpMsg *send_msg;
    unsigned char wrkSeqID[8];
    tagASTSpktCapability CapData;
    short packet_size;
    short CryptType;
    unsigned char crc8;

    crc8 = 0;
    packet_size = 0;
    CryptType = 0;
    send_msg = aoss_bss.s_buf;
    AOSS_Memset(&CapData, 0, sizeof(CapData));
    AOSS_Memset(send_msg, 0, sizeof(struct UdpIpMsg));
    CapData.info.SubAttrNo = 2;
    CapData.info.SubAttrVer = 0;
    CapData.info.length = AOSS_Htons(4);
    CapData.EncryptLevel = aoss_bss.gData.sLevel;
    CapData.EncryptLevel = AOSS_Htonl(CapData.EncryptLevel);
    packet_size = sizeof(CapData);
    PacketDataSet(aoss_bss.SecurityType, send_msg->udpipmsg + sizeof(tagASTSpktHeader),
                  (unsigned char *)&CapData, &packet_size, &CryptType, &crc8);
    AOSS_Memcpy(wrkSeqID, pSeqID[1].SendSeqID, 8);
    if (CryptSeqNo(wrkSeqID, 8, aoss_str_10375, 6) != 0) {
        aoss_set_error(2);
        return -1;
    }
    SetPacketHeader((tagASTSpktHeader *)send_msg, 0x2000, packet_size, CryptType, crc8, 0x11, wrkSeqID);
    packet_size += sizeof(tagASTSpktHeader);
    SendPacketUDP(send_msg->udpipmsg, packet_size, 0, sFd);
    return 0;
}


int AstsRestartReq(void *send_info, SEQID_INFO *pSeqID, int sFd)
{
    struct UdpIpMsg *send_msg;
    unsigned char wrkSeqID[8];

    send_msg = aoss_bss.s_buf;
    AOSS_Memset(send_msg, 0, sizeof(struct UdpIpMsg));
    AOSS_Memcpy(wrkSeqID, pSeqID[2].SendSeqID, 8);
    CryptSeqNo(wrkSeqID, 8, aoss_str_10375, AOSS_Strlen(aoss_str_10375));
    SetPacketHeader((tagASTSpktHeader *)send_msg, 0x3000, 0, 0, 0, 0x11, wrkSeqID);
    SendPacketUDP(send_msg->udpipmsg, 0x18, 0, sFd);
    return 0;
}


short SetStaData(char *StaData)
{
    int Option;
    short size;
    short Len;
    VariableData *Data;

    size = 0;
    Data = (VariableData *)StaData;
    Data->DataID = aoss_bss.gData.p_type;
    Data->DataType = 1;
    Len = aoss_bss.gData.p_name_len;
    AOSS_Memcpy(Data->Data, aoss_bss.gData.p_name, Len);
    Data->length = AOSS_Htons(Len);
    Len += 6;
    Len = (Len + 1) / 2 * 2;
    Data->offset = AOSS_Htons(Len);
    size += Len;

    Data = (VariableData *)(StaData + Len);
    Data->DataID = 0x60;
    Data->DataType = 0;
    Data->offset = AOSS_Htons(0);
    Option = AOSS_Htonl(0xE);
    AOSS_Memcpy(Data->Data, &Option, 4);
    Data->length = AOSS_Htons(4);
    size += 10;
    return size;
}


void PacketDataSet(int Type, unsigned char *pData, unsigned char *pPlaneData,
                   short *packet_size, short *CryptType, unsigned char *crc8)
{
    tagASTSpktCryptData *pcpt;

    if (Type == 1) {
        *CryptType = 1;
        pcpt = (tagASTSpktCryptData *)pData;
        EncodeRC4(pPlaneData, pcpt->Data, *packet_size, crc8, pcpt->iv, gSeqID, 8);
        pcpt->size = AOSS_Htons(*packet_size);
        *packet_size = *packet_size + 4;
    } else {
        AOSS_Memcpy(pData, pPlaneData, *packet_size);
    }
}


void SetPacketHeader(tagASTSpktHeader *Hdr, short cmd, short size, short CryptType,
                     char crc8, char Fragment, unsigned char *SeqID)
{
    Hdr->PktVersion = AOSS_Htons(1);
    Hdr->PktID = 0;
    Hdr->PktSubID = 0;
    Hdr->cmd = AOSS_Htons(cmd);
    Hdr->type = 0;
    Hdr->size = AOSS_Htons(size);
    Hdr->CryptType = AOSS_Htons(CryptType);
    Hdr->crc8 = crc8;
    Hdr->Fragment = Fragment;
    AOSS_Memcpy(Hdr->SeqID, SeqID, 8);
}


int SendPacketUDP(unsigned char *packet, int size, unsigned char Mac, int port)
{
    int byte;
    SOCSockAddrIn server;

    AOSS_Memset(&server, 0, sizeof(server));
    server.family = 2;
    server.port = AOSS_Htons(0x5790);
    server.addr.addr = AOSS_Htonl(aoss_bss.gData.apAddr);
    if (Mac == 0xff || aoss_bss.gData.ip_chg == 0)
        server.addr.addr = 0xffffffff;
    byte = AOSS_Sendto(port, packet, size, 0, &server, sizeof(server));
    return byte;
}


int EncodeRC4(unsigned char *srcData, unsigned char *EncodeData, int SizeOfData,
              unsigned char *CRC, unsigned char *iv, unsigned char *key, int keylen)
{
    ArcfourContext ctx;
    unsigned short now;
    unsigned short wrk;

    *CRC = crc(srcData, SizeOfData);
    ctx.state = AOSS_MALLOC(SizeOfData);
    if (ctx.state == 0)
        return -1;
    wrk = AOSS_Rand();
    AOSS_Memcpy(iv, &wrk, 2);
    AOSS_Memcpy(TANE, iv, 2);
    AOSS_Memcpy(TANE + 2, key, keylen);
    RC4init(&ctx, TANE, keylen + 2, SizeOfData);
    RC4encrypt(&ctx, EncodeData, srcData, SizeOfData);
    AOSS_FREE(ctx.state);
    return 0;
}


int DecodeRC4(unsigned char *srcData, unsigned char *DecodeData, int SizeOfData,
              unsigned char CRC, unsigned char *iv, unsigned char *key, int keylen)
{
    ArcfourContext ctx;
    unsigned char retCRC;

    ctx.state = AOSS_MALLOC(SizeOfData);
    if (ctx.state == 0) {
        aoss_set_error(2);
        return -1;
    }
    AOSS_Memcpy(TANE, iv, 2);
    AOSS_Memcpy(TANE + 2, key, keylen);
    RC4init(&ctx, TANE, keylen + 2, SizeOfData);
    RC4encrypt(&ctx, DecodeData, srcData, SizeOfData);
    retCRC = crc(DecodeData, SizeOfData);
    if (retCRC != CRC) {
        aoss_set_error(18);
        AOSS_FREE(ctx.state);
        return -1;
    }
    AOSS_FREE(ctx.state);
    return 0;
}


void RC4init(ArcfourContext *ctx, unsigned char *key, unsigned int key_len, unsigned int size)
{
    unsigned int keyindex, stateindex, counter;
    unsigned char t, u;
    unsigned char *state;

    state = ctx->state;
    ctx->y = 0;
    ctx->x = 0;
    ctx->SizeOfState = size;
    for (counter = 0; counter < size; counter++)
        state[counter] = counter;
    stateindex = 0;
    keyindex = 0;
    for (counter = 0; counter < size; counter++) {
        t = state[counter];
        stateindex = (stateindex + key[keyindex] + t) % ctx->SizeOfState;
        u = state[stateindex];
        state[stateindex] = t;
        state[counter] = u;
        if (++keyindex >= key_len)
            keyindex = 0;
    }
}


void RC4encrypt(ArcfourContext *ctx, unsigned char *dest, unsigned char *src, unsigned int len)
{
    unsigned int i;
    unsigned char state;

    for (i = 0; i < len; i++) {
        state = arcfour_byte(ctx);
        dest[i] = src[i] ^ state;
    }
}


unsigned int arcfour_byte(ArcfourContext *ctx)
{
    unsigned char x, y, sx, sy;
    unsigned char *state;

    state = ctx->state;
    x = (ctx->x + 1) % ctx->SizeOfState;
    sx = state[x];
    y = (sx + ctx->y) % ctx->SizeOfState;
    sy = state[y];
    ctx->x = x;
    ctx->y = y;
    state[y] = sx;
    state[x] = sy;
    return state[(sx + sy) % ctx->SizeOfState];
}


unsigned char crc(unsigned char *buf, int len)
{
    return update_crc(0xffffffffL, buf, len, 0, aoss_bss.crc_table) ^ 0xffffffffL;
}


unsigned long update_crc(unsigned long crc, unsigned char *buf, int len,
                         int crc_table_computed, unsigned long *crc_table)
{
    unsigned long c = crc;
    int n;

    if (!crc_table_computed)
        make_crc_table(crc_table_computed, crc_table);
    for (n = 0; n < len; n++) {
        c = crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
    }
    return c;
}


void make_crc_table(int crc_table_computed, unsigned long *crc_table)
{
    unsigned long c;
    int n, k;

    for (n = 0; n < 256; n++) {
        c = (unsigned long)n;
        for (k = 0; k < 8; k++) {
            if (c & 1)
                c = 0xedb88320L ^ (c >> 1);
            else
                c = c >> 1;
        }
        *crc_table++ = c;
    }
}


int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen)
{
    int i;
    char *Key, *wBuff;

    Key = AOSS_MALLOC(Datalen / 2);
    if (Key == 0)
        return -1;
    wBuff = AOSS_MALLOC(Datalen);
    if (wBuff == 0) {
        AOSS_FREE(Key);
        return -1;
    }
    for (i = 0; i < 2; i++) {
        MakeKey(i, Key, Datalen, KeyData, Keylen);
        AddKey(Key, Data, Datalen);
        Rotate(Data, Datalen, wBuff);
    }
    AOSS_FREE(Key);
    AOSS_FREE(wBuff);
    return 0;
}


void MakeKey(int ID, char *Key, int maclen, char *Wep, int weplen)
{
    int i, size, pos;

    size = maclen / 2;
    pos = ID % weplen;
    for (i = 0; i < size; i++) {
        Key[i] = i;
        Key[i] = Key[i] ^ Wep[pos];
        pos++;
        if (pos >= weplen)
            pos = 0;
    }
}


void AddKey(char *Key, unsigned char *mac, int maclen)
{
    int i, size;

    size = maclen / 2;
    for (i = 0; i < size; i++) {
        mac[size + i] ^= Key[i];
    }
}


void Rotate(unsigned char *mac, int maclen, char *wBuff)
{
    int size;

    size = maclen / 2;
    AOSS_Memcpy(wBuff, mac + size, size);
    AOSS_Memcpy(wBuff + size, mac, size);
    AOSS_Memcpy(mac, wBuff, maclen);
}


static int Alloc(int a, int b)
{
    if (b > 0)
        return (int)AOSSi_Alloc(b);
    return 0;
}


/*
 * Forward b to the handler in the global function pointer at 0x021DCE2C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/Free.c \
 *       --func Free --addr 0x021B8184 --region ov016 --cc dsi/1.1p1 --thumb
 */
static void Free(int a, int b)
{
    AOSSi_Free((void *)b);
}


int AOSS_SetIPAddr(unsigned long ip, unsigned long sm, unsigned long gw)
{
    aoss_data.soconfig.addr = AOSS_Htonl(ip);
    aoss_data.soconfig.netmask = AOSS_Htonl(sm);
    aoss_data.soconfig.router = AOSS_Htonl(gw);
    if (SOC_Startup(&aoss_data.soconfig) < 0)
        return -1;
    while (CPSMyIp == 0)
        OS_Sleep(100);
    return 0;
}


int AOSS_Disconnect(void)
{
    if (SOC_Cleanup() < 0)
        return -1;
    return -(AOSSi_Disconnect() != 0);
}


int AOSS_Memcmp(void *s1, void *s2, int n)
{
    unsigned char *c1 = s1;
    unsigned char *c2 = s2;
    int diff = 0;

    while (n-- > 0 && (diff = *c1 - *c2) == 0) {
        c1++;
        c2++;
    }
    return diff;
}


void *AOSS_Memcpy(void *dest, void *src, int n)
{
    MI_CpuCopy8(src, dest, n);
}


void *AOSS_Memset(void *s, int c, int n)
{
    MI_CpuFill8(s, (u8)c, (u32)n);
}


int AOSS_Recvfrom(int s, void *buf, int len, int flags, void *from, int *fromlen)
{
    *(unsigned char *)from = (unsigned char)*fromlen;
    return SOC_RecvFrom(s, buf, len, flags, from);
}


int AOSS_Select(int nfds, SOCPollFD *readfds, void *writefds, void *exceptfds, struct timeval *timeout)
{
    SOCPollFD fds[1];
    unsigned long long timuout_tic;

    fds[0] = *readfds;
    timuout_tic = 0;
    timuout_tic += ((unsigned long long)timeout->tv_sec * 0x01ff6210) >> 6;
    timuout_tic += ((unsigned long long)timeout->tv_usec * 0x01ff6210) >> 6;
    return SOC_Poll(fds, 1, timuout_tic);
}


int AOSS_Sendto(int s, void *msg, int len, int flags, void *to, int tolen)
{
    *(unsigned char *)to = (unsigned char)tolen;
    return SOC_SendTo(s, msg, len, flags, to);
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Setsockopt.c \
 *       --func AOSS_Setsockopt --addr 0x021B82C4 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */
int AOSS_Setsockopt(int s, int level, int optname, void *optval, int optlen)
{
}


/*
 * Thumb tail-call thunk into SOC_Socket.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Socket.c \
 *       --func AOSS_Socket --addr 0x021B82C8 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */
int AOSS_Socket(int domain, int type, int protocol)
{
    return SOC_Socket(domain, type, protocol);
}


/*
 * Store the length byte at the start of the address, then tail-call SOC_Bind with the same arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Bind.c \
 *       --func AOSS_Bind --addr 0x021B82D0 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */
int AOSS_Bind(int s, void *addr, int addrlen)
{
    *(unsigned char *)addr = addrlen;
    return SOC_Bind(s, addr, addrlen);
}


int AOSS_Close(int fd)
{
    return SOC_Close(fd);
}


unsigned long AOSS_Htonl(unsigned long hostlong)
{
    return ((hostlong >> 24) & 0xff) | ((hostlong >> 8) & 0xff00) |
           ((hostlong << 8) & 0xff0000) | ((hostlong << 24) & 0xff000000);
}


unsigned short AOSS_Htons(unsigned short hostshort)
{
    return ((hostshort >> 8) & 0xff) | ((hostshort << 8) & 0xff00);
}


unsigned long AOSS_Ntohl(unsigned long netlong)
{
    return ((netlong >> 24) & 0xff) | ((netlong >> 8) & 0xff00) |
           ((netlong << 8) & 0xff0000) | ((netlong << 24) & 0xff000000);
}


unsigned short AOSS_Ntohs(unsigned short netshort)
{
    return ((netshort >> 8) & 0xff) | ((netshort << 8) & 0xff00);
}


int AOSS_Strlen(char *s)
{
    int n = 0;
    while (s[n] != 0)
        n++;
    return n;
}


static inline void MATH_InitRand16(MATHRandContext16 *context, unsigned long seed)
{
    context->x = seed;
    context->mul = 1566083941LU;
    context->add = 2531011;
}


static inline unsigned short MATH_Rand16(MATHRandContext16 *context, unsigned short max)
{
    context->x = context->mul * context->x + context->add;
    return (unsigned short)(max ? (((context->x >> 16) * max) >> 16) : (context->x >> 16));
}


int AOSS_Rand(void)
{
    RTCTime time;
    int sheed;

    if (aoss_bss.initflg == 0) {
        sheed = 0;
        AOSS_Memset(&time, sheed, sizeof(RTCTime));
        if (RTC_GetTime(&time) == 0) {
            sheed += time.hour << 10;
            sheed += time.minute << 3;
            sheed += time.second;
        }
        MATH_InitRand16(&aoss_bss.randContext, sheed);
        aoss_bss.initflg = 1;
    }
    return MATH_Rand16(&aoss_bss.randContext, 0x7fff);
}


/*
 * Clear a u32 and two u16 fields of a small record.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_FD_ZERO.c \
 *       --func AOSS_FD_ZERO --addr 0x021B83E8 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */
void AOSS_FD_ZERO(SOCPollFD *pollFd)
{
    pollFd->fd = 0;
    pollFd->events = 0;
    pollFd->revents = 0;
}


int AOSS_FD_SET(int fd, SOCPollFD *pollFd)
{
    pollFd->fd = fd;
    pollFd->events = 1;
    return 1;
}
