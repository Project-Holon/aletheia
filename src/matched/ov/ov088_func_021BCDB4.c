/*
 * function: STARTMENU_SaveEraseStepShowPrompt
 * address:  0x021BCDB4
 * packet:   pkt_ov088_021BCDB4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   STARTMENU_SaveEraseStartMessage  0x021BD118  thumb  ov088
 */

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void STARTMENU_SaveEraseStartMessage(int *p, u32 mode);

void STARTMENU_SaveEraseStepShowPrompt(void *p, int *st)
{
    if (WIPE_SYS_EndCheck() == 1) {
        STARTMENU_SaveEraseStartMessage(p, 0);
        *st = 2;
    }
}
