/*
 * function: STARTMENU_SaveEraseStartVblankTask
 * address:  0x021BD0F4
 * packet:   pkt_ov088_021BD0F4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   STARTMENU_SaveEraseVblankTask  0x021BD0D8  thumb  ov088
 */

extern void *func_020056A0(void (*)(void), void *, int);
extern void STARTMENU_SaveEraseVblankTask(void);

void STARTMENU_SaveEraseStartVblankTask(void **p)
{
    *p = func_020056A0(STARTMENU_SaveEraseVblankTask, p, 0);
}
