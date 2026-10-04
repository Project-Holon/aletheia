/*
 * function: func_021D751C
 * address: 0x021D751C
 * packet: pkt_ov123_021D751C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5D58 0x021D5D58 thumb ov123
 *   func_021D7858 0x021D7858 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021D5D58(char *p);
extern void func_021D7858(int a);
extern void func_021D6FF0(char *p);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D751C(int a)
{
    if (func_021D5D58((char *)(*(int *)(a + 8)))) {
        func_021D6EE0((u8 *)a, (int)func_021D7858, 0x319);
        return;
    }
    *(int *)(a + 0x80) = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x31d);
}
