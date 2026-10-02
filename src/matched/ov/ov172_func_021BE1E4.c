/*
 * function: func_021BE1E4
 * address: 0x021BE1E4
 * packet: pkt_ov172_021BE1E4
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02045770(u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(u32 a);
void func_021BE1E4(u8 *p)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        func_02043B5C(func_02045770(*(u32 *)(p + i * 4 + 0x1b8)), 0);
        func_02045334(*(u32 *)(p + i * 4 + 0x1b8));
    }
}
