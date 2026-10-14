/*
 * function: ZUKAN_DETAIL_COMMON_SetBgScrollPacked
 * address: 0x021BCA54
 * packet: pkt_ov208_021BCA54
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 a, u32 packed)
{
    func_0203FB44(a, (u16)packed, (u16)(packed >> 16));
}
