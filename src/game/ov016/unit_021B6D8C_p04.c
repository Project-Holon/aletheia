/*
 * file:     unit_021B6D8C_p04.c
 * unit:     yes
 * function: func_021B7BF0, func_021B7C5C, func_021B7CE8, func_021B7D3C, func_021B7D94, func_021B7DFC, func_021B7E78, func_021B7F00, func_021B7F64, func_021B7F90, func_021B7FD0
 * address:  0x021B7BF0
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
 *   aoss_bss         0x021DC040  data
 *   aoss_str_10375   0x021DAB20  data
 *   AOSS_Memset      0x021B8240  thumb
 *   AOSS_Memcpy      0x021B8230  thumb
 *   AOSS_Strlen      0x021B8364  thumb
 *   CryptSeqNo       0x021B8068  thumb
 *   AOSS_Htons   0x021B830C  thumb
 *   AOSS_Htonl   0x021B82E4  thumb
 *   gSeqID       0x021DCDA0  data
 *   AOSS_Sendto  0x021B82B4  thumb
 *   TANE         0x021DCDA8  data
 *   AOSS_MALLOC  0x021B61B0  thumb
 *   AOSS_FREE    0x021B61C0  thumb
 *   AOSS_Rand    0x021B8378  thumb
 *   aoss_set_error  0x021B6D74  thumb
 *   _u32_div_f  0x0209C2B0  arm
 *   update_crc  0x021B7FF8  thumb
 */
#include "../../matched/include/G_AOSS_BSS.h"

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

typedef struct {
    int            SecurityType;    /* +0x000 */
    void          *bssList;         /* +0x004 */
    int            initflg;         /* +0x008 */
    void          *linkInfo;        /* +0x00C */
    unsigned int   gError;          /* +0x010 */
    void          *s_buf;           /* +0x014 */
    MATHRandContext16 randContext;  /* +0x018 */
    _AOSS_INFO     gData;           /* +0x024 */
    unsigned char  ProductInfo[0x280];   /* +0x040 PRODUCT_INFO_AOSS */
    unsigned long  crc_table[256];       /* +0x2C0 */
    unsigned char  SecurityInfo[0x6A0];  /* +0x6C0 ASTS_DATA_INFO[2] */
} AOSS_BSS;

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

struct UdpIpMsg {
    unsigned char udpipmsg[1500];
};

typedef struct {
    unsigned char  DataID;
    unsigned char  DataType;
    unsigned short length;
    unsigned short offset;
    unsigned char  Data[256];
} VariableData;

typedef struct {
    unsigned short size;
    unsigned char  iv[2];
    unsigned char  Data[1];
} tagASTSpktCryptData;

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
    unsigned int   x;
    unsigned int   y;
    unsigned char *state;
    unsigned int   SizeOfState;
} ArcfourContext;

extern void *AOSS_Memset(void *s, int c, int n);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern int AOSS_Strlen(char *s);
extern int CryptSeqNo(unsigned char *Data, int Datalen, char *KeyData, int Keylen);
extern unsigned short AOSS_Htons(unsigned short hostshort);
extern unsigned long AOSS_Htonl(unsigned long hostlong);
extern int AOSS_Sendto(int s, void *msg, int len, int flags, void *to, int tolen);
extern void *AOSS_MALLOC(int a);
extern void AOSS_FREE(void *a);
extern int AOSS_Rand(void);
extern void aoss_set_error(unsigned int type);
extern unsigned long update_crc(unsigned long crc, unsigned char *buf, int len,
                                int crc_table_computed, unsigned long *crc_table);
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
extern struct AOSS_BSS aoss_bss;
extern char aoss_str_10375[];
extern unsigned char gSeqID[8];
extern unsigned char TANE[100];


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
    Data->DataID = aoss_bss.gData_p_type;
    Data->DataType = 1;
    Len = aoss_bss.gData_p_name_len;
    AOSS_Memcpy(Data->Data, aoss_bss.gData_p_name, Len);
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
    server.addr.addr = AOSS_Htonl(aoss_bss.gData_apAddr);
    if (Mac == 0xff || aoss_bss.gData_ip_chg == 0)
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
