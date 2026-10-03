/*
 * function: func_021BC6C4
 * address: 0x021BC6C4
 * packet: pkt_ov209_021BC6C4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02021518(u32);
struct PalAnmSlot;
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
void func_021BC6C4(char *p)
{
    *(void **)(p + 12) = func_02021518(0x6B);
    func_0202155C(*(void **)(p + 12), 0, 0x200, 0x6B);
    func_0202155C(*(void **)(p + 12), 1, 0x200, 0x6B);
    func_0202155C(*(void **)(p + 12), 2, 0x200, 0x6B);
    func_0202155C(*(void **)(p + 12), 3, 0x200, 0x6B);
}
