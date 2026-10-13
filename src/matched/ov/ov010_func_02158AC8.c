/*
 * function: SCRIPT_SYS_RunFieldInitScript
 * address:  0x02158AC8
 * packet:   pkt_02158AC8
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

void SCRIPT_SYS_RunFieldInitScript(int a, int b)
{
    SCRIPT_SYS_RunSpecialScript((void *)a, b, 4, 1);
}
