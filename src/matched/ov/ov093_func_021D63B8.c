/*
 * function: func_021D63B8
 * address: 0x021D63B8
 * packet: pkt_ov093_021D63B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum loop counter with unsigned bound retains the entry guard;
 *   word-array indexing settles zero/offset scratch register allocation.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { SLOT_FIRST, SLOT_LIMIT=36, SLOT_UNSIGNED=0xFFFFFFFF } SlotIndex;
struct Slot { u32 a:3; u32 rest:29; };
extern void func_02082BCC(void *, int, u32);
void func_021D63B8(u8 *p, int all)
{
    SlotIndex i;
    i = 0;
    if (all == 0) i = 6;
    for (; i < 36U; i++) {
        ((u32 *)(p + 0x1c))[i] = 0;
        ((struct Slot *)(p + 0x1c))[i].a = 0;
    }
    func_02082BCC(p + 0xac, 0, 36);
}
