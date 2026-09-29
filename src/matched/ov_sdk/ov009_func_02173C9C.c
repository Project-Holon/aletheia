/*
 * function: func_02173C9C
 * address:  0x02173C9C
 * packet:   pkt_ov009_02173C9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetAIDBitmask (dwc_match.o)
 *
 * symbols:
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern char *func_02175F3C(void);

unsigned int func_02173C9C(int valid)
{
    unsigned int bitmask = 0;
    int i;

    for (i = 1; i < func_0217603C(); i++)
        bitmask |= 1 << *(unsigned char *)(func_0217637C(i) + 0x16);
    if (valid == 0)
        bitmask |= 1 << *(unsigned char *)(func_02175F3C() + 0x56a);
    return bitmask;
}
