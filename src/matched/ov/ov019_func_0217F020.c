/*
 * function: func_0217F020
 * address: 0x0217F020
 * packet: pkt_ov019_0217F020
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EC74 0x0201EC74 thumb
 *   func_0217EE90 0x0217EE90 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0201EC74(u32 n, u32 size, u8 heap);
extern void func_0217EE90(void *p);
void func_0217F020(u8 *p)
{
    if (*(void **)(p + 0x2804) == 0) {
        *(void **)(p + 0x2804) = func_0201EC74(5, 0x40, 0x41);
        func_0217EE90(p);
    }
}
