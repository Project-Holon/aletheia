/*
 * function: DWCi_MOV_MBP_AcceptChild
 * address:  0x021D1F6C
 * packet:   pkt_ov016_021D1F6C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_AcceptChild (libdwcutil.TWL.HYB.a dwc_mov_mbp.o)
 *
 * note:     the earlier draft read the 0x021DE65C pointer through a cast; declaring
 *           the vendor global `wb` (a pointer to a struct whose first 0xe bytes are
 *           halfwords) gives the object's registers (pool address in r1, pointee r3).
 *
 * symbols:
 *   MB_CommResponseRequest  0x021F1C30  arm  ov107
 *   MB_DisconnectChild  0x021F5FB0  arm  ov107
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gDwcMovMbpWork     0x021DE65C  data
 */

typedef unsigned short u16;
typedef struct { u16 a[7]; } WPB;
extern WPB *gDwcMovMbpWork;

extern int MB_CommResponseRequest(unsigned short child_aid, int ack);
extern void MB_DisconnectChild(u16 aid);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long);

void DWCi_MOV_MBP_AcceptChild(u16 aid)
{
    if (MB_CommResponseRequest(aid, 1) != 0)
        return;
    {
        u16 m = ~(1 << aid);
        unsigned long e = OS_DisableInterrupts();
        gDwcMovMbpWork->a[1] &= m;
        gDwcMovMbpWork->a[2] &= m;
        gDwcMovMbpWork->a[3] &= m;
        gDwcMovMbpWork->a[4] &= m;
        gDwcMovMbpWork->a[5] &= m;
        gDwcMovMbpWork->a[6] &= m;
        OS_RestoreInterrupts(e);
    }
    MB_DisconnectChild(aid);
}
