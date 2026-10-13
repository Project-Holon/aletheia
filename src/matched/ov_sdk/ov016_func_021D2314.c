/*
 * function: DWCi_MOV_MBP_StartRebootAll
 * address:  0x021D2314
 * packet:   pkt_ov016_021D2314
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_StartRebootAll (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   MB_CommResponseRequest           0x021F1C30  arm
 *   DWCi_MOV_MBP_ChangeState         0x021D276C  arm  ov016
 *   OS_DisableInterrupts             0x02087988  arm
 *   OS_RestoreInterrupts             0x0208799C  arm
 *   MB_DisconnectChild               0x021F5FB0  arm
 *   gDwcMovMbpWork                       0x021DE65C  data
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

extern Wb *gDwcMovMbpWork;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern int MB_CommResponseRequest(u16 child_aid, int ack);
extern void MB_DisconnectChild(u16 aid);
extern void DWCi_MOV_MBP_ChangeState(u16 state);

void DWCi_MOV_MBP_StartRebootAll(void)
{
    u16 i;
    u16 sentChild = 0;
    for (i = 1; i < 16; i++) {
        if (gDwcMovMbpWork->mbpState.bootableChildBmp & (1 << i)) {
            if (MB_CommResponseRequest(i, 3)) {
                sentChild |= (u16)(1 << i);
            } else {
                u32 enabled;
                u16 mask = ~(1 << i);
                enabled = OS_DisableInterrupts();
                gDwcMovMbpWork->mbpState.connectChildBmp &= mask;
                gDwcMovMbpWork->mbpState.requestChildBmp &= mask;
                gDwcMovMbpWork->mbpState.entryChildBmp &= mask;
                gDwcMovMbpWork->mbpState.downloadChildBmp &= mask;
                gDwcMovMbpWork->mbpState.bootableChildBmp &= mask;
                gDwcMovMbpWork->mbpState.rebootChildBmp &= mask;
                OS_RestoreInterrupts(enabled);
                MB_DisconnectChild(i);
            }
        }
    }
    if (sentChild == 0)
        DWCi_MOV_MBP_ChangeState(7);
    else
        DWCi_MOV_MBP_ChangeState(4);
}
