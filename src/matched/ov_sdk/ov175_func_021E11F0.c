/*
 * function: DWC_GdbCancelRequest
 * address:  0x021E11F0
 * packet:   pkt_ov175_021E11F0
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2026-10-01: closed. The image dispatches the switch in r2: the default arm's
 * printf takes s_tbl.process as its third argument (the value already in r2),
 * which also fixed the {r5,r6,r7} colouring of s_tbl / 0x38 / 3.
 *
 * sdk:      DWC_GdbCancelRequest (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 *
 * symbols:
 *   DWCi_GdbPrintf  0x021E17D8  arm  ov175
 *   sakeCancelRequest  0x021DD560  arm  ov175
 *   ghttpGetState  0x021C22D4  arm  ov114
 *   ghttpCancelRequest  0x021C22A4  arm  ov114
 *   gDwcGdbEntity  0x021E5334  data
 *   sDwcGdbNotInAsyncProcess  0x021E4548  data
 *   sDwcGdbCancelGhttp  0x021E4560  data
 *   sDwcGdbIllegalProcess  0x021E457C  data
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

extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern void sakeCancelRequest();
extern int ghttpGetState(int request);
extern void ghttpCancelRequest(int request);
extern DWCiGdbEntity gDwcGdbEntity;
extern char sDwcGdbNotInAsyncProcess[];
extern char sDwcGdbCancelGhttp[];
extern char sDwcGdbIllegalProcess[];

int DWC_GdbCancelRequest(void)
{
    if (gDwcGdbEntity.state != 2) {
        DWCi_GdbPrintf(0x14F, sDwcGdbNotInAsyncProcess);
        return 17;
    }
    gDwcGdbEntity.state = 3;
    switch (gDwcGdbEntity.process) {
    case 2:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 3:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 4:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 7:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 8:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 9:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 10:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 11:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 12:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 13:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.current_work].sake.request);
        break;
    case 5:
        DWCi_GdbPrintf(0x181, sDwcGdbCancelGhttp, ghttpGetState(gDwcGdbEntity.work[gDwcGdbEntity.current_work].ghttp.request));
        ghttpCancelRequest(gDwcGdbEntity.work[gDwcGdbEntity.current_work].ghttp.request);
        break;
    case 6:
        DWCi_GdbPrintf(0x188, sDwcGdbCancelGhttp, ghttpGetState(((DWCiGdbWork *)gDwcGdbEntity.work)[gDwcGdbEntity.current_work].ghttp2.request));
        ghttpCancelRequest(((DWCiGdbWork *)gDwcGdbEntity.work)[gDwcGdbEntity.current_work].ghttp2.request);
        break;
    default:
        DWCi_GdbPrintf(0x18F, sDwcGdbIllegalProcess, gDwcGdbEntity.process);
        break;
    }
    return 0;
}
