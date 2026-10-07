/*
 * file:     unit_021DEE3C_p02.c
 * unit:     yes
 * function: func_021DEFDC, func_021DF018, func_021DF07C, func_021DF09C
 * address:  0x021DEFDC
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
 *   func_021DFA6C  0x021DFA6C  arm
 *   func_021DF644  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *   g_021E4D08     0x021E4D08  data
 *   d_021E4F34     0x021E4F34  data
 *   d_021E4D1C     0x021E4D1C  data
 *   func_021DF110  0x021DF110  arm  ov175
 *   func_021DFB18  0x021DFB18  arm  ov175
 */
typedef int s32;

typedef unsigned int u32_021DEFDC;

typedef unsigned int u32_021DF018;

typedef unsigned long u32_021DF07C;

typedef struct {
    u32_021DF07C f0;
    u32_021DF07C f4;
    void (*fn)(u32_021DF07C, u32_021DF07C);
} Disp;

typedef unsigned int u32_021DF09C;

extern int func_021DFA6C(int *p);
extern s32 func_021DF644(s32, s32);
extern void func_02059F54(s32, s32);
extern int func_021DFAB8(u32_021DF018 *, u32_021DF018, u32_021DF018, u32_021DF018, u32_021DF018, u32_021DF018);
extern void func_021DF110(int a, int b, int c, int d);
extern int func_021DFB18(int *ctx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
s32 func_021DEFDC(void);
int func_021DF018(u32_021DF018 a0, u32_021DF018 a1, u32_021DF018 a2);
void func_021DF07C(u32_021DF07C a, u32_021DF07C b, u32_021DF07C c, u32_021DF07C d);
int func_021DF09C(u32_021DF09C a0, u32_021DF09C a1, u32_021DF09C a2, u32_021DF09C a3);
extern u32_021DEFDC g_021E4D08[];
extern char d_021E4F34[];
extern char d_021E4D1C[];


/*
 * Same post shape as the func_021DF3B0 triplet, driven by the head of the
 * 0x021E4D08 control block instead of an incoming handle.
 */
s32 func_021DEFDC(void)
{
    s32 v = func_021DFA6C((int *)g_021E4D08[1]);

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
int func_021DF018(u32_021DF018 a0, u32_021DF018 a1, u32_021DF018 a2)
{
    int r;

    g_021E4D08[2] = a0;
    r = func_021DFAB8((u32_021DF018 *)g_021E4D08[1], (u32_021DF018)d_021E4F34, (u32_021DF018)d_021E4D1C,
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
    Disp *t = (Disp *)0x021E4D08;
    t->fn(c, d);
}


/*
 * SDK provenance: DWC_ScSetReportIntentionAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the intention/console id, then forward to
 * scSetReportIntention with the fixed endpoint pair and this file's callback.
 */
int func_021DF09C(u32_021DF09C a0, u32_021DF09C a1, u32_021DF09C a2, u32_021DF09C a3)
{
    int r;

    g_021E4D08[3] = a1;
    r = func_021DFB18((int *)g_021E4D08[1], 0, a0, (u32_021DF09C)d_021E4F34,
                      (u32_021DF09C)d_021E4D1C, (u32_021DF09C)func_021DF110, a2, a3);
    if (r != 0)
        func_02059F54(8, func_021DF644(7, r));
    return r;
}
