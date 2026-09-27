/*
 * function: GetBssidData
 * address:  0x021B782C
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
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol GetBssidData (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B782C.c \
 *       --func GetBssidData --addr 0x021B782C --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    unsigned char  SubAttrNo;
    unsigned char  SubAttrVer;
    unsigned short length;
} tagASTSsubAttrHeader;

typedef struct {
    unsigned short size;
    unsigned char  Bssid[1];
} tagBssidData;

typedef struct {
    tagASTSsubAttrHeader info;
    tagBssidData         Bssid;
} tagASTSpktBssid;

typedef struct {
    unsigned char  DataID;
    unsigned char  DataType;
    unsigned short length;
    unsigned short offset;
    unsigned char  Data[256];
} VariableData;

extern unsigned short AOSS_Ntohs(unsigned short netshort);
extern void *AOSS_Memcpy(void *dest, void *src, int n);

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
