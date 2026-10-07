/*
 * file:     unit_021DEE3C_p03.c
 * unit:     yes
 * function: func_021DF110, func_021DF130, func_021DF1A8, func_021DF1C8, func_021DF20C, func_021DF224, func_021DF23C, func_021DF298
 * address:  0x021DF110
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
 *   g_021E4D08  0x021E4D08  data
 *   d_021E4D1C     0x021E4D1C  data
 *   d_021E4F34     0x021E4F34  data
 *   func_021DFBB8  0x021DFBB8  arm  ov175
 *   func_021DFAA8   0x021DFAA8  arm  ov175
 *   func_021DF644   0x021DF644  arm  ov175
 *   func_02059F54   0x02059F54  arm
 *   s_callback         0x021e4d08  data
 *   scGetConnectionId  0x021dfa98  data  ov175
 *   func_021DFAA0  0x021DFAA0  arm  ov175
 *   func_021DFC8C  0x021DFC8C  arm  ov175
 *   func_021DFCE8  0x021DFCE8  arm
 */
typedef unsigned int u32_021DF110;

typedef unsigned int u32_021DF130;

typedef unsigned long u32_021DF1A8;

typedef unsigned int u32_021DF1C8;

typedef struct {
    u32_021DF1C8 f0;
    u32_021DF1C8 f4;
} Slot;

typedef unsigned int u32_021DF224;

typedef unsigned int u32_021DF23C;

typedef unsigned int   u32_021DF298;

extern int func_021DFBB8(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate, void *thePrivateData, void *theCallback, unsigned int theTimeoutMs, void *theUserData);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);
extern int func_021DFAA8(char *a, int b);
extern unsigned char *scGetConnectionId(int);
extern u32_021DF224 func_021DFAA0(u32_021DF224 p);
extern int func_021DFC8C(u32_021DF23C *p, int a1, int a2, int a3, void **out);
extern int func_021DFCE8(u32_021DF298 *a0);
void func_021DF110(int a, int b, int c, int d);
int func_021DF130(u32_021DF130 a0, u32_021DF130 a1, u32_021DF130 a2, u32_021DF130 a3, char *a4);
void func_021DF1A8(int a, int b, int c, int d);
u32_021DF1C8 func_021DF1C8(u32_021DF1C8 a);
unsigned char *DWC_ScGetConnectionId(void);
void func_021DF224(void);
int func_021DF23C(u32_021DF23C a0, u32_021DF23C a1, u32_021DF23C a2, u32_021DF23C a3);
int func_021DF298(u32_021DF298 *a0);
extern u32_021DF110 g_021E4D08[];
extern char d_021E4D1C[];
extern char d_021E4F34[];
extern int s_callback[];


void func_021DF110(int a, int b, int c, int d)
{
    ((void (*)(int, int))g_021E4D08[3])(c, d);
}


/*
 * SDK provenance: DWC_ScSubmitReportAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the report payload, then forward to scSubmitReport
 * with the fixed endpoint pair and this file's callback.
 */
int func_021DF130(u32_021DF130 a0, u32_021DF130 a1, u32_021DF130 a2, u32_021DF130 a3, char *a4)
{
    int r;

    g_021E4D08[4] = a2;
    r = func_021DFBB8((u32_021DF130 *)g_021E4D08[1], (void *)a0, a1, (void *)((u32_021DF130)d_021E4F34),
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
    void (*fn)(int, int) = (void (*)(int, int))g_021E4D08[4];

    fn(c, d);
}


u32_021DF1C8 func_021DF1C8(u32_021DF1C8 a)
{
    Slot *t = (Slot *)g_021E4D08;
    u32_021DF1C8 r5 = func_021DFAA8((char *)t->f4, a);

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


unsigned char *DWC_ScGetConnectionId(void)
{
    return scGetConnectionId(s_callback[1]);
}


/*
 * One-line tail thunk: the object's +4 word is forwarded to the +0x84 accessor
 * that sits at the tail of func_021DFA6C's extent.
 */
void func_021DF224(void)
{
    func_021DFAA0(g_021E4D08[1]);
}


/*
 * SDK provenance: DWC_ScCreateReport (TwlDWC/libdwcsc.TWL.HYB.a, dwc_sc.o),
 * ov175.  Forward to scCreateReport on the live session and log a failure.
 */
int func_021DF23C(u32_021DF23C a0, u32_021DF23C a1, u32_021DF23C a2, u32_021DF23C a3)
{
    int r;

    r = func_021DFC8C((u32_021DF23C *)g_021E4D08[1], a0, a1, a2, (void **)a3);
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
