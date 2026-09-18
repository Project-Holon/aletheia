/*
 * function: func_02008CF8
 * address:  0x02008CF8
 * packet:   pkt_02008CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  0209DDB4; 020A70C4
 * symbols:
 *   g_020A70AC      0x020A70AC  data
 *   g_020A70C4      0x020A70C4  data
 *   g_0209DDB4      0x0209DDB4  data
 *   g_020A716C      0x020A716C  data
 */

extern unsigned char g_020A70C4[];
extern int g_0209DDB4[];
int func_02008CF8(int idx)
{
    int v = g_020A70C4[idx];
    if (v >= 0xa7) return 0;
    if (v >= 6) return 0;
    return g_0209DDB4[v];
}
