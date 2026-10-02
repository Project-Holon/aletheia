/*
 * function: func_021F1F00
 * address: 0x021F1F00
 * packet: pkt_ov032_021F1F00
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021659F0 0x021659F0 thumb ov010
 *   func_021F0F44 0x021F0F44 thumb ov032
 *   func_021F1F34 0x021F1F34 thumb ov032
 *   func_021F0DD8 0x021F0DD8 thumb ov032
 */

typedef unsigned char u8;
extern int func_021659F0(u8 *q, int delta);
extern u8 *func_021F0F44(u8 *p, u8 a);
extern void func_021F1F34(char *p, u8 *q, int *r);
extern void func_021F0DD8(int a);
void func_021F1F00(char *p, int a)
{
    u8 *q;
    u8 index;
    index = func_021659F0(*(u8 **)(p + 0x3c), a + *(u8 *)(p + 0x7c));
    q = func_021F0F44((u8 *)p, index);
    func_021F1F34(p, q, (int *)(p + 0xa8));
    func_021F0DD8(0x54c);
}
