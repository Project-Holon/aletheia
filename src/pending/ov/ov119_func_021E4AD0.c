/*
 * function: func_021E4AD0
 * address: 0x021E4AD0
 * packet: pkt_ov119_021E4AD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * symbols:
 *   func_021DF614 0x021DF614 thumb ov119
 *   func_021E4AB8 0x021E4AB8 thumb ov119
 */
extern int func_021DF614(char *p, int a, int b);
extern void func_021E4AB8(int a0, int a1, int a2);
void func_021E4AD0(char *p, int a1, int a2, int a3, int a4)
{
    int flag = 0;
    if (func_021DF614(p, a1, a2)) {
        flag = 1;
    }
    func_021E4AB8((int)p, *(int *)(p + a4 * 0x14 + a2 * 4 + 0xAC0), flag);
}
