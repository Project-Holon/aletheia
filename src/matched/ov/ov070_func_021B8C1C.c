/*
 * function: func_021B8C1C
 * address:  0x021B8C1C
 * packet:   pkt_ov070_021B8C1C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8CB4  0x021B8CB4  thumb  ov070
 */

typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_0204B8C4();
extern void func_0204B878();
extern void func_0204B92C();
extern void func_021B6100();
extern void func_021B8CB4(char *p);

void func_021B8C1C(int p, int a, int b)
{
    int x;
    if (a == 4) {
        func_020061E4(0x551);
        x = 9;
    } else if (a == 3) {
        func_020061E4(0x556);
        x = 8;
    } else if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    *(unsigned short *)((char *)p + 0x864) = a;
    func_0204B8C4(*(int *)((char *)p + *(unsigned short *)((char *)p + 0x864) * 4 + 0x710), 0);
    func_0204B878(*(int *)((char *)p + *(unsigned short *)((char *)p + 0x864) * 4 + 0x710), (unsigned short)x);
    func_0204B92C(*(int *)((char *)p + *(unsigned short *)((char *)p + 0x864) * 4 + 0x710), 1);
    *(int *)((char *)p + 0x868) = b;
    func_021B6100(p, func_021B8CB4);
}
