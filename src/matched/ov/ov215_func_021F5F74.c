/*
 * function: func_021F5F74
 * address: 0x021F5F74
 * packet: pkt_ov215_021F5F74
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker set of concrete MATCH900 ov215021F5884; parent claim.
 * extent: 14-byte predicate then two zero alignment bytes at 021F5F82.
 */
int func_021F5F74(void *unused,char *p)
{
    if(*(int *)(p+24)==1)return 1;
    return 0;
}
