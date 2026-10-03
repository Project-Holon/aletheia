/*
 * function: func_021BEAF8
 * address: 0x021BEAF8
 * packet: pkt_ov217_021BEAF8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing: two alignment bytes at 021BEB3E.
 * Prototype: caller reads r0 from func_021BF5D0 despite legacy void declaration.
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BF5D0 0x021BF5D0 thumb ov217
 *   func_021BEBE4 0x021BEBE4 thumb ov217
 *   func_021BEBC0 0x021BEBC0 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021BF810(void *p);
extern u32 func_021BF5D0(u8 *, u32);
extern u32 func_021BEBE4(u32);
extern u32 func_021BEBC0(u32);
void func_021BEAF8(u8 *p)
{
    if (*(u32 *)(p + 968) == 1 || *(u32 *)(p + 976) == 1 || func_021BF810(p) == 0) {
        if (func_021BF5D0(p, 5) == 0) func_021BEBE4((u32)p);
    } else {
        if (func_021BF5D0(p, 5) == 1) func_021BEBC0((u32)p);
    }
}
