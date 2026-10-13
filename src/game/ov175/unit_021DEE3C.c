/*
 * file:     unit_021DEE3C.c
 * unit:     yes
 * function: func_021DEE3C, func_021DEF58, func_021DEFC4, func_021DEFDC, func_021DF018, func_021DF07C, func_021DF09C, func_021DF110, func_021DF130, func_021DF1A8, func_021DF1C8, func_021DF20C, func_021DF224, func_021DF23C, func_021DF298, func_021DF2C8, func_021DF2F8, func_021DF328, func_021DF358, func_021DF3B0, func_021DF3E8, func_021DF420, func_021DF458, func_021DF490, func_021DF4A4, func_021DF4FC, func_021DF5E4, func_021DF644, func_021DF65C, func_021DF734
 * address:  0x021DEE3C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217CA40  0x0217CA40  arm  ov009
 *   func_0216AA9C  0x0216AA9C  arm  ov009
 *   func_021E2510  0x021E2510  arm  ov175
 *   func_02059F54  0x02059F54  arm
 *   func_02085A38  0x02085A38  arm
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   func_02059E18  0x02059E18  arm
 *   func_021DF9D8  0x021DF9D8  arm  ov175
 *   g_021E4D08  0x021E4D08  data
 *   g_021E3F48  0x021E3F48  data
 *   g_021E4D0C  0x021E4D0C  data
 *   func_021E22E4  0x021E22E4  arm  ov175
 *   func_021DFE20  0x021DFE20  arm  ov175
 *   func_021BF540  0x021BF540  arm  ov114
 *   func_021DFA6C  0x021DFA6C  arm
 *   d_021E4F34     0x021E4F34  data
 *   d_021E4D1C     0x021E4D1C  data
 *   func_021DFB18  0x021DFB18  arm  ov175
 *   func_021DFBB8  0x021DFBB8  arm  ov175
 *   func_021DFAA8   0x021DFAA8  arm  ov175
 *   s_callback         0x021e4d08  data
 *   scGetConnectionId  0x021dfa98  data  ov175
 *   func_021DFAA0  0x021DFAA0  arm  ov175
 *   func_021DFC8C  0x021DFC8C  arm  ov175
 *   func_021DFCE8  0x021DFCE8  arm
 *   func_021DFCF4  0x021DFCF4  arm
 *   func_021DFD00  0x021DFD00  arm
 *   func_021DFD0C  0x021DFD0C  arm
 *   func_021DFD24  0x021DFD24  arm
 *   func_021DFD18  0x021DFD18  arm
 *   func_021DFDFC  0x021DFDFC  arm
 *   func_021DFE08  0x021DFE08  arm
 *   func_021DFE14  0x021DFE14  arm
 *   func_02084F80  0x02084F80  arm
 *   func_02084FA8  0x02084FA8  arm
 *   g_021E3F68  0x021E3F68  data
 *   func_021BF8C0  0x021BF8C0  arm  ov114
 *   unit_02092344  0x02092344  arm
 *   g_021E3F74  0x021E3F74  data
 *   g_021E3FA0  0x021E3FA0  data
 *   g_021E4F34  0x021E4F34  data
 *   g_021E4D1C  0x021E4D1C  data
 *   g_021E3FCC  0x021E3FCC  data
 *   func_021BF520  0x021BF520  arm  ov114
 *   g_021E52B4  0x021E52B4  data
 *   g_021AE01C  0x021AE01C  data
 *   g_021E3FE8  0x021E3FE8  data
 *   g_021E53BC  0x021E53BC  data
 *   g_021E4040  0x021E4040  data
 *   g_021E408C  0x021E408C  data
 *   g_021E40E4  0x021E40E4  data
 */
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
typedef void (*ScCallback)(int, int);

typedef struct ScControl {
    int state;
    void *session;
    ScCallback onSession;
    ScCallback onIntention;
    ScCallback onReport;
} ScControl;

typedef unsigned int   u32;

typedef signed int     s32_021DEF58;

typedef int s32_021DEFDC;

typedef unsigned int u32_021DEFDC;

typedef unsigned int u32_021DF018;

typedef unsigned long u32_021DF07C;

typedef unsigned int u32_021DF09C;

typedef unsigned int u32_021DF110;

typedef unsigned int u32_021DF130;

typedef unsigned long u32_021DF1A8;

typedef unsigned int u32_021DF1C8;

typedef unsigned int u32_021DF224;

typedef unsigned int u32_021DF23C;

typedef unsigned int   u32_021DF298;

typedef unsigned char  u8;

typedef int s32;

typedef char *va_list;

typedef struct {
	int result;
	int pad;
	char cert[0x380];
	char priv[0x218];
} WSLoginResponse;

extern void func_0217CA40(void);
extern int func_0216AA9C(char **authToken, char **partnerChallenge);
extern int func_021E2510(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge, void *userCallback, void *userData);
extern void func_02059F54(int error, int errorCode);
extern void func_02085A38(unsigned long msec);
extern void func_0217CCCC(unsigned int theMS);
extern int func_02059E18(int *errorCode);
extern int func_021DF9D8(u32 *p, u32 *out);
extern int func_021DFA3C(void *);
extern void func_0217CD94(void);
extern int func_0217CE1C(void);
extern s32_021DEF58 func_021E22E4(void);
extern int func_021BF540(void);
extern void func_021DFE20(void);
extern int func_021DFA6C(int *p);
extern int func_021DFAB8(u32_021DF018 *, u32_021DF018, u32_021DF018, u32_021DF018, u32_021DF018, u32_021DF018);
extern int func_021DFB18(int *ctx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern int func_021DFBB8(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate, void *thePrivateData, void *theCallback, unsigned int theTimeoutMs, void *theUserData);
extern int func_021DFAA8(char *a, int b);
extern unsigned char *scGetConnectionId(void *);
extern u32_021DF224 func_021DFAA0(u32_021DF224 p);
extern int func_021DFC8C(u32_021DF23C *p, int a1, int a2, int a3, void **out);
extern int func_021DFCE8(u32_021DF298 *a0);
extern int func_021DFCF4(u32 *a0);
extern int func_021DFD00(u32 *a0);
extern int func_021DFD0C(u8 *a0);
extern int func_021DFD24(void *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId, unsigned int thePlayerTeamId, int theResult, int unused, void *theCertificate, unsigned char *theAuthHash);
extern s32 func_021DFD18(s32);
extern s32 func_021DFDFC(s32);
extern s32 func_021DFE08(s32);
extern int func_021DFE14(u32 *a0);
extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern int func_02084FA8(char *s, unsigned int n, const char *format, void *arg);
extern int func_021BF8C0(int result);
extern void *unit_02092344(void *dst, void *src, unsigned long n);
extern int func_021BF520(int a);
int func_021DEE3C(int theGameId, int ssl_type);
int func_021DEF58(void);
void func_021DEFC4(void);
s32_021DEFDC func_021DEFDC(void);
int func_021DF018(ScCallback a0, u32_021DF018 a1, u32_021DF018 a2);
void func_021DF07C(u32_021DF07C a, u32_021DF07C b, u32_021DF07C c, u32_021DF07C d);
int func_021DF09C(u32_021DF09C a0, ScCallback a1, u32_021DF09C a2, u32_021DF09C a3);
void func_021DF110(int a, int b, int c, int d);
int func_021DF130(u32_021DF130 a0, u32_021DF130 a1, ScCallback a2, u32_021DF130 a3, char *a4);
void func_021DF1A8(int a, int b, int c, int d);
u32_021DF1C8 func_021DF1C8(u32_021DF1C8 a);
unsigned char *DWC_ScGetSessionId(void);
void func_021DF224(void);
int func_021DF23C(u32_021DF23C a0, u32_021DF23C a1, u32_021DF23C a2, u32_021DF23C a3);
int func_021DF298(u32_021DF298 *a0);
int func_021DF2C8(u32 *a0);
int func_021DF2F8(u32 *a0);
int func_021DF328(u8 *a0);
s32 func_021DF358(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, char *a5, s32 a6);
s32 func_021DF3B0(s32 a);
s32 func_021DF3E8(s32 a, int a1, int a2);
s32 func_021DF420(s32 a, int a1, int a2);
s32 func_021DF458(u32 *a);
int func_021DF490(void **p);
void func_021DF4A4(int line, char *fmt, ...);
void func_021DF4FC(int httpResult, WSLoginResponse *theResponse);
s32 func_021DF5E4(s32 a);
int func_021DF644(int a, int b);
int func_021DF65C(int result);
void func_021DF734(int ssl_type);
extern ScControl g_021E4D08;
extern char g_021E3F48[];
extern void *g_021E4D0C;
extern char d_021E4F34[];
extern char d_021E4D1C[];
extern char g_021E3F68[];
extern char g_021E3F74[];
extern char g_021E3FA0[];
extern char g_021E4F34[];
extern char g_021E4D1C[];
extern char g_021E3FCC[];
extern char g_021E52B4[];
extern char g_021AE01C[];
extern char g_021E3FE8[];
extern char g_021E53BC[];
extern char g_021E4040[];
extern char g_021E408C[];
extern char g_021E40E4[];



/*
 * sdk:      DWC_ScInitialize (libdwcsc.TWL.HYB.a dwc_sc.o)
 */
int func_021DEE3C(int theGameId, int ssl_type)
{
    unsigned int gsResult;
    int result;
    char *authToken;
    char *partnerChallenge;

    func_0217CA40();
    func_021DF734(ssl_type);
    func_0216AA9C(&authToken, &partnerChallenge);
    g_021E4D08.state = 0;
    result = func_021E2510(0, theGameId, authToken, partnerChallenge,
                           (void (*)(int, void *, void *))func_021DF4FC, 0);
    if (result != 0) {
        func_021DF4A4(0x8e, g_021E3F48, result);
        func_02059F54(0x14, func_021DF644(1, 0));
        return 7;
    }
    while (g_021E4D08.state == 0) {
        func_02085A38(10);
        func_0217CCCC(0);
    }
    if (func_02059E18(0) != 0)
        return 7;
    gsResult = func_021DF9D8((u32 *)theGameId, (u32 *)(&g_021E4D0C));
    if (gsResult != 0) {
        result = func_021DF5E4(gsResult);
        func_02059F54(result, func_021DF644(2, gsResult));
    }
    return gsResult;
}






int func_021DEF58(void)
{
    int r;

    r = func_021DFA3C((void *)g_021E4D08.session);
    if (r != 0)
        func_02059F54(func_021DF5E4(r), func_021DF644(3, r));
    func_021DEFC4();
    func_0217CD94();
    func_0217CCCC(0);
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
    return r;
}






void func_021DEFC4(void)
{
    func_021E22E4();
    func_021BF540();
    func_021DFE20();
    func_021BF540();
}






/*
 * Same post shape as the func_021DF3B0 triplet, driven by the head of the
 * 0x021E4D08 control block instead of an incoming handle.
 */
s32_021DEFDC func_021DEFDC(void)
{
    s32_021DEFDC v = func_021DFA6C((int *)g_021E4D08.session);

    if (v != 0)
        func_02059F54(8, func_021DF644(4, v));
    return v;
}






/*
 * SDK provenance: DWC_ScCreateSessionAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the console/player context, then forward to
 * scCreateMatchlessSession with the fixed report endpoint and this file's
 * session callback.
 */
int func_021DF018(ScCallback a0, u32_021DF018 a1, u32_021DF018 a2)
{
    int r;

    g_021E4D08.onSession = a0;
    r = func_021DFAB8((u32_021DF018 *)g_021E4D08.session, (u32_021DF018)d_021E4F34, (u32_021DF018)d_021E4D1C,
                      (u32_021DF018)func_021DF07C, a1, a2);
    if (r != 0)
        func_02059F54(8, func_021DF644(5, r));
    return r;
}






/*
 * Dispatches through the function pointer at +8 of the ov175 bss slot
 *  *  0x021E4D08: the first two arguments are dropped, the third and fourth
 *  *  become the callee's arguments.
 */
void func_021DF07C(u32_021DF07C a, u32_021DF07C b, u32_021DF07C c, u32_021DF07C d)
{
    g_021E4D08.onSession(c, d);
}






/*
 * SDK provenance: DWC_ScSetReportIntentionAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the intention/console id, then forward to
 * scSetReportIntention with the fixed endpoint pair and this file's callback.
 */
int func_021DF09C(u32_021DF09C a0, ScCallback a1, u32_021DF09C a2, u32_021DF09C a3)
{
    int r;

    g_021E4D08.onIntention = a1;
    r = func_021DFB18((int *)g_021E4D08.session, 0, a0, (u32_021DF09C)d_021E4F34,
                      (u32_021DF09C)d_021E4D1C, (u32_021DF09C)func_021DF110, a2, a3);
    if (r != 0)
        func_02059F54(8, func_021DF644(7, r));
    return r;
}





void func_021DF110(int a, int b, int c, int d)
{
    g_021E4D08.onIntention(c, d);
}





/*
 * SDK provenance: DWC_ScSubmitReportAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the report payload, then forward to scSubmitReport
 * with the fixed endpoint pair and this file's callback.
 */
int func_021DF130(u32_021DF130 a0, u32_021DF130 a1, ScCallback a2, u32_021DF130 a3, char *a4)
{
    int r;

    g_021E4D08.onReport = a2;
    r = func_021DFBB8((u32_021DF130 *)g_021E4D08.session, (void *)a0, a1, (void *)((u32_021DF130)d_021E4F34),
                      (void *)((u32_021DF130)d_021E4D1C), (void *)((u32_021DF130)func_021DF1A8), a3, (void *)a4);
    if (r != 0)
        func_02059F54(8, func_021DF644(0xb, r));
    return r;
}





/*
 * Invoke the fifth entry of the 0x021E4D08 dispatch block with the caller's
 * third and fourth arguments.
 */
void func_021DF1A8(int a, int b, int c, int d)
{
    g_021E4D08.onReport(c, d);
}





u32_021DF1C8 func_021DF1C8(u32_021DF1C8 a)
{
    u32_021DF1C8 r5 = func_021DFAA8((char *)g_021E4D08.session, a);

    if (r5 != 0) {
        u32_021DF1C8 r4 = 8;

        func_02059F54(r4, func_021DF644(r4, r5));
    }
    return r5;
}





/*
 * EXACT*: the listing extent runs to 92 bytes because the neighbour
 * func_021DF20C is an untraced 5-word blob; the compiled body's 68 bytes
 * all compare equal and all 4 relocation sites resolve.
 */


unsigned char *DWC_ScGetSessionId(void)
{
    return scGetConnectionId(g_021E4D08.session);
}





/*
 * One-line tail thunk: the object's +4 word is forwarded to the +0x84 accessor
 * that sits at the tail of func_021DFA6C's extent.
 */
void func_021DF224(void)
{
    func_021DFAA0((u32)g_021E4D08.session);
}





/*
 * SDK provenance: DWC_ScCreateReport (TwlDWC/libdwcsc.TWL.HYB.a, dwc_sc.o),
 * ov175.  Forward to scCreateReport on the live session and log a failure.
 */
int func_021DF23C(u32_021DF23C a0, u32_021DF23C a1, u32_021DF23C a2, u32_021DF23C a3)
{
    int r;

    r = func_021DFC8C((u32_021DF23C *)g_021E4D08.session, a0, a1, a2, (void **)a3);
    if (r != 0)
        func_02059F54(8, func_021DF644(9, r));
    return r;
}





/*
 * Open the 0x021DFCE8 slot; when it hands back a handle, queue it under category
 * 0x0a and post an 8-byte message.
 */
int func_021DF298(u32_021DF298 *a0)
{
    int r = func_021DFCE8(a0);

    if (r)
        func_02059F54(8, func_021DF644(0xa, r));
    return r;
}



/*
 * Open the 0x021DFCF4 slot; when it hands back a handle, queue it under
 * category 0x0a and post an 8-byte message.
 */
int func_021DF2C8(u32 *a0)
{
    int r = func_021DFCF4(a0);

    if (r)
        func_02059F54(8, func_021DF644(0xa, r));
    return r;
}



/*
 * Open the 0x021DFD00 slot; when it hands back a handle, queue it under
 * category 0x0a and post an 8-byte message.
 */
int func_021DF2F8(u32 *a0)
{
    int r = func_021DFD00(a0);

    if (r)
        func_02059F54(8, func_021DF644(0xa, r));
    return r;
}



/*
 * Open the 0x021DFD0C slot; when it hands back a handle, queue it under category
 * 0x0a and post an 8-byte message.
 */
int func_021DF328(u8 *a0)
{
    int r = func_021DFD0C(a0);

    if (r)
        func_02059F54(8, func_021DF644(0xa, r));
    return r;
}



/*
 * Eight-argument form of the func_021DF3B0 post shape: the four register
 * arguments are forwarded, and the stack arguments become (a4, a5->f18, a5,
 * a6) on the outgoing frame.  Same warning post and same returned handle.
 */
s32 func_021DF358(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, char *a5, s32 a6)
{
    s32 v = func_021DFD24((void *)a0, a1, (unsigned char *)a2, a3, a4, *(s32 *)(a5 + 0x18), (void *)((s32)a5), (unsigned char *)a6);

    if (v != 0)
        func_02059F54(8, func_021DF644(10, v));
    return v;
}



/*
 * Probe-then-post: ask the byte-read entry for the record, and when it came
 * back non-zero post the warning (func_021DF644(10, v)) against the value
 * func_021DF5E4 picked.  The record handle is the return value either way.
 */
s32 func_021DF3B0(s32 a)
{
    s32 v = func_021DFD18(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(10, v));
    return v;
}



s32 func_021DF3E8(s32 a, int a1, int a2)
{
    s32 v = func_021DFDFC(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(10, v));
    return v;
}



/*
 * Sibling of func_021DF3B0 against the func_021DFE08 probe.
 */
s32 func_021DF420(s32 a, int a1, int a2)
{
    s32 v = func_021DFE08(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(10, v));
    return v;
}



/*
 * Sibling of func_021DF3B0 against the func_021DFE14 probe, with warning code
 * 0xd instead of 0xa.
 */
s32 func_021DF458(u32 *a)
{
    s32 v = func_021DFE14(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(0xd, v));
    return v;
}



int func_021DF490(void **p)
{
    *p = d_021E4F34;
    return 0;
}



void func_021DF4A4(int line, char *fmt, ...)
{
	char str_buf[256];
	int str_len;
	va_list args;
	str_len = func_02084F80(str_buf, 256, g_021E3F68, line);
	va_start(args, fmt);
	func_02084FA8(str_buf + str_len, 256 - str_len, fmt, args);
}



/*
 * sdk:      DWCi_ScLoginCallback (libdwcsc.TWL.HYB.a(dwc_sc.o))
 */
void func_021DF4FC(int httpResult, WSLoginResponse *theResponse)
{
	if (httpResult != 0) {
		func_021DF4A4(0x315, g_021E3F74, httpResult);
		if (httpResult == 1)
			func_02059F54(9, func_021DF644(1, 5));
		else
			func_02059F54(0x14, func_021DF644(1, 7));
		func_021BF8C0(httpResult);
	} else if (theResponse->result != 0) {
		func_021DF4A4(0x323, g_021E3FA0, theResponse->result);
		func_021DF65C(theResponse->result);
	} else {
		unit_02092344(g_021E4F34, theResponse->cert, 0x380);
		unit_02092344(g_021E4D1C, theResponse->priv, 0x218);
		func_021DF4A4(0x32b, g_021E3FCC, (char *)theResponse + 0x47);
	}
	g_021E4D08.state = 1;
}



/*
 * ARM jump-table selector over 0..0xe: only two values carry a code of their
 * own (0 and 6), everything else is 0x14.
 */
s32 func_021DF5E4(s32 a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    case 5:
        return 9;
    }
    return 0x14;
}


/*
 * Leaf: -43000 - (a * 100 + b); same 100-byte record stride as the
 *  *  func_021E20B8 family but a different table base.
 */
int func_021DF644(int a, int b)
{
    return -43000 - (a * 100 + b);
}



/*
 * sdk:      DWCi_HandleWSLoginError (libdwcsc.TWL.HYB.a(dwc_sc.o))
 *
 * The prior "case 105..108 is a second jump table" residue was a wrong value
 * set: the switch also has case 1 (the 0..7 table maps 0 to default, 1..7 to
 * the -8 arm). Adding case 1 shifted the switch tree so 105 became a lone node
 * and 106..108 a linear range chain, exactly as the image.
 */
int func_021DF65C(int result)
{
	int dwcError = 20;
	int errorCode = -43000;
	if (result == 0)
		return 0;
	switch (result) {
	case 1: case 2: case 3: case 4: case 5: case 6: case 7:
	case 100: case 101: case 102: case 103:
	case 105: case 106: case 107: case 108:
		errorCode -= 8;
		break;
	case 104:
		dwcError = 9;
		errorCode -= 6;
		break;
	default:
		errorCode -= 15;
		break;
	}
	func_02059F54(dwcError, errorCode);
	return result;
}



/*
 * sdk:      DWCi_ScSetUseSSL (libdwcsc.TWL.HYB.a(dwc_sc.o))
 */
void func_021DF734(int ssl_type)
{
	switch (ssl_type) {
	case 1:
		func_02084F80(g_021E52B4, 128, g_021E3FE8, g_021AE01C);
		func_021BF520((int)g_021E52B4);
		func_02084F80(g_021E53BC, 128, g_021E4040, g_021AE01C);
		func_021BF520((int)g_021E53BC);
		break;
	case 0:
	default:
		func_02084F80(g_021E52B4, 128, g_021E408C, g_021AE01C);
		func_021BF520((int)g_021E52B4);
		func_02084F80(g_021E53BC, 128, g_021E40E4, g_021AE01C);
		func_021BF520((int)g_021E53BC);
		break;
	}
}
