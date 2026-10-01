/*
 * function: func_0217E23C
 * address: 0x0217E23C
 * packet: pkt_ov176_0217E23C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: follower of func_0217E1FC
 */
int func_0217E23C(char *p, void **out)
{
    int value = *(int *)(p + 0x1008);
    if (value) {
        *(int *)(p + 0x1008) = 0;
        *out = p + 6;
    }
    return value;
}
