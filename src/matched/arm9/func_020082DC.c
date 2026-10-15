/*
 * function: CONFIG_InitKeyControlTable
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
 *   KEY_SetControlModeTable  0x020362A4  arm
 */

extern char g_0209DD64[];
extern void KEY_SetControlModeTable(const void *p);
void CONFIG_InitKeyControlTable(void)
{
    KEY_SetControlModeTable(g_0209DD64);
}
