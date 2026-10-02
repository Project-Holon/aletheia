/*
 * function: func_021C888C
 * address: 0x021C888C
 * packet: pkt_ov093_021C888C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021C88A2.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Packed021C888C { u16 low : 8; u16 index : 7; u16 active : 1; };
void func_021C888C(u8 *p, u32 v)
{
    if (((struct Packed021C888C *)(p + 2))->index < 8) {
        *(u32 *)(p + 0x20) = v;
        ((struct Packed021C888C *)(p + 2))->active = 1;
    }
}
