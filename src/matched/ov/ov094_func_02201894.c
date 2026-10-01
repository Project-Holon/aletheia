/*
 * function: func_02201894
 * address:  0x02201894
 * packet:   pkt_ov094_02201894
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8694  0x021F8694  thumb  ov094
 */
extern char *func_021F8694(void);

void func_02201894(int i)
{
    *(int *)(func_021F8694() + i * 0x5c + 0x4c) = 0;
}
