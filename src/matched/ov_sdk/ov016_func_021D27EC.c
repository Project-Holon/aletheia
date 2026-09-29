/*
 * function: func_021D27EC
 * address:  0x021D27EC
 * packet:   pkt_ov016_021D27EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_GetChildState (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988  arm
 *   OS_RestoreInterrupts             0x0208799C  arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   g_021DE65C                       0x021DE65C  data
 */

typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u16 state;
    u16 connectChildBmp;
    u16 requestChildBmp;
    u16 entryChildBmp;
    u16 downloadChildBmp;
    u16 bootableChildBmp;
    u16 rebootChildBmp;
} MBPState;

typedef struct {
    MBPState mbpState;
} Wb;

typedef enum {
    CS_NONE,
    CS_CONNECT,
    CS_REQUEST,
    CS_ENTRY,
    CS_DOWNLOAD,
    CS_BOOTABLE,
    CS_REBOOT
} ChildState;

extern Wb *g_021DE65C;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);

ChildState func_021D27EC(u16 aid)
{
    MBPState tmpState;
    u32 enabled;
    enabled = OS_DisableInterrupts();
    if (!(g_021DE65C->mbpState.connectChildBmp & (u16)(1 << aid))) {
        OS_RestoreInterrupts(enabled);
        return CS_NONE;
    }
    MI_CpuCopy8(&g_021DE65C->mbpState, &tmpState, sizeof(MBPState));
    OS_RestoreInterrupts(enabled);
    if (tmpState.requestChildBmp & (u16)(1 << aid))
        return CS_REQUEST;
    if (tmpState.entryChildBmp & (u16)(1 << aid))
        return CS_ENTRY;
    if (tmpState.downloadChildBmp & (u16)(1 << aid))
        return CS_DOWNLOAD;
    if (tmpState.bootableChildBmp & (u16)(1 << aid))
        return CS_BOOTABLE;
    if (tmpState.rebootChildBmp & (u16)(1 << aid))
        return CS_REBOOT;
    return CS_CONNECT;
}
