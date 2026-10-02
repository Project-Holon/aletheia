/*
 * function: func_021B6A28
 * address: 0x021B6A28
 * packet: pkt_ov067_021B6A28
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B6A42.
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204B878(void *, u16);
extern void func_020061E4(void *);
void func_021B6A28(u8 *p)
{
    *(u32 *)(p + 8) = *(u16 *)(p + 0x2a);
    func_0204B878(*(void **)p, *(u32 *)(p + 8));
    if (*(void **)(p + 0x34)) func_020061E4(*(void **)(p + 0x34));
}
