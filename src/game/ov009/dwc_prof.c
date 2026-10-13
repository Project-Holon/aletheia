/*
 * file:     dwc_prof.c
 * unit:     yes
 * function: func_0217B828, func_0217BC44, func_0217BC90, func_0217BDA8, DWCi_Prof_Alloc, DWCi_Prof_Free
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
 *   func_02096578  0x02096578  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0205A16C  0x0205A16C  arm
 *   func_02094860  0x02094860  arm
 *   func_02094B20  0x02094B20  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0217956C  0x0217956C  arm  ov009
 *   func_02178F4C  0x02178F4C  arm  ov009
 *   func_02179218  0x02179218  arm  ov009
 *   func_02179F3C  0x02179F3C  arm  ov009
 *   func_0217A044  0x0217A044  arm  ov009
 *   func_02096594  0x02096594  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_0217967C  0x0217967C  arm  ov009
 *   OS_GetThreadPriority  0x02085A30  arm
 *   func_02179718  0x02179718  arm  ov009
 *   func_02179CF4  0x02179CF4  arm  ov009
 *   func_0217C050  0x0217C050  arm  ov009
 *   func_0217C060  0x0217C060  arm  ov009
 *   g_021ACEF0     0x021ACEF0  data ov009
 *   g_021A2358     0x021A2358  data ov009
 *   g_021A27D8     0x021A27D8  data ov009
 *   g_021A27E0     0x021A27E0  data ov009
 *   g_021ACE70     0x021ACE70  data ov009
 *   g_021A27E4     0x021A27E4  data ov009
 *   g_021A27EC     0x021A27EC  data ov009
 *   g_021A27F4     0x021A27F4  data ov009
 *   g_021A2800     0x021A2800  data ov009
 *   g_021A2808     0x021A2808  data ov009
 *   g_021A2810     0x021A2810  data ov009
 *   g_02150FEC     0x02150FEC  data
 *   func_0208574C  0x0208574C  arm
 *   func_0205BDD0  0x0205BDD0  arm
 *   func_02059F54  0x02059F54  arm
 *   func_0217A484  0x0217A484  arm  ov009
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   g_021A27B8     0x021A27B8  data ov009
 *   g_021A2818     0x021A2818  data ov009
 *   g_021A2820     0x021A2820  data ov009
 *   g_02153FAC     0x02153FAC  data
 *   g_021A282C     0x021A282C  data ov009
 *   g_021A2838     0x021A2838  data ov009
 *   DWC_Alloc                    0x0205A16C  arm
 */
typedef struct OSThread {
    char pad0[0x6c];
    int id;
    char pad70[0x50];
} OSThread;

typedef struct OSThreadInfo {
    unsigned short isNeedRescheduling;
    unsigned short irqDepth;
    OSThread *current;
} OSThreadInfo;

typedef struct DWCHttp {
    char pad0[0x1020];
    int error;
    char pad1024[0xb50];
    OSThread thread;
    char mutex[0x18];
    int abort;
} DWCHttp;

typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct DWCCalInfo {
    char userid[14];
    char passwd[7];
    char gamecd[5];
    char makercd[3];
    char unitcd[2];
    char macadr[13];
    char lang[3];
    char birth[5];
    char devtime[13];
    char bssid[13];
    char ssid[33];
    char apinfo[14];
    unsigned short devname[11];
} DWCCalInfo;

typedef struct DWCProfWorkarea {
    DWCHttp http;
    int http_initialized;
    char url[257];
    char *result;
    int *badwordsnum;
    int wordsnum;
} DWCProfWorkarea;

typedef struct DWCAuthHttpParam {
    char *url;
} DWCAuthHttpParam;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct DWCProfFieldNames {
    char *name[8];
} DWCProfFieldNames;

extern int func_02096578(const unsigned short *s);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void *func_0205A16C(int name, unsigned long size);
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern char *func_02094B20(const char *s1, const char *s2);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern int func_0217956C(DWCHttp *http, DWCHttpParam *param);
extern int func_02178F4C(void *cal);
extern int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int func_02179F3C(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int func_0217A044(char *http, char *data);
extern unsigned short *func_02096594(unsigned short *dst, const unsigned short *src);
extern void func_0205A1B0(int name, void *ptr, long size);
extern int func_0217967C(char *http);
extern unsigned long OS_GetThreadPriority(OSThread *thread);
extern void func_02179718(char *http, unsigned long prio);
extern void func_02179CF4(char *http);
extern void *func_0217C050(unsigned long name, long size);
extern void func_0217C060(unsigned long name, void *ptr, long size);
extern int func_0208574C(OSThread *thread);
extern unsigned char func_0205BDD0(void);
extern void func_02059F54(int error, int errorCode);
extern int func_0217A484(DWCHttp *http, int noparsebody);
extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
extern int func_020964E0(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
extern void *DWC_Alloc(int name, unsigned long size);
int func_0217B828(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, char *region);
/*
 * sdk: DWC_CheckProfanityExAsync (dwc_prof.o) * * The region letter default is the byte at 0x02FFFE0F, a literal address * (no relocation in the object).
 */
int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
/*
 * sdk: DWC_CheckProfanityProcess (libdwcauth.TWL.HYB.a dwc_prof.o)
 */
int func_0217BC90(void);
int func_0217BDA8(void);
static void *DWCi_Prof_Alloc(int name, unsigned long size);
extern DWCProfWorkarea *g_021ACEF0;
extern DWCAuthHttpParam g_021A2358;
extern char g_021A27D8[];
extern char g_021A27E0[];
extern int g_021ACE70;
extern char g_021A27E4[];
extern char g_021A27EC[];
extern char g_021A27F4[];
extern char g_021A2800[];
extern char g_021A2808[];
extern char g_021A2810[];
extern OSThreadInfo g_02150FEC;
extern const DWCProfFieldNames g_021A27B8;
extern char g_021A2818[];
extern char g_021A2820[];
extern int g_02153FAC;
extern char g_021A282C[];
extern char g_021A2838[];




/*
 * sdk:      DWCi_CheckProfanityAsync (libdwcauth.TWL.HYB.a dwc_prof.o)
 *
 * The object is stamped 4.0.0.1025; built with dsi/1.1p1.
 *
 * All 40 relocations resolve.  The last one to close was the wide-string copy
 * at arm9 0x02096594 (PC24 at +0x2C8): the second unlabelled leaf trailing
 * func_02096508's word run, which no `label`/`literal`/`sole-ref` class could
 * see because the listing has it as bare `.word`s.  Reproducing it as
 * src/matched/arm9/func_02096594.c (EXACT) gave the `matched` class the
 * witness, the same route func_02096578 already had.
 */
int func_0217B828(unsigned short **words, int wordsnum, char *reserved, int timeout,
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
        totalnum_wchar += func_02096578(words[i]) + 1;
    if (totalnum_wchar - 1 <= 0 || totalnum_wchar - 1 > 500)
        return 0;

    if (g_021ACEF0 != 0)
        return 0;

    MI_CpuFill8(result, 0, wordsnum);
    g_021ACEF0 = func_0205A16C(0, sizeof(DWCProfWorkarea));
    if (g_021ACEF0 == 0)
        goto error;
    MI_CpuFill8(g_021ACEF0, 0, sizeof(DWCProfWorkarea));
    g_021ACEF0->http_initialized = 0;
    MI_CpuFill8(&calinfo, 0, sizeof(DWCCalInfo));

    g_021ACEF0->result = result;
    g_021ACEF0->badwordsnum = badwordsnum;
    g_021ACEF0->wordsnum = wordsnum;
    func_02094860((u8 *)g_021ACEF0->url, (const u8 *)g_021A2358.url, 256);
    g_021ACEF0->url[256] = '\0';
    pos = func_02094B20(g_021ACEF0->url, g_021A27D8);
    if (pos == 0)
        goto error;
    func_02082D44(g_021A27E0, pos, 4);

    httpparam.url = g_021ACEF0->url;
    httpparam.action = 0;
    httpparam.len_recvbuf = 0x400;
    httpparam.alloc = func_0217C050;
    httpparam.free = func_0217C060;
    httpparam.ignoreca = 0;
    if (timeout <= 0)
        httpparam.timeout = 10000;
    else
        httpparam.timeout = timeout;

    if (func_0217956C(&g_021ACEF0->http, &httpparam) != 0)
        goto error;
    g_021ACEF0->http_initialized = 1;

    if (!func_02178F4C(&calinfo))
        goto error;
    if (!func_02179218(&g_021ACEF0->http, &calinfo, g_021ACE70))
        goto error;
    if (func_02179F3C(&g_021ACEF0->http, g_021A27E4, region, 1) != 0)
        goto error;
    if (func_02179F3C(&g_021ACEF0->http, g_021A27EC, g_021A27F4, 8) != 0)
        goto error;
    if (reserved != 0) {
        if (func_02179F3C(&g_021ACEF0->http, g_021A2800, reserved, 4) != 0)
            goto error;
    }
    if (func_0217A044((char *)(&g_021ACEF0->http), g_021A2808) != 0)
        goto error;

    sendstring = func_0205A16C(0, totalnum_wchar * sizeof(unsigned short));
    if (sendstring == 0)
        goto error;
    wchar_index = 0;
    for (i = 0; i < wordsnum; i++) {
        func_02096594(&sendstring[wchar_index], words[i]);
        wchar_index += func_02096578(words[i]);
        if (wchar_index >= totalnum_wchar - 1)
            break;
        sendstring[wchar_index++] = L'\t';
    }

    if (func_02179F3C(&g_021ACEF0->http, g_021A2810, (char *)sendstring,
                      (totalnum_wchar - 1) * sizeof(unsigned short)) != 0)
        goto error;
    func_0205A1B0(0, sendstring, 0);
    sendstring = 0;

    if (func_0217967C((char *)(&g_021ACEF0->http)) != 0)
        goto error;
    func_02179718((char *)(&g_021ACEF0->http), OS_GetThreadPriority(g_02150FEC.current) - 1);
    if (g_021ACEF0->http.thread.id != 0)
        return 1;

error:
    if (sendstring != 0)
        func_0205A1B0(0, sendstring, 0);
    if (g_021ACEF0 != 0) {
        if (g_021ACEF0->http_initialized == 1)
            func_02179CF4((char *)(&g_021ACEF0->http));
        func_0205A1B0(0, g_021ACEF0, 0);
        g_021ACEF0 = 0;
    }
    return 0;
}





/*
 * sdk:      DWC_CheckProfanityExAsync (dwc_prof.o)
 *
 * The region letter default is the byte at 0x02FFFE0F, a literal address
 * (no relocation in the object).
 */
int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region)
{
    char regionLetter;

    if (region == 0x80) {
        regionLetter = 'A';
    } else {
        regionLetter = *(char *)0x02FFFE0F;
    }
    return func_0217B828(words, wordsnum, reserved, timeout, result, badwordsnum, &regionLetter);
}





/*
 * sdk:      DWC_CheckProfanityProcess (libdwcauth.TWL.HYB.a dwc_prof.o)
 */
int func_0217BC90(void)
{
    int retval;
    unsigned char aptype;

    if (g_021ACEF0 == 0 || g_021ACEF0->http.thread.id == 0)
        return 0;
    if (func_0208574C(&g_021ACEF0->http.thread) == 1) {
        aptype = func_0205BDD0();
        if (aptype == 0xff || aptype > 99)
            aptype = 99;

        switch (g_021ACEF0->http.error) {
        case 8:
            if (func_0217BDA8() == 0)
                retval = 3;
            else
                retval = 2;
            break;
        case 2:
            func_02059F54(8, -52100 - aptype);
            retval = 3;
            break;
        case 3:
        case 4:
        case 6:
            func_02059F54(18, -33010);
            retval = 3;
            break;
        default:
            func_02059F54(18, -33030);
            retval = 3;
            break;
        }
    } else {
        return 1;
    }

    func_02179CF4((char *)(&g_021ACEF0->http));
    func_0205A1B0(0, g_021ACEF0, 0);
    g_021ACEF0 = 0;
    return retval;
}



/*
 * sdk:      DWCi_Prof_ParseResponse (libdwcauth.TWL.HYB.a dwc_prof.o)
 */
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

static void *DWCi_Prof_Alloc(int name, unsigned long size)
{
    return DWC_Alloc(0, size);
}

extern void DWC_Free(int name, void *ptr, unsigned long size);
static void DWCi_Prof_Free(int name, void *ptr, unsigned long size)
{
    DWC_Free(0, ptr, size);
}
