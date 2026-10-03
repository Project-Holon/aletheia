/*
 * function: func_021D1F6C
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
 *   func_021F1C30  0x021F1C30  arm  ov107
 *   func_021F5FB0  0x021F5FB0  arm  ov107
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021DE65C     0x021DE65C  data
 */

typedef unsigned short u16;
typedef struct { u16 a[7]; } WPB;
extern WPB *g_021DE65C;

extern int func_021F1C30(unsigned short child_aid, int ack);
extern void func_021F5FB0(u16 aid);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long);

void func_021D1F6C(u16 aid)
{
    if (func_021F1C30(aid, 1) != 0)
        return;
    {
        u16 m = ~(1 << aid);
        unsigned long e = func_02087988();
        g_021DE65C->a[1] &= m;
        g_021DE65C->a[2] &= m;
        g_021DE65C->a[3] &= m;
        g_021DE65C->a[4] &= m;
        g_021DE65C->a[5] &= m;
        g_021DE65C->a[6] &= m;
        func_0208799C(e);
    }
    func_021F5FB0(aid);
}
