/*
 * function: func_021D21CC
 * address:  0x021D21CC
 * packet:   pkt_ov016_021D21CC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_StartDownloadAll (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   DWCi_MOV_MBP_ChangeState         0x021D276C  arm  ov016
 *   OS_DisableInterrupts             0x02087988  arm
 *   OS_RestoreInterrupts             0x0208799C  arm
 *   MB_DisconnectChild               0x021F5FB0  arm
 *   DWCi_MOV_MBP_StartDownload       0x021D20E8  arm  ov016
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

extern Wb *g_021DE65C;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void DWCi_MOV_MBP_ChangeState(u16 state);
extern void MB_DisconnectChild(u16 aid);
extern void DWCi_MOV_MBP_StartDownload(u16 child_aid);

void func_021D21CC(void)
{
    u16 i;
    DWCi_MOV_MBP_ChangeState(3);
    for (i = 1; i < 16; i++) {
        if (!(g_021DE65C->mbpState.connectChildBmp & (1 << i)))
            continue;
        if (g_021DE65C->mbpState.requestChildBmp & (1 << i))
            continue;
        if (!(g_021DE65C->mbpState.entryChildBmp & (1 << i))) {
            u16 mask = ~(1 << i);
            u32 enabled = OS_DisableInterrupts();
            g_021DE65C->mbpState.connectChildBmp &= mask;
            g_021DE65C->mbpState.requestChildBmp &= mask;
            g_021DE65C->mbpState.entryChildBmp &= mask;
            g_021DE65C->mbpState.downloadChildBmp &= mask;
            g_021DE65C->mbpState.bootableChildBmp &= mask;
            g_021DE65C->mbpState.rebootChildBmp &= mask;
            OS_RestoreInterrupts(enabled);
            MB_DisconnectChild(i);
        } else {
            DWCi_MOV_MBP_StartDownload(i);
        }
    }
}
