/*
 * function: func_0217BDA8
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
 *   func_0217A484  0x0217A484  arm  ov009
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   g_021A27B8     0x021A27B8  data ov009
 *   g_021ACEF0     0x021ACEF0  data ov009
 *   g_021A2818     0x021A2818  data ov009
 *   g_021A2820     0x021A2820  data ov009
 *   g_02153FAC     0x02153FAC  data
 *   g_021A282C     0x021A282C  data ov009
 *   g_021A2838     0x021A2838  data ov009
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

extern int func_0217A484(DWCHttp *http, int noparsebody);
extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
extern void func_02059F54(int error, int errorCode);

extern const DWCProfFieldNames g_021A27B8;
extern DWCProfWorkarea *g_021ACEF0;
extern char g_021A2818[];
extern char g_021A2820[];
extern int g_02153FAC;
extern char g_021A282C[];
extern char g_021A2838[];

int func_0217BDA8(void)
{
    DWCProfFieldNames regionResultFieldName = g_021A27B8;
    int isAllRegionResult = 0;
    int decodedStringLength;
    char *strp;
    int httpretcode;
    char retcode[4];
    char result[51];
    int i;
    int j;
    DWCHttp *DWChttp = &g_021ACEF0->http;

    if (!func_0217A484(DWChttp, 0))
        goto error;

    strp = func_0217A728(DWChttp, g_021A2818);
    if (strp != 0)
        func_02168250(strp);

    strp = func_0217A728(DWChttp, g_021A2820);
    if (strp == 0)
        goto error;
    httpretcode = func_020964E0((u32)strp);
    if (g_02153FAC == 34 || httpretcode != 200)
        goto error;

    if (func_0217A77C(DWChttp, g_021A282C, retcode, 4) <= 0)
        goto error;
    httpretcode = func_020964E0((u32)retcode);
    if (g_02153FAC == 34)
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
        if (decodedStringLength < g_021ACEF0->wordsnum)
            goto error;
        for (j = 0; j < g_021ACEF0->wordsnum; j++) {
            if (result[j] == '1')
                g_021ACEF0->result[j] |= (char)(1 << i);
        }
    }

    decodedStringLength = func_0217A77C(DWChttp, g_021A2838, result, sizeof(result));
    if (decodedStringLength < 0)
        goto error;
    if (decodedStringLength == 0)
        goto error;
    if (decodedStringLength < g_021ACEF0->wordsnum)
        goto error;

    *g_021ACEF0->badwordsnum = 0;
    for (j = 0; j < g_021ACEF0->wordsnum; j++) {
        if (result[j] == '1') {
            (*g_021ACEF0->badwordsnum)++;
            if (isAllRegionResult)
                g_021ACEF0->result[j] |= 0x80;
            else
                g_021ACEF0->result[j] = 1;
        }
    }
    return 1;

error:
    func_02059F54(17, -33020);
    return 0;
}
