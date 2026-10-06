/*
 * function: func_021D48CC
 * address: 0x021D48CC
 * packet: pkt_ov093_021D48CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4394 0x021D4394 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *d_021F3B88;
extern u8 func_021D4394(u32);
void *func_021D48CC(u8 a)
{
    int i = func_021D4394(a);
    void *p;
    if (i != 0x28) return *(void **)(d_021F3B88 + i * 4 + 0x3ae4);
    p = *(void **)(d_021F3B88 + 0x3b14);
    if (p != 0 && *(void **)(d_021F3B88 + 0x3b18) != 0) return p;
    return 0;
}
