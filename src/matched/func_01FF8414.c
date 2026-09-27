/*
 * function: func_01FF8414
 * address:  0x01FF8414
 * packet:   pkt_01FF8414
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   OS_IsResetOccurred        0x02084A28  arm
 *   OS_IsRunOnTwl             0x02085D3C  arm
 *   OSi_ReloadRomData         0x01FF8540  arm
 *   OSi_VerifyStaticSegments  0x01FF836C  arm
 *   OSi_DoBoot                0x01FF8460  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int OS_IsResetOccurred(void);
extern int OS_IsRunOnTwl(void);
extern void OSi_ReloadRomData(int);
extern void OSi_VerifyStaticSegments(void);
extern void OSi_DoBoot(void);

void func_01FF8414(void)
{
    while (!OS_IsResetOccurred()) {
    }
    *(volatile u16 *)0x04000208 = 0;
    if (OS_IsRunOnTwl() == 1) {
        OSi_ReloadRomData(1);
        OSi_VerifyStaticSegments();
    } else {
        OSi_ReloadRomData(0);
    }
    OSi_DoBoot();
}
