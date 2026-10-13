/*
 * function: STARTMENU_AddVblankTask
 * address:  0x021BA9B0
 * packet:   pkt_ov088_021BA9B0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   STARTMENU_VblankTask  0x021BA990  thumb  ov088
 */

extern int func_020056A0(void (*fn)(void), void *arg, int c);
extern void STARTMENU_VblankTask(void);

void STARTMENU_AddVblankTask(int *p)
{
    p[5] = func_020056A0(STARTMENU_VblankTask, p, 0);
}
