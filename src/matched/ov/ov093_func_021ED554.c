/*
 * function: BTLV_SCU_ShowMon
 * address:  0x021ED554
 * packet:   pkt_ov093_021ED554
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ShowMonSlot  0x021EDA04  thumb  ov093
 *   func_021F87D4  0x021F87D4  thumb  ov094
 */
typedef unsigned char u8;
struct E;
extern void BTLV_SCU_ShowMonSlot(struct E *e);
typedef unsigned int   u32;
extern void func_021F87D4(u32 v);
int BTLV_SCU_ShowMon(u8 *p, int k)
{
    BTLV_SCU_ShowMonSlot((struct E *)(p + 0x48 + k * 12));
    func_021F87D4(0);
    return 1;
}
