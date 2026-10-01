/*
 * function: func_021C07BC
 * address: 0x021C07BC
 * packet: pkt_ov217_021C07BC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *func_02021518(u32);
extern void func_0202155C(struct PalAnmSlot *, u32, u32, u32);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
void func_021C07BC(u8 *p)
{
    *(void **)(p + 0x3B8) = func_02021518(*(u16 *)(p + 4));
    func_0202155C(*(void **)(p + 0x3B8), 0, 512, *(u16 *)(p + 4));
    func_0202155C(*(void **)(p + 0x3B8), 2, 512, *(u16 *)(p + 4));
    func_020216D4(*(void **)(p + 0x3B8), 0, 0, 512);
    func_020216D4(*(void **)(p + 0x3B8), 2, 0, 512);
}
