/*
 * function: DWCi_NodeInfoList_InsertToTop
 * address:  0x0217604C
 * packet:   pkt_ov009_0217604C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NodeInfoList_InsertToTop (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

struct node_s {
    int w[10];
};

extern char *func_02175F3C(void);

int DWCi_NodeInfoList_InsertToTop(struct node_s *newNode)
{
    int i;

    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0;
    for (i = *(int *)(func_02175F3C() + 0x50); i > 0; i--)
        ((struct node_s *)(func_02175F3C() + 0x54))[i] = ((struct node_s *)(func_02175F3C() + 0x54))[i - 1];
    *(struct node_s *)(func_02175F3C() + 0x54) = *newNode;
    *(int *)(func_02175F3C() + 0x50) += 1;
    return 1;
}
