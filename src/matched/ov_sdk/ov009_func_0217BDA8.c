/*
 * function: DWCi_Prof_ParseResponse
 * address:  0x0217BDA8
 * packet:   pkt_ov009_0217BDA8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Prof_ParseResponse (libdwcauth.TWL.HYB.a dwc_prof.o)
 *
 * symbols:
 *   DWC_Http_ParseResult  0x0217A484  arm  ov009
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   atoi  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   gDwcProfFieldNames     0x021A27B8  data ov009
 *   gDwcProfWorkarea     0x021ACEF0  data ov009
 *   gDwcProfLabelDate     0x021A2818  data ov009
 *   gDwcProfLabelHttpResult     0x021A2820  data ov009
 *   errno     0x02153FAC  data
 *   gDwcProfLabelReturnCd     0x021A282C  data ov009
 *   gDwcProfLabelPrWords     0x021A2838  data ov009
 */

typedef struct DWCHttp {
    char pad0[0x1c50];
} DWCHttp;

typedef struct DWCProfWorkarea {
    DWCHttp http;
    int http_initialized;
    char url[257];
    char *result;
    int *badwordsnum;
    int wordsnum;
} DWCProfWorkarea;

typedef struct DWCProfFieldNames {
    char *name[8];
} DWCProfFieldNames;

extern int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
extern void func_02059F54(int error, int errorCode);

extern const DWCProfFieldNames gDwcProfFieldNames;
extern DWCProfWorkarea *gDwcProfWorkarea;
extern char gDwcProfLabelDate[];
extern char gDwcProfLabelHttpResult[];
extern int errno;
extern char gDwcProfLabelReturnCd[];
extern char gDwcProfLabelPrWords[];

int DWCi_Prof_ParseResponse(void)
{
    DWCProfFieldNames regionResultFieldName = gDwcProfFieldNames;
    int isAllRegionResult = 0;
    int decodedStringLength;
    char *strp;
    int httpretcode;
    char retcode[4];
    char result[51];
    int i;
    int j;
    DWCHttp *DWChttp = &gDwcProfWorkarea->http;

    if (!DWC_Http_ParseResult(DWChttp, 0))
        goto error;

    strp = func_0217A728(DWChttp, gDwcProfLabelDate);
    if (strp != 0)
        func_02168250(strp);

    strp = func_0217A728(DWChttp, gDwcProfLabelHttpResult);
    if (strp == 0)
        goto error;
    httpretcode = atoi((u32)strp);
    if (errno == 34 || httpretcode != 200)
        goto error;

    if (func_0217A77C(DWChttp, gDwcProfLabelReturnCd, retcode, 4) <= 0)
        goto error;
    httpretcode = atoi((u32)retcode);
    if (errno == 34)
        goto error;
    if (httpretcode == 1 || (httpretcode >= 100 && httpretcode != 100)) {
        func_02059F54(17, -33000 - httpretcode);
        return 0;
    }

    for (i = 0; i < sizeof(regionResultFieldName.name) / sizeof(char *) - 1; i++) {
        if (regionResultFieldName.name[i] == 0)
            continue;
        decodedStringLength = func_0217A77C(DWChttp, regionResultFieldName.name[i], result, sizeof(result));
        if (decodedStringLength < 0)
            goto error;
        if (decodedStringLength == 0)
            continue;
        isAllRegionResult = 1;
        if (decodedStringLength < gDwcProfWorkarea->wordsnum)
            goto error;
        for (j = 0; j < gDwcProfWorkarea->wordsnum; j++) {
            if (result[j] == '1')
                gDwcProfWorkarea->result[j] |= (char)(1 << i);
        }
    }

    decodedStringLength = func_0217A77C(DWChttp, gDwcProfLabelPrWords, result, sizeof(result));
    if (decodedStringLength < 0)
        goto error;
    if (decodedStringLength == 0)
        goto error;
    if (decodedStringLength < gDwcProfWorkarea->wordsnum)
        goto error;

    *gDwcProfWorkarea->badwordsnum = 0;
    for (j = 0; j < gDwcProfWorkarea->wordsnum; j++) {
        if (result[j] == '1') {
            (*gDwcProfWorkarea->badwordsnum)++;
            if (isAllRegionResult)
                gDwcProfWorkarea->result[j] |= 0x80;
            else
                gDwcProfWorkarea->result[j] = 1;
        }
    }
    return 1;

error:
    func_02059F54(17, -33020);
    return 0;
}
