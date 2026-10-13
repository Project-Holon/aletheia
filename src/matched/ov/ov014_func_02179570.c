/*
 * function: func_02179570
 * address: 0x02179570
 * packet: pkt_ov014_02179570
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data ov014 a4
 *   func_02178138 0x02178138 thumb ov014
 *   WM_End 0x0208F43C arm
 *   func_02178DE0 0x02178DE0 thumb ov014
 */
typedef unsigned char u8;
extern u8 *g_021797A8;
extern void func_02178138(int);
extern int WM_End(void (*)(u8 *));
extern void func_02178DE0(u8 *);
int func_02179570(void (*cb)(int))
{
    *(void (**)(int))(g_021797A8 + 0x1E64) = cb;
    func_02178138(3);
    if (WM_End(func_02178DE0) != 2) {
        func_02178138(9);
        return 0;
    }
    return 1;
}
