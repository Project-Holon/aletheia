/*
 * file:     unit_021B61B0.c
 * unit:     yes
 * function: func_021B61B0, func_021B61C0, AOSSi_Init, func_021B62C0, func_021B6CD8, aoss_release, aoss_data_init
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
 * symbols:
 *   func_021DCE20   0x021DCE20  data
 *   func_021DCE2C   0x021DCE2C  data  ov016
 *   aoss_bss              0x021DC040  data
 *   aoss_data             0x021DAAB4  data
 *   AOSSi_Alloc           0x021DCE20  data
 *   AOSSi_Free            0x021DCE2C  data
 *   AOSS_MALLOC           0x021B61B0  thumb
 *   AOSS_StatusExclusion  0x021B7098  thumb
 *   AOSS_FREE             0x021B61C0  thumb
 *   AOSS_Close            0x021B82DC  thumb
 *   AOSS_Bind             0x021B82D0  thumb
 *   AOSS_Disconnect       0x021B81EC  thumb
 *   AOSS_FD_SET           0x021B83F4  thumb
 *   AOSS_FD_ZERO          0x021B83E8  thumb
 *   AOSS_Htonl            0x021B82E4  thumb
 *   AOSS_Htons            0x021B830C  thumb
 *   AOSS_Memset           0x021B8240  thumb
 *   AOSS_Ntohs            0x021B834C  thumb
 *   AOSS_Recvfrom         0x021B824C  thumb
 *   AOSS_Select           0x021B8260  thumb
 *   AOSS_SetIPAddr        0x021B8194  thumb
 *   AOSS_Setsockopt       0x021B82C4  thumb
 *   AOSS_Socket           0x021B82C8  thumb
 *   AOSS_seq_data_copy    0x021B6D8C  thumb
 *   AOSS_set_APInfo       0x021B7024  thumb
 *   AOSSi_Sleep           0x021B89C0  thumb
 *   AOSSi_WLANConnect     0x021B87F0  thumb
 *   AOSSi_WLANGetBSSList  0x021B8678  thumb
 *   MakeSendSeqID         0x021B7068  thumb
 *   RecvMessage           0x021B70C4  thumb
 *   SendMessage           0x021B797C  thumb
 *   _s32_div_f            0x0209C0A4  arm
 *   aoss_get_error        0x021B6D80  thumb
 *   aoss_set_error        0x021B6D74  thumb
 *   checkAP               0x021B6FA8  thumb
 *   aoss_rodata           0x021D77C4  data
 *   gSeqID       0x021DCDA0  data
 */
#include "../../matched/include/G_AOSS_DATA_SECTION.h"

#define NULL ((void *)0)
#define FAIL(code)                      \
    do {                                \
        aossInfo->aossResult = (code);  \
        aoss_release();                 \
        return -1;                      \
    } while (0)
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
    struct recv_info *s_buf;        /* +0x014 */
    MATHRandContext16 randContext;  /* +0x018 */
    _AOSS_INFO     gData;           /* +0x024 */
    unsigned char  ProductInfo[0x280];   /* +0x040 PRODUCT_INFO_AOSS */
    unsigned long  crc_table[256];       /* +0x2C0 */
    unsigned char  SecurityInfo[0x6A0];  /* +0x6C0 ASTS_DATA_INFO[2] */
} AOSS_BSS;

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

typedef struct SEND_INFO SEND_INFO;

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

typedef struct {
    unsigned long  cli_ip;
    unsigned short port;
    unsigned char  IfHwAddress[8];
    unsigned long  MyIp_addr;
} SEND_INFO_;

typedef struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
} WLLA_SSID;

typedef struct wlla_key {
    unsigned long Length;
    unsigned char Key[16];
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
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    unsigned long  addr;
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

extern void *AOSS_MALLOC(int a);
extern int AOSS_StatusExclusion(int stat);
extern void AOSS_FREE(void *a);
extern int AOSS_Close(int fd);
extern void *AOSS_Memset(void *s, int c, int n);
extern void aoss_set_error(unsigned int type);
extern unsigned int aoss_get_error(void);
extern int AOSSi_WLANGetBSSList(WLLA_BSS_LIST **bssList);
extern int checkAP(WLLA_BSS_LIST *list);
extern void AOSSi_Sleep(int msec);
extern int AOSS_set_APInfo(WLLA_CONNECT_PARAM *ap);
extern int AOSSi_WLANConnect(WLLA_CONNECT_PARAM *conParam, WLLA_LINK_STAT *linkStat);
extern int AOSS_SetIPAddr(unsigned long ip, unsigned long sm, unsigned long gw);
extern void MakeSendSeqID(int Cnt, SEQID_INFO *SeqID, char *Mymacaddr);
extern int AOSS_Socket(int domain, int type, int protocol);
extern int AOSS_Setsockopt(int s, int level, int optname, void *optval, int optlen);
extern unsigned long AOSS_Htonl(unsigned long hostlong);
extern unsigned short AOSS_Htons(unsigned short hostshort);
extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern int AOSS_Bind(int s, void *addr, int addrlen);
extern int AOSS_Disconnect(void);
extern int SendMessage(int SendReq, SEND_INFO_ *send_info, SEQID_INFO *SendSeqID, int sFd);
extern void AOSS_FD_ZERO(SOCPollFD *fd);
extern int AOSS_FD_SET(int s, SOCPollFD *fd);
extern int AOSS_Select(int nfds, SOCPollFD *readfds, void *writefds, void *exceptfds, struct timeval *timeout);
extern int AOSS_Recvfrom(int s, void *buf, int len, int flags, void *from, int *fromlen);
extern int RecvMessage(int Mode, RECV_INFO *recv_info, int *Retry, SEQID_INFO *SendSeqID, int sFd);
extern int AOSS_seq_data_copy(struct aoss_info *aossInfo);
void func_021B61B0(int a);
void func_021B61C0(int a);
int AOSSi_Init(struct aoss_info *aossInfo);
int AOSS_Init_old(struct aoss_info *aossInfo);
unsigned long aoss_IP_sta(unsigned long ipAp, unsigned long nMask);
void aoss_release(void);
void aoss_data_init(AOSS_INFO *aossInfo);
extern AOSS_BSS aoss_bss;
extern struct AOSS_DATA_SECTION aoss_data;
extern unsigned char gSeqID[8];
extern const struct _retry aoss_rodata;   /* aoss.o .rodata: the compiler's @8259, retry1's initialiser { -1, -1 } */


extern void (*func_021DCE20)(int);



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
 *   python tools/match.py one --src src/matched/func_021B61B0.c \
 *       --func func_021B61B0 --addr 0x021B61B0 --region ov016 --cc dsi/1.1p1 --thumb
 */
void func_021B61B0(int a)
{
    func_021DCE20(a);
}


extern void (*func_021DCE2C)(int);



/*
 * Forward to the handler in the global function pointer at 0x021DCE2C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B61C0.c \
 *       --func func_021B61C0 --addr 0x021B61C0 --region ov016 --cc dsi/1.1p1 --thumb
 */
void func_021B61C0(int a)
{
    func_021DCE2C(a);
}




extern void *(*AOSSi_Alloc)(unsigned long size);



extern void (*AOSSi_Free)(void *ptr);




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
    SEND_INFO_ send_info;
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
    aoss_src_addr.addr = AOSS_Htonl(0xC0A80B65);
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
                aoss_src_addr.addr = AOSS_Htonl(newIP);
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
                aoss_src_addr.addr = AOSS_Htonl(newIP);
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
