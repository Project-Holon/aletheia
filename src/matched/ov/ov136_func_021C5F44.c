/*
 * function: func_021C5F44
 * address: 0x021C5F44
 * packet: pkt_ov136_021C5F44
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C5F44 0x021C5F44 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450C8 0x020450C8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0201C4C0(void *);
extern void func_02031140(u32);
extern void func_020452E8(void *);
extern void func_0201D83C(u32);
extern void func_020450C8(void);

void func_021C5F44(u8 *p)
{
    u32 i;
    func_0201C4C0(*(void **)(*(u8 **)(p + 8) + 0x1C4));
    func_02031140(*(u32 *)(*(u8 **)(p + 8) + 0x1CC));
    for (i = 0; i < 0x20; i++) {
        func_020452E8(*(void **)(*(u8 **)(p + 8) + i * 4 + 0x44));
    }
    func_0201D83C(*(u32 *)(p + 0x18));
    func_020450C8();
}
