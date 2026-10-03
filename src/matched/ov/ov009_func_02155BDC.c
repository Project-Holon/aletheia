/*
 * function: func_02155BDC
 * address: 0x02155BDC
 * packet: pkt_ov009_02155BDC
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_0216B65C 0x0216B65C arm ov009
 *   func_02155374 0x02155374 thumb ov009
 */
typedef unsigned char u8;
extern u8 *d_021A8264;
extern int func_0216B65C(void);
extern void func_02155374(int);
void func_02155BDC(unsigned int n)
{
    if (n < 2 && d_021A8264[0x7A8]) {
        func_0216B65C();
        *(int *)(d_021A8264 + 0x774) = -1;
        func_02155374(20);
    }
}
