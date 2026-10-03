/*
 * function: func_021D4A64
 * address: 0x021D4A64
 * packet: pkt_ov123_021D4A64
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D4730 0x021D4730 thumb ov123
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0201DD68(char *);
extern void func_021D4730(char *);
struct Rec;
struct U16Vec;
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(int, u16, u16);
extern void func_020403F4(u32 i);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
extern void func_02045808(struct U16Vec *vec);
void func_021D4A64(char *p)
{
    func_0201DD68(p);
    func_021D4730(p);
    func_02040DA8(5, 1, 0);
    func_0203FB44(5, *(u32 *)(p + 0x3c), *(u32 *)(p + 0x3c) >> 16);
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04(*(void **)(p + 0x24));
    func_02045C04(*(void **)(p + 0x28));
    func_0201D83C(*(void **)(p + 0x30));
    func_02045808(*(void **)(p + 0x38));
}
