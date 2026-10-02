/*
 * function: func_0217F2F4
 * address: 0x0217F2F4
 * packet: pkt_ov019_0217F2F4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021909BC 0x021909BC thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021909BC(void *p);
void func_0217F2F4(u8 *p)
{
    if (*(void **)(p + 0x2810) != 0) {
        func_021909BC(*(void **)(p + 0x2810));
        *(void **)(p + 0x2810) = 0;
    }
}
