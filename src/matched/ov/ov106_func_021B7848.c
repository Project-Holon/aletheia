/*
 * function: func_021B7848
 * address: 0x021B7848
 * packet: pkt_ov106_021B7848
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B78B8 0x021B78B8 thumb ov106
 *   func_021B80A0 0x021B80A0 thumb ov106
 *   func_021B93E4 0x021B93E4 thumb ov106
 *   func_021B78CC 0x021B78CC thumb ov106
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B78B8(u8 *);
extern void func_021B80A0(u8 *);
extern void func_0201C4E4(u32);
extern int func_021B93E4(u32);
extern u32 func_021B78CC(u8 *);
int func_021B7848(int a, int b, int c, u8 *p)
{
    int i;
    func_021B78B8(p + 0x28);
    func_021B80A0(p);
    func_0201C4E4(*(u32 *)(p + 0x61C));
    for (i = 0; i < 4; i++) func_021B93E4(*(u32 *)(p + 0x62C + i * 4));
    if (func_021B78CC(p + 0x28)) return 1;
    return 0;
}
