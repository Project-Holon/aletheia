/*
 * function: func_021760FC
 * address:  0x021760FC
 * packet:   pkt_ov009_021760FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NodeInfoList_Append (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

struct node_s {
    int w[10];
};

extern char *func_02175F3C(void);

int func_021760FC(struct node_s *newNode)
{
    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0;
    *(struct node_s *)(func_02175F3C() + 0x54 + *(int *)(func_02175F3C() + 0x50) * 40) = *newNode;
    *(int *)(func_02175F3C() + 0x50) += 1;
    return 1;
}
