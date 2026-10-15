/*
 * function: MB_SEQ_FreeBgs
 * address: 0x021C5714
 * packet: pkt_ov136_021C5714
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_SEQ_FreeBgs 0x021C5714 thumb
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned int u32;
extern void func_020403F4(u32 bgId);
extern void BG_SYS_Delete(void);

void MB_SEQ_FreeBgs(void *a0)
{
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    BG_SYS_Delete();
}
