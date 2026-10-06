/*
 * function: func_021E1604
 * address: 0x021E1604
 * packet: pkt_ov137_021E1604
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E0634 0x021E0634 thumb ov137
 *   func_021E0980 0x021E0980 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021E0634(u8 *p, int a);
extern void func_021E0980(char *, int);
void func_021E1604(char *p, int v)
{
    func_021E0634((u8 *)(p + 0xe0), v);
    func_021E0980(p, v);
}
