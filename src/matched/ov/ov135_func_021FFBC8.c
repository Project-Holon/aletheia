/*
 * function: func_021FFBC8
 * address: 0x021FFBC8
 * packet: pkt_ov135_021FFBC8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FFC16..021FFC18 is two-byte zero alignment padding.
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_021FFBC0 0x021FFBC0 thumb ov135
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0204B898(u32);
extern int func_021FFBC0(int);
extern int func_0204B3F4(u32);
extern void func_0204B878(u32, u16);
void func_021FFBC8(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 4 + 0xD10) != 0) {
            int a;
            a = func_0204B898(*(u32 *)(p + i * 4 + 0xD10));
            if (a != func_021FFBC0(i) + 1) {
                if (func_0204B3F4(*(u32 *)(p + i * 4 + 0xD10)) != 0) {
                    func_0204B878(*(u32 *)(p + i * 4 + 0xD10), func_021FFBC0(i) + 1);
                }
            }
        }
    }
}
