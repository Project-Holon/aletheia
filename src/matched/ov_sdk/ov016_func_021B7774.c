/*
 * function: GetWPAData
 * address:  0x021B7774
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AOSS_Ntohs   0x021B834C  thumb
 *   AOSS_Memcpy  0x021B8230  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol GetWPAData (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7774.c \
 *       --func GetWPAData --addr 0x021B7774 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
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

typedef struct {
    unsigned char  DataID;
    unsigned char  DataType;
    unsigned short length;
    unsigned short offset;
    unsigned char  Data[256];
} VariableData;

typedef struct {
    unsigned short size;
    unsigned char  WpaPsk[1];
} tagWpaPskData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagWpaPskData        WpaPsk;
} tagASTSpktTKIP;

typedef struct {
    int  Enable;
    int  KeyLen;
    char SSID[40];
    char Data[64];
} ASTS_DATA_TKIP;

extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern void *AOSS_Memcpy(void *dest, void *src, int n);

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
