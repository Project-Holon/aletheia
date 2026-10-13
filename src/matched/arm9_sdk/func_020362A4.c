/*
 * function: KEY_SetControlModeTable
 * address:  0x020362A4
 * packet:   pkt_020362A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224   0x02035224  arm
 *   KEY_SetControlModeTableSys   0x02036290  arm
 */

struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern int KEY_SetControlModeTableSys(int a0, const void *a1);

void KEY_SetControlModeTable(const void *p)
{
    KEY_SetControlModeTableSys((int)func_02035224(), p);
}
