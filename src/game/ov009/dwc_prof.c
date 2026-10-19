/*
 * file:     dwc_prof.c
 * unit:     yes
 * function: DWCi_CheckProfanityAsync, DWC_CheckProfanityExAsync, DWC_CheckProfanityProcess, DWCi_Prof_ParseResponse, DWCi_Prof_Alloc, DWCi_Prof_Free
 * address:  0x0217B828
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   wcslen  0x02096578  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWC_Alloc  0x0205A16C  arm
 *   strncpy  0x02094860  arm
 *   strstr  0x02094B20  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   DWC_Http_Create  0x0217956C  arm  ov009
 *   DWC_Auth_GetCalInfoFromNVRAM  0x02178F4C  arm  ov009
 *   DWC_Auth_SetCalInfoToHttp  0x02179218  arm  ov009
 *   DWC_Http_Add_PostBase64Item  0x02179F3C  arm  ov009
 *   DWC_Http_Add_Body  0x0217A044  arm  ov009
 *   wcscpy  0x02096594  arm
 *   DWC_Free  0x0205A1B0  arm
 *   DWC_Http_FinishHeader  0x0217967C  arm  ov009
 *   OS_GetThreadPriority  0x02085A30  arm
 *   DWC_Http_StartThread  0x02179718  arm  ov009
 *   DWC_Http_Destroy  0x02179CF4  arm  ov009
 *   DWCi_Prof_Alloc  0x0217C050  arm  ov009
 *   DWCi_Prof_Free  0x0217C060  arm  ov009
 *   gDwcProfWorkarea     0x021ACEF0  data ov009
 *   gDwcHttpParamArg     0x021A2358  data ov009
 *   gDwcProfPathAc     0x021A27D8  data ov009
 *   gDwcProfPathPr     0x021A27E0  data ov009
 *   gDwcAuthAllowEssId     0x021ACE70  data ov009
 *   gDwcProfPostLabelWregion     0x021A27E4  data ov009
 *   gDwcProfPostLabelWenc     0x021A27EC  data ov009
 *   gDwcProfPostValueUtf16le     0x021A27F4  data ov009
 *   gDwcProfPostLabelWtype     0x021A2800  data ov009
 *   gDwcProfBodyWtype     0x021A2808  data ov009
 *   gDwcProfPostLabelWords     0x021A2810  data ov009
 *   gMslRefToken     0x02150FEC  data
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   DWC_AC_GetApType  0x0205BDD0  arm
 *   DWCi_SetError  0x02059F54  arm
 *   DWC_Http_ParseResult  0x0217A484  arm  ov009
 *   DWC_Http_GetResult  0x0217A728  arm  ov009
 *   DWC_Auth_SetNasTimeDiff  0x02168250  arm  ov009
 *   atoi  0x020964E0  arm
 *   DWC_Http_GetBase64DecodedResult  0x0217A77C  arm  ov009
 *   gDwcProfFieldNames     0x021A27B8  data ov009
 *   gDwcProfLabelDate     0x021A2818  data ov009
 *   gDwcProfLabelHttpResult     0x021A2820  data ov009
 *   errno     0x02153FAC  data
 *   gDwcProfLabelReturnCd     0x021A282C  data ov009
 *   gDwcProfLabelPrWords     0x021A2838  data ov009
 *   DWC_Alloc                    0x0205A16C  arm
 */
#include "../sdk_os.h"

typedef struct DWCHttp {
    char pad0[0x1020];
    int error;
    char pad1024[0xb50];
    OSThread thread;
    char mutex[0x18];
    int abort;
} DWCHttp;

typedef struct DWCProfWorkarea {
    DWCHttp http;
    int http_initialized;
    char url[257];
    char *result;
    int *badwordsnum;
    int wordsnum;
} DWCProfWorkarea;

#include "../types.h"

#include "../sdk_dwc.h"

typedef struct DWCProfFieldNames {
    char *name[8];
} DWCProfFieldNames;

extern int wcslen(const unsigned short *s);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern u8 *strncpy(u8 *dest, const u8 *src, u32 n);
extern unsigned char *strstr(unsigned char *s1, unsigned char *s2);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
extern int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
extern int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int DWC_Http_Add_Body(char *http, char *data);
extern unsigned short *wcscpy(unsigned short *dst, const unsigned short *src);
extern int DWC_Http_FinishHeader(char *http);
extern unsigned long OS_GetThreadPriority(OSThread *thread);
extern void DWC_Http_StartThread(char *http, unsigned long prio);
extern void DWC_Http_Destroy(char *http);
extern int OS_IsThreadTerminated(OSThread *thread);
extern unsigned char DWC_AC_GetApType(void);
extern void DWCi_SetError(int error, int errorCode);
extern int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
extern char *DWC_Http_GetResult(char *http, char *label);
extern int DWC_Auth_SetNasTimeDiff(char *datestr);
extern int atoi(u32 s);
extern int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned int buffer_len);
extern void *DWC_Alloc(int name, unsigned long size);
/* DWC_Free takes a third argument, the allocation size. The callee ignores it. */
extern void DWC_Free(int name, void *ptr, unsigned long size);
int DWCi_CheckProfanityAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, char *region);
/*
 * sdk: DWC_CheckProfanityExAsync (dwc_prof.o) * * The region letter default is the byte at 0x02FFFE0F, a literal address * (no relocation in the object).
 */
int DWC_CheckProfanityExAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
/*
 * sdk: DWC_CheckProfanityProcess (libdwcauth.TWL.HYB.a dwc_prof.o)
 */
int DWC_CheckProfanityProcess(void);
int DWCi_Prof_ParseResponse(void);
static void *DWCi_Prof_Alloc(int name, unsigned long size);
static void DWCi_Prof_Free(int name, void *ptr, unsigned long size);
extern DWCProfWorkarea *gDwcProfWorkarea;
extern DWCAuthHttpParam gDwcHttpParamArg;
extern char gDwcProfPathAc[];
extern char gDwcProfPathPr[];
extern int gDwcAuthAllowEssId;
extern char gDwcProfPostLabelWregion[];
extern char gDwcProfPostLabelWenc[];
extern char gDwcProfPostValueUtf16le[];
extern char gDwcProfPostLabelWtype[];
extern char gDwcProfBodyWtype[];
extern char gDwcProfPostLabelWords[];
extern OSThreadInfo gMslRefToken;
extern const DWCProfFieldNames gDwcProfFieldNames;
extern char gDwcProfLabelDate[];
extern char gDwcProfLabelHttpResult[];
extern int errno;
extern char gDwcProfLabelReturnCd[];
extern char gDwcProfLabelPrWords[];

/*
 * sdk:      DWCi_CheckProfanityAsync (libdwcauth.TWL.HYB.a dwc_prof.o)
 *
 * The object is stamped 4.0.0.1025; built with dsi/1.1p1.
 *
 * All 40 relocations resolve.  The last one to close was the wide-string copy
 * at arm9 0x02096594 (PC24 at +0x2C8): the second unlabelled leaf trailing
 * fwide's word run, which no `label`/`literal`/`sole-ref` class could
 * see because the listing has it as bare `.word`s.  Reproducing it as
 * src/matched/arm9/wcscpy.c (EXACT) gave the `matched` class the
 * witness, the same route wcslen already had.
 */
int DWCi_CheckProfanityAsync(unsigned short **words, int wordsnum, char *reserved, int timeout,
                  char *result, int *badwordsnum, char *region)
{
    DWCHttpParam httpparam;
    DWCCalInfo calinfo;
    int totalnum_wchar;
    int wchar_index;
    int i;
    unsigned short *sendstring = 0;
    char *pos;

    if (words == 0 || wordsnum <= 0 || wordsnum > 50 || result == 0 || badwordsnum == 0)
        return 0;

    totalnum_wchar = 0;
    for (i = 0; i < wordsnum; i++)
        totalnum_wchar += wcslen(words[i]) + 1;
    if (totalnum_wchar - 1 <= 0 || totalnum_wchar - 1 > 500)
        return 0;

    if (gDwcProfWorkarea != 0)
        return 0;

    MI_CpuFill8(result, 0, wordsnum);
    gDwcProfWorkarea = DWC_Alloc(0, sizeof(DWCProfWorkarea));
    if (gDwcProfWorkarea == 0)
        goto error;
    MI_CpuFill8(gDwcProfWorkarea, 0, sizeof(DWCProfWorkarea));
    gDwcProfWorkarea->http_initialized = 0;
    MI_CpuFill8(&calinfo, 0, sizeof(DWCCalInfo));

    gDwcProfWorkarea->result = result;
    gDwcProfWorkarea->badwordsnum = badwordsnum;
    gDwcProfWorkarea->wordsnum = wordsnum;
    strncpy((u8 *)gDwcProfWorkarea->url, (const u8 *)gDwcHttpParamArg.url, 256);
    gDwcProfWorkarea->url[256] = '\0';
    pos = (char *)strstr((unsigned char *)gDwcProfWorkarea->url, (unsigned char *)gDwcProfPathAc);
    if (pos == 0)
        goto error;
    MI_CpuCopy8(gDwcProfPathPr, pos, 4);

    httpparam.url = gDwcProfWorkarea->url;
    httpparam.action = 0;
    httpparam.len_recvbuf = 0x400;
    httpparam.alloc = (void *(*)(unsigned long, long))DWCi_Prof_Alloc;
    httpparam.free = (void (*)(unsigned long, void *, long))DWCi_Prof_Free;
    httpparam.ignoreca = 0;
    if (timeout <= 0)
        httpparam.timeout = 10000;
    else
        httpparam.timeout = timeout;

    if (DWC_Http_Create(&gDwcProfWorkarea->http, &httpparam) != 0)
        goto error;
    gDwcProfWorkarea->http_initialized = 1;

    if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo))
        goto error;
    if (!DWC_Auth_SetCalInfoToHttp(&gDwcProfWorkarea->http, &calinfo, gDwcAuthAllowEssId))
        goto error;
    if (DWC_Http_Add_PostBase64Item(&gDwcProfWorkarea->http, gDwcProfPostLabelWregion, region, 1) != 0)
        goto error;
    if (DWC_Http_Add_PostBase64Item(&gDwcProfWorkarea->http, gDwcProfPostLabelWenc, gDwcProfPostValueUtf16le, 8) != 0)
        goto error;
    if (reserved != 0) {
        if (DWC_Http_Add_PostBase64Item(&gDwcProfWorkarea->http, gDwcProfPostLabelWtype, reserved, 4) != 0)
            goto error;
    }
    if (DWC_Http_Add_Body((char *)(&gDwcProfWorkarea->http), gDwcProfBodyWtype) != 0)
        goto error;

    sendstring = DWC_Alloc(0, totalnum_wchar * sizeof(unsigned short));
    if (sendstring == 0)
        goto error;
    wchar_index = 0;
    for (i = 0; i < wordsnum; i++) {
        wcscpy(&sendstring[wchar_index], words[i]);
        wchar_index += wcslen(words[i]);
        if (wchar_index >= totalnum_wchar - 1)
            break;
        sendstring[wchar_index++] = L'\t';
    }

    if (DWC_Http_Add_PostBase64Item(&gDwcProfWorkarea->http, gDwcProfPostLabelWords, (char *)sendstring,
                      (totalnum_wchar - 1) * sizeof(unsigned short)) != 0)
        goto error;
    DWC_Free(0, sendstring, 0);
    sendstring = 0;

    if (DWC_Http_FinishHeader((char *)(&gDwcProfWorkarea->http)) != 0)
        goto error;
    DWC_Http_StartThread((char *)(&gDwcProfWorkarea->http), OS_GetThreadPriority(gMslRefToken.current) - 1);
    if (gDwcProfWorkarea->http.thread.id != 0)
        return 1;

error:
    if (sendstring != 0)
        DWC_Free(0, sendstring, 0);
    if (gDwcProfWorkarea != 0) {
        if (gDwcProfWorkarea->http_initialized == 1)
            DWC_Http_Destroy((char *)(&gDwcProfWorkarea->http));
        DWC_Free(0, gDwcProfWorkarea, 0);
        gDwcProfWorkarea = 0;
    }
    return 0;
}

/*
 * sdk:      DWC_CheckProfanityExAsync (dwc_prof.o)
 *
 * The region letter default is the byte at 0x02FFFE0F, a literal address
 * (no relocation in the object).
 */
int DWC_CheckProfanityExAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region)
{
    char regionLetter;

    if (region == 0x80) {
        regionLetter = 'A';
    } else {
        regionLetter = *(char *)0x02FFFE0F;
    }
    return DWCi_CheckProfanityAsync(words, wordsnum, reserved, timeout, result, badwordsnum, &regionLetter);
}

/*
 * sdk:      DWC_CheckProfanityProcess (libdwcauth.TWL.HYB.a dwc_prof.o)
 */
int DWC_CheckProfanityProcess(void)
{
    int retval;
    unsigned char aptype;

    if (gDwcProfWorkarea == 0 || gDwcProfWorkarea->http.thread.id == 0)
        return 0;
    if (OS_IsThreadTerminated(&gDwcProfWorkarea->http.thread) == 1) {
        aptype = DWC_AC_GetApType();
        if (aptype == 0xff || aptype > 99)
            aptype = 99;

        switch (gDwcProfWorkarea->http.error) {
        case 8:
            if (DWCi_Prof_ParseResponse() == 0)
                retval = 3;
            else
                retval = 2;
            break;
        case 2:
            DWCi_SetError(8, -52100 - aptype);
            retval = 3;
            break;
        case 3:
        case 4:
        case 6:
            DWCi_SetError(18, -33010);
            retval = 3;
            break;
        default:
            DWCi_SetError(18, -33030);
            retval = 3;
            break;
        }
    } else {
        return 1;
    }

    DWC_Http_Destroy((char *)(&gDwcProfWorkarea->http));
    DWC_Free(0, gDwcProfWorkarea, 0);
    gDwcProfWorkarea = 0;
    return retval;
}

/*
 * sdk:      DWCi_Prof_ParseResponse (libdwcauth.TWL.HYB.a dwc_prof.o)
 */
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

    strp = DWC_Http_GetResult((char *)DWChttp, gDwcProfLabelDate);
    if (strp != 0)
        DWC_Auth_SetNasTimeDiff(strp);

    strp = DWC_Http_GetResult((char *)DWChttp, gDwcProfLabelHttpResult);
    if (strp == 0)
        goto error;
    httpretcode = atoi((u32)strp);
    if (errno == 34 || httpretcode != 200)
        goto error;

    if (DWC_Http_GetBase64DecodedResult((char *)DWChttp, gDwcProfLabelReturnCd, retcode, 4) <= 0)
        goto error;
    httpretcode = atoi((u32)retcode);
    if (errno == 34)
        goto error;
    if (httpretcode == 1 || (httpretcode >= 100 && httpretcode != 100)) {
        DWCi_SetError(17, -33000 - httpretcode);
        return 0;
    }

    for (i = 0; i < sizeof(regionResultFieldName.name) / sizeof(char *) - 1; i++) {
        if (regionResultFieldName.name[i] == 0)
            continue;
        decodedStringLength = DWC_Http_GetBase64DecodedResult((char *)DWChttp, regionResultFieldName.name[i], result, sizeof(result));
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

    decodedStringLength = DWC_Http_GetBase64DecodedResult((char *)DWChttp, gDwcProfLabelPrWords, result, sizeof(result));
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
    DWCi_SetError(17, -33020);
    return 0;
}

static void *DWCi_Prof_Alloc(int name, unsigned long size)
{
    return DWC_Alloc(0, size);
}

static void DWCi_Prof_Free(int name, void *ptr, unsigned long size)
{
    DWC_Free(0, ptr, size);
}
