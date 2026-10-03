/*
 * function: func_021E1634
 * address: 0x021E1634
 * packet: pkt_ov137_021E1634
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: following 021E168C is already matched separately.
 * symbols:
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 *   func_02030734 0x02030734 arm
 *   d_021E22B8 0x021E22B8 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
extern u32 func_020493D4(struct ArcFile *, u32);
extern void func_0204932C(struct ArcFile *, u32, void *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021E22B8[];
void *func_021E1634(char *p, u32 member, int flag)
{
    u32 size = func_020493D4(*(struct ArcFile **)(p + 0xd58), member);
    void *result;
    if (flag == 1)
        result = func_02030734(114, size, 0, d_021E22B8, 6090);
    else
        result = func_02030734(0x8072, size, 0, d_021E22B8, 6092);
    func_0204932C(*(struct ArcFile **)(p + 0xd58), member, result);
    return result;
}
