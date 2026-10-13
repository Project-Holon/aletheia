/*
 * function: SCRIPT_SYS_RunFieldRecoverScript
 * address:  0x02158AD4
 * packet:   pkt_02158AD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   SCRIPT_SYS_RunSpecialScript  0x02158A90  thumb
 */

int SCRIPT_SYS_RunSpecialScript(void *a, int unused, int key, int d);

void SCRIPT_SYS_RunFieldRecoverScript(int a, int b)
{
    SCRIPT_SYS_RunSpecialScript((void *)a, b, 3, 1);
}
