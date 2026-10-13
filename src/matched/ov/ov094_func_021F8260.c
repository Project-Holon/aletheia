/*
 * function: func_021F8260
 * address: 0x021F8260
 * packet: pkt_ov094_021F8260
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Leaf blocking ov093 BTLV_SCU_ProcEntrySingleTrainer.
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   func_02209068 0x02209068 thumb ov094
 */
typedef unsigned int u32;
extern char *d_0220AF20;
extern void func_02209068(void *);
void func_021F8260(u32 i)
{
    func_02209068(*(void **)(d_0220AF20 + i * 4 + 0x1a8));
}
