/*
 * function: func_02172B08
 * address:  0x02172B08
 * packet:   pkt_ov009_02172B08
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_InvalidateReservation (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 */

extern int func_02175F3C(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern void func_0217653C(void);

int func_02172B08(void)
{
    int result;
    unsigned long senddata = 0;

    result = 0;
    if (*(unsigned char *)(func_02175F3C() + 0x18) != 0 && *(int *)(func_02175F3C() + 0x5dc) != 0
        && *(int *)(func_02175F3C() + 0x5dc) != *(int *)(func_02175F3C() + 0x678)) {
        result = func_0216FF2C(12, *(int *)(func_02175F3C() + 0x5dc), *(int *)(func_02175F3C() + 0x558), *(unsigned short *)(func_02175F3C() + 0x560), (const unsigned int *)(&senddata), 1);
        *(unsigned char *)(func_02175F3C() + 0x18) = 0;
        *(int *)(func_02175F3C() + 0x5dc) = 0;
        func_0217653C();
    }
    return result;
}
