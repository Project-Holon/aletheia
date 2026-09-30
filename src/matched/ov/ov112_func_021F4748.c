/*
 * function: func_021F4748
 * address: 0x021F4748
 * packet: pkt_ov112_021F4748
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0201C6EC(u32);
extern void func_0201C4C0(u32);
extern void func_0202F038(u8 *);
extern void func_0201CE48(void *);
extern void func_02045808(void *);
extern void func_02045C04(void *);
extern void func_020452E8(void *);
extern void func_0201D83C(void *);
extern void func_02031140(void *);
void func_021F4748(u8 *p)
{
    func_0201C6EC(*(u32 *)(p+0x38));
    func_0201C4C0(*(u32 *)(p+0x38));
    if (*(u8 **)(p+0x34)) {
        func_0202F038(*(u8 **)(p+0x34));
        *(u32 *)(p+0x34)=0;
    }
    if (*(void **)(p+0x24)) func_0201CE48(*(void **)(p+0x24));
    if (*(void **)(p+0x2c)) func_02045808(*(void **)(p+0x2c));
    func_02045C04(*(void **)(p+0x28));
    func_020452E8(*(void **)(p+0x1c));
    func_0201D83C(*(void **)(p+0x20));
    func_02031140(*(void **)(p+0x18));
}
