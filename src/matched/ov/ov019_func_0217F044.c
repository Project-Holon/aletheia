/*
 * function: func_0217F044
 * address: 0x0217F044
 * packet: pkt_ov019_0217F044
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
extern void func_0201ED04(struct WordSet *p);
void func_0217F044(u8 *p)
{
    if (*(void **)(p + 0x2804) != 0) {
        func_0201ED04(*(void **)(p + 0x2804));
        *(void **)(p + 0x2804) = 0;
    }
}
