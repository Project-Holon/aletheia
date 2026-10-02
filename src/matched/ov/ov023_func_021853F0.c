/*
 * function: func_021853F0
 * address: 0x021853F0
 * packet: pkt_ov023_021853F0
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword store at 0x021853F8 to 0x04000050.
 * symbols:
 *   func_02186304 0x02186304 thumb ov023
 *   func_02186444 0x02186444 thumb ov023
 *   func_02185354 0x02185354 thumb ov023
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02186304(char *p, int a);
extern void func_02186444(char *p, u32 v);
extern void func_02185354(char *p);
int func_021853F0(char *p, int result)
{
    *(volatile u16 *)0x04000050 = 0;
    func_02186304(p, 1);
    func_02186444(p, 4);
    func_02185354(p);
    *(u32 *)(p + 0x9e7c) = 0;
    return result;
}
