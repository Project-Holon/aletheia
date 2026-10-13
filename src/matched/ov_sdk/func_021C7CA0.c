/*
 * function: func_021C7CA0
 * address:  0x021C7CA0
 * packet:   pkt_021C7CA0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CA0 0x021C7CA0 arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   DWCi_WINlIsInit  0x021D157C  arm
 *
 * When the wait is over, clear the low bits of the global status word.
 * Addresses are Black-image addresses.
 */

extern int DWCi_WINlIsInit(void);
extern void DWCi_ChangeScene(unsigned int v);

void func_021C7CA0(void)
{
    int *p;

    if (DWCi_WINlIsInit() != 0)
        return;
    p = *(int **)(*(int *)0x021DE5E4 + 4);
    *p &= 0xC1FFFCFF;
    DWCi_ChangeScene((unsigned int)((void *)0x021C7314));
}

