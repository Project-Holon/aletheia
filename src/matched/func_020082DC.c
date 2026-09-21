/*
 * function: func_020082DC
 * address:  0x020082DC
 * packet:   pkt_020082DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  020362A4; 0209DD64
 * symbols:
 *   g_0209DD64      0x0209DD64  data
 */

extern char g_0209DD64[];
extern void func_020362A4(void *p);
void func_020082DC(void)
{
    func_020362A4(g_0209DD64);
}
