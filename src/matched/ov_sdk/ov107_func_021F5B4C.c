/*
 * function: func_021F5B4C
 * address:  0x021F5B4C
 * packet:   pkt_ov107_021F5B4C
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_SetParentCommParam (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_021F5ADC 0x021F5ADC arm ov107
 *   g_021F6F90 0x021F6F90 data
 */

extern unsigned char g_021F6F90[];

extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_021F5ADC(unsigned short sendSize, unsigned short recvSize, unsigned short entry_num);

int func_021F5B4C(unsigned short sendSize, unsigned short maxChildren)
{
    unsigned long enabled = func_02087988();

    if ((*(unsigned char **)(g_021F6F90 + 0xC))[0x50D] != 0) {
        func_0208799C(enabled);
        return 0;
    }
    if (func_021F5ADC(sendSize, 8, maxChildren) == 0) {
        func_0208799C(enabled);
        return 0;
    }
    *(unsigned short *)(*(unsigned char **)(g_021F6F90 + 0xC) + 0x10) = maxChildren;
    *(unsigned short *)(*(unsigned char **)(g_021F6F90 + 0xC) + 0x500) = sendSize;
    *(unsigned short *)(*(unsigned char **)(g_021F6F90 + 0xC) + 0x502) = 8;
    func_0208799C(enabled);
    return 1;
}
