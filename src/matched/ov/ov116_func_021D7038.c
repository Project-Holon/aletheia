/*
 * function: func_021D7038
 * address: 0x021D7038
 * packet: pkt_ov116_021D7038
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02156DC4(int, int);
extern void func_021B99B8(u8 *);
extern void func_021B9838(u8 *);
void func_021D7038(u8 *p)
{
    if (*(u8 **)(p + 0x168)) {
        func_02156DC4(0, 0);
        func_021B99B8(*(u8 **)(p + 0x168));
        func_021B9838(*(u8 **)(p + 0x168));
        *(u8 **)(p + 0x168) = 0;
    }
}
