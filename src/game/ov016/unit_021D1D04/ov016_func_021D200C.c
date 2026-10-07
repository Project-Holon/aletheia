/*
 * function: func_021D200C
 * address:  0x021D200C
 * packet:   pkt_ov016_021D200C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_KickChild (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   MB_CommResponseRequest           0x021F1C30  arm
 *   OS_DisableInterrupts             0x02087988  arm
 *   OS_RestoreInterrupts             0x0208799C  arm
 *   MB_DisconnectChild               0x021F5FB0  arm
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
extern int MB_CommResponseRequest(u16 child_aid, int ack);
extern void MB_DisconnectChild(u16 aid);

void func_021D200C(u16 child_aid)
{
    u32 enabled;
    if (!MB_CommResponseRequest(child_aid, 0)) {
        u16 mask = ~(1 << child_aid);
        enabled = OS_DisableInterrupts();
        g_021DE65C->mbpState.connectChildBmp &= mask;
        g_021DE65C->mbpState.requestChildBmp &= mask;
        g_021DE65C->mbpState.entryChildBmp &= mask;
        g_021DE65C->mbpState.downloadChildBmp &= mask;
        g_021DE65C->mbpState.bootableChildBmp &= mask;
        g_021DE65C->mbpState.rebootChildBmp &= mask;
        OS_RestoreInterrupts(enabled);
        MB_DisconnectChild(child_aid);
        return;
    }
    enabled = OS_DisableInterrupts();
    g_021DE65C->mbpState.requestChildBmp &= (u16)~(1 << child_aid);
    g_021DE65C->mbpState.connectChildBmp &= (u16)~(1 << child_aid);
    OS_RestoreInterrupts(enabled);
}
