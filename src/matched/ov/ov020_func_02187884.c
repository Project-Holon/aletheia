/*
 * function: func_02187884
 * address: 0x02187884
 * packet: pkt_ov020_02187884
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_0204047C 0x0204047C arm
 *   func_020414AC 0x020414AC arm
 */
extern int func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(int n);
extern void func_0204047C(int a, int b);
extern void func_020414AC(int a);
void func_02187884(char *unused)
{
    int n;
    n = func_02043658();
    func_02188DA0();
    func_02043534(n);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}
