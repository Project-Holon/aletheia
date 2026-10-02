/*
 * function: func_021C15AC
 * address: 0x021C15AC
 * packet: pkt_ov093_021C15AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CD64C 0x021CD64C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021CD64C(void *, u8, ...);

void func_021C15AC(u8 *p, int k)
{
    if (k < 3) {
        func_021CD64C(*(void **)(p + 12), 0x5a, 0x4f, 0xffff0000);
    } else if (k > 3) {
        func_021CD64C(*(void **)(p + 12), 0x5a, 0x4e, 0xffff0000);
    }
}
