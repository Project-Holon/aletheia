/*
 * function: BTL_SERVER_GotoSelectCommands
 * address:  0x021BABF4
 * packet:   pkt_ov093_021BABF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub (leaf of BTL_SERVER_StepStart): forwards its first
 * argument to BTL_SERVER_SetHandler with the function pointer 0x021BACAD in r1.
 *
 * symbols:
 *   BTL_SERVER_SetHandler  0x021BABEC  thumb  ov093
 *   BTL_SERVER_StepSelectCommands  0x021BACAC  thumb  ov093
 */

typedef unsigned char  u8;
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepSelectCommands(u8 *p, int *s);

void BTL_SERVER_GotoSelectCommands(void *p)
{
    BTL_SERVER_SetHandler(p, (void *)BTL_SERVER_StepSelectCommands);
}
