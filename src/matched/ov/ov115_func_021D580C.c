/*
 * function: func_021D580C
 * address: 0x021D580C
 * packet: pkt_ov115_021D580C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A600 0x0204A600 arm
 */
typedef unsigned char u8;
typedef short s16;
extern void func_0204A600(void);
void func_021D580C(u8 *p) {
    ++*(s16 *)(p + 0x9c8);
    if (*(s16 *)(p + 0x9c8) >= 192) *(s16 *)(p + 0x9c8) = 0;
    if (*(s16 *)(p + 0xb4a)) {
        ++*(s16 *)(p + 0xb4a);
        if (*(s16 *)(p + 0xb4a) >= 257) *(s16 *)(p + 0xb4a) = 1;
    }
    func_0204A600();
}
