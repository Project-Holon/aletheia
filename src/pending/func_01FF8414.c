/*
 * function: func_01FF8414
 * address:  0x01FF8414
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   GX_GetBankForLCDC 0x02084A28  arm
 *   func_02085D3C     0x02085D3C  arm
 *   func_01FF8540     0x01FF8540  arm
 *   func_01FF836C     0x01FF836C  arm
 *   func_01FF8460     0x01FF8460  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int GX_GetBankForLCDC(void);
extern int func_02085D3C(void);
extern void func_01FF8540(int);
extern void func_01FF836C(void);
extern void func_01FF8460(void);

void func_01FF8414(void)
{
    while (!GX_GetBankForLCDC()) {
    }
    *(volatile u16 *)0x04000208 = 0;
    if (func_02085D3C() == 1) {
        func_01FF8540(1);
        func_01FF836C();
    } else {
        func_01FF8540(0);
    }
    func_01FF8460();
}
