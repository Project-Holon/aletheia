/*
 * function: BTLV_SCU_HideMonPair
 * address:  0x021ED4E4
 * packet:   pkt_ov093_021ED4E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_SCU_HideMonSlot  0x021ED9EC  thumb  ov093
 *   func_021F87D4  0x021F87D4  thumb  ov094
 */
typedef unsigned char u8;
struct E;
extern void BTLV_SCU_HideMonSlot(struct E *e);
typedef unsigned int   u32;
extern void func_021F87D4(u32 v);
void BTLV_SCU_HideMonPair(u8 *p, int a, int b)
{
    BTLV_SCU_HideMonSlot((struct E *)(p + 0x48 + a * 12));
    BTLV_SCU_HideMonSlot((struct E *)(p + 0x48 + b * 12));
    func_021F87D4(1);
}
