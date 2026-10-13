/*
 * function: func_021D0DE0
 * address:  0x021D0DE0
 * packet:   pkt_ov016_021D0DE0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbWm (libdwcutil.TWL.HYB.a usbap.o)
 *
 * vendor DWARF of usbap.o (Metrowerks 4.0.0.1025):
 *   static void cbWm(void *arg);
 *   variable struct WMStartScanExCallback *prm   r0
 *
 * wave3 lane23 (2026-10-01): EXACT, 148 bytes, 6/6 relocs.  Closed by making
 *   MemUsb->end a volatile field (as the sibling DWCi_USBAPlEnd needs for its
 *   `while (end != 2)` spin) together with the plain `if (apiid == END) end = 2;
 *   return;` arm.  With a volatile field the store is not if-converted, so the
 *   object's `cmp / popne / mov / strb / pop` comes back.  Earlier lanes had only
 *   tried a volatile store (cast), which stays predicated, and the earlier
 *   144 B / 87 history (if-conversion "compiler wall", -O1 coincidence) is
 *   superseded.  The if/else-if spelling with a volatile field still predicates;
 *   the arm needs the explicit `return` and the 0x26 test as a separate guard.
 *
 * symbols:
 *   func_021D0FCC  0x021D0FCC  arm  ov016
 *   func_021D0E74  0x021D0E74  arm  ov016
 *   func_021D0CB8  0x021D0CB8  arm  ov016
 *   OS_Terminate  0x02088234  arm
 *   gUsbapWork     0x021DE654  data
 */

typedef unsigned short u16;

typedef struct {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    unsigned char reserved[2];
    u16 bssDescCount;
} ScanCbT;

typedef struct {
    unsigned char pad[0x1b94];
    volatile unsigned char end;
    unsigned char stack;
    unsigned char wait;
} MemUsbT;

extern void func_021D0FCC(ScanCbT *prm);
extern void func_021D0E74(ScanCbT *prm);
extern int func_021D0CB8(void);
extern void OS_Terminate(void);
extern MemUsbT *gUsbapWork;

void func_021D0DE0(void *arg)
{
    ScanCbT *prm = (ScanCbT *)arg;

    if (prm->errcode != 0)
        return;
    if (gUsbapWork->end != 0) {
        if (prm->apiid == 2)
            gUsbapWork->end = 2;
        return;
    }
    if (prm->apiid != 0x26)
        return;
    switch (prm->state) {
    case 5:
        if (gUsbapWork->wait)
            func_021D0FCC(prm);
        else
            func_021D0E74(prm);
        func_021D0CB8();
        break;
    case 4:
        func_021D0CB8();
        break;
    default:
        OS_Terminate();
        break;
    }
}
