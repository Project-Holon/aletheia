/*
 * function: func_02208A54
 * address:  0x02208A54
 * packet:   pkt_02208A54
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047CFC 0x02047CFC arm
 */

extern int func_02047CFC(int, int, int);

void func_02208A54(char *a)
{
    *(int *)(a + 0x14) = func_02047CFC(4, 1, *(unsigned short *)a);
    *(unsigned short *)(a + 0x1c) = 0;
}