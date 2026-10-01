/*
 * function: InitAtermApcNetwork
 * address:  0x021B97A8
 * packet:   pkt_ov016_021B97A8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * sdk:      InitAtermApcNetwork (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * wave8 (2026-10-01).  Body is 164 B (image 164 B), now 33 concrete bytes
 * differ (was 62).  TWO residues SOLVED this wave:
 *  - MASK: enum-typed mask local `AlignMask am = ALIGN_MASK;` (ALIGN_MASK =
 *    -32) materialises the complement and emits `ands`, not `bics`.  Idiom:
 *    docs/idioms/an-enum-local-mask-keeps-ands-instead-of-bics.md.
 *  - THE CONSTANT OFF THE PC-RELATIVE BASE: writing `maxap*0xd0 + 0x1c00`
 *    (float `0x1c00`) pools `0x1c00` as a pc-relative add instead of folding
 *    it into the later `+0x700` (which had produced `subs #0x21`), matching
 *    the image's `adds r0, r3, r2` + `ldr r2, [pc]` at +0x3E/+0x40.  The
 *    image's pool word is 0x900 (`0x2490 = 0x2400 + 0x90`); the compiled
 *    word is 0xd0 and differs only in the pool datum (one concrete byte).
 *
 * DWARF (scratch/laneU55/objs/atermset.o, decl_line 206 atermapc.c) has
 * exactly three entities: maxap (DW_OP_reg6), loop_flag (reg4), retv (reg5);
 * no `t`, no `ev`.
 *
 * blocker: LINEAR-COMBINATION FOLD.  With no `t` local the allocator gives
 * maxap r6 exactly as the image, but this front end folds
 * `maxap*0xd0 + 0x24d0 + maxap*0xc0` to `movs #0x19 / lsls #4 / muls`
 * (0x190*maxap) and folds the `+0x2490` size into 0x190*maxap too
 * (0x190*maxap + 0x2490 = 0x190*(maxap+0x17)+0x90) so only `*0xd0` survives.
 * The image keeps the two multiplies (0x190, and a separate `*0xd0` at
 * +0x3E) because it materialised the two sizes separately.  Naming `t`/
 * `0x190` restores the mul but the allocator then homes a named temp where
 * maxap was (r6 vs r7 reverses).  Enum-typed SIZE constants do NOT stop the
 * fold.  Remaining documented residue is this one front-end value-numbering
 * choice (fold vs. CSE); 33 concrete bytes, register colouring only, plus the
 * one pool datum byte above.  Status DIFF, not EXACT.
 *
 * 2026-10-01 (lane03): rewritten on the sibling FreeAtermApcNetwork's atermset_bss struct
 * with vendor names. `APC_WORK_SIZE(n) + 64 + maxap * sizeof(struct WMBssDesc)` (unsigned
 * sizeof, WMBssDesc is 0xc0) stops the linear-combination fold: +0000..+002E now match the
 * image (two muls, maxap*0xd0 CSE'd in r7, 0x24d0 and 0x2490 pooled). do/while loop as in
 * the image. Residue (160 B vs 164 B): the image holds 0x1f in r1 for both `+31` adds and
 * derives -32 from it (`subs #0x3f`), with the base in r6; 2.0 adds 0x1f in place and
 * derives -32 off loop_flag. Vendor stamp is 3.0.0.126, no build in the tree.
 * No `am` mask local (not in the DWARF): plain `& ~31` gives bics, 111 B; the
 * enum local (107 B) or enum locals for both 31 and -32 (hoisted to entry, 69 B
 * at 164 B but every register off) are stand-ins.
 *
 * symbols:
 *   AtermApc_InitEventBuf  0x021B970C  thumb  ov016
 *   APC_Init  0x021B95EC  thumb  ov016
 *   OS_Sleep  0x02085A38  arm
 *   AtermApc_GetEvent  0x021B9734  thumb  ov016
 *   AtermApc_callback  0x021B976C  thumb  ov016
 *   atermset_bss  0x021DCFD0  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
struct WMBssDesc { u8 data[0xc0]; };
struct WCMConfig;
struct _ATERMApConfigState;

typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;
    unsigned long long       *gThreadStack;
    int                       cbElementData;
    int                       gAtermApState;
    unsigned char            *apci_IWBuffer;
    unsigned char            *apc_work;
    unsigned char            *apci_bssid_ptr;
    unsigned char            *apci_essid_ptr;
    struct WMBssDesc         *apci_wmbssdesc;
    int                       bDualCfg;
    unsigned char            *atermapc_work;
    unsigned long             apci_connect_option;
    struct WMBssDesc         *ap_list;
    unsigned long             apci_search_option;
    int                       gAtermThreadId;
    int                       event_set_ptr;
    int                       event_get_ptr;
    int                       gMaxApList;
    int                       bInitAtermApNetwork;
    int                       gAtermApResult;
    void                    (*gAtermNotify)(struct _ATERMApConfigState *state);
    void                    (*apci_user_callback)(int event, void *arg);
} ATERMSET_BSS;

extern ATERMSET_BSS atermset_bss;

extern void AtermApc_InitEventBuf(void);
extern int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern void OS_Sleep(unsigned long msec);
extern int AtermApc_GetEvent(void);
extern void AtermApc_callback(int event);

#define APC_WORK_SIZE(n) ((n) * 0xd0 + 0x2490)

int InitAtermApcNetwork(int maxap)
{
    int loop_flag;
    int retv;

    loop_flag = 1;
    atermset_bss.gMaxApList = maxap;
    AtermApc_InitEventBuf();
    atermset_bss.atermapc_work = atermset_bss.gAtermAlloc(APC_WORK_SIZE(maxap) + 64 + maxap * sizeof(struct WMBssDesc));
    if (atermset_bss.atermapc_work == 0)
        return -1;
    atermset_bss.apc_work = (u8 *)(((u32)atermset_bss.atermapc_work + 31) & ~31);
    atermset_bss.ap_list = (struct WMBssDesc *)(((u32)atermset_bss.apc_work + APC_WORK_SIZE(maxap) + 31) & ~31);
    if (APC_Init((void (*)(int, void *))AtermApc_callback, atermset_bss.apc_work, APC_WORK_SIZE(maxap)) == 0)
        return -2;
    do {
        int event;

        OS_Sleep(10);
        while ((event = AtermApc_GetEvent()) != 0) {
            switch (event) {
            case 4:
            case 5:
                break;
            case 6:
                loop_flag = 0;
                retv = 1;
                break;
            default:
                loop_flag = 0;
                retv = -2;
                break;
            }
        }
    } while (loop_flag);
    return retv;
}
