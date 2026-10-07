/*
 * file:     unit_0217B828_p01.c
 * unit:     yes
 * function: func_0217BC44, func_0217BC90
 * address:  0x0217BC44
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
 *   func_0217B828  0x0217B828  arm  ov009
 *   func_0208574C  0x0208574C  arm
 *   func_0205BDD0  0x0205BDD0  arm
 *   func_0217BDA8  0x0217BDA8  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   func_02179CF4  0x02179CF4  arm  ov009
 *   func_0205A1B0  0x0205A1B0  arm
 *   g_021ACEF0     0x021ACEF0  data ov009
 */
typedef struct OSThread {
    char pad0[0x6c];
    int id;
    char pad70[0x50];
} OSThread;

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

extern int func_0217B828(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, char *region);
extern int func_0208574C(OSThread *thread);
extern unsigned char func_0205BDD0(void);
extern int func_0217BDA8(void);
extern void func_02059F54(int error, int errorCode);
extern void func_02179CF4(char *http);
extern void func_0205A1B0(int name, void *ptr, long size);
int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
int func_0217BC90(void);
extern DWCProfWorkarea *g_021ACEF0;


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
