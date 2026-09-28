/*
 * function: func_021E11F0
 * address:  0x021E11F0
 * packet:   pkt_ov175_021E11F0
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    near miss, 20 instructions differ by register colouring only: the image holds 0x38 in r5, s_tbl in r6 and the constant 3 in r7; this spelling gives r6, r7, r5. Case order, the cross-jumped per-case duplicates and the mla address for case 6 all match.
 *
 * sdk:      DWC_GdbCancelRequest (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 *
 * symbols:
 *   func_021E17D8  0x021E17D8  arm  ov175
 *   func_021DD560  0x021DD560  arm  ov175
 *   func_021C22D4  0x021C22D4  arm  ov114
 *   func_021C22A4  0x021C22A4  arm  ov114
 *   g_021E5334  0x021E5334  data
 *   g_021E4548  0x021E4548  data
 *   g_021E4560  0x021E4560  data
 *   g_021E457C  0x021E457C  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef union {
    struct {
        void *request;
    } sake;
    struct {
        int request;
    } ghttp;
    struct {
        int reserved;
        int request;
    } ghttp2;
    u8 raw[56];
} DWCiGdbWork;

typedef struct {
    void *request;
    void *sake;
    int   state;
    int   process;
    int   result;
    u32   current_work;
    DWCiGdbWork work[2];
} DWCiGdbEntity;

extern void func_021E17D8(int line, const char *fmt, ...);
extern void func_021DD560();
extern int func_021C22D4(int request);
extern void func_021C22A4(int request);
extern DWCiGdbEntity g_021E5334;
extern char g_021E4548[];
extern char g_021E4560[];
extern char g_021E457C[];

int func_021E11F0(void)
{
    if (g_021E5334.state != 2) {
        func_021E17D8(0x14F, g_021E4548);
        return 17;
    }
    g_021E5334.state = 3;
    switch (g_021E5334.process) {
    case 2:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 3:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 4:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 7:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 8:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 9:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 10:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 11:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 12:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 13:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 5:
        func_021E17D8(0x181, g_021E4560, func_021C22D4(g_021E5334.work[g_021E5334.current_work].ghttp.request));
        func_021C22A4(g_021E5334.work[g_021E5334.current_work].ghttp.request);
        break;
    case 6:
        func_021E17D8(0x188, g_021E4560, func_021C22D4(((DWCiGdbWork *)g_021E5334.work)[g_021E5334.current_work].ghttp2.request));
        func_021C22A4(((DWCiGdbWork *)g_021E5334.work)[g_021E5334.current_work].ghttp2.request);
        break;
    default:
        func_021E17D8(0x18F, g_021E457C);
        break;
    }
    return 0;
}
