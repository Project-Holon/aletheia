/*
 * function: BTLV_EFFVM_GetEmitterHandle
 * address:  0x021FD1C0
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFVM_GetEmitterHandle   0x021FD1C0  thumb
 *
 * lane O10 candidate
 */

int BTLV_EFFVM_GetEmitterHandle(char *p, int i)
{
    return *(int *)(p + i * 4 + 0x8c);
}

